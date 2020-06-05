//This is a function for finding simple path in a tree.
/*   Store the tree in the g[N] vector and call dfscall function which takes
     no. of elements in the tree,starting point and ending point and returns
     a vector with simple path between a and b.  */

//Time Complexity for this function is O(2n-1).
const int N=1000000;
vector<int> g[N];
 void path(int a,int b,bool vis[],vector<int> s,vector<int> *v1)
{
   s.push_back(a);
   vis[a]=1;
   int flag=0;
   if(a==b)
   {
       vector<int> v;
       for(int i=0;i<s.size();i++)
        v.push_back(s[i]);
        *v1=v;
       return;
   }
   for(int v:g[a])
   {
     if(vis[v])  continue;
     flag=1;
     path(v,b,vis,s,v1);
   }
   if(flag==0)
    s.pop_back();
 }

 vector<int> dfscall(int n,int a,int b)
 {
    vector<int> s;
    vector<int> v1;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    path(a,b,vis,s,&v1);
    return v1;
 }

