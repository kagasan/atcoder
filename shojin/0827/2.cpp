#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll check(ll a, ll b, ll c){
    vector<ll>v = {a, b, c};
    sort(v.begin(), v.end());
    if(v[0] == v[1] || v[1] == v[2])return 0;
    if(v[1] == a || v[1] == c)return 1;
    return 0;
}

int main(){

    ll N;
    cin >> N;
    vector<ll>v(N + 2, 0);
    for(ll i = 1; i <= N; i++){
        cin >> v[i];
    }
    ll ans = 0;
    for(ll i = 1; i + 2 <= N; i++){
        ans += check(v[i], v[i + 1], v[i + 2]);
    }
    cout << ans << endl;

    return 0;
}