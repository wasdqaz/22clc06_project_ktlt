#include "header.h"
#include "functionOfDuy.h"
#include "iostream"
using namespace std;

void AddNewYear(SchoolYear *pHeadYear)
{
    if (pHeadYear == nullptr)
    {
        pHeadYear = new SchoolYear;
        pHeadYear->NextYear = nullptr;
        pHeadYear->ClassHead = nullptr;
        pHeadYear->S1 = nullptr;
        pHeadYear->S2 = nullptr;
        pHeadYear->S3 = nullptr;
        return;
    }

    while (pHeadYear->NextYear != nullptr)
        pHeadYear = pHeadYear->NextYear;
    
    pHeadYear->NextYear = new SchoolYear;
    pHeadYear->NextYear = nullptr;
    pHeadYear->ClassHead = nullptr;
    pHeadYear->S1 = nullptr;
    pHeadYear->S2 = nullptr;
    pHeadYear->S3 = nullptr;
}

Semester *AddNewSemester(SchoolYear *pHeadYear)
{
    
}