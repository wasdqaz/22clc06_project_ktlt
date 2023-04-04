#include "header.h"

Mark* makeMarkNode (double midterm, double final, double total, string course)
{
    Mark* newMark = new Mark;
    newMark->Id = course;
    newMark->FinalMark = final;
    newMark->MidtermMark = midterm;
    newMark->TotalMark = total;
    newMark->Next = nullptr;
    newMark->Prev = nullptr;
    return newMark;
    
}


void putMarkToStudentNode (Student* studentOfClass, Student* studentOfCourse, double midterm, double final, double total, string course)
{
    // push Node Mark to Student of class
    Mark* head =studentOfClass ->HeadOfMark;
    Mark* newMark =  makeMarkNode(midterm, final, total, course);
    if(!head)
    {
        studentOfClass->HeadOfMark = newMark;
        
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
Student* FindNodeStudentOfClassToPutMark (string id, Class* head, string clss)
{
    Class* cur = head;
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
    Class* headOfClass= cur->ClassHead;
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
    string course;
    getline(in,course);
    Course* CourseCur = SemesterCur->CourseList;
    while(CourseCur && CourseCur->CourseId != course)
    {
        CourseCur = CourseCur->Next;
    }
    

    // Now Access to Student
    string id, name, clss; // clss: class do bi trung ten
    double midterm, final, total;

    Class* curClass= headOfClass;
    while(!in.eof())
    {
        getline(in,id,',');
        getline(in,name,',');
        getline(in,clss,',');
        in>>midterm;
        in>>final;
        in>>total;
        in.ignore(1);
        
        Student* studentCurOfClass = FindNodeStudentOfClassToPutMark(id,headOfClass,clss);
        Student* studentCufOfCourse = FindNodeStudentOfCourseToPutMark(id, CourseCur);
        putMarkToStudentNode(studentCurOfClass, studentCufOfCourse, midterm,final,total, course);

        // Access Student
        

    }
    
    

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
