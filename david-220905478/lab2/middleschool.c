#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void main(){
	int m = 70;
	int n = 24;

	int* primes = (int*)calloc((n+1), sizeof(int)); // gives 0 if a number is prime, and -1 if a number isnt prime

	int i;
	int j;

	int operationCount= 0;

	for (i = 2; i <= n; i++){
		if (primes[i]!=-1){ //i.e if i is a prime number
			for (j = i+1; j <= n; j++){
				if ( j%i == 0 ) {
					primes[j] = -1;
					operationCount++;
				}
			}
		}
	}

	int gcd = 1;

	for (i = 2; i <= n+1; i++){
		if (primes[i] == 0){ // if the number is a prime number
			int exp = 1;
			while (m% (int)pow(i,exp) == 0 && n% (int)pow(i,exp) == 0){
				exp++;
				gcd*=i;
				operationCount++;
			}
		}
	}

	printf(" %d  is the gcd", gcd);
	printf(" %d is the operation count", operationCount);

}