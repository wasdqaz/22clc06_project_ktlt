#include "header.h"
#include "KhoiFunction.h"
#include "functionOfDuy.h"

int main(){
    Account *Student_head = nullptr;
    Account *Staff_head = nullptr;
    Account *User;
    int Role;

    createAccountList(Student_head,2);
    createAccountList(Staff_head,1);

    cout<<"You are student or staff.\n";
    cout<<"1. Staff\n";
    cout<<"2. Student\n";
    cin>>Role;
    
    if(Role==1){
        User=Login(Staff_head);
    }
    else {
        User=Login(Student_head);
    }

    while(true){
        

    }    
    return 0;
}