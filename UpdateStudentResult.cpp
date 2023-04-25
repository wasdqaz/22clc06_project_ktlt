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

                cout << "Do you want to update?\n";
                cout << "0. Exit\n";
                cout << "1. Update\n";

                int choice;
                cin >> choice;
                if (choice == 0)
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
                // ban co muon sua hay khong(tao bien roi gan);
                // while(true){
                //     int choice;
                //     cout<<"The mark you want to upp date ?\n";
                //     cout<<"1. Midterm Mark\n";
                //     cout<<"2. Final Mark\n";
                //     cout<<"3. Total Mark\n";
                //     cout<<"4. Other Mark\n";
                //     cout<<"5. All.\n";
                //     cout<<"0. Exit\n";
                //     cin>>choice;
                // }
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


