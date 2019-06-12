#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
typedef pair<P, P>PP;

string make(ll x, ll y){
    stringstream ss1;
    ss1 << x;
    string s1 = ss1.str();
    while(s1.size() < 6)s1 = "0" + s1;
    stringstream ss2;
    ss2 << y;
    string s2 = ss2.str();
    while(s2.size() < 6)s2 = "0" + s2;
    return s1 + s2;
}

int main(){

    ll N, M;
    cin >> N >> M;
    vector<PP>v(M, PP(P(0, 0), P(0, 0)));
    for(ll i = 0; i < M; i++){
        cin >> v[i].first.second >> v[i].first.first;
        v[i].second.first = i;
    }
    sort(v.begin(), v.end());
    vector<ll>cnt(101010, 0);
    vector<string>ans(101010);
    for(ll i = 0; i < M; i++){
        ll p = v[i].first.second;
        ll idx = v[i].second.first;
        cnt[p]++;
        ans[idx] = make(p, cnt[p]);
    }
    for(ll i = 0; i < M; i++)cout << ans[i] << endl;


    return 0;
}