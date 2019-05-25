#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll r, d, x;
    cin >> r >> d >> x;
    for(ll i = 0; i < 10; i++){
        ll xx = r * x - d;
        cout << xx << endl;
        x = xx;
    }

    return 0;
}