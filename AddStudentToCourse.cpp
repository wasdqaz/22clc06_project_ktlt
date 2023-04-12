#include"header.h"
#include"KhoiFunction.h"


void AddStudentToCourse(Course *CourseHead){
    string CourseID;
    cout<<"Please input course id: \n";
    cin>>CourseID;
    
    while(CourseHead->CourseId!=CourseID){
        CourseHead=CourseHead->Next;
    }
    Student *cur=new Student;
    cur->Next=CourseHead->CourseStudent;
    CourseHead->CourseStudent=cur;
    cout<<"Enter name of student: ";
    cin.ignore();
    getline(cin, cur->Name);
    cout<<"Enter student ID: ";
    cin>>cur->Id;
}
