#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    ll N;
    cin >> N;
    for(ll i = 1; i <= N; i++){
        ll a;
        cin >> a;
        cout << a;
        if(i < N)cout << ",";
        else cout << endl;
    }
    return 0;
}