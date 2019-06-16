#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MAX = 1000000000000000LL;

ll s(ll n){
    ll tmp = 0;
    for(;n;n/=10)tmp+=n%10;
    return tmp;
}

bool mn(ll n, ll m){
    return n * s(m) < m * s(n);
}

void test(){
    vector<ll>v;
    v.push_back(1);
    for(ll i = 2; i < 1000000; i++){
        for(;;){
            if(mn(i, v.back())) v.pop_back();
            else break;
        }
        v.push_back(i);
    }
    for(ll i = 0; i < v.size(); i++){
        cout << v[i] << " : " << v[i] << " / " << s(v[i]) << " = " << (double)v[i] / s(v[i]) << endl;
    }
}

int main(){

    set<ll>S;
    for(ll i = 1; i <= 999; i++){
        for(ll j = i; j <= MAX; j = j * 10 + 9){
            S.insert(j);
        }
    }
    vector<ll>v;
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
        ll n = *it;
        while(!v.empty()){
            if(mn(n, v.back()))v.pop_back();
            else break;
        }
        v.push_back(n);
    }

    ll K;
    cin >> K;
    for(ll i = 0; i < K; i++)cout << v[i] << endl;

    return 0;
}
