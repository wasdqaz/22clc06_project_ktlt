#ifndef _KHOIFUNCTION_H_
#define _KHOIFUNCTION_H_
#include "header.h"
#include<iomanip>

void changePassword(Account &a);
bool checkPassword(string a);
void CreateSchoolYears(SchoolYear Year);
void CreateClass(Class a);
void ViewListOfCourse(Course *head);
#endif