#include <bits/stdc++.h>
 
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        int mi=1e9;int res=0;
        for(int i=n-1;i>=0;--i)
        {
            if(a[i]<=mi) {mi=a[i];continue;}
            int k=((a[i]+mi-1)/mi);res+=(k-1);
            mi=a[i]/k;
        }
        cout<<res<<'\n';
    }
    return 0;
}