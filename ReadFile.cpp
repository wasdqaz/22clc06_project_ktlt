#include "header.h"

void InputStudent(Student *&StuHead, string input)
{
    ifstream ifs;
    ifs.open(input);
    if (!ifs.is_open())
        return;

    string line;//subline
    getline(ifs,line);

    Student *cur = StuHead;
    while (!ifs.eof()) /*  */
    {
        string Info = "";
        getline(ifs, Info, ',');
        //if (Info == "\n" || Info == "") return;
        if (StuHead == nullptr)
        {
            StuHead = new Student;
            cur = StuHead;
        }
        else
        {
            cur->Next = new Student;
            cur = cur->Next;
        }

        cur->No = stoi(Info);
        getline(ifs, cur->Id, ',');
        getline(ifs, cur->Name, ',');
        getline(ifs, cur->Gender, ',');
        getline(ifs, cur->DateOfBirth, ',');
        getline(ifs, cur->SocialId);
    }
    ifs.close();
}

void InputStudentCourse(Course *&subCourse, string input)
{
    ifstream ifs;
    ifs.open(input);
    if (!ifs.is_open())
        return;
    getline(ifs, subCourse->CourseId);
    getline(ifs, subCourse->CourseName);
    getline(ifs, subCourse->ClassName);
    getline(ifs, subCourse->TeacherName);
    getline(ifs, subCourse->Session);
    getline(ifs, subCourse->DayOfWeek);
    ifs >> subCourse->NumberOfCredits;
    // subCourse -> NumberOfCredits = stoi(Credits);
    
    ifs.ignore();
    string line;//subline
    getline(ifs,line);
    
    Student *cur = nullptr;
    while (!ifs.eof())
    {
        if (subCourse -> CourseStudent == nullptr)

        {
            subCourse->CourseStudent = new Student;
            cur = subCourse->CourseStudent;
        }
        else
        {
            cur->Next = new Student;
            cur = cur->Next;
        }
        string NO = "";
        getline(ifs, NO, ',');
        cur->No = stoi(NO);
        getline(ifs, cur->Id, ',');
        getline(ifs, cur->Name, ',');
        getline(ifs, cur->Class);
    }
    ifs.close();
}

void ReadDirectory(const string &directoryPath, Semester *&curSe, Course *&curCourse, Class *curClass, SchoolYear *&YearHead, SchoolYear *curYear)
{

    string directoryGlob = directoryPath + "/*";
    struct _finddata_t fileInfo;
    intptr_t handle = _findfirst(directoryGlob.c_str(), &fileInfo);

    if (handle == -1)
    {
        return;
    }

    do
    {
        if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0)
        {
            if (fileInfo.attrib & _A_SUBDIR)
            {
                string subdirectoryPath = directoryPath + "/" + fileInfo.name;
                if (fileInfo.name[2] == '-')
                {
                    if (YearHead == nullptr)
                    {
                        YearHead = new SchoolYear;
                        curYear = YearHead;
                    }
                    else
                    {
                        curYear->NextYear = new SchoolYear;
                        curYear = curYear->NextYear;
                    }
                    string FileName = fileInfo.name;
                    curYear->BeginYear = FileName.substr(0, 2);
                    curYear->EndYear = FileName.substr(3, 2);
                }
                else
                {
                    string NameYear = curYear->BeginYear + "-" + curYear->EndYear;
                    if (fileInfo.name[0] == 'S')
                    {
                        if (fileInfo.name[9] == '1')
                        {
                            if (curYear->S1 == nullptr)
                                curYear->S1 = new Semester;
                            curSe = curYear->S1;
                            curSe->NameSemester = "Semester01";
                        }
                        else if (fileInfo.name[9] == '2')
                        {
                            if (curYear->S2 == nullptr)
                                curYear->S2 = new Semester;
                            curSe = curYear->S2;
                            curSe->NameSemester = "Semester02";
                        }
                        else
                        {
                            if (curYear->S3 == nullptr)
                                curYear->S3 = new Semester;
                            curSe = curYear->S3;
                            curSe->NameSemester = "Semester03";
                        }
                        curSe->Year = NameYear;
                    }
                }
                ReadDirectory(subdirectoryPath, curSe, curCourse, curClass, YearHead, curYear);
            }
            else
            {
                string pathFile = directoryPath + "/" + fileInfo.name;
                string NameYear = curYear->BeginYear + "-" + curYear->EndYear;
                if (fileInfo.name[0] >= '0' && fileInfo.name[0] <= '9')
                {
                    if (curYear->ClassHead == nullptr)
                    {
                        curYear->ClassHead = new Class;
                        curClass = curYear->ClassHead;
                    }
                    else
                    {
                        curClass->Next = new Class;
                        curClass = curClass->Next;
                    }
                    curClass->Year = NameYear;
                    string FileName = fileInfo.name;
                    curClass->Name = FileName.substr(0, FileName.find('.'));
                    InputStudent(curClass->StudentHead, pathFile);
                }
                else
                {

                    string FileName = fileInfo.name;
                    int t = FileName.find("mark");
                    if (t != -1)
                        continue;
                    
                    Course *curYearCourse = curSe -> CourseList;
                    if (curSe->CourseList == nullptr)
                    {
                        curSe->CourseList = new Course;
                        curCourse = curSe->CourseList;
                    }
                    else
                    {
                        curCourse->Next = new Course;
                        curCourse = curCourse->Next;
                    }
                    curCourse->Year = NameYear;
                    curCourse->NameSemester = curSe->NameSemester;
                    InputStudentCourse(curCourse, pathFile);
                }
            }
        }
    } while (_findnext(handle, &fileInfo) == 0);

    _findclose(handle);
}
