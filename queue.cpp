#include<iostream>
#include"queulist.cpp"
using namespace std;
void printelement(que_type w){
    cout<<"output element"<<w<<endl;
}
int main(){
    queue q;
    int x,s;
    bool y;
   
 // s= q.quesize();
 // cout<<"inital size"<<s<<endl;
   y = q. append(10);
    for(int i=0;i<5;++i){
       bool v= q. append(i+10); 
  }

     y=q.full();
     if(!y){
         cout<<"full"<<endl;
     }
    //  bool z=q. retrieve(&x);
     //  cout<<"appended value main"<<x<<endl;
  //    q.append(300);
 //    q.que_clear();
  s= q.quesize();
  cout<<"inital size"<<s<<endl;
/* for(int i=0;i<s;++i){
      bool u= q. retrieve(&x);
          cout<<"appended value main"<<x<<endl;
   }*/
   
  //  q. retrieve(&x);
  // cout<<"appended value main"<<x<<endl;
 /*  bool z;
   z=q.empty();
   if(!z){
       cout<<"empty"<<endl;
   }*/
//  q. tryyyy();
q. print_reverse(& printelement);

    return 0;
}