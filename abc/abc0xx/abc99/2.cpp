#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll a, b;
    cin >> a >> b;
    ll B = 0;
    for(ll c = b - a; c;c--)B+=c;
    cout << B - b << endl;
    
    return 0;
}