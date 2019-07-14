#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    map<ll, ll>cnt;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        cnt[a]++;
    }
    vector<ll>v;
    for(map<ll, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        v.push_back((*it).first);
    }
    if(v.size() == 1 && v[0] == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(v.size() == 2 && v[0] == 0){
        if(cnt[v[0]] * 2 == cnt[v[1]] && cnt[v[0]] + cnt[v[1]] == N){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(v.size() == 3 && (v[0] == (v[1] ^ v[2]))){
        if(cnt[v[0]] == cnt[v[1]] && cnt[v[1]] == cnt[v[2]] && cnt[v[0]] * 3 == N){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
