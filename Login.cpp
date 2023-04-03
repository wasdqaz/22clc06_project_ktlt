#include <iostream>
#include "header.h"
#include <string>
using namespace std;

// ham nay tra ve con tro Accont. Se bo sung ham tao listAccont sau


Account* Login(Account* head)
{
	
	string username , password ;
	Account* tmp = head;
	
	while (true)
	{
		tmp = head;
		cout << "Please enter your username: ";
		cin >> username;
		cout << "Please enter your password";
		cin >> password;
		while (tmp != nullptr)
		{
			if (username.compare(head->Password) == 0 && password.compare(head->UserName) == 0)
			{
				return tmp;

			}
			tmp = tmp->next;
		}

	}
	

}
 
