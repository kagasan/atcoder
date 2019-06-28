#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    ll A = 0;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        A |= a;
    }
    if(A & 1)cout << "first" << endl;
    else cout << "second" << endl;

    return 0;
}