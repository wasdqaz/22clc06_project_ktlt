#include "header.h"

void viewClass(SchoolYear *YearHead, SchoolYear *curYear)
{
    if (!YearHead)
    {
        cout << "No schoolyear found" << endl;
        return;
    }
    string year;
    cout << "School Year (example 21-22): \n";
    cin >> year;
    if(year.length()!=5){
        cout<<"Wrong input.\n";
        return;
    }
    string curYear_classBegin = year.substr(0,2);
    int Begin_year = stoi(curYear_classBegin);
    string curYear_classEnd = year.substr(3,2);
    int End_year = stoi(curYear_classEnd);
    if (curYear_classBegin > curYear->BeginYear || Begin_year > End_year || End_year - Begin_year > 1)
    {
        cout <<"Errors: No schoolyear found!";
        return;
    }

    cout << "+-----------+" << endl;
    while (YearHead)
    {
        int Year = stoi(YearHead->BeginYear);
        if (Year > Begin_year - 4 && Year <= Begin_year)
        {
            Class *ListClass = YearHead->ClassHead;
            while (ListClass)
            {
                cout << setw(3) << left << " " << ListClass->Name << endl;
                ListClass = ListClass->Next;
            }
        }
        YearHead = YearHead->NextYear;
    }
    cout << "+-----------+" << endl;
    if (!YearHead)
        return;
}