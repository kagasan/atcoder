#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    s += "XYZ";
    ll ans = 0;
    for(ll i = 0; i < s.size();){
        if(s[i] == 'X')break;
        if(s[i] == 'C' || (s[i] == 'B' && s[i + 1] != 'C')){
            i++;
            continue;
        }
        vector<ll>vec;
        for(;i < s.size();){
            if(s[i] == 'A'){
                vec.push_back(0);
                i++;
            }
            else if(s[i] == 'B' && s[i + 1] == 'C'){
                vec.push_back(1);
                i+=2;
            }
            else{
                break;
            }
        }
        ll cnt = 0;
        for(ll j = 0; j < vec.size(); j++){
            if(vec[j] == 0)cnt++;
            else ans += cnt;
        }
    }
    

    cout << ans << endl;

    return 0;
}
