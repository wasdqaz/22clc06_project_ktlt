#include "header.h"
#include "KhoiFunction.h"

void AddStudentToCourse(Course *CourseHead)
{
    string CourseID;
    cout << "Please input course id: \n";
    cin >> CourseID;

    string ClassName;
    cout << "Please enter class name: \n";
    cin >> ClassName;
    while (CourseHead->CourseId != CourseID && CourseHead->ClassName != ClassName)
    {
        CourseHead = CourseHead->Next;
    }
    /*Student *cur = new Student;
    cur->Next = CourseHead->CourseStudent;
    CourseHead->CourseStudent = cur;
    cout << "Enter name of student: ";
    cin.ignore();
    getline(cin, cur->Name);
    cout << "Enter student ID: ";
    cin >> cur->Id;
    cout << "Enter student's current class: ";
    cin >> cur->Class;*/

    string ID, name, Class;
    cout << "Enter student ID: ";
    cin >> ID;
    cout << "Enter name of student: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student's current class: ";
    cin >> Class;

    int choice = MenuYN("Do you want to add this student to the course?");
    
    if (choice == 2)
        return;

    Student *cur = CourseHead->CourseStudent;
    do
    {
        cur = cur->Next;
    } 
    while (cur->Next != nullptr);
    int No = cur->No;
    Student *New_Stu = new Student;
    New_Stu->No = No + 1;
    New_Stu->Id = ID;
    New_Stu->Name = name;
    New_Stu->Class = Class;
    cur->Next = New_Stu;
    string pathSemester = "Data/SchoolYear/" + CourseHead->Year + "/" + CourseHead->NameSemester + "/";
    string Course_Name = pathSemester + CourseHead->CourseName + "/";
    string nameSmter = nameSemester(CourseHead->NameSemester);
    string FileCourse = Course_Name + nameSmter + "_" + CourseHead->ClassName + "_" + CourseHead->CourseId + ".txt";
    Save_StudentCourse_1(New_Stu, FileCourse);
    string FileCourseMark = Course_Name + "mark_" + CourseHead->ClassName + "_" + CourseHead->CourseId + ".txt";
    Save_StudentCourse_1(New_Stu, FileCourseMark);
}
