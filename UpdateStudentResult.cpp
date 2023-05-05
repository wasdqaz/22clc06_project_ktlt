#include "header.h"
#include "KhoiFunction.h"
bool FindCourse(Course *head, string Course_Id, Course *&tmp)
{
    Course *cur_course = head;
    while (cur_course)
    {
        if (cur_course->CourseId == Course_Id)
        {
            tmp = cur_course;
            return true;
        }
        cur_course = cur_course->Next;
    }
    return false;
}
bool FindStudent(Student *&head, string Student_id)
{
    Student *Cur = head;
    while (Cur)
    {
        if (Cur->Id == Student_id)
        {
            head = Cur;
            return true;
        }
        Cur = Cur->Next;
    }
    return false;
}



void UpdateStudentResult(Semester* Semester_head)
{
    Course* head = Semester_head->CourseList;
    string Course_Id, Student_id;
    Course *cur_course;
    while (true)
    {
        cout << "Please enter course ID: ";
        cin >> Course_Id;
        if (FindCourse(head, Course_Id, cur_course))
        {
            cout << "Please enter student ID: ";
            cin >> Student_id;
            Student *Student_head = head->CourseStudent;
            if (FindStudent(Student_head, Student_id))
            {
                cout << left << setw(15) << "ID"
                     << left << setw(30) << "Name"
                     << left << setw(15) << "Midterm Mark"
                     << left << setw(15) << "Final Mark"
                     << left << setw(15) << "Total mark"
                     << left << setw(15) << "Other Mark";
                cout << endl;

                cout << left << setw(15) << Student_head->Id;
                cout << left << setw(30) << Student_head->Name;
                cout << left << setw(15) << Student_head->HeadOfMark->MidtermMark;
                cout << left << setw(15) << Student_head->HeadOfMark->FinalMark;
                cout << left << setw(15) << Student_head->HeadOfMark->TotalMark;
                cout << left << setw(15) << Student_head->HeadOfMark->OtherMark;
                cout << endl;
                cout<<"Press any key to continue.\n";
                getch();
                int choice = MenuYN("Do you want to update?");
                if (choice == 2)
                    return;

                cout << "Midterm Mark: ";
                cin >> Student_head->HeadOfMark->MidtermMark;
                cout << "Final Mark: ";
                cin >> Student_head->HeadOfMark->FinalMark;
                cout << "Total Mark: ";
                cin >> Student_head->HeadOfMark->TotalMark;
                cout << "Other Mark: ";
                cin >> Student_head->HeadOfMark->OtherMark;
                cout << "Update result successfully!!!\n";
                SaveWhenUpdateStudentResult(Semester_head, cur_course);
                return;
            }
            else
            {
                cout << "Can't find student.\n";
                cout << "PLEASE RE-ENTER.\n";
            }
        }
        else
        {
            cout << "Can't find course id.\n";
            cout << "PLEASE RE-ENTER.\n";
        }
    }
}


