#include "header.h"

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
        getline(ifs, cur -> SocialId);
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
                string pathFile = directoryPath + "/" + fileInfo.name;
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
                    string FileName = fileInfo.name;
                    curClass -> Name = FileName.substr(0, FileName.find('.'));
                    InputStudent(curClass -> StudentHead, pathFile);
                    curClass -> Next = nullptr;
                }
                
                cout << string(indent, ' ') << "File: " << fileInfo.name << endl;
            }
        }
    } while (_findnext(handle, &fileInfo) == 0);

    _findclose(handle);
}

/*int main() {
    string directoryPath = "SchoolYear";
    Course *CourseHead = nullptr, *curCourse = nullptr;
    Class *ClassHead = nullptr, *curClass = nullptr;
    printDirectory(directoryPath, 0, CourseHead, curCourse, ClassHead, curClass);
    return 0;
}*/
