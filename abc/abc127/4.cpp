#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
int main(){
    
    ll N, M;
    cin >> N >> M;
    vector<ll>A(N);
    for(int i = 0; i < N; i++)cin >> A[i];
    sort(A.begin(), A.end());
    priority_queue<P>Q;
    for(ll i = 0; i < M; i++){
        ll B, C;
        cin >> B >> C;
        Q.push(P(C, B));
    }
    for(ll i = 0;!Q.empty();){
        ll B = Q.top().second;
        ll C = Q.top().first;
        Q.pop();
        for(;i < N && B > 0 && A[i] < C;i++, B--){
            A[i] = C;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++)ans += A[i];
    cout << ans << endl;
    return 0;
}