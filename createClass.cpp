#include "header.h"


void CreateClass(SchoolYear *YearHead)
{
    string ClassName;
    cout << "Please enter class name: ";
    cin.ignore();
    getline(cin, ClassName);

    int choice;
    cout << "Do you want to add this class?" << endl;
    cout << "1. Yes \n2. No \n->Your choice: ";
    cin >> choice;
    if (choice == 2)
        return;
        
        if(YearHead->ClassHead==nullptr)
        {
            YearHead->ClassHead = new Class;
            YearHead->ClassHead->Name=ClassName;
        }
        else {
            Class *Cur_Class = YearHead->ClassHead;
            YearHead->ClassHead=new Class;
            YearHead->ClassHead->Name=ClassName;
            YearHead->ClassHead->Next=Cur_Class;
        }


    if (YearHead->ClassHead == nullptr)
    {
        YearHead->ClassHead = new Class;
        YearHead->ClassHead->Name = ClassName;
    }
    else
    {
        Class *Cur_Class = YearHead->ClassHead;
        YearHead->ClassHead = new Class;
        YearHead->ClassHead->Name = ClassName;
        YearHead->ClassHead->Next = Cur_Class;
    }
}

