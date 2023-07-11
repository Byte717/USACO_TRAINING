#include <bits/stdc++.h>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.in","r",stdin);
    int n,q; cin >> n >> q;
    int a, b;
    int arr[n+2];
    int prefix[n+2];
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
	prefix[1] = arr[1];
	for (int i = 2; i <= n; i++) { prefix[i] = prefix[i - 1] ^ arr[i]; }

	while (q--) {
		cin >> a >> b;
		cout << (prefix[a - 1] ^ prefix[b]) << endl;
	}
    return 0;
}