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

class SinglyCL 
{
  public:

  int iCount ; 
  PNODE last ;
  PNODE first ;

    public : 
    SinglyCL(); 

    void InsertFirst(int) ;
    void InsertLast (int) ;
    void InsertAtPos (int,int) ;

    void DeleteFirst() ;
    void DeleteLast() ;
    void DeleteAtPos(int) ;

    void Display () ;

    int count () ; 


};


SinglyCL :: SinglyCL()
{
   iCount = 0 ;
   last = NULL ;
   first = NULL ;
} 


void SinglyCL :: InsertFirst (int no )
{

    PNODE newnode = NULL ;

    newnode = new NODE ;
    newnode -> data = no ;
    newnode -> next =  NULL ;
    
    
    if (first == NULL && last == NULL )
    {
        newnode -> next = newnode ;
        first = newnode ;
        last = newnode ;
    }
    else 
    {
        newnode -> next = first ;
        last -> next = newnode ;
        first = newnode ;
    }
    iCount++ ;

}

void SinglyCL :: InsertLast (int no )
{

    PNODE newnode = NULL ;

    newnode = new NODE ;
    newnode -> data = no ;
    newnode -> next =  NULL ;
    
    
    if (first == NULL && last == NULL )
    {
        newnode -> next = newnode ;
        first = newnode ;
        last = newnode ;
    }
    else 
    {
        newnode -> next = first ;
        last -> next = newnode ;
        last = newnode ;
       
    }
    iCount++ ;

}

void SinglyCL ::InsertAtPos (int no , int pos )
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

void SinglyCL :: DeleteFirst()
{
    if (first == NULL )
    {
        return ;
    }
    else if (first -> next == first )
    {
        delete first ;
        first = NULL ;
        last = NULL ;
    }
    else 
    {
        first = first -> next ;
        delete last -> next ;
        last -> next = first ;
    }
    iCount-- ;
}


void SinglyCL :: DeleteLast()
{
    PNODE temp = NULL ;

    if (first == NULL )
    {
        return ;
    }
    else if (first -> next == first )
    {
        delete first ;
        first = NULL ;
        last = NULL ;
    }
    else 
    {
        temp = first ;
        
        do 
        {
            temp = temp -> next ;
        }
        while (temp -> next -> next != first ) ;

        delete temp -> next ;
        temp -> next = first ;
        last = temp ;
    }
    iCount-- ; 
}

void SinglyCL :: DeleteAtPos(int pos )
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


void SinglyCL :: Display()
{
    PNODE temp = NULL ;
    temp = first ;

    do
    {
        cout<<temp->data<<"\t" ;
        temp = temp -> next ;
    }   while (temp != first );

}

int SinglyCL :: count()
{
 return iCount ;
}

int main ()
{
    int iRet = 0 ;

    SinglyCL lobj ;

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
  
    lobj.DeleteAtPos(2);

    lobj.Display() ;
    iRet = lobj.count() ;
    cout<<" the count is : "<<iRet<<"\n" ;

    

  
    return 0 ;
}