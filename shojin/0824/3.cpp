#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

ll imos[202020];
ll d[202020];

int main(){

    ll N;
    cin >> N;
    ll ans = 1;
    for(ll i = 1; i <= N; i++){
        ans = (ans * i) % MOD;
    }
    string S;
    cin >> S;
    S = "#" + S;
    for(ll i = 1; i < S.size(); i++){
        if(S[i] == 'W'){
            if(abs(imos[i]) % 2){
                d[i] = 1;
                imos[i] += 1;
                imos[i + 1] = imos[i];
            }
            else{
                d[i] = -1;
                imos[i] += 0;
                imos[i + 1] = imos[i] - 1;
            }
        }
        else{
            if(abs(imos[i]) % 2){
                d[i] = -1;
                imos[i] += 0;
                imos[i + 1] = imos[i] - 1;
            }
            else{
                d[i] = 1;
                imos[i] += 1;
                imos[i + 1] = imos[i];
            }
        }
    }
    ll tmp = 1;
    ll cnt = 0;
    for(ll i = 1; i < S.size(); i++){
        if(d[i] == 1){
            cnt++;
        }
        else{
            if(cnt <= 0)tmp = 0;
            tmp = (tmp * cnt) % MOD;
            cnt--;
        }
    }
    if(cnt != 0)tmp = 0;
    ans = (ans * tmp) % MOD;
    cout << ans << endl;
    
    return 0;
}