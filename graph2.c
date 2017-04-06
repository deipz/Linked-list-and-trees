#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int GREY=0;
#define WHITE 1;
#define BLACK 2;

int main()
{
int t,num,records,i,j,src,dest,flag=0;
int *arr;
printf("enter the test cases\n");
scanf("%d",&t);
for(i=0;i<t;t++)
{
printf("enter the number of nodes\n");
scanf("%d",&num);
printf("number of treaty records:\n");
scanf("%d",&records);
printf("record details: source    destination \n");

arr=(int*)malloc(num*sizeof(int));
for(i=0;i<num;i++)
{
	arr[i]=GREY;
	//printf("%d",arr[i]);
}

for(i=0;i<records;i++)
    {
        scanf("%d %d",&src,&dest);
		if(arr[src]==GREY)
			arr[src]=WHITE;
		if(arr[dest]==GREY)
			arr[dest]=BLACK;
			if(arr[src]==arr[dest])
				flag=1;
    }
if(flag==0)
	printf("POSSIBLE");
	else
		printf("NOT POSSIBLE");
}
getch();
}
