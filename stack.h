#ifndef _stack_H_
#define _stack_H_
#include <string>
using namespace std;
struct Node
{
	string data;
	Node* next;
};

struct Stack
{
	Node* head;
	

};
void  init(Stack& s);
void push(Stack& s, string x);
bool pop(Stack& s);
string top (Stack s);
bool isEmpty(Stack s);
void empty(Stack& s);
int size(Stack s);
#endif
