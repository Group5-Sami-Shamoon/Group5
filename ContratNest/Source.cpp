#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#define SIZE2 25
#define LENGTH 20
#define RED "\033[1;31m" //color red
#define GREEN "\033[1;32m" //color green
#define YELLOW "\033[1;33m" //color yellow
#define BLUE "\033[1;34m" //color blue
#define PINK "\033[1;35m" //color pink
#define MAGENTA "\033[1;36m" //color magenta
#define WHITE "\033[0m"    //color reset to white
#define BLOCKCOLOR "\033[1;100;30m" //block of color
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct
{
	char c[LENGTH];
	int index;
} City;

typedef struct
{
	int day[SIZE2] = { 0 };
	int month[SIZE2] = { 0 };
	int year[SIZE2] = { 0 };
} Availabilty;

typedef struct
{
	int seniority;
	int day;
	int month;
	int year;
	float Hour_Salary;
	char Location[LENGTH];
	char Profession[LENGTH];
} Booking;

typedef struct
{
	char ch;
	int day;
	int month;
	int year;
	int S_Hour;
	int S_Min;
	int F_Hour;
	int F_Min;
	float Hour_Salary;
	char employer[LENGTH];
	char employee[LENGTH];
	int External_id;
	int Contractor_id;
	int premium_hours;
	int premium_mins;
} Job;

typedef struct
{
	char username[LENGTH];
	char password[LENGTH];
	char ch;
	char Firstname[LENGTH];
	char Lastname[LENGTH];
	int id;
	char City[LENGTH];
	char Adress[LENGTH];
	int Phone_Number;
} CompanyEmployee;

typedef struct
{
	char username[LENGTH];
	char password[LENGTH];
	char ch;
	char Firstname[LENGTH];
	char Lastname[LENGTH];
	int id;
	char City[LENGTH];
	char Adress[LENGTH];
	int Phone_Number;
} ExternalEmployee;

typedef struct
{
	char ch;
	char username[LENGTH];
	char password[LENGTH];
	char Firstname[LENGTH];
	char Lastname[LENGTH];
	int id;
	float Hourly_Pay;
	char City[LENGTH];
	char Adress[LENGTH];
	int Phone_Number;
	char profession[LENGTH];
	int seniority;
	int CheckInOut;
	Availabilty a;
} Contractor;

bool Exist_Contractor_ID(Contractor* c, int id);
bool Exist_Company_ID(CompanyEmployee* c, int id);
bool Exist_External_ID(ExternalEmployee* c, int id);
bool Exist_ID(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int id);
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void ContractorMenu(Contractor* c, Job* c4, int index);
void CompanyEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, int index);
void ExternalEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, int index);
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void addNewContractor(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void login_CE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void login_C(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void login_EE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
bool Exist_Contractor_Username(Contractor* c, char username[]);
bool Exist_Company_Username(CompanyEmployee* c, char username[]);
bool Exist_External_Username(ExternalEmployee* c, char username[]);
bool Exist_Username(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, char username[]);
bool Valid_Name(char name[]);
void Salary_Calculation(Contractor* c2, Job* c4, int index);
void Report_Hours(Contractor* c2, Job* c4, int index);
bool CheckAvibillity(Contractor* c2, int day, int month, int year, int index);
bool Checkprofession(Contractor* c2, char profession[], int index);
bool CheckPlace(Contractor* c2, char city[], int index);
bool Checkpay(Contractor* c2, float pay_hour, int index);
bool CheckVetek(Contractor* c2, int vetek2, int index);
void Search(Contractor* c2, ExternalEmployee* c3, Job* c4, int index1);
void Book(Booking b, Contractor* c2, ExternalEmployee* c3, Job* c4, int index1, int index2);
void VacationRequest(Contractor* c2, int index);
bool Date_Vaild(Contractor* c2, int day, int month, int year, int index);
void workHistory(ExternalEmployee* c3, Job* c4, int index);
void printJob(Job c4);
void ContractorWorkHistory(Contractor* c2, int index);
void printContractor(Contractor c2);
void FindContractors(Contractor* c2);
bool SameHourlyPay(Contractor* c2, float pay_hour, int index);
bool CheckAttendanceClock(Contractor* c2, int In_Out, int index);
void Statistic_Analysis(Contractor* c2, Job* c4);
bool CheckName(Contractor* c2, char name[], int index);
int main()
{
	int i = 0, choise = 0, count = 0;
	CompanyEmployee c1[SIZE] = { 0 };
	Contractor c2[SIZE] = { 0 };
	ExternalEmployee c3[SIZE] = { 0 };
	Job c4[SIZE] = { 0 };
	City c5[SIZE] = { 0 };
	ReadFromFile(c1, c2, c3, c4);
	First_Menu(c1, c2, c3, c4);
	WriteToFile(c1, c2, c3, c4);
	return 0;
}
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int choice, choice2;
	cout << "               ContactNest               " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1.Company Employee" << endl << "2.Contractor" << endl << "3.External employee" << endl << "4.Exit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		login_CE(c1, c2, c3, c4);
		break;
	case 2:
		login_C(c1, c2, c3, c4);
		break;
	case 3:
		cout << "1.Register" << endl << "2.Login" << endl;
		cin >> choice2;
		if (choice2 == 1)
			Register(c1, c2, c3, c4);
		else if (choice2 == 2)
			login_EE(c1, c2, c3, c4);
		break;
	case 4:
		cout << "Bye Bye." << endl;
		break;
	default:
		cout << "Error" << endl;
	}
}
void ContractorMenu(Contractor* c, Job* c4, int index)
{
	int choise;
	cout << endl;
	cout << "               Contractor Menu               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1 - Report Hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Work history" << endl << "5 - Exit." << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		Report_Hours(c, c4, index);
		break;
	case 2:
		Salary_Calculation(c, c4, index);
		break;
	case 3:
		VacationRequest(c, index);
		break;
	case 4:
		ContractorWorkHistory(c, index);
		break;
	case 5:
		cout << "Bye Bye." << endl;
		break;
	default:
		break;
	}
}
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int i = 0;
	string c = " ";
	ifstream C_In1;
	C_In1.open("CompanyEmployees.txt");
	for (i = 0; i < SIZE; i++)
	{
		C_In1 >> c1[i].ch;
		C_In1 >> c1[i].username;
		C_In1 >> c1[i].password;
		C_In1 >> c1[i].Firstname;
		C_In1 >> c1[i].Lastname;
		C_In1 >> c1[i].id;
		C_In1 >> c1[i].City;
		C_In1 >> c1[i].Adress;
		C_In1 >> c1[i].Phone_Number;
	}
	C_In1.close();

	ifstream C_In2;
	C_In2.open("ContractorWorkers.txt");
	for (i = 0; i < SIZE; i++)
	{
		C_In2 >> c2[i].ch;
		C_In2 >> c2[i].username;
		C_In2 >> c2[i].password;
		C_In2 >> c2[i].Firstname;
		C_In2 >> c2[i].Lastname;
		C_In2 >> c2[i].id;
		C_In2 >> c2[i].Hourly_Pay;
		C_In2 >> c2[i].City;
		C_In2 >> c2[i].Adress;
		C_In2 >> c2[i].Phone_Number;
		C_In2 >> c2[i].profession;
		C_In2 >> c2[i].seniority;
		C_In2 >> c2[i].CheckInOut;
		for (int j = 0; j < SIZE2; j++)
		{
			C_In2 >> c2[i].a.day[j];
		}
		for (int j = 0; j < SIZE2; j++)
		{
			C_In2 >> c2[i].a.month[j];
		}
		for (int j = 0; j < SIZE2; j++)
		{
			C_In2 >> c2[i].a.year[j];
		}
	}
	C_In2.close();

	ifstream C_In3;
	C_In3.open("ExternalEmployees.txt");
	for (i = 0; i < SIZE; i++)
	{
		C_In3 >> c3[i].ch;
		C_In3 >> c3[i].username;
		C_In3 >> c3[i].password;
		C_In3 >> c3[i].Firstname;
		C_In3 >> c3[i].Lastname;
		C_In3 >> c3[i].id;
		C_In3 >> c3[i].City;
		C_In3 >> c3[i].Adress;
		C_In3 >> c3[i].Phone_Number;
	}
	C_In3.close();

	ifstream C_In4;
	C_In4.open("Booking Database.txt");
	for (i = 0; i < SIZE; i++)
	{
		C_In4 >> c4[i].ch;
		C_In4 >> c4[i].day;
		C_In4 >> c4[i].month;
		C_In4 >> c4[i].year;
		C_In4 >> c4[i].S_Hour;
		C_In4 >> c4[i].S_Min;
		C_In4 >> c4[i].F_Hour;
		C_In4 >> c4[i].F_Min;
		C_In4 >> c4[i].Hour_Salary;
		C_In4 >> c4[i].employer;
		C_In4 >> c4[i].employee;
		C_In4 >> c4[i].External_id;
		C_In4 >> c4[i].Contractor_id;
		C_In4 >> c4[i].premium_hours;
		C_In4 >> c4[i].premium_mins;
	}
	C_In4.close();
}
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int i = 0;
	string c = " ";
	ofstream C_Out1;
	C_Out1.open("CompanyEmployees.txt");
	for (i = 0; i < SIZE; i++)
	{
		if (c1[i].ch == 0)
			break;
		else
		{
			C_Out1 << c1[i].ch << endl;
			C_Out1 << c1[i].username << endl;
			C_Out1 << c1[i].password << endl;
			C_Out1 << c1[i].Firstname << endl;
			C_Out1 << c1[i].Lastname << endl;
			C_Out1 << c1[i].id << endl;
			C_Out1 << c1[i].City << endl;
			C_Out1 << c1[i].Adress << endl;
			C_Out1 << c1[i].Phone_Number << endl;
		}
	}
	C_Out1.close();//close file

	ofstream C_Out2;
	C_Out2.open("ContractorWorkers.txt");
	for (i = 0; i < SIZE; i++)
	{
		if (c2[i].ch == 0)
			break;
		else
		{
			C_Out2 << c2[i].ch << endl;
			C_Out2 << c2[i].username << endl;
			C_Out2 << c2[i].password << endl;
			C_Out2 << c2[i].Firstname << endl;
			C_Out2 << c2[i].Lastname << endl;
			C_Out2 << c2[i].id << endl;
			C_Out2 << c2[i].Hourly_Pay << endl;
			C_Out2 << c2[i].City << endl;
			C_Out2 << c2[i].Adress << endl;
			C_Out2 << c2[i].Phone_Number << endl;
			C_Out2 << c2[i].profession << endl;
			C_Out2 << c2[i].seniority << endl;
			C_Out2 << c2[i].CheckInOut << endl;
			for (int j = 0; j < SIZE2; j++)
			{
				C_Out2 << c2[i].a.day[j];
				C_Out2 << endl;
			}
			for (int j = 0; j < SIZE2; j++)
			{
				C_Out2 << c2[i].a.month[j];
				C_Out2 << endl;
			}
			for (int j = 0; j < SIZE2; j++)
			{
				C_Out2 << c2[i].a.year[j];
				C_Out2 << endl;
			}
		}
	}
	C_Out2.close();//close file

	ofstream C_Out3;
	C_Out3.open("ExternalEmployees.txt");
	for (i = 0; i < SIZE; i++)
	{
		if (c3[i].ch == 0)
			break;
		else
		{
			C_Out3 << c3[i].ch << endl;
			C_Out3 << c3[i].username << endl;
			C_Out3 << c3[i].password << endl;
			C_Out3 << c3[i].Firstname << endl;
			C_Out3 << c3[i].Lastname << endl;
			C_Out3 << c3[i].id << endl;
			C_Out3 << c3[i].City << endl;
			C_Out3 << c3[i].Adress << endl;
			C_Out3 << c3[i].Phone_Number << endl;
		}

	}
	C_Out3.close();//close file

	ofstream C_Out4;
	C_Out4.open("Booking Database.txt");
	for (i = 0; i < SIZE; i++)
	{
		if (c4[i].ch == 0)
			break;
		else
		{
			C_Out4 << c4[i].ch << endl;
			C_Out4 << c4[i].day << endl;
			C_Out4 << c4[i].month << endl;
			C_Out4 << c4[i].year << endl;
			C_Out4 << c4[i].S_Hour << endl;
			C_Out4 << c4[i].S_Min << endl;
			C_Out4 << c4[i].F_Hour << endl;
			C_Out4 << c4[i].F_Min << endl;
			C_Out4 << c4[i].Hour_Salary << endl;
			C_Out4 << c4[i].employer << endl;
			C_Out4 << c4[i].employee << endl;
			C_Out4 << c4[i].External_id << endl;
			C_Out4 << c4[i].Contractor_id << endl;
			C_Out4 << c4[i].premium_hours << endl;
			C_Out4 << c4[i].premium_mins << endl;
		}
	}
	C_Out4.close();
}
void addNewContractor(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
{
	char username[LENGTH];
	char name[LENGTH];
	int id;
	for (int i = 0; i < SIZE; i++)
	{
		if (c2[i].ch == 0)
		{
			cout << "Please enter new contractor details" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			c2[i].ch = '*';
			cout << "enter username:";
			cin >> username;
			while (Exist_Username(c1, c2, c3, username) == true)
			{
				cout << "username is already exist, please try agian." << endl;
				cout << "enter username:";
				cin >> username;
			}
			strcpy(c2[i].username, username);
			cout << "enter password:";
			cin >> c2[i].password;
			cout << "enter firstname:";
			cin >> name;
			while (Valid_Name(name) == false)
			{
				cout << "the name is invaild, please try agian." << endl;
				cout << "enter firstname:";
				cin >> name;
			}
			strcpy(c2[i].Firstname, name);
			cout << "enter lastname:";
			cin >> name;
			while (Valid_Name(name) == false)
			{
				cout << "the name is invaild, please try agian." << endl;
				cout << "enter lastname:";
				cin >> name;
			}
			strcpy(c2[i].Lastname, name);
			cout << "enter ID:";
			cin >> id;
			while (Exist_ID(c1, c2, c3, id) == true)
			{
				cout << "Id is already exist, please try agian." << endl;
				cout << "enter ID:";
				cin >> id;
			}
			c2[i].id = id;
			cout << "enter hourly pay:";
			cin >> c2[i].Hourly_Pay;
			cout << "enter city:";
			cin >> c2[i].City;
			cout << "enter adress:";
			cin >> c2[i].Adress;
			cout << "enter phoneNumber:";
			cin >> c2[i].Phone_Number;
			cout << "enter profession:";
			cin >> c2[i].profession;
			cout << "enter seniority:";
			cin >> c2[i].seniority;
			cout << "[NEW CONTRACOTR] " << c2[i].username << " added to the system." << endl;
			break;
		}
	}
}
void login_CE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int choice = 0;
	char username[LENGTH];
	char password[LENGTH];
	int index = 0;
	cout << "Please enter username:";
	cin >> username;
	while (Exist_Company_Username(c1, username) == false)
	{
		cout << "No such a username in the database please try agian." << endl;
		cout << "Please enter username:";
		cin >> username;
	}
	cout << "Please enter password:";
	cin >> password;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c1[i].username) == 0 && strcmp(password, c1[i].password) == 0)
		{
			cout << "Vaild username and password, welcome " << c1[i].Firstname << endl;
			index = i;
			CompanyEmployeeMenu(c1, c2, c3, c4, index);
		}
		else if (strcmp(username, c1[i].username) == 0 && !(strcmp(password, c1[i].password) == 0))
		{
			while (!(strcmp(password, c1[i].password) == 0) && choice != 2)
			{
				cout << "InVaild password, want to try agian?" << endl << "1.Yes" << endl << "2.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please enter password again:";
					cin >> password;
					if (strcmp(password, c1[i].password) == 0)
					{
						cout << "Vaild username and password, welcome " << c1[i].Firstname << endl;
						index = i;
						CompanyEmployeeMenu(c1, c2, c3, c4, index);
					}
					break;
				case 2:
					cout << "Bye Bye." << endl;
					break;
				default:
					cout << "No Such An Option, please try agian." << endl;
					break;
				}
			}
		}
	}
}
void login_C(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int choice = 0;
	char username[LENGTH];
	char password[LENGTH];
	int index = 0;
	cout << "Please enter username:";
	cin >> username;
	while (Exist_Contractor_Username(c2, username) == false)
	{
		cout << "No such a username in the database please try agian." << endl;
		cout << "Please enter username:";
		cin >> username;
	}
	cout << "Please enter password:";
	cin >> password;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c2[i].username) == 0 && strcmp(password, c2[i].password) == 0)
		{
			cout << "Vaild username and password, welcome " << c2[i].Firstname << endl;
			index = i;
			ContractorMenu(c2, c4, index);
		}
		else if (strcmp(username, c2[i].username) == 0 && !(strcmp(password, c2[i].password) == 0))
		{
			while (!(strcmp(password, c2[i].password) == 0) && choice != 2)
			{
				cout << "InVaild password, want to try agian?" << endl << "1.Yes" << endl << "2.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please enter password again:";
					cin >> password;
					if (strcmp(password, c2[i].password) == 0)
					{
						cout << "Vaild username and password, welcome " << c2[i].Firstname << endl;
						index = i;
						ContractorMenu(c2, c4, index);
					}
					break;
				case 2:
					cout << "Bye Bye." << endl;
					break;
				default:
					cout << "No Such An Option, please try agian." << endl;
					break;
				}
			}
		}
	}
}
void login_EE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int choice = 0;
	char username[LENGTH];
	char password[LENGTH];
	int index = 0;
	cout << "Please enter username:";
	cin >> username;
	while (Exist_External_Username(c3, username) == false)
	{
		cout << "No such a username in the database please try agian." << endl;
		cout << "Please enter username:";
		cin >> username;
	}
	cout << "Please enter password:";
	cin >> password;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c3[i].username) == 0 && strcmp(password, c3[i].password) == 0)
		{
			cout << "Vaild username and password, welcome " << c3[i].Firstname << endl;
			index = i;
			ExternalEmployeeMenu(c1, c2, c3, c4, index);
		}
		else if (strcmp(username, c3[i].username) == 0 && !(strcmp(password, c3[i].password) == 0))
		{
			while (!(strcmp(password, c3[i].password) == 0) && choice != 2)
			{
				cout << "InVaild password, want to try agian?" << endl << "1.Yes" << endl << "2.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please enter password again:";
					cin >> password;
					if (strcmp(password, c3[i].password) == 0)
					{
						cout << "Vaild username and password, welcome " << c3[i].Firstname << endl;
						index = i;
						ExternalEmployeeMenu(c1, c2, c3, c4, index);
					}
					break;
				case 2:
					cout << "Bye Bye." << endl;
					break;
				default:
					cout << "No Such An Option, please try agian." << endl;
					break;
				}
			}
		}
	}
}
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	char username[LENGTH];
	char name[LENGTH];
	int id;
	for (int i = 0; i < SIZE; i++)
	{
		if (c3[i].ch == 0)
		{
			cout << "Please enter new external employee details" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			c3[i].ch = '*';
			cout << "enter username:";
			cin >> username;
			while (Exist_Username(c1, c2, c3, username) == true)
			{
				cout << "username is already exist, please try agian." << endl;
				cout << "enter username:";
				cin >> username;
			}
			strcpy(c3[i].username, username);
			cout << "enter password:";
			cin >> c3[i].password;
			cout << "enter firstname:";
			cin >> name;
			while (Valid_Name(name) == false)
			{
				cout << "the name is invaild, please try agian." << endl;
				cout << "enter firstname:";
				cin >> name;
			}
			strcpy(c3[i].Firstname, name);
			cout << "enter lastname:";
			cin >> name;
			while (Valid_Name(name) == false)
			{
				cout << "the name is invaild, please try agian." << endl;
				cout << "enter lastname:";
				cin >> name;
			}
			strcpy(c3[i].Lastname, name);
			cout << "enter ID:";
			cin >> id;
			while (Exist_ID(c1, c2, c3, id) == true)
			{
				cout << "Id is already exist, please try agian." << endl;
				cout << "enter ID:";
				cin >> id;
			}
			c3[i].id = id;
			cout << "enter city:";
			cin >> c3[i].City;
			cout << "enter adress:";
			cin >> c3[i].Adress;
			cout << "enter phoneNumber:";
			cin >> c3[i].Phone_Number;
			cout << "[NEW ACCOUNT] " << c3[i].username << " added to the system." << endl;
			break;
		}
	}
}
void ExternalEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, int index)
{
	int choise;
	cout << endl;
	cout << "               External Employee Menu               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1 - Search" << endl << "2 - History" << endl << "3 - Exit" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		Search(c2, c3, c4, index);
		break;
	case 2:
		workHistory(c3, c4, index);
		break;
	case 3:
		cout << "Bye Bye." << endl;
		break;
	default:
		break;
	}
}
void CompanyEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, int index)
{
	int choise;
	cout << endl;
	cout << "               Company Employee Menu               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1 - Add Contractor" << endl << "2 - Statistic Analysis" << endl << "3 - Contractor Inforomation" << endl << "4 - Exit." << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		addNewContractor(c1, c2, c3);
		break;
	case 2:
		Statistic_Analysis(c2, c4);
		break;
	case 3:
		FindContractors(c2);
		break;
	case 4:
		cout << "Bye Bye." << endl;
		break;
	default:
		break;
	}
}
bool Exist_Contractor_Username(Contractor* c, char username[])
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c[i].username) == 0)
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_Company_Username(CompanyEmployee* c, char username[])
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c[i].username) == 0)
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_External_Username(ExternalEmployee* c, char username[])
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c[i].username) == 0)
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_Username(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, char username[])
{
	if ((Exist_External_Username(c3, username) == false) && (Exist_Contractor_Username(c2, username) == false) && (Exist_Company_Username(c1, username) == false))
		return false;
	else
		return true;
}
bool Valid_Name(char name[])
{
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[0] > 'Z' || name[0] < 'A')
			return false;
		if ((name[i] > 'z' || name[i] < 'a') && i != 0)
			return false;
	}
	return true;
}
bool Exist_Contractor_ID(Contractor* c, int id)
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (id == c[i].id)
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_Company_ID(CompanyEmployee* c, int id)
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (id == c[i].id)
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_External_ID(ExternalEmployee* c, int id)
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (id == c[i].id)
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_ID(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int id)
{
	if ((Exist_External_ID(c3, id) == false) && (Exist_Contractor_ID(c2, id) == false) && (Exist_Company_ID(c1, id) == false))
		return false;
	else
		return true;
}
void Salary_Calculation(Contractor* c2, Job* c4, int index)
{
	int month;
	int year;
	float sum = 0;
	float HoursWorked = 0;
	float MinsWorked = 0;
	float Nosafot_hours;
	float Nosafot_mins;
	int count = 0;
	cout << "Please enter year you want to calculate:";
	cin >> year;
	cout << "Please enter month you want to calculate:";
	cin >> month;
	for (int i = 0; i < SIZE; i++)
	{
		if (c2[index].id == c4[i].Contractor_id)
		{
			if (c4[i].year == year)
			{
				if (c4[i].month == month)
				{
					count++;

					if (c4[i].F_Min >= c4[i].S_Min)
					{
						HoursWorked = (c4[i].F_Hour - c4[i].S_Hour)*c4[i].Hour_Salary;
						MinsWorked = ((c4[i].F_Min - c4[i].S_Min) / 60)*c4[i].Hour_Salary;
					}
					else
					{
						HoursWorked = (c4[i].F_Hour - c4[i].S_Hour - 1)*c4[i].Hour_Salary;
						MinsWorked = ((60 - c4[i].S_Min + c4[i].F_Min) / 60)*c4[i].Hour_Salary;
					}
					Nosafot_hours = c4[i].premium_hours*c4[i].Hour_Salary*1.15;
					Nosafot_mins = (c4[i].premium_mins / 60)*c4[i].Hour_Salary*1.15;
					sum = sum + Nosafot_mins + Nosafot_hours + HoursWorked + MinsWorked;
				}
			}
		}
	}
	if (count != 0)
		cout << "You earned " << sum << " in this month in the year" << endl;
	else
		cout << "You didnt work in this month in this year" << endl;
}
void Report_Hours(Contractor* c2, Job* c4, int index)
{
	int day, month, year, count = 0;
	int start_hour, start_min, finish_hour, finish_min, premium_hours, premium_mins;
	cout << "Please enter the day you want to report:";
	cin >> day;
	cout << "Please enter the month you want to report:";
	cin >> month;
	cout << "Please enter the year you want to report:";
	cin >> year;
	for (int i = 0; i < SIZE; i++)
	{
		if (c2[index].id == c4[i].Contractor_id)
		{
			if (c4[i].year == year)
			{
				if (c4[i].month == month)
				{
					if (c4[i].day == day)
					{
						count++;
						if (c2[index].CheckInOut == 0)
						{
							cout << "    Enter the shift    " << endl;
							cout << "-----------------------" << endl;
							cout << "Please enter the start hour to report:";
							cin >> start_hour;
							c4[i].S_Hour = start_hour;
							cout << "Please enter the start min to report:";
							cin >> start_min;
							c4[i].S_Min = start_min;
							cout << "have a nice shift!!" << endl;
							c2[index].CheckInOut = 1;
						}
						else
						{
							cout << "    Exit the shift    " << endl;
							cout << "----------------------" << endl;
							cout << "Please enter the finish hour to report:";
							cin >> finish_hour;
							c4[i].F_Hour = finish_hour;
							cout << "Please enter the finish min to report:";
							cin >> finish_min;
							c4[i].F_Min = finish_min;
							cout << "Please enter premium hours to report:";
							cin >> premium_hours;
							c4[i].premium_hours = premium_hours;
							cout << "Please enter premium hours to report:";
							cin >> premium_mins;
							c4[i].premium_mins = premium_mins;
							cout << "We Hope you had a nice shift, have a good day!" << endl;
							c2[index].CheckInOut = 0;
						}
					}
				}
			}
		}
	}
	if (count != 0)
		cout << "Report Succceded." << endl;
	else
		cout << "You didnt work in this day in this month in this year" << endl;


}
bool CheckAvibillity(Contractor* c2, int day, int month, int year, int index)
{
	for (int j = 0; j < SIZE2; j++)
	{
		if (c2[index].a.day[j] == day && c2[index].a.month[j] == month && c2[index].a.year[j] == year)
			return false;
	}
	return true;
}
bool Checkprofession(Contractor* c2, char profession[], int index)
{
	if (strcmp(c2[index].profession, profession) == 0)
		return true;
	return false;
}
bool CheckPlace(Contractor* c2, char city[], int index)
{
	if (strcmp(c2[index].City, city) == 0)
		return true;
	return false;
}
bool CheckName(Contractor* c2, char name[], int index)
{
	if (strcmp(c2[index].Firstname, name) == 0)
		return true;
	return false;
}
bool Checkpay(Contractor* c2, float pay_hour, int index)
{
	if (c2[index].Hourly_Pay <= pay_hour)
		return true;
	return false;
}
bool SameHourlyPay(Contractor* c2, float pay_hour, int index)
{
	if (c2[index].Hourly_Pay == pay_hour)
		return true;
	return false;
}
bool CheckVetek(Contractor* c2, int vetek2, int index)
{
	if (c2[index].seniority >= vetek2)
		return true;
	return false;
}
bool CheckAttendanceClock(Contractor* c2, int In_Out, int index)
{
	if (c2[index].CheckInOut == In_Out)
		return true;
	return false;
}
void Search(Contractor* c2, ExternalEmployee* c3, Job* c4, int index1)
{
	int day, month, year;
	int count = 0;
	int index2 = 0;
	char profession[LENGTH];
	float pay_hour;
	char city[LENGTH];
	int vetek;
	Booking b = { 0 };
	cout << "Here you can serch the contractor for you!" << endl;
	cout << "------------------------------------------" << endl;
	cout << "There are some categories for you" << endl;
	cout << "1. Avibillity" << endl << "2. Profession" << endl << "3.Payment" << endl << "4.Place" << endl << "5.Seniority" << endl;
	cout << "Please enter day:";
	cin >> day;
	cout << "Please enter month:";
	cin >> month;
	cout << "Please enter year:";
	cin >> year;
	cout << "Please enter profession:";
	cin >> profession;
	cout << "Please enter payment:";
	cin >> pay_hour;
	cout << "Please enter place:";
	cin >> city;
	cout << "Please enter seniority:";
	cin >> vetek;
	for (int i = 0; i < SIZE; i++)
	{
		if (CheckAvibillity(c2, day, month, year, i) == true && Checkprofession(c2, profession, i) == true && Checkpay(c2, pay_hour, i) == true && CheckPlace(c2, city, i) == true && CheckVetek(c2, vetek, i) == true)
		{
			cout << c2[i].Firstname << " " << c2[i].Lastname << " " << "from " << c2[i].City << endl;
			b.Hour_Salary = pay_hour;
			strcpy(b.Location, city);
			strcpy(b.Profession, profession);
			b.seniority = vetek;
			b.day = day;
			b.month = month;
			b.year = year;
			count++;
			Book(b, c2, c3, c4, index1, i);
			break;
		}
	}
	if (count == 0)
	{
		cout << "------------------------------" << endl;
		cout << "     No contractors found     " << endl;
		cout << "------------------------------" << endl;
	}
}
void Book(Booking b, Contractor* c2, ExternalEmployee* c3, Job* c4, int index1, int index2)
{

	for (int j = 0; j < SIZE2; j++)
	{
		if (c2[index2].a.day[j] == 0 && c2[index2].a.month[j] == 0 && c2[index2].a.year[j] == 0)
		{
			c2[index2].a.day[j] = b.day;
			c2[index2].a.month[j] = b.month;
			c2[index2].a.year[j] = b.year;
			break;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		if (c4[i].ch == 0)
		{
			c4[i].ch = '*';
			c4[i].day = b.day;
			c4[i].month = b.month;
			c4[i].year = b.year;
			cout << "Please enter start hour:";
			cin >> c4[i].S_Hour;
			cout << "Please enter start min:";
			cin >> c4[i].S_Min;
			cout << "Please enter finish hour:";
			cin >> c4[i].F_Hour;
			cout << "Please enter finish min:";
			cin >> c4[i].F_Min;
			c4[i].Hour_Salary = b.Hour_Salary;
			strcpy(c4[i].employer, c3[index1].Firstname);
			strcpy(c4[i].employee, c2[index2].Firstname);
			c4[i].External_id = c3[index1].id;
			c4[i].Contractor_id = c2[index2].id;
			c4[i].premium_hours = 0;
			c4[i].premium_mins = 0;
			break;
		}
	}
}
void VacationRequest(Contractor* c2, int index)
{
	int day;
	int month;
	int year;
	int amount = 0;
	int count = 0;
	int count2 = 0;
	cout << "              Vacation Report              " << endl;
	cout << "--------------------------------------------" << endl << endl;
	cout << "Please enter how many spesific days you want to take a vaction (Days Need To Be One After Another): ";
	cin >> amount;
	for (int i = 0; i < amount; i++)
	{
		if (i != 0)
			cout << "Please enter the next vaction day." << endl;
		cout << "enter day you want to take a vaction:";
		cin >> day;
		cout << "enter month you want to take a vaction:";
		cin >> month;
		cout << "enter year you want to take a vaction:";
		cin >> year;
		cout << endl;
		while (Date_Vaild(c2, day, month, year, index) == false)
		{
			cout << "This date is not available, please try agian." << endl;
			cout << "enter day you want to take a vaction:";
			cin >> day;
			cout << "enter month you want to take a vaction:";
			cin >> month;
			cout << "enter year you want to take a vaction:";
			cin >> year;
			cout << endl;
		}
		{
			for (int j = 0; j < SIZE2; j++)
			{
				if (c2[index].a.day[j] == 0 && c2[index].a.month[j] == 0 && c2[index].a.year[j] == 0)
				{
					c2[index].a.day[j] = day;
					c2[index].a.month[j] = month;
					c2[index].a.year[j] = year;
					cout << "Reported successed." << endl << endl;
					break;
				}
				count++;
			}
			if (count == SIZE2)
				cout << "There are no free days";
		}
	}
}
bool Date_Vaild(Contractor* c2, int day, int month, int year, int index)
{
	for (int j = 0; j < SIZE2; j++)
	{
		if (c2[index].a.day[j] == day && c2[index].a.month[j] == month && c2[index].a.year[j] == year)
			return false;
	}
	return true;
}
void workHistory(ExternalEmployee* c3, Job* c4, int index) {
	int position = 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (c4[i].External_id == c3[index].id)
		{
			cout << endl;
			cout << "Job Number " << position << endl;
			cout << "~~~~~~~~~~~~" << endl;
			printJob(c4[i]);
			position++;
		}
	}
}
void printJob(Job c4)
{
	cout << "Date worked: " << c4.day << "." << c4.month << "." << c4.year << endl;
	cout << "Starting hour for hiring: " << c4.S_Hour << ":" << c4.S_Min << endl;
	cout << "Finishing hour for hiring: " << c4.F_Hour << ":" << c4.F_Min << endl;
	cout << "Salary per hour: " << c4.Hour_Salary << endl;
	cout << "employer is: " << c4.employer << endl;
	cout << "employee is: " << c4.employee << endl;
	cout << "The external employee's Id: " << c4.External_id << endl;
	cout << "The contractor's ID: " << c4.Contractor_id << endl;
	cout << "The amount of extra hours: " << c4.premium_hours << ":" << c4.premium_mins << endl;
}
void ContractorWorkHistory(Contractor* c2, int index) {
	for (int i = 0; i < SIZE; i++)
	{
		if (c2[i].id == c2[index].id)
			printContractor(c2[i]);
	}
}
void printContractor(Contractor c2)
{

	cout << "   Contractor Details   " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Name: " << c2.Firstname << " " << c2.Lastname << endl;
	cout << "id: " << c2.id << endl;
	cout << "Hourly pay: " << c2.Hourly_Pay << endl;
	cout << "City: " << c2.City << endl;
	cout << "Adress: " << c2.Adress << endl;
	cout << "profession " << c2.profession << endl;
	cout << "Seniority: " << c2.seniority << endl << endl;
}
void Statistic_Analysis(Contractor* c2, Job* c4)
{
	int MaxVetek1 = 0, MaxVetek2 = 0, MaxVetek3 = 0;
	int index1 = 0, index2 = 0, index3 = 0;
	int MaxHours1 = 0, MaxHours2 = 0, MaxHours3 = 0;
	int MaxLocation1 = 0, MaxLocation2 = 0, MaxLocation3 = 0;
	int HoursWorked = 0, MinsWorked = 0, Nosafot_hours = 0, Nosafot_mins = 0;
	int sum = 0, temp1 = 0, temp2 = 0, temp3 = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (c2[i].id != 0)
		{
			for (int j = 0; j < SIZE; j++)//עוברת על כל העבודות
			{
				if (c4[j].Contractor_id == c2[i].id)
				{
					if (c4[i].F_Min >= c4[i].S_Min)
					{
						HoursWorked = (c4[i].F_Hour - c4[i].S_Hour);
						MinsWorked = c4[i].F_Min - c4[i].S_Min;
					}
					else
					{
						HoursWorked = c4[i].F_Hour - c4[i].S_Hour - 1;
						MinsWorked = 60 - c4[i].S_Min + c4[i].F_Min;
					}
					Nosafot_hours = c4[i].premium_hours;
					Nosafot_mins = c4[i].premium_mins;
					sum = sum + HoursWorked + MinsWorked + Nosafot_hours + Nosafot_mins;//סך הכל שעות ודקות
				}
			}
			if (sum >= MaxHours1)
				MaxHours1 = sum;
			else if (sum >= MaxHours2 && sum < MaxHours1)
				MaxHours2 = sum;
			else if (sum >= MaxHours3 && sum < MaxHours2 && sum < MaxHours1)
				MaxHours3 = sum;
		}
	}
}
void FindContractors(Contractor* c2)
{
	int tryAgain = 0;
	int In_Out = 0;
	int count = 0;
	int searchChoice = 0;
	char PlacePicked[LENGTH];
	char ProfessionPicked[LENGTH];
	int vetekPicked = 0;
	float payPicked = 0;
	int changeChoice = 1;
	int changePick = 0;
	char NamePicked[LENGTH];
	int contractorID = 0;


	while (tryAgain != 2)
	{
		count = 0;
		cout << "Let's find a contractor, what would you like to search for? your options:" << endl;
		cout << "1. Search by profession" << endl;
		cout << "2. Search by place" << endl;
		cout << "3. Search through pay by hour" << endl;
		cout << "4. Attendance clock" << endl;
		cout << "5. Serch by first name" << endl;
		cin >> searchChoice;
		switch (searchChoice)
		{
		case 1:
			cout << "Please enter the profession:";
			cin >> ProfessionPicked;
			cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (Checkprofession(c2, ProfessionPicked, i) == true)
				{
					printContractor(c2[i]);
					count++;
				}
			}
			if (count == 0)
				cout << "There Was No Contractors Found." << endl;
			tryAgain = 2;
			break;

		case 2:
			cout << "Please enter the place:";
			cin >> PlacePicked;
			cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (CheckPlace(c2, PlacePicked, i) == true)
				{
					printContractor(c2[i]);
					count++;
				}
			}
			if (count == 0)
				cout << "There Was No Contractors Found." << endl;
			tryAgain = 2;
			break;
		case 3:
			cout << "Please enter pay by hour:";
			cin >> payPicked;
			cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (SameHourlyPay(c2, payPicked, i) == true)
				{
					printContractor(c2[i]);
					count++;
				}
			}
			if (count == 0)
				cout << "There Was No Contractors Found." << endl;
			tryAgain = 2;
			break;
		case 4:
			cout << "Please enter which type of contractors you would like to see, (In/Out Clock)" << endl;
			cout << "0.Out Shift" << endl << "1.In Shift" << endl;
			cin >> In_Out;
			cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (CheckAttendanceClock(c2, In_Out, i) == true && c2[i].id != 0)
				{
					printContractor(c2[i]);
					count++;
				}
			}
			if (count == 0)
				cout << "There Was No Contractors Found." << endl;
			tryAgain = 2;
			break;
		case 5:
			cout << "Please enter the name of the contractor:";
			cin >> NamePicked;
			cout << endl;
			for (int i = 0; i < SIZE; i++)
			{
				if (CheckName(c2, NamePicked, i) == true)
				{
					printContractor(c2[i]);
					count++;
				}
			}
			if (count == 0)
				cout << "There Was No Contractors Found." << endl;
			tryAgain = 2;
			break;
		default:
			cout << "No such an option." << endl;
			cout << "Whould you like to try again?" << endl;
			cout << "1.Yes" << endl << "2.No" << endl;
			cin >> tryAgain;
			break;
		}
	}

	if (count != 0)
	{
		count = 0;
		cout << endl;
		cout << "Would you like to change any information about the contractors? (1 or 2)" << endl;
		cout << "1 - Yes" << endl;
		cout << "2 - No" << endl;
		cin >> changeChoice;
		if (changeChoice == 1)
		{
			cout << "Enter the id of the contractor you would like to update:";
			cin >> contractorID;
		}
		while (changeChoice != 2)
		{
			cout << endl;
			cout << "    What do you want to change?    " << endl;
			cout << "-----------------------------------" << endl;
			cout << "1. change first name" << endl;
			cout << "2. change last name" << endl;
			cout << "3. change pay by hour" << endl;
			cout << "4. change city" << endl;
			cout << "5. change adress" << endl;
			cout << "6. change phone number" << endl;
			cout << "7. change profession" << endl;
			cout << "8. change seniority" << endl;
			cin >> changePick;
			switch (changePick)
			{
			case 1:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "what's his/her first name?:";
						cin >> c2[i].Firstname;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 2:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "what's his/hers last name?:";
						cin >> c2[i].Lastname;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 3:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "Enter new amount of pay by the hour:";
						cin >> c2[i].Hourly_Pay;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 4:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "what's his/her city?:";
						cin >> c2[i].City;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 5:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "what's his/her adress?:";
						cin >> c2[i].Adress;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 6:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "Enter phone number:";
						cin >> c2[i].Phone_Number;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 7:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "what's his/her profession?:";
						cin >> c2[i].profession;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			case 8:
				for (int i = 0; i < SIZE; i++)
				{
					if (contractorID == c2[i].id)
					{
						cout << "Enter the amount of years worked:";
						cin >> c2[i].seniority;
						count++;
					}
				}
				if (count == 0)
					cout << "There Was No Contractor with ID:" << contractorID << " Found." << endl;
				changeChoice = 2;
				break;
			default:
				cout << "No such an option." << endl;
				cout << "Whould you like to try again?" << endl;
				cout << "1.Yes" << endl << "2.No" << endl;
				cin >> changeChoice;
				break;
			}
		}
	}
	cout << "Thank you, Bye Bye." << endl;
}


