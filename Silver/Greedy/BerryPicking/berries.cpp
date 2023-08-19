#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int LOG2(int n){
    int ret = 0; 
    while((1<<(ret+1)) <= n){ret++;}
    return ret;
}

/*
solution: if we want to minimize the amount given to elsie, then lets set q as the bound for what we give elsie
we can segment each tree into segments of q and a segment with the remaining. like 9 has 2 chunks of 4 and 1 chunk of 1.
after we count the numebr of chunks, if the number of chunks with q is less than k/2, then ignore
otherwise, elsie is given those k/2 then we count the maximum we can give bessie by slowing reducing the chunk sizes

what I learned Berry Picking:
    - Think of setting upper bounds to minimize values 



*/


int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("berries.in","r",stdin);
    int n, k; cin >> n >> k;
    int MX = -1;
    vector<int> B(n);
    for(int i = 0; i < n;i++){
        cin >> B[i];
        MX = max(MX, B[i]);
    }
    // sort(all(B));
    int MXTot = 0;
    for(int q = 1; q <= MX;q++){ // q is the max we give to elsie
        vector<int> chunks(10001,0); // represents how many  baskets of size i we have
        for(int i = 0; i < n;i++){
            chunks[q] += B[i]/q;
            chunks[B[i] % q]++;
        }
        if(k/2 > chunks[q]){ // since we need to give Elsie k/2 with q in them, if k/2 is more than q then this is not valid
            continue;
        }
        chunks[q] -= k/2;
        int BessieBuckets = 0;
        int curr = q;
        int amount = 0;
        while(curr > 0 && BessieBuckets < k/2){
            if(chunks[curr] > 0){
                amount += curr;
                BessieBuckets++;
                chunks[curr]--;
            }else{
                curr--;
            }
        }
        if(BessieBuckets == k/2){
            MXTot = max(MXTot, amount);
        }
    }
    cout << MXTot << endl;
    return 0;
}