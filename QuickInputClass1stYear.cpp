#include "header.h"

void quickInputClass1stYear(SchoolYear *cur)
{
    Class *curclass = cur->ClassHead;
    string clss;
    cout << "Please enter name of class you want to upload: ";
    cin >> clss;
    while (curclass)
    {
        if (curclass->Name == clss)
            break;
        curclass = curclass->Next;
    }
    if (!curclass)
        return;
   

    string filePath = "Data/Input_User/" + clss + ".txt";
    InputStudent(curclass->StudentHead, filePath); // use function of Tran
    SaveClass1stYearToFolderSchoolYear(filePath, clss, cur);
}

void SaveClass1stYearToFolderSchoolYear(string input, string clss, SchoolYear *cur)
{
    std::string schoolYear = "SchoolYear";
    std::string year = cur->BeginYear + "-" + cur->EndYear;

    std::string folderPath = "Data/" + schoolYear + "/" + year + "/" + "Class";

    // Tạo đường dẫn đến file mới
    std::string newFilePath = folderPath + "/" + clss + ".txt";

    // Tạo file mới và viết nội dung vào file
    std::ofstream newFile(newFilePath);
    newFile.close();

    std::ifstream inputFile(input);
    std::ofstream outputFile(newFilePath);

    if (inputFile.is_open() && outputFile.is_open())
    {
        // Đọc toàn bộ nội dung của file cần copy
        std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

        // Ghi nội dung vào file mới
        outputFile << fileContent;

        std::cout << "File copied successfully!\n";
    }
    else
    {
        std::cerr << "Failed to copy file!\n";
    }

    // Đóng file
    inputFile.close();
    outputFile.close();
}
