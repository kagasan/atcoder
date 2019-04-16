#include "bits/stdc++.h"
#include <random>
using namespace std;
typedef long long ll;

ll N;
ll rnd[18][256];

void func(string s, vector<map<ll, ll> >&v){
    for(ll i = 0; i < (1 << N); i++){
        ll hs = 0;
        int cnt = 0;
        for(ll j = 0, k = 1, front = 0, back = N - 1; j < N; j++, k <<= 1){
            if(i & k){
                hs ^= rnd[front][s[j]];
                front++;
                cnt++;
            }
            else{
                hs ^= rnd[back][s[j]];
                back--;
            }
        }
        v[cnt][hs]++;
    }
}

int main(){

    random_device rd;
    mt19937_64 mt(rd());
    for(int i = 0; i < 18; i++){
        for(int j = 'a'; j <= 'z'; j++){
            rnd[i][j] = mt();
        }
    }

    cin >> N;
    string s;
    cin >> s;

    string s1 = s.substr(0, N);
    string s2 = s.substr(N, N);
    reverse(s2.begin(), s2.end());
    
    vector<map<ll, ll> >v1(N + 1);
    vector<map<ll, ll> >v2(N + 1);

    func(s1, v1);
    func(s2, v2);

    ll ans = 0;
    for(int a = 0; a <= N; a++){
        for(map<ll, ll>::iterator it = v1[a].begin(); it != v1[a].end(); it++){
            ll key = (*it).first;
            ll value = (*it).second;
            ans += v2[a][key] * value;
        }
    }
    cout << ans << endl;

    return 0;
}