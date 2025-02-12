#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3+10;
const int INF = 1e9+10;
vector<pii> g[N];
vector<int> dist(N,INF);
bool visited[N];

void dijkstra(int source){
    priority_queue<pii, vector<pii> , greater<pii>> pq;
    dist[source] = 0;
    pq.push({dist[source],source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(pii vpair: g[u]){
            int v = vpair.first;
            int w = vpair.second;
            if(visited[v]) continue;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] +w;
                pq.push({dist[v],v});
            }
        }
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        // g[v].push_back({u,w});

    }
    int s,d;
    cin>>s>>d;
    dijkstra(s);
    cout<<dist[d]<<endl;

    
    return 0;
}