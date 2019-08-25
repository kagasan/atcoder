#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    string n, m;
    cin >> n;
    cin >> m;
    if(m == "0"){
        cout << 1 << endl;
        return 0;
    }
    ll a = n[n.size() - 1] - '0';
    string ans[10] = {
        "0000",
        "1111",
        "2486",
        "3971",
        "4646",
        "5555",
        "6666",
        "7931",
        "8426",
        "9191"
    };
    ll b = m[m.size() - 1] - '0';
    if(m.size() > 1)b += 10 * (m[m.size() - 2] - '0');
    b = (b + 3) % 4;
    cout << ans[a][b] << endl;


    return 0;
}