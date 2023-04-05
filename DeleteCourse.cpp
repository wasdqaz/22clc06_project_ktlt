#include"header.h"
#include"KhoiFunction.h"
void DeleteStudentInCourse(Student *&head){
    Student *cur=head;
    while (!head)
    {
        head=head->Next;
        delete cur;
        cur=head;
    }
}
void DeleteMark(Mark *&head);
void DeleteCourse(Course *&head){
    string Course_id;
    cout<<"Please enter course you want to delete: ";
    cin.ignore();
    getline(cin, Course_id);
    Course *Cur_course=head;

    if(head->CourseId==Course_id){
        head=head->Next;
        //DeleteMark(Cur_course->)
    }



    //while(Cur_course)
}


