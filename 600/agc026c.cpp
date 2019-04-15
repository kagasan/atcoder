#include <iostream>
#include <string>
#include <random>
#include <map>
using namespace std;
typedef long long ll;

int main(){

    ll rnd[18][26];
    random_device rd;
    mt19937_64 mt(rd());
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 26; j++){
            rnd[i][j] = mt();
        }
    }

    ll N;
    cin >> N;
    string s;
    cin >> s;

    ll ans = 0;
    map<ll, ll>m;
    for(ll i = 0; i < (1 << N); i++){
        ll hs = 0;
        ll idx = 0;
        for(ll j = 1, k = 0; k < N; j <<= 1, k++){
            if((i & j) == 0){
                hs ^= rnd[idx][s[k] - 'a'];
                idx++;
            }
        }
        for(ll j = (1 << (N - 1)), k = N - 1; k >= 0; k--){
            if(i & j){
                hs ^= rnd[idx][s[k] - 'a'];
                idx++;
            }
        }
        m[hs]++;
    }
    for(ll i = 0; i < (1 << N); i++){
        ll hs = 0;
        ll idx = 0;
        for(ll j = 1, k = 0; k < N; j <<= 1, k++){
            if((i & j) == 0){
                hs ^= rnd[idx][s[k + N] - 'a'];
                idx++;
            }
        }
        for(ll j = (1 << (N - 1)), k = N - 1; k >= 0; k--){
            if(i & j){
                hs ^= rnd[idx][s[k + N] - 'a'];
                idx++;
            }
        }
        ans += m[hs];
    }

    cout << ans << endl;

    return 0;
}