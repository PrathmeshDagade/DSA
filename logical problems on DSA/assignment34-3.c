//  Addition of all elements from singly linear linkedlist 

# include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data ; 
    struct node *next ;

} ;

typedef struct node* PNODE ;
typedef struct node** PPNODE ;
typedef struct node NODE ;
 
void InsertFirst( PPNODE first , int no ) 
{
    PNODE newnode = NULL ;
    newnode = (PNODE)malloc(sizeof( NODE)) ;

    newnode ->data = no ;
    newnode->next = NULL ;

    if (*first == NULL )     
    {
        *first = newnode ;                                            
    }
    else  
    {
        newnode->next = *first ;
        *first = newnode ;
    }

}

void InsertLast(PPNODE first , int no )
{
    PNODE temp = NULL ;
     PNODE newnode = NULL ;
    newnode = (PNODE)malloc(sizeof( NODE)) ;

    newnode ->data = no ;
    newnode->next = NULL ;

    if (*first == NULL )    
    {
        *first = newnode ;   
    }
    else  
    {
        temp = *first ;

        while (temp -> next != NULL )
        {
            temp = temp->next ; 
        }
        temp -> next = newnode ;
    }

}

void Display (PNODE first )
{
    while (first != NULL)
    {
         printf("| %d | -> ",first->data) ;
       first = first-> next ;
    }
     printf("NULL\n") ;
    
}

int Addition (PNODE first )
{

    int iSum = 0 ; 
    while (first != NULL)
    {
        iSum = iSum + first -> data ;
       first = first-> next ;
    }
    return iSum ;
}
int main ()
{
   PNODE head = NULL ; 
   int iRet = 0 ;

   
   InsertFirst(&head,70) ;
   InsertFirst(&head,30) ;
   InsertFirst(&head,50) ;
   InsertFirst(&head,40) ;
   InsertFirst(&head,30) ;
   InsertFirst(&head,20) ;
   InsertFirst(&head,10) ;

   Display(head) ;
   
  iRet = Addition (head) ;

  printf(" the addition from the singly linear linked list is : %d",iRet) ;

   


    return 0 ;
} 