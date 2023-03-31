#include <iostream>
#include "header.h"
#include "functionOfDuy.h"
using namespace std;

void CalGpa(Class *pHead)
{
    while (pHead != nullptr) {
        Student *pHeadStudent = pHead->StudentHead;

        while (pHeadStudent != nullptr) {
            Mark *pHeadMark = pHeadStudent->HeadOfMark;
            float total = 0, count = 0;

            while (pHeadMark != nullptr) {
                total += pHeadMark->FinalMark + pHeadMark->MidtermMark + pHeadMark->OtherMark + pHeadMark->TotalMark;
                count++;
                pHeadMark = pHeadMark->Next;
            }

            pHeadStudent->Gpa = total/count;
            pHeadStudent = pHeadStudent->Next;
        }

        pHead = pHead->Next;
    }
}
