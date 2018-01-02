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
	
	init->setFixedHeight(35);
	init->setFixedWidth(150);
	encrypt->setFixedHeight(35);
	decrypt->setFixedHeight(35);
	selectFile->setFixedHeight(35);

	QFont ft;
	ft.setPointSize(12);
	init->setFont(ft);
	encrypt->setFont(ft);
	decrypt->setFont(ft);
	selectFile->setFont(ft);
	
	//说明文字
	information = new QLabel("Please select the length of the key first");
	information->setFont(ft);
	information->setFixedHeight(30);

	//下拉列表
	keyLength = new QComboBox();
	keyLength->setFixedHeight(35);
	keyLength->setFixedWidth(150);
	keyLength->addItem(QString("16"));
	keyLength->addItem(QString("32"));
	keyLength->addItem(QString("64"));
	keyLength->addItem(QString("128"));
	keyLength->addItem(QString("256"));
	keyLength->setFont(ft);

	//QTextLine
	fileName = new QLineEdit();
	fileName->setFocusPolicy(Qt::NoFocus);
	fileName->setFixedHeight(35);
	fileName->setText(QS_filePath);

	//addWidget
	RSALay->addWidget(information, 0, 0);
	RSALay->addWidget(keyLength, 1, 0);
	RSALay->addWidget(init, 1, 1);

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

	setLayout(RSALay);

}

void RSATab::initClicked()
{
	GetMouse *GM = new GetMouse;
	GM->exec();
	if (GM->clickTime == 1)
	{
		QString len = keyLength->currentText();
		std::thread t(&RSA::init, (unsigned)len.toInt() >> 1, std::ref(rsa), (unsigned int)GM->_seed);
		t.join();
		//RSA::init((unsigned)len.toInt(), this->rsa, (unsigned int)GM->_seed);
		init->setHidden(true);
		keyLength->setHidden(true);
		information->setHidden(1);
		RSALay->addWidget(fileName, 0, 0, 1, 3);
		RSALay->addWidget(encrypt, 1, 0, 1, 2);
		RSALay->addWidget(decrypt, 1, 2, 1, 2);
		RSALay->addWidget(selectFile, 0, 3, 1, 1);
	}
}

void RSATab::encryptClicked()
{
	if (this->QS_filePath == "")
	{
		QMessageBox::information(this, "error", "please select a file first to encrypt", QMessageBox::Ok);
	}
	else
	{
		QFile file(QS_filePath);
		QFile outFile(QS_filePath + ".priY");
		outFile.open(QIODevice::WriteOnly);
		outFile.close();
		if (!file.open(QIODevice::ReadOnly))
		{
			QMessageBox::warning(this, "error", "cannot open this file", QMessageBox::Ok);
		}
		else
		{
			/*encrypt->setHidden(1);
			decrypt->setHidden(1);*/
			//RSALay->addWidget(crypting, 1, 0, 1, 4);
			outFile.open(QIODevice::WriteOnly);
			QDataStream in(&file);
			QDataStream out(&outFile);
			in.setByteOrder(QDataStream::LittleEndian);
			out.setByteOrder(QDataStream::LittleEndian);
			//double increase = 8 / (fileSize / 8);//进度条增长步长
			int value = 1;
			quint64 n;
			BigIntegerForRsa result, temp;
			while (!in.atEnd())
			{
				in >> n;
				BigIntegerForRsa temp(n);
				result = rsa.encryptByPublic(n);
				for (int i = 0; i < result.dataSize(); i++)
				{
					out << result.getData(i);
				}
				//value += increase;
				//crypting->setValue(value);
			}
		}
	}
}

void RSATab::decryptClicked()
{
	if (this->QS_filePath == "")
	{
		QMessageBox::information(this, "error", "please select a file first to decrypt", QMessageBox::Ok);
	}
	else
	{
		QFile file(QS_filePath);
		QFile outFile(QS_filePath.left(QS_filePath.length() - 5));
		outFile.open(QIODevice::WriteOnly);
		outFile.close();
		if (!file.open(QIODevice::ReadOnly))
		{
			QMessageBox::warning(this, "error", "cannot open this file", QMessageBox::Ok);
		}
		else
		{
			/*encrypt->setHidden(1);
			decrypt->setHidden(1);*/
			//RSALay->addWidget(crypting, 1, 0, 1, 4);
			outFile.open(QIODevice::WriteOnly);
			QDataStream in(&file);
			QDataStream out(&outFile);
			in.setByteOrder(QDataStream::LittleEndian);
			out.setByteOrder(QDataStream::LittleEndian);
			//double increase = 8 / (fileSize / 8);//进度条增长步长
			int value = 1;
			quint64 n;
			BigIntegerForRsa result, temp;
			while (!in.atEnd())
			{
				in >> n;
				BigIntegerForRsa temp(n);
				result = rsa.decryptByPrivate(n);
				for (int i = 0; i < result.dataSize(); i++)
				{
					out << result.getData(i);
				}
				//value += increase;
				//crypting->setValue(value);
			}
		}
	}
}

void RSATab::selectFileClicked()
{
	QString temp = QFileDialog::getOpenFileName();
	QFileInfo fi = QFileInfo(temp);
	this->QS_fileName = fi.fileName();
	this->QS_filePath = fi.absoluteFilePath();
	this->fileSize = fi.size();
	fileName->setText(QS_filePath);
}