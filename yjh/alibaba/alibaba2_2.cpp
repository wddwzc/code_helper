#include <bits/stdc++.h>
using namespace std;
map<pair<int,int> ,uint64_t> store;
uint64_t op(int n, int m){
    if(store.count({n,m})!=0)
        return store[{n,m}];
    auto maxn = static_cast<uint64_t> (pow(2,m)-1);
    if(n>maxn)return 0;
    if(n<2)return 1;
    uint64_t res = 0;
    for(int i=0;i<n;i++){
        res += op(n-1-i,m-1)*op(i, m-1);
        res = res%static_cast<uint64_t>(1e9+7);
    }
    store[{n,m}] = res;
    return res;
}
uint64_t op2(int n, int m){
    uint64_t res = op(n,m);
    return res%static_cast<uint64_t>(1e9+7);
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    cout<<op2(n,m);
}