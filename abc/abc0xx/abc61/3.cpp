#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, K;
    cin >> N >> K;
    vector<ll>A(101010, 0);
    for(ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        A[a] += b;
    }
    for(ll i = 1; ; i++){
        K -= A[i];
        if(K <= 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
