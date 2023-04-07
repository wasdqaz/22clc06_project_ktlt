#include "functionOfDuy.h"
#include "header.h"

void viewStudentsInCourse(Course *pHead)
{
    cout << "Enter the course ID to view its student list: ";
    string CourseId;
    cin >> CourseId;
    Course *temp = pHead;
    while (temp != nullptr && temp->CourseId != CourseId)
        temp = temp->Next;
    if (temp == nullptr) {
        cout << "No course found!!!" << endl;
        return;
    }
    Student *Temp = temp->CourseStudent;
    int i = 1;
    cout << "-----------" << endl;
    while (Temp != nullptr) {
        cout << i++ << ". " << Temp->Name << endl;
        Temp = Temp->Next;
    }
    cout << "-----------" << endl;
}