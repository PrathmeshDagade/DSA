# include<iostream>
using namespace std ;

struct snode
{
   int data ; 
   struct snode * next ;
} ;

typedef struct snode SNODE ;
typedef struct snode * SPNODE ;

struct dnode
{
   int data ; 
   struct dnode * next ;
   struct dnode * prev ;

} ;

typedef struct dnode DNODE ;
typedef struct dnode * DPNODE ;

////////////////////////////////////singly linear begins//////////////////////////////////////////////////////////////////////

class SinglyLL 
{
  public:

  int iCount ; 
  SPNODE first ;

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

SinglyLL :: SinglyLL()
{
   iCount = 0 ;
   first = NULL ;
} 


void SinglyLL :: InsertFirst (int no )
{

    SPNODE newnode = NULL ;

    newnode = new SNODE ;
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
    SPNODE temp = NULL ;
    SPNODE newnode = NULL ;

    newnode = new SNODE ;
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
    SPNODE temp = NULL ;
    SPNODE newnode =NULL ;
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

        newnode = new SNODE ;
        newnode -> data = no ;
        newnode -> next =  NULL ;

        newnode -> next = temp -> next ;
        temp -> next = newnode ;
        
        iCount++ ;
    }
}

void SinglyLL :: DeleteFirst()
{
    SPNODE target = NULL ;
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
    SPNODE temp = NULL ;

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
    SPNODE temp = NULL ;
    SPNODE target = NULL ;
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
    SPNODE temp = NULL ;
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


///////////////////////////////////////////////////singly linear end///////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////singly Circular begins///////////////////////////////////////////////////////////////


class SinglyCL 
{
  public:

  int iCount ; 
  SPNODE last ;
  SPNODE first ;

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

    SPNODE newnode = NULL ;

    newnode = new SNODE ;
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

    SPNODE newnode = NULL ;

    newnode = new SNODE ;
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
    SPNODE temp = NULL ;
    SPNODE newnode =NULL ;
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

        newnode = new SNODE ;
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
    SPNODE temp = NULL ;

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
    SPNODE temp = NULL ;
    SPNODE target = NULL ;
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
    SPNODE temp = NULL ;
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

//////////////////////////////////////////////////singly Circular end///////////////////////////////////////////////////////


//////////////////////////////////////////////////doubly linear begins///////////////////////////////////////////////////////

class DoublyLL 
{
    public : 

   int iCount ;
   DPNODE first ; 

    DoublyLL() ;

    void InsertFirst(int) ;
    void InsertLast(int) ;
    void InsertAtPos(int,int) ;

    void DeleteFirst() ;
    void DeleteLast() ;
    void DeleteAtPos(int) ;


    int Count();

    void Display();


} ;

DoublyLL :: DoublyLL()
{
    iCount =  0  ; 
    first = NULL ;
}

void DoublyLL :: InsertFirst(int no )
{
    DPNODE newnode =  NULL  ; 

    newnode = new DNODE ;

    newnode -> next = NULL ;
    newnode -> prev = NULL ;
    newnode -> data = no ; 

    if ( first == NULL )
    {
        first = newnode ;
    }
    else 
    {
        newnode -> next = first ;
        first -> prev = newnode ;
        first = newnode ;

    }
     iCount++ ;
   
}

void DoublyLL :: InsertLast(int no )
{
    DPNODE temp = NULL ;
    DPNODE newnode =  NULL  ; 

    newnode = new DNODE ;

    newnode -> next = NULL ;
    newnode -> prev = NULL ;
    newnode -> data = no ; 

    if ( first == NULL )
    {
        first = newnode ;
    }
    else 
    {
        temp = first ; 
       while (temp -> next != NULL )
       {
            temp = temp-> next ; 
       }
       temp -> next = newnode ; 
       newnode -> next = NULL ;
       newnode -> prev = temp ; 
    }
    iCount++ ;
}

void DoublyLL :: InsertAtPos(int no , int pos )
{
    int iCnt = 0 ; 
    int iCounter = 0 ; 
    DPNODE temp = NULL ;
    DPNODE newnode =  NULL  ; 

    newnode = new DNODE ;
   

    iCounter = Count() ;

    if ( pos < 1 || pos > iCounter+1)
    {
        return ;
    }

    if (pos == 1 )
    {
        InsertFirst(no) ;
    }
    else if (pos == iCounter + 1 )
    {
        InsertLast(no);
    }
    else 
    {
        temp = first ; 

        for (iCnt = 1 ; iCnt < pos -1 ; iCnt++ )
        {
            temp = temp -> next ;
        }

        newnode -> next = NULL ;
        newnode -> prev = NULL ;
        newnode -> data = no ; 

        newnode -> next = temp -> next ;
        newnode->prev = temp;
        temp -> next = newnode ;
        newnode -> next -> prev = newnode ;
    }
    iCount++ ;
}
void  DoublyLL :: DeleteFirst() 
{

   if (first  == NULL)
    {
        return ;
    }

    if (first -> next == NULL)
    {
        delete first ; 
        first = NULL ;
    }
    else 
    {
        first = first -> next ;
        delete first -> prev ;
        first -> prev = NULL ;
    }
    iCount --;

}

void  DoublyLL :: DeleteLast() 
{
    DPNODE temp = NULL ;

   if (first  == NULL)
    {
        return ;
    }

    if (first -> next == NULL)
    {
        delete first ; 
        first = NULL ;
    }
    else 
    {
       temp = first ;

       while (temp -> next -> next != NULL )
       {
        temp = temp -> next ;
       }

       delete temp -> next ;
       temp -> next = NULL ;

    }
    iCount --;
}

void DoublyLL :: DeleteAtPos(int pos )
{
    int iCnt = 0 ; 
    int iCounter = 0 ; 
    DPNODE temp = NULL ;
    DPNODE target = NULL ;
   
    iCounter = Count() ;

    if ( pos < 1 || pos > iCounter)
    {
        return ;
    }

    if (pos == 1 )
    {
        DeleteFirst() ;
    }
    else if (pos == iCounter)
    {
        DeleteLast();
    }
    else 
    {
        temp = first ; 

        for (iCnt = 1 ; iCnt < pos -1 ; iCnt++ )
        {
            temp = temp -> next ;
        }

        target = temp -> next ;
        temp -> next = target -> next ;
        delete target ;
        temp -> next -> prev  = temp ; 

    }
    iCount-- ;
}

void DoublyLL :: Display ()
{
    DPNODE temp = NULL ;

    temp = first ;

    while (temp != NULL )
    {
        cout<<temp->data<<"\t" ;
        temp = temp -> next ;
    }
    cout<<"\n";
    
}

int DoublyLL :: Count()
{
    return iCount ;
}


//////////////////////////////////////////////////doubly linear end////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////doubly circular begins///////////////////////////////////////////////////////////


class DoublyCLL
{
   public :

   DPNODE first ;
   DPNODE last ;
   int iCount ;

   DoublyCLL () ;

   void InsertFirst(int) ;
   void InsertLast(int) ;
   void InsertAtPos(int,int) ;

   void DeleteFirst() ;
   void DeleteLast() ;
   void DeleteAtPos(int) ;

   void Display () ;

   int Count () ;

};

DoublyCLL :: DoublyCLL ()
{
    cout<<"inside constructor "; 

    first = NULL ;
    last = NULL ;
    iCount = 0 ;
}  

void DoublyCLL :: InsertFirst(int no )
{ 
    DPNODE newnode = NULL ;

    newnode = new DNODE ;

    newnode->data = no ;
    
    if (first == NULL )
    {
        newnode->next = newnode ;
        newnode->prev = newnode ;

        last = newnode ;
        first = newnode ;
    }
    else 
    {
        newnode->next = first ;
        first -> prev = newnode ;
        newnode->prev = last ;
        last -> next = newnode ;
        first = newnode ; 
    }
    iCount++ ;
}

void DoublyCLL :: InsertLast(int no )
{ 
    DPNODE newnode = NULL ;
    newnode = new DNODE ;

    newnode->data = no ;
    
    if (first == NULL )
    {
        newnode->next = newnode ;
        newnode->prev = newnode ;

        last = newnode ;
        first = newnode ;
    }
    else 
    {
        last-> next = newnode ;
        newnode -> next = first ;
        newnode-> prev = last ;
        first ->prev = newnode ;
        last = newnode ;
    }
    iCount++ ;
}

void DoublyCLL :: InsertAtPos(int no , int pos )
{ 
    int iCnt = 0 ;
    DPNODE temp = NULL ;
    DPNODE newnode = NULL ;
    int iCounter = 0 ; 
    iCounter =  Count() ;

    newnode = new DNODE ;
    

    newnode->data = no ;
 
    if (pos < 1 || pos > iCounter + 1 )
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

        for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++  )
        {
            temp = temp -> next ;
        }

        newnode -> next = temp -> next ;
        temp -> next = newnode ;
        newnode -> prev = temp ;
        newnode -> next -> prev = newnode ;
    }
    iCount++ ;
}

void DoublyCLL :: DeleteFirst()
{
    DPNODE temp = NULL ;

    if (first == NULL )
    {
        return ;
    }
    else if (first -> next == first) 
    {
        delete first ;
        first = NULL ;
    }
    else 
    {
        first = first -> next ;
        delete first -> prev ;
        first -> prev = last ;
        last-> next = first ;

    }
    iCount-- ;
}

void DoublyCLL :: DeleteLast()
{
    DPNODE temp = NULL ;

    if (first == NULL )
    {
        return ;
    }
    else if (first -> next == first) 
    {
        delete first ;
        first = NULL ;
        last = NULL ;
    }
    else 
    {
        last = last -> prev ;
        delete last -> next ;
        last -> next = first ;
        first->prev = last;

    }
    iCount-- ;
}

void DoublyCLL :: DeleteAtPos(int pos )
{ 
    int iCnt = 0 ;
    DPNODE temp = NULL ;
    
    int iCounter = 0 ; 
    iCounter =  Count() ;


    if (pos < 1 || pos > iCounter )
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

        for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++  )
        {
            temp = temp -> next ;
        }

        temp -> next = temp -> next -> next ;
        delete temp -> next -> prev ;
        temp-> next -> prev = temp ;
    }
    iCount-- ;
}

void DoublyCLL :: Display()
{
    DPNODE temp = NULL ;

    temp = first ;

    do
    {
        cout<<temp->data<<"\t" ;
        temp = temp -> next  ;
    }
    while(temp != first ) ;

}

int DoublyCLL :: Count() 
{
    return iCount ;
}


///////////////////////////////////////////////////doubly circular end/////////////////////////////////////////////////////////

int main ()
{

    return 0 ;
}
