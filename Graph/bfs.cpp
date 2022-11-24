vector<int>bfs(int nd,int n)
{
    vector<int>lvl(n+3,inf);
    queue<int>q;
    q.push(nd);
    lvl[nd] = 0;
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        for(auto to:adj[top]){
            if(lvl[top] + 1 < lvl[to]){
                lvl[to] = lvl[top] + 1;
                q.push(to);
            }
        }
    }
    return lvl;
}
