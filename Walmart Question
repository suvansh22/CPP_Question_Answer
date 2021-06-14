#include<bits/stdc++.h>
using namespace std;
class Tree{
    public:
  int color;
  int index;
  vector<Tree*>edges;
  Tree(int idx){
      index =idx;
      color = 1;
  }
};
void addEdges(vector<Tree*> nodes,int e1,int e2){
    int mine = e1<e2?e1:e2;
    int maxe = e1<e2?e2:e1;
    nodes[mine-1]->edges.push_back(nodes[maxe-1]);
}
void colorEdgesRed(Tree* root) {
    if(root!=NULL) {
        for(auto x:root->edges) {
            colorEdgesRed(x);
            x->color = 1;
        }
    }
}
void colorEdgesBlack(Tree* root) {
    if(root!=NULL) {
        for(auto x:root->edges) {
            colorEdgesBlack(x);
            x->color = 0;
        }
    }
}
int countRedEdges(Tree* root){
    if(root == NULL) {
        return 0;
    }
    int count = 0;
    for(auto x:root->edges) {
        count += countRedEdges(x);
        if(x->color == 1) {
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    vector<Tree*>nodes;
    for(int i =  0;i<n;i++) {
        nodes.push_back(new Tree(i+1));
    }
    int e1,e2;
    for(int i = 0;i<n-1;i++) {
        cin>>e1>>e2;
        addEdges(nodes,e1,e2);
    }
    int operations;
    cin>>operations;
    int type,node;
    for(int i =0;i<operations;i++) {
        cin>>type>>node;
        if(type == 1) {
            colorEdgesRed(nodes[node-1]);
        } 
        else if(type == 2) {
            colorEdgesBlack(nodes[node-1]);
        }
        else {
            cout<<countRedEdges(nodes[node-1])<<"\n";
        }
    }
}
