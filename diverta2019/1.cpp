#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

    ll N, K;
    cin >> N >> K;
    cout << max(0LL, N - K + 1) << endl;

    return 0;
}