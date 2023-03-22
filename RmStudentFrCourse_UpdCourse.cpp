#include "header.h"
#include "functionOfDuy.h"
#include <iostream>
using namespace std;

void RmStudentFrCourse(Course *pHead) //con tro cac course trong hoc ki hien tai
{
    string CourseName;
    cout << "Enter the name of the course to remove student from: ";
    cin.ignore();
    getline(cin, CourseName);

    while (pHead != nullptr && pHead->CourseName != CourseName)
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