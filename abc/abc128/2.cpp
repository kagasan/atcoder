#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int>P;
typedef pair<string, P>SP;


int main(){
    
    ll N;
    cin >> N;
    vector<SP>v(N);
    for(ll i = 0; i < N; i++){
        cin >> v[i].first;
        cin >> v[i].second.first;
        v[i].second.first *= -1;
        v[i].second.second = i + 1;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        cout << v[i].second.second << endl;
    }

    return 0;
}