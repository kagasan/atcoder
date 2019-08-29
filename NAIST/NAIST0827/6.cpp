#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

int main(){

    ll N, K, L;
    cin >> N >> K >> L;
    vector<ll>v(N + 1, 0);
    for(ll i = 1; i <= N; i++){
        cin >> v[i];
    }
    vector<ll>v2;
    for(ll l = 1; l <= N; l++){
        for(ll r = l + K - 1; r <= N; r++){
            vector<ll>v3;
            for(ll i = l; i <= r; i++)v3.push_back(v[i]);
            sort(v3.begin(), v3.end());
            v2.push_back(v3[K - 1]);
        }
    }
    sort(v2.begin(), v2.end());
    cout << v2[L - 1] << endl;

    return 0;    
}