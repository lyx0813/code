void Dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    dis[0]=0x3f;
    while(true){
        int u=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&dis[i]<dis[u]){
                u=i;
            }
        }
        if(u==0){
            break;
        }
        vis[u]=1;
        for(auto v:edge[u]){
            if(dis[v.to]>dis[u]+v.w){
                dis[v.to]=dis[u]+v.w;
            }
        }
    }
}

struct node{
    int v,w;
    bool operator < (const node &a) const {
        return a.w<w;
    }
}tmp;
priority_queue<node> q;
void Dijkstra(){
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    dis[0]=0x3f;
    tmp.v=s;
    tmp.w=0;
    q.push(tmp);
    while(!q.empty()){
        int u=q.top().v;
        q.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto v:edge[u]){
            if(dis[v.to]>dis[u]+v.w){
                dis[v.to]=dis[u]+v.w;
                tmp.v=v.to;
                tmp.w=dis[v.to];
                q.push(tmp);
            }
        }
    }
}