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

typedef struct//A struct to help working with cities//
{
	char city[LENGTH];
	int counter;
} CityCheck;

typedef struct//Helps with checking the availabilities of workers//
{
	int day[SIZE2] = { 0 };
	int month[SIZE2] = { 0 };
	int year[SIZE2] = { 0 };
} Availabilty;

typedef struct//Organizes the booking procedure with a struct//
{
	int seniority;
	int day;
	int month;
	int year;
	float Hour_Salary;
	char Location[LENGTH];
	char Profession[LENGTH];
} Booking;

typedef struct//A struct to help with accessing job deals//
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

typedef struct//Handling the company employee with a struct//
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

typedef struct// Handling the external employee with a struct//
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

typedef struct//Organizing the contractos with a struct//
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

bool Exist_Contractor_ID(Contractor* c, int id);//Checks if Exist Id In Contractor Database
bool Exist_Company_ID(CompanyEmployee* c, int id);//Checks if Exist id in Company Database
bool Exist_External_ID(ExternalEmployee* c, int id);//Checks if Exist id in External Database
bool Exist_ID(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int id);//Checks if Exist id in any Database
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);//read all infromation from all databases
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);//write all to all the databases files
void ContractorMenu(Contractor* c, Job* c4, int index);//contractor menu
void CompanyEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, CityCheck* c5, int index);//companyemployee menu
void ExternalEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, int index);//External Employee menu
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, CityCheck* c5);//Main Menu
void addNewContractor(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void login_CE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, CityCheck* c5);//Login Company employee
void login_C(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);//Login Contractor
void login_EE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);//Login External Employee
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
bool Exist_Contractor_Username(Contractor* c, char username[]);//Checks if username Exist  In Contractor Database
bool Exist_Company_Username(CompanyEmployee* c, char username[]);//Checks if username Exist  In company emplyee Database
bool Exist_External_Username(ExternalEmployee* c, char username[]);//Checks if username Exist  In external employee Database
bool Exist_Username(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, char username[]);//Checks if  username Exist in any Database
bool Valid_Name(char name[]);//Vaild name
void Salary_Calculation(Contractor* c2, Job* c4, int index);
void Report_Hours(Contractor* c2, Job* c4, int index);
bool CheckAvibillity(Contractor* c2, int day, int month, int year, int index);//If the contractor can work in those days
bool Checkprofession(Contractor* c2, char profession[], int index);//check if the profession match
bool CheckPlace(Contractor* c2, char city[], int index);//check if the city match
bool Checkpay(Contractor* c2, float pay_hour, int index);//check if the hourly pay match
bool CheckVetek(Contractor* c2, int vetek2, int index);//check if the seniority match
void Search(Contractor* c2, ExternalEmployee* c3, Job* c4, int index1);//Serch for a contractor
void Book(Booking b, Contractor* c2, ExternalEmployee* c3, Job* c4, int index1, int index2);//book a contractor
void VacationRequest(Contractor* c2, int index);
bool Date_Vaild(Contractor* c2, int day, int month, int year, int index);//checks if the date is already taken or not
void workHistory(ExternalEmployee* c3, Job* c4, int index);//work history of the external employee
void printJob(Job c4);//print some job
void ContractorWorkHistory(Contractor* c2, int index);
void printContractor(Contractor c2);
void contractorinfromation(Contractor* c2);
bool SameHourlyPay(Contractor* c2, float pay_hour, int index);
bool CheckAttendanceClock(Contractor* c2, int In_Out, int index);
void StatisticsAnalysis(Contractor* c2, Job* c4, CityCheck* c5);
bool CheckName(Contractor* c2, char name[], int index);//checks if the name is the same
void print();
int main()
{
	print();//print logo
	CompanyEmployee c1[SIZE] = { 0 };
	Contractor c2[SIZE] = { 0 };
	ExternalEmployee c3[SIZE] = { 0 };
	Job c4[SIZE] = { 0 };
	CityCheck c5[SIZE] = { 0 };
	ReadFromFile(c1, c2, c3, c4);
	First_Menu(c1, c2, c3, c4,c5);
	WriteToFile(c1, c2, c3, c4);
	return 0;
}
void print()
{
	cout << PINK << "  HHHHHH  " << MAGENTA << "   HHHHH  " << YELLOW << "  HH    H" << GREEN << " HHHHHHH" << RED << " HHHHHHH   " << BLUE << "      HH    " << WHITE << "  HHHHHH  " << PINK << " HHHHHHHHH   " << MAGENTA << "  HH    H" << YELLOW << "  HHHHHHHH" << GREEN << "   HHH " << RED << " HHHHHHH" << endl;
	cout << PINK << " H      HH" << MAGENTA << "  H     H " << YELLOW << "  H H   H" << GREEN << "    H   " << RED << " H      H  " << BLUE << "     H  H   " << WHITE << " H      HH" << PINK << "     H       " << MAGENTA << "  H H   H" << YELLOW << "  H       " << GREEN << "  H    " << RED << "    H   " << endl;
	cout << PINK << "H         " << MAGENTA << " H       H" << YELLOW << "  H  H  H" << GREEN << "    H   " << RED << " HHHHHHH   " << BLUE << "    HHHHHH  " << WHITE << "H         " << PINK << "     H    HHH" << MAGENTA << "  H  H  H" << YELLOW << "  H       " << GREEN << "   HHH " << RED << "    H   " << endl;
	cout << PINK << "H         " << MAGENTA << " H       H" << YELLOW << "  H   H H" << GREEN << "    H   " << RED << " H      H  " << BLUE << "   H      H " << WHITE << "H         " << PINK << "     H    HHH" << MAGENTA << "  H   H H" << YELLOW << "  HHHHHHHH" << GREEN << "      H" << RED << "    H   " << endl;
	cout << PINK << " H      HH" << MAGENTA << "  H     H " << YELLOW << "  H    HH" << GREEN << "    H   " << RED << " H       H " << BLUE << "  H        H" << WHITE << " H      HH" << PINK << "     H       " << MAGENTA << "  H    HH" << YELLOW << "  H       " << GREEN << "      H" << RED << "    H   " << endl;
	cout << PINK << "  HHHHHH  " << MAGENTA << "   HHHHH  " << YELLOW << "  H    HH" << GREEN << "    H   " << RED << " H        H" << BLUE << "  H        H" << WHITE << "  HHHHHH  " << PINK << "     H       " << MAGENTA << "  H    HH" << YELLOW << "  HHHHHHHH" << GREEN << "  HHHH " << RED << "    H   " << endl;

	cout << BLOCKCOLOR << "                                                                                                                                                                                                                                                " << WHITE << endl;
	cout  << "\nBy Group 5" << endl <<endl;
}
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, CityCheck* c5)
{
	int choice, choice2;
	cout << "               ContactNest               " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1.Company Employee" << endl << "2.Contractor" << endl << "3.External employee" << endl << "4.Exit" << endl;
	cin >> choice;
	switch (choice)//choose type of employee
	{
	case 1:
		login_CE(c1, c2, c3, c4,c5);
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
	int choise=0;
	while (choise != 5)
	{
		cout << endl;
		cout << "               Contractor Menu               " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "1 - Report Hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Work history" << endl << "5 - Exit." << endl;
		cin >> choise;
		switch (choise)//choose action you want to do 
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
}
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int i = 0;
	string c = " ";
	ifstream C_In1;
	C_In1.open("CompanyEmployees.txt");
	for (i = 0; i < SIZE; i++)//read all data of the company employeee
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
	C_In2.open("ContractorWorkers.txt");//read all data of the contractor
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
	C_In3.open("ExternalEmployees.txt");//read all data of the external employeee
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
	C_In4.open("Booking Database.txt");//read all data of the booking database
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
	C_Out1.open("CompanyEmployees.txt");//write data to the company employee database
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
	C_Out2.open("ContractorWorkers.txt");//write data to the contractor database
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
			for (int j = 0; j < SIZE2; j++)//arr of vaction\job days
			{
				C_Out2 << c2[i].a.day[j];
				C_Out2 << endl;
			}
			for (int j = 0; j < SIZE2; j++)//arr of vaction\job months
			{
				C_Out2 << c2[i].a.month[j];
				C_Out2 << endl;
			}
			for (int j = 0; j < SIZE2; j++)//arr of vaction\job years
			{
				C_Out2 << c2[i].a.year[j];
				C_Out2 << endl;
			}
		}
	}
	C_Out2.close();//close file

	ofstream C_Out3;
	C_Out3.open("ExternalEmployees.txt");//write data to the external employee database
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
	C_Out4.open("Booking Database.txt");//write data to the booking database
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
void login_CE(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, CityCheck* c5)
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
			CompanyEmployeeMenu(c1, c2, c3, c4, c5 , index);
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
						CompanyEmployeeMenu(c1, c2, c3, c4, c5, index);
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
	int choise = 0;
	while (choise != 3)
	{
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
}
void CompanyEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4, CityCheck* c5, int index)
{
	int choise=0;
	while (choise != 4)
	{
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
			StatisticsAnalysis(c2, c4, c5);
			break;
		case 3:
			contractorinfromation(c2);
			break;
		case 4:
			cout << "Bye Bye." << endl;
			break;
		default:
			break;
		}
	}
}
bool Exist_Contractor_Username(Contractor* c, char username[]) //func that check's if the constactor username already exist in the contractor arr
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
bool Exist_Company_Username(CompanyEmployee* c, char username[]) //func that check's if the employee username already exist in the contractor arr
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
bool Exist_External_Username(ExternalEmployee* c, char username[]) //func that check's if the external emplooye username already exist in the contractor arr
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c[i].username) == 0) //compares between the username from index i in the arr between the username that the func got
			count++;
	}
	if (count == 0)                              //condition
		return false;
	else
		return true;
}
bool Exist_Username(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, char username[]) //func that check's if the username exist
{
	if ((Exist_External_Username(c3, username) == false) && (Exist_Contractor_Username(c2, username) == false) && (Exist_Company_Username(c1, username) == false))  //condition that chacks if the username exist
		return false;
	else
		return true;
}
bool Valid_Name(char name[]) //func that check's if the name is ligal to use
{
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[0] > 'Z' || name[0] < 'A')   //condition if there are chars from the ABC
			return false;
		if ((name[i] > 'z' || name[i] < 'a') && i != 0)   //condition if there are chars from the ABC little latters
			return false;
	}
	return true;
}
bool Exist_Contractor_ID(Contractor* c, int id) //func that check's if the contractor ID exist in the contarctor arr
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)  //for loop
	{
		if (id == c[i].id)    //condition checks if the id in the arr and the id from the input are the same
			count++;
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_Company_ID(CompanyEmployee* c, int id) //func that check's if the company employee's ID exist in the arr
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (id == c[i].id)    //condition checks if the id in the arr and the id from the input are the same
			count++;          //add count +1
	}
	if (count == 0)         //condition
		return false;
	else
		return true;
}
bool Exist_External_ID(ExternalEmployee* c, int id)  //func that check's if the contractor ID exist in the contarctor arr
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (id == c[i].id) //condition checks if the id in the arr and the id from the input are the same
			count++;   //counter +1
	}
	if (count == 0)
		return false;
	else
		return true;
}
bool Exist_ID(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int id)  //func that check's if the ID exist
{
	if ((Exist_External_ID(c3, id) == false) && (Exist_Contractor_ID(c2, id) == false) && (Exist_Company_ID(c1, id) == false))  //condition checks if the id exist
		return false;
	else
		return true;
}
void Salary_Calculation(Contractor* c2, Job* c4, int index) //func that calculates the salary in specific month and year by his jobs
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
		if (c2[index].id == c4[i].Contractor_id)   //compares the id's 
		{
			if (c4[i].year == year)//compers the year's
			{
				if (c4[i].month == month) //compers the month's
				{
					count++;

					if (c4[i].F_Min >= c4[i].S_Min)  //see's that the time is ok
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
void Report_Hours(Contractor* c2, Job* c4, int index)       //func porpose to report hours worked  
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
		if (c2[index].id == c4[i].Contractor_id)    //sees that the id is correct
		{
			if (c4[i].year == year)                //sees that the year is correct
			{
				if (c4[i].month == month)            //sees that the month is correct
				{
					if (c4[i].day == day)             //sees that the day is correct
					{
						count++;
						if (c2[index].CheckInOut == 0)
						{                                 //prints/gets all the ditails
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
							cout << "----------------------" << endl;             //gets all the ditails
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
	if (count != 0)       //saw there was day worked
		cout << "Report Succceded." << endl;
	else        //no worked day
		cout << "You didnt work in this day in this month in this year" << endl;


}
bool CheckAvibillity(Contractor* c2, int day, int month, int year, int index)   //check if the date is free
{
	for (int j = 0; j < SIZE2; j++)
	{
		if (c2[index].a.day[j] == day && c2[index].a.month[j] == month && c2[index].a.year[j] == year)
			return false;
	}
	return true;
}
bool Checkprofession(Contractor* c2, char profession[], int index) //checks if the professions are the same
{
	if (strcmp(c2[index].profession, profession) == 0)          //compers
		return true;
	return false;
}
bool CheckPlace(Contractor* c2, char city[], int index) //checks if the palces are the same
{
	if (strcmp(c2[index].City, city) == 0) //compares
		return true;
	return false;
}
bool CheckName(Contractor* c2, char name[], int index)  //checks if the names are the same
{
	if (strcmp(c2[index].Firstname, name) == 0)   //compares
		return true;
	return false;
}
bool Checkpay(Contractor* c2, float pay_hour, int index) //checks if the payment fits the requrments
{
	if (c2[index].Hourly_Pay <= pay_hour)       //condition
		return true;
	return false;
}
bool SameHourlyPay(Contractor* c2, float pay_hour, int index) //checks if the payment is the same
{
	if (c2[index].Hourly_Pay == pay_hour)  //condition the pay is the same
		return true;
	return false;
}
bool CheckVetek(Contractor* c2, int vetek2, int index) //checks if the seniority fits the requrments
{
	if (c2[index].seniority >= vetek2)      //condition the seniority 
		return true;
	return false;
}
bool CheckAttendanceClock(Contractor* c2, int In_Out, int index)  //checks attandance clock
{
	if (c2[index].CheckInOut == In_Out)   //condition
		return true;
	return false;
}
void Search(Contractor* c2, ExternalEmployee* c3, Job* c4, int index1) //finds the right contractor by differnt categories 
{
	int day, month, year;
	int count = 0;
	int index2 = 0;
	char profession[LENGTH];
	float pay_hour;
	char city[LENGTH];
	int vetek;
	Booking b = { 0 };        //booking arr
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
			Book(b, c2, c3, c4, index1, i);         //func
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
void Book(Booking b, Contractor* c2, ExternalEmployee* c3, Job* c4, int index1, int index2) //func that books the contractor you want to hire
{

	for (int j = 0; j < SIZE2; j++)  //for loop
	{
		if (c2[index2].a.day[j] == 0 && c2[index2].a.month[j] == 0 && c2[index2].a.year[j] == 0) //condition  sees that all date in index i is intialized
		{
			c2[index2].a.day[j] = b.day;
			c2[index2].a.month[j] = b.month;
			c2[index2].a.year[j] = b.year;
			break;
		}
	}
	for (int i = 0; i < SIZE; i++)     //forr loop
	{
		if (c4[i].ch == 0)   //input the ditails needed / placment
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
			strcpy(c4[i].employer, c3[index1].Firstname);   //compares
			strcpy(c4[i].employee, c2[index2].Firstname);  //compares
			c4[i].External_id = c3[index1].id;
			c4[i].Contractor_id = c2[index2].id;
			c4[i].premium_hours = 0;
			c4[i].premium_mins = 0;
			break;
		}
	}
}
void VacationRequest(Contractor* c2, int index) // gives the ability to requst a  vacation
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
		while (Date_Vaild(c2, day, month, year, index) == false)        //while the func returns false, tells the date is not vaild. trys again
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
			for (int j = 0; j < SIZE2; j++)  //reqest in this date the vocation
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
bool Date_Vaild(Contractor* c2, int day, int month, int year, int index)  // chacks if the date is legal
{
	for (int j = 0; j < SIZE2; j++)
	{
		if (c2[index].a.day[j] == day && c2[index].a.month[j] == month && c2[index].a.year[j] == year)   //condition if the input to the func is the same as the date in the arr
			return false;
	}
	return true;
}
void workHistory(ExternalEmployee* c3, Job* c4, int index) {    //shows the jobs history
	int position = 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (c4[i].External_id == c3[index].id)    //condition the id is the same
		{
			cout << endl;
			cout << "Job Number " << position << endl;
			cout << "~~~~~~~~~~~~" << endl;
			printJob(c4[i]);    //prints the job ditails
			position++;
		}
	}
}
void printJob(Job c4)      // prints the job ditails
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
void printContractor(Contractor c2)     //prints the contractor ditails
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
void StatisticsAnalysis(Contractor* c2, Job* c4, CityCheck* c5) //func to checkstatistics about top contractors in a few fields
{
	int menu = 0, max1 = 0, max2 = 0, max3 = 0;
	int index1 = 0, index2 = 0, index3 = 0;
	int index4 = 0, index5 = 0, index6 = 0;
	int mostSenior1 = 0, mostSenior2 = 0, mostSenior3 = 0;
	int MaxHours1 = 0, MaxHours2 = 0, MaxHours3 = 0;
	int MaxLocation1 = 0, MaxLocation2 = 0, MaxLocation3 = 0;
	int HoursWorked = 0, MinsWorked = 0, Nosafot_hours = 0, Nosafot_mins = 0;
	int sum = 0;
	int countCity1 = 0, countCity2 = 0, countCity3 = 0;
	int cityIndex1 = 0, cityIndex2 = 0, cityIndex3 = 0;
	cout << "### Statistics Analysis ###" << endl;
	cout << "Enter given number to enter category" << endl << "1 - Contractors with most hours" << endl << "2 - Contractors with most seniority" << endl << "3 - Most popular city among the contractors" << endl;
	cin >> menu;
	switch (menu)
	{
	case 1:
	{
		for (int i = 0; i < SIZE; i++)//מערך קבלנים
		{
			if (c2[i].id != 0)//תעודת זהות לא אפס
			{
				sum = 0;
				for (int j = 0; j < SIZE; j++)//מערך עבודות
				{
					if (c4[j].Contractor_id == c2[i].id)//תעודת זהות של הקבלן זהה לתעודת זהות בעבודה
					{
						if (c4[i].F_Min >= c4[i].S_Min)
						{
							HoursWorked = c4[i].F_Hour - c4[i].S_Hour;
							MinsWorked = c4[i].F_Min - c4[i].S_Min;
						}
						else
						{
							HoursWorked = c4[i].F_Hour - c4[i].S_Hour - 1;
							MinsWorked = 60 - c4[i].S_Min + c4[i].F_Min;
						}
						Nosafot_hours = c4[i].premium_hours;
						Nosafot_mins = c4[i].premium_mins;
						sum = sum + HoursWorked * 60 + MinsWorked + Nosafot_hours * 60 + Nosafot_mins;
					}
				}
				if (sum > MaxHours1)
				{
					MaxHours3 = MaxHours2;
					index6 = index5;
					MaxHours2 = MaxHours1;
					index5 = index4;
					MaxHours1 = sum;
					index4 = i;
				}
				else if (sum > MaxHours2)
				{
					MaxHours3 = MaxHours2;
					index6 = index5;
					MaxHours2 = sum;
					index5 = i;
				}
				else if (sum > MaxHours3)
				{
					MaxHours3 = sum;
					index6 = i;
				}
			}
		}
		cout << "    Total Minutes    " << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << "1." << c4[index4].employee << " Minutes:" << MaxHours1 << endl;
		cout << "2." << c4[index5].employee << " Minutes:" << MaxHours2 << endl;
		cout << "3." << c4[index6].employee << " Minutes:" << MaxHours3 << endl;
		break;
	}
	case 2:
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (c2[i].id != 0)
			{
				if (c2[i].seniority > mostSenior1)
				{
					mostSenior3 = mostSenior2;
					index3 = index2;
					mostSenior2 = mostSenior1;
					index2 = index1;
					mostSenior1 = c2[i].seniority;
					index1 = i;

				}
				else if (c2[i].seniority > mostSenior2)
				{
					mostSenior3 = mostSenior2;
					index3 = index2;
					mostSenior2 = c2[i].seniority;
					index2 = i;

				}
				else if (c2[i].seniority > mostSenior3)
				{
					mostSenior3 = c2[i].seniority;
					index3 = i;
				}
			}
		}
		cout << "    Seniority    " << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << "1 - " << c2[index1].Firstname << "    seniority: " << c2[index1].seniority << endl;
		cout << "2 - " << c2[index2].Firstname << "    seniority: " << c2[index2].seniority << endl;
		cout << "3 - " << c2[index3].Firstname << "    seniority: " << c2[index3].seniority << endl;
		break;
	}
	case 3:
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (c2[i].id != 0)
			{
				for (int j = 0; j < SIZE; j++)
				{
					if (strlen(c5[j].city) == 0)
					{
						strcpy(c5[j].city, c2[i].City);
						c5[j].counter++;
						break;
					}
				}
				if (c5[i].counter > max1)
				{
					max3 = max2;
					cityIndex3 = cityIndex2;
					max2 = max1;
					cityIndex2 = cityIndex1;
					max1 = c5[i].counter;
					cityIndex1 = i;
				}
				else if (c5[i].counter > max2)
				{
					max3 = max2;
					cityIndex3 = cityIndex2;
					max2 = c5[i].counter;
					cityIndex2 = i;
				}
				else if (c5[i].counter > max3)
				{
					max3 = c5[i].counter;
					cityIndex3 = i;
				}
			}
		}
		cout << "    Cities    " << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << "1 - " << c2[cityIndex1].City << " " << c5[cityIndex1].counter << endl;
		cout << "2 - " << c2[cityIndex2].City << " " << c5[cityIndex2].counter << endl;
		cout << "3 - " << c2[cityIndex3].City << " " << c5[cityIndex3].counter << endl;
		break;
	}
	default:
		break;
	}
}
void contractorinfromation(Contractor* c2)  //this func finds the spesific contractor and you can update the contractor ditails
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


	while (tryAgain != 2)   //while loop 
	{
		count = 0;
		cout << "Let's find a contractor, what would you like to search for? your options:" << endl;
		cout << "1. Search by profession" << endl;
		cout << "2. Search by place" << endl;
		cout << "3. Search through pay by hour" << endl;
		cout << "4. Attendance clock" << endl;
		cout << "5. Serch by first name" << endl;
		cin >> searchChoice;
		switch (searchChoice)   //switch case that gives me the abillity to find contractor by differnt categoris
		{
		case 1:
			cout << "Please enter the profession:";    //proffesion category
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
			cout << "Please enter the place:";     //palce category
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
			cout << "Please enter pay by hour:";   //paycheck category
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
		case 4: // Attendance clock category
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
		case 5:   //name category 
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
		default:    //no contractor found
			cout << "No such an option." << endl;
			cout << "Whould you like to try again?" << endl;
			cout << "1.Yes" << endl << "2.No" << endl;
			cin >> tryAgain;
			break;
		}
	}

	if (count != 0)    //changes the info. of the contractor
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
			cout << "1. change pay by hour" << endl;
			cout << "2. change city" << endl;
			cout << "3. change adress" << endl;
			cout << "4. change phone number" << endl;
			cout << "5. change profession" << endl;
			cout << "6. change seniority" << endl;
			cin >> changePick;
			switch (changePick)
			{
			case 1:    //changes the first name
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
			case 2:                //changes the last name
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
			case 3:      //changes the payment
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
			case 4:  //changes the city
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
			case 5:     //changes adress
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
			case 6:  //changes number
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




