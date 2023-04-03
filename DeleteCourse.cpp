// #include"header.h"
// #include"KhoiFunction.h"
// void DeleteStudentInCourse(Student *&head){
//     Student *cur=head;
//     while (!head)
//     {
//         head=head->Next;
//         delete cur;
//         cur=head;
//     }
// }
// void DeleteMark(Mark *&head){
//     Mark *cur=head;
//     while (!head)
//     {
//         head=head->next;
//         delete cur;
//         cur=head;
//     }
// }
// void DeleteCourse(Course *&head){
//     string IdOFCourse;
//     cout<<"Please input course id you want to delete: ";
//     cin.ignore();
//     getline(cin, IdOFCourse);
//     Course *cur=head;
//     if(head->CourseId==IdOFCourse){
//         head=head->Next;
//         delete cur;
//         return;
//     }
//     while(cur->Next->CourseId!=IdOFCourse){
//         cur=cur->Next;
//     }
//     DeleteMark(cur->headMark);
//     DeleteStudentInCourse(cur->CourseStudent);
//     if(cur->Next==nullptr)delete cur;
//     else {
//         Course *tmp=cur->Next;
//         cur->Next=tmp->Next;
//         delete tmp;
//     }
// }