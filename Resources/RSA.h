#pragma once


#ifndef __RSA_H__
#define __RSA_H__

#include <iostream>
#include "BigIntegerForRsa.h"
class RSA {
public:
	RSA() {}
	RSA(const unsigned len) { init(len, *this, 0); }    // ����len��ʼ������
	~RSA() {}

	void static init(const unsigned, RSA&, unsigned int);// ��ʼ��,������˽Կ��

	BigIntegerForRsa encryptByPublic(const BigIntegerForRsa &);    // ��Կ����
	BigIntegerForRsa decryptByPrivate(const BigIntegerForRsa &);   // ˽Կ����

	void setd(const BigIntegerForRsa &);  //�ⲿ����˽Կd
	void setn(const BigIntegerForRsa &);  //�ⲿ���ù�Կn
	void sete(const BigIntegerForRsa &);  //�ⲻ���ù�Կe
	BigIntegerForRsa getd();              //���˽Կ

protected:
	friend std::ostream & operator << (std::ostream &, const RSA &);// ����������
private:
	BigIntegerForRsa static createOddNum(unsigned);// ����һ��������,����Ϊ�䳤��
	bool static isPrime(const BigIntegerForRsa &, const unsigned);// �ж��Ƿ�Ϊ����
	BigIntegerForRsa static createRandomSmaller(const BigIntegerForRsa &);// �������һ����С����
	void static createPrime(unsigned, const unsigned, BigIntegerForRsa&, unsigned int);// ����һ��������,����Ϊ�䳤��
	void createExponent(const BigIntegerForRsa &);// �����ṩ��ŷ�������ɹ�Կ��˽Կָ��
public:
	BigIntegerForRsa n, e;// ��Կ
private:
	BigIntegerForRsa d;// ˽Կ
	BigIntegerForRsa p, q;// ������p��q
	BigIntegerForRsa eul;// n��ŷ������
};

#endif // __RSA_H__