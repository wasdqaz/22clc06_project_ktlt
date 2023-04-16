#include "functionOfDuy.h"
#include "header.h"

void readStaffInfo(Staff *&pHead)
{
    ifstream fin;
    fin.open("Data/staff_info.txt");
    Staff *temp;
    string ID, Name, Gender, BD, S_ID;
    if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, ID);
            getline(fin, Name);
            getline(fin, Gender);
            getline(fin, BD);
            getline(fin, S_ID);

            if (pHead == nullptr) {
                pHead = new Staff;
                pHead->Id = ID;
                pHead->Name = Name;
                pHead->Gender = Gender;
                pHead->Birth = BD;
                pHead->Social_ID = S_ID;
                pHead->Next = nullptr;
                temp = pHead;
            }
            else {
                temp->Next = new Staff;
                temp->Next->Id = ID;
                temp->Next->Name = Name;
                temp->Next->Gender = Gender;
                temp->Next->Birth = BD;
                temp->Next->Social_ID = S_ID;
                temp->Next->Next = nullptr;
            }
        }
    }

    fin.close();
}