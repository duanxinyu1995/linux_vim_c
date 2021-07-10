#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
void bubblesort(int *k, int n)
{
	int flag=0, temp;
	for(int i=0;i<n-1;i++)
	{
		flag=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(k[j]>k[j+1])
			{
				temp=k[j+1];
				k[j+1]=k[j];
				k[j]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
void quicksort(int *num, int i, int j){
	int left, right, base, temp;
	left= i;
	right=j;
	base=num[i];
	while(left<right){
		while(num[right]>base&&left<right)
			right--;
		while(num[left]<=base&&left<right)
			left++;
		if(right>left)
		{
			temp=num[right];
			num[right]=num[left];
			num[left]=temp;
		}
	
	}
	num[i]=num[left];
	num[left]=base;
	quicksort(num, i, left-1);
	quicksort(num, left+1, j);
}
int main()
{	
	int *nums=(int *)malloc(sizeof(int));
	int count=0, num;
	char s;
	printf("enter the list of number:\n");
	while(scanf("%d", &num)!=EOF)
	{
		count++;
		nums=(int *)realloc(nums, count * sizeof(int));
		nums[count-1]=num;
		s=getchar();
		if(s=='\n')
			break;
	}
	printf("the list you entered is:\n");
	for(int i=0;i<count;i++)
	{
		printf("%d", nums[i]);
	}
	bubblesort(nums, count);
	printf("sorted list is as follow:\n");
	for(int i=0;i<count;i++)
	{
		printf("%d", nums[i]);
	}
	printf("\n");
	quicksort(nums, 0, count-1);
	printf("the quicksorted list:\n");
	for(int i=0;i<count;i++)
		printf("%d", nums[i]);
	printf("\n");

}
