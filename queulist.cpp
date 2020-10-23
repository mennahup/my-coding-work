#include<iostream>
#define que_type int
using namespace std;
struct node{
    que_type data;
    node*next;
};

class queue{
 public:
 node*front;
 node*rear;
 int size;
 queue(){
     front=NULL;
     rear=NULL;
     size=0;
 }
bool append(que_type y){
    node *pn=new node;
    if(pn){
        cout<<"check if not null"<<endl;
      if(size==0){
          cout<<"case first"<<endl;
       front=pn;
       rear=pn;
       pn->data=y;
       pn->next=NULL;
     }
     else{
         cout<<"not first"<<endl;
         rear->next=pn;
         pn->data=y;
         rear=pn;
         pn->next=NULL;
     }
     size++;
     return 0;
    }
    else 
    return 1;     

    }

bool retrieve(que_type *pe){
    if(size!=0){
        cout<<"ret can occur"<<endl;
    node*pn=front;
    front=front->next;
    *pe=pn->data;
    free(pn);
    return 0;
    size--;
    }
    return 1;
}
bool empty(void){
    if(size==0)
    return 0;
    else 
    return 1;
}
bool full(void){
    return 0;
}
int quesize(void){
    return size;
}
void que_clear(void){
    if(size){
        node*pn;
        while(front){
        pn=front;
        front=front->next;
        free(pn);
        size--;
        }
    }
}
void print_reverse(void(*pf)(que_type v)){
    if(size){
        for(node*pn=front;pn!=NULL;pn=pn->next){
            (*pf)(pn->data);
        }
    }
}

};