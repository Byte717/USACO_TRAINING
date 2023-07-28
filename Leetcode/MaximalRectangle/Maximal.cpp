#include <bits/stdc++.h>
#define INF 1e18
#define MOD 1e9+7
#define all(x) begin(x),end(x)
#define rall(x) x.rbegin(), x.rend()

typedef long long ll;

using namespace std;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int maxArea = 0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    if(j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = dp[i][j-1]+1;
                    }
                    int width = dp[i][j];
                    for(int k = i; k >= 0; k--){
                        width = min(width,dp[k][j]);
                        maxArea = max(maxArea, width*(i-k+1));
                    }
                }
            }
        }
        return maxArea;
    }
};



int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("","r",stdin);
    return 0;
}