#include "header.h"

string ImportScoreboardFromFileUser(SchoolYear *headOfyear)
{
    string idCourse, classname;
    cout << "Please enter id course:\n";
    cin >> idCourse;
    cout << "Please enter classname: ";
    cin >> classname;
    string fileName;
    fileName = "mark_" + idCourse + "_"+ classname + ".txt";

    string parentFolderName = "Data";    // replace with the name of the parent folder
    string subFolderName = "Input_User"; // replace with the name of the subfolder containing the file

    string filePath = "Data/Input_User/" + fileName;

    

   
    InputMarkForStudent(headOfyear, filePath);

    
   
    return filePath;
}
