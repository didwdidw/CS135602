#include<stdio.h>
#include"function.h"

int main(void){
	int n,m;
	scanf("%u %u",&n, &m);
	josephus(m,create(n));
}
