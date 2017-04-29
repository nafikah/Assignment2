#include<stdio.h>
#include<string.h>
#define MAX 256

int main() {
	FILE *fpr,*fpw;
	int ch, ch2;
	char string [100], *begin, *end, temp, tgt[MAX];

	fpr = fopen("text", "rt");

	if(fpr == NULL) {
		printf("Error couldnt open file\n");
		return(-1);
	}

	while(fgets(string, sizeof(string), fpr) != NULL){
		begin = string;
		end = begin + strlen(string) -1;

		while(end>begin){
			temp = *end;
			*end = *begin;
			*begin = temp;
			++begin;
			--end;
		}
	}

	fpw = fopen("OutputInverse","wt");
	fprintf(fpw, "%s", string);
	printf("%s\n",string);

		fclose(fpr);
		fclose(fpw);
		return 0;
}
