#include "header.h"
void CreateFileClass(string year, string classname)
{
   
    string schoolYear = "SchoolYear";

    string folderPath = "Data/" + schoolYear + "/" + year + "/Class";

    string FilePath = folderPath + "/" + classname + ".txt";
    ofstream out;
    out.open(FilePath);
    out<<"No,ID,Name,Date Of Birth,Social ID";
    out.close();

}