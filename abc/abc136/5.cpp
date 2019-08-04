#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>A(N);
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
    }
    vector<ll>B;
    for(ll i = 1; i * i <= sum; i++){
        if(sum % i == 0){
            B.push_back(i);
            B.push_back(sum / i);
        }
    }
    ll ans = 1;
    for(ll i = 0; i < B.size(); i++){
        ll b = B[i];
        vector<ll>v;
        for(ll j = 0; j < N; j++){
            v.push_back(A[j] % b);
        }
        sort(v.begin(), v.end());
        ll cost = 0;
        ll L = 0, R = v.size() - 1;
        ll tmp = 0;
        for(;L <= R;){
            if(tmp <= 0){
                tmp += v[L];
                cost += v[L];
                L++;
            }
            else{
                tmp -= (b - v[R]);
                R--;
            }
        }
        if(cost <= K)ans = max(ans, B[i]);
    }
    cout << ans << endl;

    return 0;
}