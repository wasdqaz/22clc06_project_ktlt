#ifndef _FUNCTIONOFDUY_H_
#define _FUNCTIONOFDUY_H_

#include "header.h"

void CalGpa(Student &Hs, Course *HeadCourse);
void AddNewYear(SchoolYear *&pHeadYear);
Semester *AddNewSemester(SchoolYear *pHeadYear);
void AddCourse(Semester *pHeadSemester);
void AddNewStudent(Class *pHead);
void RmStudentFrCourse(Course *pHead);

#endif