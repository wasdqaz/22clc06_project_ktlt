#include "stack.h"
#include <iostream>
using namespace std;

void  init(Stack& s)
{
	s.head = nullptr;
	
}
int size(Stack s)
{
	int cnt = 0;
	while (s.head)
	{
		s.head = s.head->next;
		cnt++;
	}
	return cnt;
}
void push(Stack& s, string x)
{
	

	Node* newNode = new Node;
	newNode->data = x;
	
	newNode->next = s.head;
	s.head = newNode;
	
}
bool pop(Stack& s)
{
	if (!s.head)
	{
        
		return false;
	}
	Node* deleteNode = s.head;
	string x = s.head->data;
	s.head = s.head->next;
	delete deleteNode;
	
	return true;

}
string top (Stack s)
{
    if(s.head == nullptr) return"";
    return s.head->data;

}
bool isEmpty(Stack s)
{
	if (!s.head ) return true;
	return false;
}
void empty(Stack& s)
{
	while (s.head)
	{
		pop(s);
	}
}