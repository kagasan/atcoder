#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    priority_queue<double, vector<double>, greater<double> >Q;
    for(ll i = 0; i < N; i++){
        double v;
        cin >> v;
        Q.push(v);
    }
    while(Q.size() > 1){
        double x = Q.top(); Q.pop();
        double y = Q.top(); Q.pop();
        Q.push((x + y) * 0.5);
    }
    printf("%.9f\n", Q.top());

    return 0;
}