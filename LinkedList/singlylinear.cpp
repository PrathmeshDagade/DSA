// singly circular linkedlist

# include<iostream>
using namespace std ; 

struct node 
{
    int data ; 
    struct node * next ;
} ;

typedef struct node NODE ;
typedef struct node * PNODE ;

class SinglyLL 
{
  public:

  int iCount ; 
  PNODE first ;

    public : 
    SinglyLL(); 

    void InsertFirst(int) ;
    void InsertLast (int) ;
    void InsertAtPos (int,int) ;

    void DeleteFirst() ;
    void DeleteLast() ;
    void DeleteAtPos(int) ;

    void Display () ;

    int count () ; 


};
/////////////////////////////////////////////////////////////////////////////////
SinglyLL :: SinglyLL()
{
   iCount = 0 ;
   first = NULL ;
} 
///////////////////////////////////////////////////////////////////////////////////

void SinglyLL :: InsertFirst (int no )
{

    PNODE newnode = NULL ;

    newnode = new NODE ;
    newnode -> data = no ;
    newnode -> next =  NULL ;
    
    
    if (first == NULL)
    {
        first = newnode ;
    }
    else 
    {
        newnode -> next = first ;
        first = newnode ;
    }
    iCount++ ;

}

void SinglyLL :: InsertLast (int no )
{
    PNODE temp = NULL ;
    PNODE newnode = NULL ;

    newnode = new NODE ;
    newnode -> data = no ;
    newnode -> next =  NULL ;
    
    
    if (first == NULL)
    {
        first = newnode ;
    }
    else 
    {
        temp = first ;
        while (temp -> next != NULL )
        {
            temp = temp -> next ;
        }
        temp -> next = newnode ;
        newnode -> next = NULL ;
       
    }
    iCount++ ;

}

void SinglyLL ::InsertAtPos (int no , int pos )
{
    int iCnt = 0  ;
    PNODE temp = NULL ;
    PNODE newnode =NULL ;
    int iCounter = 0 ;

    iCounter = count() ;

    if (pos < 1 || pos > iCounter + 1)
    {
        return ;
    }

    if (pos == 1 )
    {
        InsertFirst(no) ;
    }
    else if (pos == iCounter + 1 )
    {
        InsertLast(no) ;
    }
    else 
    {
        temp = first ;
        for (iCnt = 1 ; iCnt < pos -1 ; iCnt++ )
        {
            temp = temp -> next ;
        }

        newnode = new NODE ;
        newnode -> data = no ;
        newnode -> next =  NULL ;

        newnode -> next = temp -> next ;
        temp -> next = newnode ;
        
        iCount++ ;
    }
}

void SinglyLL :: DeleteFirst()
{
    PNODE target = NULL ;
    if (first == NULL )
    {
        return ;
    }
    else if (first -> next == NULL )
    {
        delete first ;
        first = NULL ;
    }
    else 
    {
       target = first ; 
       first = first -> next ;
        delete target ;
    }
    iCount-- ;
}

void SinglyLL :: DeleteLast()
{
    PNODE temp = NULL ;

    if (first == NULL )
    {
        return ;
    }
    else if (first -> next == NULL )
    {
        delete first ;
        first = NULL ;
    }
    else 
    {
        temp = first ;
        
        do 
        {
            temp = temp -> next ;
        }
        while (temp -> next -> next != NULL ) ;

        delete temp -> next ;
        temp -> next = NULL ;
    }
    iCount-- ; 
}

void SinglyLL :: DeleteAtPos(int pos )
{
    int iCnt = 0  ;
    PNODE temp = NULL ;
    PNODE target = NULL ;
    int iCounter = 0 ;

    iCounter = count() ;

    if (pos < 1 || pos > iCounter)
    {
        return ;
    }

    if (pos == 1 )
    {
        DeleteFirst() ;
    }
    else if (pos == iCounter )
    {
        DeleteLast() ;
    }
    else 
    {
        temp = first ;
        for (iCnt = 1 ; iCnt < pos -1 ; iCnt++ )
        {
            temp = temp -> next ;
        }

        target = temp -> next ;
        temp -> next = temp -> next -> next ;
        delete target ;
        
        iCount-- ;
    }


}


void SinglyLL :: Display()
{
    PNODE temp = NULL ;
    temp = first ;

    do
    {
        cout<<temp->data<<"\t" ;
        temp = temp -> next ;
    }   while (temp != NULL );

}

int SinglyLL :: count()
{
 return iCount ;
}

int main ()
{
    int iRet = 0 ;

    SinglyLL lobj ;

    lobj.InsertFirst(101) ;
    lobj.InsertFirst(111) ;
    lobj.InsertFirst(51) ;
    lobj.InsertFirst(21) ;
    lobj.InsertFirst(11) ;


   lobj.InsertLast(121) ;
    lobj.InsertLast(1451) ;
    lobj.InsertLast(12551) ;

   
  
    lobj.InsertAtPos(151,5) ;

    lobj.Display() ;
    iRet = lobj.count() ;
    cout<<" the count is : "<<iRet<<"\n" ;
  
    lobj.DeleteAtPos(5);

    lobj.Display() ;
    iRet = lobj.count() ;
    cout<<" the count is : "<<iRet<<"\n" ;

    return 0 ;
}