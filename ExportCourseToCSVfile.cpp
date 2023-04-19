#include "header.h"
#include <direct.h>

Course *FindCourse(SchoolYear *HeadOfYear)
{
    SchoolYear *curyear = HeadOfYear;
    string year;
    cout << "Please enter begin year of SchoolYear contain course. Example: 21 (if that schoolYear is 2021-2022\n";
    cin >> year;
    string semester;
    cout << "Please enter semester contain course. Ex: S1 (if semester is first semester)\n";
    cin >> semester;
    while (curyear)
    {
        if (curyear->BeginYear.compare(year) == 0)
            break;
        curyear = curyear->NextYear;
    }
    if (!curyear)
    {
        cout << "Not found schoolyear\n";
        return nullptr;
    }
    Semester *semesterCur;
    if (semester[1] == '1')
        semesterCur = curyear->S1;
    else if (semester[1] == '2')
        semesterCur = curyear->S2;
    else if (semester[1] == '3')
        semesterCur = curyear->S3;
    else
    {
        cout << "semester invalid\n";
        return nullptr;
    }
    Course *curCourse = semesterCur->CourseList;
    string courseId, classname;
    cout << "Please enter Id course\n";
    cin >> courseId;
    cout << "Please enter classname of course\n";
    cin >> classname;
    while (curCourse)
    {
        if (curCourse->CourseId == courseId && curCourse->ClassName == classname)
            break;
        curCourse = curCourse->Next;
    }
    if (!curCourse)
    {
        cout << "Not found course\n";
        return nullptr;
    }
    return curCourse;
}

void ExportCourseToCSVFile(SchoolYear *head, string parentFolder)
{
    Course *cur = FindCourse(head);
    string idcourse = cur->CourseId;

    string semester[] = {"S1", "S2", "S3"};
    string tmp;
    if (cur->NameSemester[9] == '1')
        tmp = semester[0];
    if (cur->NameSemester[9] == '2')
        tmp = semester[1];
    if (cur->NameSemester[9] == '3')
        tmp = semester[2];
    string filename = tmp + "_" + cur->ClassName + "_" + idcourse + ".txt";

    Student *headOfStudent = cur->CourseStudent;
    string Data = "Data";
    string User = "User_Output";
    string filePath;

    // Search for the parent folder
    _finddata_t fileInfo;
    filePath = Data + "/" + User + "/" + filename;

    

    ofstream file;
    file.open(filePath.c_str());
    if (!file.is_open())
    {
        cerr << "Failed to create file!" << endl;
        return;
    }
    file << cur->CourseName << endl;
    file << cur->CourseId << endl;

    file << "ID Student,Name\n";
    while (headOfStudent)
    {
        file << headOfStudent->No << "," << headOfStudent->Id << "," << headOfStudent->Name << endl;
        headOfStudent = headOfStudent->Next;
    }

    file.close();
}
