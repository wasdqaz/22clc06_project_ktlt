#include "header.h"
#include "functionOfDuy.h"
#include "iostream"
#include <string>
using namespace std;

void AddNewYear(SchoolYear *&pHeadYear)
{
    string Temp;
    cout << "What is the school year (Ex: 2022-2023): ";
    cin >> Temp;
    if (pHeadYear == nullptr)
    {
        pHeadYear = new SchoolYear;
        pHeadYear->BeginYear = Temp.substr(0, 4);
        pHeadYear->EndYear = Temp.substr(5, 4);
        pHeadYear->NextYear = nullptr;
        pHeadYear->ClassHead = nullptr;
        return;
    }

    while (pHeadYear->NextYear != nullptr)
        pHeadYear = pHeadYear->NextYear;
    
    pHeadYear->NextYear = new SchoolYear;
    pHeadYear->BeginYear = Temp.substr(0, 4);
    pHeadYear->EndYear = Temp.substr(5, 4);
    pHeadYear->NextYear = nullptr;
    pHeadYear->ClassHead = nullptr;
}

Semester *AddNewSemester(SchoolYear *pHeadYear)
{
    int Smter;
    string Year, StartDate, EndDate;
    cout << "What semester do you want to create (1, 2 or 3): ";
    cin >> Smter;
    cout << "What year does it belong to (Ex: 2022-2023): ";
    cin >> Year;
    cout << "What is the start date (Ex: 30/04): ";
    cin >> StartDate;
    cout << "What is the end date (Ex: 30/08): ";
    cin >> EndDate;

    string Temp = StartDate.substr(0, 4);
    while (pHeadYear != nullptr && pHeadYear->BeginYear != Temp)
        pHeadYear = pHeadYear->NextYear;

    if (pHeadYear == nullptr)
    {
        cout << "No school year found!!!" << endl;
        return nullptr;
    }
    
    switch (Smter)
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

void AddCourse(Semester *pHeadSemester)
{
    string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent = 50;
    cout << "Please input the information of the course: " << endl;
    cout << "Course ID: ";
    cin >> CourseId;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, CourseName);
    cout << "Class name: ";
    cin.ignore();
    getline(cin, ClassName);
    cout << "Teacher name: ";
    cin.ignore();
    getline(cin, TeacherName);
    cout << "Session(S1, S2, S3 or S4): ";
    cin.ignore();
    getline(cin, Session);
    cout << "Day of week (MON, TUE, WED, THU, FRI or SAT): ";
    cin.ignore();
    getline(cin, DayOfWeek);
    cout << "Number of credits: ";
    cin >> NumberOfCredits;

    if (pHeadSemester->CourseList == nullptr)
    {
        pHeadSemester->CourseList = new Course;
        pHeadSemester->CourseList->ClassName = ClassName;
        pHeadSemester->CourseList->CourseId = CourseId;
        pHeadSemester->CourseList->CourseName = CourseName;
        pHeadSemester->CourseList->DayOfWeek = DayOfWeek;
        pHeadSemester->CourseList->MaxStudent = MaxStudent;
        pHeadSemester->CourseList->Session = Session;
        pHeadSemester->CourseList->NumberOfCredits = NumberOfCredits;
        pHeadSemester->CourseList->TeacherName = TeacherName;
        pHeadSemester->CourseList->Next = nullptr;
    }

    Course *pHeadCourse = pHeadSemester->CourseList;
    while (pHeadCourse->Next != nullptr)
        pHeadCourse = pHeadCourse->Next;

    pHeadCourse->Next = new Course;
    pHeadCourse->Next->ClassName = ClassName;
    pHeadCourse->Next->CourseId = CourseId;
    pHeadCourse->Next->CourseName = CourseName;
    pHeadCourse->Next->DayOfWeek = DayOfWeek;
    pHeadCourse->Next->MaxStudent = MaxStudent;
    pHeadCourse->Next->Session = Session;
    pHeadCourse->Next->NumberOfCredits = NumberOfCredits;
    pHeadCourse->Next->TeacherName = TeacherName;
    pHeadCourse->Next->Next = nullptr;
}