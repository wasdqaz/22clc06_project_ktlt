#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
using namespace std;

//quy tac dat ten bien: viet hoa chu dau moi tu vd HocSinh, Sinh, ....
//so thap phan de kieu float

struct Account{
    string UserName, Password;

    //Type true = giao vien, false = hoc sinh
    //status true la log in con false la log out
    bool Status,Type;
};

struct Student{
    Account Acc;
    int No;
    string Name, Id, Class, Course;
    float Gpa, TotalMark, FinalMark, MidtermMark, OtherMark;//yeu cau 20
    
};

struct Class
{       
    
};


#endif