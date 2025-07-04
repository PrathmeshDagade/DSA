//  write a program to display all palindrome numbers elements from linked list ; 

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

void PalindromeElement (PNODE first  )
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
        
        if (iRev == first -> data )
        {
            printf("%d\t",iRev) ;
        }

        iRev = 0 ;

        first = first -> next ;

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
   
  PalindromeElement(head) ;

  

    return 0 ;
} 