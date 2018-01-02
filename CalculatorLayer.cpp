#include "mainWindow.h"
//计算器层
using namespace std;


Calculator::Calculator(QWidget *parent)
	: QWidget(parent)
{
	//ui.setupUi(this);
	//QWidget *widget = new QWidget;
	//this->setCentralWidget(widget);

	inputLine = new QLineEdit;
	inputLine->setText(input);
	inputLine->setFocusPolicy(Qt::NoFocus);

	zero = new QPushButton("0");
	one = new QPushButton("1");
	two = new QPushButton("2");
	three = new QPushButton("3");
	four = new QPushButton("4");
	five = new QPushButton("5");
	six = new QPushButton("6");
	seven = new QPushButton("7");
	eight = new QPushButton("8");
	nine = new QPushButton("9");

	add = new QPushButton("+");
	sub = new QPushButton("-");
	mul = new QPushButton("*");
	div = new QPushButton("/");
	equ = new QPushButton("=");
	leftBracket = new QPushButton("(");
	rightBracket = new QPushButton(")");
	//bot = new QPushButton("+/-");

	CE = new QPushButton("CE");
	AC = new QPushButton("AC");

	QGridLayout *H = new QGridLayout(this);

	inputLine->setFixedHeight(50);
	CE->setFixedHeight(50);
	AC->setFixedHeight(50);

	H->addWidget(inputLine, 0, 0, 1, 3);
	H->setRowStretch(0, 100);
	H->addWidget(CE, 0, 3);
	H->addWidget(AC, 0, 4);

	H->addWidget(one, 1, 0);
	H->addWidget(two, 1, 1);
	H->addWidget(three, 1, 2);

	H->addWidget(four, 2, 0);
	H->addWidget(five, 2, 1);
	H->addWidget(six, 2, 2);
	H->addWidget(add, 2, 3);
	H->addWidget(sub, 2, 4);

	H->addWidget(seven, 3, 0);
	H->addWidget(eight, 3, 1);
	H->addWidget(nine, 3, 2);
	H->addWidget(mul, 3, 3);
	H->addWidget(div, 3, 4);

	H->addWidget(zero, 4, 0);
	//H->addWidget(bot, 4, 1);
	H->addWidget(equ, 4, 2);
	H->addWidget(leftBracket, 4, 3);
	H->addWidget(rightBracket, 4, 4);

	//widget->setLayout(H);

	connect(zero, SIGNAL(clicked()), this, SLOT(zeroClicked()));
	connect(one, SIGNAL(clicked()), this, SLOT(oneClicked()));
	connect(two, SIGNAL(clicked()), this, SLOT(twoClicked()));
	connect(three, SIGNAL(clicked()), this, SLOT(threeClicked()));
	connect(four, SIGNAL(clicked()), this, SLOT(fourClicked()));
	connect(five, SIGNAL(clicked()), this, SLOT(fiveClicked()));
	connect(six, SIGNAL(clicked()), this, SLOT(sixClicked()));
	connect(seven, SIGNAL(clicked()), this, SLOT(sevenClicked()));
	connect(eight, SIGNAL(clicked()), this, SLOT(eightClicked()));
	connect(nine, SIGNAL(clicked()), this, SLOT(nineClicked()));

	connect(add, SIGNAL(clicked()), this, SLOT(addClicked()));
	connect(sub, SIGNAL(clicked()), this, SLOT(subClicked()));
	connect(mul, SIGNAL(clicked()), this, SLOT(mulClicked()));
	connect(div, SIGNAL(clicked()), this, SLOT(divClicked()));
	connect(leftBracket, SIGNAL(clicked()), this, SLOT(leftBucketClicked()));
	connect(rightBracket, SIGNAL(clicked()), this, SLOT(rightBucketClicked()));
	//connect(bot, SIGNAL(clicked(bool)), this, SLOT(botClicked()));

	connect(equ, SIGNAL(clicked()), this, SLOT(equClicked()));

	connect(AC, SIGNAL(clicked()), this, SLOT(ACClicked()));
	connect(CE, SIGNAL(clicked()), this, SLOT(CEClicked()));


	setLayout(H);
}

void Calculator::zeroClicked()
{
	if (input == "0")
	{
		input = "0";
	}
	else if (input == "-0")
	{
		input = "0";
	}
	else
	{
		input += "0";
	}
	inputLine->setText(input);
}

void Calculator::oneClicked()
{
	if (input == "0")
	{
		input = "1";
	}
	else if (input == "-0")
	{
		input = "-1";
	}
	else
	{
		input += "1";
	}
	inputLine->setText(input);
}

void Calculator::twoClicked()
{
	if (input == "0")
	{
		input = "2";
	}
	else if (input == "-0")
	{
		input = "-2";
	}
	else
	{
		input += "2";
	}
	inputLine->setText(input);
}

void Calculator::threeClicked()
{
	if (input == "0")
	{
		input = "3";
	}
	else if (input == "-0")
	{
		input = "-3";
	}
	else
	{
		input += "3";
	}
	inputLine->setText(input);
}

void Calculator::fourClicked()
{
	if (input == "0")
	{
		input = "4";
	}
	else if (input == "-0")
	{
		input = "-4";
	}
	else
	{
		input += "4";
	}
	inputLine->setText(input);
}

void Calculator::fiveClicked()
{
	if (input == "0")
	{
		input = "5";
	}
	else if (input == "-0")
	{
		input = "-5";
	}
	else
	{
		input += "5";
	}
	inputLine->setText(input);
}

void Calculator::sixClicked()
{
	if (input == "0")
	{
		input = "6";
	}
	else if (input == "-0")
	{
		input = "-6";
	}
	else
	{
		input += "6";
	}
	inputLine->setText(input);
}

void Calculator::sevenClicked()
{
	if (input == "0")
	{
		input = "7";
	}
	else if (input == "-0")
	{
		input = "-7";
	}
	else
	{
		input += "7";
	}
	inputLine->setText(input);
}

void Calculator::eightClicked()
{
	if (input == "0")
	{
		input = "8";
	}
	else if (input == "-0")
	{
		input = "-8";
	}
	else
	{
		input += "8";
	}
	inputLine->setText(input);
}

void Calculator::nineClicked()
{
	if (input == "0")
	{
		input = "9";
	}
	else if (input == "-0")
	{
		input = "-9";
	}
	else
	{
		input += "9";
	}
	inputLine->setText(input);
}

void Calculator::addClicked() //加法
{
	if (input == "0")
	{
		//input = "+";
	}
	else if (input.at(input.length() - 1) == '+' || input.at(input.length() - 1) == '-' || input.at(input.length() - 1) == '*' || input.at(input.length() - 1) == '/')
	{
	}
	else
	{
		input += '+';
	}
	inputLine->setText(input);
}

void Calculator::subClicked() //减法
{
	if (input == "0")
	{
		//input = "-";
	}
	else if (input.at(input.length() - 1) == '+' || input.at(input.length() - 1) == '-' || input.at(input.length() - 1) == '*' || input.at(input.length() - 1) == '/')
	{
	}
	else
	{
		input += '-';
	}
	inputLine->setText(input);
}

void Calculator::mulClicked() //乘法
{
	if (input == "0")
	{
		//input = "*";
	}
	else if (input.at(input.length() - 1) == '+' || input.at(input.length() - 1) == '-' || input.at(input.length() - 1) == '*' || input.at(input.length() - 1) == '/')
	{
	}
	else
	{
		input += '*';
	}
	inputLine->setText(input);
}

void Calculator::divClicked() //除法
{
	if (input == "0")
	{
		//input = "/";
	}
	else if (input.at(input.length() - 1) == '+' || input.at(input.length() - 1) == '-' || input.at(input.length() - 1) == '*' || input.at(input.length() - 1) == '/')
	{
	}
	else
	{
		input += '/';
	}
	inputLine->setText(input);
}

void Calculator::equClicked()
{
	vector<NumOrSymbol> output;
	createBehind(input, output);
	input = solveBehind(output);
	inputLine->setText(input);
}

void Calculator::leftBucketClicked()
{
	if (input == "0")
	{
		input = "(";
	}
	else
	{
		input += '(';
	}
	leftCount++;
	inputLine->setText(input);
}

void Calculator::rightBucketClicked()
{
	if (input != "0")
	{
		if (rightCount < leftCount)
		{
			input += ')';
			rightCount++;
		}
	}
	inputLine->setText(input);
}

void Calculator::ACClicked()
{
	leftCount = 0;
	rightCount = 0;
	input = "0";
	inputLine->setText(input);
}

void Calculator::CEClicked()
{
	if (input.mid(input.length() - 1, 1) == "(")
	{
		leftCount--;
	}
	else if (input.mid(input.length() - 1, 1) == ")")
	{
		rightCount--;
	}
	input = input.left(input.length() - 1);
	inputLine->setText(input);
}

bool Calculator::createBehind(QString input, vector<NumOrSymbol>& output)
{
	vector<NumOrSymbol> v_temp, result;
	QStack<NumOrSymbol> QS_temp;
	string s_temp = input.toStdString();//input转换而来
	string S_temp = ""; //存数或者符号
	NumOrSymbol NOS_temp;
	for (int i = 0; i < s_temp.length(); i++) //  先序表达式创建 结果存放v_temp
	{
		switch (s_temp[i])
		{
		case '+':
		{
			if (S_temp != "")
			{
				NOS_temp.setData(S_temp);
				v_temp.push_back(NOS_temp);
			}
			NOS_temp.setData('+');
			v_temp.push_back(NOS_temp);
			S_temp = "";
			break;
		}
		case '-':
		{
			if (S_temp != "")
			{
				NOS_temp.setData(S_temp);
				v_temp.push_back(NOS_temp);
			}
			NOS_temp.setData('-');
			v_temp.push_back(NOS_temp);
			S_temp = "";
			break;
		}
		case '*':
		{
			if (S_temp != "")
			{
				NOS_temp.setData(S_temp);
				v_temp.push_back(NOS_temp);
			}
			NOS_temp.setData('*');
			v_temp.push_back(NOS_temp);
			S_temp = "";
			break;
		}
		case '/':
		{
			if (S_temp != "")
			{
				NOS_temp.setData(S_temp);
				v_temp.push_back(NOS_temp);
			}
			NOS_temp.setData('/');
			v_temp.push_back(NOS_temp);
			S_temp = "";
			break;
		}
		case '(':
		{
			NOS_temp.setData('(');
			v_temp.push_back(NOS_temp);
			S_temp = "";
			break;
		}
		case ')':
		{
			if (S_temp != "")
			{
				NOS_temp.setData(S_temp);
				v_temp.push_back(NOS_temp);
			}
			NOS_temp.setData(')');
			v_temp.push_back(NOS_temp);
			S_temp = "";
			break;
		}
		default:
		{
			S_temp += s_temp[i];
			break;
		}
		}
	}
	if (S_temp != "")
	{
		NOS_temp.setData(S_temp);
		v_temp.push_back(NOS_temp);
	}

	//构建后序表达式
	for (int i = 0; i < v_temp.size(); i++)
	{
		if (v_temp[i].flag == 1)
		{
			output.push_back(v_temp[i]);
		}
		else
		{
			if (QS_temp.isEmpty())
			{
				QS_temp.push(v_temp[i]);
			}
			else
			{
				if ((QS_temp.top().symbol == '*' || QS_temp.top().symbol == '/') &&
					(v_temp[i].symbol == '+' || v_temp[i].symbol == '-'))
				{
					while ((QS_temp.top().symbol == '*' || QS_temp.top().symbol == '/') &&
						(v_temp[i].symbol == '+' || v_temp[i].symbol == '-'))
					{
						output.push_back(QS_temp.pop());
						if (QS_temp.isEmpty())
						{
							break;
						}
					}
					QS_temp.push(v_temp[i]);
				}
				else if (v_temp[i].symbol == ')')
				{
					while (QS_temp.top().symbol != '(')
					{
						output.push_back(QS_temp.pop());
						if (QS_temp.isEmpty())
						{
							break;
						}
					}
					QS_temp.pop();
				}
				else
				{
					QS_temp.push(v_temp[i]);
				}
			}
		}
	}
	while (!QS_temp.isEmpty())
	{
		output.push_back(QS_temp.pop());
	}
	return 1;
}

//求解后序表达式
QString Calculator::solveBehind(vector<NumOrSymbol> input)
{
	QStack<BigInteger> number;
	BigInteger t_numA, t_numB, t_res;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i].flag == 1)
		{
			number.push(input[i].num);
		}
		else
		{
			t_numA.setData(number.pop());
			t_numB.setData(number.pop());
			switch (input[i].symbol)
			{
			case '+':
			{
				t_res = t_numA + t_numB;
				number.push(t_res);
				break;
			}
			case '-':
			{
				t_res = t_numB - t_numA;
				number.push(t_res);
				break;
			}
			case '*':
			{
				t_res = t_numA * t_numB;
				number.push(t_res);
				break;
			}
			case '/':
			{
				t_res = t_numB / t_numA;
				if (t_res.isNegative && t_res != BIG_ZERO)
				{
					t_res = t_res - BIG_ONE;
				}
				else if (!t_res.isNegative && t_res != BIG_ZERO)
				{
					t_res = t_res + BIG_ONE;
				}
				number.push(t_res);
				break;
			}
			}
		}
	}
	BigInteger t(number.pop());
	QString result;
	result = QString::fromStdString(t.num);
	if (t.isNegative)
	{
		result = '-' + result;
	}
	return result;
}

void NumOrSymbol::setData(std::string str)
{
	//数字
	this->flag = 1;
	this->num.setData(str);
	//this->num.numLength = this->num.num.length();
	this->symbol = '#';
}

void NumOrSymbol::setData(char c)
{
	//符号
	this->flag = 2;
	this->num.setData(BIG_ZERO);
	this->symbol = c;
}

void NumOrSymbol::operator=(const NumOrSymbol &_num)
{
	this->flag = _num.flag;
	this->num.setData(_num.num);
	this->symbol = _num.symbol;
}

//896*632+254*55

//TODO
//给RSA添加选项卡
