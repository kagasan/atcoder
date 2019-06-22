#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll A, B, C;
    cin >> A >> B >> C;
    for(ll i = 1; ;i++){
        if(A * i % B == C){
            cout << "YES" << endl;
            return 0;
        }
        if(i > 1 && (A * i % B == A % B))break;
    }

    cout << "NO" << endl;
    
    return 0;
}