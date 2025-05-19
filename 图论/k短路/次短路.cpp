#include<bits/stdc++.h>
using namespace std;
void add(int x,int y,int w){
    ma[++cnt].to=y;
    ma[cnt].dis=w;
    ma[cnt].nxt=h[x];
    h[x]=cnt;
}
void spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    que.qush(s);vis[s]=1;
    dis[s][0]=0;
    while(!que.empty()){
        int u=que.front();
        vis[u]=0;que.pop();
        for(int i=h[u];i;i=ma[i].nxt){
            int v=ma[i].to;
            if(dis[v][0]>dis[u][0]+ma[i].w){
                dis[v][1]=dis[v][0];
                dis[v][0]=dis[u][0]+ma[i].w;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
            if(dis[v][1]>dis[u][0]+ma[i].w&&d[u][0]+ma[i].dis>d[u][0]){
                dis[v][1]=dis[u][0]+ma[i].w;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
            if(dis[v][1]>dis[u][1]+ma[i].w){
                dis[v][1]=dis[u][1]+ma[i].w;
                if(!vis[v]){
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

int main(){

}