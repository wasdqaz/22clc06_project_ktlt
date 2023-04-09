#include "header.h"
Course* FindCourse (SchoolYear* HeadOfYear)
{
    

    SchoolYear* curyear = HeadOfYear;
    string year;
    cout<<"Please enter begin year of SchoolYear contain course. Example: 21 (if that schoolYear is 2021-2022\n";

    cin>>year;
    string semester;
    cout<<"Please enter semester contain course. Ex: S1 (if semester is first semester)\n";
    cin>>semester;
    while(curyear && (curyear->BeginYear.compare(year) == 0))
    {
       curyear = curyear->NextYear;
    }
    if(!curyear)
    {
        cout<<"Not found schoolyear\n";
        return nullptr;
    }
    Semester* semesterCur;
    if(semester[1] == '1') semesterCur = curyear->S1;
    else if(semester[1] == '2') semesterCur = curyear->S2;
    else if(semester[1] == '3') semesterCur = curyear->S3;
    else{
        cout<<"semester invalid\n";
        return nullptr;
    }
    Course* curCourse = semesterCur->CourseList;
    string courseId;
    cout<<"Please enter Id course\n";
    cin>> courseId;
    while(curCourse && curCourse->CourseId ==courseId )
    {
        curCourse = curCourse->Next;
        
    } 
    if(!curCourse)
    {
        cout<<"Not found course\n";
        return nullptr;
    }
    return curCourse;





}
void ExportCourseToCSVFile(SchoolYear* head, string parentFolder)
{

    Course* cur =  FindCourse(head);
    Student* headOfStudent = cur->CourseStudent;
   std::string parentFolderName = "Data"; // replace with the name of the parent folder
    std::string subFolderName = "User_Output"; // replace with the name of the subfolder you want to create the file in
    std::string filePath;

    // Search for the parent folder
    for (const auto& entry : fs::directory_iterator(".")) {
        if (fs::is_directory(entry.status()) && entry.path().filename() == parentFolderName) {
            filePath = entry.path().string() + "/" + subFolderName + "/new_file.txt";
            break;
        }
    }

    // Check if the parent folder was found
    if (filePath.empty()) {
        std::cerr << "Parent folder not found!" << std::endl;
        return ;
    }

    std::ofstream file;

    // Open the file stream and check if it opened successfully
    file.open(filePath.c_str());
    if (!file.is_open()) {
        std::cerr << "Failed to create file!" << std::endl;
        return ;
    }

    // Write some data to the file
    file<<"ID Student,Name\n";
    while(headOfStudent)
    {
        file<<headOfStudent->Id<<","<<headOfStudent->Name<<endl;
        headOfStudent = headOfStudent->Next;
    }
    
    

    // Close the file stream
    file.close();

    

    
}