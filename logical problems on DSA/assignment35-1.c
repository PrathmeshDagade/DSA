//  write a program which reverse all elements from linked list ; 

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

void ReverseElement (PNODE first  )
{
    int iNo = 0 ;
    int iDigit = 0 ; 
    int iRev = 0 ;

    while (first != NULL)
    {
        iNo = first -> data ;

        while (iNo != 0 )
        {
            iDigit = iNo % 10 ;
            iRev = iRev * 10 + iDigit ;
            iNo = iNo / 10 ; 
        }
        
        first -> data = iRev ;

        iRev = 0 ;

        first = first -> next ;

    }
    
}
int main ()
{
   PNODE head = NULL ; 
   int iRet = 0 ;

   
   InsertFirst(&head,725) ;
   InsertFirst(&head,35) ;
   InsertFirst(&head,543) ;
   InsertFirst(&head,454) ;
   InsertFirst(&head,312) ;
   InsertFirst(&head,29) ;
   InsertFirst(&head,176) ;

   Display(head) ;
   
  ReverseElement (head) ;

  Display(head) ;

    return 0 ;
} 