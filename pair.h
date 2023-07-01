#pragma once
#include <cmath>
#include <valarray>
#include <iostream>
using namespace std;

class Pair
{
protected:
	int* rub, * kop;
public:
	Pair(int R, int K);
	Pair(const Pair& m);
	~Pair();
	Pair& operator=(const Pair& m);
	Pair& operator+=(const Pair& m);
    Pair& operator-=(const Pair& m);
	friend ostream& operator«(ostream& os, const Pair& p);
};

class Money : Pair
{
public:
	Money(int R, int K);
	Money(const Money& other);
	~Money();
	void Norm();
	void DiffNorm();
	Money& operator=(const Money& other);
	Money& operator+=(const Pair& other);
	Money& operator-=(const Pair& other);


};

ostream& operator«(ostream& os, const Pair& p)
{
	os << *p.rub << " " << *p.kop << endl;
	return os;
}