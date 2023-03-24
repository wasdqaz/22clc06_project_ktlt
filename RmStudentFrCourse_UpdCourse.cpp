#include "header.h"
#include "functionOfDuy.h"
#include <iostream>
#include <string>
using namespace std;

void RmStudentFrCourse(Course *pHead) //con tro cac course trong hoc ki hien tai
{
    string CourseId;
    cout << "Enter the ID of the course to remove student from: ";
    cin.ignore();
    getline(cin, CourseId);

    while (pHead != nullptr && pHead->CourseId != CourseId)
        pHead = pHead->Next;
    
    if (pHead == nullptr || pHead->CourseStudent == nullptr)
    {
        cout << "No course found or class has no student!!!" << endl;
        return;
    }

    string Id;
    cout << "Enter the ID of the student you want to remove: ";
    getline(cin, Id);

    Student *pHeadStudent = pHead->CourseStudent;
    if (pHeadStudent->Id == Id)
    {   
        pHead->CourseStudent = pHead->CourseStudent->Next;
        delete pHeadStudent;
        cout << "Delete successfully" << endl;
        return;
    }

    while (pHeadStudent->Next != nullptr && pHeadStudent->Next->Id != Id)
        pHeadStudent = pHeadStudent->Next;
    
    if (pHeadStudent->Next == nullptr)
    {
        cout << "No student found!!!" << endl;
        return;
    }

    Student *Temp = pHeadStudent->Next;
    pHeadStudent->Next = pHeadStudent->Next->Next;
    delete Temp;
    cout << "Delete successfully" << endl;
}

void UpdCourseInf(Course *pHead) //con tro danh sach cac course
{
    string CourseId;
    cout << "Please enter the ID of the course you want to update: ";
    cin.ignore();
    getline(cin, CourseId);

    while (pHead != nullptr && pHead->CourseId != CourseId)
        pHead = pHead->Next;

    if (pHead == nullptr)
    {
        cout << "No course found!!!" << endl;
        return;
    }

    string CourseName, ClassName, TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent;

    cout << "Please enter the new information: " << endl;
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
    cout << "Session (S1, S2, S3 or S4): ";
    cin.ignore();
    getline(cin, Session);
    cout << "Day of week (MON, TUE, WED, THU, FRI or SAT): ";
    cin.ignore();
    getline(cin, DayOfWeek);
    cout << "Number of credits: ";
    cin >> NumberOfCredits;
    cout << "Maximum number of student in the course: ";
    cin >> MaxStudent;

    pHead->ClassName = ClassName;
    pHead->CourseId = CourseId;
    pHead->CourseName = CourseName;
    pHead->DayOfWeek = DayOfWeek;
    pHead->MaxStudent = MaxStudent;
    pHead->NumberOfCredits = NumberOfCredits;
    pHead->Session = Session;
    pHead->TeacherName = TeacherName;
    cout << "Update successfully" << endl;
}