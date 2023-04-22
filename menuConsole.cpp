#include "header.h"
#include "KhoiFunction.h"
#include "functionOfDuy.h"
using namespace std;




    const int MAX_LIST[] = {10, 16, 12};
    const int MAX_STUDENT_LIST = 5;
    int mode = 1;


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
    
// begining of schoolyear->0
// beginning of semester->1
// end of semester->2
string menu[3][16] = {
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
        "Cresate course course.",
        "Upload file student list for course.",
        "View a list of courses.",
        "Update course information. ",
        "Add a student to the course.",
        "Remove a student from the course.",
        "Delete course.",
        "Change the password.",
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

void BeginningYear(int choice){
    switch (choice)
    {
    case 0:
        
        break;
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    case 9:
        
        break;
    default:
        break;
    }
}
void BeginningSemester(int choice)
{
    switch (choice)
    {
    case 0:
        
        break;
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    case 9:
        
        break;
    case 10:
        
        break;
    case 11:
        
        break;
    case 12:
        
        break;
    case 13:
        
        break;
    case 14:
        
        break;
    case 15:
        
        break;
    case 16:
        
        break;
    default:
        break;
    }
}
void EndOfSemester(int choice){
    switch (choice)
    {
    case 0:
        
        break;
    case 1:
        
        break;
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        
        break;
    case 9:
        
        break;
    case 10:
        
        break;
    case 11:
        
        break;
    
    default:
        break;
    }
}
void STAFF_MENU()
{
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
                        BeginningYear(pointer);
                    }
                    if(mode==1){
                        BeginningSemester(pointer);
                    }
                    if(mode==2){
                        EndOfSemester(pointer);
                    }
                }
            }
        }
        if(flag==-1)break;
        
    }
}
void STUDENR_MENU(){
    {
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
                        
                        break;
                    case 1:

                        break;
                    case 2:
                    
                        break;
                    case 3:
                    
                        break;
                    case 4:

                        break;

                    default:
                        break;
                    }
                    break;
                }
            }
        }
        if(flag==-1)break;
        
    }
}
}
