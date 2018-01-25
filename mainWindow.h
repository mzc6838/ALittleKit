#pragma once

#include <QtWidgets/QMainWindow>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qgridlayout.h>
#include <qstring.h>
#include <qstack.h>
#include <qprogressBar.h>
#include "Resources\bigInt.h"
#include <qlabel.h>
#include <qdialog.h>
#include "Resources\BigIntegerForRsa.h"
#include "Resources\RSA.h"
#include "GeneratedFiles\ui_Calculator.h"
#include <QMouseEvent>
#include <qfiledialog.h>
#include <Windows.h>
#include <qmessagebox.h>
#include <qdebug.h>

#pragma comment(lib, "Resources/BigInt.lib")
#pragma comment(lib, "Resources/RSA.lib")

//���ڼ����������������ʽ�Ĺ���
class NumOrSymbol
{
public:
	int        flag;  //1��ʾ���֣�2��ʾ����     
	BigInteger num;
	char       symbol;

public:
	NumOrSymbol() { flag = 0; num = BIG_ZERO; symbol = '#'; };
	void setData(std::string);
	void setData(char);
	void operator=(const NumOrSymbol &);
};

//������
class mainTab : public QWidget
{
	Q_OBJECT

public:
	mainTab(QWidget *parent = Q_NULLPTR);
	QTabWidget * tabWidget;
};

//����������
class Calculator : public QWidget
{
	Q_OBJECT

public:
	Calculator(QWidget *parent = Q_NULLPTR);

private:
	//Ui::calculateClass ui;
	QLineEdit * inputLine;
	QString input = "0";

	//0 - 9
	QPushButton *zero; //0
	QPushButton *one;  //1
	QPushButton *two;  //2
	QPushButton *three;//3
	QPushButton *four; //4
	QPushButton *five; //5
	QPushButton *six;  //6
	QPushButton *seven;//7
	QPushButton *eight;//8
	QPushButton *nine; //9

					   //����
	QPushButton *add;  //+
	QPushButton *sub;  //-
	QPushButton *mul;  //*
	QPushButton *div;  ///
	QPushButton *equ;  //=
	//QPushButton *bot;  //����
	QPushButton *leftBracket; //������
	QPushButton *rightBracket;//������
	int leftCount = 0;        //�����Ÿ���
	int rightCount = 0;       //�����Ÿ���

	//��������
	QPushButton *AC;   //AC
	QPushButton *CE;   //CE

	private slots:

	void zeroClicked();
	void oneClicked();
	void twoClicked();
	void threeClicked();
	void fourClicked();
	void fiveClicked();
	void sixClicked();
	void sevenClicked();
	void eightClicked();
	void nineClicked();

	void addClicked();
	void subClicked();
	void mulClicked();
	void divClicked();
	void equClicked();
	void leftBucketClicked();
	void rightBucketClicked();
	//void botClicked();

	void ACClicked();
	void CEClicked();

	bool createBehind(QString, std::vector<NumOrSymbol>&); // ����������ʽ
	
	QString solveBehind(std::vector<NumOrSymbol>);         // ���������ʽ�����ؽ��


};

//RSA���ܲ��� todo
class RSATab : public QWidget
{
	Q_OBJECT

public:
	RSATab(QWidget * parent = Q_NULLPTR);
	RSA rsa;

private:
	QGridLayout * RSALay;

	QPushButton *init;           //��ʼ����ť�����ڹ�����Կ����Կ
	QPushButton *encrypt;        //���ܰ�ť
	QPushButton *decrypt;        //���ܰ�ť
	QPushButton *selectFile;     //ѡ��Ҫ���ܵ��ļ�
	QPushButton *getKeyFromFile; //���ļ�����key

	QComboBox *QCB_keyLength; //��Կ���ȵ�����ѡ���

	QLabel *information;  //˵������
	QLabel *informationMain;

	QString QS_filePath = "";
	QString QS_fileName = "";
	qint64  fileSize = 0;
	QLineEdit *fileName;

	QProgressBar *crypting;

	int i_keyLength;

	unsigned int _seed;


private slots:
	void initClicked();
	void encryptClicked();
	void decryptClicked();
	void selectFileClicked();
	void getKeyFromFileClicked();

};

//�������������
class GetMouse : public QDialog
{
	Q_OBJECT

public:
	GetMouse(QWidget *parent = Q_NULLPTR);
	long long _seed = 0;
	int clickTime = 10;

private:
	QGridLayout * GMWindow;
	QLabel * information;
	void mousePressEvent(QMouseEvent *m);
};
