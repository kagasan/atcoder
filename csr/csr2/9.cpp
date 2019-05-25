#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

bool check(ll A1, ll B1, ll A2, ll B2){
    return ((A1 + B2 - 1) / B2) > ((A2 + B1 - 1) / B1); 
}

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    ll cand = 0;
    for(ll i = 1; i < N; i++){
        if(check(A[cand], B[cand], A[i], B[i]));
        else cand = i;
    }
    for(ll i = 0; i < N; i++){
        if(i == cand)continue;
        if(check(A[cand], B[cand], A[i], B[i]));
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cand + 1<< endl;

    return 0;
}