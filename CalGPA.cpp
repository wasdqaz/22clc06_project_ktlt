#include <iostream>
#include "header.h"
#include "CalGPA.h"
using namespace std;

void CalGpa(Student &Hs, Course *HeadCourse)
{
    float SumMark = 0;
    float SumCredits = 0;
    Course *Temp = Hs.CoursesOfStudentHead; //day la con tro temp cho danh sach course cua hoc sinh
    while(Temp != nullptr)
    {
        Course *CourseTemp = HeadCourse; //con tro temp cho danh sach toan bo khoa hoc trong nam hoc
        while (CourseTemp != nullptr)
        {
            if (Temp->CourseName == CourseTemp->CourseName) //neu do la course cua hoc sinh thi thuc hien tinh toan
            {
                Student *StudentTemp = CourseTemp->CourseStudent; //con tro temp cho danh sach hoc sinh trong course

                while (StudentTemp->Id != Hs.Id)       //dua con tro cua danh sach hoc sinh 
                    StudentTemp = StudentTemp->Next;   //trong course den hoc sinh can tinh gpa

                SumMark += StudentTemp->TotalMark;
                SumCredits += CourseTemp->NumberOfCredits;
                break;
            }
            CourseTemp = CourseTemp->Next;
        }
        Temp = Temp->Next;
    }
    Hs.Gpa = SumMark / SumCredits;
}
