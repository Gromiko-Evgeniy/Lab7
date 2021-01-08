#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter a number in natural form:";
    cin >> num;

    int size_2sys = 0;
    int abs_num = abs(num);


    int temp1 = abs_num;
    while (temp1 != 0)
    {
        size_2sys++;
        temp1 = temp1 / 2;
    }
    cout << "size_2sys=" << size_2sys << endl;



    int num_2sys[20];
    int temp2 = size_2sys - 1;
    while (abs_num != 0)
    {
        num_2sys[temp2] = (abs_num % 2);
        temp2--;
        abs_num = abs_num / 2;

    }
    
    /*  cout << "num_2sys=";
    for (int i = 0; i < size_2sys; i++)
    {
        cout << num_2sys[i];
    }
    cout << endl;*/


    char num_strCode[9];
    num_strCode[8] = '\0';


    if (num > 0)
    {
        num_strCode[0] = '0';
    }
    else
    {
        num_strCode[0] = '1';
    }

    int number_of_0s = 7 - size_2sys;


    int temp3 = 0;
    for (int i = 1; i < 8; i++)
    {
        if (i <= number_of_0s)
        {
            num_strCode[i] = '0';
        }
        else
        {
            char temp = num_2sys[temp3] + '0';
            num_strCode[i] = temp;
            temp3++;
            
        }
    }
 
    cout << "Direct number code: ";
    for (int i = 0; i < 8; i++)
    {
        cout << num_strCode[i];
    }
    cout << endl;

}
