#include "header.h"
#include "KhoiFunction.h"
#include "functionOfDuy.h"




    const int MAX_LIST[] = {10, 14, 12};
    const int MAX_STUDENT_LIST = 5;
    int mode = 1;

    
    
// begining of schoolyear->0
// beginning of semester->1
// end of semester->2
string menu[3][14] = {
    {
        "Create school year.",
        "Create class.",
        "Add student.",
        "View a list of classes.",
        "View a list of students in a class.",
        "View a list of courses.",
        "View a list of students in a course.",
        "View profile.",
        "Change the password.",
        "Logout.",
    },
    {
        "Create semester.",
        "Create course.",
        "Upload file student list for course.",
        "Update course information. ",
        "Add a student to the course.",
        "Remove a student from the course.",
        "Delete course.",
        "View a list of classes.",
        "View a list of students in a class.",
        "View a list of courses.",
        "View a list of students in a course.",
        "View profile.",
        "Change the password.",
        "Logout.",
    },
    {
        "Export a list of students in a course to a CSV file.",
        "Import the scoreboard of a course.",
        "View the scoreboard of a course.",
        "Update a student's result.",
        "View the scoreboard of a class.",
        "View a list of classes.",
        "View a list of students in a class.",
        "View a list of courses.",
        "View a list of students in a course.",
        "View profile.",
        "Change the password.",
        "Logout.",

    }};

string StudentMenu[] = {
    "View list of course.",
    "View scoreboard.",
    "Change password.",
    "View profile.",
    "Logout.",
};



void TextColor(int x) // X là mã màu
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

void BeginningYear(int &flag, int choice, SchoolYear *&Year_head, SchoolYear *&curYear,
 Staff *&Staff_info_head, Account *&User, Semester *&Semester_head, Account *&Staff_head){
    switch (choice)
    {
    case 0:
        AddNewYear(curYear);
        break;
    case 1:
        CreateClass(curYear);
        break;
    case 2:
        AddNewStudent(Year_head);
        break;
    case 3:
        viewClass(Year_head);
        break;
    case 4:
        viewStudentClass(Year_head);
        break;
    case 5:
        ViewListOfCourse(Semester_head->CourseList);
        break;
    case 6:
        viewStudentsInCourse(Semester_head->CourseList);
        break;
    case 7:
        PrintProfile_Staff(Staff_head, Staff_info_head);    
        break;
    case 8:
        changePassword(User);
        break;
    case 9:
        flag=-1;
        return;
        break;
    default:
        break;
    }
}
void BeginningSemester(int &flag, int choice, SchoolYear *&Year_head, SchoolYear *&curYear,
 Staff *&Staff_info_head, Account *&User, Semester *&Semester_head, Account *&Staff_head)
{
    switch (choice)
    {
    case 0:
        Semester_head = AddNewSemester(curYear);
        break;
    case 1:
        AddCourse(Semester_head);
        break;
    case 2:
        InputCSV_Course(Semester_head->CourseList);
        break;
    case 3:
        UpdCourseInf(Semester_head->CourseList);
        break;
    case 4:
        AddStudentToCourse(Semester_head->CourseList);
        break;
    case 5:
        RmStudentFrCourse(Semester_head->CourseList);
        break;
    case 6:
        DeleteCourse(Semester_head->CourseList);
        break;
    case 7:
        viewClass(Year_head);
        break;
    case 8:
        viewStudentClass(Year_head);
        break;
    case 9:
        ViewListOfCourse(Semester_head->CourseList);
        break;
    case 10:
        viewStudentsInCourse(Semester_head->CourseList);
        break;
    case 11:
        PrintProfile_Staff(Staff_head, Staff_info_head);
        break;
    case 12:
        changePassword(User);
        break;
    case 13:
        flag=-1;
        return;
        break;
    
    default:
        break;
    }
    cout<<"\nPress any key to exit!!!\n";
    getch();
}
void EndOfSemester(int &flag, int choice, SchoolYear *&Year_head, SchoolYear *&curYear,
 Staff *&Staff_info_head, Account *&User, Semester *&Semester_head, Account *&Staff_head){
    switch (choice)
    {
    case 0:
        ExportCourseToCSVFile(Year_head, "");
        break;
    case 1:
        {
            string filepath = ImportScoreboardFromFileUser(Year_head);
            SaveScorboardToFolderSchoolyear(filepath);
            break;
        }
        break;
    case 2:
        viewCourseScoreboard(Semester_head->CourseList);
        break;
    case 3:
        UpdateStudentResult(Semester_head->CourseList);
        break;
    case 4:
        viewClassScoreboard(Year_head->ClassHead, Semester_head, curYear);
        break;
    case 5:
        viewClass(Year_head);
        break;
    case 6:
        viewStudentClass(Year_head);
        break;
    case 7:
        ViewListOfCourse(Semester_head->CourseList);
        break;
    case 8:
        viewStudentsInCourse(Semester_head->CourseList);
        break;
    case 9:
        PrintProfile_Staff(Staff_head, Staff_info_head);
        break;
    case 10:
        changePassword(User);
        break;
    case 11:
        flag=-1;
        return;
        break;
    
    default:
        break;
    }
}
void STAFF_MENU()
{   
    Account *Student_head = nullptr;
    Account *Staff_head = nullptr;
    Account *User;
    Semester *curSmeter = nullptr, *Semester_head;
    SchoolYear *Year_head = nullptr;
    Staff *Staff_info_head = nullptr;
    int Role;
    
    createAccountList(Student_head, 2);
    createAccountList(Staff_head, 1);

    string directoryPath = "Data/SchoolYear";
    Course *curCourse = nullptr;
    Class *curClass = nullptr;
    SchoolYear *curYear = nullptr;
    ReadDirectory(directoryPath, curSmeter, curCourse, curClass, Year_head, curYear);
    AccessFileMark(directoryPath, Year_head);
    readStaffInfo(Staff_info_head);
    
    User= Login(Staff_head);

    curYear = Year_head;
    while (curYear->NextYear != nullptr)
        curYear = curYear->NextYear;
    Semester_head = defaultSemester(curYear);
    CalGpa(Year_head->ClassHead);
    calGPASemester(Year_head->ClassHead, Semester_head);



    int pointer = 0;
    int flag = 0;


    while (true)
    {   
        system("cls");
        cout<<"============================MENU==========================\n";
        for (int i = 0; i < MAX_LIST[mode]; i++)
        {
            if (pointer == i)
            {   
                TextColor(1);
                cout << ">> " << menu[mode][i] <<" <<"<< endl;
                TextColor(7);
            }
            else
            {
                cout << "[+]" << menu[mode][i] << endl;
            }
        }
        cout<<"===========================END===========================\n";
        while (true)
        {
            if (kbhit())
            {
                char key = getch();
                if (key == 80)
                {
                    if (pointer < MAX_LIST[mode] - 1)
                        ++pointer;
                    else
                        pointer = 0;
                    break;
                }
                if (key == 72)
                {
                    if (pointer > 0)
                        --pointer;
                    else
                        pointer = MAX_LIST[mode] - 1;
                    break;
                }
                if (key == 13)
                {
                    if(mode==0){
                        BeginningYear(flag,pointer,Year_head,curYear,Staff_info_head,User,Semester_head,Staff_head);
                       
                    }
                    if(mode==1){
                        BeginningSemester(flag,pointer,Year_head,curYear,Staff_info_head,User,Semester_head,Staff_head);
                        
                    }
                    if(mode==2){
                        EndOfSemester(flag,pointer,Year_head,curYear,Staff_info_head,User,Semester_head,Staff_head);
                        
                    }
                    break;
                }
            }
        }
        
        if(flag==-1){
            deleteAllLists(Year_head, Student_head, Staff_head);
            return;
            break;
        } 
    }
}
void STUDENR_MENU(){
    {
    
    Account *Student_head = nullptr;
    Account *Staff_head = nullptr;
    Account *User;
    Semester *curSmeter = nullptr, *Semester_head=nullptr;
    SchoolYear *Year_head = nullptr;
    Staff *Staff_info_head = nullptr;
    int Role;

    createAccountList(Student_head, 2);
    createAccountList(Staff_head, 1);

    string directoryPath = "Data/SchoolYear";
    Course *curCourse = nullptr;
    Class *curClass = nullptr;
    SchoolYear *curYear = nullptr;
    ReadDirectory(directoryPath, curSmeter, curCourse, curClass, Year_head, curYear);
    AccessFileMark(directoryPath, Year_head);
    readStaffInfo(Staff_info_head);

    User = Login(Student_head);
    string clss = User->Class;

    curYear = Year_head;
    while (curYear->NextYear != nullptr)
        curYear = curYear->NextYear;
    Semester_head = defaultSemester(curYear);
    CalGpa(Year_head->ClassHead);
    calGPASemester(Year_head->ClassHead, Semester_head);

    int pointer = 0;
    int flag = 0;


    while (true)
    {   
        system("cls");
        cout<<"============MENU===========\n";
        for (int i = 0; i < MAX_STUDENT_LIST; i++)
        {
            if (pointer == i)
            {   
                TextColor(1);
                cout << ">> " << StudentMenu[i] <<" <<"<< endl;
                TextColor(7);
            }
            else
            {
                cout << "[+]" << StudentMenu[i] << endl;
            }
        }
        cout<<"=============END===========\n";
        while (true)
        {
            if (kbhit())
            {
                char key = getch();
                if (key == 80)
                {
                    if (pointer < MAX_STUDENT_LIST - 1)
                        ++pointer;
                    else
                        pointer = 0;
                    break;
                }
                if (key == 72)
                {
                    if (pointer > 0)
                        --pointer;
                    else
                        pointer = MAX_STUDENT_LIST - 1;
                    break;
                }
                if (key == 13)
                {
                    switch (pointer)
                    {
                    case 0:
                        viewListOfCourses_Student(Semester_head, Student_head);
                        break;
                    case 1:
                        ViewScoreBoardStudent(Year_head, User);
                        break;
                    case 2:
                        changePassword(User);
                        break;
                    case 3:
                        PrintProfile_Student(User, Year_head);
                        break;
                    case 4:
                        deleteAllLists(Year_head, Student_head, Staff_head);
                        return;
                        break;

                    default:
                        break;
                    }

                    cout<<"\nPress any key to exit!!!\n";
                    getch();
                    break;
                }
            }
        }
    }
}
}



string Login_Menu[] = {
    "Staff.",
    "Student.",
    "Exit"
    };
const int MAX_LOGIN = 3;

int LoginConsole()
{
    int pointer = 0;
    while (true)
    {   
        system("cls");
        cout << "You are student or staff.\n";
        for (int i = 0; i < MAX_LOGIN; i++)
        {
            if (pointer == i)
            {
                TextColor(1);
                cout << ">> " << Login_Menu[i] << " <<" << endl;
                TextColor(7);
            }
            else
                cout << "[+]" << Login_Menu[i] << endl;
        }
        while (true)
        {
            if (kbhit())
            {
                char key = getch();
                if (key == 80)
                {
                    if (pointer < MAX_LOGIN - 1)
                        ++pointer;
                    else
                        pointer = 0;
                    break;
                }
                if (key == 72)
                {
                    if (pointer > 0)
                        --pointer;
                    else
                        pointer = MAX_LOGIN - 1;
                    break;
                }
                if (key == 13)
                {
                    switch (pointer)
                    {
                    case 0:
                        return 1;
                        break;
                    case 1:
                        return 2;
                        break;
                    case 2:
                        return 0;
                        break;

                    default:
                        break;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}