class node
{
    public:
    int minvalue;
    int sum=0;
}tree[1000000];

void build(int si,int ei,int arr[],int ci)
{
  if(si==ei)
  {
    tree[ci].sum=arr[si];
    tree[ci].minvalue=arr[si];
    return;
  }
   int mid = (si + ei)/2;
   build(si,mid,arr,ci*2);
   build(mid+1,ei,arr,ci*2+1);
   tree[ci].sum = tree[ci*2].sum+tree[ci*2+1].sum;
   tree[ci].minvalue=min(tree[ci*2].minvalue,tree[ci*2+1].minvalue);
   return;
}
void update(int value,int ind,int l,int r,int pos)
{
    if(l==r)
    {
        tree[ind].sum=value;
        tree[ind].minvalue=value;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(value,ind*2,l,mid,pos);
    else
        update(value,ind*2+1,mid+1,r,pos);
    tree[ind].sum = tree[ind*2].sum + tree[ind*2+1].sum;
     tree[ind].minvalue = min(tree[ind*2].minvalue , tree[ind*2+1].minvalue);
}


int query(int l,int r,int si,int ei,int ci)
{
  if(l==si&&r==ei)
  return tree[ci].minvalue;
  else if(si>r||ei<l)
  return 100000000000;
  else
  {
      int mid=(si+ei)/2;
  return min(query(l,min(r,mid),si,mid,ci*2) , query(max(l,mid+1),r,mid+1,ei,ci*2+1));
  }
}
