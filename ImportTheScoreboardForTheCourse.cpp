#include "header.h"
void ImportScoreboardFromFileUser (SchoolYear* headOfyear) 
{
    string idCourse;
    cout<<"Please enter id course:\n";
    cin>>idCourse;
    string fileName;
    fileName = "Input_mark_"+ idCourse;

     std::string parentFolderName = "Data"; // replace with the name of the parent folder
std::string subFolderName = "User_Input"; // replace with the name of the subfolder containing the file


std::string filePath;

// Search for the parent folder
for (const auto& entry : fs::directory_iterator(".")) {
    if (fs::is_directory(entry.status()) && entry.path().filename() == parentFolderName) {
        // Search for the subfolder
        for (const auto& subentry : fs::directory_iterator(entry.path())) {
            if (fs::is_directory(subentry.status()) && subentry.path().filename() == subFolderName) {
                // Search for the file
                for (const auto& file : fs::directory_iterator(subentry.path())) {
                    if (fs::is_regular_file(file.status()) && file.path().filename() == fileName) {
                        filePath = file.path().string();
                        break;
                    }
                }
                break;
            }
        }
        break;
    }
}

// Check if the file was found
if (filePath.empty()) {
    std::cerr << "File not found!" << std::endl;
    return;
}
InputMarkForStudent(headOfyear,filePath);

}