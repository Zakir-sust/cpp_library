const int N=105;
int ara[N];
int capacity[N][N];
int par[N];
vi adj[N];
bool vis[N];
int bfs(int st,int ed)
{
	queue<int>q;
	q.push(st);
	memset(vis,0,sizeof vis);
	vis[st] = 1;
	par[st] = -1;
	while(!q.empty()){
		auto top = q.front();
		q.pop();
		if(top == ed)
			return 1;
		for(auto to:adj[top]){
			if(vis[to] == 0 && capacity[top][to] ){
				q.push(to);
				par[to] = top;
				vis[to] = 1;
			}
		}
	}
	return 0;
}
int ford_fulkerson(int st,int ed)
{
	int ans = 0;
	while(bfs(st,ed)){
		int u = ed,w=inf;
		while(par[u] != -1){
			w = min(w,capacity[par[u]][u]);
			u = par[u];
		}
		u = ed;
		while(par[u] != -1){
			capacity[par[u]][u] -= w;
			capacity[u][par[u]] += w;
			u = par[u];
		}
		ans += w;
	}
	return ans;
}
