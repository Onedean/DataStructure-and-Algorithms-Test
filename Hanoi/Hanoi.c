#include<stdio.h>
#include<stdlib.h>
int main(){
	void Hanoi(int,char,char,char);
	int n;
	char a='A',b='B',c='C';
	scanf("%d",&n);
	Hanoi(n,a,b,c);
	system("pause");
	return 0;
}
void Hanoi(int m,char one,char two,char three){
	void move(char,char);
	if(m==1){
		move(one,three);
	}else{
		Hanoi(m-1,one,three,two);
		move(one,three);
		Hanoi(m-1,two,one,three);
	}
}
void move(char x,char y){
	printf("%c->%c\n",x,y);
}