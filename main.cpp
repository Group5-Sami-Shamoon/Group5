#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#include <iostream>
#include <fstream>
using namespace std;

typedef struct
{
	int type = 1;
	char username[20];
	char password[20];
	char ch;
	char Firstname[20];
	char Lastname[20];
	float id;
	char City[30];
	char Adress[30];
	int Phone_Number;
} CompanyEmployee;

typedef struct
{
	int type = 3;
	char username[20];
	char password[20];
	char ch;
	char Firstname[20];
	char Lastname[20];
	float id;
	char City[30];
	char Adress[30];
	int Phone_Number;
} ExternalEmployee;

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

typedef struct
{
	int type = 2;
	char username[20];
	char password[20];
	char ch;
	char Firstname[20];
	char Lastname[20];
	float id;
	float Daily_Salary;
	char City[30];
	char Adress[30];
	int Phone_Number;
	char profession[20];
	Job j;
} Contractor;

void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void ContractorMenu(Contractor* c, int index);
void CompanyEmployeeMenu(CompanyEmployee* c, int index);
void ExternalEmployeeMenu(ExternalEmployee* c, int index);
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void addNewContractor(Contractor* c);
void login_CE(CompanyEmployee* c1);
void login_C(Contractor* c2);
void login_EE(ExternalEmployee* c3);
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
bool Exist_Contractor_Username(Contractor* c, char username[]);
bool Exist_Company_Username(CompanyEmployee* c, char username[]);
bool Exist_External_Username(ExternalEmployee* c, char username[]);
bool Exist_Username(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, char username[]);

int main()
{
	float num;
	int i = 0, choise = 0, count = 0;
	CompanyEmployee c1[SIZE] = { 0 };
	Contractor c2[SIZE] = { 0 };
	ExternalEmployee c3[SIZE] = { 0 };
	ReadFromFile(c1, c2, c3);
	First_Menu(c1, c2, c3);
	WriteToFile(c1, c2, c3);
	return 0;
}
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
{
	int choice, choice2;
	cout << "               ContactNest               " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "1.Company Employee" << endl << "2.Contractor" << endl << "3.External employee" << endl << "4.Exit" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		login_CE(c1);
		break;
	case 2:
		login_C(c2);
		break;
	case 3:
		cout << "1.Register" << endl << "2.Login" << endl;
		cin >> choice2;
		if (choice2 == 1)
			Register(c1,c2,c3);
		else if (choice2 == 2)
			login_EE(c3);
		break;
	case 4:
		cout << "Bye Bye." << endl;
		break;
	default:
		printf("Error.\n");
	}
}
void ContractorMenu(Contractor* c, int index)
{
	int choise;
	cout << "               Contractor Menu               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Work history" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}
}
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
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
		C_In2 >> c2[i].Daily_Salary;
		C_In2 >> c2[i].City;
		C_In2 >> c2[i].Adress;
		C_In2 >> c2[i].Phone_Number;
		C_In2 >> c2[i].profession;
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
}
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
{
	int i = 0;
	ofstream C_Out1;
	C_Out1.open("ContractorWorkers.txt");
	for (i = 0; i < SIZE; i++)//כותבת את כל הנתונים לקובץ לאחר שינוי
	{
		if (c1[i].id == 0)
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
	for (i = 0; i < SIZE; i++)//כותבת את כל הנתונים לקובץ לאחר שינוי
	{
		if (c2[i].id == 0)
			break;
		else
		{
			C_Out2 << c2[i].ch << endl;
			C_Out2 << c2[i].username << endl;
			C_Out2 << c2[i].password << endl;
			C_Out2 << c2[i].Firstname << endl;
			C_Out2 << c2[i].Lastname << endl;
			C_Out2 << c2[i].id << endl;
			C_Out2 << c2[i].Daily_Salary << endl;
			C_Out2 << c2[i].City << endl;
			C_Out2 << c2[i].Adress << endl;
			C_Out2 << c2[i].Phone_Number << endl;
			C_Out2 << c2[i].profession << endl;
		}
	}
	C_Out2.close();//close file

	ofstream C_Out3;
	C_Out3.open("ExternalEmployees.txt");
	for (i = 0; i < SIZE; i++)//כותבת את כל הנתונים לקובץ לאחר שינוי
	{
		if (c3[i].id == 0)
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
}
void addNewContractor(Contractor* c)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (c[i].ch == 0)
		{
			cout << "Please enter new contractor worker details:" << endl;
			c[i].ch = '*';
			cout << "enter profession worker:";
			cin >> c[i].profession;
			cout << "enter personalId:";
			cin >> c[i].id;
			cout << "enter firstname:";
			cin >> c[i].Firstname;
			cout << "enter secondname:";
			cin >> c[i].Lastname;
			cout << "enter phoneNumber:";
			cin >> c[i].Phone_Number;
			cout << "enter city:";
			cin >> c[i].City;
			cout << "enter adress:";
			cin >> c[i].Adress;
			cout << "enter username:";
			cin >> c[i].username;
			cout << "enter password:";
			cin >> c[i].password;
			cout << "[NEW CONTRUCTOR]" << c[i].username << " added to the system." << endl;
			break;
		}
	}
}
void login_CE(CompanyEmployee* c)
{
	int choice = 0;
	char username[20];
	char password[20];
	int index = 0;
	cout << "Please enter username:";
	cin >> username;
	while (Exist_Company_Username(c, username) == false)
	{
		cout << "No such a username in the database please try agian." << endl;
		cout << "Please enter username:";
		cin >> username;
	}
	cout << "Please enter password:";
	cin >> password;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c[i].username) == 0 && strcmp(password, c[i].password) == 0)
		{
			cout << "Vaild username and password, welcome" << c[i].Firstname;
			index = i;
			CompanyEmployeeMenu(c, index);
		}
		else if (strcmp(username, c[i].username) == 0 && !(strcmp(password, c[i].password) == 0))
		{
			while (choice != 2)
			{
				cout << "InVaild password, want to try agian?" << endl << "1.Yes" << endl << "2.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please enter password again:";
					cin >> password;
					if (strcmp(password, c[i].password) == 0)
					{
						cout << "Vaild username and password, welcome " << c[i].Firstname << endl;
						index = i;
						CompanyEmployeeMenu(c, index);
					}
					break;
				case 2:
					cout << "Bye Bye." << endl;
				default:
					cout << "No Such An Option, please try agian." << endl;
					break;
				}
			}
		}
	}
}
void login_C(Contractor* c)
{
	int choice = 0;
	char username[20];
	char password[20];
	int index = 0;
	cout << "Please enter username:";
	cin >> username;
	while (Exist_Contractor_Username(c, username) == false)
	{
		cout << "No such a username in the database please try agian." << endl;
		cout << "Please enter username:";
		cin >> username;
	}
	cout << "Please enter password:";
	cin >> password;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username, c[i].username) == 0 && strcmp(password, c[i].password) == 0)
		{
			cout << "Vaild username and password, welcome" << c[i].Firstname;
			index = i;
			ContractorMenu(c, index);
		}
		else if (strcmp(username, c[i].username) == 0 && !(strcmp(password, c[i].password) == 0))
		{
			while (choice != 2)
			{
				cout << "InVaild password, want to try agian?" << endl << "1.Yes" << endl << "2.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please enter password again:";
					cin >> password;
					if (strcmp(password, c[i].password) == 0)
					{
						cout << "Vaild username and password, welcome " << c[i].Firstname << endl;
						index = i;
						ContractorMenu(c, index);
					}
					break;
				default:
					cout << "No Such An Option, please try agian." << endl;
					break;
				}
			}
			cout << "Bye Bye." << endl;
		}
	}
}
void login_EE(ExternalEmployee* c)
{
	int choice = 0;
	char username[20];
	char password[20];
	int index = 0;
	cout << "Please enter username:";
	cin >> username;
	while (Exist_External_Username(c, username) == false)
	{
		cout << "No such a username in the database please try agian." << endl;
		cout << "Please enter username:";
		cin >> username;
	}
	cout << "Please enter password:";
	cin >> password;
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(username,c[i].username)==0  && strcmp(password,c[i].password)==0)
		{
			cout << "Vaild username and password, welcome" << c[i].Firstname;
			index = i;
			ExternalEmployeeMenu(c, index);
		}
		else if (strcmp(username, c[i].username) == 0 && !(strcmp(password, c[i].password) == 0))
		{
			while (choice != 2)
			{
				cout << "InVaild password, want to try agian?" << endl << "1.Yes" << endl << "2.Exit" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Please enter password again:";
					cin >> password;
					if (strcmp(password, c[i].password) == 0)
					{
						cout << "Vaild username and password, welcome " << c[i].Firstname << endl;
						index = i;
						ExternalEmployeeMenu(c, index);
					}
					break;
				default:
					cout << "No Such An Option, please try agian." << endl;
					break;
				}
			}
			cout << "Bye Bye." << endl;
		}
	}
}
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
{
	char username[20];
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
			cin >> c3[i].Firstname;
			cout << "enter secondname:";
			cin >> c3[i].Lastname;
			cout << "enter ID:";
			cin >> c3[i].id;
			cout << "enter city:";
			cin >> c3[i].City;
			cout << "enter adress:";
			cin >> c3[i].Adress;
			cout << "enter phoneNumber:";
			cin >> c3[i].Phone_Number;
			cout << "[NEW ACCOUNT]" << c3[i].username << " added to the system." << endl;
			break;
		}
	}
}
void ExternalEmployeeMenu(ExternalEmployee* c, int index)
{
	cout << "Hello" << endl;
}
void CompanyEmployeeMenu(CompanyEmployee* c, int index)
{
	cout << "Hello" << endl;
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