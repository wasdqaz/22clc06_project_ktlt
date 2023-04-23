#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include <stack>
#include <conio.h>
#include <io.h>
#include <windows.h>
#include <iomanip>

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
    string year;
    float TotalMark=0, FinalMark=0, MidtermMark=0, OtherMark=0;
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
    //Semester *Next;
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
//Save change password
void SaveChangePassword (Account* head);
Staff *Find_Staff(Staff *pHead, string ID);
void PrintProfile_Staff(Account *User, Staff *pHead);
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
void InputMarkForStudent(SchoolYear* headOfSchoolyear, string input);
void ReadDirectory(const string &directoryPath, Semester *&curSmeter, Course *&curCourse, Class *curClass, SchoolYear *&YearHead, SchoolYear *curYear);
void CreateClass(SchoolYear *YearHead);
// Read mark
Mark* makeMarkNode (double midterm, double final, double othermark, double total, string courseid,string coursename, string semester, string year);
void putMarkToStudentNode (Student* studentOfClass, Student* studentOfCourse, double midterm, double final,double othermark, double total, string courseid, string coursename,string semester, string year);
Student *FindNodeStudentOfCourseToPutMark(string id, Course *cur);
Student* FindNodeStudentOfClassToPutMark (string id, SchoolYear* headOfschoolyear, string clss);
void InputMarkForStudent(SchoolYear *headOfSchoolyear, string input);
void AccessFileMark(string directoryPath,  SchoolYear* headOfSchoolyear);
void viewClass(SchoolYear *YearHead);
void viewStudentClass(SchoolYear *YearHead);
void ViewListOfCourse(Course *head);

// Export course to CSV file
Course *FindCourse(SchoolYear *HeadOfYear);
void ExportCourseToCSVFile(SchoolYear *head, string parentFolder);
//import
string ImportScoreboardFromFileUser(SchoolYear* headOfyear);
void Add_FolderSchoolYear(SchoolYear *Year);

void Add_FolderSemester(Semester *Smeter);

void Add_InfoCourse(Course *curCourse); // Semester mac dinh

string nameSemester(string name);
void Save_InfoCourse(Course *curCourse);
void Save_StudentCourse_1(Student *StuCourse, string FileName);
void Save_StudentCourse_All(Course *curCourse);
void Save_StudentCourse_All_Mark(Course *curCourse, string FileName);
void Input_Student_Course_File(Student *&StuCourse, string FileName);
void CopyFile_Course(string fileCSV, string fileCourse);
void InputCSV_Course(Course *curCourse);
void Remove_File_Course(Course *curCourse);

//Save scoreboard
void SaveScorboardToFolderSchoolyear (string input);


//Quick input class 1st Year
void quickInputClass1stYear (SchoolYear* cur);
void SaveClass1stYearToFolderSchoolYear (string input, string clss, SchoolYear* cur);

//Save when add a student
void SaveWhenAdd1StudentToClass(Student *add,Student*head, string classname, SchoolYear *cur);


//menu
void STAFF_MENU();
void TextColor(int x);
void STUDENR_MENU();
void BeginningYear(int choice);
void BeginningSemester(int choice);
void EndOfSemester(int choice);
#endif

