#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct 
{
	char ch;
	char Firstname[20];
	char Lastname[20];
	float id;
	float Daily_Salary;
	char City[30];
	char Adress[30];
	int Phone_Number;
} Contractor;

typedef struct
{
	int day;
	int month;
	int year;
	float S_Hour;
	float F_Hour;
	char employer[20];
	char employee[20];
	float Hour_Salary;
	float total;
	float premium;
} Job;


int main()
{
	float num;
	int i = 0, choise = 0, count = 0;
	//קליטת המידע מהקובץ

	ifstream C_In;
	C_In.open("ContractorWorkers.txt");
	Contractor c[SIZE] = { 0 };
	for (i = 0; i < SIZE; i++)
	{
		C_In >> c[i].ch;
		C_In >> c[i].Firstname;
		C_In >> c[i].Lastname;
		C_In >> c[i].id;
		C_In >> c[i].Daily_Salary;
		C_In >> c[i].City;
		C_In >> c[i].Adress;
		C_In >> c[i].Phone_Number;
	}
	C_In.close();

	//החזרת המידע והשינוי שלו אם יש צורך

	ofstream C_Out;
	C_Out.open("ContractorWorkers.txt");
	cout <<"               Contractor Menu               "<< endl;
	cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Work history" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		break;
	case 2:

		for (i = 0; i < SIZE; i++)
		{
			if (c[i].ch == 0)
				break;
			else
			{
				C_Out << c[i].ch << endl;
				C_Out << c[i].Firstname << endl;
				C_Out << c[i].Lastname << endl;
				C_Out << c[i].id << endl;
				C_Out << c[i].Daily_Salary << endl;
				C_Out << c[i].City << endl;
				C_Out << c[i].Adress << endl;
				C_Out << c[i].Phone_Number << endl;
			}
		}
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
	C_Out.close();//close file
	return 0;
}


