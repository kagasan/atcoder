#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    for(ll N;cin>>N,N;){
        vector<string>s(N);
        for(ll i = 0; i < N; i++){
            cin >> s[i];
        }
        ll ans = 100;
        for(ll k = 1; k <= 50; k++){
            set<string>S;
            for(ll i = 0; i < N; i++){
                string tmp = "";
                tmp += s[i][0];
                for(ll j = 1; j < s[i].size(); j++){
                    ll flg = 0;
                    if(s[i][j-1] == 'a')flg = 1;
                    if(s[i][j-1] == 'i')flg = 1;
                    if(s[i][j-1] == 'u')flg = 1;
                    if(s[i][j-1] == 'e')flg = 1;
                    if(s[i][j-1] == 'o')flg = 1;
                    if(flg && tmp.size() < k)tmp += s[i][j];
                }
                S.insert(tmp);
            }
            if(S.size() == N)ans = min(ans, k);
        }
        if(ans == 100)cout << -1 << endl;
        else cout << ans << endl;
    }
    
    return 0;    
}