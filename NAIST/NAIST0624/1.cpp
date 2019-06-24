#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll>P;

class Team{
    public:
    vector<ll>flg, tim;
    ll name;
    P score;
    Team(ll _name, ll P){
        name = _name;
        flg = vector<ll>(P + 1, 0);
        tim = vector<ll>(P + 1, 0);
    }
    void calc(){
        score.first = 0;
        score.second = 0;
        for(ll i = 0; i < flg.size(); i++){
            if(flg[i]){
                score.first--;
                score.second += tim[i];
            }
        }
    }
    bool operator < (const Team &t)const{
        if(score == t.score)return name > t.name;
        return score < t.score;

    }
};

int main(){
    
    for(ll M, T, P, R; cin >> M >> T >> P >> R, M;){
        vector<Team>teams;
        for(ll i = 0; i <= T; i++)teams.push_back(Team(i, P));
        for(ll i = 0; i < R; i++){
            ll m, t, p, j;
            cin >> m >> t >> p >> j;
            if(teams[t].flg[p])continue;
            if(j == 0){
                teams[t].tim[p] += m;
                teams[t].flg[p] = 1;
            }
            else{
                teams[t].tim[p] += 20;
            }
        }
        vector<Team>vec;
        for(ll i = 1; i <= T; i++){
            teams[i].calc();
            vec.push_back(teams[i]);
        }    
        sort(vec.begin(), vec.end());
        for(ll i = 0; i < T; i++){
            cout << vec[i].name;
            if(i + 1 == T)cout << endl;
            else if(vec[i].score == vec[i+1].score)cout << "=";
            else cout << ",";
        }
    }
    
    return 0;    
}