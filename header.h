    #ifndef _HEADER_H_
    #define _HEADER_H_

    #include<iostream>
    #include<fstream>
    #include<string>
    using namespace std;


    struct Account{
        string username, Password;
        bool Status = false;
        int Role;
        string Class;           // Them ID, Class; // ID: username
        Account *next;
    };

    struct Staff{
        string Id, Name, Gender, Birth, Social_ID;
        Staff *pNext;
    };
    struct Student{
        int No;
        string Name, Id, Class, Gender, DateOfBirth, SocialId; //da bo cai Course, them Ho Ten, ngay sinh va CCCD
        float Gpa, TotalMark, FinalMark, MidtermMark, OtherMark;
        Course *CoursesOfStudentHead; //moi update them
        Student *Next, *Prev=nullptr;
        bool Male; // them gioi tinh
    };

    struct Course
    {
        string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
        int NumberOfCredits, MaxStudent = 50;
        Student *CourseStudent; // moi update them
        Course *Next, *Prev = nullptr;
    };

    struct Class{
        string Name;
        Student *StudentHead;
        Class *next, *tail;
    };

    struct Semester{
        Course *CourseList;
        string StartDate, EndDate; // them ngay bat dau, ket thuc hk
        Semester *next;
    };

    struct SchoolYear{
        string BeginYear, EndYear;
        Class *ClassHead;
        Semester S1, S2, S3;
        SchoolYear *NextYear; //them con tro cho nam hoc
    };
    void changePassword(Account &a);
    bool checkPassword(string a);
    void CreateSchoolYears(SchoolYear Year);
    void Input_Class(Class *&ClassHead);

    #endif
