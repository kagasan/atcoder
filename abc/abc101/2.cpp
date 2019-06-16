#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll s(ll n){
    ll tmp = 0;
    for(;n;n/=10)tmp+=n%10;
    return tmp;
}

int main(){
    
    ll N;
    cin >> N;
    if(N % s(N) == 0)cout << "Yes" << endl;
    else cout << "No" << endl;   
    
    return 0;
}