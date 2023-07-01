#include "pair.h"


using namespace std;


	Pair::Pair(int R, int K)
	{
		this->rub = new int(R);
		this->kop = new int(K);
	}

	Pair::Pair(const Pair& m)
	{
		this->rub = new int(*m.rub);
		this->kop = new int(*m.kop);
	}

	Pair::~Pair()
	{
		delete rub;
		delete kop;
	};

	Pair& Pair::operator=(const Pair& m)
	{
		*this->rub = *m.rub;
		*this->kop = *m.kop;
		return *this;
	}

	Pair& Pair::operator+=(const Pair& m)
	{
		Pair temp(*rub + *m.rub, *kop + *m.kop);
		return *this;
	}

	Pair& Pair::operator-=(const Pair& m)
	{
		Pair temp(*rub - *m.rub, *kop - *m.kop);
		return *this;
	}

	void Money::Norm()
	{
		*rub += *kop / 100;
		*kop = *kop % 100;
	}

	void Money::DiffNorm()
	{
		if (*kop < 0)
		{
			*rub -= 1;
			*kop += 100;
		}
	}

	Money::Money(int R, int K) :Pair(R, K)
	{
		Norm();
	}

	Money::Money(const Money& m) :Pair(m)
	{
		DiffNorm();
	}

	Money::~Money()
	{
		delete rub;
		delete kop;
	};

	Money& Money::operator=(const Money& m)
	{
		*this->rub = *m.rub;
		*this->kop = *m.kop;
		return *this;
	}

	Money& Money::operator+=(const Pair& m)
	{
		Pair temp = Pair::operator+=(m);
		Money* res = (Money*)temp;
		res->Norm();
		return res;
	}

	Money& Money::operator-=(const Pair& m)
	{
		Pair temp = Pair::operator-=(m);
		Money* res = (Money*) temp;
		res->DiffNorm();
		return res;
	}
	Matrix operator-(const Matrix& m1, const Matrix& m2)
	{
		Matrix temp(m1);
		return (temp -= m2);
	}