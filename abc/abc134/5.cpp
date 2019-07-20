#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};
typedef pair<ll, ll>P;

int main(){

    ll N;
    cin >> N;
    vector<ll>a(N);
    for(ll i = 0; i < N; i++)cin >> a[i];
    ll ok = N, ng = 0;
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        set<P>S;
        S.insert(P(-1, -1));
        ll flg = 1;
        for(ll i = 0; i < N; i++){
            set<P>::iterator it = S.lower_bound(P(a[i], 0));
            it--;
            if((*it).first < 0 && S.size() <= p){
                S.insert(P(a[i], i));
            }
            else if((*it).first < 0){
                flg = 0;
                break;
            }
            else{
                S.erase(it);
                S.insert(P(a[i], i));
            }
        }
        if(flg)ok = p;
        else ng = p;
    }
    cout << ok << endl;

    return 0;
}