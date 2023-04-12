#include "header.h"

void ImportScoreboardFromFileUser(SchoolYear *headOfyear)
{
    string idCourse;
    cout << "Please enter id course:\n";
    cin >> idCourse;
    string fileName;
    fileName = "Input_mark_" + idCourse;

    std::string parentFolderName = "Data";    // replace with the name of the parent folder
    std::string subFolderName = "User_Input"; // replace with the name of the subfolder containing the file

    std::string filePath;

    // Search for the parent folder
    _finddata_t parentFolder, subFolder;
    intptr_t parentHandle, subHandle;
    parentHandle = _findfirst(parentFolderName.c_str(), &parentFolder);
    if (parentHandle == -1)
    {
        std::cerr << "Parent folder not found!" << std::endl;
        return;
    }

    // Search for the subfolder
    std::string subFolderPath = parentFolderName + "\\" + subFolderName;
    subHandle = _findfirst(subFolderPath.c_str(), &subFolder);
    if (subHandle == -1)
    {
        std::cerr << "Subfolder not found!" << std::endl;
        _findclose(parentHandle);
        return;
    }

    // Search for the file
    std::string searchPattern = subFolderPath + "\\" + fileName + ".*";
    _finddata_t file;
    intptr_t handle = _findfirst(searchPattern.c_str(), &file);
    if (handle == -1)
    {
        std::cerr << "File not found!" << std::endl;
        _findclose(subHandle);
        _findclose(parentHandle);
        return;
    }

    filePath = file.name;

    // Process the file
    InputMarkForStudent(headOfyear, filePath);

    // Release resources
    _findclose(handle);
    _findclose(subHandle);
    _findclose(parentHandle);
}
