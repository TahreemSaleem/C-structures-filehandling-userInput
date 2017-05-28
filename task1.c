#include<stdio.h>
#include<conio.h>
struct time{
	int id;
	int hours;
	int minutes;
	int sec;
};
int main(){
	FILE *cfptr;
	struct time abc;
	int t;
	int i;

	char a[20]="The time is: ";
	
	
	abc.id=1;
	
	printf("Enter The time \n");
	
	scanf("%d",&t);
	
	abc.sec=t%60;
	
	i=t/60;
	
	abc.minutes=i%60;
	
abc.hours=i/60;
	if((cfptr=fopen("abc.txt", "w"))==NULL)
		printf("the file could not be opened\n");
	else{
		fprintf(cfptr,"%s", a);
		fclose(cfptr);
	}
	if((cfptr=fopen("abc.txt","rb+"))==NULL)
		printf("the file could not be opened\n");
	else{
		fseek(cfptr,sizeof(a), SEEK_SET);
		fwrite(&abc, sizeof(struct time),1,cfptr);
		fclose(cfptr);
	}
	if((cfptr=fopen("abc.txt","rb+"))==NULL)
		printf("the file could not be opened\n");
	else{
		fseek(cfptr,sizeof(a), SEEK_SET);
		fread(&abc, sizeof(struct time),1,cfptr);
		printf("%d:%d:%d\n",abc.hours,abc.minutes,abc.sec);
		fclose(cfptr);
	}
	
	return 0;
}

