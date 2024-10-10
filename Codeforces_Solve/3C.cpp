#include<iostream>
using namespace std;
char g[11],s;
bool r(int q,int w,int e){return s==g[q]&&s==g[w]&&s==g[e];}
bool c(char x){s=x;return r(0,1,2)||r(0,4,8)||r(8,9,10)||r(2,6,10)||r(1,5,9)||r(4,5,6)||r(0,5,10)||r(2,5,8);}
int main(){
	int i,k=0,n=0;
	for (i=0;i<11;i++){scanf("%c",&g[i]);g[i]=='X'?k++:g[i]=='0'?n++:n;}
	if (abs(k-n)>1||n>k||c('X')&&c('0')||k>n&&c('0')||k==n&&c('X'))cout<<"illegal";
	else if(c('X')||c('0'))c('0')?cout<<"the second player won":cout<<"the first player won";
	else k+n==9?cout<<"draw":k==n?cout<<"first":cout<<"second";
}
