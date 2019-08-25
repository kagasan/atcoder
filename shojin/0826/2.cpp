#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, string>P;

int main(){

    ll N;
    cin >> N;
    map<string, ll>cnt;
    for(ll i = 0; i < N; i++){
        ll no;
        cin >> no;
        ll M, S;
        cin >> M >> S;
        for(ll j = 0; j < M; j++){
            string tag;
            cin >> tag;
            cnt[tag]+=S;
        }
    }
    vector<P>v;
    for(map<string, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        v.push_back(P(-(*it).second, (*it).first));
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < v.size() && i < 10; i++){
        cout << v[i].second << " " << -v[i].first << endl;
    }

    return 0;
}