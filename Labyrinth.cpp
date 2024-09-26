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

            if(isValid(newi,newj) && !visited[newi][newj] && g[newi][newj] != '#'){
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
    for (int i = 0; i < m; i++)
    {
        string x;
        cin>>x;
        for (int j = 0; j < m; j++)
        {
            if(x[j] == 'A') si = i,sj = j;
            if(x[j] == 'B') di = i,dj = j;
        }
        
        g.push_back(x);
    }
    bfs(si,sj);
    if(level[di][dj] != 0){
        cout<<"YES\n";
        cout<<level[di][dj]<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    vector<pii> path;
    pii curr = {di,dj};

    while (!(curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(),path.end());
    
    for (int i = 1; i < path.size(); i++)
    {
       if(path[i-1].first == path[i].first){
        //dan bam
            if(path[i-1].second == path[i].second - 1){
                //dan theke bame jacchi
                cout<<"R";
            }
            else{
                cout<<"L";
            }
       }
       else{
        //upor niche
            if(path[i-1].first == path[i].first - 1){
                //down
                cout<<"D";
            }
            else{
                cout<<"U";
            }
       }
    }
    


    return 0;
}