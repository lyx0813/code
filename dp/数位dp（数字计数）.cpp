#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cuta[50],cutb[50];
ll ten[50],dp[50];
ll num[50];
void init(){
    ten[0]=1;
    for(int i=1;i<=15;i++){
        dp[i]=10*dp[i-1]+ten[i-1];
        ten[i]=ten[i-1]*10;
    }
}
void solve(ll x,ll cut[]){
    ll len=0;
    while(x){
        num[++len]=x%10;
        x/=10;
    }
    for(int i=len;i>=1;i--){
        for(int j=0;j<=9;j++){
            cut[j]+=dp[i-1]*num[i];
        }
        for(int j=0;j<num[i];j++){
            cut[j]+=ten[i-1];
        }
        ll num2=0;
        for(int j=i-1;j>=1;j--){
            num2=num2*10+num[j];
        }
        cut[num[i]]+=num2+1;
        cut[0]-=ten[i-1];
    }
}
int main(){
    init();
    ll a,b;
    cin>>a>>b;
    solve(a-1,cuta);
    solve(b,cutb);
    for(int i=0;i<=9;i++){
        cout<<cutb[i]-cuta[i]<<" ";
    }
    return 0;
}
