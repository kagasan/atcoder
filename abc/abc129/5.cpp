#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll tri[101010];

int main(){

    tri[0] = 1;
    for(ll i = 1; i < 101000; i++){
        tri[i] = (tri[i - 1] * 3) % MOD;
    }

    string s;
    cin >> s;
    ll sz = s.size();

    ll ans = 0;
    ll tmp = 1;
    for(ll i = 0; i < sz; i++){
        if(s[i] == '0')continue;
        ans += (tmp * tri[sz - i - 1]) % MOD;
        tmp = (tmp + tmp) % MOD;
    }
    ans = (ans + tmp) % MOD;
    cout << ans << endl;

    return 0;
}