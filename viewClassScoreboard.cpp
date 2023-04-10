#include "functionOfDuy.h"
#include "header.h"

void viewClassScoreboard(Class *pHead, Semester *SemesterHead)
{
    string ClassName;
    cout << "Enter the class name to view scoreboard (Ex: 21CLC01): ";
    cin >> ClassName;

    Class *pTemp = pHead;
    while (pTemp != nullptr && pTemp->Name != ClassName)
        pTemp = pTemp->Next;
    if (pTemp == nullptr) {
        cout << "No class found!!!" << endl;
        return;
    }

    string Smt = SemesterHead->NameSemester.substr(9, 1);

    Student *StudentTemp = pTemp->StudentHead;
    while (StudentTemp != nullptr) {
        Mark *MarkTemp = StudentTemp->HeadOfMark;

        cout << setw(4) << left << "No";
        cout << setw(30) << left << "Name";

        while (MarkTemp != nullptr) {
            string tmp = MarkTemp->semester.substr(1, 1);
            if (tmp == Smt)
                cout << setw(10) << left << MarkTemp->Id;
            MarkTemp = MarkTemp->Next;
        }
        
        MarkTemp = StudentTemp->HeadOfMark;

        cout << setw(20) << left << "GPA This Semester";
        cout << setw(15) << left << "Overall GPA" << endl;

        cout << setw(4) << left << StudentTemp->No;
        cout << setw(30) << left << StudentTemp->Name;

        while (MarkTemp != nullptr) {
            string tmp = MarkTemp->semester.substr(1, 1);
            if (tmp == Smt)
                cout << setw(10) << left << MarkTemp->FinalMark;
            MarkTemp = MarkTemp->Next;
        }

        cout << setw(20) << left << StudentTemp->SemesterGpa;
        cout << setw(15) << left << StudentTemp->Gpa << endl << endl;

        StudentTemp = StudentTemp->Next;
    }
}