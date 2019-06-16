#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll p[55600];
vector<ll>pri;
void era(){
    for(ll i = 2; i < 55600; i++){
        p[i] = 1;
    }
    for(ll i = 2; i * i < 55600; i++){
        for(ll j = i * 2; j < 55600; j += i){
            p[j] = 0;
        }
    }
    for(ll i = 1; i <= 55555; i++)if(p[i])pri.push_back(i);
}
int main(){
    era();
    vector<ll>v;
    for(ll i = 0; i < pri.size(); i++)if(pri[i] % 5 == 1)v.push_back(pri[i]);
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; i++){
        cout << v[i];
        if(i < N)cout << " ";
        else cout << endl;
    }


    return 0;
}
