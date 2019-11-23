#include <bits/stdc++.h>
using namespace std;
int l[2002],n;
long long int b[4004],ans,ans2;
int main(){
    scanf("%d",&n);
    for (int i=1,x;i<=n;i++){
        scanf("%d",&x);
        l[x]++;
    }
    for (int i=1;i<=2000;i++){
        if (l[i]>0) {
            b[i*2]+=l[i]/2;
            for (int j = i+1; j <= 2000; j++) {
                if (l[j]>0){
                    b[i+j]+=min(l[i],l[j]);
                }
            }
        }
    }
    for (int i=1;i<=4000;i++){
        if (b[i]>ans){
            ans=b[i];
        }
    }
    for (int i=1;i<=4000;i++){
        if (b[i]==ans){
            ans2++;
        }
    }
    printf("%lld %lld\n",ans,ans2);
}
