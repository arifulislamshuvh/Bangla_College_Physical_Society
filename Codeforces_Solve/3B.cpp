#include<cstdio>
#include<algorithm>
using namespace std;
int c[2],i,x,t,n,p,j;
pair<int,int> a[2][1<<17];
#define F(i,n) for(i=0;i<n;++i)
int main(){
	scanf("%d%d",&n,&p);
	F(i,n){
		scanf("%d%d",&t,&j);
		a[t&1][++c[t&1]]=make_pair(-j,i+1);
	}
	F(i,2)sort(a[i]+1,a[i]+c[i]+1);
	F(i,2)F(j,c[i])a[i][j+1].first+=a[i][j].first;
	n=min(p,c[1]);
	for(i=0;~n;--n)
		if((t=a[1][n].first+a[0][min(*c,(p-n)/2)].first)<x)i=n,x=t;
	printf("%d\n",-x);
	F(t,i)printf("%d ",a[1][t+1].second);
	t=min(*c,(p-i)/2);
	F(i,t)printf("%d ",a[0][i+1].second);
	return 0;
}
