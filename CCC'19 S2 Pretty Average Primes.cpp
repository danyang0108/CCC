//question link: https://dmoj.ca/problem/ccc19s2

#include <bits/stdc++.h>
using namespace std;
bool prime[2000002];
vector<int> primes;
int t,n,num,se;
int main(){
    fill(prime,prime+2000001,true);
    for (int i=2;i<=2000000;i++){
        if (prime[i]) {
            for (int j=i*2;j<=2000000;j+=i){
                prime[j]=false;
            }
        }
    }
    for (int i=2;i<=1000000;i++){
        if (prime[i])primes.push_back(i);
    }
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        scanf("%d",&n);
        num=2*n;
        for (auto u:primes){
            se=num-u;
            if (se>0 && se<2000000 && prime[se]){
                printf("%d %d\n",u,se);
                break;
            }
        }
    }
}
