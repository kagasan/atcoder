#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll T;
    cin >> T;
    for(ll t = 0; t < T; t++){
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        ll flg = 1;
        ll r = 0, g = 0, w = 0, gg = 0;
        for(ll i = 0; i < s.size(); i++){
            if(s[i] == 'R')r++;
            if(s[i] == 'G'){
                if(r == 0)flg = 0;
                else{
                    r--;
                    g++;
                    gg = 1;
                }
            }
            if(s[i] == 'W'){
                if(gg == 0)flg = 0;
                if(g)g--;
            }
        }
        if(r > 0)flg = 0;
        if(g > 0)flg = 0;
        if(flg)cout << "possible" << endl;
        else cout << "impossible" << endl;
    }

    return 0;
}