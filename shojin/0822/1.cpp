#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    for(ll i = N; i >= 1; i--){
        for(ll j = 0; j < i; j++)cout << N;
        cout << endl;
    }

    return 0;
}