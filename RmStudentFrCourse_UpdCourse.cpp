#include "header.h"
#include "functionOfDuy.h"
#include <iostream>
#include <string>
using namespace std;

void RmStudentFrCourse(Course *pHead) // con tro cac course trong hoc ki hien tai
{
    if (pHead == nullptr) {
        cout << "No course found!!!" << endl;
        return;
    }
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

    int choice;
    cout << "Do you want to remove this student from course?" << endl;
    cout << "1. Yes \n2. No \n->Your choice: ";
    cin >> choice;
    
    if (choice == 2)
        return;

    Student *pHeadStudent = pHead->CourseStudent;
    if (pHeadStudent->Id == Id) // nếu đây là hs đầu tiên trong list
    {
        // chuyển điểm hs đó thành -1
        pHeadStudent->HeadOfMark->FinalMark = -1;
        pHeadStudent->HeadOfMark->MidtermMark = -1;
        pHeadStudent->HeadOfMark->OtherMark = -1;
        pHeadStudent->HeadOfMark->TotalMark = -1;

        // xóa hs
        pHead->CourseStudent = pHead->CourseStudent->Next;
        delete pHeadStudent;
    }
    else
    {
    // đưa con trỏ đến hs trước hs cần xóa
    while (pHeadStudent->Next != nullptr && pHeadStudent->Next->Id != Id)
        pHeadStudent = pHeadStudent->Next;

    if (pHeadStudent->Next == nullptr)
    {
        cout << "No student found!!!" << endl;
        return;
    }

    // chuyển điểm hs đó thành -1
    pHeadStudent->Next->HeadOfMark->FinalMark = -1;
    pHeadStudent->Next->HeadOfMark->MidtermMark = -1;
    pHeadStudent->Next->HeadOfMark->OtherMark = -1;
    pHeadStudent->Next->HeadOfMark->TotalMark = -1;

    // xóa hs
    Student *Temp = pHeadStudent->Next;
    pHeadStudent->Next = pHeadStudent->Next->Next;
    delete Temp;
    }
    
    string pathSemester = "Data/SchoolYear/" + pHead->Year + "/" + pHead->NameSemester + "/";
    string Course_Name = pathSemester + pHead -> CourseName + "/";
    string nameSmter;
    Save_StudentCourse_All(pHead);
    string fileCourseMark = Course_Name + "mark_" + pHead->CourseId + ".txt";
    Save_StudentCourse_All_Mark(pHead, fileCourseMark);
    cout << "Delete successfully" << endl;
}

void UpdCourseInf(Course *pHead) // con tro danh sach cac course
{
    if (pHead == nullptr) {
        cout << "No course found!!!" << endl;
        return;
    }
    string CourseId;
    cout << "Please enter the ID of the course you want to update: ";
    cin.ignore();
    getline(cin, CourseId);
    string ClassName;
    cout << "Class name: ";
    getline(cin, ClassName);
    while (pHead != nullptr && pHead->CourseId != CourseId && pHead->ClassName != ClassName)
        pHead = pHead->Next;

    if (pHead == nullptr)
    {
        cout << "No course found!!!" << endl;
        return;
    }

    string TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent;

    cout << "Please enter the new information " << endl;
    /*cout << "Course ID: ";
    cin >> CourseId;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, CourseName);
    */
    cout << "Teacher name: ";
    getline(cin, TeacherName);
    cout << "Session (S1, S2, S3 or S4): ";
    getline(cin, Session);
    cout << "Day of week (MON, TUE, WED, THU, FRI or SAT): ";
    getline(cin, DayOfWeek);
    cout << "Number of credits: ";
    cin >> NumberOfCredits;
    /*cout << "Maximum number of student in the course: ";
    cin >> MaxStudent;*/

    int choice;
    cout << "Do you want to update?" << endl;
    cout << "1. Yes \n2. No \n->Your choice: ";
    cin >> choice;
    
    if (choice == 2)
        return;

    /*pHead->ClassName = ClassName;
    pHead->CourseId = CourseId;
    pHead->CourseName = CourseName;*/
    pHead->TeacherName = TeacherName;
    pHead->Session = Session;
    pHead->DayOfWeek = DayOfWeek;
    //pHead->MaxStudent = MaxStudent;
    pHead->NumberOfCredits = NumberOfCredits;
    
    //Save_InfoCourse(pHead);
    Save_StudentCourse_All(pHead);
    cout << "Update successfully" << endl;
}