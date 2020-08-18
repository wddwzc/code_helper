#include <bits/stdc++.h>
using namespace std;

int main(){
    map<vector<int>, int> store;
    int n=0;
    int k=0;
    while(cin >>n>>k){
        long long res=0;
        vector<int> ng(k-1,0);
        long long pcount =0;
        for(int i=0;i<n;i++){
            vector<int> vec(k-1, 0);
            int fv;
            int v;
            cin>>fv;
            for(int j=1;j<k;j++){
                cin>>v;
                vec[j-1]=v-fv;
            }
            store[vec]++;
        }
        if(store.find(ng)!=store.end()){
            long long count =store[ng];
            res += count*(count-1)/2;
            store.erase(ng);
        }
        for(auto it=store.begin();it!=store.end();it++){
            for(size_t i = 0;i<it->first.size();i++){
                ng[i] = -it->first[i];
            }
            if(store.find(ng)!=store.end()){
                long long count =store[ng];
                pcount +=count*it->second;
            }
        }
        res +=pcount/2;
        cout<< res<< endl;
    }
    return 0;
}