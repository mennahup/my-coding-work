#include<iostream>
using namespace std;
#define tree_type int
struct node{
    tree_type data;
    node * left;
    node *right;
};

class tree{
    public:
     node * root;
     int size;
     int debth;
     tree(){
      size=0;
      root=NULL;
   }
   tree(int pe){
       
       data=pe;
       left=NULL;
       right=NULL;
   }
  void empty_tree(void){
       if(!root)
       cout<<"empty tree"<<endl;
   } 
   tree* insert(tree*root,int pe){
      if(!root){
        return tree(pe);
      }
    else if(root->data > pe){
       root->left=insert(root->left,pe);
      }
       else{
         root->right= insert(root->right,pe);
      }
      size++;
   }
  void read(tree* root){
       cout<<"data"<<root->data<<endl;
      if(root!=NULL){
         read(root->left);
      }
      else
       read(root->right);

   }

};
int main(){
    int x=2;
    int y=4;
    int z=1;
    int c=5;
    tree t;
    tree(&c);
    t.empty_tree();
   t= t.insert(t,x);
   t= t.insert(t,y);
    t= t.insert(t,z);
     t.read(t); 
    return 0;
}
