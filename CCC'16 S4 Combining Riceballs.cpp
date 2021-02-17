//question link: https://dmoj.ca/problem/ccc16s4

#include <bits/stdc++.h>
using namespace std;
int n,a[402],ans;bool dp[402][402];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans=max(ans,a[i]);
        a[i]+=a[i-1]; dp[i][i]=true;
    }
    for (int len=1;len<n;len++){
        for (int l=1;l+len<=n;l++){
            int r=l+len;
            for (int p=l,q=r;p<q;){
                int ls=a[p]-a[l-1],rs=a[r]-a[q-1];
                //join three
                if (dp[l][p] && dp[q][r] && (p+1==q ||dp[p+1][q-1])&& ls==rs) dp[l][r]=true;
                if (ls<rs)p++;
                else q--;
            }
            if (dp[l][r])ans=max(ans,a[r]-a[l-1]);
        }
    }
    printf("%d\n",ans);
}
