#include "header.h"
void SaveScorboardToFolderSchoolyear(string input)
{
    ifstream in;
    in.open(input);
    if(!in.is_open())
    {
        return;
        in.close();
    }
    string year;
    in >> year;
    string semester;
    in >> semester;
    if(semester[1] == '1') semester = "Semester01";
    else if(semester[1] == '2') semester = "Semester02";
    else semester  = "Semester03";
    string courseid;
    in >> courseid;
    
    string coursename;
    in >> coursename;

    string classname;
    in >> classname;
    in.close();
    std::string schoolYear = "SchoolYear";

    std::string folderPath = ".\\Data\\" + schoolYear + "\\" + year + "\\" + semester + "\\" + coursename;

    // Tạo folder mới nếu chưa tồn tại
    _mkdir(folderPath.c_str());
    string filename = "\\mark_" + classname + "_" + courseid + ".txt";

    // Tạo file mới và ghi dữ liệu vào đó
    std::ofstream newFile(folderPath + filename);
    newFile.close();
    string filePath = folderPath + filename;
    // Đọc toàn bộ nội dung của file cần copy và ghi vào file mới
    std::ifstream sourceFile(input, std::ios::binary);
    std::ofstream destinationFile(filePath, std::ios::binary);

    if (sourceFile.is_open() && destinationFile.is_open())
    {
        // Đọc toàn bộ nội dung của file cần copy
        std::string fileContent((std::istreambuf_iterator<char>(sourceFile)), std::istreambuf_iterator<char>());

        // Ghi nội dung vào file mới
        destinationFile << fileContent;

        std::cout << "File copied successfully!\n";
    }
    else
    {
        std::cerr << "Failed to copy file!\n";
    }

    // Đóng file
    sourceFile.close();
    destinationFile.close();
}
