#include "header.h"
#include "functionOfDuy.h"

void deleteAllLists(SchoolYear *&pHead, Account *&pHeadAccStudent, Account *&pHeadAccStaff /*,Staff *&pHeadStaff*/)
{
    Student *tmp = pHead->ClassHead->StudentHead;
    while (tmp != nullptr)
    { // xóa list điểm
        Mark *temp = tmp->HeadOfMark;
        while (temp != nullptr)
        {
            Mark *tempMark = temp;
            temp = temp->Next;
            delete tempMark;
        }
        tmp = tmp->Next;
    }

    Class *pTemp = pHead->ClassHead;
    while (pTemp != nullptr)
    { // xóa hs trong class
        tmp = pTemp->StudentHead;
        while (tmp != nullptr)
        {
            Student *tempStudent = tmp;
            tmp = tmp->Next;
            delete tempStudent;
        }
        pTemp = pTemp->Next;
    }

    SchoolYear *Temp = pHead;
    while (Temp != nullptr)
    { // xóa class
        pTemp = Temp->ClassHead;
        while (pTemp != nullptr)
        {
            Class *tempClass = pTemp;
            pTemp = pTemp->Next;
            delete tempClass;
        }
        Temp = Temp->NextYear;
    }

    if (pHead->S1 != nullptr)
    {
        Course *TempCourse = pHead->S1->CourseList;
        while (TempCourse != nullptr)
        { // xóa hs trong course hk1
            tmp = TempCourse->CourseStudent;
            while (tmp != nullptr)
            {
                Student *tempStudent = tmp;
                tmp = tmp->Next;
                delete tempStudent;
            }
            TempCourse = TempCourse->Next;
        }
    }

    if (pHead->S2 != nullptr)
    {
        Course *TempCourse = pHead->S2->CourseList;
        while (TempCourse != nullptr)
        { // xóa hs trong course hk2
            tmp = TempCourse->CourseStudent;
            while (tmp != nullptr)
            {
                Student *tempStudent = tmp;
                tmp = tmp->Next;
                delete tempStudent;
            }
            TempCourse = TempCourse->Next;
        }
    }

    if (pHead->S3 != nullptr)
    {
        Course *TempCourse = pHead->S3->CourseList;
        while (TempCourse != nullptr)
        { // xóa hs trong course hk3
            tmp = TempCourse->CourseStudent;
            while (tmp != nullptr)
            {
                Student *tempStudent = tmp;
                tmp = tmp->Next;
                delete tempStudent;
            }
            TempCourse = TempCourse->Next;
        }
    }

    if (pHead->S1 != nullptr)
    {
        Course *TempCourse = pHead->S1->CourseList;
        while (TempCourse != nullptr)
        { // xóa course hk1
            Course *temp = TempCourse;
            TempCourse = TempCourse->Next;
            delete temp;
        }
    }

    if (pHead->S2 != nullptr)
    {
        Course *TempCourse = pHead->S2->CourseList;
        while (TempCourse != nullptr)
        { // xóa course hk2
            Course *temp = TempCourse;
            TempCourse = TempCourse->Next;
            delete temp;
        }
    }

    if (pHead->S3 != nullptr)
    {
        Course *TempCourse = pHead->S3->CourseList;
        while (TempCourse != nullptr)
        { // xóa course hk3
            Course *temp = TempCourse;
            TempCourse = TempCourse->Next;
            delete temp;
        }
    }

    while (pHead != nullptr)
    { // xóa năm học
        Temp = pHead;
        delete Temp->S1;
        delete Temp->S2;
        delete Temp->S3;
        pHead = pHead->NextYear;
        delete Temp;
    }

    /*while (pHeadStaff != nullptr) { //xóa list staff
        Staff *tempStaff = pHeadStaff;
        pHeadStaff = pHeadStaff->Next;
        delete tempStaff;
    }*/

    while (pHeadAccStaff != nullptr)
    { // xóa account staff
        Account *temp = pHeadAccStaff;
        pHeadAccStaff = pHeadAccStaff->next;
        delete temp;
    }

    while (pHeadAccStudent != nullptr)
    { // xóa account student
        Account *temp = pHeadAccStudent;
        pHeadAccStudent = pHeadAccStudent->next;
        delete temp;
    }
}