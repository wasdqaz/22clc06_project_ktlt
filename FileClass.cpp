#include "header.h"

Student *InputStudent(Student *&StuHead, string input)
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
        getline(ifs, Info, ';');
        cur -> No = stoi(Info);
        getline(ifs, cur ->Id, ';');
        getline(ifs, cur -> Name, ';');
        getline(ifs, cur -> Gender, ';');
        getline(ifs, cur -> DateOfBirth, ';');
        getline(ifs, cur -> SocialId, ';');
        cur -> Next = nullptr;
    }
}


void Input_Class(Class *&ClassHead)
{
    Class *cur = ClassHead; 
    while (cur)
    {
        string Inp = ClassHead -> Name + ".txt";
        cur -> StudentHead = InputStudent(cur -> StudentHead, Inp);
        ClassHead -> tail = cur;
        cur = cur -> next;
    }
}

void CreateClass(Class *&AddClass, Class *&ClassHead)
{
    cout <<"The structure of the class name: Year(YY)+";
    cout <<"Please enter the class name: ";
    string ClassName;
    cin >>ClassName;
    ClassName += "txt";
    Class *cur = ClassHead -> tail;
    cur -> next = new Class;
    cur = cur -> next;
    cur -> StudentHead = InputStudent(cur -> StudentHead, ClassName);
    ClassHead -> tail = cur;
}


