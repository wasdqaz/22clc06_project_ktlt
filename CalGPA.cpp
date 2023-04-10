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
                count += 4;
                pHeadMark = pHeadMark->Next;
            }

            float temp = total/count;
            pHeadStudent->Gpa = temp*4.0 / 10.0;
            pHeadStudent = pHeadStudent->Next;
        }

        pHead = pHead->Next;
    }
}

void calGPASemester(Class *pHeadClass, Semester *pHeadSemester)
{
    string Smt = pHeadSemester->NameSemester.substr(9, 1);
    Class *pTemp = pHeadClass;

    if (pTemp == nullptr) {
        cout << "No class found!!!" << endl;
        return;
    }
    if (pHeadSemester == nullptr) {
        cout << "No semester found!!!" << endl;
        return;
    }

    while (pTemp != nullptr) {
        Student *TempStudent = pTemp->StudentHead;

        while (TempStudent != nullptr) {
            Mark *TempMark = TempStudent->HeadOfMark;
            float total = 0, count = 0;

            while (TempMark != nullptr) {
                string temp = TempMark->semester.substr(1, 1);
                if (temp == Smt && pTemp->Year == pHeadSemester->Year) {
                    total += TempMark->FinalMark + TempMark->MidtermMark + TempMark->OtherMark + TempMark->TotalMark;
                    count += 4;
                }
                TempMark = TempMark->Next;
            }
            float temp = total/count;
            TempStudent->SemesterGpa = temp*4.0 / 10.0;
            TempStudent = TempStudent->Next;
        }
        pTemp = pTemp->Next;
    }
}
