#include<stdio.h>
#include<stdlib.h>
struct std
{
	int data;
	struct std* next;
};
struct std* insertAtRandom(struct std* start,struct std* newNode,int n)
{
	struct std *temp=start;
	if(n<=1)
	{
		newNode->next=start;
		return newNode;
	}
	while(--n && temp!=NULL)
		temp=temp->next;
	if(temp==NULL)
	return NULL;
	
	newNode->next=temp->next;
	temp->next=newNode;
	return start;
}
main()
{
	struct std* start=NULL,*temp,*node;
	int data,n;
	char ch;
	do
	{	
		node=(struct std*)malloc(sizeof(struct std));
		puts("Enter the data");
		scanf("%d",&node->data);
		puts("Enter the position number");
		scanf("%d",&n);
		start=insertAtRandom(start,node,n);
		puts("Do you want to continue(Press 'y' to continue)");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
	puts("Data in Linked List");
	for(temp=start;temp!=NULL;temp=temp->next)
	printf("%d\t",temp->data);
	
}
