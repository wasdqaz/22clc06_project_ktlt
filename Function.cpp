#include "header.h"

void PrintProfile_Staff(Staff *User)
{
    cout << "Profile\n";
    cout << "Academic staff member\n";
    cout << "Id: " << User -> Id <<endl;
    cout << "Name: " << User -> Name << endl;
    cout << "Gender: " << User -> Gender << endl;
    cout << "Birth: "<< User -> Birth << endl;
    cout << "Social ID: " << User -> Social_ID << endl;
}

void PrintProfile_Student(Student *User)
{
    cout << "Profile\n";
    cout << "Student\n";
    cout << "No: " << User -> No << endl;
    cout << "ID: " << User -> Id << endl;
    cout << "Name: "<< User -> Name <<endl;
    cout << "Gender: " << User -> Gender << endl;
    cout << "Birth: "<< User -> DateOfBirth << endl;
    cout << "Social ID: " << User -> SocialId << endl;
}

Staff *Find_Staff(Staff *pHead, string ID)
{
    if (pHead == nullptr) return;
    Staff *cur = pHead;
    while (cur)
    {
        if (cur -> Id == ID)
            return cur;
        cur = cur -> pNext;
    }
    return nullptr;
}
Class *Find_ClassName(Class *pHead, string Class_Name)
{
    if (pHead == nullptr) return;
    Class *cur = pHead;
    while (cur)
    {
        if (cur -> Name == Class_Name)
            return cur;
        cur = cur -> next;
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
void Profile(Account *User, Staff *StaffInfo, Class *ClassName)
{
    string ID = User -> username;
    if (User -> Role == 1)
    {
        Staff *Staff_Info = Find_Staff(StaffInfo, ID);
        PrintProfile_Staff(Staff_Info);
    }
    else
    {
        string Stu_Class = User -> Class;
        Class *Class_Info = Find_ClassName(ClassName, Stu_Class);
        Student *Student_Info = Find_Student(Class_Info, ID);
        PrintProfile_Student(Student_Info);
    }
}