#include "header.h"
#include "KhoiFunction.h"
void ViewListOfCourse(Course *head){
    Course *cur=head;
    cout<<"----------------------------------------------------------------------------------------\n";
    cout<<left<<setw(20)<<"Course Id"
        <<left<<setw(30)<<"course name"
        <<left<<setw(20)<<"Class name"
        <<left<<setw(20)<<"Teacher name";
    cout<<endl;
    cout<<"----------------------------------------------------------------------------------------\n";
    while(cur){
        cout<<left<<setw(20)<<cur->CourseId<<""
            <<left<<setw(30)<<cur->CourseName<<""
            <<left<<setw(20)<<cur->ClassName<<""
            <<left<<setw(20)<<cur->TeacherName<<"\n";
        cur=cur->Next;
    }
    cout<<"----------------------------------------------------------------------------------------\n";

}
