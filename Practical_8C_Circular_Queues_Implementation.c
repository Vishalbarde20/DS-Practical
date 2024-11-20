#include <stdio.h>
#define MAX 5

int myQueue[MAX];
int F = -1;
int R = -1;

void add()  
{
    int item;
    printf("\nEnter Item: ");
    scanf("%d", &item);

    if ((R + 1) % MAX == F) 
    {
        printf("\nQueue Overflow!");
        return;
    }
    
    if (F == -1) 
    {
        F = 0;
        R = 0;
    }
    else
    {
        R = (R + 1) % MAX; 
    }

    myQueue[R] = item;
    printf("\n%d added to the queue.", item);
}

void Delete()  
{
    if (F == -1) 
    {
        printf("\nQueue Underflow!");
        return;
    }

    printf("\n%d is deleted...", myQueue[F]);

    if (F == R) 
    {
        F = -1;
        R = -1;
    }
    else
    {
        F = (F + 1) % MAX; 
    }
}

void print() 
{
    if (F == -1)
    {
        printf("\nQueue is empty!");
        return;
    }

    printf("\nQueue elements are: ");
    int i = F;
    while (1)
    {
        printf("%d ", myQueue[i]);
        if (i == R) 
            break;
        i = (i + 1) % MAX; 
    }
    printf("\n");
}

int main()
{
    int ch;
    do
    {
        printf("\n1. Add\n2. Delete\n3. Print\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

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
                printf("\nExiting program...");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (ch != 4);

    return 0;
}