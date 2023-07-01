#include <iostream>
#include "mpair.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int x, y;

	cout << "Введите первую пару чисел:" << endl;
	cin >> x >> y;
	Pair first(x, y);
	cout << "Введите вторую пару чисел:" << endl;
	cin >> x >> y;
	Pair second(x, y);

	Pair* z = first + second;
	Pair* g = first - second;

	cout << "Сумма чисел = " << *z;
	cout << "Разность чисел = " << *g << endl;

	int R, K;
	cout << "Введите первую сумму:" << "\nРубли: ";
	cin >> R;
	cout << "Копейки: ";
	cin >> K;
	Money cash1(R, K);

	cout << "Введите вторую сумму:" << "\nРубли: ";
	cin >> R;
	cout << "Копейки: ";
	cin >> K;
	Money cash2(R, K);
	Money* cashSum = cash1 + cash2;
	Money* cashDiff = cash1 - cash2;
	cout << "Сумма = " << *cashSum << "Разность = " << *cashDiff << endl;



	system("pause");
	return 0;
}