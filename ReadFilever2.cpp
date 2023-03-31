#include <iostream>
#include <string>
#include <direct.h>
#include <io.h>
#include<fstream>

    using namespace std;


    struct Account{
        string UserName, Password;
        bool Status = false;
        int Role;
        string Class;           // Them ID, Class; // ID: username
        Account *Next;
    };
    struct Mark;
    struct Staff{
        string Id, Name, Gender, Birth, Social_ID;
        Staff *Next;
    };
   
    struct Student{
        int No;
        string Id, Name, Gender, DateOfBirth, SocialId, Class; //da bo cai Course, them Ho Ten, ngay sinh va CCCD
        float Gpa;
        Mark* HeadOfMark; //update head of mark
        Student *Next = nullptr;
        //bool Gender; // them gioi tinh
    };

    struct Mark{
        string NameOfCourse, Id;
        float TotalMark, FinalMark, MidtermMark, OtherMark;
        Mark *Next = nullptr;
        Mark* Prev = nullptr;
    };

    struct Course
    {
        string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
        int NumberOfCredits, MaxStudent = 50;
        Student *CourseStudent = nullptr; // moi update them
        Course *Next = nullptr;
    };

    struct Class{
        string Name;
        Student *StudentHead = nullptr;
        Class *Next = nullptr;
    };

    struct Semester{
        Course *CourseList;
        string StartDate, EndDate; // them ngay bat dau, ket thuc hk
        Semester *Next;
    };

    struct SchoolYear{
        string BeginYear, EndYear;
        Class *ClassHead;
        Semester S1, S2, S3;
        SchoolYear *NextYear; //them con tro cho nam hoc
    };

    
void InputStudent(Student *&StuHead, string input)
{
    ifstream ifs;
    ifs.open(input);
    if (!ifs.is_open()) return;
    Student *cur = nullptr;
     while (!ifs.eof())/*  */
    {
        string Info = "";
        getline(ifs, Info, ',');
        if (Info == "\n" || Info == "") return;
        if (StuHead == nullptr)
        {
            StuHead = new Student;
            cur = StuHead;
        }
        else
        {
            cur -> Next = new Student;
            cur = cur -> Next;
        }
        
        cur -> No = stoi(Info);
        getline(ifs, cur -> Id, ',');
        getline(ifs, cur -> Name, ',');
        getline(ifs, cur -> Gender, ',');
        getline(ifs, cur -> DateOfBirth, ',');
        getline(ifs, cur -> SocialId, ',');
        getline(ifs, cur -> Class);
    }
}


void printDirectory(const string& directoryPath, int indent, Course *&CourseHead, Course *curCourse, Class *&ClassHead, Class *curClass) {
    string directoryGlob = directoryPath + "/*";
    struct _finddata_t fileInfo;
    intptr_t handle = _findfirst(directoryGlob.c_str(), &fileInfo);

    if (handle == -1) {
        cerr << "Error: unable to open directory " << directoryPath << endl;
        return;
    }

    do {
        if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0){
            if (fileInfo.attrib & _A_SUBDIR)  {
                string subdirectoryPath = directoryPath + "/" + fileInfo.name;
                cout << string(indent, ' ') << "Directory: " << fileInfo.name << endl;
                printDirectory(subdirectoryPath, indent + 2, CourseHead, curCourse, ClassHead, curClass);
            } 
            else {
                string FileName = directoryPath + "/" + fileInfo.name;
                if (fileInfo.name[0] >= '0' && fileInfo.name[0] <= '9')
                {
                    if (ClassHead == nullptr)
                    {
                        ClassHead = new Class;
                        curClass = ClassHead;
                    }
                    else
                    {
                        curClass -> Next = new Class;
                        curClass = curClass -> Next;
                    }
                    curClass -> Name = fileInfo.name;
                    InputStudent(curClass -> StudentHead, FileName);
                    curClass -> Next = nullptr;
                }
                
                cout << string(indent, ' ') << "File: " << fileInfo.name << endl;
            }
        }
    } while (_findnext(handle, &fileInfo) == 0);

    _findclose(handle);
}

int main() {
    string directoryPath = "SchoolYear";
    Course *CourseHead = nullptr, *curCourse = nullptr;
    Class *ClassHead = nullptr, *curClass = nullptr;
    printDirectory(directoryPath, 0, CourseHead, curCourse, ClassHead, curClass);
    return 0;
}





/*#include <iostream>
#include <dirent.h>
#include <string>
#include <vector>
#include <sys/types.h>
using namespace std;

void read_directory(const std::string& dir_path, std::vector<std::string>& files)
{
    DIR* dir = opendir(dir_path.c_str());
    if (dir)
    {
        struct dirent* entry;
        while ((entry = readdir(dir)) != NULL)
        {
            std::string file_name = entry->d_name;
            if (file_name != "." && file_name != "..")
            {
                std::string full_path = dir_path + "/" + file_name;
                if (entry->d_type == DT_DIR) // if it is a directory
                {
                    // Recursively read subdirectory
                    read_directory(full_path, files);
                }
                else // if it is a file
                {
                    files.push_back(full_path);
                }
            }
        }
        closedir(dir);
    }
}

int main()
{
    std::string dir_path = "SchoolYear";
    std::vector<std::string> files;
    read_directory(dir_path, files);
    for (const auto& file : files)
    {
        std::cout << file << std::endl;
    }
    return 0;
}*/


