//question link: https://dmoj.ca/problem/ecoo18r2p2

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,double> pi;
int n,p[1000002];
double w;
bool cmp(pi a,pi b){
    return a.second>b.second;
}
int find(int d){
    if (d!=p[d])p[d]=find(p[d]);
    return p[d];
}
int main(){
    for (int aa=0;aa<10;aa++){
        int mx=0; vector<pi> a; double ans=0.0;
        scanf("%d",&n);
        for (int i=1,d;i<=n;i++){
            scanf("%d %lf",&d,&w);
            a.push_back({d,w});
            mx=max(mx,d);
        }
        sort(a.begin(),a.end(),cmp);
        for (int i=0;i<=mx;i++)p[i]=i;
        for (int i=0;i<n;i++){
            int f= find(a[i].first);
            if (f!=0){
                p[f]=f-1;ans+=a[i].second;
            }
        }
        printf("%.4f\n",ans);
    }
}