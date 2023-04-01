#include "header.h"
void InputMarkForStudent(Class* headOfClass, SchoolYear* headOfSchoolyear, string input)
{
    ifstream in;
    in.open(input);
    if(!in.is_open()) cout<<"Can not open file "<<input<<endl;

    // Access to ShoolYear current
    SchoolYear* cur;
    string beginYear, endYear;
    getline(in,beginYear, '-');
    getline(in,endYear);
    while(cur && cur->BeginYear != beginYear)
   {
    cur = cur->NextYear;
   }

   // Access Semester Current
   string semester;
   getline(in,semester);
   Semester SemesterCur;

   if(semester[1] == '1')
   SemesterCur = cur->S1;
   else if(semester[1] == '2')
    SemesterCur = cur->S2;
    else SemesterCur = cur->S3;

    // Access Course cur
    string course;
    getline(in,course);
    Course* CourseCur = SemesterCur.CourseList;
    while(CourseCur && CourseCur->ClassName != course)
    {
        CourseCur = CourseCur->Next;
    }

    // Now Access to Student
    string id, name, clss; // clss: class do bi trung ten
    double gpa;
    while(!in.eof())
    {
        getline(in,id,',');
        getline(in,name,',');
        getline(in,clss,',');
        in>>gpa;
        in.ignore(1);

        // Access 
    }

    
    

}