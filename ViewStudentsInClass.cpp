#include "header.h"

void viewStudentClass(SchoolYear *YearHead)
{
    if (!YearHead) {
        cout << "No schoolyear found" << endl;
        return;
    }
    string Year, Class_out;
    cout << "School Year (example 21-22): ";
    cin.ignore();
    cin >> Year;
    cout << "Class: ";
    cin >> Class_out;
    string yearClass = Class_out.substr(0,2);
    while (YearHead && YearHead->BeginYear != yearClass)
    {
        YearHead = YearHead->NextYear;
    }
    if (!YearHead) {
        cout << "Error: No schoolyear found!!!" << endl;
        return;
    }
    while (YearHead->ClassHead && YearHead->ClassHead->Name != Class_out)
        YearHead->ClassHead = YearHead->ClassHead->Next;
    if (!YearHead->ClassHead) {
        cout << "Error: No class found!!!" << endl;
        return;
    }
    Student *ListStudent = YearHead->ClassHead->StudentHead;
    cout << "+------+----------------+-----------------------------------------+" << endl;
    cout << setw(2) << left << "|" << setw(5) << left << "No";
    cout << setw(2) << left << "|" << setw(15) << left << "Student ID";
    cout << setw(2) << left << "|" << setw(40) << left << "Name" << "|" << endl;
    cout << "+------+----------------+-----------------------------------------+" << endl;
    while (ListStudent)
    {
        cout << setw(2) << left << "|" << setw(5) << left << ListStudent->No;
        cout << setw(2) << left << "|" << setw(15) << left << ListStudent->Id;
        cout << setw(2) << left << "|" << setw(40) << left << ListStudent->Name << "|" << endl;
        ListStudent = ListStudent->Next;
    }
    cout << "+------+----------------+-----------------------------------------+" << endl;
}