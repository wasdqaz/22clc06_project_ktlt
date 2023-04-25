#include "header.h"

void SaveChangePassword (Account* head)
{
    if(!head) return;
    ofstream out;
    if(head->Role == 1)
    {
        out.open("Data/staff.txt");
    }
    else out.open("Data/student.txt");
    if(!out.is_open()) return;
    while(head && head->next)
    {
        out<<head->username<<endl;
        out<<head->Password<<endl;
        head = head->next;
    }
    out<<head->username<<endl;
    out<<head->Password;
    out.close();

}