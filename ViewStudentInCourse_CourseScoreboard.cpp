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
    if (Temp == nullptr) {
        cout << "No student in the course!!!" << endl;
        return;
    }
    int i = 1;
    cout << "-----------" << endl;
    while (Temp != nullptr) {
        cout << i++ << ". " << Temp->Name << endl;
        Temp = Temp->Next;
    }
    cout << "-----------" << endl;
}

void viewCourseScoreboard(Course *pHead)
{
    cout << "Enter the course ID to view the score: ";
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
    if (Temp == nullptr) {
        cout << "No student in the course!!!" << endl;
        return;
    }
    cout << endl << setw(35) << left << "Name";
    cout << setw(15) << left << "Midterm Mark";
    cout << setw(15) << left << "Total Mark";
    cout << setw(15) << left << "Other Mark";
    cout << setw(15) << left << "Final Mark" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    while (Temp != nullptr) {
        cout << setw(35) << left << Temp->Name;
        cout << setw(15) << left << Temp->HeadOfMark->MidtermMark;
        cout << setw(15) << left << Temp->HeadOfMark->TotalMark;
        cout << setw(15) << left << Temp->HeadOfMark->OtherMark;
        cout << setw(15) << left << Temp->HeadOfMark->FinalMark << endl;
        Temp = Temp->Next;
    }
}