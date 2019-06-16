#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll ans = 4;
    string s;
    cin >> s;
    for(ll i = 0; i < 4; i++)if(s[i] == '-')ans -= 2;
    cout << ans << endl;

    return 0;
}
