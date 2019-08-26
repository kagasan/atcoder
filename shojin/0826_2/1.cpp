#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

int main(){

    ll a, b;
    cin >> a >> b;
    cout << (a * b) % MOD << endl;

    return 0;
}