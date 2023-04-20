#include "header.h"

void viewStudentClass(SchoolYear *YearHead)
{
    string year, Class_out;
    cout << "School Year (example 21-22): ";
    cin.ignore();
    cin >> year;
    cout << "Class: ";
    cin >> Class_out;
    while (YearHead && YearHead->BeginYear + "-" + YearHead->EndYear != year)
    {
        YearHead = YearHead->NextYear;
    }
    if (!YearHead)
        return;
    while (YearHead->ClassHead->Name != Class_out)
        YearHead->ClassHead = YearHead->ClassHead->Next;
    if (!YearHead->ClassHead)
        return;
    Student *ListStudent = YearHead->ClassHead->StudentHead;
    cout << setw(5) << left << "No";
    cout << setw(15) << left << "Student ID";
    cout << setw(40) << left << "Name" << endl;
    while (ListStudent)
    {
        cout << setw(5) << left << ListStudent->No;
        cout << setw(15) << left << ListStudent->Id;
        cout << setw(40) << left << ListStudent->Name << endl;
        ListStudent = ListStudent->Next;
    }
}