#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    ll N;
    cin >> N;
    vector<ll>vec(N);
    for(ll i = 0; i < N; i++)cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(ll i = 0; i < N; i++){
        cout << vec[i];
        if(i + 1 < N)cout << " ";
        else cout << endl;
    }
    return 0;
}