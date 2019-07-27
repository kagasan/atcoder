#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll ans = 0;
    ll N;
    cin >> N;
    vector<ll>v(N, 0);
    for(ll i = 0; i < N; i++)cin >> v[i];
    ans = 1;
    for(ll i = 1; i < N; i++)if(v[i-1] > v[i])ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = i + 1; j < N; j++){
            swap(v[i], v[j]);
            ll tmp = 1;
            for(ll k = 1; k < N; k++)if(v[k - 1] > v[k])tmp = 0;
            if(tmp)ans = 1;
            swap(v[i], v[j]);
        }
    }
    Say(ans, "YES", "NO");

    return 0;
}