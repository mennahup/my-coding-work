//#pragma once
#include<iostream>
#include"stacklist.cpp"
void print_single(stack_input x){
   
    cout<<"value of user func"<<x<<endl;
}
int main(){
    cout<<"hello world"<<endl;
    Stack s;
    stack_input x;
    bool y;
    bool r;
    stack_init(&s);
    y=is_full(&s);
    if(!y){
        cout<<"the stack is full"<<endl;
        return 0;
    }
    for(int i=0;i<stack_size;++i){
       cout<<"i"<<i<<endl;
        push(i,&s);
    }
  /*  clear_stack(&s);
    r=empty(&s);
    if(!r){
        cout<<"stack is empty"<<endl;
        return 0;
    }
   for(int i=0;i<stack_size;++i){
        pop(&x,&s);
        cout<<"value of stack elements"<<x<<endl;
        if(!empty(&s)){
            cout<<"stack empty"<<endl;
            return 0;
        }
     cout<<"stack values"<<x<<endl;
    }
    */
 reverse_print(&s,&print_single);

/*push(2,&s);
stack_input x1;
pop(&x1,&s);
cout<<"x"<<x1<<endl;
stack_input y1;
pop(&y1,&s);
cout<<"y"<<y1<<endl;
*/

}