#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    vector<ll>v(3);
    for(ll i = 0; i < 3; i++)cin >> v[i];
    ll k;
    cin >> k;
    sort(v.begin(), v.end(), greater<ll>());
    v[0] *= (1LL << k);
    cout << v[0] + v[1] + v[2] << endl;

    
    return 0;
}
