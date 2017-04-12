#include<stdlib.h>
#include<stdio.h>

typedef struct node
{
int value;
int count;
struct node *next;
}Node;

Node *addOrdered(Node *, int);
void printList(Node *);
int main(int argc, char *argv[])
{
Node *head = NULL;

if(argc != 2)
{
printf("Usage: ./a.out data\n");
exit(1);
}
FILE *fp = fopen(argv[1], "r");
if(!fp)
{
printf("File %s does not exist\n", argv[1]);
exit(1);
}
int num;
fscanf(fp, "%d", &num);

while(! feof(fp))
{
head = addOrdered(head,num);
fscanf(fp, "%d", &num);
}
printList(head);
return 0;
}
Node *addOrdered(Node *head, int num)
{
Node *temp;
Node *travel,*prev;
int flag = 0;
if(head == NULL)
{
temp = (Node *)malloc(sizeof(Node));
temp->value = num;
temp->count = 1;
temp->next = NULL;
head = temp;
}
else
{
travel = head;
while(travel != NULL)
{
if(travel->value == num)
{
travel->count++;
flag = 1;
break;
}
travel = travel->next;
}
if(!flag)
{
travel = head;
prev = NULL;
temp = (Node *)malloc(sizeof(Node));
temp->value = num;
temp->count = 1;
temp->next = NULL;
while(travel != NULL)
{
if(travel->value > num)
break;

prev = travel;
travel = travel->next;

}
if(prev == NULL)
{
temp->next = head;
head = temp;
}
else
{
prev->next = temp;
temp->next = travel;
}

}
}
return head;
}

void printList(Node *head)
{
Node *travel;
travel = head;

while(travel != NULL)
{
printf("[%d-%d]\t", travel->value, travel->count);
   travel = travel->next;
}
printf("\n");

}
