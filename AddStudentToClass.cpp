#include <iostream>
#include <string>
#include "functionOfDuy.h"
using namespace std;

void AddNewStudent(SchoolYear *pHeadYear)
{
    if (pHeadYear == nullptr) {
        cout << "No schoolyear found!!!" << endl;
        return;
    }
    while (pHeadYear->NextYear != nullptr)
        pHeadYear = pHeadYear->NextYear;
    Class *pHead = pHeadYear->ClassHead;
    string ClassName;
    cout << "Enter the class you want to add student to: ";
    cin >> ClassName;
    while (pHead != nullptr && pHead->Name != ClassName)
        pHead = pHead->Next;
    if (pHead == nullptr)
    {
        cout << "No class found!!!" << endl;
        return;
    }

    string Id, Name, Gender, DateOfBirth, SocialId;
    cout << "Please enter student information: " << endl;
    cout << "ID: ";
    cin >> Id;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Gender (Nam/Nu): ";
    getline(cin, Gender);
    cout << "Date of birth: ";
    cin >> DateOfBirth;
    cout << "Social ID: ";
    cin >> SocialId;

    int choice;
    cout << "Do you want to add this student?" << endl;
    cout << "1. Yes \n2. No \n->Your choice: ";
    cin >> choice;
    
    if (choice == 2)
        return;

    int No = 0;
    Student *Temp = pHead->StudentHead;
    if (Temp != nullptr)
    { // neu da co hs trong lop
        while (Temp->Next != nullptr)
            Temp = Temp->Next;
        No = Temp->No;
        Temp->Next = new Student;
        Temp->Next->Class = ClassName;
        Temp->Next->DateOfBirth = DateOfBirth;
        Temp->Next->Gender = Gender;
        Temp->Next->Id = Id;
        Temp->Next->Name = Name;
        Temp->Next->No = No + 1;
        Temp->Next->SocialId = SocialId;
        Temp->Next->HeadOfMark = nullptr;
        SaveWhenAdd1StudentToClass(Temp->Next, ClassName, pHeadYear );
    }
    else
    { // neu chua co hs nao trong lop
        pHead->StudentHead = new Student;
        pHead->StudentHead->Class = ClassName;
        pHead->StudentHead->DateOfBirth = DateOfBirth;
        pHead->StudentHead->Gender = Gender;
        pHead->StudentHead->Id = Id;
        pHead->StudentHead->Name = Name;
        pHead->StudentHead->No = No + 1;
        pHead->StudentHead->SocialId = SocialId;
        pHead->StudentHead->HeadOfMark = nullptr;
         SaveWhenAdd1StudentToClass ( pHead->StudentHead, ClassName,pHeadYear);
    }
    cout << "Add student to class successfully." << endl;
}
