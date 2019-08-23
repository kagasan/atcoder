#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    set<ll>S[20];
    S[0].insert(1);
    vector<ll>v = {1, 2, 5, 10};
    for(ll i = 0; i < N; i++){
        for(auto it = S[i].begin(); it != S[i].end(); it++){
            for(ll j = 0; j < 4; j++){
                S[i + 1].insert((*it) * v[j]);
            }
        }
    }
    for(auto it = S[N].begin(); it != S[N].end(); it++){
        cout << *it << endl;
    }

    return 0;
}