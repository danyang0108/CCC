#include <bits/stdc++.h>
using namespace std;
int n,m,L,rt,edge,dis[100002];vector<int>adj[100002],adj2[100002];bool pho[100002];
void tree_pruning(int u,int par){
    if (dis[u]>L && pho[u]){
        L=dis[u];
        rt=u;
    }
    for (int v:adj[u]){
        if (v!=par){
            dis[v]=dis[u]+1; tree_pruning(v,u);
            if (pho[v] || !adj2[v].empty()){
                adj2[u].push_back(v);
                adj2[v].push_back(u);
                edge++;
            }
        }
    }
}
void dfs(int u, int par){
    if (dis[u]>L){
        L=dis[u];
        rt=u;
    }
    for (int v:adj2[u]){
        if (v!=par){
            dis[v]=dis[u]+1;dfs(v,u);
        }
    }
}
int main(){
  scanf("%d %d",&n,&m);
  for (int i=1;i<=m;i++){
      scanf("%d",&rt);pho[rt]=true;
  }
  for (int i=1,x,y;i<n;i++){
      scanf("%d %d",&x,&y);
      adj[x].push_back(y);
      adj[y].push_back(x);
  }
  tree_pruning(rt,-1);
  dis[rt]=0;dfs(rt,-1);
  printf("%d\n",2*edge-L);
}
