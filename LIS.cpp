//Finds longest increasing subsequence in O(nlogn).

//Just call lis function by passing a sequence vector for which you want to find the longest increasing subsequence.
//eg..
// vector<int> v;
//int ans = lis(v);

int lis(vector<int> v)
{
     int n=v.size();
     vector<int> ans;
     ans.push_back(v[0]);
     int len=1;
     for(int i=1;i<n;i++)
     {
          if(v[i]>ans[len-1])
          {
             ans.push_back(v[i]);
             len++;
          }
          else
          {
              int ind=lower_bound(ans.begin(),ans.end(),v[i])-ans.begin();
              ans[ind]=v[i];
          }
     }
     return len;
}
