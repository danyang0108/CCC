//question link: https://dmoj.ca/problem/ccc20s2

#include <bits/stdc++.h>
using namespace std;
int m,n;
int arr[1002][1002];
bool vis[1002][1002];
queue<int> q;
int main(){
    scanf("%d",&m);
    scanf("%d",&n);
    for (int i = 1; i <=m;i++){
        for (int j=1; j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    q.push(arr[1][1]);
    vis[1][1] = true;
    while (!q.empty()){
        int cur = q.front();q.pop();
        int st = (int)(cur/1000);
        for (int i = max(st,1); i <= sqrt(cur); i++){
            if (cur%i == 0){
                int div = cur/i;
                if (div<=m && i<=n && !vis[div][i]) {
                    q.push(arr[cur / i][i]);
                    vis[div][i] = true;
                }
                if (div<=n && i<=m && !vis[i][div]) {
                    q.push(arr[i][cur / i]);
                    vis[i][div] = true;
                }
            }
        }
    }
    if (vis[m][n]){
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
}