#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *F=NULL;
struct node *R=NULL;
void add()
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data:");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    if(F==NULL && R==NULL){
        F=R=newNode;
    }else{
        R->next=newNode;
        R=newNode;
    }
}
void Delete()
{
    struct node *temp;
    if(F==NULL && R==NULL)
    {
        printf("\nQueue Underflow....!");
        return;
    }
    if(F==R)
    {
        temp=F;
        printf("\n%d is deleted....!",F->data);
        F=NULL;
        R=NULL;
        free(temp);
    }else{
        temp=F;
        printf("\n%d is deleted....!",F->data);
        F=F->next;
        free(temp);
    }
  
}
void print()
{
    struct node *temp;
    if(F==NULL && R==NULL)
    {
        printf("\nQueue is empty.....!");
        return;
    }else{
        temp=F;
    }
    while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->next;
        }
}
int main()
{
    int ch;
    do{
        printf("\n1.Add\n2.Delete\n3.Print\n4.Exit");
        printf("Enter Ur choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            Delete();
            break;
        case 3:
            print();
            break;
        case 4:
            return 0;
            break;
        default:
            break;
        }
    }while(ch);
}