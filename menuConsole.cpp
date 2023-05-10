#include "header.h"
#include "KhoiFunction.h"
#include "functionOfDuy.h"

const int MAX_LIST[] = {11, 14, 12};
const int MAX_STUDENT_LIST = 5;
int mode = 2;

// begining of schoolyear->0
// beginning of semester->1
// end of semester->2
string menu[3][14] = {
    {
        "Create school year.",
        "Create class.",
        "Add student.",
        "Upload file student for class",
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

void BeginningYear(int &flag, int choice, SchoolYear *&Year_head, SchoolYear *&curYear, Account *Student_head,
                   Staff *&Staff_info_head, Account *&User, Semester *&Semester_head, Account *&Staff_head)
{
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
        if (curYear)
            quickInputClass1stYear(curYear);
        else
            cout << "Please create year first.\n";
        break;
    case 4:
        viewClass(Year_head, curYear);
        break;
    case 5:
        viewStudentClass(Year_head);
        break;
    case 6:
        if (Semester_head)
            ViewListOfCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 7:
        if (Semester_head)
            viewStudentsInCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 8:
        PrintProfile_Staff(Staff_head, Staff_info_head);
        break;
    case 9:
    {
        changePassword(User);
        if (User->Role == 1)
            SaveChangePassword(Staff_head);
        else
            SaveChangePassword(Student_head);
        break;
    }
    break;
    case 10:
        flag = -1;
        return;
        break;
    default:
        break;
    }
    cout << "\nPress any key to exit!!!\n";
    getch();
}
void BeginningSemester(int &flag, int choice, SchoolYear *&Year_head, SchoolYear *&curYear, Account *Student_head,
                       Staff *&Staff_info_head, Account *&User, Semester *&Semester_head, Account *&Staff_head)
{
    switch (choice)
    {
    case 0:
        Semester_head = AddNewSemester(curYear);
        break;
    case 1:
        if (Semester_head)
            AddCourse(Semester_head);
        else
            cout << "Please create semester and course.\n";

        break;
    case 2:
        if (Semester_head)
            InputCSV_Course(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";

        break;
    case 3:
        if (Semester_head)
            UpdCourseInf(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";

        break;
    case 4:
        if (Semester_head)
            AddStudentToCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";

        break;
    case 5:
        if (Semester_head)
            RmStudentFrCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";

        break;
    case 6:
        if (Semester_head)
            DeleteCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 7:
        viewClass(Year_head,curYear);
        break;
    case 8:
        viewStudentClass(Year_head);
        break;
    case 9:
        if (Semester_head)
            ViewListOfCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 10:
        if (Semester_head)
            viewStudentsInCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 11:
        PrintProfile_Staff(Staff_head, Staff_info_head);
        break;
    case 12:
    {
        changePassword(User);
        if (User->Role == 1)
            SaveChangePassword(Staff_head);
        else
            SaveChangePassword(Student_head);
        break;
    }
    break;
    case 13:
        flag = -1;
        return;
        break;

    default:
        break;
    }
    cout << "\nPress any key to exit!!!\n";
    getch();
}
void EndOfSemester(int &flag, int choice, SchoolYear *&Year_head, SchoolYear *&curYear, Account *Student_head,
                   Staff *&Staff_info_head, Account *&User, Semester *&Semester_head, Account *&Staff_head)
{
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
        if (Semester_head)
            viewCourseScoreboard(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 3:
        if (Semester_head)
            UpdateStudentResult(Semester_head);
        else
            cout << "Please create semester and course.\n";
        break;
    case 4:
        if (Semester_head)
            viewClassScoreboard(Year_head, Semester_head, curYear);
        else
            cout << "Please create semester and course.\n";
        break;
    case 5:
        viewClass(Year_head,curYear);
        break;
    case 6:
        viewStudentClass(Year_head);
        break;
    case 7:
        if (Semester_head)
            ViewListOfCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 8:
        if (Semester_head)
            viewStudentsInCourse(Semester_head->CourseList);
        else
            cout << "Please create semester and course.\n";
        break;
    case 9:
        PrintProfile_Staff(Staff_head, Staff_info_head);
        break;
    case 10:
    {
        changePassword(User);
        if (User->Role == 1)
            SaveChangePassword(Staff_head);
        else
            SaveChangePassword(Student_head);
        break;
    }
    break;
    case 11:
        flag = -1;
        return;
        break;

    default:
        break;
    }
    cout << "\nPress any key to exit!!!\n";
    getch();
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

    User = Login(Staff_head);

    curYear = Year_head;
    while (curYear->NextYear != nullptr)
        curYear = curYear->NextYear;
    Semester_head = defaultSemester(curYear);
    SchoolYear *tmp = Year_head;
    while (tmp) {
        CalGpa(tmp->ClassHead);
        if (tmp->S1)
            calGPASemester(tmp->ClassHead, tmp->S1);
        if (tmp->S2)
            calGPASemester(tmp->ClassHead, tmp->S2);
        if (tmp->S3)
            calGPASemester(tmp->ClassHead, tmp->S3);
        tmp = tmp->NextYear;
    }

    int pointer = 0;
    int flag = 0;

    while (true)
    {
        system("cls");
        cout << "============================MENU==========================\n";
        for (int i = 0; i < MAX_LIST[mode]; i++)
        {
            if (pointer == i)
            {
                TextColor(1);
                cout << ">> " << menu[mode][i] << " <<" << endl;
                TextColor(7);
            }
            else
            {
                cout << "[+]" << menu[mode][i] << endl;
            }
        }
        cout << "===========================END===========================\n";
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
                    if (mode == 0)
                    {
                        BeginningYear(flag, pointer, Year_head, curYear, Student_head, Staff_info_head, User, Semester_head, Staff_head);
                    }
                    if (mode == 1)
                    {
                        BeginningSemester(flag, pointer, Year_head, curYear, Student_head, Staff_info_head, User, Semester_head, Staff_head);
                    }
                    if (mode == 2)
                    {
                        EndOfSemester(flag, pointer, Year_head, curYear, Student_head, Staff_info_head, User, Semester_head, Staff_head);
                    }
                    break;
                }
            }
        }

        if (flag == -1)
        {
            deleteAllLists(Year_head, Student_head, Staff_head,Staff_info_head);
            return;
            break;
        }
    }
}
void STUDENT_MENU()
{
    {

        Account *Student_head = nullptr;
        Account *Staff_head = nullptr;
        Account *User;
        Semester *curSmeter = nullptr, *Semester_head = nullptr;
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
        SchoolYear *tmp = Year_head;
        while (tmp) {
            CalGpa(tmp->ClassHead);
            if (tmp->S1)
                calGPASemester(tmp->ClassHead, tmp->S1);
            if (tmp->S2)
                calGPASemester(tmp->ClassHead, tmp->S2);
            if (tmp->S3)
                calGPASemester(tmp->ClassHead, tmp->S3);
            tmp = tmp->NextYear;
        }

        int pointer = 0;
        int flag = 0;

        while (true)
        {
            system("cls");
            cout << "============MENU===========\n";
            for (int i = 0; i < MAX_STUDENT_LIST; i++)
            {
                if (pointer == i)
                {
                    TextColor(1);
                    cout << ">> " << StudentMenu[i] << " <<" << endl;
                    TextColor(7);
                }
                else
                {
                    cout << "[+]" << StudentMenu[i] << endl;
                }
            }
            cout << "=============END===========\n";
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
                        {
                            changePassword(User);
                            if (User->Role == 1)
                                SaveChangePassword(Staff_head);
                            else
                                SaveChangePassword(Student_head);
                            break;
                        }
                        break;
                        case 3:
                            PrintProfile_Student(User, Year_head);
                            break;
                        case 4:
                            deleteAllLists(Year_head, Student_head, Staff_head, Staff_info_head);
                            return;
                            break;

                        default:
                            break;
                        }

                        cout << "\nPress any key to exit!!!\n";
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
    "Exit"};
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