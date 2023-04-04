#include "header.h"
#include "functionOfDuy.h"

Semester *defaultSemester(SchoolYear *pHead)
{
    if (pHead->S3)
        return pHead->S3;
    if (pHead->S2)
        return pHead->S2;
    return pHead->S1;
}