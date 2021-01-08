#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");

	int num;
	cout << "введите ваше число в 9иричной системе счисления " << endl;
	cin >> num;

	int size = 0;
	int temp = num;


	do
	{
		temp = temp / 10;
		size++;
	} while (temp != 0);

	cout << "size=" << size << endl;

	int temp1, temp2 = num;
	for (int i = 0; i < size; i++)   //проверка принадлежит ли число 9иричной системе счисления
	{
		temp1 = temp2 % 10;

		if (temp1 == 9)
		{
			cout << "ваше число неверное";
			break;
		}
		temp2 = temp2 / 10;

	}
	int newnum1 = 0;
	int temp3 = num;

	for (int i = 0; i < size; i++)
	{
		newnum1 = newnum1 + (temp3 % 10) * pow(9, i);
		temp3 = temp3 / 10;
	}

	cout << "newnum1=" << newnum1 << endl;


	int temp4 = newnum1;
	int size1 = 0;

	do
	{
		temp4 = temp4 / 11;
		size1++;
	} while (temp4 != 0);

	cout << "size1=" << size1 << endl;

	string newnum2;

	for (int i = size1 - 1; i >= 0; i--)
	{
		int rem = newnum1 % 11;
		string rem1 = to_string(rem);
	 

		switch (rem)
		{

		case 10:
			newnum2 += "A";
			break;

		default:
			newnum2 += rem1;

		}

		newnum1 = newnum1 / 11;
	}

	cout << "newnum2 = ";

	for (int i = size1 - 1; i >= 0; i--)
	{
		cout << newnum2[i];
	}
	
 
}

