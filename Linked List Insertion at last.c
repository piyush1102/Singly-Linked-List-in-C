#include<stdio.h>
#include<stdlib.h>
struct std
{
	int data;
	struct std *next;	
};
struct std* insertAtLast(struct std *start,int data)
{
	struct std *temp,*node;
	node=(struct std*)malloc(sizeof(struct std));
	node->data=data;
	node->next=NULL;
	if(start==NULL)
	{
		start=node;
		//start->next=NULL;
	}
	else
	{
		temp=start;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=node;
		//temp->next->next=NULL;
	}
	return start;
}
main()
{
	struct std *start=NULL,*temp;
	int data;
	char ch;
	do
	{
		puts("Enter the data");
		scanf("%d",&data);
		start=insertAtLast(start,data);
		puts("Do you want to continue(Press 'y' to continue)");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
	puts("Data in Linked list");
	for(temp=start;temp!=NULL;temp=temp->next)
	printf("%d\t",temp->data);
}
