#include<stdio.h>
#include<stdlib.h>

void main(){
	int m, n;
	m = 70;
	n = 24;

	int temp = n;
	int opCount = 0;

	while (temp > 0){
		opCount++;
		if (m%temp==0 && n%temp==0) {
			printf("%d is the gcd", temp);
			printf("%d is the opCount", opCount);
			return;
		}else{
			temp--;
		}
	}
}