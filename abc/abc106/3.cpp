#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    ll K;
    cin >> K;
    for(ll i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            K--;
            if(K == 0){
                cout << 1 << endl;
                return 0;
            }
        }
        else{
            cout << s[i] << endl;
            return 0;
        }
    }
    
    return 0;
}