#include "header.h"


void CreateClass(SchoolYear *YearHead)
{
    string ClassName;
    cout << "Please enter class name: ";
    cin.ignore();
    getline(cin, ClassName);

        
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

