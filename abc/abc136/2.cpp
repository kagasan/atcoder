#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ll tmp = 0;
        for(ll x = i;x;x /= 10)tmp++;
        if(tmp%2)ans++;
    }
    cout << ans << endl;

    return 0;
}