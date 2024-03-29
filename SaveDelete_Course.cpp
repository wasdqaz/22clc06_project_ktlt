#include "header.h"

string nameSemester(string name)
{
    if (name == "Semester01")
        return "S1";
    else if (name == "Semester02")
        return "S2";
    else
        return "S3";
}

void Save_InfoCourse(Course *curCourse) // Year, Semester mac dinh
{
    string Course_Name = "Data/SchoolYear/" + curCourse->Year + "/" + curCourse->NameSemester + "/" + curCourse->CourseName + "/";
    // string Course_Name = pathSemester + Smeter -> CourseList -> CourseName;
    ofstream ofs;
    string nameSmter = nameSemester(curCourse->NameSemester);
    string NameFile = Course_Name + nameSmter + "_" + curCourse->ClassName + "_" + curCourse->CourseId + ".txt";
    ofs.open(NameFile);
    if (!ofs.is_open())
        return;
    ofs << curCourse->CourseId << "\n"
        << curCourse->CourseName << "\n"
        << curCourse->ClassName << "\n"
        << curCourse->TeacherName << "\n"
        << curCourse->Session << "\n"
        << curCourse->DayOfWeek << "\n"
        << curCourse->NumberOfCredits;
    ofs.close();
}

void Save_StudentCourse_1(Student *StuCourse, string FileName)
{
    fstream file;
    file.open(FileName, ios::app);
    if (!file.is_open())
        return;
    file << "\n"
         << StuCourse->No << "," << StuCourse->Id << "," << StuCourse->Name << "," << StuCourse->Class;
    file.close();
}

void Save_StudentCourse_All(Course *curCourse)
{
    string pathSemester = "Data/SchoolYear/" + curCourse->Year + "/" + curCourse->NameSemester + "/";
    string pathCourse = pathSemester + curCourse->CourseName + "/";
    string nameSmter = nameSemester(curCourse->NameSemester);
    string NameCourse = pathCourse + nameSmter + "_" + curCourse->ClassName + "_" + curCourse->CourseId + ".txt";
    ofstream ofs;
    ofs.open(NameCourse);
    if (!ofs.is_open())
    return;
    ofs << curCourse->CourseId << "\n"
        << curCourse->CourseName << "\n"
        << curCourse->ClassName << "\n"
        << curCourse->TeacherName << "\n"
        << curCourse->Session << "\n"
        << curCourse->DayOfWeek << "\n"
        << curCourse->NumberOfCredits << "\n";
    ofs <<"No,ID,Name,Class";
    Student *StuCourse = curCourse->CourseStudent;
    while (StuCourse != nullptr)
    {
        ofs << "\n"
            << StuCourse->No << "," << StuCourse->Id << "," << StuCourse->Name << "," << StuCourse->Class;
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
    string nameSmter = nameSemester(curCourse->NameSemester);
    ofs << curCourse->Year << "\n"
        << nameSmter << "\n"
        << curCourse->CourseId << "\n"
        << curCourse->CourseName << "\n"
        << curCourse->ClassName << "\n";
    ofs << "No,ID,Name,Class,Midterm,Final,Other Mark,Total";
    Student *StuCourse = curCourse->CourseStudent;
    while (StuCourse != nullptr)
    {
        ofs << "\n"
            << StuCourse->No << "," << StuCourse->Id << "," << StuCourse->Name << "," << StuCourse->Class << ",";
        Mark* markStu = StuCourse->HeadOfMark;
        if (markStu)
        {
            ofs << markStu->MidtermMark << "," << markStu->FinalMark << "," << markStu->OtherMark << "," << markStu->TotalMark;
        }
        StuCourse = StuCourse->Next;
    }
    ofs.close();
}

void Input_Student_Course_File(Student *&StuCourse, string FileName)
{
    ifstream ifs;
    ifs.open(FileName);
    if (!ifs.is_open())
        return;
    
    string line;//subline
    getline(ifs,line);
    
    Student *curStudent = nullptr;
    while (!ifs.eof())
    {
        if (StuCourse == nullptr)
        {
            StuCourse = new Student;
            curStudent = StuCourse;
        }
        else
        {
            curStudent->Next = new Student;
            curStudent = curStudent->Next;
        }
        string NO = "";
        getline(ifs, NO, ',');
        curStudent->No = stoi(NO);
        getline(ifs, curStudent->Id, ',');
        getline(ifs, curStudent->Name, ',');
        getline(ifs, curStudent->Class);
    }
    ifs.close();
}

void CopyFile_Course(string fileCSV, string fileCourse)
{
    ifstream ifs;
    ifs.open(fileCSV);
    fstream ofs;
    ofs.open(fileCourse, ios::app);
    if (ifs.is_open() && ofs.is_open())
    {
        string fileContent((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
        ofs << "\n";
        ofs << fileContent;
    }else {
        cout<<"Unable to open file.\n";
    }
    cout<<"Upload successfully.\n";
    ifs.close();
    ofs.close();
}

void InputCSV_Course(Course *curCourse)
{
        string CourseID;
        cout << "Please enter the course ID: ";
        cin>>CourseID;
        // getline(cin, CourseID);
        string Class_Name;
        cout << "Please enter the class name of course: ";
        cin>> Class_Name;
        // getline(cin, Class_Name);
        while (curCourse && (curCourse->CourseId != CourseID || curCourse->ClassName != Class_Name)){
            curCourse = curCourse->Next;
        }
    string pathSemester = "Data/SchoolYear/" + curCourse->Year + "/" + curCourse->NameSemester + "/";
    string pathCourse = pathSemester + curCourse->CourseName + "/";
    string nameSmter = nameSemester(curCourse->NameSemester);
    string NameCourse = pathCourse + nameSmter + "_" + curCourse->ClassName + "_" + curCourse->CourseId + ".txt";

    string pathInput = "Data/Input_User/" + curCourse->CourseId + "_" + curCourse->ClassName + ".txt";
    Input_Student_Course_File(curCourse->CourseStudent, pathInput);
    CopyFile_Course(pathInput, NameCourse);
    /*string pathInput = pathIp + "*";
    struct _finddata_t fileInfo;
    intptr_t handle = _findfirst(pathInput.c_str(), &fileInfo);
    if (handle == -1)
        return;
    do
    {
        if (strcmp(fileInfo.name, ".") == 0 || strcmp(fileInfo.name, "..") == 0)
            continue;
        string fileName = fileInfo.name;
        if (fileName.find(CourseID) < 0)
            continue;
        string pathInputCourse = pathIp + fileName;
        Input_Student_Course_File(curCourse->CourseStudent, pathInputCourse);
        CopyFile_Course(fileName, NameCourse);
        break;
    } while (_findnext(handle, &fileInfo) == 0);
    _findclose(handle);*/
}

void Remove_File_Course(Course *curCourse)
{
    string pathSemester = "Data/SchoolYear/" + curCourse->Year + "/" + curCourse->NameSemester + "/" + curCourse->CourseName + "/";
    string nameSmter = nameSemester(curCourse->NameSemester);
    string NameCourse = pathSemester + nameSmter + "_" + curCourse->ClassName + "_" + curCourse->CourseId + ".txt";
    string NameMark = pathSemester + "mark_" + curCourse->ClassName + "_" + curCourse->CourseId + ".txt";
    remove(NameCourse.c_str());
    remove(NameMark.c_str());
}