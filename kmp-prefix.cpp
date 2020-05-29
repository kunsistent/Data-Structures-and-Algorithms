#include<bits/stdc++.h>
using namespace std;
int arr[100001];
void prefix(string s)
{
    int n=s.size();
    int i=1,j=0;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            arr[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j-1<0)
             i++;
             else
            j=arr[j-1];
        }
    }
}

int main()
{
    string s;
    cin>>s;
    prefix(s);
    for(int i=0;i<s.size();i++)
        cout<<arr[i]<<" ";
    return(0);
}
