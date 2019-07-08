#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main(){
    
    ll a, b, c;
    cin >> a >> b >> c;
    a *= b;
    a %= MOD;
    a *= c;
    a %= MOD;
    cout << a << endl;
    
    return 0;
}