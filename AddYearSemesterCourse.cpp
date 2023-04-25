#include "header.h"
#include "functionOfDuy.h"

void AddNewYear(SchoolYear *&pHeadYear) // con tro toan bo cac nam hoc
{
    string Temp;
    while (true) {
        cout << "What is the school year you want to create (Ex: 2022-2023): ";
        cin >> Temp;

        if (Temp.length() != 9) {
            cout << "Wrong input!!! Please re-enter: " << endl;
            continue;
        }

        SchoolYear *temp = pHeadYear;
        while (temp != nullptr) {
            string tmp = Temp.substr(2, 2);
            if (temp->BeginYear.compare(tmp) == 0) {
                cout << "School year has existed already!!!" << endl;
                cout << "Please re-enter: " << endl;
                break;
            }
            else
                temp = temp->NextYear;
        }
        if (temp != nullptr)
            continue;
        break;
    }

    int choice = MenuYN("Do you want to add new school year?");
    
    if (choice == 2)
        return;

    if (pHeadYear == nullptr)
    {
        pHeadYear = new SchoolYear;
        pHeadYear->BeginYear = Temp.substr(2, 2);
        pHeadYear->EndYear = Temp.substr(7, 2);
        pHeadYear->NextYear = nullptr;
        pHeadYear->ClassHead = nullptr;
        Add_FolderSchoolYear(pHeadYear);
        // cout << "Add new school year successfully" << endl;
        return;
    }

    SchoolYear *temp = pHeadYear;

    temp->NextYear = new SchoolYear;
    temp->NextYear->BeginYear = Temp.substr(2, 2);
    temp->NextYear->EndYear = Temp.substr(7, 2);
    temp->NextYear->NextYear = nullptr;
    temp->NextYear->ClassHead = nullptr;
    pHeadYear = temp->NextYear;
    Add_FolderSchoolYear(pHeadYear);
    // cout << "Add new school year successfully" << endl;
}

Semester *AddNewSemester(SchoolYear *pHeadYear) // con tro toan bo cac nam hoc
{
    SchoolYear *tmp = pHeadYear;
    while (tmp->NextYear != nullptr)
        tmp = tmp->NextYear;
    
    if (pHeadYear == nullptr) {
        cout << "No schoolyear found!!!" << endl;
        return defaultSemester(tmp);
    }
    int Smter;
    string StartDate, EndDate;
    cout << "What semester do you want to create (1, 2 or 3): ";
    cin >> Smter;
    cout << "What is the start date (Ex: 30/04): ";
    cin >> StartDate;
    cout << "What is the end date (Ex: 30/08): ";
    cin >> EndDate;

    if (pHeadYear == nullptr)
    {
        cout << "No school year found!!!" << endl;
        return nullptr;
    }

    int choice = MenuYN("Do you want to add new semester?");

    if (choice == 2)
        return defaultSemester(tmp);

    string YearName = pHeadYear->BeginYear + "-" + pHeadYear->EndYear;
    switch (Smter)
    {
    case 1:
    {
        if (pHeadYear->S1 == nullptr)
        {
            pHeadYear->S1 = new Semester;
            pHeadYear->S1->NameSemester = "Semester01";
            pHeadYear->S1->StartDate = StartDate;
            pHeadYear->S1->EndDate = EndDate;
            pHeadYear->S1->Year = YearName;
            Add_FolderSemester(pHeadYear->S1);
            // cout << "Semester created" << endl;
        }
        else
            cout << "S1 has already existed.";
        return pHeadYear->S1;
    }
    case 2:
    {
        if (pHeadYear->S2 == nullptr)
        {
            pHeadYear->S2 = new Semester;
            pHeadYear->S1->NameSemester = "Semester02";
            pHeadYear->S2->StartDate = StartDate;
            pHeadYear->S2->EndDate = EndDate;
            pHeadYear->S2->Year = YearName;
            Add_FolderSemester(pHeadYear->S2);
            // cout << "Semester created" << endl;
        }
        else
            cout << "S2 has already existed.";
        return pHeadYear->S2;
    }
    case 3:
    {
        if (pHeadYear->S3 == nullptr)
        {
            pHeadYear->S3 = new Semester;
            pHeadYear->S3->NameSemester = "Semester03";
            pHeadYear->S3->StartDate = StartDate;
            pHeadYear->S3->EndDate = EndDate;
            pHeadYear->S3->Year = YearName;
            Add_FolderSemester(pHeadYear->S3);
            // cout << "Semester created" << endl;
        }
        else
            cout << "S3 has already existed.";
        return pHeadYear->S3;
    }
    }
    return nullptr;
}

void AddCourse(Semester *pHeadSemester) // con tro hoc ki mac dinh
{   
    if(pHeadSemester==nullptr){
        cout<<"Please create semester first.\n";
        return;
    }
    string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent = 50;
    cout << "Please input the information of the course: " << endl;
    cout << "Course ID: ";
    cin >> CourseId;
    cout << "Course name: ";
    cin.ignore();
    getline(cin, CourseName);
    cout << "Class name: ";
    getline(cin, ClassName);
    cout << "Teacher name: ";
    getline(cin, TeacherName);
    cout << "Session(S1, S2, S3 or S4): ";
    getline(cin, Session);
    cout << "Day of week (MON, TUE, WED, THU, FRI or SAT): ";
    getline(cin, DayOfWeek);
    cout << "Number of credits: ";
    cin >> NumberOfCredits;

    int choice = MenuYN("Do you want to add new course?");

    if (choice == 2)
        return;
    
    if (pHeadSemester->CourseList == nullptr)
    {
        pHeadSemester->CourseList = new Course;
        pHeadSemester->CourseList->NameSemester = pHeadSemester -> NameSemester;
        pHeadSemester->CourseList->Year = pHeadSemester -> Year;
        pHeadSemester->CourseList->ClassName = ClassName;
        pHeadSemester->CourseList->CourseId = CourseId;
        pHeadSemester->CourseList->CourseName = CourseName;
        pHeadSemester->CourseList->DayOfWeek = DayOfWeek;
        pHeadSemester->CourseList->MaxStudent = MaxStudent;
        pHeadSemester->CourseList->Session = Session;
        pHeadSemester->CourseList->NumberOfCredits = NumberOfCredits;
        pHeadSemester->CourseList->TeacherName = TeacherName;
        pHeadSemester->CourseList->Next = nullptr;
        pHeadSemester->CourseList->CourseStudent = nullptr;
        pHeadSemester->CourseList->Year = pHeadSemester->Year;
        pHeadSemester->CourseList->NameSemester = pHeadSemester->NameSemester;
        Add_InfoCourse(pHeadSemester->CourseList);
        // cout << "Add course successfully" << endl;
        return;
    }

    Course *pHeadCourse = pHeadSemester->CourseList;
    while (pHeadCourse->Next != nullptr)
        pHeadCourse = pHeadCourse->Next;

    pHeadCourse->Next = new Course;
    pHeadCourse->Next->NameSemester = pHeadSemester -> NameSemester;
    pHeadCourse->Next->Year = pHeadSemester -> Year;
    pHeadCourse->Next->ClassName = ClassName;
    pHeadCourse->Next->CourseId = CourseId;
    pHeadCourse->Next->CourseName = CourseName;
    pHeadCourse->Next->DayOfWeek = DayOfWeek;
    pHeadCourse->Next->MaxStudent = MaxStudent;
    pHeadCourse->Next->Session = Session;
    pHeadCourse->Next->NumberOfCredits = NumberOfCredits;
    pHeadCourse->Next->TeacherName = TeacherName;
    pHeadCourse->Next->Next = nullptr;
    pHeadCourse->Next->CourseStudent = nullptr;
    pHeadCourse->Next->Year = pHeadSemester->Year;
    pHeadCourse->Next->NameSemester = pHeadSemester->NameSemester;
    Add_InfoCourse(pHeadCourse->Next);
    cout << "Add course successfully" << endl;
}