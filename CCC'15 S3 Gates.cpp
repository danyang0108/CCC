//question link: https://dmoj.ca/problem/ccc15s3

#include <bits/stdc++.h>
using namespace std;
int g,p,a,cnt;
int arr[100002];
vector <int>arr2;
int main(){
  scanf("%d",&g);
  scanf("%d",&p);
  arr2.push_back(0);
  for (int i=1;i<=g;i++){
    arr2.push_back(i);
  }
  for (int i=1;i<=p;i++){
    scanf("%d",&a);
    a=upper_bound(arr2.begin(),arr2.end(),a)-arr2.begin()-1;
    if (a<=0){
      printf("%d",cnt);
      return 0;
    }
    arr2.erase(arr2.begin()+a);
    cnt++;
  }
  printf("%d",cnt);
}