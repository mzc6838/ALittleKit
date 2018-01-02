#pragma once


#ifndef __RSA_H__
#define __RSA_H__

#include <iostream>
#include "BigIntegerForRsa.h"
class RSA {
public:
	RSA() {}
	RSA(const unsigned len) { init(len, *this, 12345); }    // 利用len初始化对象
	~RSA() {}

	void static init(const unsigned, RSA&, unsigned int);// 初始化,产生公私钥对

	BigIntegerForRsa encryptByPublic(const BigIntegerForRsa &);    // 公钥加密
	BigIntegerForRsa decryptByPrivate(const BigIntegerForRsa &);   // 私钥解密

	// 以下主要用于数字签名
	BigIntegerForRsa encryptByPrivate(const BigIntegerForRsa &);// 私钥加密
	BigIntegerForRsa decryptByPublic(const BigIntegerForRsa &);    // 公钥解密
protected:
	friend std::ostream & operator << (std::ostream &, const RSA &);// 输出相关数据
private:
	BigIntegerForRsa static createOddNum(unsigned);// 生成一个大奇数,参数为其长度
	bool static isPrime(const BigIntegerForRsa &, const unsigned);// 判断是否为素数
	BigIntegerForRsa static createRandomSmaller(const BigIntegerForRsa &);// 随机创建一个更小的数
	void static createPrime(unsigned, const unsigned, BigIntegerForRsa&, unsigned int);// 生成一个大素数,参数为其长度
	void createExponent(const BigIntegerForRsa &);// 根据提供的欧拉数生成公钥、私钥指数
public:
	BigIntegerForRsa n, e;// 公钥
private:
	BigIntegerForRsa d;// 私钥
	BigIntegerForRsa p, q;// 大素数p和q
	BigIntegerForRsa eul;// n的欧拉函数
};

#endif // __RSA_H__