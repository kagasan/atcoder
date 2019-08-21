#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
const ll MOD = 10007;

int main(){

    ll N;
    cin >> N;
    vector<P>v;
    for(ll i = 1; i <= N; i++){
        ll A;
        cin >> A;
        for(ll j = 1; j <= A; j++)v.push_back(P(i, j));
    }
    ll ans = 0;
    do{
        ll flg = 1;
        for(ll i = 1; i < v.size(); i++){
            if(abs(v[i].first - v[i - 1].first) <= 1)flg = 0;
        }
        if(flg)ans = (ans + 1) % MOD;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;

    return 0;    
}