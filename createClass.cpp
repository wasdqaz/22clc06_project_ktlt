#include "header.h"
void CreateClass(SchoolYear *YearHead)
{
    string ClassName;
    cout << "Please enter class name: ";
    cin.ignore();
    getline(cin, ClassName);

    // Class *Temp_Class=YearHead->ClassHead;

    // while(Temp_Class&&Temp_Class->Next){
    //     if(Tmp)
    // }

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
    Add_FolderClass(YearHead->ClassHead);
}

// int main(){
//     SchoolYear *a=nullptr;
//     CreateClass(a);

//     return 0;
// }