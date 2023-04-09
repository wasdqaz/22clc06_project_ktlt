#ifndef _FUNCTIONOFDUY_H_
#define _FUNCTIONOFDUY_H_

#include "header.h"
#include <iomanip>

void CalGpa(Class *pHead);
void AddNewYear(SchoolYear *&pHeadYear);
Semester *AddNewSemester(SchoolYear *pHeadYear);
void AddCourse(SchoolYear *Year, Semester *pHeadSemester);
void AddNewStudent(SchoolYear *pHeadYear);
void RmStudentFrCourse(Course *pHead);
void UpdCourseInf(Course *pHead);
Semester *defaultSemester(SchoolYear *pHead);
void deleteAllLists(SchoolYear *&pHead, Account *&pHeadAccStudent, Account *&pHeadAccStaff /*,Staff *&pHeadStaff*/);
void viewStudentsInCourse(Course *pHead);
void viewCourseScoreboard(Course *pHead);

#endif