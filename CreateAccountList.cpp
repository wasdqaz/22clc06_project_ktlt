#include "header.h"
#include <iostream>
#include <fstream>
using namespace std;
Account* MakeNewAccountOfStudent(string username, string password, string Class)
{
	Account* newAccount = new Account;
	newAccount->Class = Class;
	newAccount->Password = password;
	newAccount->Role = 2;
	newAccount->Status = 0;
	newAccount->username = username;
	newAccount->next = nullptr;
	return newAccount;
}
Account* MakeNewAccountOfStaff(string username, string password)
{
	Account* newAccount = new Account;
	
	newAccount->Password = password;
	newAccount->Role = 2;
	newAccount->Status = 0;
	newAccount->username = username;
	newAccount->next = nullptr;
	return newAccount;
}
void createAccountList(Account*& head, int role)
{
	ifstream in;
	if (role == 1) in.open("staff.txt");
	else in.open("student.txt");
	if (!in.is_open()) cout << "Can not open file";
	string s, s2, s3;
	Account* tmp = head;
	if (role == 1)
	{
		while (!in.eof())
		{
			in >> s >> s2;
			Account* newAccount = MakeNewAccountOfStaff(s, s2);
			if (head == nullptr)
			{
				head = newAccount;
				tmp = head;
			}
			else
			{
				tmp->next = newAccount;
				tmp = tmp->next;

			}



		}
		in.close();

	}
	else
	{
		while (!in.eof())
		{
			in >> s >> s2 >> s3;
			Account* newAccount = MakeNewAccountOfStudent(s, s2, s3);
			if (head == nullptr)
			{
				head = newAccount;
				tmp = head;
			}
			else
			{
				tmp->next = newAccount;
				tmp = tmp->next;

			}


		}
		in.close();


	}
}


