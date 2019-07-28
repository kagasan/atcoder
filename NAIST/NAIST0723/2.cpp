#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

map<ll, ll>flg;
vector<P>vec;

int main(){

    ll N, K, M;
    cin >> N >> K >> M;
    map<ll, ll>cnt;
    for(ll i = 2; i * i <= N; i++){
        while(N % i == 0){
            cnt[i]++;
            N /= i;
        }
    }
    if(N != 1)cnt[N] = 1;
    vector<P>vec;
    for(map<ll, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        vec.push_back(P((*it).first, (*it).second * K));
    }
    // for(ll i = 0; i < vec.size(); i++){
    //     cout << vec[i].first << ", " << vec[i].second << endl;
    // }
    queue<ll>Q;
    Q.push(1);
    flg[1] = 1;
    ll ans = 1;
    while(!Q.empty()){
        vector<ll>tmp(vec.size(), 0);
        ll n = Q.front();
        N = n;
        Q.pop();
        for(ll i = 0; i < vec.size(); i++){
            while(n % vec[i].first == 0){
                tmp[i]++;
                n /= vec[i].first;
            }
        }
        for(ll i = 0; i < vec.size(); i++){
            ll hoge = N * vec[i].first;
            if(tmp[i] < vec[i].second && hoge <= M && flg[hoge] == 0){
                Q.push(hoge);
                flg[hoge] = 1;
                ans++;
            }
        }
    }
    cout << ans << endl;
    
    return 0;    
}