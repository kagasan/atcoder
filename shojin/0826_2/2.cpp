#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;

int main(){

    ll N;
    cin >> N;
    vector<P>v;
    for(ll i = 0; i < N; i++){
        ll g, d;
        cin >> g >> d;
        v.push_back(P(-(g - 30000 * d), i + 1));
    }    
    sort(v.begin(), v.end());
    if(v[0].first * (-6) < 3000000){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        for(ll i = 0; i < 6; i++){
            cout << v[0].second << endl;
        }
    }

    return 0;
}