#include<stdio.h>
#include<stdlib.h>
struct std
{
	int data;
	struct std *next;
};
void deleteAtRandom(struct std** start,int position)
{
	int k=1;
	struct std *prev,*curr=*start;
	if(*start==NULL)
	{
		puts("List is empty");
		return;
	}
	if(position==1)
	{
		*start=(*start)->next;
		return;
	}
	else
	{
	while(curr!=NULL && k<position)
	{
		prev=curr;
		curr=curr->next;
		k++;
	}
	if(curr==NULL)
	{
		puts("Position doesn't exist");
		return;
	}
	else
	{
		prev->next=curr->next;
		free(curr);
	}
	return;
	}
}
main()
{
	struct std *start=NULL,*temp,*node;
	char ch;
	int op,a,position;
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
				puts("Enter the position");
				scanf("%d",&position);
				deleteAtRandom(&start,position);
				for(temp=start;temp!=NULL;temp=temp->next)
				printf("%d\t",temp->data);
				break;
		}
		printf("\nPress 1 to continue\n");
		scanf("%d",&a);
	}while(a==1);
}
