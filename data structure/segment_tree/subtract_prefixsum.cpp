


void push(int nd,int st,int ed)
{
    if(lazy[nd]==0)return;
    int m=(st+ed)>>1,l=nd<<1,r=l+1;
    int mn = -min(tr[l],-lazy[nd]),rem=lazy[nd]-mn;
    tr[l] += mn,lazy[l] +=mn;
    if(rem<0)tr[r] += rem,lazy[r] += rem;
    lazy[nd] = 0;
}
///subtract val starting from i.
int update(int nd,int st,int ed,int i,int j,ll val)
{
//        error(st,ed,i,j,val);
    if(st >j || ed < i)return 0;
    if(st >=i && ed <=j){
        int mn = min(tr[nd],-val);
        tr[nd] -= mn;
        lazy[nd] -= mn;
        return mn;
    }
    push(nd,st,ed);
    int m=(st+ed)>>1,l=nd<<1,r=l+1;
    int f1 = update(l,st,m,i,j,val),f2=0;
    if(f1< -val){
        f2 = update(r,m+1,ed,i,j,f1+val);
    }
    tr[nd] = merg(tr[l],tr[r]);
    return f1 + f2;
}
