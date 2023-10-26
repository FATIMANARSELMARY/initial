#include<stdio.h>
#include<stdlib.h>
void insert();
void del();
void search();
void display();
struct node
{
	int data;
	struct node*next;
};
struct node *head=NULL;
int main()
{
	int choice;
	char ch;
	
	do
	{
		printf("1.insert\n" "2.delete\n" "3.search\n" "4.display\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				display();
				break;
			case 2:
				del();
				display();
				break;
			case 3:
				search();
				display();
				break;
			case 4:
				display();
				break;
			default:
				printf("Invalid input");
	
		}
		printf("Do you want to continue:\n");
		scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');   
	
}
void insert()
{
	struct node*temp;
	struct node*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	int ele,pos,i;

	
	printf("Enter the element to be inserted:");
	scanf("%d",&ele);
	printf("Enter the position to be inserted:");
	scanf("%d",&pos);
	temp=head;
	if(pos==1)
	{
		newnode->data=ele;
		newnode->next=head;
		head=newnode;
	}
	else
	{
	
		for(i=2;i<pos;i++)
		{
		    temp=temp->next;
		}
		if(temp->next==NULL)
		{
			newnode->data=ele;
			newnode->next=NULL;
			temp->next=newnode;
		}
		else
		{
			newnode->data=ele;
			newnode->next=temp->next;
			temp->next=newnode;
		}
		
	}

}
void search()
{
	struct node*temp;
	int key;
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	temp=head;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp->data==key)
		{
			printf("Element is found at %d position",temp);	
		}
	}
}
void del()
{
	struct node*temp;
	struct node*delnode;
	int ele;
	if(head==NULL)
	{
		printf("List is empty");
	}

	else
	{
		printf("Enter the element to be deleted:");
		scanf("%d",&ele);
		temp=head;
		if(temp->data==ele)	
		{
			delnode=temp;
			head=head->next;
			free(delnode);
			head=head->next;
		}
		else
		{
			for(temp=head;temp!=NULL;temp=temp->next)
			{
				if(temp->next->data==ele)
				{
					delnode=temp->next;
					temp->next=temp->next->next;
					free(delnode);
				}
			}
		}

	}
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
	    //printf("hello");
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("%d\n",temp->data);
				
		}
	
	}
}
	



