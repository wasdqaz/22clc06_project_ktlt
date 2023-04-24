#include "functionOfDuy.h"
#include "header.h"

void viewStudentsInCourse(Course *pHead)
{
    string CourseId, ClassName;
    cout << "Enter the course ID to view its student list: ";
    cin >> CourseId;
    cout << "Enter the class name of the course: ";
    cin >> ClassName;

    Course *temp = pHead;
    while (temp != nullptr && temp->CourseId != CourseId && temp->ClassName == ClassName)
        temp = temp->Next;
    if (temp == nullptr)
    {
        cout << "No course found!!!" << endl;
        return;
    }
    Student *Temp = temp->CourseStudent;
    if (Temp == nullptr)
    {
        cout << "No student in the course!!!" << endl;
        return;
    }
    int i = 1;
    cout << "-----------------------------------------------" << endl;
    cout << setw(5) << left << "No";
    cout << setw(15) << left << "Student ID";
    cout << setw(40) << left << "Name" << endl;
    while (Temp != nullptr)
    {
        cout << setw(5) << left << i++;
        cout << setw(15) << left << Temp->Id;
        cout << setw(40) << left << Temp->Name << endl;
        Temp = Temp->Next;
    }
    cout << "-----------------------------------------------" << endl;
}

void viewCourseScoreboard(Course *pHead)
{
    string CourseId, ClassName;
    cout << "Enter the course ID to view the score: ";
    cin >> CourseId;
    cout << "Enter the class name of the course: ";
    cin >> ClassName;

    Course *temp = pHead;
    while (temp != nullptr && temp->CourseId != CourseId && temp->ClassName == ClassName)
        temp = temp->Next;
    if (temp == nullptr)
    {
        cout << "No course found!!!" << endl;
        return;
    }
    Student *Temp = temp->CourseStudent;
    if (Temp == nullptr)
    {
        cout << "No student in the course!!!" << endl;
        return;
    }
    int i = 1;
    cout << endl << setw(5) << left << "No";
    cout << setw(15) << left << "Student ID";
    cout << setw(35) << left << "Name";
    cout << setw(15) << left << "Midterm Mark";
    cout << setw(15) << left << "Total Mark";
    cout << setw(15) << left << "Other Mark";
    cout << setw(15) << left << "Final Mark" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    while (Temp != nullptr)
    {
        cout << setw(5) << left << i++;
        cout << setw(15) << left << Temp->Id;
        cout << setw(35) << left << Temp->Name;
        cout << setw(15) << left << Temp->HeadOfMark->MidtermMark;
        cout << setw(15) << left << Temp->HeadOfMark->TotalMark;
        cout << setw(15) << left << Temp->HeadOfMark->OtherMark;
        cout << setw(15) << left << Temp->HeadOfMark->FinalMark << endl;
        Temp = Temp->Next;
    }
}