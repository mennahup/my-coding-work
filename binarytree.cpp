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
       cout<<"size"<<size<<endl;
   } 
   tree* insert(tree*root,int pe){
       cout<<"enta 3mbet"<<endl;
      if(!root){
          cout<<"check con1"<<endl;
        return tree(pe);
      }
    else if(root->data > pe){
            cout<<"check con2"<<endl;
       root->left=insert(root->left,pe);
      }
       else{
             cout<<"check con2"<<endl;
         root->right= insert(root->right,pe);
      }
      size++;
   }
  void read(tree* root){
      cout<<"enta magnon"<<endl;
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
    cout<<"hello world"<<endl;
    tree t;
    tree(&c);
    t.empty_tree();
   t= t.insert(t,x);
   t= t.insert(t,y);
    t= t.insert(t,z);
     t.read(t); 
 //   t.empty_tree();
    return 0;
}