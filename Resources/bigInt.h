#pragma once
#include <iostream>
#ifndef _BIG_INT_H_
#define _BIG_INT_H_

/**
*返回值各种情况的分类
*/
#define E_BIGINT_OK  1 //成功计算
#define E_BIGINT_DBZ 0 //除数为零
#define E_BIGINT_MAL 2 //内存分配错误
#define E_BIGINT_NPT 3 //空指针作为参数传递
#define E_BIGINT_OFL 4 //上溢
#define E_BIGINT_UFL 5 //下溢
#define E_BIGINT_POW 6 //以0为底数的0次方

/**
*三个特殊的数
*/
#define BIG_ZERO BigInteger(0)
#define BIG_ONE BigInteger(1)
#define BIG_TWO BigInteger(2)

/**
*GLOBAL全局变量
*/
extern int *G_primeIn65536;

/**
*@class  BigInteger  \bigInt.h
*@author mzc6838
*@brief  提供大整数的生成，表示，运算功能
*@notice 仅是整数运算，负数幂不包含在内
*/
class BigInteger
{
public:

	std::string num;                     //原始字符串(DEC)
	int         numLength;	             //数值长度
	bool        isNegative = false;      //负数判断
	bool        isError = false;         //错误判断，用于除数为0检测
	std::string Bin;                     //原始字符串(BIN)

public:

	///////////////////////////////////////
	//成员方法

	/**
	*@brief 默认构造函数
	*/
	BigInteger() {
		this->num = "0";
		this->numLength = 1;
		this->isNegative = false;
		this->Bin = "";
	}

	/**
	*@brief 大整数的定义，赋值构造函数
	*@param s 字符串常量，表示一个超长整数
	*/
	BigInteger(std::string);

	/**
	*@brief 大整数的定义，赋值构造函数
	*@param i 整形常量，表示一个int整数
	*/
	BigInteger(int);

	/**
	*@brief 大整数的定义，赋值构造函数
	*@param c 字符常量，表示一个char整数
	*/
	BigInteger(char);

	/**
	*@brief 析构函数
	*/
	~BigInteger() {};

	/**
	*@brief 复制函数
	*@param BigInteger* 被复制的大整数
	*/
	inline void setData(BigInteger);
	//void setData(std::string);

	/**
	*@brief 对象置空
	*@waring 此方法会将数据清除
	*/
	inline void setEmpty();

	/********************
	*进制转换
	********************/

	/**
	*@brief 十进制转换为二进制 存放于成员Bin中
	*@notice 前提是十进制不为空
	*/
	inline void DecToBin();
	inline static void DecToBin(BigInteger&);

	/**
	*@brief 二进制转十进制 存放于成员num中
	*@notice 前提是二进制不为空
	*/
	inline void BinToDec();
	inline static void BinToDec(BigInteger&);

	/**
	*@brief 判断是否是偶数
	*/
	inline bool IsEven();


	/////////////////////////////////////////////////////////////////////
	//静态函数

	/**
	*@brief 基本加法
	*@param[1] BigInteger* 第一个正整数
	*@param[2] BigInteger* 第二个正整数
	*@return BigInteger*  运算结果
	*@notice 仅支持两个正整数的加法
	*/
	inline BigInteger static _BaseAddition(BigInteger, BigInteger);

	/**
	*@brief 基本减法
	*@param[1] BigInteger* 被减数
	*@param[2] BigInteger* 减数
	*@return BigInteger*  运算结果
	*@notice 仅支持两个正数的减法，并且[被减数]大于[减数]
	*/
	inline BigInteger static _BaseSubtraction(BigInteger minuend, BigInteger meiosis);

	/**
	*@brief 大整数加法运算
	*@param[1] BigInteger* 第一个任意整数
	*@param[2] BigInteger* 第二个任意整数
	*@output   BigInteger* 加法结果
	*@return
		E_BIGINT_OK  成功
		E_BIGINT_NPT 空指针作为参数传递
	*/
	int static Addition(BigInteger, BigInteger, BigInteger*);

	/**
	*@brief 大整数减法运算
	*@param[1] BigInteger* 被减数
	*@param[2] BigInteger* 减数
	*@output   BigInteger* 减法结果
	*@return
		E_BIGINT_OK  成功
		E_BIGINT_NPT 空指针作为参数传递
	*/
	int static Subtraction(BigInteger, BigInteger, BigInteger*);

	/**
	*@brief 基本乘法
	*@param[1] BigInteger* 被乘数，为任意正整数
	*@param[2] c           乘数，单一[0-9]的字符
	*@return   s           运算结果
	*@notice 此方法仅限于任意正数乘10以内的数
	*/
	inline std::string static  _BaseMultiplication(BigInteger, char);

	/**
	*@brief 大整数乘法运算
	*@param[1] BigInteger* 被乘数
	*@param[2] BigInteger* 乘数
	*@output   BigInteger* 运算结果
	*@return
		E_BIGINT_OK  成功
		E_BIGINT_NPT 空指针作为参数传递
	*/
	int static Multiplication(BigInteger, BigInteger, BigInteger*);

	/**
	*@brief 大整数除法运算
	*@param[1]  BigInteger* 被除数
	*@param[2]  BigInteger* 除数
	*@output[1] BigInteger* 余数
	*@output[2] BigInteger* 除法结果
	*@return
		E_BIGINT_OK  成功
		E_BIGINT_NPT 空指针作为参数传递
		E_BIGINT_DBZ 除数为零
	*/
	int static Division(BigInteger dividend, BigInteger divisor, BigInteger *Remainder, BigInteger *result);

	/**
	*@brief 按位与
	*@param[1] BigInteger 第一个整数
	*@param[2] BigInteger 第二个整数
	*@return BigInteger 按位与的结果
	*/
	BigInteger static AND_Big(BigInteger, BigInteger);


	/**
	*@brief 大整数幂运算
	*@param[1] BigInteger     底数
	*@param[2] i / BigInteger 幂
	*@return   BigInteger     运算结果
	*/
	BigInteger static Power(BigInteger, int);
	BigInteger static Power(BigInteger, BigInteger);

	/**
	*@TODO 平方运算
	*/
	BigInteger static Sqr(BigInteger);

	/**
	*@brief    成员变量num前补零
	*@param  i 补零个数
	*@return s 补零后的字符串
	*@notice   此方法不会对数值造成影响
	*/
	inline std::string AddZeroFront(int);

	/**
	*@brief static 前补零
	*@param[1] s 需要补零的整数
	*@param[2] i 需要补零的个数
	*@return s 返回补零后的字符串代表整数
	*@notice 此方法不会对数值造成影响
	*/
	inline std::string static AddZeroFront(std::string, int);

	/**
	*@brief static 后补零
	*@param[1] BigInteger* 需要补零的大整数
	*@param[2] i 需要补零的个数
	*@return BigInteger 返回补零之后的大整数
	*@warning 此方法势必会改变数值大小
	*/
	inline BigInteger static AddZeroRear(BigInteger*, int);
	inline void AddZeroRear(int);

	/**
	*@brief 消去任意字符串前的0
	*@param s 需要被处理的字符串
	*@return s 处理过的字符串
	*/
	inline std::string static SubZero(std::string);

	/**
	*@brief 对两个大整数进行真值以及绝对值的比较
	*@param[1] BigInteger* 第一个整数
	*@param[2] BigInteger* 第二个整数
	*@return i:
		 0： A的绝对值等于B
		 1： A的绝对值大于B
		 2： A的绝对值小于B
		0x： A的真值等于B
		1x： A的真值大于B
		2x： A的真值小于B
	*@notice 此方法对A和B的输入顺序有关
	*/
	inline int static Compare(BigInteger, BigInteger);

	/**
	*@brief 两个大整数的求模运算
	*@param[1] BigInteger* 第一个整数
	*@param[2] BigInteger* 第二个整数
	*@return   BigInteger* 两数求模的运算结果
	*/
	BigInteger static Mod(BigInteger, BigInteger);

	/**
	*@brief 求两数的最大公约数（欧几里得算法）
	*@param[1] BigInteger* 第一个数
	*@param[2] BigInteger* 第二个数
	*@return   BigInteger* 两数的最大公约数
	*/
	BigInteger static Gcd(BigInteger, BigInteger);

	/**
	*@brief 扩展欧几里得算法 gcd(numA, numB) = u * numA + v * numB
	*@param[1] BigInteger 参与运算的第一个数
	*@param[2] BigInteger 参与运算的第二个数
	*@param[3] BigInteger* 存放u
	*@param[4] BigInteger* 存放v
	*@return BigInteger 两数的最大公约数
	*/
	BigInteger static XGcd(BigInteger numA, BigInteger numB, BigInteger *u, BigInteger *v);

	/**
	*@brief 求乘法逆
	*@param[1] BigInteger 原数
	*@param[2] BigInteger 模数
	*@param[3] BigInteger* 结果
	*@return
		0: 表明原数模数不互素 result返回两数最大公约数
		1: 表明原数模数互素 result返回num关于1模n的乘法逆元
	*/
	int static Inverse(BigInteger num, BigInteger n, BigInteger *result);

	/**
	*@brief 在范围内生成随机数
	*@param[1] BigInteger 范围下界
	*@param[2] BigInteger 范围上界
	*@return BigInteger 所生成的随机数
	*@notice 仅提供正数的随机数生成
	*/
	BigInteger static Random(BigInteger, BigInteger);

	/**
	*@brief MR素性测试算法
	*@param[1] BigInteger 需要判断的大整数
	*@param[2] i          MR算法中的k
	*@param[3] BigInteger MR算法中的q（奇数）
	*@return b
		true: 不确定
		false: 是一个合数
	*/
	bool static MR_algorithm(BigInteger, int, BigInteger);

	/**
	*@brief 素性测试
	*@param 待测试整数
	*@return
		true: 有大概率待测数据是一个素数
		false: 待测数据是一个合数
	*@warning 使用此方法前务必调用一次G_CreatePrimeList()
	*/
	bool static IsPrime(BigInteger);

	/**
	*@brief Montgomery模幂运算
	*@param[1] BigInteger 底数
	*@param[2] BigInteger 指数
	*@param[3] BigInteger 模数
	*@return BigInteger 返回 a^b mod c 的值
	*/
	inline BigInteger static MontgomeryPower(BigInteger, BigInteger, BigInteger);

	/**
	*@brief Montgomery乘积 a * b mod modulus
	*@param[1] BigInteger 第一个乘数
	*@param[2] BigInteger 第二个乘数
	*@param[3] BigInteger 模数
	*@return BigInteger Montgomery乘积的结果
	*/
	BigInteger static MontgomeryX(BigInteger numA, BigInteger numB, BigInteger modulus);

	/**
	*@brief 对2^N求模
	*@param[1] BigInteger 原数
	*@param[2] int 2的幂数N
	*return BigInteger 原数模2^N的结果
	*/
	inline BigInteger static Mod_Bin(BigInteger, int);

	/**
	*@brief 某二进制减1
	*@param s 输入的二进制原数
	*@return s 原二进制数减一后的结果
	*/
	inline std::string static BinSubOne(std::string);

	/**
	*@brief 欧拉函数(由两个素数决定)
	*@param[1] BigInteger 第一个素数
	*@param[2] BigInteger 第二个素数
	*@notice 不是用模数方式产生，两数一定要都是素数
	*/
	BigInteger static Euler(BigInteger, BigInteger);

	/********************
	*各运算符和操作符的重载
	********************/

	void operator=(int &);
	void operator=(BigInteger &);
	void operator=(const BigInteger &);
	BigInteger operator++(int);//后缀
	BigInteger operator++();
	BigInteger operator--(int);//后缀
	BigInteger operator--();
	friend BigInteger operator >> (BigInteger&, int);
	BigInteger operator >>= (int);
	friend BigInteger operator +(BigInteger&, BigInteger&);
	friend BigInteger operator -(BigInteger&, BigInteger&);
	friend BigInteger operator *(BigInteger&, BigInteger&);
	friend BigInteger operator /(BigInteger&, BigInteger&);
	friend BigInteger operator %(BigInteger&, BigInteger&);
	friend BigInteger operator &(BigInteger&, BigInteger&);
	friend bool operator <(BigInteger&, BigInteger&);
	friend bool operator <=(BigInteger&, BigInteger&);
	friend bool operator >(BigInteger&, BigInteger&);
	friend bool operator >=(BigInteger&, BigInteger&);
	friend bool operator == (BigInteger&, BigInteger&);
	friend bool operator != (BigInteger&, BigInteger&);
	friend std::ostream & operator << (std::ostream &out, BigInteger &num);
	friend std::istream & operator >> (std::istream &in, BigInteger &num);

};//class BigInteger

//GLOBAL函数
/**
*@brief 产生65536以内的素数表
*/
void G_CreatePrimeList();

#endif // !_BIG_INT_H_
