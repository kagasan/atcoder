#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){
    
    string s, t;
    cin >> s >> t;
    ll flg = 0;
    for(ll i = 0; i < s.size(); i++){
        ll f = 1;
        for(ll j = 0; j < s.size(); j++){
            ll k = (i + j) % s.size();
            if(s[j] != t[k])f = 0;
        }
        if(f)flg = 1;
    }
    if(flg)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}