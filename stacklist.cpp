#include<iostream>
#include"stc.h"
using namespace std;

Stack*top;
void stack_init(Stack*ps ){
    top=NULL;
}
bool is_full(Stack*ps){
    return 1;
}
bool empty(Stack*p){
    if(top==NULL)
     return 0;
    else 
      return 1;
}
bool push(stack_input y,Stack*ps ){
    Stack *n=new Stack;
    n->value=y;
    n->next=top;
    top=n;
    return 0;
}
bool pop(stack_input*pe,Stack*ps){
   if(top==NULL){
   cout<<"empty stack"<<endl;
    return 1;
   }
    else{
    *pe=top->value;
     Stack*pt=top;
     top=top->next;
      free(pt);
      return 0;
    }
}
void clear_stack(Stack*ps){
    Stack *pn;
   
    do{
    pn=top;
    cout<<"top"<<top<<endl;
    if(top==NULL)
     break;
    top=top->next;
    free(pn);
    }while(1);

}
void reverse_print(Stack*ps,void(*pf)(stack_input x)){
    while(top){
        (*pf)(top->value);
        top=top->next;
    }
}