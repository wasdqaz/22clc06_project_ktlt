#include "header.h"
#include "KhoiFunction.h"

void AddStudentToCourse(Course *CourseHead)
{
    string CourseID;
    cout << "Please input course id: \n";
    cin >> CourseID;

    while (CourseHead->CourseId != CourseID)
    {
        CourseHead = CourseHead->Next;
    }
    Student *cur = new Student;
    cur->Next = CourseHead->CourseStudent;
    CourseHead->CourseStudent = cur;
    cout << "Enter name of student: ";
    cin.ignore();
    getline(cin, cur->Name);
    cout << "Enter student ID: ";
    cin >> cur->Id;
    cout << "Enter student's current class: ";
    cin >> cur->Class;

    string pathSemester = "Data/SchoolYear/" + CourseHead->Year + "/" + CourseHead->NameSemester + "/";
    string Course_Name = pathSemester + CourseHead->CourseName + "/";
    string nameSmter;
    if (CourseHead->NameSemester == "Semester01")
        nameSmter = "S1";
    else if (CourseHead->NameSemester == "Semester02")
        nameSmter = "S2";
    else
        nameSmter = "S3";
    string FileCourse = Course_Name + nameSmter + "_" + CourseHead->CourseId + ".txt";
    Save_StudentCourse_1(cur, FileCourse);
    string FileCourseMark = Course_Name + "mark/" + CourseHead->CourseId + ".txt";
    Save_StudentCourse_1(cur, FileCourseMark);
}
