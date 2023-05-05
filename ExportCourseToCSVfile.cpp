#include "header.h"
#include <direct.h>

Course *FindCourse(SchoolYear *HeadOfYear)
{
    if (HeadOfYear == nullptr)
        return nullptr;
    SchoolYear *curyear = HeadOfYear;
    string year;
    while (true) {
        cout << "Please enter begin year of the SchoolYear that contains course. Example: 21 (if that SchoolYear is 2021-2022)\n";
        cin >> year;
        if (year.length() != 2 || year[0] != '2' || (year[1] < '0' || year[1] > '9')) {
            cout << "Wrong input!!! Please re-enter\n";
            continue;
        }
        break;
    }
    string semester;
    while (true) {
        cout << "Please enter the name of the Semester that contains the Course. Ex: S1 (if that Semester is the first semester)\n";
        cin >> semester;
        if (semester[1] < '1' || semester[1] > '3' || semester[0] != 'S') {
            cout << "Wrong input!!! Please re-enter\n";
            continue;
        }
        break;
    }
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
        cout << "Semester invalid\n";
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
    if (cur == nullptr)
        return;
    
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
    string User = "Output_User";
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

    file << "No,ID Student,Name\n";
    while (headOfStudent)
    {
        file << headOfStudent->No << "," << headOfStudent->Id << "," << headOfStudent->Name << endl;
        headOfStudent = headOfStudent->Next;
    }

    file.close();
}
