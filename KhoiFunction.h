#ifndef _KHOIFUNCTION_H_
#define _KHOIFUNCTION_H_
#include "header.h"
#include <iomanip>

void changePassword(Account &a);
bool checkPassword(string a);
void CreateSchoolYears(SchoolYear Year);

void ViewListOfCourse(Course *head);
void AddStudentToCourse(Course *CourseHead);
void DeleteCourse(Course *&head);
void DeleteStudentInCourse(Student *&head);
void DeleteMark(Mark *&head);

void UpdateStudentResult(Semester* Semester_head);
bool FindCourse(Course *head, string name, Course *&tmp);
bool FindStudent(Student *&head, string Student_id); 

void ViewScoreBoardStudent(SchoolYear *head, SchoolYear *CurYear, Account *User);
bool FindClass(Class *&head, string ClassName);

#endif