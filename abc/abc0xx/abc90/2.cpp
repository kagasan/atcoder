#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll A, B;
    cin >> A >> B;
    ll ans = 0;
    for(ll i = A; i <= B; i++){
        stringstream ss;
        ss << i;
        string s = ss.str();
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t)ans++;
    }
    cout << ans << endl;
    
    return 0;
}