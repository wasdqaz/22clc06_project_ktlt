#ifndef _FUNCTIONOFDUY_H_
#define _FUNCTIONOFDUY_H_

#include "header.h"
#include <iomanip>

void CalGpa(Class *pHead);
void AddNewYear(SchoolYear *&pHeadYear);
Semester *AddNewSemester(SchoolYear *pHeadYear);
void AddCourse(Semester *pHeadSemester);
void AddNewStudent(SchoolYear *pHeadYear);
void RmStudentFrCourse(Course *pHead);
void UpdCourseInf(Course *pHead);
Semester *defaultSemester(SchoolYear *pHead);
void deleteAllLists(SchoolYear *&pHead, Account *&pHeadAccStudent, Account *&pHeadAccStaff ,Staff *&pHeadStaff);
void viewStudentsInCourse(Course *pHead);
void viewCourseScoreboard(Course *pHead);
void calGPASemester(Class *pHeadClass, Semester *pHeadSemester);
void viewClassScoreboard(SchoolYear *pHead, Semester *SemesterHead, SchoolYear *YearHead);
void viewListOfCourses_Student(Semester *Semester_head, Account *Student_head);
void readStaffInfo(Staff *&pHead);

#endif