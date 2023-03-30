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

    Student *Temp = pHead->StudentHead;
    while (Temp->Next != nullptr)
        Temp = Temp->Next;  

    int No = Temp->No;
    Temp->Next = new Student;
    Temp->Class = ClassName;
    Temp->DateOfBirth = DateOfBirth;
    Temp->Gender = Gender;
    Temp->Id = Id;
    Temp->Name = Name;
    Temp->No = No+1;
    Temp->SocialId = SocialId;
}
