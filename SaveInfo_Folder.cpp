#include "header.h"

void Add_FolderSchoolYear(SchoolYear *Year)
{
    string pathSchoolYear = "Data/SchoolYear/";
    string YearName = pathSchoolYear + Year->BeginYear + "-" + Year->EndYear;
    int create_folder = _mkdir(YearName.c_str());
    if (create_folder == 0) cout << "Add new school year successfully" << endl;
    string ClassName = YearName + "/CLASS";
    _mkdir(ClassName.c_str());
}
void Add_FolderSemester(Semester *Smeter)
{
    string pathYear = "Data/SchoolYear/" + Smeter->Year + "/";
    string SemesterName = pathYear + Smeter->NameSemester;
    int create_folder = _mkdir(SemesterName.c_str());
    if (create_folder == 0)
        cout << "Semester created" << endl;
}

void Add_InfoCourse(Course *newCourse)
{
    string Course_Name = "Data/SchoolYear/" + newCourse->Year + "/" + newCourse->NameSemester + "/" + newCourse->CourseName;
    int create_folder = _mkdir(Course_Name.c_str());
    //if (create_folder == 0)
    Save_InfoCourse(newCourse);
    cout << "Add course successfully" << endl;
}

