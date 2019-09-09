#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll check(ll x, ll y, ll z){
    if(x != y && y != z && x != z && ((x < y && y > z) || (x > y && y < z))){
        return 1;
    }
    return 0;
}

int main(){

    ll x, y, z;
    cin >> x >> y >> z;
    if(check(x, y, z)){
        cout << "INF" << endl;
        return 0;
    }
    ll ans = 0;
    for(ll i = 1; i < 1010; i++){
        if(check(x % i, y % i, z % i))ans++;
    }
    cout << ans << endl;

    return 0;
}