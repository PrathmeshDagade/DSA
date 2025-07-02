
# include<iostream>
#include <cstdio>
using namespace std ;

   struct node 
    {
        int data ;
        struct node * next ;
        struct node * prev ;
    };

    typedef struct node NODE ;
    typedef struct node* PNODE ;
    typedef struct node** PPNODE ;


class LinkedListFunction 
{
   public : 

 ////////////////////////////////////////////////////////////////////////////

    void InsertFirst(PPNODE first , int no)
    {
        PNODE newnode = NULL ; 

        newnode = new NODE   ;

        newnode ->data = no ;
        newnode -> next = NULL ;
        newnode -> prev = NULL ; 

        if (*first == NULL )
        {
            *first = newnode ;
        }
        else 
        {
            newnode -> next = *first ;
            (*first) -> prev = newnode ;
            *first = newnode ;
        }
    }

 /////////////////////////////////////////////////////////////////////////////
    void InsertLast(PPNODE first , int no)
    {
        PNODE temp = NULL ;
        PNODE newnode = NULL ; 

        newnode = new NODE  ;

        newnode ->data = no ;
        newnode -> next = NULL ;
        newnode -> prev = NULL ; 

        if (*first == NULL )
        {
            *first = newnode ;
        }
        else 
        {
            temp = *first ;
            while (temp -> next != NULL )
            {
              temp = temp -> next ;
            }
            temp -> next = newnode ; 
            newnode-> prev = temp ;
        
        }
    }

    ////////////////////////////////////////////////////////////////////////////

    void InsertAtPos(PPNODE first , int no , int pos )
    {

        int iCnt = 0 ;
        int iCounter = 0 ;
        iCounter = Count(*first) ;

        PNODE temp = NULL ; 
        PNODE newnode = NULL ; 

        if (pos < 1 ) 
        {
            return ;
        }

        if(pos == 1 )
        {
            InsertFirst(first,no) ;
            return ;
        } 
        else if(pos == iCounter+1 )
        {
            InsertLast(first,no) ;
            return ;
        }

        if (*first == NULL )
        {
            *first = newnode ;
        }
        else 
        {
            temp = *first ;

            for (iCnt = 1 ; iCnt < pos-1 ; iCnt++ )
            {
                temp = temp -> next ;
            }
        }
        newnode = new NODE   ;

        newnode ->data = no ;
        newnode -> next = NULL ;
        newnode -> prev = NULL ; 

        newnode -> next = temp -> next ;
        temp -> next =  newnode ;
        newnode-> prev = temp ;
       
    }

    ////////////////////////////////////////////////////////////////////////////

    void DeleteFirst(PPNODE first )
    {
        PNODE temp = NULL ;

        if (*first == NULL )
        {
            return ;
        }
        else if ((*first) -> next == NULL)
        {
            free(*first) ;
            *first = NULL ;
        }
        else 
        {
            temp = *first ;

            *first = temp -> next ;
            (*first) -> prev = NULL ;
            free (temp);
        }
    }

    /////////////////////////////////////////////////////////////////////////////

    void DeleteLast(PPNODE first )
    {
        PNODE temp = NULL ;
       
        if (*first == NULL )
        {
            return ;
        }
        else if ((*first) -> next == NULL)
        {
            free(*first) ;
            *first = NULL ;
        }
        else 
        {
            temp = *first ;

            while ( temp -> next -> next != NULL )
            {
                temp = temp -> next ;
            }

            free(temp -> next ) ;
            temp -> next = NULL ;

        }
    }

    ////////////////////////////////////////////////////////////////////////////

    void DeleteAtPos(PPNODE first , int Pos )
    {
        int iCnt = 0 ;
        int iCounter = 0 ;
        iCounter = Count(*first) ;

        PNODE target =  NULL ;
        PNODE temp = NULL ; 
        PNODE newnode = NULL ; 

        if ((Pos < 1 ) || (Pos > iCounter ))
        {
            return ;
        }

        if (Pos == 1 )
        {
            DeleteFirst(first) ;
        }
        else if (Pos == iCounter)
        {
            DeleteLast(first) ;
        }
        else 
        {
            temp = *first ;

            for (iCnt = 1 ; iCnt < Pos -1 ; iCnt++ )
            {
                temp = temp -> next ;
            }

            target = temp -> next ;

            temp -> next = target -> next ;
            target -> next -> prev = temp ;
            free(target) ;

        }


    }

    //////////////////////////////////////////////////////////////////////////// 


    void Display(PNODE first)
    {
        PNODE temp = NULL ;
        temp = first ;
        while (temp != NULL )
        {
             cout << "| " << temp->data << " |-> " ;
            temp = temp -> next ;
        }
        cout<<"NULL \n " ;
    }

    ////////////////////////////////////////////////////////////////////////////

    int Count(PNODE first)
    {
        int iCount = 0 ;

        PNODE temp = NULL ;
        temp = first ;
        while (temp != NULL )
        {
           iCount++ ;
            temp = temp -> next ;
        }
       return iCount ;
    }
};

 ///////////////////////////////////////// DOUBLY LINEAR LINKEDLIST //////////////////////////////////////////

int main ()
{
   PNODE head = NULL;
    
    int iChoice = 0;
    int iValue = 0;
    int iPos = 0;
    int iRet = 0;

    LinkedListFunction lobj ;

    printf("-------------------------------------------------------------\n");
    printf("---------------- Doubly Linear LinkedList -------------------\n");
    printf("-------------------------------------------------------------\n\n");
    
    while(1)
    {
        printf("-------------------------------------------------------------\n");
        printf("------------------ Please select the option -----------------\n");
        printf("-------------------------------------------------------------\n");
        printf("1 : Insert new node at first position\n");
        printf("2 : Insert new node at last position\n");
        printf("3 : Insert new node at given position\n");
        printf("4 : Delete the node from first position\n");
        printf("5 : Delete the node from last position\n");
        printf("6 : Delete the node from given position\n");
        printf("7 : Display all elements of LinkedList\n");
        printf("8 : Count number of nodes of LinkedList\n");
        printf("0 : Terminate the application\n");
        
        printf("-------------------------------------------------------------\n");

        cin>>iChoice ;

        if(iChoice == 1)
        {
            printf("Enter the data that you want to insert : \n");
            cin>>iValue ;

            lobj.InsertFirst(&head,iValue);
        }
        else if(iChoice == 2)
        {
            printf("Enter the data that you want to insert : \n");
            cin>>iValue ;

            lobj.InsertLast(&head,iValue);
        }
        else if(iChoice == 3)
        {
            printf("Enter the data that you want to insert : \n");
            cin>>iValue ;

            printf("Enter the position at which you want to insert new node : \n");
            cin>>iPos ;

            lobj.InsertAtPos(&head,iValue,iPos);
        }
        else if(iChoice == 4)
        {
            printf("Deleting the first element from LinkedList\n");

            lobj.DeleteFirst(&head);
        }
        else if(iChoice == 5)
        {
            printf("Deleting the last element from LinkedList\n");

            lobj.DeleteLast(&head);
        }
        else if(iChoice == 6)
        {
            printf("Deleting the element from given position from LinkedList\n");

            printf("Enter the position from which you want to delete the node : \n");
            cin>>iPos ;

            lobj.DeleteAtPos(&head,iPos);
        }
        else if(iChoice == 7)
        {
            printf("Elements of the LinkedList are : \n");
            lobj.Display(head);
        }
        else if(iChoice == 8)
        {
            iRet = lobj.Count(head);
            printf("Number of elements in the LinkedList are : %d\n",iRet);
        }
        else if(iChoice == 0)
        {
            printf("Thank you for using our application\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
        printf("-------------------------------------------------------------\n");
    }
 
    return 0 ;
}