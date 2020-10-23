/*this is a general main function for queue ,stack with both array and linkedlist implementation ,however ,it is here implemented commands for stack list
if we want to try stack (array based implementation )we change only the included file 
we only should include the queue file we want and use the wanted methods call
*/
//#pragma once
#include<iostream>
#include"stacklist.cpp"
//#include"queuelist.cpp"
//#include"queuearr.cpp"
//#include"stackarr.cpp"
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
   reverse_print(&s,&print_single);
    clear_stack(&s);
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
    

}
