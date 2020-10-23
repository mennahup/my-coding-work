#include<iostream>

using namespace std;
struct node{
int value;
node*next;
};
int no_nodes;
void insertlast(node**list){
    node*temp=*list;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node*last=new node;
    int v;
    cout<<"enter value"<<endl;
    cin>>v;
    last->value=v;
    last->next=NULL;
    temp->next=last;
}
void dellast(node**list){
   node*temp=*list;
   while(temp->next->next !=NULL){
       temp=temp->next;
   }
    free(temp->next->next);
    temp->next=NULL;
  

}
bool insert_node(node**list){
 bool x;
 int v;
 cout<<"where to insert "<<endl;
 cout<<"enter 0 if insert at beginig and 1 if insert in general position"<<endl;
 cin>>x;
 //insert at beginig
 if(!x){
     cout<<"got to point"<<endl;
    node*n= new node;
    //cout<<"ADRESS OF NEW NODE"<<n<<endl;
    if(n!=NULL){
       cout<<"enter the value"<<endl;
       cin>>v;
        n->value=v;
        n->next=*list;
      
        *list=n;
    
       
    }
     
 }
 //insert at first pos
 else{
  int pos;
  cout<<"enter certain position"<<endl;
   cin>>pos;
   if(pos>=no_nodes){
       cout<<"invalid"<<endl;
       return 1;
   }
  cout<<"enter value"<<endl;
  cin>>v;
  node *prev=NULL;
  node *te=*list;
  node*n=new node;
  n->value=v;
  for(int i=0;i<pos+1;i++){
      if(i==pos)
      prev=te;
      te=te->next;
  }
  n->next=te;
  prev->next=n;
 }
 return 0;

}

bool del_node(node**list){
   //delete node 
//delete from general index
   int pos;
    node* tem=*list;
    node*prev=NULL;
    node*index=NULL;
    cout<<"enter postion of node you want to delete"<<endl;
    cin>>pos;
    if(pos>=no_nodes){
       cout<<"invalid"<<endl;
       return 1;
   }
   /// //delete from beging
    if(pos==0){
        node*m=*(list);
        m=m->next;
        free(*list);
        *list=m;
    }
 else{
      //delete general point
       for(int i=0;i<pos+1;++i){
         if(i==pos-1){
          prev=tem;
         }
        if(i==pos){
           index=tem;
        }
        tem=tem->next;
       }
    
   //dlete last element
     if(tem==NULL){
        free(index);
        prev->next=NULL;
     }
    prev->next=tem;
    free(index);
    }
 return 0;

}
 void search_value(node**list){
     node*t=*list;
     int key;
     cout<<"enter the value you are searching for"<<endl;
     cin>>key;
     bool f;
     node*indx;
     for(node*t=*list;t!=NULL;t=t->next){
        // cout<<"search"<<endl;
         if(key==t->value){
            f=1;
            indx=t;
         }
     }
         if(f){
         bool g;
         cout<<"press 1 if you want to replace"<<endl;
         cin>>g;
          if(g){
             int re;
             cout<<"enter new value"<<endl;
             cin>>re;
             t=indx;
             t->value=re;
           }
         }
         else{
             cout<<"not found"<<endl;
         }
    
 }

int main(){
 cout<<"hello"<<endl;
 node*list=NULL;
 node*temp=NULL;


///////////////////////////// node creation for given no of nodes/////////////////////
 cout<<"enter no of nodes"<<endl;
 cin>>no_nodes;
//creat 5 nodes
for(int i=0;i<no_nodes;i++){
  // cout<<"where the prob is"<<endl;
    node*n=new node;
    n->value=i;
    if(i==0){
        list=n;
        temp=n;
    }
    temp->next=n;
    temp=n;

}

////////////////////////print created nodes////////////////////////////////////
 for(temp=list;temp!=NULL;temp=temp->next){
     cout<<"value stored"<<temp->value<<endl;
 }
 /////////////////////////////////////////////////////////////
 cout<<"choose operation you want 1 insert last 2 delete last 3 insert 4 delete 5 search"<<endl;
 int ch;
 cin>>ch;
 switch(ch){
     case(1):
     {
     insertlast(&list);
     break;
     }
     case(2):
     {
     dellast(&list);
     break;
     }
     case(3):
     {
     bool x=insert_node(&list);
     if(x)
     return 0;
     break;
     }
     case(4):
     {
     bool y=del_node(&list);
     break;
     }
     case(5):
     {
     search_value(&list);
     break;
     }
     default:
     cout<<"wrong entry"<<endl;
     break;

 };


  for(temp=list;temp!=NULL;temp=temp->next){
      cout<<"value stored"<<temp->value<<endl;
    }
  

  while(list!=NULL){
    cout<<"delete node"<<endl;
    node*t;
    t=list->next;
    free(list);
    list=t;
 }

}
