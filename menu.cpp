#include "header.h"
#include "KhoiFunction.h"
#include "functionOfDuy.h"

// #define time;

int main(){
    Account *Student_head = nullptr;
    Account *Staff_head = nullptr;
    Account *User;
    Semester *Semester_head=nullptr;
    SchoolYear *Year_head=nullptr;
    int Role;

    createAccountList(Student_head,2);
    createAccountList(Staff_head,1);


    string directoryPath = "Data/SchoolYear";
    Course *curCourse = nullptr;
    Class *curClass = nullptr;
    SchoolYear *curYear = nullptr;
    ReadDirectory(directoryPath, curCourse, curClass, Year_head, curYear);
    AccessFileMark(directoryPath, Year_head);



//-------------------------------------login--------------------------------
    cout<<"You are student or staff.\n";
    cout<<"1. Staff\n";
    cout<<"2. Student\n";
    cin>>Role;
    string clss;
    if(Role==1){
        User=Login(Staff_head);
    }
    else {
        User=Login(Student_head);
        clss = User -> Class;
    }
   
    

//------------------------------------login-------------------------------------- 
    // string Begin_Year;
    // cout<<"Please input school year.\n";    
    // cout<<"20--(PLease enter two last digits of year. Ex: 22( 2022),...)\n";
    // cin>>Begin_Year;
    // while (Year_head && Year_head -> BeginYear != Begin_Year)
    // {
    //     Year_head = Year_head -> NextYear;
    // }
    
    Semester_head = defaultSemester(Year_head);    
//---------------------------------------------------------------------------------
    while(true){
        if(User->Role == 1){
            cout<<"\n-----------------------------MENU-------------------------------------\n";
            cout<<"|0. Change the password.                                             |\n";                                               cout<<"|1. Create school year.                                              |\n";
            cout<<"|1. Add year.                                                        |\n";
            cout<<"|2. Create class.                                                    |\n";
            cout<<"|3. Add student.                                                     |\n";
            cout<<"|4. Create semester.                                                 |\n";
            cout<<"|5. Add course.                                                      |\n";
            cout<<"|6. Upload file student list for course.                             |\n";//chua co
            cout<<"|7. Update course information.                                       |\n";
            cout<<"|8. Add a student to the course.                                     |\n";
            cout<<"|9. Remove a student from the course.                                |\n";
            cout<<"|10. Delete course.                                                  |\n";//can fix
            cout<<"|11. View a list of classes.                                         |\n";
            cout<<"|12. View a list of students in a class.                             |\n";
            cout<<"|13. View a list of courses.                                         |\n";
            cout<<"|14. View a list of students in a course.                            |\n";
            cout<<"|15. Export a list of students in a course to a CSV file.            |\n";
            cout<<"|16. Import the scoreboard of a course.                              |\n";
            cout<<"|17. Update a student's result.                                      |\n";
            cout<<"|18. View the scoreboard of a class.                                 |\n";
            cout<<"|19. View the scoreboard of a course.                                |\n";
            cout<<"|20. View profile.                                                   |\n";
            cout<<"|21. Logout.                                                         |\n";
            cout<<"------------------------------END-------------------------------------\n";
            

            int Staff_Choice;
            cout<<"Please enter your choice. \n";
            cin>>Staff_Choice;
            switch (Staff_Choice)
            {
            case 0:
            {
                changePassword(User);
                break;
            }
            case 1:
                AddNewYear(Year_head);
                break;
            case 2:
                CreateClass(Year_head);//can update
                break;
            case 3:
                AddNewStudent(Year_head);
                break;
            case 4:
                Semester_head = AddNewSemester(Year_head);
                break;
            case 5:
                AddCourse(Year_head, Semester_head);
                break;
            case 6:
                
                break;
            case 7:
                UpdCourseInf(Semester_head->CourseList);
                break;
            case 8:
                AddStudentToCourse(Semester_head->CourseList);
                break;
            case 9:
                RmStudentFrCourse(Semester_head->CourseList);
                break;
            case 10:
                DeleteCourse(Semester_head->CourseList);
                break;
            case 11:
                viewClass(Year_head);
                break;
            case 12:
                viewStudentClass(Year_head);
                break;
            case 13:
                ViewListOfCourse(Semester_head->CourseList);
                break;
            case 14:
                viewStudentsInCourse(Semester_head->CourseList);
                break;
            case 15:
                
                break;
            case 16:
                
                break;
            case 17:
                
                break; 
            case 18:
                
                break;
            case 19:
                viewCourseScoreboard(Semester_head->CourseList);
                break;
            case 20:
                
                break;
            case 21:
                //logout.
                break;    
            default:
                cout<<"Please re-check your choice.\n\n";
                break;
            }
            if(Staff_Choice == 21)break;
        }
        else {
            cout<<"\n-----------------------------MENU-------------------------------------\n";
            cout<<"|1. View list of course.                                             |\n";
            cout<<"|2. View scoreboard                                                  |\n";
            cout<<"|3. Change password.                                                 |\n";
            cout<<"|4. View profile.                                                    |\n";
            cout<<"|5. Logout                                                           |\n";
            cout<<"------------------------------END-------------------------------------\n";


            cout<<"Please enter your choice. \n";
            int Student_choice;
            cin>>Student_choice;

            switch (Student_choice)
            {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                PrintProfile_Student(User, Year_head);
                break;
            case 5:

                break;
            default:
                cout<<"Please re-check your choice.\n\n";
                break;
            
            }
            if(Student_choice == 5)break;
        }
    } 
    deleteAllLists (Year_head, Student_head, Staff_head);
    delete User;
    return 0;
}