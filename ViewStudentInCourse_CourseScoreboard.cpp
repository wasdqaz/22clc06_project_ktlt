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
    cout << "+------+----------------+-----------------------------------------+" << endl;
    cout << setw(2) << left << "|" << setw(5) << left << "No";
    cout << setw(2) << left << "|" << setw(15) << left << "Student ID";
    cout << setw(2) << left << "|" << setw(40) << left << "Name" << "|" << endl;
    cout << "+------+----------------+-----------------------------------------+" << endl;
    while (Temp != nullptr)
    {
        cout << setw(2) << left << "|" << setw(5) << left << i++;
        cout << setw(2) << left << "|" << setw(15) << left << Temp->Id;
        cout << setw(2) << left << "|" << setw(40) << left << Temp->Name << "|" << endl;
        Temp = Temp->Next;
    }
    cout << "+------+----------------+-----------------------------------------+" << endl;
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
    cout << "+-----+----------------+-------------------------------+--------------+------------+------------+------------+" << endl;
    cout << setw(2) << left << "|" << setw(4) << left << "No";
    cout << setw(2) << left << "|" << setw(15) << left << "Student ID";
    cout << setw(2) << left << "|" << setw(30) << left << "Name";
    cout << setw(2) << left << "|" << setw(13) << left << "Midterm Mark";
    cout << setw(2) << left << "|" << setw(11) << left << "Total Mark";
    cout << setw(2) << left << "|" << setw(11) << left << "Other Mark";
    cout << setw(2) << left << "|" << setw(11) << left << "Final Mark" << "|" << endl;
    cout << "+-----+----------------+-------------------------------+--------------+------------+------------+------------+" << endl;
    while (Temp != nullptr)
    {
        cout << setw(2) << left << "|" << setw(4) << left << i++;
        cout << setw(2) << left << "|" << setw(15) << left << Temp->Id;
        cout << setw(2) << left << "|" << setw(30) << left << Temp->Name;
        cout << setw(2) << left << "|" << setw(13) << left << Temp->HeadOfMark->MidtermMark;
        cout << setw(2) << left << "|" << setw(11) << left << Temp->HeadOfMark->TotalMark;
        cout << setw(2) << left << "|" << setw(11) << left << Temp->HeadOfMark->OtherMark;
        cout << setw(2) << left << "|" << setw(11) << left << Temp->HeadOfMark->FinalMark << "|" << endl;
        Temp = Temp->Next;
    }
    cout << "+-----+----------------+-------------------------------+--------------+------------+------------+------------+" << endl;
}