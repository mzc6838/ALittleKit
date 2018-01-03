#include "mainWindow.h"
#include "qcombobox.h"

#include <thread>
//RSA加密层
RSATab::RSATab(QWidget * parent)
	: QWidget(parent)
{

	RSALay = new QGridLayout;

	//按钮
	init = new QPushButton("Initialization key");
	encrypt = new QPushButton("encrypt");
	decrypt = new QPushButton("decrypt");
	selectFile = new QPushButton("select file...");
	getKeyFromFile = new QPushButton("Load key from file...");


	init->setFixedHeight(35);
	init->setFixedWidth(135);
	encrypt->setFixedHeight(35);
	encrypt->setFixedWidth(250);
	decrypt->setFixedHeight(35);
	decrypt->setFixedWidth(250);
	selectFile->setFixedHeight(35);
	getKeyFromFile->setFixedHeight(35);

	QFont ft;
	ft.setPointSize(12);
	init->setFont(ft);
	encrypt->setFont(ft);
	decrypt->setFont(ft);
	selectFile->setFont(ft);
	getKeyFromFile->setFont(ft);
	
	//说明文字
	information = new QLabel("Please select the length of the key first");
	information->setFont(ft);
	information->setFixedHeight(30);

	informationMain = new QLabel("Please select a file to encrypt or decrypt");
	informationMain->setFont(ft);
	informationMain->setFixedHeight(30);

	//下拉列表
	QCB_keyLength = new QComboBox();
	QCB_keyLength->setFixedHeight(35);
	QCB_keyLength->setFixedWidth(75);
	QCB_keyLength->addItem(QString("32"));
	QCB_keyLength->addItem(QString("64"));
	QCB_keyLength->addItem(QString("128"));
	QCB_keyLength->addItem(QString("256"));
	QCB_keyLength->setFont(ft);

	//QTextLine
	fileName = new QLineEdit();
	fileName->setFocusPolicy(Qt::NoFocus);
	fileName->setFixedHeight(35);
	fileName->setText(QS_filePath);

	//addWidget
	RSALay->addWidget(information, 0, 0);
	RSALay->addWidget(QCB_keyLength, 0, 1);
	RSALay->addWidget(init, 1, 2, 1, 1);
	RSALay->addWidget(getKeyFromFile, 1, 0);

	//进度条
	/*crypting = new QProgressBar(this);
	crypting->setMaximum(100);
	crypting->setMinimum(0);
	crypting->setValue(0);*/
	
	//其他
	//rsa = new RSA();

	//信号和槽
	connect(init, SIGNAL(clicked()), this, SLOT(initClicked()));
	connect(encrypt, SIGNAL(clicked()), this, SLOT(encryptClicked()));
	connect(decrypt, SIGNAL(clicked()), this, SLOT(decryptClicked()));
	connect(selectFile, SIGNAL(clicked()), this, SLOT(selectFileClicked()));
	connect(getKeyFromFile, SIGNAL(clicked()), this, SLOT(getKeyFromFileClicked()));
	setLayout(RSALay);

}

void RSATab::initClicked()
{
	GetMouse *GM = new GetMouse;
	GM->exec();
	if (GM->clickTime == 1)
	{
		QString len = QCB_keyLength->currentText();
		this->i_keyLength = len.toInt();
		std::thread t(&RSA::init, (unsigned)len.toInt() >> 1, std::ref(rsa), (unsigned int)GM->_seed);
		t.join();

		srand((unsigned)time(NULL));
		QString keyName = QString::number((long long)rand()) + ".keyY";
		QFile saveKey(keyName);
		saveKey.open(QIODevice::WriteOnly);
		saveKey.close();
		saveKey.open(QIODevice::WriteOnly);
		QTextStream saveKeyStream(&saveKey);
		saveKeyStream << len << endl;
		saveKeyStream << QString::fromStdString(rsa.getd().toString()) << endl;
		saveKeyStream << QString::fromStdString(rsa.e.toString()) << endl;
		saveKeyStream << QString::fromStdString(rsa.n.toString()) << endl;
		saveKey.close();
		QMessageBox::information(this, "success!", "your key has been saved as " + keyName, QMessageBox::Ok);

		init->setHidden(true);
		QCB_keyLength->setHidden(true);
		information->setHidden(1);
		RSALay->addWidget(informationMain, 0, 0);
		RSALay->addWidget(fileName, 1, 0, 1, 3);
		RSALay->addWidget(encrypt, 2, 0, 1, 2);
		RSALay->addWidget(decrypt, 2, 2, 1, 2);
		RSALay->addWidget(selectFile, 1, 3, 1, 1);
	}
}

//加密模块
void RSATab::encryptClicked()
{
	if (this->QS_filePath == "")
	{
		QMessageBox::information(this, "error", "please select a file first to encrypt", QMessageBox::Ok);
	}
	else
	{
		QFile file(QS_filePath);
		QFile outFile(QS_filePath + ".encryptY");
		outFile.open(QIODevice::WriteOnly);
		outFile.close();
		if (!file.open(QIODevice::ReadWrite | QIODevice::Append))
		{
			QMessageBox::warning(this, "error", "cannot open this file", QMessageBox::Ok);
		}
		else
		{
			outFile.open(QIODevice::WriteOnly);
			QDataStream in(&file);
			QDataStream out(&outFile);
			in.setVersion(QDataStream::Qt_5_7);
			out.setVersion(QDataStream::Qt_5_7);

			quint8 n;
			BigIntegerForRsa result;
			in.device()->seek(0);
			while (!in.atEnd())
			{
				in >> n;
				result = rsa.encryptByPublic(QString::number(n, 16).toUpper().toStdString());
				for (int i = result.dataSize() - 1; i >= 0; i--)
				{
					out << result.getData(i);
				}
			}
			file.close();
			outFile.close();
			QMessageBox::information(this, "success", "encrypt finished!", QMessageBox::Ok);
		}
	}
}

//解密模块
void RSATab::decryptClicked()
{
	if (this->QS_filePath == "")
	{
		QMessageBox::information(this, "error", "please select a file first to decrypt", QMessageBox::Ok);
	}
	else
	{
		QFile file(QS_filePath);
		QFile outFile(QS_filePath.left(QS_filePath.length() - 9) + ".decryptY");
		outFile.open(QIODevice::WriteOnly);
		outFile.close();
		if (!file.open(QIODevice::ReadOnly))
		{
			QMessageBox::warning(this, "error", "cannot open this file", QMessageBox::Ok);
		}
		else
		{
			outFile.open(QIODevice::WriteOnly);
			QDataStream in(&file);
			QDataStream out(&outFile);
			in.setVersion(QDataStream::Qt_5_7);
			out.setVersion(QDataStream::Qt_5_7);
			
			quint8 n = 0; //用于获得每位的16进制数据，后序将进行拼接
			QString QS_temp, t;
			BigIntegerForRsa result;
			while (!in.atEnd())
			{
				QS_temp = "";
				for (int i = 0; i < i_keyLength / 8; i++)
				{
					in >> n;
					t = QString::number(n, 16).toUpper();
					if (t.size() == 1)
					{
						t = '0' + t;
					}
					QS_temp += t;
				}
				result = rsa.decryptByPrivate(QS_temp.toStdString());
				out << (quint8)result.getData(0);
			}
			file.close();
			outFile.close();
			QMessageBox::information(this, "success", "decrypt finished!", QMessageBox::Ok);
		}
	}
}

void RSATab::selectFileClicked()
{
	QString temp = QFileDialog::getOpenFileName(this, "select a file to encrypt(decrypt)", "/");
	QFileInfo fi = QFileInfo(temp);
	this->QS_fileName = fi.fileName();
	this->QS_filePath = fi.absoluteFilePath();
	this->fileSize = fi.size();
	//qDebug() << this->fileSize;
	fileName->setText(QS_filePath);
}

void RSATab::getKeyFromFileClicked()
{
	QString loadFile = QFileDialog::getOpenFileName(this, "select a key", ".", "*.keyY");
	QFileInfo fi = QFileInfo(loadFile);

	QFile readKey(fi.absoluteFilePath());
	if (!readKey.open(QIODevice::ReadOnly))
	{
		QMessageBox::warning(this, "error", "cannot open this file", QMessageBox::Ok);
	}
	else
	{
		QTextStream keyStream(&readKey);
		QString temp = "";
		temp = keyStream.readLine();
		this->i_keyLength = temp.toInt();
		temp = keyStream.readLine();
		this->rsa.setd(temp.toStdString());
		temp = keyStream.readLine();
		this->rsa.sete(temp.toStdString());
		temp = keyStream.readLine();
		this->rsa.setn(temp.toStdString());

		init->setHidden(true);
		QCB_keyLength->setHidden(true);
		information->setHidden(true);
		getKeyFromFile->setHidden(true);
		RSALay->addWidget(informationMain, 0, 0);
		RSALay->addWidget(fileName, 1, 0, 1, 3);
		RSALay->addWidget(selectFile, 1, 3, 1, 1);
		RSALay->addWidget(encrypt, 2, 0);
		RSALay->addWidget(decrypt, 2, 2);
	}

}
