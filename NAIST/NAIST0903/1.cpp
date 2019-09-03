#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    ll ans = 0;
    ll cold = 0;
    if(A < 0)cold = 1;
    for(; A < B; ){
        if(A < 0){
            ans += C;
            A++;
        }
        else if(A == 0 && cold){
            ans += D;
            cold = 0;
        } 
        else{
            ans += E;
            A++;
        }
    }   
    cout << ans << endl;

    return 0;    
}