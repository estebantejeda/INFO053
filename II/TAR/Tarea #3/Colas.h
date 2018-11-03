#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Queue{

private:

    struct nodeQueue{
    	int val;
    	nodeQueue *next;
    }; typedef struct nodeQueue nodoQ;
    nodoQ *Q;

public:
     
   Queue();
   Queue(int num);
   ~Queue();

   void enqueue(int);
   int dequeue();
   int front();
   int last();
   int size();
   bool isEmpty();
   void display();
};

Queue::Queue(){
   cout << "Creando Cola..." << endl;
   Q = NULL;
}

Queue::Queue(int num){
   Q = new nodoQ;
   Q->val = num;
   Q->next = NULL;
}

Queue::~Queue(){
   nodoQ *p;
   while(Q != NULL){
      p = Q;
      Q = Q->next;
      delete p;
   }
}


void Queue::enqueue(int num){
   nodoQ *p = new nodoQ;
   p->val = num;
   p->next = Q;
   Q = p;
}

int Queue::dequeue(){
   int k = -1;
   nodoQ *p = Q;
   nodoQ *q = Q;
   if(Q == NULL){
      cout << "ERROR!" <<endl;
      return k;
   }
   else{
      while(p->next != NULL){
         q = p;
         p = p->next;
      }
      k = p->val;
      q->next = NULL;
      delete p;
      return k;
   }
}

int Queue::front(){
   nodoQ *p = Q;
   if(Q == NULL){
      cout << "ERROR!" <<endl;
      return -1;
   }
   else{
      while(p->next != NULL){
         p = p->next;
      }
   }
   return p->val;
}

int Queue::last(){
   if(Q == NULL){
      cout << "ERROR!" <<endl;
      return -1;
   }
   else{
   return Q->val;
   }  
}

int Queue::size(){
   int x = 0;
   nodoQ *p = Q;
   while(p != NULL){
      x++;
      p = p->next;
   }
   return x;
}

bool Queue::isEmpty(){
   if(Q == NULL){
      return true;
   }
   else{
      return false;
   }
}

void Queue::display(){
   nodoQ *p = Q;
   while(p != NULL){
      cout << p->val << " ";
      p = p->next;
   }
   cout << endl;
}
