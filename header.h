#ifndef _HEADER_H_
#define _HEADER_H_

#include<iostream>
#include<fstream>

using namespace std;


struct Account{
    string UserName, Password;
    bool Status,Type;
    Account *next;
};

struct Student{
    int No;
    string Name, Id, Class, Course;
    float Gpa, TotalMark, FinalMark, MidtermMark, OtherMark;
    Student *Next, *Prev=nullptr;
};

struct Course
{
    string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent = 50;
    Course *Next, *Prev = nullptr;
};

struct Class{
    Student *StudentHead;
    Class *next;
};

struct Semester{
    Course *SemesterHead;
    Semester *next;
};

struct SchoolYear{
    string BeginYear, EndYear;
    Class *ClassHead;
    Semester *S1, *S2, *S3;
};
void changePassword(Account &a);
bool checkPassword(string a);
void CreateSchoolYears(SchoolYear Year);
void CreateClass(Class a);

#endif