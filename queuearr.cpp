#include<iostream>
using namespace std;
#define que_size 3
#define que_type int
class queue{
    public:
    que_type que_arr[que_size];
    int front;
    int rear;
    int size;
   
 
    queue(){
       front=0;
       rear=0;
       size=0;
   }
   void append(que_type t){
        if(size<que_size){
        que_arr[rear]=t;
     //   cout<<"tnfez"<<" t "<<t<<endl;
      //  cout<<"value "<<que_arr[rear]<<" rear "<<rear<<" front "<<front<<endl;
      //  cout<<"size app"<<size<<endl;
        rear=((rear+1)%que_size);
      //  cout<<"rear last"<<rear<<endl;
      // que_arr[rear]=t;
      // cout<<"after inclusion"<<" "<<que_arr[rear]<<" rear "<<rear<<" front "<<front<<endl;
        size++;
         cout<<"size app"<<size<<endl;
        }
        else{
         cout<<"no sufficient space"<<endl; 
        }
        
   }
   void retrieve (que_type*pe){
      // cout<<"check func"<<endl;
     // cout<<"front ret"<<front<<endl;
       *pe=que_arr[front];
     //  cout<<"currnt front"<<front<<endl;
     //  cout<<"size ret"<<size<<endl;
     //  cout<<"stored value"<<*pe<<endl;
      //  front++;
       front=((front+1)%que_size);
        size--;
   cout<<"size ret"<<size<<endl;
   }
   bool full(void){
       if(size==que_size)
       return 0;
       else 
       return 1;
   }
   int quesize(void){
       return size;
   }
   bool empty(void){
       if(size==0)
       return 0;
       else
       return 1;
   }
   void que_clear(void){
       front=0; 
       size=0;
       rear=0; 
   }
   void print_reverse(void(*pf)(que_type t)){
       cout<<"size"<<size<<endl;
       cout<<"front  "<<front<<endl;
       cout<<"rear   "<<rear<<endl;
     //  cout<<"check"<<check<<endl;
     if(size==que_size ){
      for(int i=front;i<que_size;++i){
           (*pf)(que_arr[i]);
      }
      for(int i=0;i<front;++i){
            (*pf)(que_arr[i]);
      }
     }
      else if(front>rear){
          for(int i=front;i<que_size;++i){
           (*pf)(que_arr[i]);
          }
      }
     
     else{
       for(int i=front;i<=rear;++i){
           cout<<"i"<<i<<endl;
           (*pf)(que_arr[i]);
       }
     }
   }
   void tryyyy (void){
       for(int i=0;i<que_size;++i){
           cout<<"arr content"<<que_arr[i]<<endl;
       }
   }


};