#include "header.h"
#include "KhoiFunction.h"

bool FindClass(Class *&head, string ClassName)
{
    Class *Cur_Class = head;
    while (Cur_Class)
    {
        if (Cur_Class->Name == ClassName)
        {
            head = Cur_Class;
            return true;
        }
        Cur_Class = Cur_Class->Next;
    }
    return false;
}
void PrintMark(Mark *head, string S_name)
{
    while (head)
    {
        if (head->semester == S_name)
        {   
            cout << setw(2) << left << "|" << left << setw(40) << head->NameOfCourse;
            cout << setw(2) << left << "|" << left << setw(11) << head->Id;
            cout << setw(2) << left << "|" << left << setw(13) << head->MidtermMark;
            cout << setw(2) << left << "|" << left << setw(11) << head->FinalMark;
            cout << setw(2) << left << "|" << left << setw(11) << head->TotalMark;
            cout << setw(2) << left << "|" << left << setw(11) << head->OtherMark << "|";
            cout<<endl;
        }
        head=head->Next;
    }
}
void ViewScoreBoardStudent(SchoolYear *head, Account *User)
{
    Class *Cur_Class = head->ClassHead;
    if (FindClass(Cur_Class, User->Class))
    {
        Student *Cur_Student = Cur_Class->StudentHead;
        if (FindStudent(Cur_Student, User->username))
        {

            cout << "ID: " << Cur_Student->Id << endl;
            cout << "Name: " << Cur_Student->Name << endl;
            while (true)
            {
                string choice;
                cout << "Semester 1: S1\n";
                cout << "Semester 2: S2\n";
                cout << "Semester 3: S3\n";
                cout << "0. Exit\n";
                cout << "Please enter S1 or S2 or S3 to choose semester.\n";
                cin >> choice;
                if (choice == "0")
                    return;
                if (choice == "S1" || choice == "S2" || choice == "S3")
                {
                    cout << "+-----------------------------------------+------------+--------------+------------+------------+------------+" << endl;
                    cout << setw(2) << left << "|" << left << setw(40) << "Course name"
                         << setw(2) << left << "|" << left << setw(11) << "Course ID"
                         << setw(2) << left << "|" << left << setw(13) << "Midterm Mark"
                         << setw(2) << left << "|" << left << setw(11) << "Final Mark"
                         << setw(2) << left << "|" << left << setw(11) << "Total mark"
                         << setw(2) << left << "|" << left << setw(11) << "Other Mark" << "|";
                    cout << endl;
                    cout << "+-----------------------------------------+------------+--------------+------------+------------+------------+" << endl;
                    PrintMark(Cur_Student->HeadOfMark, choice);
                    cout << "+-----------------------------------------+------------+--------------+------------+------------+------------+" << endl;
                    return;
                }
            }
        }
    }
}
