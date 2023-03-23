#include "header.h"
#include "KhoiFunction.h"
void ViewListOfCourse(Course *head){
    Course *cur=head;
    cout<<left<<setw(20)<<"Course Id"
        <<left<<setw(20)<<"course name"
        <<left<<setw(20)<<"Class name"
        <<left<<setw(20)<<"Teacher name";
    cout<<endl;
    cout<<"------------------------------------------------------------------------\n";
    while(cur){
        cout<<left<<setw(20)<<cur->CourseId<<" "
            <<left<<setw(20)<<cur->CourseName<<" "
            <<left<<setw(20)<<cur->ClassName<<" "
            <<left<<setw(20)<<cur->TeacherName<<" \n";
        cur=cur->Next;
    }
}
// int main(){
//     Course *head=new Course;
//     head->CourseName="text name";
//     head->CourseId="csc123";
//     head->ClassName="clc0";
//     head->TeacherName="test";
//     Course *cur=head;
//     head->Next=new Course;
//     head=head->Next;
//     head->CourseName="text name";
//     head->CourseId="csc123";
//     head->ClassName="clc0";
//     head->TeacherName="test";
    
//     ViewListOfCourse(cur);
//     return 0;
// }