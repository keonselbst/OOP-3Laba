#include <iostream>
#include "mpair.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int x, y;

	cout << "������� ������ ���� �����:" << endl;
	cin >> x >> y;
	Pair first(x, y);
	cout << "������� ������ ���� �����:" << endl;
	cin >> x >> y;
	Pair second(x, y);

	Pair* z = first + second;
	Pair* g = first - second;

	cout << "����� ����� = " << *z;
	cout << "�������� ����� = " << *g << endl;

	int R, K;
	cout << "������� ������ �����:" << "\n�����: ";
	cin >> R;
	cout << "�������: ";
	cin >> K;
	Money cash1(R, K);

	cout << "������� ������ �����:" << "\n�����: ";
	cin >> R;
	cout << "�������: ";
	cin >> K;
	Money cash2(R, K);
	Money* cashSum = cash1 + cash2;
	Money* cashDiff = cash1 - cash2;
	cout << "����� = " << *cashSum << "�������� = " << *cashDiff << endl;



	system("pause");
	return 0;
}