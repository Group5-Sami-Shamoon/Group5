#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#define LENGTH 20
#include <iostream>
#include <fstream>
using namespace std;

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
<<<<<<< Updated upstream
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
=======
	int age;
	bool CheckInOut;
	float MissedDays;
} Contractor;
>>>>>>> Stashed changes

typedef struct
{
	int day;
	int month;
	int year;
	float S_Hour;
	float F_Hour;
	char employer[LENGTH];
	char employee[LENGTH];
	float Hour_Salary;
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
	float Daily_Salary;
	char City[LENGTH];
	char Adress[LENGTH];
	int Phone_Number;
	char profession[LENGTH];
	int seniority;
	Job j;
} Contractor;

bool Exist_Contractor_ID(Contractor* c, int id);
bool Exist_Company_ID(CompanyEmployee* c, int id);
bool Exist_External_ID(ExternalEmployee* c, int id);
bool Exist_ID(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, int id);
void ReadFromFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void WriteToFile(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void ContractorMenu(Contractor* c, int index);
void CompanyEmployeeMenu(CompanyEmployee* c, int index);
void ExternalEmployeeMenu(ExternalEmployee* c, int index);
void First_Menu(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void addNewContractor(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
void login_CE(CompanyEmployee* c1);
void login_C(Contractor* c2);
void login_EE(ExternalEmployee* c3);
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3);
bool Exist_Contractor_Username(Contractor* c, char username[]);
bool Exist_Company_Username(CompanyEmployee* c, char username[]);
bool Exist_External_Username(ExternalEmployee* c, char username[]);
bool Exist_Username(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3, char username[]);
bool Valid_Name(char name[]);
int main()
{
	float num;
<<<<<<< Updated upstream
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
=======
	int i = 0, choice = 0, count = 0;
	//קליטת המידע מהקובץ

	ifstream C_In;
	C_In.open("ContractorWorkers.txt");
	Contractor c[SIZE] = { 0 };
	for (i = 0; i < SIZE; i++)
>>>>>>> Stashed changes
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
	cout << endl;
	cout << "               Contractor Menu               " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
<<<<<<< Updated upstream
	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Work history" << endl << "5 - Exit." << endl;
	cin >> choise;
	switch (choise)
=======
	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Work history" << endl;
	cin >> choice;
	switch (choice)
>>>>>>> Stashed changes
	{
	case 1:
		break;
	case 2:
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
			C_Out2 << c2[i].seniority << endl;
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
void addNewContractor(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
{
	char username[LENGTH];
	char name[LENGTH];
	int id;
	for (int i = 0; i < SIZE; i++)
	{
		if (c2[i].ch == 0)
		{
			cout << "Please enter new external employee details" << endl;
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
			cin >> c2[i].Firstname;
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
			c3[i].id = id;
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
void login_CE(CompanyEmployee* c)
{
	int choice = 0;
	char username[LENGTH];
	char password[LENGTH];
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
			cout << "Vaild username and password, welcome " << c[i].Firstname << endl;
			index = i;
			CompanyEmployeeMenu(c, index);
		}
		else if (strcmp(username, c[i].username) == 0 && !(strcmp(password, c[i].password) == 0))
		{
			while (!(strcmp(password, c[i].password) == 0) && choice !=2)
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
					break;
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
	char username[LENGTH];
	char password[LENGTH];
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
			cout << "Vaild username and password, welcome " << c[i].Firstname << endl;
			index = i;
			ContractorMenu(c, index);
		}
		else if (strcmp(username, c[i].username) == 0 && !(strcmp(password, c[i].password) == 0))
		{
			while (!(strcmp(password, c[i].password) == 0) && choice != 2)
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
void login_EE(ExternalEmployee* c)
{
	int choice = 0;
	char username[LENGTH];
	char password[LENGTH];
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
			cout << "Vaild username and password, welcome " << c[i].Firstname <<endl;
			index = i;
			ExternalEmployeeMenu(c, index);
		}
		else if (strcmp(username, c[i].username) == 0 && !(strcmp(password, c[i].password) == 0))
		{
			while (!(strcmp(password, c[i].password) == 0) && choice != 2)
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
void Register(CompanyEmployee* c1, Contractor* c2, ExternalEmployee* c3)
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
void CompanyEmployeeMenu(CompanyEmployee* c, int index)
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

//              ##################################################### EILON ############################################################################
//              ##################################################### EILON ############################################################################
//              ##################################################### EILON ############################################################################
//              ##################################################### EILON ############################################################################
//              ##################################################### EILON ############################################################################
/*
{
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#define Max 50
using namespace std;
}
typedef struct 
{
	int day[Max];
	int month[Max];
	int year[Max];
	float S_Hour;
	float F_Hour;
	char employer[20];
	char employee[20];
	float Hour_Salary;
	float total;
	float premium;
}Job;
typedef struct 
{
	char Firstname[20];
	char Lastname[20];
	int id;
	char City[30];
	char Adress[30];
	int Phone_Number;
	int age;
	float salary;
	float hours=0;
	float MissedDays;
	bool CheckInOut;
	int UserID;
	Job vacation;
} Contractor;

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

	//קליטת המידע מהקובץ
	ifstream beta;
	beta.open("BetaFile.txt");
	beta >> size;

	//קליטת המידע מהקובץ
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
	
	//החזרת המידע והשינוי שלו אם יש צורך
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
/*
	cout << endl<< "Welcome to ContractNest." << endl;
	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Report hours" << endl << "5 - Work history" <<endl << "6 - Exit" <<endl;

	while (menu != 5)
	{
	cout <<	"Please enter the given to number to enter a category:" << endl;
	cin >> menu;
		switch (menu)
		{
		case 1:
			ClockReport(c,0);
			break;
		case 2:

			break;
		case 3:	
			VacationRequest(c, 0);
			break;
		case 4:
			break;

		}
	}

	cout << endl << "Thank you for choosing ContractNest <3"<<endl;
	//C_Out.close();//close file
	return 0;
}






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





#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#define LENGTH 20
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

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




bool CheckAvibillity(Contractor cont[SIZE], int day, int month, int year)     //בודק זמינות
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

bool Checkprofession(Contractor cont[SIZE],char* profession)      //בודק אם המקצוע קיים
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
	//CheckAvibillity(cont, day, month, year);    //מחזיר אמת או שקר
	//cout << "Profession" << endl;
	//Checkprofession(cont, profession);        //מחזיר אמת או שקר
	//cout << "Payment" << endl;
	//Checkpay(cont, pay_hour);                 //מחזיר אמת או שקר
	//cout << "Place" << endl;
	//CheckPlace(cont, city);           //מחזיר אמת או שקר
	//cout << "Seniority" << endl;
	//CheckVetek(cont, vetek);              //מחזיר אמת או שקר

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
//
//void InviteHistory(Contractor cont[SIZE])
//{
//	cout<< "This is the booking history by the emplooyer:" << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//		cout << "Profession booked:" << endl;
//	}
//
//}

int main()
{
	int menu = 0;
	int size;
	float num = 0;
	int i = 0;

	Contractor c[SIZE] = { NULL };
	cout << "Enter Name,Surname,ID";
	cin >> c[0].Firstname >> c[0].Lastname >> c[0].id;
	cout << endl;
	cout << c[0].Firstname << endl << c[0].Lastname << endl << c[0].id << endl;

	cout << endl << "Welcome to ContractNest." << endl;
	cout << "1 - Report hours" << endl << "2 - Salary calculation" << endl << "3 - Vacation report" << endl << "4 - Report hours" << endl << "5 - Work history" << endl << "6 - Exit" << endl;

	while (menu != 6)
	{
		cout << "Please enter the given to number to enter a category:" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			//ClockReport(c, 0);
			break;
		case 2:

			break;
		case 3:
			//VacationRequest(c, 0);
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}

	cout << endl << "Thank you for choosing ContractNest <3" << endl;

	return 0;



}
///oti///r//////////////////////////////////////////////otir
//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define SIZE 50
#define LENGTH 20
#include <iostream>
#include <fstream>
using namespace std;

typedef struct
{
	int type = 2;
	char username[LENGTH];
	char password[LENGTH];
	char ch;
	char Firstname[LENGTH];
	char Lastname[LENGTH];
	int id;
	float Daily_Salary;
	char City[LENGTH];
	char Adress[LENGTH];
	int Phone_Number;
	char profession[LENGTH];
	int seniority;

} Contractor;

void workHistory(Contractor* c, int cc);
int CountConstractorCases(Contractor* c, char* n);
bool checkContractor(Contractor c, char* n);
void printContractor(Contractor cTp);

int main() {

	return 0;

}

void workHistory(Contractor* c, int cCount) {

	for (int i = 0; i < cCount; i++) {

		printContractor(c[i]);
	}

}

int CountConstractorCases(Contractor* c, char* Contname) {

	int ContractorCounter;

	for (int i = 0; i < SIZE; i++) {

		if (checkContractor(c[i], Contname) == true)

			ContractorCounter++;

	}

	return ContractorCounter;

}

bool checkContractor(Contractor c, char* name) {

	if (strcmp(c.Firstname, name) == 0)

		return true;

	else

		return false;


}

void printContractor(Contractor cTp) {

	cout << "The contractor information is: " << endl;
	cout << "First name: " << cTp.Firstname;
	cout << "Last name: " << cTp.Lastname;
	cout << "ID: " << cTp.id;
	cout << "lives in: " << cTp.Adress;
	cout << "Phone: " << cTp.Phone_Number;
	cout << "Works in: " << cTp.profession;
	cout << "Years on the job: " << cTp.seniority;

}