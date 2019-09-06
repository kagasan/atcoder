#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    string s;
    for(ll t = 0; getline(cin, s); t++){
        if(t == 0)continue;
        string ans = "";
        ll flg = 0;
        for(ll i = s.size() - 1; i >= 0; i--){
            if(s[i] == '9' && flg < 2){
                ans += '0';
                flg = 1;
            }
            else if('0' <= s[i] && s[i] < '9' && flg < 2){
                ans += s[i] + 1;
                flg = 2;                
            }
            else{
                if(flg == 1){
                    ans += "1";                
                    flg = 2;
                }
                ans += s[i];
            }
        }
        if(flg == 1)ans += "1";
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}