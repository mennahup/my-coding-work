//#pragma once
#define stack_input  int 
#define stack_size 5
 /* struct Stack{
    stack_input stackarr[stack_size];
    int top;
};*/
struct Stack{
     stack_input value;
      Stack * next;
};
void stack_init(Stack*ps );
bool pop(stack_input*pe,Stack*ps);
bool push(stack_input y,Stack*ps );
bool is_full(Stack*ps);
bool empty(Stack*p);
void reverse_print(Stack*ps,void(*pf)(Stack*ps));
void clear_stack(Stack*ps);
