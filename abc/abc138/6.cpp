#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

void draw(ll X){
    for(ll y = 1; y <= X; y++){
        for(ll x = 1; x <= X; x++){
            if(x > y)cout << " ";
            else if(y % x == (y ^ x))cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}

ll nm[50];
ll sz[50];
ll u[50], d[50];
void init(){
    nm[0] = 1;
    sz[0] = 1;
    u[0] = 1;
    d[0] = 1;
    for(ll i = 0; i < 40; i++){
        nm[i + 1] = (nm[i] * 3) % MOD;
        sz[i + 1] = sz[i] * 2;
        d[i + 1] = u[i] + 1;
        u[i + 1] = u[i] + (u[i] - d[i] + 1) * 2;
    }
    // for(ll i = 0; i < 10; i++){
    //     cout << d[i] << ", " << u[i] << " : " << nm[i] << endl;
    // }
}

ll calc(ll idx, ll x){
    cout << idx << " " << x << endl;
    if(x + 1 == sz[idx])return nm[idx];
    if(idx == 0)return 1;
    ll res = 0;
    if(x < sz[idx] / 2)res = calc(idx - 1, x);
    else{
        res = nm[idx - 1];
        x -= sz[idx] / 2;
        res += (calc(idx - 1, x) * 2) % MOD;
        res %= MOD;
    }
    return res;
}

ll cnt(ll x){
    if(x == 0)return 0;
    if(x == 1)return 1;
    ll res = 0;
    for(ll i = 0; ;i++){
        if(u[i] < x)res = (res + nm[i]) % MOD;
        else{
            res = (res + calc(i, x - d[i])) % MOD;
            break;
        }
    }
    return res;
}

int main(){
    draw(110);
    return 0;
    init();
    ll k = cnt(100);
    // for(ll i = 0; i <= 15; i++){
    //     ll tmp = cnt(i);
    //     cout << i << " : " << tmp << endl;
    // }
    cout << k << endl;
    // ll l, r;
    // cin >> l >> r;
    // cout << cnt(r) - cnt(l - 1) << endl;

    return 0;
}