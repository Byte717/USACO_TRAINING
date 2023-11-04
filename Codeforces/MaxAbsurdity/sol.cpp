
# include <iostream>
using namespace std;
long long i,j,n,m,t,l,k,r,a[200009],b[200009];
// sixth_avenue
int main()
{
    // freopen("absurd.in","r",stdin);
	cin>>n>>k;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t+a[i-1];
	}
	for (i=1;i<=n-k+1;i++)
	b[i]=a[i+k-1]-a[i-1];
	t=0;
	for (i=n-2*k+1;i>=1;i--)
	{
		if (t<=b[i+k]) { t=b[i+k]; j=i+k; }
		if (t+b[i]>=m) { m=b[i]+t; l=i; r=j; }
	}
	cout<<l<<' '<<r;
}