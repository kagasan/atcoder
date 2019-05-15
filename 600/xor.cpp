#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void hoge(vector<ll>&v){
    for(ll a = (1LL << 60), b = (1LL << 61); a; a /= 2, b /= 2){
        int idx = -1;
        for(int i = 0; i < v.size(); i++){
            if(a <= v[i] && v[i] < b)idx = i;
        }
        if(idx < 0)continue;
        for(int i = 0; i < v.size(); i++){
            if(i != idx && (v[i] & a)){
                v[i] ^= v[idx];
            }
        }
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < v.size(); i++)cout << v[i] << " ";
    // cout << endl;
}

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(int i = 0; i < N; i++)cin >> A[i];
    for(int i = 0; i < N; i++)cin >> B[i];
    hoge(A);
    hoge(B);
    for(int i = 0; i < N; i++){
        if(A[i] != B[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}