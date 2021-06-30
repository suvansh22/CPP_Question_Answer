#include<bits/stdc++.h>
using namespace std;

void add(vector<pair<int,int>>adj[],int a,int b,int wt){
    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});
}

void removePath(vector<int>adj[],vector<int>path,int v){
    queue<int>q;
    q.push(v);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(front == 1){
            break;
        }
        int parent = path[front];
        q.push(parent);
        for(auto it = adj[parent].cbegin();it != adj[parent].cend();it++){
            if(it->first == front){
                adj[parent].erase(it);
                break;
            }
        }
    }
}
void dijkstra(vector<int>adj[],int v,int src,int c,int t,int k){
    int result = -1;
    while(k--){
        vector<int>dist(v+1,INT_MAX);
        vector<bool>fin(v+1,false);
        dist[src] = 0;
        vector<int>parent(v+1,-1);
        for(int count = 1;count<=v;count++){
            int u = -1;
            for(int i=1;i<=v;i++){
                if(!fin[i] && (u==-1 || dist[i] < dist[u])){
                    u = i;
                }
            }
            fin[u] = true;
            for(auto x : adj[u]){
                if(dist[x.first] > dist[u]+c+(c>=t)){
                    dist[x.first] = dist[u]+x.second;
                    parent[x.first] = u;
                }
            }
        }
        if(k>0){
            removePath(adj,parent,v);
        }
        result = dist[v];
    }
    cout<<(result == INT_MAX ? -1 : result-1)<<"\n";
}

int main(){
    int n,m,c,t;
    cin>>n>>m>>t>>c;
    int a,b,wt;
    vector<int>adj[n+1];
    for(int i = 0;i<m;i++){
        cin>>a>>b>>wt;
        add(adj,a,b,wt);
    }
    dijkstra(adj,n,1,c,t,2);
}
