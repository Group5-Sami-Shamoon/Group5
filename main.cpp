#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct 
{
	char Firstname[20];
	char Lastname[20];
	float id;
	float Daily_Salary;
	/*
	char City[30];
	char Adress[30];
	int Phone_Number;
	*/
} Contractor;
void Ofek_Eilon();

int main()
{
	
	return 0;
}

void Ofek_Eilon()//רק ההתחלה
{
    int size=0;
	float num;
	int i=0;
	//קליטת המידע מהקובץ

	ifstream C_In;
	C_In.open("ContractorWorkers.txt");
	C_In >> size;
	Contractor* c = new Contractor[size];
	for(i=0;i<size;i++)
		C_In >> c[i].Firstname >> c[i].Lastname >> c[i].id;
	C_In.close();

	//החזרת המידע והשינוי שלו אם יש צורך

	ofstream C_Out;
	C_Out.open("ContractorWorkers.txt");
	C_Out << size << endl;
	for (i = 0; i < size; i++)
	{
		if (c[i].id==2)
		{
			cout << "Please Enter ID:";
			cin >> c[i].id;
			C_Out << c[i].Firstname << " " << c[i].Lastname << " " << c[i].id << endl;
		}
		else
			C_Out << c[i].Firstname << " " << c[i].Lastname << " " << c[i].id << endl;
	}
	C_Out.close();//close file
    //cout << "Welcome to ContractNest™." << endl << "Please enter the given to number to enter a category:" << endl;
    //cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Report hours" << endl << "5 - Work history" << endl;
    //cin >> menu;
    //switch (menu)
    //{
    //case 1:
    //	break;
    //case 2:
    //	break;
    //case 3:
    //	break;
    //case 4:
    //	break;
    //case 5:
    //	break;
    //}
}
