#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int main(){

    ll N, X;
    cin >> N >> X;
    vector<ll>A, B;
    A.push_back(X);
    B.push_back(X);
    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;
        if(X < x)B.push_back(x);
        else A.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ans = 0;
    if(A.size() > 1)ans = A[1] - A[0];
    else ans = B[1] - B[0];
    for(ll i = 1; i < A.size(); i++){
        ans = gcd(ans, A[i] - A[i-1]);
    }
    for(ll i = 1; i < B.size(); i++){
        ans = gcd(ans, B[i] - B[i-1]);
    }
    cout << ans << endl;

    return 0;
}