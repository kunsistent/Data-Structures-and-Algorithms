#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define INF 100000000
const int N=1000000;
vector<pair<int,int>> g[N];
bool vis[N];
void dijkstra(int src,int n)
{
  int dist[100000];
  for(int i=1;i<=n;i++)
    dist[i]=INF;
  dist[src]=0;
  set<pair<int,int>> s;
  s.insert({dist[src],src});
  while(!s.empty())
  {
      auto cur=*(s.begin());
      int cur_dist=cur.first;
      s.erase(s.begin());
      for(auto v:g[cur.second])
      {
          if(cur_dist+v.second<dist[v.first])
          {
              auto f=s.find({dist[v.first],v.first});
              if(f!=s.end())
                s.erase(f);
              dist[v.first]=cur_dist+v.second;
              s.insert({dist[v.first],v.first});
          }
      }
  }
  for(int i=1;i<=n;i++)
    cout<<i<<" "<<dist[i]<<"\n";
}
signed main()
{
   int u,v,p,n,m,src;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
       cin>>u>>v>>p;
       g[u].push_back({v,p});
   }
   src=1;
dijkstra(src,n);
}
