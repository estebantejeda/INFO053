#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Stack{

private:

    struct nodeStack{
    	int val;
    	nodeStack *next;
    }; typedef struct nodeStack nodoS;
    nodoS *S;

public:

   Stack();
   Stack(int num);
   ~Stack();

   void push(int);
   int pop();
   int top();
   int size();
   bool isEmpty();
   void display();
};

Stack::Stack(){
   cout << "Creando Pila..." << endl;
   S = NULL;
}

Stack::Stack(int num){
   S = new nodoS;
   S->val = num;
   S->next = NULL;
}

Stack::~Stack(){
   nodoS *p;
   while(S != nullptr){
      p = S;
      S = S->next;
      delete p;
   }
}

void Stack::push(int num){
   nodoS *p = new nodoS;
   p->val = num;
   p->next = S;
   S = p;
}

int Stack::pop(){
   int k = -1;
   if(S == nullptr){
      cout << "ERROR!" <<endl;
      return k;
   }
   else{
      k = S->val;
      nodoS *p = S;
      S = S->next;
      delete p;
      return k;
   }
}

void Stack::display(){
   nodoS *p = S;
   while(p != nullptr){
      cout << p->val << " ";
      p = p->next;
   }
   cout << endl;
}

int Stack::top(){
   if(S == nullptr){
      cout << "ERROR!" <<endl;
      return -1;
   }
   return S->val;
}

int Stack::size(){
   int x = 0;
   nodoS *p = S;
   while(p != nullptr){
      x++;
      p = p->next;
   }
   return x;
}

bool Stack::isEmpty(){
   if(S == nullptr){
      return true;
   }
   else{
      return false;
   }
}
