#include "header.h"

void Add_FolderSchoolYear(SchoolYear *Year)
{
    string pathSchoolYear = "Data/SchoolYear/";
    string YearName = pathSchoolYear + Year -> BeginYear + "-" + Year -> EndYear;
    int create_folder = _mkdir(YearName.c_str());
    if (create_folder == 0) cout << "Add new school year successfully" << endl;
    
}
void Add_FolderSemester(Semester *Smeter)
{
    string pathYear = "Data/SchoolYear/" + Smeter -> Year + "/";
    string SemesterName = pathYear + Smeter -> NameSemester;
    int create_folder = _mkdir(SemesterName.c_str());
    if (create_folder == 0) cout << "Semester created" << endl;
}
void Save_InfoCourse(Course *curCourse) //Year, Semester mac dinh 
{
    string Course_Name = "Data/SchoolYear/" + curCourse -> Year + "/" + curCourse -> NameSemester + "/" + curCourse -> CourseName;
    //string Course_Name = pathSemester + Smeter -> CourseList -> CourseName;
    ofstream ofs;
    string nameSmter;
    if (curCourse -> NameSemester == "Semester01")
        nameSmter = "S1";
    else if (curCourse -> NameSemester == "Semester02")
            nameSmter = "S2";
            else nameSmter = "S3";
    string NameFile = Course_Name + nameSmter + "_" + curCourse -> CourseId;
    ofs.open(NameFile);
    if (!ofs.is_open()) return;
    ofs << curCourse -> CourseId << "\n" 
        << curCourse -> CourseName << "\n"
        << curCourse -> ClassName << "\n"
        << curCourse -> TeacherName << "\n"
        << curCourse -> Session << "\n"
        << curCourse -> DayOfWeek << "\n"
        << curCourse -> NumberOfCredits << "\n";
    ofs.close();
    
}
void Add_InfoCourse(Course *curCourse) 
{
    string Course_Name = "Data/SchoolYear/" + curCourse -> Year + "/" + curCourse -> NameSemester + "/" + curCourse -> CourseName;
    int create_folder = _mkdir(Course_Name.c_str());
    if (!create_folder == 0) cout << "Add course successfully" << endl;
    Save_InfoCourse(curCourse);
}