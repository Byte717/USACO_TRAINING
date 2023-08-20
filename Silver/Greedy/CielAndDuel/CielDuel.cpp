#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;
/*
solution: there are 2 things we can do. Pair our highest attack cards with their lowest attack cards
or we can knock out the smallest cards and deal damage directly.

What I learned: 
    - in Greedy, think of approaches and take the best one!


*/

struct Card{
    bool state;
    int strength;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    int n, m;cin >> n >> m;
    vector<Card> jiro;
    for(int i = 0; i < n;i++){
        string state; int strength;
        cin >> state >> strength;
        jiro.push_back(Card{(state == "ATK"), strength});
    }
    vector<Card> ciel;
    for(int i = 0; i < m;i++){
        int strength; cin >> strength;
        ciel.push_back(Card{1,strength});
    }
    sort(all(jiro), [](const Card&c1, const Card &c2){
        if(c1.state == c2.state) return c1.strength < c2.strength;
        return c1.strength < c2.strength;
    });
    sort(all(ciel),[](const Card&c1, const Card&c2){
        return c1.strength < c2.strength;
    });

    auto highLow = [&](){
        int ret = 0;
        for(int i = 0; i < min(n,m);i++){
            if(!jiro[i].state ||ciel[i].strength <= jiro[i].state) break;
            ret += ciel[i].strength - jiro[i].strength
        }
        return ret;
    };

    auto directDamage = [&](){
        int ret  = 0;
        vector<bool> done(n,false);
        for(int i = 0; i < n;i++){
            bool found = false;
            for(int j = 0; j < m;j++){
                if(!done[j] && ((jiro[i].state && ciel[j].state >= jiro[i].state) || (!jiro[i].state && ciel[j].state  > jiro[i].state))){
                    done[j] = true;
                    if(jiro[i].state){
                        ret += ciel[j].strength - jiro[i].strength;
                    }
                    found = true;
                    break;
                }
            }
            if(!found){
                return -1;
            }
        }
        for(int i = 0; i < m;i++){
            if(!done[i]) ret += ciel[i].strength;
        }
        return ret;
    };


    int appr1 = highLow();
    int appr2 = directDamage();
    if(appr2 == -1){
        cout << appr1 << endl;
        return 0;
    }
    cout << max(appr1,appr2) << endl;
    return 0;
}