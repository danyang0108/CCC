//question link: https://dmoj.ca/problem/ecoo16r3p3

#include <bits/stdc++.h>
using namespace std;
int n;
string a,b;
set<string> word;
int dp[2002];
int main(){
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a;
        word.insert(a);
    }
    for (int i=0;i<10;i++){
        memset(dp,0x3f3f3f,sizeof(dp));
        cin>>b;
        dp[b.length()]=0;
        for (int j=b.length()-1;j>=0;j--){
            for (int k=j+1;k<=b.length();k++){
                string sub=b.substr(j,k-j);
                if (word.count(sub))dp[j]=min(dp[j],dp[k]+1);
            }
        }
        printf("%d\n",dp[0]-1);
    }
}