#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

int main(){

    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll W = B - A + 1;
    ll C_OK = B / C - (A - 1) / C;
    ll D_OK = B / D - (A - 1) / D;
    ll CD_OK = B / (lcm(C, D)) - (A - 1) / (lcm(C, D));
    cout << W - C_OK - D_OK + CD_OK << endl;

    return 0;
}