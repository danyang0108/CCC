#include <bits/stdc++.h>
using namespace std;

int adj[5][5];
bool vis[5][5];

void RUN(){
   if (vis[0][0] && vis[0][1] && !vis[0][2]){
      adj[0][2] = adj[0][1] + (adj[0][1] - adj[0][0]);
      vis[0][2] = true;
   }
   if (vis[0][0] && vis[0][2] && !vis[0][1]){
      adj[0][1] = adj[0][0] + (adj[0][2] - adj[0][0]) / 2;
      vis[0][1] = true;
   }
   if (vis[0][1] && vis[0][2] && !vis[0][0]){
      adj[0][0] = adj[0][1] - (adj[0][2] - adj[0][1]);
      vis[0][0] = true;
   }
   if (vis[0][0] && vis[1][0] && !vis[2][0]){
      adj[2][0] = adj[1][0] + (adj[1][0] - adj[0][0]);
      vis[2][0] = true;
   }
   if (vis[0][0] && vis[2][0] && !vis[1][0]){
      adj[1][0] = adj[0][0] + (adj[2][0] - adj[0][0]) / 2;
      vis[1][0] = true;
   }
   if (vis[1][0] && vis[2][0] && !vis[0][0]){
      adj[0][0] = adj[1][0] - (adj[2][0] - adj[1][0]);
      vis[0][0] = true;
   }
   if (vis[0][1] && vis[1][1] && !vis[2][1]){
      adj[2][1] = adj[1][1] + (adj[1][1] - adj[0][1]);
      vis[2][1] = true;
   }
   if (vis[0][1] && vis[2][1] && !vis[1][1]){
      adj[1][1] = adj[0][1] + (adj[2][1] - adj[0][1]) / 2;
      vis[1][1] = true;
   }
   if (vis[1][1] && vis[2][1] && !vis[0][1]){
      adj[0][1] = adj[1][1] - (adj[2][1] - adj[1][1]);
      vis[0][1] = true;
   }
   if (vis[0][2] && vis[1][2] && !vis[2][2]){
      adj[2][2] = adj[1][2] + (adj[1][2] - adj[0][2]);
      vis[2][2] = true;
   }
   if (vis[0][2] && vis[2][2] && !vis[1][2]){
      adj[1][2] = adj[0][2] + (adj[2][2] - adj[0][2]) / 2;
      vis[1][2] = true;
   }
   if (vis[1][2] && vis[2][2] && !vis[0][2]){
      adj[0][2] = adj[1][2] - (adj[2][2] - adj[1][2]);
      vis[0][2] = true;
   }
   if (vis[1][0] && vis[1][1] && !vis[1][2]){
      adj[1][2] = adj[1][1] + (adj[1][1] - adj[1][0]);
      vis[1][2] = true;
   }
   if (vis[1][0] && vis[1][2] && !vis[1][1]){
      adj[1][1] = adj[1][0] + (adj[1][2] - adj[1][0]) / 2;
      vis[1][1] = true;
   }
   if (vis[1][1] && vis[1][2] && !vis[1][0]){
      adj[1][0] = adj[1][1] - (adj[1][2] - adj[1][1]);
      vis[1][0] = true;
   }
   if (vis[2][0] && vis[2][1] && !vis[2][2]){
      adj[2][2] = adj[2][1] + (adj[2][1] - adj[2][0]);
      vis[2][2] = true;
   }
   if (vis[2][0] && vis[2][2] && !vis[2][1]){
      adj[2][1] = adj[2][0] + (adj[2][2] - adj[2][0]) / 2;
      vis[2][1] = true;
   }
   if (vis[2][1] && vis[2][2] && !vis[2][0]){
      adj[2][0] = adj[2][1] - (adj[2][2] - adj[2][1]);
      vis[2][0] = true;
   }
}

int main(){
   memset(vis, false, sizeof(vis));
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
         string temp; cin >> temp;
         if (temp != "X") adj[i][j] = stoi(temp), vis[i][j] = true;
      }
   }
   for (int i = 0; i < 50; i++) RUN();

   if (!vis[1][1]){
      adj[1][1] = 0;
      vis[1][1] = true;
      for (int i = 0; i < 50; i++) RUN();
   }
   if (!vis[1][0]){
      adj[1][0] = adj[1][1];
      vis[1][0] = true;
      for (int i = 0; i < 50; i++) RUN();
   }
   if (!vis[1][2]){
      adj[1][2] = adj[1][1];
      vis[1][2] = true;
      for (int i = 0; i < 50; i++) RUN();
   }
   if (!vis[0][1]){
      adj[0][1] = adj[1][1];
      vis[0][1] = true;
      for (int i = 0; i < 50; i++) RUN();
   }
   if (!vis[2][1]){
      adj[2][1] = adj[1][1];
      vis[2][1] = true;
      for (int i = 0; i < 50; i++) RUN();
   }
   if (!vis[0][0]){
      adj[0][0] = adj[1][0];
      vis[0][0] = true;
      for (int i = 0; i < 50; i++) RUN();
   }
   if (!vis[2][2]){
       adj[2][2] = adj[2][1];
       vis[2][2] = true;
       for (int i = 0; i < 50; i++) RUN();
   }

   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
         printf("%d ", adj[i][j]);
      }
      printf("\n");
   }
   return 0;
}