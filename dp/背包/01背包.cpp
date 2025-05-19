#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int v,w;
}a[100100];
int n,m,dp[100100];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i].w;j--){
            dp[i]=max(dp[i],dp[j-a[i].w]+a[i].v);
        }
    }
    return 0;
}
