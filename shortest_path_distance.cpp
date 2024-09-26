#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int level[1000];
bool visited[1000];
int parent[1000] ;

void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v:adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
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
        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }
    int s,d;
    cin>>s>>d;
    bfs(s);
    cout<<"Distance : "<<level[d]<<endl;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout<<"parent of"<<i<<" : "<<parent[i]<<endl;
    // }

    
    //path finding 
    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(),path.end());
    cout<<"path : ";
    for (int i =0; i < path.size(); i++)
    {
       
        cout<<path[i]<<" ";
    }
    
    
    return 0;
}