#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#define SIZE2 3
#define LENGTH 20
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Aasdasd
typedef struct
{
	int day[SIZE2] = { 0 };
	int month[SIZE2] = { 0 };
	int year[SIZE2] = { 0 };
} Availabilty;

typedef struct
{
	char ch;
	int day;
	int month;
	int year;
	float S_Hour;
	float S_Min;
	float F_Hour;
	float F_Min;
	float Hour_Salary;
	char employer[LENGTH];
	char employee[LENGTH];
	int External_id;
	int Contractor_id;
	float premium_hours;
	float premium_mins;
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
	int CheckInOut;
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
	c2[0].a.day[0] = 2;
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
	int sum = 0;
	int HoursWorked = 0;
	int MinsWorked = 0;
	int Nosafot_hours;
	int Nosafot_mins;
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
						MinsWorked = ((c4[i].F_Min - c4[i].S_Min)/60)*c4[i].Hour_Salary;
					}
					else
					{
						HoursWorked = (c4[i].F_Hour - c4[i].S_Hour - 1)*c4[i].Hour_Salary;
						MinsWorked = ((60 - c4[i].S_Min + c4[i].F_Min)/60)*c4[i].Hour_Salary;
					}
					Nosafot_hours = c4[i].premium_hours*c4[i].Hour_Salary*1.15;
					Nosafot_mins = (c4[i].premium_mins/60)*c4[i].Hour_Salary*1.15;
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
	int day, month, year,count=0;
	int start_hour, start_min, finish_hour, finish_min, premium_hours, premium_mins;
	cout << "Please enter the year you want to report:";
	cin >> year;
	cout << "Please enter the month you want to report:";
	cin >> month;
	cout << "Please enter the day you want to report:";
	cin >> day;
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
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
//##################################################### EILON ############################################################################
/*
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
*/
