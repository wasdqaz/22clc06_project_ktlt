#include "header.h"
#include "KhoiFunction.h"

void DeleteStudentInCourse(Student *&head)
{
    Student *cur = head;
    while (!head)
    {
        cur = cur->Next;
        DeleteMark(head->HeadOfMark);
        delete head;
        head = cur;
    }
}

void DeleteMark(Mark *&head)
{
    if (!head->Next && !head->Prev)
    {
        delete head;
        return;
    }

    if (head->Prev != nullptr)
        head->Prev->Next = head->Next;

    if (head->Next != nullptr)
        head->Next->Prev = head->Prev;

    delete head;
}
bool checkCourse(Course *head, string Course_id, string Class_name, Course *&cur_course)
{
    if (head->CourseId == Course_id && head->ClassName == Class_name)
    {
        return true;
    }
    Course *cur = head;
    while (cur->Next != nullptr)
    {
        if (cur->Next->CourseId == Course_id && cur->Next->ClassName == Class_name)
        {
            cur_course = cur;
            return true;
        }
        else
            cur = cur->Next;
    }
    return false;
}

void DeleteCourse(Course *&head)
{
    string Course_id, Class_Name;
    while (true)
    {
        cout << "Please enter ID of course you want to delete: ";
        cin.ignore();
        getline(cin, Course_id);
        cout << "Please enter the class name of course: ";
        getline(cin, Class_Name);
        Course *cur = head;

        if (checkCourse(head, Course_id, Class_Name, cur))
        {

            int choice = MenuYN("Do you want to delete course?");
            
            if (choice == 2)
                return;
                
            // hàm checkCoures sẽ trả con trỏ cur về trc Node Course cần xóa.
            // Nếu Course cần xóa ở đầu thì sẽ trả về head;
            if (cur == head)
            {
                DeleteStudentInCourse(cur->CourseStudent);
                Remove_File_Course(cur);
                cur = cur->Next;
                delete head;
                head = cur;
                cout << "Delete the course successfully.\n";
                return;
            }
            else
            {
                Course *tmp = cur->Next;
                DeleteStudentInCourse(tmp->CourseStudent);
                Remove_File_Course(tmp);
                cur->Next = tmp->Next;
                delete tmp;
                cout << "Delete the course successfully.\n";
                return;
            }
        }
        else
        {      
            int choice = MenuYN("Don't find course name. Do you  want to re-enter?");
            if (choice == 2)
                return;
        }
    }
}
