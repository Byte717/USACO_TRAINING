#include <bits/stdc++.h> 

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("convention2.in","r",stdin);
    int n; cin >> n; 
    vector<pair<int,pair<int,int>>> cows;
    for(int i = 0; i < n; i++){
        int a, t; 
        cin >> a >> t; 
        cows.push_back(make_pair(a,make_pair(i,t)));
    }
    int ans = 0, current_finished; 
    int nextCow = 1;
    set<pair<int,int>> waiting; 
    sort(cows.begin(), cows.end());
    current_finished = cows[0].first + cows[0].second.second;
    while(nextCow < n || waiting.size() > 0){
        while(nextCow < n && cows[nextCow].first <= current_finished){ // keep adding to waitlist
            waiting.insert(make_pair(cows[nextCow].second.first, nextCow));
            nextCow++;
        }

        if(waiting.size() == 0 && nextCow < n){
            current_finished = cows[nextCow].first + cows[nextCow].second.second;
            nextCow++;
        }else if(waiting.size() > 0){
            set<pair<int,int>>::iterator most_Senior = waiting.begin();
            ans = max(ans, current_finished - cows[most_Senior->second].first);
            current_finished = current_finished + cows[most_Senior->second].second.second;
            waiting.erase(most_Senior);
        }
    }
    freopen("convention2.out","w",stdout);
    cout << ans << endl;
    return 0;
}