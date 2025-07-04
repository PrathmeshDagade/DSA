//  write a program to find product of single node from linked list ; 

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

void ProductElement (PNODE first  )
{
    int iNo = 0 ;
    int iDigit = 0 ; 
    int iProduct = 1 ;

    while (first != NULL)
    {
        iNo = first -> data ;

        while (iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iProduct = iProduct * iDigit ;
            iNo = iNo / 10 ; 
        }
        
        printf("%d\t",iProduct) ;

        first = first -> next ;

        iProduct = 1 ;
    }

}
int main ()
{
   PNODE head = NULL ; 
   int iRet = 0 ;

   
   InsertFirst(&head,111) ;
   InsertFirst(&head,35) ;
   InsertFirst(&head,6) ;
   InsertFirst(&head,454) ;
   InsertFirst(&head,212) ;
   InsertFirst(&head,49) ;
   InsertFirst(&head,176) ;

   Display(head) ;
   
  ProductElement(head) ;

  

    return 0 ;
} 