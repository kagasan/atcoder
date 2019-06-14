#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll n;
    cin >> n;
    for(ll i = 111; ;i += 111){
        if(i >= n){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}