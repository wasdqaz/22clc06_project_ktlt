#include "header.h"
#include "functionOfDuy.h"
#include "KhoiFunction.h"

int main()
{
    while (true)
    {
        int role = LoginConsole();
        if (role == 0)
            return 0;
        
        if (role == 1)
        {
            STAFF_MENU();
        }
        else
        {
            STUDENT_MENU();
        }
    }

    return 0;
}
