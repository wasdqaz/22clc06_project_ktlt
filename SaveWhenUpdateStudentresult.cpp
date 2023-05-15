#include "header.h"
#include "KhoiFunction.h"
void SaveWhenUpdateStudentResult(Semester* cur, Course* Course_cur)
{
    string year = cur->Year ;
    string coursename = Course_cur->CourseName;
    string courseId = Course_cur->CourseId;
    string classname = Course_cur->ClassName;
    
    string filename = "mark_" + classname + "_"+ courseId + ".txt";
    string filepath = "Data/SchoolYear/" + year +"/"+ cur->NameSemester + "/" + coursename + "/" + filename;
    ofstream out;
    out.open(filepath);
    if(!out.is_open()) cout<<"Can not open file\n";
    out<<year<<endl;
    if(cur->NameSemester[9] == '1')
    {
        out<<"S1\n";
    }
    else if(cur->NameSemester[9] == '2')
    {
        out<<"S2\n";
    }
    else out<<"S3\n";
    out<<courseId<<endl;
    out<<coursename<<endl;
    out<<classname<<endl;
    out<<"No,ID,Name,Class,Midterm,Final,Other Mark,Total\n";
    Student* head = Course_cur->CourseStudent;
    while(head &&head->Next)
    {
        out<<head->No<<","<<head->Id<<","<<head->Name<<","<<head->Class<<","<<head->HeadOfMark->MidtermMark<<" "<<head->HeadOfMark->FinalMark<< " " <<head->HeadOfMark->OtherMark<<" "<<head->HeadOfMark->TotalMark<<endl;
        head = head->Next;
    }
    out<<head->No<<","<<head->Id<<","<<head->Name<<","<<head->Class<<","<<head->HeadOfMark->MidtermMark<<" "<<head->HeadOfMark->FinalMark<< " " <<head->HeadOfMark->OtherMark<<" "<<head->HeadOfMark->TotalMark;




}