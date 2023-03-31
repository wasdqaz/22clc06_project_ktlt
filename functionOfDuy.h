#ifndef _FUNCTIONOFDUY_H_
#define _FUNCTIONOFDUY_H_

#include "header.h"

void CalGpa(Class *pHead);
void AddNewYear(SchoolYear *&pHeadYear);
Semester *AddNewSemester(SchoolYear *pHeadYear);
void AddCourse(Semester *pHeadSemester);
void AddNewStudent(Class *pHead);
void RmStudentFrCourse(Course *pHead);
void UpdCourseInf(Course *pHead);

#endif