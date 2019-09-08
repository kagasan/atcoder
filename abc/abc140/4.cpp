#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    s = s + "#";
    ll cnt = 0;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(s[i] != s[i + 1])cnt++;
        else ans++;
    }
    for(;K > 0 && cnt;K--){
        if(cnt == 1)break;
        if(cnt == 2){
            ans++;
            cnt--;
        }
        else{
            ans += 2;
            cnt -= 2;
        }
    }
    cout << ans << endl;


    return 0;
}