#include<iostream>
using namespace std;
#define no_ofv 3
struct graph{
    int n;
    int m[no_ofv][no_ofv];
};
void init_graph (graph*p){
    p-> m[0][0]=0;
    p-> m[0][1]=1;
    p-> m[0][2]=1;
    p-> m[1][0]=0;
    p-> m[1][1]=0;
    p-> m[1][2]=1;
    p-> m[2][0]=1;
    p-> m[2][1]=0;
    p-> m[2][2]=1;
}
void show_graph(graph*p){
    for(int i=0;i<no_ofv;++i){
        for(int j=0;j<no_ofv;++j){
            cout<<" i j "<<i<<" "<<j<<" "<<p->m[i][j]<<endl;
        }
    }
}
int main(){
    graph g;
    init_graph(&g);
    show_graph(&g);
    return 0;
}