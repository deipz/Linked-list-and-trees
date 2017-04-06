#include<stdio.h>
#define MAX 10000;
int n,sum=0;
int a[10][10],wgt[10][10];
AdjacencyMatrix(int index1,int index2,int value) 
{
a[index1][index2]=value;
wgt[index1][index2]=value;

}

int shortPath(int src,int dest)
{

//int path_sum;
sum=sum+wgt[src][dest];
return dest;


}

int main()
{
int t,num,path,i,j,k,src,dest,dist,col,ret=0;
printf("enter the test cases\n");
scanf("%d",&t);
for(i=0;i<t;t++)
{
printf("enter the number of cities\n");
scanf("%d",&num);
printf("number of path details:\n");
scanf("%d",&path);
printf("path details: source    destination   distance\n");
for(i=0;i<num;i++)
{
        for(j=0;j<num;j++)
        {
                 a[i][j]=MAX;
                 wgt[i][j]=MAX;
        }
}
for(i=0;i<path;i++)
    {
        scanf("%d %d %d",&src,&dest,&dist);
        AdjacencyMatrix(src,dest,dist);
    }
/*for(i=0;i<path;i++)
{
        for(j=0;j<path;j++)
        {
                 printf("%d     ",wgt[i][j]);
                
        }
printf("\n");
}*/
for (i = 0; i < num; i++) 
{
    for (j = 0; j < num; j++) 
{
           for (k = 0; k < num; k++) 
{
               if (wgt[j][k] > wgt[j][i] + wgt[i][k]) {
                      wgt[j][k] = wgt[j][i] + wgt[i][k];
                                }
                        }
                }
        }
//DISPLAY

printf("enter the number of collection and delivery points\n");
scanf("%d",&col);
for(i=0;i<col;i++)
{
scanf("%d %d",&src,&dest);
if(i==0)
	ret=src;
if(ret!=src)
{
ret=shortPath(ret,src);
}
ret=shortPath(src,dest);
}
printf("final distance travelled\n%d",sum);
}
getch();
}
