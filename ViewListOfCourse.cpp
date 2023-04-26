#include "header.h"
#include "KhoiFunction.h"

void ViewListOfCourse(Course *head)
{   
    if(head==nullptr){
        cout<<"Can't find course.\n";
        return;
    }
    Course *cur = head;
    cout << "+---------------------+---------------------------------------------------------------------------+\n";
    cout << setw(2) << left << "|" << left << setw(20) << "Course ID"
         << setw(2) << left << "|" << left << setw(30) << "Course name"
         << setw(2) << left << "|" << left << setw(20) << "Class name"
         << setw(2) << left << "|" << left << setw(20) << "Teacher name" << "|";
    cout << endl;
    cout << "+---------------------+---------------------------------------------------------------------------+\n";
    while (cur)
    {
        cout << setw(2) << left << "|" << left << setw(20) << cur->CourseId << setw(2) << left << "|"
             << left << setw(30) << cur->CourseName << setw(2) << left << "|"
             << left << setw(20) << cur->ClassName << setw(2) << left << "|"
             << left << setw(20) << cur->TeacherName << "|" << "\n";
        cur = cur->Next;
    }
    cout << "+---------------------+---------------------------------------------------------------------------+\n";
}
