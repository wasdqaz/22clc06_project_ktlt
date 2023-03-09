#ifndef _COURSESTRUCT_H_
#define _COURSESTRUCT_H_

#include <iostream>
using namespace std;

struct Course
{
    string CourseId, CourseName, ClassName, TeacherName, Session, DayOfWeek;
    int NumberOfCredits, MaxStudent = 50;
    Course *Next, *Prev = nullptr;
};

#endif