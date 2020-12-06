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


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string DATA_FILE_CON = "data_base_contractor";
const string DATA_FILE_EXT = "data_base_external";
const string DATA_FILE_COMP = "data_base_company";


void addNewContractor() 
{
    cout << "Please enter new contractor worker details: " << endl;

    string username, password, firstname, secondname, personalId, phoneNumber, city, adress,profession;

    cout << "enter profession worker: "; cin >> profession;
    cout << "enter firstname: "; cin >> firstname;
    cout << "enter secondname: "; cin >> secondname;
    cout << "enter personalId: "; cin >> personalId;
    cout << "enter phoneNumber: "; cin >> phoneNumber;
    cout << "enter city: "; cin >> city;
    cout << "enter adress: "; cin >> adress;
    cout << "enter username: "; cin >> username;
    cout << "enter password: "; cin >> password;

    ofstream file;
    file.open(DATA_FILE_CON + ".txt", ios_base::app);
    file << username << '' << password << '' << profession << '' << firstname << '' << secondname << '' << personalId << '' << phoneNumber << '' << city << '' << adress << endl;
    file.close();

    cout << "[NEW CONTRUCTOR] " << username << " added to the system." << endl;
}



void ExternalRegister()
{
    cout << "Please enter your details: " << endl;

    string username, password, firstname, secondname, personalId, phoneNumber, city, adress;

    cout << "enter firstname: "; cin >> firstname;
    cout << "enter secondname: "; cin >> secondname;
    cout << "enter personalId: "; cin >> personalId;
    cout << "enter phoneNumber: "; cin >> phoneNumber;
    cout << "enter city: "; cin >> city;
    cout << "enter adress: "; cin >> adress;
    cout << "enter username: "; cin >> username;
    cout << "enter password: "; cin >> password;

    ofstream file;
    file.open(DATA_FILE_EXT + ".txt", ios_base::app);
    file << username << '' << password << '' <<  firstname << '' << secondname << '' << personalId << '' << phoneNumber << '' << city << '*' << adress << endl;
    file.close();

    cout << "WELCOME!" << username << " to the CONTRACT_NEST." << endl;
}


void logIn_employee()
{
    string line,name_temp, password_temp;
    char x;
    ifstream file;
    cout << "USER NAME:\n ";
    cin >> name_temp;
    cout << "PASSWORD:\n ";
    cin >> password_temp;

    file.open(DATA_FILE_CON +".txt",ios::in);
    while(getline(file,line))
    {
        while(x!= '*')
        {

        }
    }
    file.close();
}

int main()
{
    logIn_employee();
    addNewContractor();
    ExternalRegister();
    logIn_employee();
    //int choice;
    //std::cout << "WELCOME!to the CONTRACT_NEST\n";
    //cout << "please choose:\n1-COMPANY EMPLOYEE\n2-CONTRACTOR WORKER\n3-EXTERNAL EMPLOYERS\n4-Exit\n";
    //cin >> choice;
    //while (choice =! 4)
    //{
    //    switch (choice)
    //    {
    //    case 1:
    //        if (logIn_employee() == true)
    //        {
    //            //menu comamy employee
    //            addNewContractor();
    //            //search
    //            //change
    //        }
    //        else
    //            cout << "Error! user not Found";
    //            break;

    //    case 2:
    //        break;

    //    case 3:
    //        ExternalRegister()
    //        break;

    //    default:
    //        printf("Error");
    //}
}