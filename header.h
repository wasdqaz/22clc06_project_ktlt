#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <stack>

using namespace std;

struct Account
{
    string username, Password;
    bool Status = false;
    int Role;
    string Class; // Them ID, Class; // ID: username
    Account *next;
};

struct Staff
{
    string Id, Name, Gender, Birth, Social_ID;
    Staff *Next;
};
struct Mark
{
    string NameOfCourse, Id;
    string semester;
    float TotalMark, FinalMark, MidtermMark, OtherMark;
    Mark *Next = nullptr;
    Mark *Prev = nullptr;
};
struct Student
{
    int No;
    string Id, Name, Gender, DateOfBirth, SocialId, Class; // da bo cai Course, them Ho Ten, ngay sinh va CCCD
    float Gpa, SemesterGpa;
    Mark *HeadOfMark = nullptr; // update head of mark
    Student *Next = nullptr;
    // bool Gender; // them gioi tinh
};

struct Course
{
    string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
    string NameSemester, Year;
    int NumberOfCredits, MaxStudent = 50;
    Student *CourseStudent = nullptr; // moi update them
    Course *Next = nullptr;
};

struct Class
{
    string Name, Year;
    Student *StudentHead = nullptr;
    Class *Next = nullptr;
};

struct Semester
{
    Course *CourseList = nullptr;
    string NameSemester, Year, StartDate, EndDate; // them ngay bat dau, ket thuc hk
    Semester *Next;
};

struct SchoolYear
{
    string BeginYear, EndYear;
    Class *ClassHead = nullptr;
    Semester *S1 = nullptr, *S2 = nullptr, *S3 = nullptr;
    SchoolYear *NextYear = nullptr; // them con tro cho nam hoc
};
// Login
Account *MakeNewAccountOfStudent(string username, string password, string Class);
Account *MakeNewAccountOfStaff(string username, string password);
void createAccountList(Account *&head, int role);
Account *Login(Account *head);

Staff *Find_Staff(Staff *pHead, string ID);
void PrintProfile_Staff(Account *User);
Class *Find_ClassName(Class *pHead, string Class_Name);
Student *Find_Student(Class *pClass, string ID);
void PrintProfile_Student(Account *User, SchoolYear *curYear);

void changePassword(Account *a);
bool checkPassword(string a);
void CreateSchoolYears(SchoolYear Year);
bool checkCourse(Course *head);

// Read list of Course and Class from File
void InputStudent(Student *&StuHead, string input);
void InputStudentCourse(Course *&subCourse, string input);
void InputMarkForStudent(Class *headOfClass, SchoolYear *headOfSchoolyear);
void ReadDirectory(const string &directoryPath, Course *&curCourse, Class *curClass, SchoolYear *&YearHead, SchoolYear *curYear);
void CreateClass(SchoolYear *YearHead);
// Read mark
Mark *makeMarkNode(double midterm, double final, double total);
void putMarkToStudentNode(Student *studentOfClass, Student *studentOfCourse, double midterm, double final, double total);
Student *FindNodeStudentOfCourseToPutMark(string id, Course *cur);
Student *FindNodeStudentOfClassToPutMark(string id, Class *head, string clss);
void InputMarkForStudent(SchoolYear *headOfSchoolyear, string input);
void AccessFileMark(string directoryPath, SchoolYear *headOfSchoolyear);
void viewClass(SchoolYear *YearHead);
void viewStudentClass(SchoolYear *YearHead);
void ViewListOfCourse(Course *head);

// Export course to CSV file
Course *FindCourse(SchoolYear *HeadOfYear);
void ExportCourseToCSVFile(SchoolYear *head, string parentFolder);

void Add_FolderSchoolYear(SchoolYear *Year);

void Add_FolderSemester(Semester *Smeter);

void Save_InfoCourse(Course *curCourse);
void Add_InfoCourse(Course *curCourse); // Semester mac dinh

void Add_FolderClass(Class *newClass);

#endif

