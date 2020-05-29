#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
vector<int> g[N];
queue<int> v1;
bool vis[N];
void bfs(int u)
{
    if(!vis[u])
    cout<<u<<"\n";
    vis[u]=1;
    while(!v1.empty())
    {
        v1.pop();
       for(int v:g[u])
        {
          if(!vis[v])
           {
               v1.push(v);
             cout<<v<<"\n";
             vis[v]=1;
           }
        }
        if(!v1.empty())
        bfs(v1.front());
    }

}

/*
int main()
{
    int u,v,e,n;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    v1.push(1);
    bfs(1);
    return(0);
}
*/
