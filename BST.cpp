#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node * root;
int size;
int debth;
 node* tree(int y){
    root=new node;
    size++;
    root->data=y;
    root->left=NULL;
    root->right=NULL;
    cout<<"saved value"<<root->data<<endl;
    return root;
 }
node* creat_node(int x){
    node* pn=new node;
    pn->left=NULL;
    pn->right=NULL;
    pn->data=x;
    return pn;
}
node* insert(node* pn,int x){
    if(!pn){
        cout<<"creat node"<<endl;
        size++;
        return creat_node(x);
    }
    else if(pn->data > x){
        cout<<"going left from"<<pn->data<<endl;
        pn->left=insert(pn->left,x);
    }
    else{
        cout<<"going rigth from"<<pn->data<<endl;
        pn->right=insert(pn->right,x);
    }
}
void lvr(node*r){
  
   if(r){
    cout<<"con"<<endl;
    lvr(r->left);
    cout<<"value"<<r->data<<endl; 
    lvr(r->right); 
   }
}
node* minrighttree(node*r){
    int min=1000;   //very large number
    if(r->data <min){
        min=r->data;
        cout<<"min no stored in the right branch"<<min<<endl;
        return r;
    }
    r=minrighttree(r->right);
}
void dele_value(node*r,int v){
static  node *p;
  static bool d;
    if(r){
        if(r->data >v){
            if(r->left->data==v){
                p=r;
                cout<<"last un deleted value"<<p->data<<endl;
                d=1;
              //  free(r->left);
              //  p->left=NULL;
               }
            
            dele_value(r->left,v);
        }
        else if(r->data <v){
            if(r->right->data==v){
                 p=r;
                cout<<"last un del value"<<p->data<<endl;
              //  d=0;
              //  free(r->right);
              //  p->right=NULL;
            }
            dele_value(r->right,v);
        }
        else{
           if(r->left==NULL && r->right==NULL){
             cout<<"free region"<<endl;
              free(r);
              size--;
              cout<<"p data"<<p->data<<endl;
           //   if(d)
              p->left=NULL;
           //   else
              p->right=NULL;
              
 
           }
           else {
               // d=1 left d=2 right 
               if(r->left && !r->right){
                   r->data=r->left->data;
                   free(r->left);
                   size--;
                   r->left=NULL;
                   cout<<"p dataa left"<<p->data<<endl;
                   
               }
               else if(r->right && !r->left){

                   r->data=r->right->data;
                   free(r->right);
                   size--;
                   r->right=NULL;
                   cout<<"p dataa right"<<p->data<<endl;
                   
               }
               else if(r->right&&r->left){
                   cout<<"node left"<<r->left->data<<endl;
                   cout<<"node right"<<r->right->data<<endl;
                   cout<<"node right right"<<r->right->right->data<<endl;
                 p=minrighttree(r->right);
                 cout<<"min p data"<<p->data<<endl;
                 r->data=p->data;
                 r->right=p->right;
                // r->left=p->left;
                 free(p);
                 size--;
                   
               }
                  
           }
           
        }
        
    }
}
int debth_tree(node*r){
  static  int dl,dr;
  static bool d;
    if(r){
       // cout<<"ifffffffffffffff"<<endl;
       if(!d){
        dl++;
        cout<<"dl"<<dl<<endl;
        debth_tree(r->left);
       }
    }  
    return dl;  
}
int min_dbth(node *r){
    int dl,dr;
   dl= debth_tree(r->left);
   cout<<"dl min"<<dl<<endl;
   dr= debth_tree(r->right);
   cout<<"dr min"<<dr<<endl;
   if(dl>dr)
    return dl+1;
    else 
    return dr+1;
}

int main(){
node *r= tree(6);
r=insert(r,2);
cout<<"returned value"<<r->data<<endl;
r=insert(r,7);
cout<<"returned value"<<r->data<<endl;
r=insert(r,1);
r=insert(r,10);
r=insert(r,3);
//r=insert(r,11);
//lvr(r);
//r=minrighttree(r);
//dele_value(r,10);
//dele_value(r,6);
//debth=min_dbth(r);
//cout<<"tree debth"<<debth<<endl;
//lvr(r);
//cout<<"sy hello world"<<endl;



    return 0;
}