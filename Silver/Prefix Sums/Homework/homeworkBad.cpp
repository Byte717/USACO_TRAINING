#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7

typedef long long ll;

using namespace std; 

int dirX[] = {-1, 0, 1, 0};
int dirY[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("homework.in","r",stdin);
    int n; cin >> n;
    vector<int> questions(n);
    for(int &i : questions){cin >> i;}
    sort(questions.begin(),questions.end());
    vector<int> pref(n + 1);
    pref[n] = 0;
    for(int i = n-1;i >= 0;i--){
        pref[i] = pref[i+1] + questions[i];
    }
    int MX = -1;
    map<int, vector<int>> averages;
    int elementsLeft = n-2;
    for(int k = 0; k < n-2;k++){
        int currAverage = (pref[k+1] - questions[k+1])/elementsLeft;
        averages[currAverage].push_back(k);
        MX = max(MX,currAverage);
        elementsLeft--;
    }

    for(int i = 0; i < averages[MX].size();i++){
        cout << averages[MX][i] << endl;
    }

    return 0;
}