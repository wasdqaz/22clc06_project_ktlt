#include "header.h"
#include "functionOfDuy.h"
#include "iostream"
#include <string>
using namespace std;

void AddNewYear(SchoolYear *&pHeadYear) //con tro toan bo cac nam hoc
{
    string Temp;
    cout << "What is the school year you want to create (Ex: 2022-2023): ";
    cin >> Temp;
    if (pHeadYear == nullptr)
    {
        pHeadYear = new SchoolYear;
        pHeadYear->BeginYear = Temp.substr(2, 2);
        pHeadYear->EndYear = Temp.substr(7, 2);
        pHeadYear->NextYear = nullptr;
        pHeadYear->ClassHead = nullptr;
        Add_FolderSchoolYear(pHeadYear);
        //cout << "Add new school year successfully" << endl;
        return;
    }

    SchoolYear *temp = pHeadYear;

    while (temp->NextYear != nullptr)
        temp = temp->NextYear;
    
    temp->NextYear = new SchoolYear;
    temp->NextYear->BeginYear = Temp.substr(2, 2);
    temp->NextYear->EndYear = Temp.substr(7, 2);
    temp->NextYear->NextYear = nullptr;
    temp->NextYear->ClassHead = nullptr;
    Add_FolderSchoolYear(temp->NextYear);
    //cout << "Add new school year successfully" << endl;
}

Semester *AddNewSemester(SchoolYear *pHeadYear) //con tro toan bo cac nam hoc
{
    int Smter;
    string StartDate, EndDate;
    cout << "What semester do you want to create (1, 2 or 3): ";
    cin >> Smter;
    cout << "What is the start date (Ex: 30/04): ";
    cin >> StartDate;
    cout << "What is the end date (Ex: 30/08): ";
    cin >> EndDate;

    if (pHeadYear == nullptr)
    {
        cout << "No school year found!!!" << endl;
        return nullptr;
    }
    
    switch (Smter)
    {
        case 1:
        {
            if (pHeadYear->S1 == nullptr) {
                pHeadYear->S1 = new Semester;
                pHeadYear->S1->StartDate = StartDate;
                pHeadYear->S1->EndDate = EndDate;
                pHeadYear->S1->Next = nullptr;
                Add_FolderSemester(pHeadYear, pHeadYear -> S1);
                //cout << "Semester created" << endl;
            }
            else
                cout << "S1 has already existed.";
            return pHeadYear->S1;
        }
        case 2:
        {
            if (pHeadYear->S2 == nullptr) {
                pHeadYear->S2 = new Semester;
                pHeadYear->S2->StartDate = StartDate;
                pHeadYear->S2->EndDate = EndDate;
                pHeadYear->S2->Next = nullptr;
                Add_FolderSemester(pHeadYear, pHeadYear -> S2);
                //cout << "Semester created" << endl;
            }
            else
                cout << "S2 has already existed.";
            return pHeadYear->S2;
        }
        case 3:
        {
            if (pHeadYear->S3 == nullptr) {
                pHeadYear->S3 = new Semester;
                pHeadYear->S3->StartDate = StartDate;
                pHeadYear->S3->EndDate = EndDate;
                pHeadYear->S3->Next = nullptr;
                Add_FolderSemester(pHeadYear, pHeadYear -> S3);
                //cout << "Semester created" << endl;
            }
            else
                cout << "S3 has already existed.";
            return pHeadYear->S3;
        }
    }
    return nullptr;
}

void AddCourse(SchoolYear *Year, Semester *pHeadSemester) //con tro hoc ki mac dinh
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
    getline(cin, ClassName);
    cout << "Teacher name: ";
    getline(cin, TeacherName);
    cout << "Session(S1, S2, S3 or S4): ";
    getline(cin, Session);
    cout << "Day of week (MON, TUE, WED, THU, FRI or SAT): ";
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
        pHeadSemester->CourseList->CourseStudent = nullptr;
        Add_InfoCourse(Year, pHeadSemester);
        //cout << "Add course successfully" << endl;
        return;
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
    pHeadCourse->Next->CourseStudent = nullptr;
    Add_InfoCourse(Year, pHeadSemester);
    cout << "Add course successfully" << endl;
}