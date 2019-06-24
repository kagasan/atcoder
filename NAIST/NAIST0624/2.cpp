#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    
    for(ll n; cin >> n, n;){
        vector<string>vec(n);
        for(ll i = 0; i < n; i++){
            cin >> vec[i];
        }
        for(ll i = n - 1; i > 0; i--){
            ll idx = 0;
            for(;vec[i][idx + 1] == '.' || vec[i][idx + 1] == '|';idx++)if(vec[i][idx] == '.')vec[i][idx] = ' ';
            vec[i][idx] = '+';
            for(ll j = i - 1; j > 0; j--){
                if(vec[j][idx] != '.')break;
                vec[j][idx] = '|';
            }
        }
        for(ll i = 0; i < n; i++){
            cout << vec[i] << endl;
        }
    }
    
    return 0;    
}