#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;


struct Account{
    string UserName, Password;
    //Type true = giao vien, false = hoc sinh
    //status true la log in con false la log out
    bool Status,Type;
};

struct Student{
    int No;
    string Name, Id, Class, Course;
    float Gpa, TotalMark, FinalMark, MidtermMark, OtherMark;//yeu cau 20
    Student *Next, *Prev=nullptr;//pre luc nao co tg thi uppdate
};

struct Class
{       
    
};



#endif