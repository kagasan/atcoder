#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};
typedef pair<ll, ll>P;
int main(){
    ll N;
    cin >> N;
    vector<ll>A(N + 1, 0), B(N + 1, 0);
    for(ll i = 1; i <= N; i++)cin >> A[i] >> B[i];
    set<P>S;
    for(ll i = 1; i <= N; i++)S.insert(P(min(A[i], B[i]), max(A[i], B[i])));
    cout << S.size() << endl;

    return 0;
}