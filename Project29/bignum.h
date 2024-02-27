#pragma once
#ifndef bignumber_h
#define bignumber_h
#include<iostream>
#include<string>
using namespace std;
class bignum {
	friend istream& operator>>(istream&, bignum&);
	friend ostream& operator<<(ostream&, const bignum&);
public:
	bignum();
	bool operator==(const bignum&);
	bool operator!=(const bignum&);
	bignum operator+(const bignum&);
	bignum operator-(const bignum&);
	bignum& operator=(const bignum&);
	bool operator>(const bignum&);
	bool operator<(const bignum&);
	bool operator<=(const bignum&);
	bool operator>=(const bignum&);
	bignum& operator+=(const bignum&);
	bignum operator*(const bignum&);
	bignum operator++(int);
	bignum operator--(int);
	bignum operator-=(const bignum&);
	//bignum operator*=(const bignum&);
private:
	int size;
	int* a;
};
#endif