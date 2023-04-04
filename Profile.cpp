#include "header.h"





Staff *Find_Staff(Staff *pHead, string ID)
{
    if (pHead == nullptr) return nullptr;
    Staff *cur = pHead;
    while (cur)
    {
        if (cur -> Id == ID)
            return cur;
        cur = cur -> Next;
    }
    return nullptr;
}

void PrintProfile_Staff(Account *User)
{
    Staff *StaffInfo;
    Staff *Staff_Info = Find_Staff(StaffInfo, User -> username);
    cout << "Profile\n";
    cout << "Academic staff member\n";
    cout << "Id: " << StaffInfo -> Id <<endl;
    cout << "Name: " << StaffInfo -> Name << endl;
    cout << "Gender: " << StaffInfo -> Gender << endl;
    cout << "Birth: "<< StaffInfo -> Birth << endl;
    cout << "Social ID: " << StaffInfo -> Social_ID << endl;
}

Class *Find_ClassName(Class *pHead, string Class_Name)
{
    if (pHead == nullptr) return nullptr;
    Class *cur = pHead;
    while (cur)
    {
        if (cur -> Name == Class_Name)
            return cur;
        cur = cur -> Next;
    }
    return nullptr;
}

Student *Find_Student(Class *pClass, string ID)
{
    Student *Stu_Head = pClass -> StudentHead;
    while (Stu_Head)
    {
        if (Stu_Head -> Id == ID)
            return Stu_Head;
        Stu_Head = Stu_Head -> Next;
    }
    return nullptr;
}

void PrintProfile_Student(Account *User, SchoolYear *curYear)
{
    string Stu_Class = User -> Class;
    Class *Class_Info = Find_ClassName(curYear -> ClassHead, Stu_Class);
    Student *Student_Info = Find_Student(Class_Info, User -> username);
    cout << "Profile\n";
    cout << "Student\n";
    cout << "No: " << Student_Info -> No << endl;
    cout << "ID: " << Student_Info -> Id << endl;
    cout << "Name: "<< Student_Info -> Name <<endl;
    cout << "Gender: " << Student_Info -> Gender << endl;
    cout << "Birth: "<< Student_Info -> DateOfBirth << endl;
    cout << "Social ID: " << Student_Info -> SocialId << endl;
}
