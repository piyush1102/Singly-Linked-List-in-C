#include<stdio.h>
#include<stdlib.h>
struct std 
{
	int data;
	struct std *next;
};
struct std* insertAtBeginning(struct std *start,int data)
{
	struct std *node;
	node=(struct std*)malloc(sizeof(struct std));
	node->data=data;
	node->next=NULL;
	if(start == NULL)
	{
		start=node;
		start->next=NULL;
	}
	else
	{
		node->next=start;
		start=node;
	}
	return start;
}

main()
{
	char ch;
	int data;
	struct std *start=NULL,*temp;
	do{
			puts("Enter the data");
			scanf("%d",&data);
			start=insertAtBeginning(start,data);
			puts("Do you want to continue(Press y to continue)");
			fflush(stdin);
			scanf("%c",&ch);
	}while(ch=='y');
	puts("Data in Linked list");
	for(temp=start;temp!=NULL;temp=temp->next)
	printf("%d\t",temp->data);
	
}
