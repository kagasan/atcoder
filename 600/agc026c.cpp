#include <iostream>
#include <string>
#include <random>
#include <map>
using namespace std;
typedef long long ll;

ll N;
ll rnd[18][256];
map<ll, string>hoge;

void calc(const string &str, map<ll, ll>&m){
    for(ll i = 0; i < (1 << N); i++){
        ll hs = 0;
        for(ll j = 0, k = 1, front = 0, back = N - 1; j < N; j++, k <<= 1){
            if(i & k){
                hs ^= rnd[front][str[j]];
                front++;
            }
            else{
                hs ^= rnd[back][str[j]];
                back--;
            }
        }
        m[hs]++;
        string tmp = "";
        for(ll j = 0, k = 1; j < N; j++, k <<= 1){
            if(i & k){
                tmp += str[j];
            }
        }
        for(ll j = N - 1, k = (1 << (N - 1)); j >= 0; j--, k >>= 1){
            if((i & k) == 0){
                tmp += str[j];
            }
        }
        
        hoge[hs] = tmp;
    }
}

int main(){

    random_device rd;
    mt19937_64 mt(rd());
    for(int i = 0; i < 18; i++){
        for(int j = 'a'; j <= 'z'; j++){
            rnd[i][j] = mt();
        }
    }

    cin >> N;
    string s;
    cin >> s;

    string s1 = s.substr(0, N);
    string s2 = s.substr(N, N);
    reverse(s2.begin(), s2.end());
    
    map<ll, ll>m1, m2;
    calc(s1, m1);
    calc(s2, m2);

    ll ans = 0;
    for(map<ll, ll>::iterator it = m1.begin(); it != m1.end(); it++){
        ll key = (*it).first;
        ll value = (*it).second;
        ans += m2[key] * value;
        cout << hoge[key] << " : " << m2[key] << " * " << value << " = " << m2[key] * value << endl;
    }
    cout << ans << endl;

    return 0;
}