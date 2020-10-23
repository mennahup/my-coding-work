//this code implement graph data structures using the idea of linked list
#include<iostream>
using namespace std;
struct node{
    char vertix;
    node *next;
};
struct edge{
     int weight;
     node* ind1;
     node* ind2;
     edge* next;
};
node *s;
class graph{
    public:
    int size;
    node *s;
    edge *d;
     graph(){
         cout<<"graph init"<<endl;
         s=NULL;
         d=NULL;
     }
    node* add_vertix (char v){
         if(s==NULL){
           node* r=new node;
            r->vertix=v;
            s=r; 
            cout<<"first node"<<s->vertix<<endl; 
            return s;
         }
         else{
             node* temp;
             temp=s;
             node* r=new node;
             r->vertix=v;
            while(temp->next){
                temp=temp->next;
            }
             temp->next=r;
             cout<<"node v"<<r->vertix<<"prev node v"<<temp->vertix<<endl;
             return r;
         }
    }
    void add_edge (node*a,node*b,int w){
       if(!d){
        d=new edge;
        d->weight=w;
        d->ind1=a;
        d->ind2=b;
        d->next=NULL;
       }
       else{
         edge *temp=d;
        while(temp->next){
           temp=temp->next;
        }
          edge *r=new edge;
          r->weight=w;
          r->ind1=a;
          r->ind2=b;
          cout<<"created edge"<<r->weight<<endl;
          cout<<"root value"<<d->weight<<endl;
          temp->next=r;
       }
        
    }
    void display_edge(void){
        
        for(edge*temp=d;temp!=NULL;temp=temp->next){
           cout<<"temp "<<temp<<endl;
           cout<<"V1 V2 WEIGHT "<<temp->ind1->vertix<<" "<<temp->ind2->vertix<<" "<<temp->weight<<endl;
           
        }
    }
    void display_node(void){
       
        for(node*t=s;t!=NULL;t=t->next){
            cout<<"node"<<t->vertix<<endl;
        }
    }     
};
int main(){
    graph g;
    node * r1;
    node * r2;
    node* r3;
    edge*y;
   r1=g.add_vertix ('A');
   r2=g.add_vertix ('b');
   r3=g.add_vertix ('c');
   g.display_node();
   g.add_edge(r1,r2,2);
   g.add_edge(r2,r3,3);
   g.add_edge(r1,r3,5);
   g.display_edge();

    return 0;
}
