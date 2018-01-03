#pragma once
#include <iostream>
#ifndef _BIG_INT_H_
#define _BIG_INT_H_

/**
*����ֵ��������ķ���
*/
#define E_BIGINT_OK  1 //�ɹ�����
#define E_BIGINT_DBZ 0 //����Ϊ��
#define E_BIGINT_MAL 2 //�ڴ�������
#define E_BIGINT_NPT 3 //��ָ����Ϊ��������
#define E_BIGINT_OFL 4 //����
#define E_BIGINT_UFL 5 //����
#define E_BIGINT_POW 6 //��0Ϊ������0�η�

/**
*�����������
*/
#define BIG_ZERO BigInteger(0)
#define BIG_ONE BigInteger(1)
#define BIG_TWO BigInteger(2)

/**
*GLOBALȫ�ֱ���
*/
extern int *G_primeIn65536;

/**
*@class  BigInteger  \bigInt.h
*@author mzc6838
*@brief  �ṩ�����������ɣ���ʾ�����㹦��
*@notice �����������㣬�����ݲ���������
*/
class BigInteger
{
public:

	std::string num;                     //ԭʼ�ַ���(DEC)
	int         numLength;	             //��ֵ����
	bool        isNegative = false;      //�����ж�
	bool        isError = false;         //�����жϣ����ڳ���Ϊ0���
	std::string Bin;                     //ԭʼ�ַ���(BIN)

public:

	///////////////////////////////////////
	//��Ա����

	/**
	*@brief Ĭ�Ϲ��캯��
	*/
	BigInteger() {
		this->num = "0";
		this->numLength = 1;
		this->isNegative = false;
		this->Bin = "";
	}

	/**
	*@brief �������Ķ��壬��ֵ���캯��
	*@param s �ַ�����������ʾһ����������
	*/
	BigInteger(std::string);

	/**
	*@brief �������Ķ��壬��ֵ���캯��
	*@param i ���γ�������ʾһ��int����
	*/
	BigInteger(int);

	/**
	*@brief �������Ķ��壬��ֵ���캯��
	*@param c �ַ���������ʾһ��char����
	*/
	BigInteger(char);

	/**
	*@brief ��������
	*/
	~BigInteger() {};

	/**
	*@brief ���ƺ���
	*@param BigInteger* �����ƵĴ�����
	*/
	inline void setData(BigInteger);
	//void setData(std::string);

	/**
	*@brief �����ÿ�
	*@waring �˷����Ὣ�������
	*/
	inline void setEmpty();

	/********************
	*����ת��
	********************/

	/**
	*@brief ʮ����ת��Ϊ������ ����ڳ�ԱBin��
	*@notice ǰ����ʮ���Ʋ�Ϊ��
	*/
	inline void DecToBin();
	inline static void DecToBin(BigInteger&);

	/**
	*@brief ������תʮ���� ����ڳ�Աnum��
	*@notice ǰ���Ƕ����Ʋ�Ϊ��
	*/
	inline void BinToDec();
	inline static void BinToDec(BigInteger&);

	/**
	*@brief �ж��Ƿ���ż��
	*/
	inline bool IsEven();


	/////////////////////////////////////////////////////////////////////
	//��̬����

	/**
	*@brief �����ӷ�
	*@param[1] BigInteger* ��һ��������
	*@param[2] BigInteger* �ڶ���������
	*@return BigInteger*  ������
	*@notice ��֧�������������ļӷ�
	*/
	inline BigInteger static _BaseAddition(BigInteger, BigInteger);

	/**
	*@brief ��������
	*@param[1] BigInteger* ������
	*@param[2] BigInteger* ����
	*@return BigInteger*  ������
	*@notice ��֧�����������ļ���������[������]����[����]
	*/
	inline BigInteger static _BaseSubtraction(BigInteger minuend, BigInteger meiosis);

	/**
	*@brief �������ӷ�����
	*@param[1] BigInteger* ��һ����������
	*@param[2] BigInteger* �ڶ�����������
	*@output   BigInteger* �ӷ����
	*@return
		E_BIGINT_OK  �ɹ�
		E_BIGINT_NPT ��ָ����Ϊ��������
	*/
	int static Addition(BigInteger, BigInteger, BigInteger*);

	/**
	*@brief ��������������
	*@param[1] BigInteger* ������
	*@param[2] BigInteger* ����
	*@output   BigInteger* �������
	*@return
		E_BIGINT_OK  �ɹ�
		E_BIGINT_NPT ��ָ����Ϊ��������
	*/
	int static Subtraction(BigInteger, BigInteger, BigInteger*);

	/**
	*@brief �����˷�
	*@param[1] BigInteger* ��������Ϊ����������
	*@param[2] c           ��������һ[0-9]���ַ�
	*@return   s           ������
	*@notice �˷�������������������10���ڵ���
	*/
	inline std::string static  _BaseMultiplication(BigInteger, char);

	/**
	*@brief �������˷�����
	*@param[1] BigInteger* ������
	*@param[2] BigInteger* ����
	*@output   BigInteger* ������
	*@return
		E_BIGINT_OK  �ɹ�
		E_BIGINT_NPT ��ָ����Ϊ��������
	*/
	int static Multiplication(BigInteger, BigInteger, BigInteger*);

	/**
	*@brief ��������������
	*@param[1]  BigInteger* ������
	*@param[2]  BigInteger* ����
	*@output[1] BigInteger* ����
	*@output[2] BigInteger* �������
	*@return
		E_BIGINT_OK  �ɹ�
		E_BIGINT_NPT ��ָ����Ϊ��������
		E_BIGINT_DBZ ����Ϊ��
	*/
	int static Division(BigInteger dividend, BigInteger divisor, BigInteger *Remainder, BigInteger *result);

	/**
	*@brief ��λ��
	*@param[1] BigInteger ��һ������
	*@param[2] BigInteger �ڶ�������
	*@return BigInteger ��λ��Ľ��
	*/
	BigInteger static AND_Big(BigInteger, BigInteger);


	/**
	*@brief ������������
	*@param[1] BigInteger     ����
	*@param[2] i / BigInteger ��
	*@return   BigInteger     ������
	*/
	BigInteger static Power(BigInteger, int);
	BigInteger static Power(BigInteger, BigInteger);

	/**
	*@TODO ƽ������
	*/
	BigInteger static Sqr(BigInteger);

	/**
	*@brief    ��Ա����numǰ����
	*@param  i �������
	*@return s �������ַ���
	*@notice   �˷����������ֵ���Ӱ��
	*/
	inline std::string AddZeroFront(int);

	/**
	*@brief static ǰ����
	*@param[1] s ��Ҫ���������
	*@param[2] i ��Ҫ����ĸ���
	*@return s ���ز������ַ�����������
	*@notice �˷����������ֵ���Ӱ��
	*/
	inline std::string static AddZeroFront(std::string, int);

	/**
	*@brief static ����
	*@param[1] BigInteger* ��Ҫ����Ĵ�����
	*@param[2] i ��Ҫ����ĸ���
	*@return BigInteger ���ز���֮��Ĵ�����
	*@warning �˷����Ʊػ�ı���ֵ��С
	*/
	inline BigInteger static AddZeroRear(BigInteger*, int);
	inline void AddZeroRear(int);

	/**
	*@brief ��ȥ�����ַ���ǰ��0
	*@param s ��Ҫ��������ַ���
	*@return s ��������ַ���
	*/
	inline std::string static SubZero(std::string);

	/**
	*@brief ������������������ֵ�Լ�����ֵ�ıȽ�
	*@param[1] BigInteger* ��һ������
	*@param[2] BigInteger* �ڶ�������
	*@return i:
		 0�� A�ľ���ֵ����B
		 1�� A�ľ���ֵ����B
		 2�� A�ľ���ֵС��B
		0x�� A����ֵ����B
		1x�� A����ֵ����B
		2x�� A����ֵС��B
	*@notice �˷�����A��B������˳���й�
	*/
	inline int static Compare(BigInteger, BigInteger);

	/**
	*@brief ��������������ģ����
	*@param[1] BigInteger* ��һ������
	*@param[2] BigInteger* �ڶ�������
	*@return   BigInteger* ������ģ��������
	*/
	BigInteger static Mod(BigInteger, BigInteger);

	/**
	*@brief �����������Լ����ŷ������㷨��
	*@param[1] BigInteger* ��һ����
	*@param[2] BigInteger* �ڶ�����
	*@return   BigInteger* ���������Լ��
	*/
	BigInteger static Gcd(BigInteger, BigInteger);

	/**
	*@brief ��չŷ������㷨 gcd(numA, numB) = u * numA + v * numB
	*@param[1] BigInteger ��������ĵ�һ����
	*@param[2] BigInteger ��������ĵڶ�����
	*@param[3] BigInteger* ���u
	*@param[4] BigInteger* ���v
	*@return BigInteger ���������Լ��
	*/
	BigInteger static XGcd(BigInteger numA, BigInteger numB, BigInteger *u, BigInteger *v);

	/**
	*@brief ��˷���
	*@param[1] BigInteger ԭ��
	*@param[2] BigInteger ģ��
	*@param[3] BigInteger* ���
	*@return
		0: ����ԭ��ģ�������� result�����������Լ��
		1: ����ԭ��ģ������ result����num����1ģn�ĳ˷���Ԫ
	*/
	int static Inverse(BigInteger num, BigInteger n, BigInteger *result);

	/**
	*@brief �ڷ�Χ�����������
	*@param[1] BigInteger ��Χ�½�
	*@param[2] BigInteger ��Χ�Ͻ�
	*@return BigInteger �����ɵ������
	*@notice ���ṩ���������������
	*/
	BigInteger static Random(BigInteger, BigInteger);

	/**
	*@brief MR���Բ����㷨
	*@param[1] BigInteger ��Ҫ�жϵĴ�����
	*@param[2] i          MR�㷨�е�k
	*@param[3] BigInteger MR�㷨�е�q��������
	*@return b
		true: ��ȷ��
		false: ��һ������
	*/
	bool static MR_algorithm(BigInteger, int, BigInteger);

	/**
	*@brief ���Բ���
	*@param ����������
	*@return
		true: �д���ʴ���������һ������
		false: ����������һ������
	*@warning ʹ�ô˷���ǰ��ص���һ��G_CreatePrimeList()
	*/
	bool static IsPrime(BigInteger);

	/**
	*@brief Montgomeryģ������
	*@param[1] BigInteger ����
	*@param[2] BigInteger ָ��
	*@param[3] BigInteger ģ��
	*@return BigInteger ���� a^b mod c ��ֵ
	*/
	inline BigInteger static MontgomeryPower(BigInteger, BigInteger, BigInteger);

	/**
	*@brief Montgomery�˻� a * b mod modulus
	*@param[1] BigInteger ��һ������
	*@param[2] BigInteger �ڶ�������
	*@param[3] BigInteger ģ��
	*@return BigInteger Montgomery�˻��Ľ��
	*/
	BigInteger static MontgomeryX(BigInteger numA, BigInteger numB, BigInteger modulus);

	/**
	*@brief ��2^N��ģ
	*@param[1] BigInteger ԭ��
	*@param[2] int 2������N
	*return BigInteger ԭ��ģ2^N�Ľ��
	*/
	inline BigInteger static Mod_Bin(BigInteger, int);

	/**
	*@brief ĳ�����Ƽ�1
	*@param s ����Ķ�����ԭ��
	*@return s ԭ����������һ��Ľ��
	*/
	inline std::string static BinSubOne(std::string);

	/**
	*@brief ŷ������(��������������)
	*@param[1] BigInteger ��һ������
	*@param[2] BigInteger �ڶ�������
	*@notice ������ģ����ʽ����������һ��Ҫ��������
	*/
	BigInteger static Euler(BigInteger, BigInteger);

	/********************
	*��������Ͳ�����������
	********************/

	void operator=(int &);
	void operator=(BigInteger &);
	void operator=(const BigInteger &);
	BigInteger operator++(int);//��׺
	BigInteger operator++();
	BigInteger operator--(int);//��׺
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

//GLOBAL����
/**
*@brief ����65536���ڵ�������
*/
void G_CreatePrimeList();

#endif // !_BIG_INT_H_
