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


    string directoryPath = "SchoolYear";
    Course *curCourse = nullptr;
    Class *curClass = nullptr;
    SchoolYear *curYear = nullptr;
    printDirectory(directoryPath, 0, curCourse, curClass, Year_head, curYear);
    //AccessFileMark(directoryPath, Year_head);

    cout<<"You are student or staff.\n";
    cout<<"1. Staff\n";
    cout<<"2. Student\n";
    cin>>Role;
    
    if(Role==1){
        User=Login(Staff_head);
        User->Role=Role;
    }
    else {
        User=Login(Student_head);
        User->Role=Role;
    }
    
    string Begin_Year;
    cout<<"Please input school year.\n";    
    cout<<"20--(PLease enter two last digits of year. Ex: 22( 2022),...)\n";
    cin>>Begin_Year;//happy case
    
 
    while(true){
        if(User->Role == 1){
            cout<<"\n-----------------------------MENU-------------------------------------\n";
            cout<<"|1. Create school year.                                              |\n";
            cout<<"|2. Create class.                                                    |\n";//can lam them
            cout<<"|3. Add student.                                                     |\n";//can fix
            cout<<"|4. Create semester.                                                 |\n";
            cout<<"|5. Add course.                                                      |\n";//can fix
            cout<<"|6. Upload file student list for course.                             |\n";//chua co
            cout<<"|7. Update course information.                                       |\n";
            cout<<"|8. Add a student to the course.                                     |\n";
            cout<<"|9. Remove a student from the course.                                |\n";
            cout<<"|10. Delete course.                                                  |\n";
            cout<<"|11. View a list of classes.                                         |\n";
            cout<<"|12. View a list of students in a class.                             |\n";
            cout<<"|13. View a list of courses.                                         |\n";
            cout<<"|14. View a list of students in a course.                            |\n";
            cout<<"|15. Export a list of students in a course to a CSV file.            |\n";
            cout<<"|16. Import the scoreboard of a course.                              |\n";
            cout<<"|17. Update a student's result.                                      |\n";
            cout<<"|18. View the scoreboard of a class.                                 |\n";
            cout<<"|19. View the scoreboard of a course.                                |\n";
            cout<<"|20. Logout                                                          |\n";
            cout<<"------------------------------END-------------------------------------\n";
            

            int Staff_Choice;
            cout<<"Please enter your choice. \n";
            cin>>Staff_Choice;
            switch (Staff_Choice)
            {
            case 1:
                AddNewYear(Year_head);
                break;
            case 2:
                
                break;
            case 3:
                //AddNewStudent();
                break;
            case 4:

                Semester_head = AddNewSemester(Year_head);
                break;
            case 5:
                // Semester 
                // AddCourse(Year_head->S1);
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 9:
                
                break;
            case 10:
                
                break;
            case 11:
                
                break;
            case 12:
                
                break;
            case 13:
                
                break;
            case 14:
                
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
                
                break;
            case 20:
                
                break;    
            default:
                cout<<"Please re-check your choice.\n\n";
                break;
            }
            if(Staff_Choice==20)break;
        }
        else {
            cout<<"\n-----------------------------MENU----------------------------------\n";
            cout<<"1. View list of course.\n";
            cout<<"2. View scoreboard\n";
            cout<<"3. Change password.\n";
            cout<<"4. Logout\n";
            cout<<"\n------------------------------END----------------------------------\n";

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
                
                break;
            default:
                cout<<"Please re-check your choice.\n\n";
                break;
            
            }
            if(Student_choice == 4)break;
        }
    }    
    return 0;
}