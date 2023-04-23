#include "header.h"

Mark* makeMarkNode (double midterm, double final, double othermark, double total, string courseid,string coursename, string semester, string year)
{
    Mark* newMark = new Mark;
    newMark->Id = courseid;
    newMark->NameOfCourse = coursename;
    newMark->FinalMark = final;
    newMark->MidtermMark = midterm;
    newMark->TotalMark = total;
    newMark->OtherMark = othermark;
    newMark->semester = semester;
    newMark->year = year;
    newMark->Next = nullptr;
    newMark->Prev = nullptr;
    return newMark;
    
}


void putMarkToStudentNode (Student* studentOfClass, Student* studentOfCourse, double midterm, double final,double othermark, double total, string courseid, string coursename,string semester, string year)
{
    // push Node Mark to Student of class
    Mark* head =studentOfClass ->HeadOfMark;
    Mark* newMark =  makeMarkNode(midterm, final, othermark, total, courseid, coursename, semester,year);
    if(!head)
    {
        studentOfClass->HeadOfMark = newMark;
        //return
    }
    else
    {
        while(head->Next)
        head = head->Next;
        newMark->Prev = head;
        head->Next = newMark;
    }
    // push node mark to student of course
    studentOfCourse->HeadOfMark = newMark;
}
Student* FindNodeStudentOfCourseToPutMark (string id, Course* cur)
{
    Student* head = cur->CourseStudent;
    while(head)
    {
        if(head->Id == id)
            return head;
            head = head->Next;
    }
    return nullptr;

}
Student* FindNodeStudentOfClassToPutMark (string id, SchoolYear* headOfschoolyear, string clss)
{
    SchoolYear* curYear = headOfschoolyear;
    string beginYear = clss.substr(0,2);
    while(curYear)
    {
        if(curYear->BeginYear == beginYear) break;
        curYear = curYear->NextYear;
    }
    if(!curYear)
    {
        cout<<"Not found student "<<id<<endl;
        return nullptr;
    }
    

    Class* cur = curYear->ClassHead;
    while(cur)
    {
        if(cur ->Name == clss)
        break;
        cur = cur->Next;
    }
    if(cur)
    {
        Student* head = cur->StudentHead;
        while(head)
        {
            if(head->Id == id) break;
            head = head->Next;

        }
        return head;
    }
    return nullptr;
}

void InputMarkForStudent(SchoolYear* headOfSchoolyear, string input)
{
    ifstream in;
    in.open(input);
    if(!in.is_open()) return;

    // Access to ShoolYear contain semester (This semester contain course current)
    SchoolYear* cur = headOfSchoolyear;
    string year;
    //getline(in,year);
    getline(in, year);
    string beginYear = year.substr(0,2);

    while(cur && cur->BeginYear != beginYear)
   {
    cur = cur->NextYear;
   }
    
   // Access Semester Contain Course current
   string semester;
   getline(in,semester);
   Semester* SemesterCur;

   if(semester[1] == '1')
   SemesterCur = cur->S1;
   else if(semester[1] == '2')
    SemesterCur = cur->S2;
    else SemesterCur = cur->S3;

    //Access Course current
   
    
    string idcourse;
    getline(in,idcourse);

     string coursename;
    getline(in,coursename);

    string classnameOfcourse;
    getline(in,classnameOfcourse);


    Course* CourseCur = SemesterCur->CourseList;
    while(CourseCur )
    {
        if(CourseCur->CourseId == idcourse && CourseCur->ClassName == classnameOfcourse) break;
        CourseCur = CourseCur->Next;
    }
    

    // Now Access to Student
    string id, name, clss, no; // clss: class do bi trung ten
    double midterm, final, total, othermark;

    string line; // line: No,ID,name,Class.... (subline)
    getline(in,line);
    
    
    while(!in.eof())
    {
        getline(in,no,',');
        getline(in,id,',');
        getline(in,name,',');
        getline(in,clss,',');
        in>>midterm;
        in>>final;
        in>>othermark;
        in>>total;
        in.ignore(1);
        
        Student* studentCurOfClass = FindNodeStudentOfClassToPutMark(id,headOfSchoolyear,clss);
        Student* studentCufOfCourse = FindNodeStudentOfCourseToPutMark(id, CourseCur);
        putMarkToStudentNode(studentCurOfClass, studentCufOfCourse, midterm,final,othermark,total, idcourse, coursename,semester,year);

        // Access Student
        

    }
    in.close();
    
    

}



//This function access File store Mark and Using InputMarkForStudent function to input mark for student in a course
void AccessFileMark(string directoryPath,  SchoolYear* headOfSchoolyear) {
    stack<string> directories;
    directories.push(directoryPath);

    while (!directories.empty()) {
        string currentDirectory = directories.top();
        directories.pop();

        string directoryGlob = currentDirectory + "/*";
        _finddata_t fileInfo;
        intptr_t handle = _findfirst(directoryGlob.c_str(), &fileInfo);

        if (handle == -1) {
            cerr << "Error: unable to open directory " << currentDirectory << endl;
            continue;
        }

        do {
            if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0){
                if (fileInfo.attrib & _A_SUBDIR)  {
                    string subdirectoryPath = currentDirectory + "/" + fileInfo.name;
                    
                    directories.push(subdirectoryPath);
                } 
                else {
                	
                    string fileName = fileInfo.name;
                    string check = fileName.substr(0,4);
                    
                    string a = "mark";
                    if(check.compare(a)== 0) 
                    {
                        
					string filePath = currentDirectory + "/" + fileInfo.name;
                    InputMarkForStudent(headOfSchoolyear,filePath);
                    }
                    
                    
                }
            }
        } while (_findnext(handle, &fileInfo) == 0);

        _findclose(handle);
    }
}

//Ai do chay dum ham main nay zoi
//include lun ca ham cua Tran
// int main()
// {
//     string directoryPath = "SchoolYear";
//     Course *CourseHead = nullptr, *curCourse = nullptr;
//     Class *ClassHead = nullptr, *curClass = nullptr;
//     SchoolYear *YearHead = nullptr, *curYear = nullptr;
//     printDirectory(directoryPath, 0, curCourse, curClass, YearHead, curYear);
   
//     AccessFileMark(directoryPath , ClassHead, YearHead);

//     return 0;
// }
