#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>

using namespace std;

int main(){
    ifstream cin("DaisyChain.txt");
	int n;
	cin >> n;
	int petals[n];
	for (int i = 0; i < n; ++i) {
		cin >> petals[i];
	}
	int photos = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int totalPetals = 0;
			for (int k = i; k <= j; ++k) {
				totalPetals += petals[k];
			}
			bool present = false;
			for (int k = i; k <= j; ++k) {
				if (petals[k] * (j-i+1) == totalPetals) {
					present = true;
				}
			}
			if (present) {
				++photos;
			}
		}
	}
	cout << photos;
	return 0;
}