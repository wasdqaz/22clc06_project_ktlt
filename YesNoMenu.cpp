#include "header.h"
#include "KhoiFunction.h"

string menuYN[] = {"Yes.", "No."};
const int max_list = 2;

int MenuYNChangePass(string pass)
{
    int pointer = 0;
    int flag = 0;
    while (true)
    {
        system("cls");
        cout << "Are you sure to change passwork to: " << pass << endl;
        for (int i = 0; i < max_list; i++)
        {

            if (pointer == i)
            {
                TextColor(1);
                cout << ">> " << menuYN[i] << " <<" << endl;
                TextColor(7);
            }
            else
                cout << "[+]" << menuYN[i] << endl;
        }
        while (true)
        {
            if (kbhit())
            {
                char key = getch();
                if (key == 80)
                {
                    if (pointer < max_list - 1)
                        ++pointer;
                    else
                        pointer = 0;
                    break;
                }
                if (key == 72)
                {
                    if (pointer > 0)
                        --pointer;
                    else
                        pointer = max_list - 1;
                    break;
                }
                if (key == 13)
                {
                    switch (pointer)
                    {
                    case 0:
                        return 1;
                        break;
                    case 1:
                        return 2;
                    default:
                        break;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

int MenuYN(string comment)
{
    int pointer = 0;
    int flag = 0;
    while (true)
    {
        system("cls");
        cout << comment <<endl;
        for (int i = 0; i < max_list; i++)
        {

            if (pointer == i)
            {
                TextColor(1);
                cout << ">> " << menuYN[i] << " <<" << endl;
                TextColor(7);
            }
            else
                cout << "[+]" << menuYN[i] << endl;
        }
        while (true)
        {
            if (kbhit())
            {
                char key = getch();
                if (key == 80)
                {
                    if (pointer < max_list - 1)
                        ++pointer;
                    else
                        pointer = 0;
                    break;
                }
                if (key == 72)
                {
                    if (pointer > 0)
                        --pointer;
                    else
                        pointer = max_list - 1;
                    break;
                }
                if (key == 13)
                {
                    switch (pointer)
                    {
                    case 0:
                        return 1;
                        break;
                    case 1:
                        return 2;
                    default:
                        break;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}