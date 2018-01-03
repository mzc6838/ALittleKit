#ifndef __BIGINTEGER_H__
#define __BIGINTEGER_H__

#include <string>
#include <vector>
#include <iostream>

class BigIntegerForRsa {
public:
	typedef long long long_t;
	typedef unsigned base_t;
	BigIntegerForRsa() : is_negative(false) { data.push_back(0); } // Ĭ��Ϊ0
	BigIntegerForRsa(const BigIntegerForRsa &);    // ���ø����Ĵ�������ʼ��
	BigIntegerForRsa(const std::string &);// ���ø�����ʮ�������ַ�����ʼ��
	BigIntegerForRsa(const long_t &);        // ���ø�����long_t�������ݳ�ʼ��
	~BigIntegerForRsa() {}

	BigIntegerForRsa add(const BigIntegerForRsa &);        // �������ӷ�
	BigIntegerForRsa subtract(const BigIntegerForRsa &);// ����������
	BigIntegerForRsa multiply(const BigIntegerForRsa &) const;// �������˷�
	BigIntegerForRsa divide(const BigIntegerForRsa &);    // ����������
	BigIntegerForRsa remainder(const BigIntegerForRsa &);    // ������ȡ��
	BigIntegerForRsa mod(const BigIntegerForRsa &);        // ������ȡģ
	BigIntegerForRsa divideAndRemainder(const BigIntegerForRsa &, BigIntegerForRsa &);// ������������ȡ��
	BigIntegerForRsa pow(const BigIntegerForRsa &);        // �������ݳ�
	BigIntegerForRsa modPow(const BigIntegerForRsa &, const BigIntegerForRsa &) const;// ��������ģ����
	BigIntegerForRsa modInverse(const BigIntegerForRsa &);// ����չŷ������㷨��˷���Ԫ

	BigIntegerForRsa shiftLeft(const unsigned);    // ��λ����,����
	BigIntegerForRsa shiftRight(const unsigned);    // ��λ����,����

	int compareTo(const BigIntegerForRsa &) const;// �Ƚ�����
	bool equals(const BigIntegerForRsa &) const;// �ж��Ƿ���ڸ�����
	static BigIntegerForRsa valueOf(const long_t &);// ��������ת��Ϊ������������
	std::string toString() const;    // ��������ת��Ϊʮ�������ַ���
	BigIntegerForRsa abs() const;        // ��������ľ���ֵ

	base_t getData(int); //�õ�data������һλ��ֵ
	int dataSize();//����data�ĳ���

protected:
	// ������������غ�����Ҫ�������������һ��ʹ�ô���������
	friend BigIntegerForRsa operator + (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend BigIntegerForRsa operator - (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend BigIntegerForRsa operator * (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend BigIntegerForRsa operator / (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend BigIntegerForRsa operator % (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend bool operator < (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend bool operator > (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend bool operator == (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend bool operator <= (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend bool operator >= (const BigIntegerForRsa &, const BigIntegerForRsa &);
	friend bool operator != (const BigIntegerForRsa &, const BigIntegerForRsa &);

	// ���ذ汾,ʹ��������long_t����
	friend BigIntegerForRsa operator + (const BigIntegerForRsa &, const long_t &);
	friend BigIntegerForRsa operator - (const BigIntegerForRsa &, const long_t &);
	friend BigIntegerForRsa operator * (const BigIntegerForRsa &, const long_t &);
	friend BigIntegerForRsa operator / (const BigIntegerForRsa &, const long_t &);
	friend BigIntegerForRsa operator % (const BigIntegerForRsa &, const long_t &);
	friend bool operator < (const BigIntegerForRsa &, const long_t &);
	friend bool operator > (const BigIntegerForRsa &, const long_t &);
	friend bool operator == (const BigIntegerForRsa &, const long_t &);
	friend bool operator <= (const BigIntegerForRsa &, const long_t &);
	friend bool operator >= (const BigIntegerForRsa &, const long_t &);
	friend bool operator != (const BigIntegerForRsa &, const long_t &);

	friend std::ostream & operator << (std::ostream &, const BigIntegerForRsa &);
	BigIntegerForRsa operator = (const std::string & str) { return (*this) = BigIntegerForRsa(str); }
	BigIntegerForRsa operator = (const long_t & num) { return (*this) = BigIntegerForRsa(num); }
private:
	BigIntegerForRsa trim();    // ȥ����λ���õ�0
	int hexToNum(char);    // ʮ�������ַ�ת��Ϊʮ������
public:
	static const int base_bit = 5;    // 2^5=32,������ÿλ�洢�Ķ�����λ��
	static const int base_char = 8;    // ��ɴ�������һλ��Ҫ��ʮ������λ��
	static const int base_int = 32;    // ������һλ��Ӧ�Ķ�����λ��
	static const int base_num = 0xffffffff;// ��ȡ��λ�ĸ���
	static const int base_temp = 0x1f;    // ��ȡģ32�������ĸ���
	static const BigIntegerForRsa ZERO;    // ����������0
	static const BigIntegerForRsa ONE;    // ����������1
	static const BigIntegerForRsa TWO;    // ����������2
	static const BigIntegerForRsa TEN;    // ����������10
	
private:
	bool is_negative;// �Ƿ�Ϊ����
		std::vector<base_t> data;// ��λ���ݴ洢,��λ�ں�
	class bit {    // ���ڴ���������Ķ����ƴ�����
	public:
		bit(const BigIntegerForRsa &);// ���ݴ�������ʼ��

		size_t size() { return length; }    // ���ش�������Ӧ�Ķ�����λ��
		bool at(size_t);    // ���ص�iλ�������Ƿ�Ϊ1
	private:
		std::vector<base_t> bit_vector;    // ���������ݴ洢,ÿһ��Ԫ�ض�Ӧ32λ������
		size_t length;    // �����Ƶ���λ��
	};
	friend class RSA;    // RSAΪ����Ԫ��
};

#endif // __BIGINTEGER_H__