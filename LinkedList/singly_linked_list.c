#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

Node* createNode(int val)
{
	Node* temp = (Node*)(malloc(sizeof(Node)));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void print_list(Node* head)
{
	printf("List : ");
	while(head->next != NULL)
	{
		head = head->next;
		printf("%d ", head->data);		
	}
	printf("\n");
}

int size(Node* head)
{
	int count = 0;
	while(head->next != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

void push_front(Node* head ,int val)
{
	Node* temp = createNode(val);
	temp->next = head->next;
	head->next = temp;
}

int pop_front(Node* head)
{
	Node* temp = head->next;
	int val = temp->data;
	head->next = temp->next;
	free(temp);
	return val;
}

void push_back(Node* head, int val)
{
	while(head->next != NULL)
	{
		head = head->next;
	}
	Node* temp = createNode(val);
	head->next = temp;
	temp->next = NULL;
}

int pop_back(Node* head)
{
	while(head->next->next != NULL)
	{
		head = head->next;
	}
	int val = head->next->data;
	head->next = NULL;
	return val;
}

int front(Node* head)
{
	return head->next->data;
}

int back(Node* head)
{
	while(head->next->next != NULL)
	{
		head = head->next;
	}
	int val = head->next->data;
	return val;
}

int valueAt(Node* head, int index)
{
	int count = 0;
	while(count<index && head->next != NULL)
	{
		head = head->next;
		count++;
	}
	return head->data;
}

void insertAt(Node* head, int index, int val)
{
	int count = 0;
	while(count<index-1 && head->next != NULL)
	{
		head = head->next;
		count++;
	}
	Node* temp = createNode(val);
	temp->next = head->next;
	head->next = temp;
}

void erase(Node* head, int index)
{
	int count = 0;
	while(count<index-1 && head->next != NULL)
	{
		head = head->next;
		count++;
	}
	Node* temp =  head->next;
	head->next = temp->next;
	free(temp);
}

int value_from_end(Node* head, int index)
{
	while(head->next != NULL)
	{
		head = head->next;
	}
	int count = 1;

}

void reverse(Node* head)
{
	while(head->next != NULL)
	{
		Node* temp = createNode(0);
		temp = head->next->next;
		head->next = head;
		head = head->next;
	}
}

void remove_val(Node* head, int val)
{
	int count = 0;
	Node* root = head;
	while(head->next != NULL && head->data != val)
	{
		head = head->next;
		count++;
	}
	if(head->next != NULL)
	{
		erase(root, count);
	}
}

int main()
{
	printf(" 1. push_front  2.size     3.print    4.pop_front  5.push_back   6.pop_back 7.front 8.back \n");
	printf(" 9. valueAt    10.eraseAt 11.reverse 12.insertAt  13.remove_val 14.exit\n");
	int choice = 0, data, index;
	scanf("%d",&choice);
	Node* head;
	head->next=NULL;
	while(choice != 14)
	{		
		switch(choice)
		{
			case 1: scanf("%d",&data);
					push_front(head, data);
					print_list(head);
					break;
			case 2:	printf("%d\n", size(head));
					break;
			case 3:	print_list(head);
					break;
			case 4:	printf("%d\n", pop_front(head));
					print_list(head);
					break;
			case 5: scanf("%d",&data);
					push_back(head, data);
					print_list(head);
					break;
			case 6:	printf("%d\n", pop_back(head));
					print_list(head);
					break;
			case 7:	printf("%d\n", front(head));
					print_list(head);
					break;
			case 8:	printf("%d\n", back(head));
					print_list(head);
					break;
			case 9:	scanf("%d",&index);
					printf("%d\n", valueAt(head, index));
					print_list(head);
					break;	
		   case 10: scanf("%d",&index);
					erase(head, index);
					print_list(head);
		   			break;	
		   case 12: scanf("%d",&index);
		   			scanf("%d",&data);
					insertAt(head, index, data);
					print_list(head);
		   			break;
		   case 13: scanf("%d",&data);
					remove_val(head, data);
					print_list(head);
		   			break;		
			default:printf("Exitting\n");
		}
		scanf("%d",&choice);
	}
	return 0;
}