#include "header.h"

void SaveChangePassword (Account* head)
{
    if(!head) return;
    ofstream out;
    if(head->Role == 1)
    {
        out.open("staff.txt");
    }
    else out.open("student.txt");
    
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