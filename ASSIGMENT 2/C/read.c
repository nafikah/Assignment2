#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 256

struct rec{
	char mydata;
};

int main()
{
	int count,i;
	char *ch,src[1];
	//char convert;
	
	FILE *fpr,*fpw;
	struct rec record;

	fpr = fopen("text", "r");

	if(!fpr)
	{
		puts("unable to open the input file");
		return 1;
	}
	
	for(count=1;count<= 10; count++){
		fread(&record,sizeof(struct rec),1,fpr);
		printf("%d\n",record.mydata);
	}

	fpw = fopen("binary.bin", "wb");

	if(!fpw)
	{
		puts("Output file is having issues while opening");
	}

	while(!feof(fpr))
	{ 	
		i=0;
		for(count = 0; count<10; count++){
		record.mydata = i;
		fseek(fpr,count,SEEK_SET);
		fwrite(&record,sizeof(struct rec),1,fpr);
		}
		
	}

	fclose(fpr);
	fclose(fpw);
	return 0;
}

