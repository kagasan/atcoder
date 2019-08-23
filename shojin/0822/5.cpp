#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

int main(){

    ll N, M;
    cin >> N >> M;
    ll c2 = 0, c5 = 0;
    for(;N % 2 == 0; N /= 2)c2++;
    for(;N % 5 == 0; N /= 5)c5++;
    for(;M % 2 == 0; M /= 2)c2--;
    for(;M % 5 == 0; M /= 5)c5--;
    while(c2 < 0 || c5 < 0){
        c2++;
        c5++;
    }
    if(gcd(N, M) != M){
        cout << -1 << endl;
        return 0;
    }
    N /= gcd(N, M);

    while(N % 10 == 0)N /= 10;
    N %= 10;

    for(ll i = 0; i < c2; i++){
        N *= 2;
        while(N % 10 == 0)N /= 10;
        N %= 10;    
    }

    for(ll i = 0; i < c5; i++){
        N *= 5;
        while(N % 10 == 0)N /= 10;
        N %= 10;    
    }

    cout << N << endl;

    return 0;
}