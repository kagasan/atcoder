#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class hoge{
    public:
    string s;
    int p;
    int idx;
    bool operator < (const hoge &h)const{
        if(s != h.s)return s < h.s;
        return -p < -h.p;
    }
};

int main(){
    
    ll N;
    cin >> N;
    vector<hoge>v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].s >> v[i].p;
        v[i].idx = i + 1;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N; i++){
        cout << v[i].idx << endl;
    }

    return 0;
}