#include <bits/stdc++.h>
using namespace std;
int t,r,c;
typedef pair<int,int> pi;
char arr[22][22];
bool vis[22][22];
int dis[22][22];
queue<pi> q;
int main(){
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        memset(arr,0,sizeof(arr));
        memset(vis,false,sizeof(vis));
        memset(dis,0,sizeof(dis));
        scanf("%d %d",&r,&c);
        for (int j=1;j<=r;j++){
            for (int k=1;k<=c;k++){
                cin>>arr[j][k];
            }
        }
        q.push({1,1});
        vis[1][1] = true;
        dis[1][1] = 1;
        while (!q.empty()){
            int curR = q.front().first; int curC = q.front().second;
            q.pop();
            if (arr[curR][curC] == '+'){
                if (!vis[curR-1][curC] && curR-1 > 0 && curC > 0 && arr[curR-1][curC]!='*'){
                    q.push({curR-1,curC});
                    vis[curR-1][curC]= true;
                    dis[curR-1][curC]=dis[curR][curC]+1;
                }
                if (!vis[curR+1][curC] && curR+1 > 0 && curC > 0 && arr[curR+1][curC]!='*'){
                    q.push({curR+1,curC});
                    vis[curR+1][curC]= true;
                    dis[curR+1][curC]=dis[curR][curC]+1;
                }
                if (!vis[curR][curC-1] && curR > 0 && curC-1 > 0 && arr[curR][curC-1]!='*'){
                    q.push({curR,curC-1});
                    vis[curR][curC-1]= true;
                    dis[curR][curC-1]=dis[curR][curC]+1;
                }
                if (!vis[curR][curC+1] && curR > 0 && curC+1 > 0 && arr[curR][curC+1]!='*'){
                    q.push({curR,curC+1});
                    vis[curR][curC+1]= true;
                    dis[curR][curC+1]=dis[curR][curC]+1;
                }
            }
            if (arr[curR][curC] == '-'){
                if (!vis[curR][curC-1] && curR > 0 && curC-1 > 0 && arr[curR][curC-1]!='*'){
                    q.push({curR,curC-1});
                    vis[curR][curC-1]= true;
                    dis[curR][curC-1]=dis[curR][curC]+1;
                }
                if (!vis[curR][curC+1] && curR > 0 && curC+1 > 0 && arr[curR][curC+1]!='*'){
                    q.push({curR,curC+1});
                    vis[curR][curC+1]= true;
                    dis[curR][curC+1]=dis[curR][curC]+1;
                }
            }
            if (arr[curR][curC] == '|'){
                if (!vis[curR-1][curC] && curR-1 > 0 && curC > 0 && arr[curR-1][curC]!='*'){
                    q.push({curR-1,curC});
                    vis[curR-1][curC]= true;
                    dis[curR-1][curC]=dis[curR][curC]+1;
                }
                if (!vis[curR+1][curC] && curR+1 > 0 && curC > 0 && arr[curR+1][curC]!='*'){
                    q.push({curR+1,curC});
                    vis[curR+1][curC]= true;
                    dis[curR+1][curC]=dis[curR][curC]+1;
                }
            }
        }
        if (vis[r][c])printf("%d\n", dis[r][c]);
        else printf("-1\n");
    }
}
