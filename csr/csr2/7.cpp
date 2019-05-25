#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    for(ll i = 0; i < N; i++){
        cout << gcd(A[i], B[i]) << endl;
    }

    return 0;
}