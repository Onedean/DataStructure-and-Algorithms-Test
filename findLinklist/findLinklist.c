#include<stdio.h>
int find(char *a, int n, char key) {
	int i = 0;
	while (i < n) {
		if (a[i] == key) {
			return i;
		}
		++i;
	}
	return -1;
}
void main(){
	char a[50],key;
	int n,j;
	scanf("%d %d",&n,&key);
	for(j=0;j<n;j++)
		scanf("%d",&a[j]);
	printf("%d",find(a,n,key));
}