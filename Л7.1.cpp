#include <iostream>
#include <math.h>
#include <iomanip>
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
	} while (temp !=0);
	
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
	int size1=0;

	do
	{
		temp4 = temp4 / 11;
		size1++;
	} while (temp4 != 0);

	cout << "size1=" << size1 << endl;

	char arr[100];
	 
	for (int i = size1-1; i >= 0; i--)
	{
		 int rem = newnum1 % 11;
		 char temp5 = rem + '0';


		switch (rem)
		{
		case 0:
			arr[i] = temp5;
			break;

		case 1:
			arr[i] = temp5;
			break;

		case 2:
			arr[i] = temp5;
			break;

		case 3:
			arr[i] = temp5;
			break;

		case 4:
			arr[i] = temp5;
			break;

		case 5:
			arr[i] = temp5;
			break;

		case 6:
			arr[i] = temp5;
			break;

		case 7:
			arr[i] = temp5;
			break;

		case 8:
			arr[i] = temp5;
			break;

		case 9:
			arr[i] = temp5;
			break;

		case 10:
			arr[i] = 'A';
			break;
		}

		newnum1 = newnum1 / 11;
	}  


	for (int i = 0; i < size1; i++)
	{
		cout << arr[i];
	}
}

