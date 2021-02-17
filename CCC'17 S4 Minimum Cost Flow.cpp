//question link: https://dmoj.ca/problem/ccc17s4

#include <bits/stdc++.h>
using namespace std;
int n,m,d,edge,lw,lwn,rt,rt2,rt3,day,edgenum;
struct edges{
    int a,b,c,d;
};
vector<edges > adj;
int p[100002];
int find(int d){
    if (d!=p[d])p[d]=find(p[d]);
    return p[d];
}
bool cmp(edges a, edges b){
    if  (a.d==b.d){
        return a.a<b.a;
    }
    return a.d<b.d;
}
int main(){
    scanf("%d %d %d",&n,&m,&d);
    for (int i=1;i<=n;i++)p[i]=i;
    for (int i=1,a,b,c;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        adj.push_back({i,a,b,c});
    }
    sort(adj.begin(),adj.end(),cmp);
    for (auto cur:adj){
        edgenum++;
        if (edge==n-1){
            if (lwn<=d && cur.a<=n-1 && rt3>n-1 &&cur.d <=d){
                day--;
                break;
            }
            if (cur.d>d){
                break;
            }
        }
        int fu=find(cur.b),fv=find(cur.c);
        if (fu!=fv){
            p[fu]=fv;
            edge++;
            if (cur.a>n-1){
                day++;
            }
            if (cur.d>lwn){
                lwn=cur.d;
                rt=cur.b;
                rt2=cur.c;
                rt3=cur.a;
            }
        }
    }
    printf("%d\n",day);
}