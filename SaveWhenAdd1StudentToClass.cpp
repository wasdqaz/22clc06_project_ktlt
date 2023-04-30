#include "header.h"
void SaveWhenAdd1StudentToClass(Student *add,Student*head, string classname, SchoolYear *cur)
{
    string year = cur->BeginYear + "-" + cur->EndYear;
    std::string schoolYear = "SchoolYear";

    std::string folderPath = "Data/" + schoolYear + "/" + year + "/Class";

    std::string FilePath = folderPath + "/" + classname + ".txt";
    ofstream out;
    out.open(FilePath, ios::app);

   out<<endl;
    out << add->No << "," << add->Id << "," << add->Name << "," << add->Gender << "," << add->DateOfBirth << ","<<add->SocialId;
    out.close();
}
