#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    string s;
    cin >> s;
    string ans = "";
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '0')ans += "0";
        if(s[i] == '1')ans += "1";
        if(s[i] == 'B' && ans.size())ans.pop_back();        
    }
    cout << ans << endl;
    
    return 0;
}