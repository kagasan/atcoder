#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    double sum = 0;
    for(ll i = 1; i <= N; i++){
        double a;
        cin >> a;
        sum += 1 / a;
    }
    printf("%.9f\n", 1 / sum);

    return 0;
}