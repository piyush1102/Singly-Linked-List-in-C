#include<stdio.h>
#include<stdlib.h>
struct std
{
	int data;
	struct std *next;	
};
void deleteAtLast(struct std **start)
{
	struct std *temp,*curr=*start;
	if(*start==NULL)
	{
		puts("List is empty");
		return;
	}
	while(curr->next)
	{
		temp=curr;
		curr=curr->next;
	}
	temp->next=NULL;
	free(curr);
	return;
}
main()
{
	struct std *node,*temp,*start=NULL;
	char ch;
	int op,a;
	do
	{	
		node=(struct std*)malloc(sizeof(struct std));
		puts("Enter the data");
		scanf("%d",&node->data);
		node->next=NULL;	
		if(start==NULL)
		{
			start=node;
			temp=node;
		}
		else
		{
			temp->next=node;
			temp=temp->next;
		}
		puts("Do you want to continue");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y');
	do
	{
		printf("1. Print the list \n2. Delete the list\n");
		scanf("%d",&op);
		switch(op)
			{
			case 1:
				puts("Data in list");
				for(temp=start;temp!=NULL;temp=temp->next)
				printf("%d\t",temp->data);
				break;
			case 2:
				deleteAtLast(&start);
				for(temp=start;temp!=NULL;temp=temp->next)
				printf("%d\t",temp->data);
				break;
			}
			printf("\nPress 1 to continue\n");
			scanf("%d",&a);
	}while(a==1);
}
