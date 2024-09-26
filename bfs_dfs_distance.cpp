#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3+ 10;
vector<string> g;
int visited[N][N];
int level[N][N];
pii parent[N][N];
int n,m;

vector<pii> direct ={ {0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i,int j){
    return (i>= 0 && i <n && j>= 0 && j <m);
}

void bfs(int si,int sj){
    queue<pii> q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for(auto d:direct){
            int newi = i+d.first;
            int newj = j+d.second;

            if(isValid(newi,newj) && !visited[newi][newj] && g[newi][newj] != 'x'){
                q.push({newi,newj});
                visited[newi][newj] = true;
                level[newi][newj] = level[i][j] + 1;
                parent[newi][newj] = {i,j};
            }
        }
    }
    
}

int main(){
    int si,sj,di,dj;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin>>x;
        for (int j = 0; j < m; j++)
        {
            if(x[j] == 's') si = i,sj = j;
            if(x[j] == 'e') di = i , dj = j;
        }
        g.push_back(x);
    }
    bfs(si,sj);
    if(level[di][dj] > 0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
    
    return 0;
}