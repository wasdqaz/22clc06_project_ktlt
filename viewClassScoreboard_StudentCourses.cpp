#include "functionOfDuy.h"
#include "header.h"

void viewClassScoreboard(SchoolYear *pHead, Semester *SemesterHead, SchoolYear *YearHead)
{
    if (!pHead->ClassHead || !SemesterHead) {
        cout << "No class found!!!" << endl;
        return;
    }
    string ClassName;
    cout << "Enter the class name to view scoreboard (Ex: 22CLC01): ";
    cin >> ClassName;

    SchoolYear *tmp = pHead;
    Class *pTemp;
    while (tmp) {
        pTemp = tmp->ClassHead;
        while (pTemp != nullptr && pTemp->Name != ClassName)
            pTemp = pTemp->Next;
        if (pTemp && pTemp->Name == ClassName)
            break;
        tmp = tmp->NextYear;
    }

    if (pTemp == nullptr)
    {
        cout << "No class found!!!" << endl;
        return;
    }

    string Smt = SemesterHead->NameSemester.substr(9, 1);
    string curYear = YearHead->BeginYear;

    bool haveClass = false;
    Student *StudentTemp = pTemp->StudentHead;
    while (StudentTemp != nullptr)
    {
        haveClass = false;
        Mark *MarkTemp = StudentTemp->HeadOfMark;

        cout << setw(2) << left << "|" << setw(4) << left << "No";
        cout << setw(2) << left << "|" << setw(30) << left << "Name";

        while (MarkTemp != nullptr)
        {
            string tmp = MarkTemp->semester.substr(1, 1);
            string year = MarkTemp->year.substr(0, 2);
            if (tmp == Smt && year == curYear)
                if (MarkTemp->FinalMark != -1) {
                    cout << setw(2) << left << "|" << setw(10) << left << MarkTemp->Id;
                    haveClass = true;
                }
            MarkTemp = MarkTemp->Next;
        }

        cout << setw(2) << left << "|" << setw(20) << left << "GPA This Semester";
        cout << setw(2) << left << "|" << setw(15) << left << "Overall GPA" << "|" << endl;

        cout << setw(2) << left << "|" << setw(4) << left << StudentTemp->No;
        cout << setw(2) << left << "|" << setw(30) << left << StudentTemp->Name;

        MarkTemp = StudentTemp->HeadOfMark;

        while (MarkTemp != nullptr)
        {
            string tmp = MarkTemp->semester.substr(1, 1);
            string year = MarkTemp->year.substr(0, 2);
            if (tmp == Smt && year == curYear)
                if (MarkTemp->FinalMark != -1)
                    cout << setw(2) << left << "|" << setw(10) << left << MarkTemp->FinalMark;
            MarkTemp = MarkTemp->Next;
        }

        if (haveClass) {
            cout << setw(2) << left << "|" << setw(20) << left << StudentTemp->SemesterGpa;
            cout << setw(2) << left << "|" << setw(15) << left << StudentTemp->Gpa << "|" << endl;
        }
        else {
            cout << setw(2) << left << "|" << setw(20) << left << "0";
            cout << setw(2) << left << "|" << setw(15) << left << StudentTemp->Gpa << "|" << endl;
        }
        cout << endl;

        StudentTemp = StudentTemp->Next;
    }
}

void viewListOfCourses_Student(Semester *Semester_head, Account *Student_head)
{
    if (!Semester_head || !Student_head) {
        cout << "No Semester found!!!" << endl;
        return;
    }
    string StudentID = Student_head->username;
    Course *Temp = Semester_head->CourseList;
    
    cout << "+------------+-------------------------------+---------+-----------------------+-------------+---------+---------+" << endl;
    cout << setw(2) << left << "|" << setw(11) << left << "Course ID";
    cout << setw(2) << left << "|" << setw(30) << left << "Course name";
    cout << setw(2) << left << "|" << setw(8) << left << "Class";
    cout << setw(2) << left << "|" << setw(22) << left << "Teacher";
    cout << setw(2) << left << "|" << setw(12) << left << "Day of week";
    cout << setw(2) << left << "|" << setw(8) << left << "Session";
    cout << setw(2) << left << "|" << setw(8) << left << "Credits" << "|" << endl;
    cout << "+------------+-------------------------------+---------+-----------------------+-------------+---------+---------+" << endl;

    while (Temp != nullptr) {
        Student *tempStd = Temp->CourseStudent;

        while (tempStd != nullptr) {
            if (tempStd->Id == StudentID) {
                cout << setw(2) << left << "|" << setw(11) << left << Temp->CourseId;
                cout << setw(2) << left << "|" << setw(30) << left << Temp->CourseName;
                cout << setw(2) << left << "|" << setw(8) << left << Temp->ClassName;
                cout << setw(2) << left << "|" << setw(22) << left << Temp->TeacherName;
                cout << setw(2) << left << "|" << setw(12) << left << Temp->DayOfWeek;
                cout << setw(2) << left << "|" << setw(8) << left << Temp->Session;
                cout << setw(2) << left << "|" << setw(8) << left << Temp->NumberOfCredits << "|" << endl;
                break;
            }
            tempStd = tempStd->Next;
        }

        Temp = Temp->Next;
    }
    cout << "+------------+-------------------------------+---------+-----------------------+-------------+---------+---------+" << endl;
}