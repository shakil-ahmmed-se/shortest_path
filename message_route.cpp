#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
vector<bool> visited(N,false);
vector<int> level(N,0);
vector<int> parent(N,-1);

void bfs(int source){
    queue<int> q;
    q.push(source);
    level[source] = 1;
    visited[source] = true;
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : g[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            level[v] = level[u] + 1;
        }
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    if(level[n] == 0){ 
        cout<<"IMPOSSIBLE"<<endl;
       
    }
    else{
        cout<<level[n]<<endl;
    int current = n;
    vector<int> path;

    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(),path.end());
    for(auto p: path){
        cout<<p<<" ";
    }
    }

    return 0;
}