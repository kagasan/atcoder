#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll D, N;
    cin >> D >> N;
    ll cnt = 0;
    for(ll i = 1; ;i++){
        ll d = 0;
        for(ll j = i; j % 100 == 0; j /= 100)d++;
        if(d == D)cnt++;
        if(cnt == N){
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}