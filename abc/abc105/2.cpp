#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){
    
    ll N;
    cin >> N;
    for(ll i = 0; i <= N; i+=4){
        for(ll j = 0; j <= N; j += 7){
            if(i + j == N){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}