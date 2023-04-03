// #include "header.h"
// void Inputcourse(Course *&headCourse, string FileName){
//     Course *Cur_Course=headCourse;
//     ifstream fin (FileName);
//     while(Cur_Course){
//         getline(fin, Cur_Course->CourseId);
//         getline(fin, Cur_Course->CourseName);
//         getline(fin, Cur_Course->ClassName);
//         getline(fin, Cur_Course->TeacherName);
//         getline(fin, Cur_Course->Session);
//         getline(fin, Cur_Course->DayOfWeek);
//         Cur_Course->headMark=new Mark;
//         Mark *Cur_Student=Cur_Course->headMark;
//         while(Cur_Student){
//             fin>>Cur_Student->Id;
//             if(Cur_Student->Id=="-1")break;
//             fin>>Cur_Student->TotalMark;
//             fin>>Cur_Student->FinalMark;
//             fin>>Cur_Student->MidtermMark;
//             fin>>Cur_Student->OtherMark;
//             fin>>Cur_Student->Gpa;
//             Cur_Student->next=new Mark;
//             Cur_Student=Cur_Student->next;
//         }

//         Cur_Course=Cur_Course->Next;
//     }
//     fin.close();
// }
// //chua chay thu luon
