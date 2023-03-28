#include "header.h"


void Course()
{
    string Name_SY = "SchoolYear";
    DIR *SchoolYear = opendir(Name_SY.c_str());
    if (SchoolYear)
    {
        dirent *NameY;
        while ((NameY = readdir(SchoolYear)) != NULL)
        {
            string Name_Year = NameY -> d_name;
            if (NameY->d_name[0] == '.') 
            //if (Name_Year == "." || Name_Year == "..")
                continue;
            cout <<Name_Year<<endl;
            if (Name_Year == "CLASS") continue;
            string pathSemester = Name_SY + "/" + Name_Year;
            DIR *Semester = opendir(pathSemester.c_str());
            if (Semester)
            {
                dirent *NameS;
                while ((NameS = readdir(Semester)) != NULL)
                {
                     if (NameS->d_name[0] == '.')
                    //if (Name_Semester == "." || Name_Semester == "..")
                        continue;
                    string Name_Semester = NameS -> d_name;
                    cout <<"\t"<<Name_Semester<<endl;

                    string pathCourse = pathSemester + "/" + Name_Semester;
                    DIR *Course = opendir(pathCourse.c_str());
                    if (Course)
                    {
                        dirent *NameC;
                        while ((NameC = readdir(Course)) != NULL)
                        {
                            if (NameC -> d_name[0] == '.') 
                                continue;
                            string Name_Course = NameC -> d_name;
                            cout <<"\t\t"<<Name_Course<<endl;
                        }
                        closedir(Course);
                    }
                }
                closedir(Semester);
            }
        }
        closedir(SchoolYear);
    }
}


void InputStudent(Student *&StuHead, string input)
{
    ifstream ifs;
    ifs.open(input);
    if (!ifs.is_open()) return;
    Student *cur = nullptr;
     while (!ifs.eof())/*  */
    {
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
        string Info = "";
        getline(ifs, Info, ',');
        cur -> No = stoi(Info);
        getline(ifs, cur ->Id, ',');
        getline(ifs, cur -> Name, ',');
        getline(ifs, cur -> Gender, ',');
        getline(ifs, cur -> DateOfBirth, ',');
        getline(ifs, cur -> SocialId, ',');
        cur -> Next = nullptr;
    }
}


void InputClass(Class *&ClassHead)
{
    string Name_SY = "SchoolYear";
    DIR *SchoolYear = opendir(Name_SY.c_str());
    Class *cur = nullptr;
    if (SchoolYear)
    {
        dirent *ClassAll;
        while ((ClassAll = readdir(SchoolYear)) != NULL)
        {
            string NClass = ClassAll -> d_name;
            if (ClassAll->d_name[0] == '.' || NClass != "CLASS") 
            //if (Name_Year == "." || Name_Year == "..")
                continue;
            cout <<NClass<<endl;
            string pathClass = Name_SY + "/" + NClass;
            DIR *CLASS = opendir(pathClass.c_str());
            if (CLASS)
            {
                dirent *NameC;
                while ((NameC = readdir(CLASS)) != NULL)
                {
                     if (NameC->d_name[0] == '.')
                    //if (Name_Semester == "." || Name_Semester == "..")
                        continue;
                    string Name_Class = NameC -> d_name;
                    cout <<Name_Class <<endl;
                    if (ClassHead == nullptr)
                    {
                        ClassHead = new Class;
                        cur = ClassHead;
                    }
                    else
                    {
                        cur -> next = new Class;
                        cur = cur -> next;
                    }
                    cur -> Name = Name_Class;
                    InputStudent(cur -> StudentHead, cur -> Name);
                    cur -> next = nullptr;
                }
                closedir(CLASS);
            }
        }
        closedir(SchoolYear);
    }   
}
int main()
{
    string name;
    Class *ClassHead = nullptr;
    InputClass(ClassHead);
    cout <<1;
}
