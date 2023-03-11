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

struct Course;

struct Student{
    int No;
    string F_Name, L_Name, Id, Class; //da bo cai Course va them Ho Ten
    float Gpa, TotalMark, FinalMark, MidtermMark, OtherMark;
    Course *CoursesOfStudentHead; //moi update them
    Student *Next, *Prev=nullptr;
};

struct Course
{
    string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent = 50;
    Student *CourseStudent; // moi update them
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
