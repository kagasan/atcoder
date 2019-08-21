#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    string s;
    cin >> s;
    s += "###";
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '#')break;
        if(s[i] == 'O' && s[i + 1] == 'X'){
            i++;
            ans++;
        }
        else if(s[i] == 'X' && s[i + 1] == 'O'){
            i++;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;    
}