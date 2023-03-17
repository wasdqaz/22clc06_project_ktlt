#include "header.h"
#include "functionOfDuy.h"
#include "iostream"
#include <string>
using namespace std;

void AddNewYear(SchoolYear *pHeadYear)
{
    if (pHeadYear == nullptr)
    {
        pHeadYear = new SchoolYear;
        pHeadYear->NextYear = nullptr;
        pHeadYear->ClassHead = nullptr;
        return;
    }

    while (pHeadYear->NextYear != nullptr)
        pHeadYear = pHeadYear->NextYear;
    
    pHeadYear->NextYear = new SchoolYear;
    pHeadYear->NextYear = nullptr;
    pHeadYear->ClassHead = nullptr;
}

Semester *AddNewSemester(SchoolYear *pHeadYear)
{
    int Smt;
    string Year, StartDate, EndDate;
    cout << "What semester do you want to create (1, 2 or 3): ";
    cin >> Smt;
    cout << "What year does it belong to (Ex: 2022-2023): ";
    cin >> Year;
    cout << "What is the start date (Ex: 30/04): ";
    cin >> StartDate;
    cout << "What is the end date (Ex: 30/08): ";
    cin >> EndDate;

    string Temp = StartDate.substr(0, 4);
    while (pHeadYear->BeginYear != Temp)
        pHeadYear = pHeadYear->NextYear;
    
    switch (Smt)
    {
        case 1:
            Semester *pHead = &pHeadYear->S1;
            pHead->StartDate = StartDate;
            pHead->EndDate = EndDate;
            return pHead;
            break;
        case 2:
            Semester *pHead = &pHeadYear->S2;
            pHead->StartDate = StartDate;
            pHead->EndDate = EndDate;
            return pHead;
            break;
        case 3:
            Semester *pHead = &pHeadYear->S3;
            pHead->StartDate = StartDate;
            pHead->EndDate = EndDate;
            return pHead;
            break;
    }
}