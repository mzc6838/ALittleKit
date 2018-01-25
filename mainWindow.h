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

//用于计算器的中序后序表达式的构建
class NumOrSymbol
{
public:
	int        flag;  //1表示数字，2表示符号     
	BigInteger num;
	char       symbol;

public:
	NumOrSymbol() { flag = 0; num = BIG_ZERO; symbol = '#'; };
	void setData(std::string);
	void setData(char);
	void operator=(const NumOrSymbol &);
};

//主窗口
class mainTab : public QWidget
{
	Q_OBJECT

public:
	mainTab(QWidget *parent = Q_NULLPTR);
	QTabWidget * tabWidget;
};

//计算器层面
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

					   //计算
	QPushButton *add;  //+
	QPushButton *sub;  //-
	QPushButton *mul;  //*
	QPushButton *div;  ///
	QPushButton *equ;  //=
	//QPushButton *bot;  //正负
	QPushButton *leftBracket; //左括号
	QPushButton *rightBracket;//右括号
	int leftCount = 0;        //左括号个数
	int rightCount = 0;       //右括号个数

	//其他操作
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

	bool createBehind(QString, std::vector<NumOrSymbol>&); // 创建后序表达式
	
	QString solveBehind(std::vector<NumOrSymbol>);         // 计算后序表达式并返回结果


};

//RSA功能层面 todo
class RSATab : public QWidget
{
	Q_OBJECT

public:
	RSATab(QWidget * parent = Q_NULLPTR);
	RSA rsa;

private:
	QGridLayout * RSALay;

	QPushButton *init;           //初始化按钮，用于构建公钥和密钥
	QPushButton *encrypt;        //加密按钮
	QPushButton *decrypt;        //解密按钮
	QPushButton *selectFile;     //选择要加密的文件
	QPushButton *getKeyFromFile; //从文件加载key

	QComboBox *QCB_keyLength; //密钥长度的下拉选项框

	QLabel *information;  //说明文字
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

//构造随机数种子
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
