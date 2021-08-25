#include<iostream>
#include<string>
#define MAX 1000
using namespace std;

struct Person
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct AddressBook
{
	int size;
	struct Person pArray[MAX];
};

void menuShow()
{
	cout << "*****************************" << endl;
	cout << "*****  1--Add a Person\t*****" << endl;
	cout << "*****  2--ShowPerson\t*****" << endl;
	cout << "*****  3--DeletePerson\t*****" << endl;
	cout << "*****  4--Search Person\t*****" << endl;
	cout << "*****  5--Modify Person\t*****" << endl;
	cout << "*****  6--Clear Person\t*****" << endl;
	cout << "*****  7--Quit software\t*****" << endl;
	cout << "*****************************" << endl;
}

void addPerson(struct AddressBook p[])
{
	if (p->size == MAX)
	{
		cout << "Capacity is full, you can not add a new contact. . ." << endl;
		return ;
	}
	else
	{
		//Name
		cout << "Enter name..." << endl;
		string tempName;
		cin >> tempName;
		p->pArray[p->size].name = tempName;

		//Sex
		cout << "Enter sex, 1--male, 2--female" << endl;
		int tempSex = -1;
		while (true)
		{
			cin >> tempSex;
			if (tempSex == 1 || tempSex == 2)
			{
				p->pArray[p->size].sex = tempSex;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		//Age
		cout << "Enter age..." << endl;
		int tempAge = -1;
		while (true)
		{
			cin >> tempAge;
			if (tempAge > 0 && tempAge < 150)
			{
				p->pArray[p->size].age = tempAge;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		//Phone
		cout << "Enter phone number..." << endl;
		string tempPhone;
		while (true)
		{
			cin >> tempPhone;
			if (tempPhone.size() == 11)
			{
				p->pArray[p->size].phone = tempPhone;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		//Address
		cout << "Enter address..." << endl;
		string tempAddress;
		while (true)
		{
			cin >> tempAddress;
			if (tempAddress.size() > 0)
			{
				p->pArray[p->size].address = tempAddress;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

	}
	p->size++;
	cout << "You successfully added a record..." << endl;
	system("pause");
	system("cls");
}

void showPerson(struct AddressBook p[])
{
	if (p->size == 0)
	{
		cout << "Address book is empty..." << endl;
	}
	else
	{
		for (int i = 0; i < p->size; i++)
		{
			cout << "Name :" << p->pArray[i].name << "\t";
			cout << "Sex :" << (p->pArray[i].sex == 1 ? "Male" : "Female") << "\t";
			cout << "Age :" << p->pArray[i].age << "\t";
			cout << "Phone :" << p->pArray[i].phone << "\t";
			cout << "Adress :" << p->pArray[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}

//判断联系人是否存在
int isExist(struct AddressBook *p,string name)
{
	for (int i = 0; i < p->size; i++)
	{
		if (name == p->pArray[i].name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(struct AddressBook* p)
{
	string name;
	cout << "Enter the name of the target person..." << endl;
	cin >> name;
	int result = isExist(p, name);
	if (result == -1)
	{
		cout << "This person was not found..." << endl;
	}
	else
	{
		for (int i = result; i < p->size;i++)
		{
			p->pArray[i] = p->pArray[i + 1];
		}
		p->size--;
		cout << "Successfully deleted..." << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(struct AddressBook* p)
{
	string name;
	cout << "Enter the name of the target person..." << endl;
	cin >> name;
	int result = isExist(p, name);
	if (result == -1)
	{
		cout << "This person was not found..." << endl;
	}
	else
	{
		cout << "Information about the person you are looking for :" << endl;
		cout << "Name :" << p->pArray[result].name << "\t";
		cout << "Sex :" << (p->pArray[result].sex == 1 ? "Male" : "Female") << "\t";
		cout << "Age :" << p->pArray[result].age << "\t";
		cout << "Phone :" << p->pArray[result].phone << "\t";
		cout << "Adress :" << p->pArray[result].address << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(struct AddressBook* p)
{
	string name;
	cout << "Enter the name of the target person..." << endl;
	cin >> name;
	int result = isExist(p, name);
	if (result == -1)
	{
		cout << "This person was not found..." << endl;
	}
	else
	{
		
		//Name
		cout << "Enter name..." << endl;
		string tempName;
		cin >> tempName;
		p->pArray[result].name = tempName;

		//Sex
		cout << "Enter sex, 1--male, 2--female" << endl;
		int tempSex = -1;
		while (true)
		{
			cin >> tempSex;
			if (tempSex == 1 || tempSex == 2)
			{
				p->pArray[result].sex = tempSex;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		//Age
		cout << "Enter age..." << endl;
		int tempAge = -1;
		while (true)
		{
			cin >> tempAge;
			if (tempAge > 0 && tempAge < 150)
			{
				p->pArray[result].age = tempAge;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		//Phone
		cout << "Enter phone number..." << endl;
		string tempPhone;
		while (true)
		{
			cin >> tempPhone;
			if (tempPhone.size() == 11)
			{
				p->pArray[result].phone = tempPhone;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		//Address
		cout << "Enter address..." << endl;
		string tempAddress;
		while (true)
		{
			cin >> tempAddress;
			if (tempAddress.size() > 0)
			{
				p->pArray[result].address = tempAddress;
				break;
			}
			cout << "Illegal value entered, please enter again..." << endl;
		}

		cout << "Successfully modified..." << endl;
	}
	system("pause");
	system("cls");
}

void clearPerson(struct AddressBook* p)
{
	p->size = 0;
	cout << "Clear operation is completed" << endl;
	system("pause");
	system("cls");
}

int main()
{
	AddressBook adb;
	adb.size = 0;
	
	while (true)
	{
		menuShow();
		cout << "Please select a function" << endl;
		int select = -1;
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&adb);
			break;

		case 2:
			showPerson(&adb);
			break;

		case 3:
			deletePerson(&adb);
			break;

		case 4:
			findPerson(&adb);
			break;

		case 5:
			modifyPerson(&adb);
			break;

		case 6:
			clearPerson(&adb);
			break;

		case 7:
			cout << "Quit software...." << endl;
			return 0;
			break;
		default:
			cout << "Wrong choice, please re-enter. . ." << endl;
			//select = -1;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}