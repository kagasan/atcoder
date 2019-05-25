#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    for(ll i = 0; i < N; i++){
        ll tmp = abs(A[i] - B[i]);
        if(tmp == 0){
            cout << -1 << endl;
            continue;
        }
        cout << tmp << endl;
    }

    return 0;
}