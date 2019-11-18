const int N=1000000;
vector<int> g[N];
bool vis[N];
void dfs(int u)
{
   cout<<u<<"\n";
   vis[u]=1;
   for(int v:g[u])
   {
     if(vis[v])  continue;
     dfs(v);
   } 
 } 
