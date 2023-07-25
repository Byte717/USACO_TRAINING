#include <bits/stdc++.h>

using namespace std;


int main() {
	int n; cin >> n;
	vector<pair<int,int>> cows(n);
	for(int i = 0; i < n;i++){
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows.begin(), cows.end());

	int Time = 0;
	for(auto &i : cows){
		if(Time > i.first){
			Time += i.second; 
		}else{
			Time += i.first + i.second;
		}
	}
	cout << Time << endl;
	return 0;
}

