#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    
    ll X;
    cin >> X;
    for(ll i = 1; ;i++){
        if(i * i * i * i == X){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
