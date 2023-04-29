#include "header.h"

void viewClass(SchoolYear *YearHead)
{
    if (!YearHead)
    {
        cout << "No schoolyear found" << endl;
        return;
    }
    string year;
    cout << "School Year (example 21-22): \n";
    cin >> year;
    string curYear = year.substr(0,2);
    int Begin_year = stoi(curYear);

    cout << "+-----------+" << endl;
    while (YearHead)
    {
        int Year = stoi(YearHead->BeginYear);
        if (Year >= Begin_year - 4 && Year <= Begin_year)
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