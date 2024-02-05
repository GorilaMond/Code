#include <stdio.h>
#include <malloc.h>
int main(void) {
#define swap(a,b) ({t=a;a=b;b=t;})
	unsigned char **mat, m, n, l, s, t;
	short i, j;
	scanf("%hhu %hhu", &m, &n); l=m>n?m:n;
	mat=malloc(sizeof(char*)*l);
	for(i=0;i<l;i++) mat[i]=malloc(l);
	for(i=0;i<m;i++) for(int j=0; j<n; j++) scanf("%hhu", mat[i]+j);
	getchar(); while((s=getchar())!='\n') {
		if(s=='B'||s=='C')
			for(i=0;i<m;i++) for(j=(n-1)/2;j>=0;j--) swap(mat[i][j],mat[i][n-j-1]);
		else if(s=='A'||s=='D')
			for(i=(m-1)/2;i>=0;i--) for(j=0;j<n;j++) swap(mat[i][j],mat[m-i-1][j]);
		if(s=='A'||s=='B') {
			if(m>=n) for(i=0;i<m;i++) for(j=0;j<i;j++) swap(mat[i][j],mat[j][i]);
			else for(i=0;i<m;i++) for(j=i+1;j<n;j++) swap(mat[i][j],mat[j][i]);
			swap(m,n);
		}
	}
	for(i=0;i<m;i++) {
		for(j=0;j<n-1;j++) printf("%hhu ", mat[i][j]);
		printf("%hhu\n", mat[i][j]);
	}
}