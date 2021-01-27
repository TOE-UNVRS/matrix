#include<cstdio>
#define N 1010
using namespace std;
int n,a[N][N],b[N][N],c[N][N];
long long ra[N],rb[N],rc[N],ca[N],cb[N],cc[N];
char BuF[1<<26],*InF=BuF;
template<typename T>void read(T &x){
	bool f=1;
	for(;47>*InF||*InF>58;f^=*InF++=='-');
	for(x=0;47<*InF&&*InF<58;x=(x<<3)+(x<<1)+(*InF++^48));
	x=f?x:-x;
}

int main(){
	freopen("matrix.in","r",stdin);        //输入文件
	fread(BuF,1,1<<26,stdin);
	read(n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			read(a[i][j]);
			ra[i]+=a[i][j];
			ca[j]+=a[i][j];
		}
	}
	fclose(stdin);
	freopen("matrix.out","r",stdin);        //输出文件
	fread(BuF,1,1<<26,stdin);
	InF=BuF; 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			read(b[i][j]);
			rb[i]+=b[i][j];
			cb[j]+=b[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			read(c[i][j]);
			rc[i]+=c[i][j];
			cc[j]+=c[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(a[i][j]!=b[i][j]+c[i][j]){
				printf("NO");
				return(0);
			}
		}
	}
	for(int i=0;i<n;++i){
		if(ra[i]!=rb[i]+rc[i]||rb[i]!=rc[i]||ca[i]!=cb[i]+cc[i]||cb[i]!=cc[i]){
			printf("NO");
			return(0);
		}
	}
	printf("YES");
	return(0);
}
