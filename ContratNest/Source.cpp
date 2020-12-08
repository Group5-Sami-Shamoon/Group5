#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100
#define LENGTH 20
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct
{
	int day[SIZE];
	int month[SIZE];
	int year[SIZE];
} Availabilty;

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
	float premium;
} Job;

typedef struct
{
	int seniority;
	Availabilty a;
	float Hour_Salary;
	char Location[LENGTH];
	char Profession[LENGTH];
} Booking;

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
	bool CheckInOut;
	Availabilty a;
	Job j;
} Contractor;

bool Exist_Contractor_ID(Contractor* c, int id);
bool Exist_Company_ID(CompanyEmployee* c, int id);
bool Exist_External_ID(ExternalEmployee* c, int id);
bool Exist_ID(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int id);
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4);
void ContractorMenu(Contractor* c, Job* c4, int index);
void CompanyEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int index);
void ExternalEmployeeMenu(ExternalEmployee* c, int index);
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
int main()
{
	float num;
	int i = 0, choise = 0, count = 0;
	CompanyEmployee c1[SIZE] = { 0 };
	Contractor c2[SIZE] = { 0 };
	ExternalEmployee c3[SIZE] = { 0 };
	Job c4[SIZE] = { 0 };
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
		login_CE(c1,c2,c3,c4);
		break;
	case 2:
		login_C(c1,c2,c3,c4);
		break;
	case 3:
		cout << "1.Register" << endl << "2.Login" << endl;
		cin >> choice2;
		if (choice2 == 1)
			Register(c1,c2,c3,c4);
		else if (choice2 == 2)
			login_EE(c1,c2,c3,c4);
		break;
	case 4:
		cout << "Bye Bye." << endl;
		break;
	default:
		printf("Error.\n");
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
		break;
	case 4:
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
		C_In4 >> c4[i].premium;
	}
	C_In4.close();
}
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, Job* c4)
{
	int i = 0;
	ofstream C_Out1;
	C_Out1.open("CompanyEmployees.txt");
	for (i = 0; i < SIZE; i++)//����� �� �� ������� ����� ���� �����
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
	for (i = 0; i < SIZE; i++)//����� �� �� ������� ����� ���� �����
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
		}
	}
	C_Out2.close();//close file

	ofstream C_Out3;
	C_Out3.open("ExternalEmployees.txt");
	for (i = 0; i < SIZE; i++)//����� �� �� ������� ����� ���� �����
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
			C_Out4 << c4[i].premium << endl;
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
			CompanyEmployeeMenu(c1,c2,c3 ,index);
		}
		else if (strcmp(username, c1[i].username) == 0 && !(strcmp(password, c1[i].password) == 0))
		{
			while (!(strcmp(password, c1[i].password) == 0) && choice !=2)
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
						CompanyEmployeeMenu(c1, c2,c3,index);
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
		if (strcmp(username,c3[i].username)==0  && strcmp(password,c3[i].password)==0)
		{
			cout << "Vaild username and password, welcome " << c3[i].Firstname <<endl;
			index = i;
			ExternalEmployeeMenu(c3, index);
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
						ExternalEmployeeMenu(c3, index);
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
			c3[i].id=id;
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
void ExternalEmployeeMenu(ExternalEmployee* c, int index)
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
		break;
	case 2:
		break;
	case 3:
		cout << "Bye Bye." << endl;
		break;
	default:
		break;
	}
}
void CompanyEmployeeMenu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int index)
{
	int choise;
	cout << endl;
	cout << "               Company Employee Menu               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1 - Add Contractor" << endl << "2 - Statistic" << endl << "3 - Contractor Inforomation" << endl << "4 - Exit."<< endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		addNewContractor(c1, c2, c3);
		break;
	case 2:
		break;
	case 3:
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
		if (strcmp(username, c[i].username)==0)
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
		if ((name[i] > 'z' || name[i] < 'a') && i!=0)
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
	float salary = 0;
	int sum = 0;
	int HoursWorked = 0;
	int Nosafot;
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
					HoursWorked = c4[i].F_Hour - c4[i].S_Hour;
					Nosafot = c4[i].premium * c4[i].Hour_Salary * 1.15;
					sum = sum + Nosafot + (HoursWorked*c4[i].Hour_Salary);
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



}
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
/*

void ClockReport(Contractor cont[Max],int index)
{
	int hourMenu = 0;
	int hours = 0;
	cout << "#### Hours report ####" << endl;
	do
	{
		cout << "Would you like to clock in or out?" << endl << "1 - In" << endl << "2 - Out" << endl;
		cin >> hourMenu;
	}
	while (hourMenu != 1 && hourMenu != 2);
	switch (hourMenu)
	{
	case 1:
	{
		if (cont[index].CheckInOut == true)
			cout << "You are already clocked in!" << endl;
		else
		{
			cont[index].CheckInOut = true;
			cout << "You are now clocked in!" << endl;
		}
	}
		break;
	case 2:
	{
		if (cont[index].CheckInOut == true)
		{
			cout << "How many hours did you work today?:" << endl;
			do
			{
				cout << "## Must be between 0-24 hours ##" << endl;
				cin >> hours;
			} while (hours < 0 || hours > 24);
			cont[index].hours += hours;
			cout << "You are now clocked out!" << endl;
			cont[index].CheckInOut = false;
		}
		else
			cout << "To clock out you must clock in!" << endl;
	}
	break;
	}
}
void VacationRequest(Contractor cont[Max],int indexush)
{
	int days;
	cout << "## Vacation report ##" << endl;
	cout << "How many days would you like to take off?:" << endl;
	do
		cin >> days;
	while (days <= 0);
	cout << "Which dates would you like to take off? **(Day,Month,Year)** :" << endl;
	for (int i = 0; i < days; i++)
		cin >> cont[indexush].vacation.day[i] >> cont[indexush].vacation.month[i] >> cont[indexush].vacation.year[i];
	cout << "Requested dates:" << endl;
	for (int i = 0; i < days; i++)
		cout << cont[indexush].vacation.day[i] << "/" << cont[indexush].vacation.month[i] << "/" << cont[indexush].vacation.year[i] << endl;
}

int main()
{
	int menu=0;
	int size;
	float num = 0;
	int i = 0;

	//����� ����� ������
	ifstream beta;
	beta.open("BetaFile.txt");
	beta >> size;

	//����� ����� ������
	ifstream C_In;
	C_In.open("ContractorWorkers.txt");
	C_In >> size;

	Contractor c[Max] = { NULL };
	cout << "Enter Name,Surname,ID";
	cin >> c[0].Firstname >> c[0].Lastname >>  c[0].id;
	cout << endl;
	cout << c[0].Firstname <<endl<< c[0].Lastname << endl<<c[0].id<<endl;

	/*for (i = 0; i < size; i++)
		C_In >> c[i].Firstname >> c[i].Lastname >> c[i].age;
	C_In.close();*/

	//����� ����� ������� ��� �� �� ����
	//ofstream C_Out;
	//C_Out.open("ContractorWorkers.txt");
	//C_Out << size << endl;
	//cout << "enter name"<<endl;
	//cin >> c[i].Firstname;
	//C_Out << "Name: " <<  c[i].Firstname << endl;
	//cout << "enter hours" << endl;
	//cin >> c[i].hours;
	//C_Out <<"Hours worked: "<<  c[i].hours << endl;
	//for (i = 0; i < size; i++)
	//{
	//	if (c[i].age == 3154)
	//	{
	//		cout << "Please Enter Age:";
	//		cin >> c[i].age;
	//		C_Out << c[i].Firstname << " " << c[i].Lastname << " " << c[i].age << endl;
	//	}
	//	else
	//		C_Out << c[i].Firstname << " " << c[i].Lastname << " " << c[i].age << endl;
	//}
//
//	cout << endl<< "Welcome to ContractNest." << endl;
//	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Report hours" << endl << "5 - Work history" <<endl << "6 - Exit" <<endl;
//
//	while (menu != 5)
//	{
//	cout <<	"Please enter the given to number to enter a category:" << endl;
//	cin >> menu;
//		switch (menu)
//		{
//		case 1:
//			ClockReport(c,0);
//			break;
//		case 2:
//
//			break;
//		case 3:
//			VacationRequest(c, 0);
//			break;
//		case 4:
//			break;
//
//		}
//	}
//
//	cout << endl << "Thank you for choosing ContractNest <3"<<endl;
//	//C_Out.close();//close file
//	return 0;
//}






//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
//              ##################################################### NAKNIKA ############################################################################
/*
typedef struct
{
	int type = 1;
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
	int type = 3;
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
	int day;
	int month;
	int year;
	float S_Hour;
	float F_Hour;
	float Hour_Salary;
	char employer[LENGTH];
	char employee[LENGTH];
	float total;
	float premium;
} Job;

typedef struct
{
	int type = 2;
	char username[LENGTH];
	char password[LENGTH];
	char ch;
	char Firstname[LENGTH];
	char Lastname[LENGTH];
	int id;
	float Month_Salary;
	float Hourly_Pay;
	char City[LENGTH];
	char Adress[LENGTH];
	int Phone_Number;
	char profession[LENGTH];
	int seniority;
	Job j;
} Contractor;




bool CheckAvibillity(Contractor cont[SIZE], int day, int month, int year)     //���� ������
{
	cout << "checks if the cotractor is avilible" << endl;
	cout << "enter day:" << endl;
	cin >> day;
	cout << "enter month:" << endl;
	cin >> month;
	cout << "enter year:" << endl;
	cin >> year;
	for (int  i = 0; i < SIZE; i++)
	{
		if (cont[i].j.day == day&& cont[i].j.month == month&& cont[i].j.year == year)
			return true;
		else
			return false;
	}
}

bool Checkprofession(Contractor cont[SIZE],char* profession)      //���� �� ������ ����
{
	cout << "Enter a profession:" << endl;
	cin >> profession;
	cout << "checks if the profession is exist" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(cont[i].profession, profession)==0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

bool Checkpay(Contractor cont[SIZE], float pay_hour)
{
	cout << "Enter a salary per hour:" << endl;
	cin >> pay_hour;
	cout << "checks if the salary is fits the requrment" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (cont[i].j.Hour_Salary <=pay_hour)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

bool CheckPlace(Contractor cont[SIZE], char* city)
{
	cout << "Enter a city:" << endl;
	cin >> city;
	cout << "checks if its the same city" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(cont[i].City, city)==0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}


bool CheckVetek(Contractor cont[SIZE], int vetek2)
{
	cout << "Enter a vetek:" << endl;
	cin >> vetek2;
	cout << "checks if its the same Seniority" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (cont[i].seniority <= vetek2)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

int SerchAndBook(Contractor cont[SIZE])
{
	int day{}, month{}, year{};
	char* profession{};
	float pay_hour{};
	char* city{};
	int vetek{};
	bool requrment=true;
	Contractor booking[SIZE] = { NULL };
	int num;


	cout << "Here you can serch the contractor for you !" << endl;
	cout << "There are some categories for you:" << endl;
	cout << "1. Avibillity" << endl << "2. Profession" << endl << "3.Payment" << endl << "4.Place" << endl << "5.Seniority" << endl;
	//cout << "Avibillity" << endl;
	//CheckAvibillity(cont, day, month, year);    //����� ��� �� ���
	//cout << "Profession" << endl;
	//Checkprofession(cont, profession);        //����� ��� �� ���
	//cout << "Payment" << endl;
	//Checkpay(cont, pay_hour);                 //����� ��� �� ���
	//cout << "Place" << endl;
	//CheckPlace(cont, city);           //����� ��� �� ���
	//cout << "Seniority" << endl;
	//CheckVetek(cont, vetek);              //����� ��� �� ���

	for (int i = 0; i < SIZE; i++)

	{
		if (CheckAvibillity(cont, day, month, year) == false && Checkprofession(cont, profession) == true && Checkpay(cont, pay_hour) == true && CheckPlace(cont, city) == true && CheckVetek(cont, vetek) == true)
		{
			cout << cont[i].Firstname<<" "<<cont[i].Lastname<<" "<<cont[i].City<< endl;
			booking[i] = cont[i];
		}
		else
		{
			cout << "The contractor was not found" << endl;
		}

		cout << "Contractor index is:" << i << endl;
	}
	cout << "Would you like to hire this contractor??" << endl << "1-yes | 2-no" << endl;;
	cin >> num;
	if (num==1)
	{

	}

	return 0;
}



}
*/
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################ ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//              ##################################################### Otir ############################################################################
//
//
//typedef struct
//{
//	int type = 2;
//	char username[LENGTH];
//	char password[LENGTH];
//	char ch;
//	char Firstname[LENGTH];
//	char Lastname[LENGTH];
//	int id;
//	float Daily_Salary;
//	char City[LENGTH];
//	char Adress[LENGTH];
//	int Phone_Number;
//	char profession[LENGTH];
//	int seniority;
//
//} Contractor;
//
//void workHistory(Contractor* c, int cc);
//int CountConstractorCases(Contractor* c, char* n);
//bool checkContractor(Contractor c, char* n);
//void printContractor(Contractor cTp);
//
//int main() {
//
//	return 0;
//
//}
//
//void workHistory(Contractor* c, int cCount) {
//
//	for (int i = 0; i < cCount; i++) {
//
//		printContractor(c[i]);
//	}
//
//}
//
//int CountConstractorCases(Contractor* c, char* Contname) {
//
//	int ContractorCounter;
//
//	for (int i = 0; i < SIZE; i++) {
//
//		if (checkContractor(c[i], Contname) == true)
//
//			ContractorCounter++;
//
//	}
//
//	return ContractorCounter;
//
//}
//
//bool checkContractor(Contractor c, char* name) {
//
//	if (strcmp(c.Firstname, name) == 0)
//
//		return true;
//
//	else
//
//		return false;
//
//
//}
//
//void printContractor(Contractor cTp) {
//	cout << "The contractor information is: " << endl;
//	cout << "First name: " << cTp.Firstname;
//	cout << "Last name: " << cTp.Lastname;
//	cout << "ID: " << cTp.id;
//	cout << "lives in: " << cTp.Adress;
//	cout << "Phone: " << cTp.Phone_Number;
//	cout << "Works in: " << cTp.profession;
//	cout << "Years on the job: " << cTp.seniority;
//}