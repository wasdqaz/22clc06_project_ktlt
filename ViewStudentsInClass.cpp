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
    while (ListStudent)
    {
        cout << ListStudent->Name << endl;
        ListStudent = ListStudent->Next;
    }
}