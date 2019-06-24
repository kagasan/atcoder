#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};


int main(){

    ll N;
    cin >> N;
    vector<P>v;
    for(ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back(P(b, a));
    }
    sort(v.begin(), v.end());
    ll flg = 1, t = 0;
    for(ll i = 0; i < N; i++){
        t += v[i].second;
        if(t > v[i].first)flg = 0;
    }
    Yes(flg);

    return 0;
}