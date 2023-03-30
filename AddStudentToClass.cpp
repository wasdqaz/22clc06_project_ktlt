#include <iostream>
#include <string>
#include "functionOfDuy.h"
using namespace std;

void AddNewStudent(Class *pHead)
{
    string ClassName;
    cout << "Enter the class you want to add student to: ";
    cin >> ClassName;
    while (pHead != nullptr && pHead->Name != ClassName)
        pHead = pHead->next;
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
    cout << "Gender (Male/Female): ";
    getline(cin, Gender);
    cout << "Date of birth: ";
    cin >> DateOfBirth;
    cout << "Social ID: ";
    cin >> SocialId;

    int No = 0;
    Student *Temp = pHead->StudentHead;
    if (Temp != nullptr) { //neu da co hs trong lop
        while (Temp->Next != nullptr)
            Temp = Temp->Next;
        No = Temp->No;
        Temp->Next = new Student;
        Temp->Next->Class = ClassName;
        Temp->Next->DateOfBirth = DateOfBirth;
        Temp->Next->Gender = Gender;
        Temp->Next->Id = Id;
        Temp->Next->Name = Name;
        Temp->Next->No = No+1;
        Temp->Next->SocialId = SocialId;
        Temp->Next->HeadOfMark = nullptr;
    }
    else { //neu chua co hs nao trong lop
    pHead->StudentHead = new Student;
    pHead->StudentHead->Class = ClassName;
    pHead->StudentHead->DateOfBirth = DateOfBirth;
    pHead->StudentHead->Gender = Gender;
    pHead->StudentHead->Id = Id;
    pHead->StudentHead->Name = Name;
    pHead->StudentHead->No = No+1;
    pHead->StudentHead->SocialId = SocialId;
    pHead->StudentHead->HeadOfMark = nullptr;
    }
}
