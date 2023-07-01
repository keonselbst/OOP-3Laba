#include <iostream>
using namespace std;

class Pair
{
protected:
	int* rub, * kop;
public:
	Pair(int R, int K)
	{
		this->rub = new int(R);
		this->kop = new int(K);
	}

	Pair(const Pair& other)
	{
		this->rub = new int(*other.rub);
		this->kop = new int(*other.kop);
	}

	Pair& operator=(const Pair& other)
	{
		*this->rub = *other.rub;
		*this->kop = *other.kop;
		return *this;
	}

	Pair* operator+(const Pair& other)
	{
		Pair* tmp = new Pair(*rub + *other.rub, *kop + *other.kop);
		return tmp;
	}

	Pair* operator-(const Pair& other)
	{
		Pair* tmp = new Pair(*rub - *other.rub, *kop - *other.kop);
		return tmp;
	}

	~Pair()
	{
		delete rub;
		delete kop;
	};
	friend ostream& operator<<(std::ostream&, const Pair&);
};

ostream& operator<<(ostream& os, const Pair& p)
{
	os << *p.rub << " " << *p.kop << endl;
	return os;
}

class Money : public Pair
{
public:
	void Norm()
	{
		*rub += *kop / 100;
		*kop = *kop % 100;
	}

	void DiffNorm()
	{
		if (*kop < 0)
		{
			*rub -= 1;
			*kop += 100;
		}
	}

	Money(int R, int K) :Pair(R, K)
	{
		Norm();
	}

	Money(const Money& other) :Pair(other)
	{}

	Money& operator=(const Money& other)
	{
		*this->rub = *other.rub;
		*this->kop = *other.kop;
		return *this;
	}

	Money* operator+(const Pair& other)
	{
		Pair* tmp = Pair::operator+(other);
		Money* res = (Money*)tmp;
		res->Norm();
		return res;
	}

	Money* operator-(const Pair& other)
	{
		Pair* tmp = Pair::operator-(other);
		Money* res = (Money*)tmp;
		res->DiffNorm();
		return res;
	}

	~Money()
	{
		delete rub;
		delete kop;
	};
};