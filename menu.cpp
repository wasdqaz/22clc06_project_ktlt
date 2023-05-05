// #include "header.h"
// #include "KhoiFunction.h"
// #include "functionOfDuy.h"


// const int Mode[]={-1,1,2,3};
// int defautSemester=Mode[1];


// int main()
// {
//     Account *Student_head = nullptr;
//     Account *Staff_head = nullptr;
//     Account *User;
//     Semester *curSmeter = nullptr, *Semester_head = nullptr;
//     SchoolYear *Year_head = nullptr;
//     Staff *Staff_info_head = nullptr;
//     int Role;

//     createAccountList(Student_head, 2);
//     createAccountList(Staff_head, 1);

//     string directoryPath = "Data/SchoolYear";
//     Course *curCourse = nullptr;
//     Class *curClass = nullptr;
//     SchoolYear *curYear = nullptr;
//     ReadDirectory(directoryPath, curSmeter, curCourse, curClass, Year_head, curYear);
//     AccessFileMark(directoryPath, Year_head);
//     readStaffInfo(Staff_info_head);

//     //-------------------------------------login--------------------------------
//     cout << "You are student or staff.\n";
//     cout << "1. Staff\n";
//     cout << "2. Student\n";
//     cin >> Role;
//     string clss;
//     if (Role == 1)
//     {
//         User = Login(Staff_head);
//     }
//     else
//     {
//         User = Login(Student_head);
//         clss = User->Class;
//     }
//     //---------------------------------------------------------------------------------
//     curYear = Year_head;
//     while (curYear->NextYear != nullptr)
//         curYear = curYear->NextYear;
//     Semester_head = defaultSemester(curYear);
//     //CalGpa(Year_head->ClassHead);
//     //calGPASemester(Year_head->ClassHead, Semester_head);
//     //---------------------------------------------------------------------------------
//     while (true)
//     {
//         if (User->Role == 1)
//         {
//             cout << "-----------------------------MENU-------------------------------------\n";
//             cout << "|0. Change the password.                                             |\n";
//             cout << "|1. Create school year.                                              |\n";
//             cout << "|1. Add year.                                                        |\n";
//             cout << "|2. Create class.                                                    |\n";
//             cout << "|3. Add student.                                                     |\n";
//             cout << "|4. Create semester.                                                 |\n";
//             cout << "|5. Add course.                                                      |\n";
//             cout << "|6. Upload file student list for course.                             |\n";
//             cout << "|7. Update course information.                                       |\n";
//             cout << "|8. Add a student to the course.                                     |\n";
//             cout << "|9. Remove a student from the course.                                |\n";
//             cout << "|10. Delete course.                                                  |\n";
//             cout << "|11. View a list of classes.                                         |\n";
//             cout << "|12. View a list of students in a class.                             |\n";
//             cout << "|13. View a list of courses.                                         |\n";
//             cout << "|14. View a list of students in a course.                            |\n";
//             cout << "|15. Export a list of students in a course to a CSV file.            |\n";
//             cout << "|16. Import the scoreboard of a course.                              |\n";
//             cout << "|17. Update a student's result.                                      |\n";
//             cout << "|18. View the scoreboard of a class.                                 |\n";
//             cout << "|19. View the scoreboard of a course.                                |\n";
//             cout << "|20. View profile.                                                   |\n";
//             cout << "|21. Upload file student for class                                    |\n";
//             cout << "|22. Logout.                                                         |\n";
//             cout << "------------------------------END-------------------------------------\n";

//             int Staff_Choice;
//             cout << "Please enter your choice. \n";
//             cin >> Staff_Choice;
//              switch (Staff_Choice)
//             {
//             case 0:
//             {
//                 changePassword(User);
//                 if(User->Role == 1) SaveChangePassword(Staff_head);
//                 else SaveChangePassword(Student_head);
//                 break;
//             }
//             case 1:
//                 AddNewYear(curYear);
//                 break;
//             case 2:
//                 CreateClass(curYear); // can update
//                 break;
//             case 3:
//                 AddNewStudent(Year_head);
//                 break;
//             case 4:
//                 Semester_head = AddNewSemester(curYear);
//                 break;
//             case 5:
//                 AddCourse(Semester_head);
//                 break;
//             case 6:
//                 InputCSV_Course(Semester_head->CourseList);
//                 break;
//             case 7:
//                 UpdCourseInf(Semester_head->CourseList);
//                 break;
//             case 8:
//                 AddStudentToCourse(Semester_head->CourseList);
//                 break;
//             case 9:
//                 RmStudentFrCourse(Semester_head->CourseList);
//                 break;
//             case 10:
//                 DeleteCourse(Semester_head->CourseList);
//                 break;
//             case 11:
//                 viewClass(Year_head,curYear);
//                 break;
//             case 12:
//                 viewStudentClass(Year_head);
//                 break;
//             case 13:
//                 ViewListOfCourse(Semester_head->CourseList);
//                 break;
//             case 14:
//                 viewStudentsInCourse(Semester_head->CourseList);
//                 break;
//             case 15:
//                 ExportCourseToCSVFile(Year_head, "");

//                 break;
//             case 16:

//             {
//                 string filepath = ImportScoreboardFromFileUser(Year_head);
//                 SaveScorboardToFolderSchoolyear(filepath);
//                 break;
//             }

//             case 17:
//                 UpdateStudentResult(Semester_head);
//                 break;
//             case 18:
//                 viewClassScoreboard(Year_head->ClassHead, Semester_head, curYear);
//                 break;
//             case 19:
//                 viewCourseScoreboard(Semester_head->CourseList);
//                 break;
//             case 20:
//                 PrintProfile_Staff(Staff_head, Staff_info_head);
//                 break;
//             case 21:
//                 quickInputClass1stYear(curYear);
//                 break;
//             case 22:
                
//                 break;
//             default:
//                 cout << "Please re-check your choice.\n\n";
//                 break;
//             }
//             if (Staff_Choice == 22)
//                 break;
//         }
//         else
//         {
//             cout << "-----------------------------MENU--------------------------------------\n";
//             cout << "|1. View list of course.                                             |\n";
//             cout << "|2. View scoreboard                                                  |\n";
//             cout << "|3. Change password.                                                 |\n";
//             cout << "|4. View profile.                                                    |\n";
//             cout << "|5. Logout                                                           |\n";
//             cout << "------------------------------END-------------------------------------\n";

//             cout << "Please enter your choice. \n";
//             int Student_choice;
//             cin >> Student_choice;

//             switch (Student_choice)
//             {
//             case 1:
//                 viewListOfCourses_Student(Semester_head, Student_head);
//                 break;
//             case 2:
//                 ViewScoreBoardStudent(Year_head, User);
//                 break;
//             case 3:
//             {
//                 changePassword(User);
//                     if(User->Role == 1) SaveChangePassword(Staff_head);
//                     else SaveChangePassword(Student_head);
//                 break;

//             }
                
//             case 4:
//                 PrintProfile_Student(User, Year_head);
//                 break;
//             case 5:
                
//                 break;
//             default:
//                 cout << "Please re-check your choice.\n\n";
//                 break;
//             }
//             if (Student_choice == 5)
//                 break;
//         }
//     }
//     deleteAllLists(Year_head, Student_head ,Staff_head, Staff_info_head);
//     //delete User;
//     return 0;
// }