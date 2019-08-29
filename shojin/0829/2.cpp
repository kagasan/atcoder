#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll ans = 0;
    ll N;
    ll tmp = 0;
    cin >> N;
    ll M = N;
    ll mn = 0;
    for(;M ;M /= 2)mn += M;
    for(;N; N /= 2){
        ans = max(ans, tmp + N * 2);
        tmp += N;
    }
    cout << ans - mn << endl;


    return 0;
}