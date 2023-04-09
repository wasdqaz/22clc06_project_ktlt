#include "header.h"


void viewClass(SchoolYear *YearHead)
{
    string year;
    cout <<"School Year (example 21-22): \n";
    cin >>year;
    while (YearHead && YearHead -> BeginYear + "-" + YearHead -> EndYear != year)
    {
        YearHead = YearHead -> NextYear;
    }
    if (!YearHead) return;
    Class *ListClass = YearHead -> ClassHead;
    while (ListClass)
    {
        cout << ListClass -> Name << endl;
        ListClass = ListClass -> Next;
    }
}