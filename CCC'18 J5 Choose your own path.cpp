//question link: https://dmoj.ca/problem/ccc18j5

#include <bits/stdc++.h>
using namespace std;
#define MM 10002
int n,m,length=INT_MAX;
bool end_page[MM];
bool vis[MM];
int dis[MM];
bool reach=true;
vector <int> adj[MM];
int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;i++){
    scanf("%d",&m);
    if (m==0){
      end_page[i]=true;
    }
    else{
    for (int j=1,a;j<=m;j++){
      scanf("%d",&a);
      adj[i].push_back(a);
    }
    }
  }
  queue<int> q; q.push(1); vis[1] = true; dis[1]=1;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto u: adj[cur]){
      if(!vis[u]){
        dis[u]=dis[cur]+1;
        vis[u] = true;
        q.push(u);
      }
    }
  }
  for (int i=1;i<=n;i++){
    if (vis[i]){
      continue;
    }
    else{
      reach=false;
      break;
    }
  }
  for (int i=1;i<=n;i++){
    if (dis[i]==0){
      continue;
    }
    if (end_page[i] && dis[i]<length){
      length=dis[i];
    }
  }
  if (reach){
    printf("Y\n");
    printf("%d",length);
  }
  else{
    printf("N\n");
    printf("%d",length);
  }
}
