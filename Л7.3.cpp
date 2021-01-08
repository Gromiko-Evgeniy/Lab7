#include <iostream>
#include <math.h>
using namespace std;



void transformTo_2sys(int* num_2sys, int num); 
void transformTo_AddCode(int num, int* num_2sys, char* num_AddCode);
void sum(char* num_AddCode1, char* num_AddCode2, int* num_addcode);

int main()
{
    int num1, num2;

    cout << "Enter number 1: ";
    cin >> num1;
    cout << endl;

    cout << "Enter number 2: ";
    cin >> num2;
    cout << endl;


    int num1_2sys[20];
    int num2_2sys[20];


    transformTo_2sys(num1_2sys, num1);
    transformTo_2sys(num2_2sys, num2);



    //вывод массивов с 2 кодом
    int size1_2sys = 0;
    int abs_num1 = abs(num1);

    int temp1 = abs_num1;
    while (temp1 != 0)
    {
        size1_2sys++;
        temp1 = temp1 / 2;
    }

    cout << "num1_2sys=";
    for (int i = 0; i < size1_2sys; i++)
    {
        cout << num1_2sys[i];
    }
    cout << endl;


    int size2_2sys = 0;
    int abs_num2 = abs(num2);


    int temp2 = abs_num2;
    while (temp2 != 0)
    {
        size2_2sys++;
        temp2 = temp2 / 2;
    }

    cout << "num2_2sys=";
    for (int i = 0; i < size2_2sys; i++)
    {
        cout << num2_2sys[i];
    }
    cout << endl;


    char num1_AddCode[9];
    num1_AddCode[8] = '\0';

    char num2_AddCode[9];
    num2_AddCode[8] = '\0';

    transformTo_AddCode(num1, num1_2sys, num1_AddCode);
    transformTo_AddCode(num2, num2_2sys, num2_AddCode);
    

    cout << "num1_AddCode" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << num1_AddCode[i];
    }

    cout << endl;
    cout << "num2_AddCode" << endl;


    for (int i = 0; i < 8; i++)
    {
        cout << num2_AddCode[i];
    }

    cout << endl;

    int sum_AddCode[9];


    sum(num1_AddCode, num2_AddCode, sum_AddCode);

    cout << "sum_AddCode " << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << sum_AddCode[i];
    }

    /*int sum_strCode[8];

    if (sum_AddCode[0] == 0)
    {
        sum_strCode[0] = 0;
    }
    else if (sum_AddCode[0] == 1)
    {
        sum_strCode[0] = 1;
    }*/

    cout << endl;
    cout << "Str_Code" << endl;
    if (sum_AddCode[0] == 0)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << sum_AddCode[i];
        }
    }
    else
    {
        int k = 7;
        while (sum_AddCode[k] != 1)
        {
            k--;
        }
        
       
        
        
       sum_AddCode[k] = 0;
       while (k != 7)
        {
           k++;
           sum_AddCode[k] = 1;
            
        }

        

        
        for (int i = 1; i < 8; i++)
        {
            if (sum_AddCode[i] == 1)
            {
                sum_AddCode[i] = 0;
            }
            else
            {
                sum_AddCode[i] = 1;
            }
        }
        for (int i = 0; i < 8; i++)
        {
            cout << sum_AddCode[i];
        }
    }





}



void transformTo_2sys(int* num_2sys, int num)
{
    int size_2sys = 0;
    int abs_num = abs(num);


    int temp1 = abs_num;
    while (temp1 != 0)
    {
        size_2sys++;
        temp1 = temp1 / 2;
    }

    int temp2 = size_2sys - 1;
    while (abs_num != 0)
    {
        num_2sys[temp2] = (abs_num % 2);
        temp2--;
        abs_num = abs_num / 2;

    }



}


void transformTo_AddCode(int num, int* num_2sys, char* num_AddCode)
{
    int size_2sys = 0;
    int abs_num = abs(num);

    int temp1 = abs_num;
    while (temp1 != 0)
    {
        size_2sys++;
        temp1 = temp1 / 2;
    }

    char num_strCode[9];
    num_strCode[8] = '\0';

    //

    if (num > 0)
    {
        num_strCode[0] = '0';
        num_AddCode[0] = '0';

    }
    else
    {
        num_strCode[0] = '1';
        num_AddCode[0] = '1';
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

   
    cout << "num_strCode=";
    for (int i = 0; i < 8; i++)
    {
        cout << num_strCode[i];
    }
    cout << endl;


    if (num > 0)
    {
        for (int i = 1; i < 8; i++)
        {
            num_AddCode[i] = num_strCode[i];
        }
    }
    else
    {
        for (int i = 1; i < 8; i++)
        {
            if (num_strCode[i] == '1')
            {
                num_AddCode[i] = '0';
            }
            else
            {
                num_AddCode[i] = '1';
            }
        }
        int i = 7;
        while (num_AddCode[i] != '0')
        {
            i--;
        }
        num_AddCode[i] = '1';
        for (int k = i + 1; k < 8; k++)
        {
            num_AddCode[k] = '0';
        }
    }
}


void sum(char* num_AddCode1, char* num_AddCode2, int* sum_addcode)
{

    for (int i = 7; i >= 0; i--)
    {
        int sum = (num_AddCode1[i] - '0') + (num_AddCode2[i] - '0');
        if (sum == 2)
        {
            sum_addcode[i] = 0;
            num_AddCode1[i - 1] = ((num_AddCode1[i - 1] - '0') + 1) + '0';
        }
        else if (sum == 3)
        {
            sum_addcode[i] = 1;
            num_AddCode1[i - 1] = ((num_AddCode1[i - 1] - '0') + 1) + '0';
        }
        else
        {
            sum_addcode[i] = sum;
        }

        if (i == 0 && sum == 2)
        {
            sum_addcode[i] = 0;
            sum_addcode[7] = 1;
        }
        if (i == 0 && sum == 3)
        {
            sum_addcode[i] = 1;
            sum_addcode[7] = 1;
        }
    }
}

