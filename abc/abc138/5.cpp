#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

set<ll>S[256];

int main(){

    string s, t;
    cin >> s >> t;
    for(ll i = 0; i < s.size(); i++){
        S[s[i]].insert(i + 1);
    }

    ll tmp = 0;
    ll idx = 0;
    for(ll i = 0; i < t.size(); i++){
        if(S[t[i]].empty()){
            cout << "-1" << endl;
            return 0;
        }
        set<ll>::iterator it = S[t[i]].upper_bound(idx);
        if(it == S[t[i]].end()){
            tmp += s.size();
            it = S[t[i]].upper_bound(0);
        }
        idx = *it;
    }
    cout << tmp + idx << endl;

    return 0;
}