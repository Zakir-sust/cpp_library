int dfs(int nd,int p)
{
    sz[nd]=1;
    int mx=0;
    for(ll to:adj[nd]){
        if(to==p)continue;
        sz[nd]+=dfs(to,nd);
        if(mx<sz[to]){
            mx=sz[to];
            son[nd]=to;
        }
    }
    return sz[nd];
}

int t=0;
void hld(int nd,int p,int h,int d)
{
    fa[nd]=p,dis[nd]=++t,head[nd]=h,lvl[nd]=d;
    for(auto to:adj[nd]){
        if(to!=p&&son[nd]==to){
            hld(to,nd,h,d+1);
            break;
        }
    }
    for(auto to:adj[nd]){
        if(to!=p&&son[nd]!=to){
            hld(to,nd,to,d+1);
        }
    }
}
int n;
int get_res(int u,int v)                ///calculates max
{
    int ans=0;
    while(1)
    {
        if(dis[u]>dis[v])swap(u,v);
        if(head[u]==head[v]){                       /// here u is the lca
            int f=query(1,1,n,dis[u],dis[v]);   
            ans=max(ans,f);
            return ans;
        }
        int l=head[v];
        int f=query(1,1,n,dis[l],dis[v]);
        ans=max(ans,f);
//        error(u,v,f);
        v=fa[head[v]];
    }
    return ans;
}
