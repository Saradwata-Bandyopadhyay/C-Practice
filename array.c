//c program to perform all array operations
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void arrayprint(int[],int);
int arraysearch(int[],int,int);
int main()
{
	int n,*arr,*arr2,i,o,a,elementd,elements,pos,ne,np;
	do
	{
	printf("\nChoose an option from the given list => ");
	printf("\nEnter 1 to Perform array operation");
	printf("\nEnter 2 to exit\n");
	scanf("%d",&a);
	if(a==1)
	{
	printf("\nHow many elements do you want to enter => ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	if(arr==NULL)
	{
	printf("\nUnable to Allocate memory !!!\n");
	exit(1);
	}
	printf("\nEnter values for the array => \n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	arrayprint(arr,n);
	do
	{
	printf("\nEnter 1 to Insert an element in the array");
	printf("\nEnter 2 to Delete an element from the array");
	printf("\nEnter 3 to print the array");
	printf("\nEnter 4 to search for an element in the array");
	printf("\nEnter 5 to go back to main menu\n");
	scanf("%d",&o);
	switch(o)
	{
	case 1:
		printf("\nEnter the element to be inserted => ");
		scanf("%d",&ne);
		printf("\nEnter the position where the element will be inserted => ");
		scanf("%d",&np);
		if(np<=0||np>n+1)
		{
		printf("\nElement cannot be entered there !!!\n");
		break;
		}
		else
		{
		arr2=(int*)malloc((n+1)*sizeof(int));
		if(arr2==NULL)
		{
		printf("\nUnable to Allocate memory !!!\n");
		exit(1);
		}
		for(i=0;i<n+1;i++)
		{
			if(i>np-1)
			arr2[i]=arr[i-1];
			else if(i==np-1)
			arr2[np-1]=ne;
			else arr2[i]=arr[i];
		}
		arr=(int*)malloc((n+1)*sizeof(int));
		if(arr==NULL)
		{
		printf("\nUnable to Allocate memory !!!\n");
		exit(1);
		}
		arr=arr2;
		free(arr2);
		n=n+1;
		printf("\nElement Inserted successfully\n");
		}
		break;
	case 2:
		if(n==0)
		printf("\nArray is empty!!!\n");
		else
		{
		printf("\nEnter the element to be deleted => ");
		scanf("%d",&elementd);
		pos=arraysearch(arr,n,elementd);
		if(pos==-1)
		{
		printf("\nElement not found\n");
		break;
		}
		else
		for(i=pos;i<n-1;i++)
		{
			arr[i]=arr[i+1];
		}
		n=n-1;
		printf("\nElement deleted successfully\n");
		}
		break;
	case 3:
		if(n==0)
		printf("\nArray is empty!!!\n");
		else arrayprint(arr,n);
		break;
	case 4:
		if(n==0)
		printf("\nArray is empty!!!\n");
		else 
		{
		printf("\nEnter the element to be searched => ");
		scanf("%d",&elements);
		pos=arraysearch(arr,n,elements);
		if(pos==-1)
		printf("\nElement not found\n");
		else
		printf("\nElement found at position => %d\n",pos+1);
		}
		break;
	case 5: 
		o=5;
		break;
	default:printf("\nInvalid input\n");
	}
	}while(o!=5);
	}
	else exit(1);
	free(arr);
	}while(a!=0);
	return 0;
}
void arrayprint(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}
int arraysearch(int arr[],int n,int element)
{
	int i,pos;
	for(i=0;i<n;i++)
		if(arr[i]==element)
		{
		pos=i;
		break;
		}
		else pos=-1;
	return pos;
}
//Coded by Saradwata Bandyopadhyay
