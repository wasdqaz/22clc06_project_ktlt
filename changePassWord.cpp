#include "header.h"
bool checkPassword(string a){
    for (int i = 0; i < a.size(); i++)
        if(a[i]==' ')return false;
    return true;
}
void changePassword(Account *a){
    string tmp;
    cout<<"Enter old password: ";
    cin.ignore();
    getline(cin, tmp);
    while(tmp != a->Password){
        cout<<"Invalid password!!! Please re-enter.\n";
        getline(cin, tmp);
    }
    cout<<"Enter new password: ";
    getline(cin, tmp);
    while(checkPassword(tmp)==0){
        cout<<"Invalid password!!! Please re-enter.\n";
        cout<<"The password mustn't include the character " ".\n";
        cout<<"Enter new password: ";
        getline(cin, tmp);
    }
    a->Password = tmp;
    cout<<"Change password successfully!!!\n";
}

