#include<stdio.h>
#include<string.h>

int match(char* a, char*b){
	int s1 = strlen(a);
	int s2 = strlen(b);

	int i;
	int j;

	int flag = 0;
	int comparisions = 0;

	for (i = 0; i < s1; i++){
		if (a[i]==b[flag]){
			flag++;
		}else{
			flag = 0;
		}

		comparisions++;
		if (flag==strlen(b)-1) return 1;
	}

	printf("%d comparisions\n", comparisions);

	return 0;
}


void main(){

	char* a = "abcddefgh";
	char* b = "def";

	printf("%d", match(a,b));
}

