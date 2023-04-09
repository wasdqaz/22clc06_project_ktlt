#include "header.h"

void Add_FolderSchoolYear(SchoolYear *Year)
{
    string pathSchoolYear = "Data/SchoolYear/";
    string YearName = pathSchoolYear + Year -> BeginYear + "-" + Year -> EndYear;
    int create_folder = _mkdir(YearName.c_str());
    if (create_folder == 0) cout << "Add new school year successfully" << endl;
    
}
void Add_FolderSemester(SchoolYear *Year, Semester *Smeter)
{
    string pathYear = "Data/SchoolYear/" + Year -> BeginYear + "-" + Year -> EndYear + "/";
    string SemesterName = pathYear + Smeter -> NameSemester;
    int create_folder = _mkdir(SemesterName.c_str());
    if (create_folder == 0) cout << "Semester created" << endl;
}
void Add_InfoCourse(SchoolYear *Year, Semester *Smeter) //Year, Semester mac dinh 
{
    string pathYear = "Data/SchoolYear/" + Year -> BeginYear + "-" + Year -> EndYear + "/";
    string pathSemester = pathYear + Smeter -> NameSemester;
    string Course_Name = pathSemester + Smeter -> CourseList -> CourseName;
    int create_folder = _mkdir(Course_Name.c_str());
    ofstream ofs;
    string nameSmter;
    if (Smeter -> NameSemester == "Semester01")
        nameSmter = "S1";
    else if (Smeter -> NameSemester == "Semester02")
            nameSmter = "S2";
            else nameSmter = "S3";
    string NameFile = Course_Name + nameSmter + "_" + Smeter->CourseList->CourseName;
    ofs.open(Course_Name);
    if (!ofs.is_open()) return;
    Course *curCourse = Smeter -> CourseList;
    ofs << curCourse -> CourseId << "\n" 
        << curCourse -> CourseName << "\n"
        << curCourse -> ClassName << "\n"
        << curCourse -> TeacherName << "\n"
        << curCourse -> Session << "\n"
        << curCourse -> DayOfWeek << "\n"
        << curCourse -> NumberOfCredits << "\n";
    ofs.close();
    if (create_folder == 0) cout << "Add course successfully" << endl;
}