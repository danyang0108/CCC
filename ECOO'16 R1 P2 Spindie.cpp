//question link: https://dmoj.ca/problem/ecoo16r1p2

#include <bits/stdc++.h>
using namespace std;
bool t[1000002];
int n,q;
set<int> arr;
vector<long long int> doublesum;
vector<long long int> doubleproduct;
vector<int> test;
int main(){
    for (int aa=0;aa<10;aa++){
        scanf("%d",&n);
        for (int i=0,x;i<n;i++){
            scanf("%d",&x);
            t[x]=true;
            arr.insert(x);
        }
        for (auto it=arr.begin(); it != arr.end(); ++it){
            for (auto is=arr.begin(); is != arr.end(); ++is){
                doubleproduct.push_back(*it**is);
                doublesum.push_back(*it+*is);
            }
        }
        for (int i=0;i<5;i++){
            scanf("%d",&q);
            bool done=false;
           for (auto u:doublesum){
               if (q>u && t[q-u]){
                   printf("T");
                   done=true;
                   break;
               }
               if (q>u && q%u==0 && t[q/u]){
                   printf("T");
                   done=true;
                   break;
               }
           }
           if (!done){
               for(auto u:doubleproduct){
                   if(q>u && t[q - u]){
                       printf("T");
                       done=true;
                       break;
                   }
                   if(q>u && q % u == 0 && t[q / u]){
                       printf("T");
                       done=true;
                       break;
                   }
               }
           }
           if (!done)
           printf("F");
        }
        printf("\n");
        doubleproduct.clear();
        doublesum.clear();
        memset(t,0,sizeof(t));
        arr.clear();
    }
}