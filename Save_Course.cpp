#include "header.h"


void Save_InfoCourse(Course *curCourse) // Year, Semester mac dinh
{
    string Course_Name = "Data/SchoolYear/" + curCourse->Year + "/" + curCourse->NameSemester + "/" + curCourse->CourseName + "/";
    // string Course_Name = pathSemester + Smeter -> CourseList -> CourseName;
    ofstream ofs;
    string nameSmter;
    if (curCourse->NameSemester == "Semester01")
        nameSmter = "S1";
    else if (curCourse->NameSemester == "Semester02")
        nameSmter = "S2";
    else
        nameSmter = "S3";
    string NameFile = Course_Name + nameSmter + "_" + curCourse->CourseId + ".txt";
    ofs.open(NameFile);
    if (!ofs.is_open())
        return;
    ofs << curCourse->CourseId << "\n"
        << curCourse->CourseName << "\n"
        << curCourse->ClassName << "\n"
        << curCourse->TeacherName << "\n"
        << curCourse->Session << "\n"
        << curCourse->DayOfWeek << "\n"
        << curCourse->NumberOfCredits << "\n";
    ofs.close();
}

void Save_StudentCourse_1(Student *StuCourse, string FileName)
{
    fstream file;
    file.open(FileName, ios::app);
    if (!file.is_open())
        return;
    file <<"\n";
    file << StuCourse -> Id << "," << StuCourse -> Name <<","<<StuCourse -> Class;
    file.close();
}



void Save_StudentCourse_All(Course *curCourse, string FileName)
{
    ofstream ofs;
    ofs.open(FileName);
    if (!ofs.is_open());
        return;
    ofs << curCourse->CourseId << "\n"
        << curCourse->CourseName << "\n"
        << curCourse->ClassName << "\n"
        << curCourse->TeacherName << "\n"
        << curCourse->Session << "\n"
        << curCourse->DayOfWeek << "\n"
        << curCourse->NumberOfCredits;
    Student *StuCourse = curCourse -> CourseStudent;
    while (StuCourse != nullptr)
    {
        ofs << "\n" <<StuCourse->Id << "," <<StuCourse->Name << "," << StuCourse->Class;
        StuCourse = StuCourse->Next;
    }
    ofs.close();
}


void Save_StudentCourse_All_Mark(Course *curCourse, string FileName)
{
    ofstream ofs;
    ofs.open(FileName);
    if (!ofs.is_open())
        return;
    string nameSmter;
    if (curCourse->NameSemester == "Semester01")
        nameSmter = "S1";
    else if (curCourse->NameSemester == "Semester02")
        nameSmter = "S2";
    else
        nameSmter = "S3";
    ofs << curCourse -> Year << "\n"
        << nameSmter << "\n"
        << curCourse->CourseId;
    Student *StuCourse = curCourse -> CourseStudent;
    while (StuCourse != nullptr)
    {
        ofs << "\n" <<StuCourse->Id << "," <<StuCourse->Name << "," << StuCourse->Class;
        StuCourse = StuCourse->Next;
    }
    ofs.close();
}