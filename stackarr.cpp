
#include<iostream>
#include"stc.h"
using namespace std;

//#define stack_input  int 
//#define stack_size 5

 /* Stack{
    stack_input stackarr[stack_size];
    int top;
};*/
void stack_init(Stack*ps ){
  ps->top=0;
}
bool pop(stack_input*pe,Stack*ps){
     ps->top--;
     (*pe)=ps->stackarr[ps->top];
}
bool push(stack_input y,Stack*ps ){
   ps->stackarr[ps->top]=y;
     ps->top++;
}
bool is_full(Stack*ps){
    if(ps->top >=stack_size)
    return 0;
    else 
    return 1;
}
bool empty(Stack*p){
    if(p->top==0)
    return 0;
    else
    return 1;
}
void reverse_print(Stack*ps,void(*pf)(stack_input )){
  //  ps->top--;
    for(int i=ps->top-1;i>=0;i--){
        (*pf)(ps->stackarr[i]);
    }
}

