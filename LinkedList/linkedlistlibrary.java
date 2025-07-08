class snode 
{
    public int data ;
    public snode next ;
}

class dnode 
{

    public int data ;
    public dnode next ;
    public dnode prev ;

}


/////////////////////////////////////////singly linear begins//////////////////////////////////////////////////////////////////////// 
class SinglyLL  
{
   private snode first ;
   private int iCount ;

   public SinglyLL ()
   {
    System.out.println("Inside Constructor ") ;
     first = null ;
     iCount = 0 ; 
   }
 
    public void InsertFirst(int no) 
    {
            snode newn = null ;
            newn = new snode() ;

            newn.data= no ;
            newn.next =null ;

            if (first == null )  // LL is empty 
            {
                 first = newn ;
            }
            else // LL contains at least one node  
            {
                newn.next = first ;
                first = newn ;   
            }
            iCount++ ;
    }


    public void InsertLast(int no) 
    {
            snode temp = null ;
            snode newn = null ;
            newn = new snode() ;

            newn.data= no ;
            newn.next =null ;

            if (first == null )  // LL is empty 
            {
                 first = newn ;
            }
            else // LL contains at least one node  
            {
                temp = first ;

                while (temp.next != null )
                {
                    temp = temp.next ;
                }
                temp.next = newn ;
                newn.next = null ;   

            }
            iCount++ ;

    }


    void Display()
    {
        snode temp = null ;
        temp = first ;

        while (temp != null )
        {
            System.out.print("|"+temp.data+"|"+"->") ;
            temp = temp.next ;
        }
        System.out.println("null") ;
    }

    int Count ()
    {
        return iCount ;
    }


    public void DeleteFirst ()
    {
        if (first == null )
        {
            return ;
        }
        
        if (first.next == null )
        {
            first = null ;
        }
        else 
        {
            first = first.next ;
        }
        iCount-- ;
    }

    public void DeleteLast ()
    {
        snode temp = null ;
        if (first == null )
        {
            return ;
        }
        
        if (first.next == null )
        {
            first = null ;
        }
        else 
        {
            temp = first ;

            while (temp.next.next != null) 
            {
                temp =temp.next ;
            }
            temp.next = null ;

        }
        iCount-- ;

    }

    public void InsertAtPos (int no , int pos )
    {
       int iCnt = 0 ;
       snode temp = null ;
       int iCounter = 0 ; 
       snode newnode = null ;
       
       iCounter = Count() ;

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
       
       temp = first ;

       for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++ )
       {
          temp=temp.next ;
       }
       newnode = new snode() ;
       newnode.next = null ;
       newnode.data = no ; 

       newnode.next = temp.next ;
       temp.next = newnode ;

       iCount++ ;
    }


    public void DeleteAtPos (int pos )
    {
       int iCnt = 0 ;
       snode temp = null ;
       int iCounter = 0 ; 
       
     
       
       iCounter = Count() ;

       if (pos < 1 || pos > iCounter)
       {
         return ;
       }

       if (pos == 1 )
       {
            DeleteFirst() ;
       }
       else if (pos == iCounter + 1 )
       {
            DeleteLast() ;  
       }
       
       temp = first ;

       for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++ )
       {
          temp=temp.next ;
       }

       temp.next = temp.next.next ;

       iCount-- ;
    }
}    

/////////////////////////////////////////singly linear end////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////singly circular begins///////////////////////////////////////////////////////////////////


class SinglyCLL 
{
    private snode first ;
    private snode last ;
    private int iCount ;

    public SinglyCLL ()
    {
        first = null ;
        last = null ;
        iCount = 0 ;
    }

   public void InsertFirst(int no ) 
    {
         snode newnode = null ;
         newnode = new snode() ;

            newnode.data= no ;
            newnode.next =null ;

            if (first == null )  // LL is empty 
            {
                newnode.next = newnode ;
                last = newnode ;
                first = newnode ;
            }
            else // LL contains at least one node  
            {
                newnode.next = first ;
                last.next = newnode ;
                first = newnode ;   
            }
            iCount++ ;
        
    }
    void InsertLast (int no ) 
    {
        snode temp = null ;
        snode newnode = null ;
        newnode = new snode() ;

        newnode.data= no ;
        newnode.next =null ;

        if (first == null )  // LL is empty 
        {
            newnode.next = newnode ;
            last = newnode ;
            first = newnode ;
        }
        else // LL contains at least one node  
        {
            temp = first ;

            while (temp.next != null )
            {
                temp = temp.next ;
            }
            temp.next = newnode ;
            newnode.next = first ; 
            last = newnode ;
        }
        iCount++ ;

    }

    void InsertAtPos (int no ,int pos ) 
    {
        int iCnt = 0 ;
       snode temp = null ;
       int iCounter = 0 ; 
       snode newnode = null ;
       
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
       
       temp = first ;

       for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++ )
       {
          temp=temp.next ;
       }
       newnode = new snode() ;
       newnode.next = null ;
       newnode.data = no ; 

       newnode.next = temp.next ;
       temp.next = newnode ;

       iCount++ ;
    }
    

    void DeleteFirst() 
    {
        if (first == null )
        {
            return ;
        }

        if (first.next == null )
        {
            first = null ;
        }
        else
        {
            first = first.next ;
        }
        iCount-- ;


    }
    void DeleteLast()
    {
        snode temp = null ;

          if (first == null )
        {
            return ;
        }

        if (first.next == null )
        {
            first = null ;
        }
        else
        {
            temp = first ;

            while(temp.next.next != null )
            {
                temp = temp.next ;
            }  
            temp.next = null ;
        }

    }
    void DeleteAtPos(int pos ) 
    {
        snode temp = null ;
        int iCnt = 0 ; 
        int iCounter = 0 ; 
        iCounter = count() ;
        
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
            DeleteLast();
        }
        else 
        {
            temp = first ;
             
            for (iCnt = 1 ; iCnt < pos -1 ; iCnt++ )
            {
                temp = temp.next ;
            }
            temp.next = temp.next.next ;
        }
        iCount-- ;

    }

    void Display () 
    {
        snode temp = null ;
        temp = first ;

        while (temp != null )
        {
            System.out.print("|"+temp.data+"|"+"->") ;
            temp = temp.next ;
        }
        System.out.println("null") ;

    }

    int count () 
    {
        return iCount ; 
    } 

}

///////////////////////////////////////////////////////singly circular end///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////doubly linear begins/////////////////////////////////////////////////////////////////


class DoublyLLL
{
    private dnode first ;
    private dnode last ;
    private int iCount ;

    public DoublyLLL ()
    {
        first = null ;
        last = null ;
        iCount = 0 ;
    }

    void InsertFirst(int no ) 
    {
        dnode newnode = null ;

        newnode = new dnode() ;

        newnode.next = null ;
        newnode.prev = null ;
        newnode.data = no ;

        if ( first == null )
        {
            first = newnode ;
            last = newnode ;
        }
        else 
        {
            newnode.next = first ;
            last.prev = first ;
            newnode.prev = null ;
            first = newnode ;
        }
        iCount++ ;

    }
    void InsertLast (int no ) 
    {

        dnode newnode = null ;

        newnode = new dnode() ;

        newnode.next = null ;
        newnode.prev = null ;
        newnode.data = no ;

        if ( first == null )
        {
            first = newnode ;
            last = newnode ;
        }
        else 
        {
            last.next = newnode ;
            newnode.next = null ;
            newnode.prev = last ;
            last = newnode ; 
        }
        iCount++ ;

    }
    void InsertAtPos (int no ,int pos ) 
    {
        int iCnt = 0 ; 
        dnode temp = null ; 
        dnode newnode = null ;
        int iCounter = 0 ; 
        iCounter = count() ;

        if ( pos < 1 || pos > iCounter + 1 )
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
                temp = temp.next ; 
            }

            newnode = new dnode() ;

            newnode.data = no ;
            newnode.next = temp.next ;
            temp.next = newnode ; 
            newnode.prev = temp ;
            newnode.next.prev = newnode ;

        }
        iCount++ ;

    }

    void DeleteFirst() 
    {
        if (first == null )
        {
            return ;
        }
        else if (first.next == null )
        {
            first = null ;
        }
        else 
        {
            first = first.next ;
        }
        iCount-- ;

    }
    void DeleteLast()
    {
        if (first == null )
        {
            return ;
        }
        else if (first.next == null )
        {
            first = null ;
        }
        else 
        {
            last = last.prev ;
            last.next = null ;
        }
        iCount-- ;

    }
    void DeleteAtPos(int pos ) 
    {
        int iCnt = 0 ; 
        dnode temp = null ; 
        int iCounter = 0 ; 
        iCounter = count() ;

        if ( pos < 1 || pos > iCounter )
        {
            return ;
        }

        if (pos == 1 )
        {
            DeleteFirst() ;
        }
        else if (pos == iCounter )
        {
            DeleteLast();
        }
        else 
        {
            temp = first ;

            for (iCnt = 1 ; iCnt < pos -1 ; iCnt++ )
            {
                temp = temp.next ; 
            }

            temp.next = temp.next.next ;
            temp.next.prev = temp ;
    
        }
        iCount-- ;



    }

    void Display () 
    {
        dnode temp = null ;

        temp = first ;

        while (temp != null )
        {
            System.out.print(temp.data+"\t");
            temp = temp.next ;
        }
        System.err.println("\n");

    }

    int count () 
    {
        return iCount  ;
    } 


}

///////////////////////////////////////////////doubly linear end/////////////////////////////////////////////////////////////////


///////////////////////////////////////////////doubly circular begins////////////////////////////////////////////////////////////


class DoublyCLL
{
    private dnode first ;
    private dnode last ;
    private int iCount ;

    public DoublyCLL ()
    {
        first = null ;
        last = null ;
        iCount = 0 ;
    }

    void InsertFirst(int no ) 
    {
        dnode newnode = new dnode() ;

        newnode.prev = null ;
        newnode.next = null ;
        newnode.data = no ;

        if ( first == null )
        {
            newnode.next = newnode ;
            newnode.prev = newnode ;
            last = newnode ;
            first = newnode ;
        }
        else 
        {
            newnode.next = first ;
            first.prev = newnode ;
            last.next = newnode ;
            newnode.prev = last ;
            first = newnode ;
        }
        iCount++ ; 
    }
    void InsertLast (int no ) 
    {
        dnode temp = null ;
        dnode newnode = null ;
        
        temp = first ;
        while (temp.next != first )
        {
            temp = temp.next ;
        }

        newnode = new dnode() ;

        newnode.data = no ;
        temp.next = newnode ;
        newnode.prev = temp ;
        newnode.next = first ;
    
        last = newnode ;
        iCount++ ;

    }
    void InsertAtPos (int no ,int pos ) 
    {
        dnode newnode = null ;
        int iCnt = 0 ;
        dnode temp = null ;
        int  iCounter = 0 ;

       iCounter = count() ;

       if (pos < 1 || pos > iCounter + 1 )
       {
         return ;
       }
       

       if (pos == 1 )
       {
         InsertFirst(no);
       }
       else if (pos > iCounter + 1 )
       {
         InsertLast(no) ;
       }
       else 
       {
           temp = first ;

           for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++ )
           {
             temp = temp.next ;
           }

           newnode = new dnode() ;

           newnode.data = no ;
           newnode.next = temp.next ;
           newnode.prev = temp ;
           temp.next = newnode ;
           newnode.next.prev = newnode ;
       }
       iCount++ ;

    }

    void DeleteFirst() 
    {
        if (first == null )
        {
            return ;
        }
        else if(first.next == first )
        {
            first = null ;
        }
        else 
        {
            first = first.next ;
            first.prev = last ;
            last.next = first ;
        }
        iCount-- ;


    }
    void DeleteLast()
    {
        dnode temp = null ;

        if (first == null )
        {
            return ;
        }
        else if(first.next == first )
        {
            first = null ;
        }
        else 
        {
            temp = first ;

           while (temp.next.next != first )
           {
                temp = temp.next ;
           }

           temp.next = first ;
        }
        iCount-- ;



    }
    void DeleteAtPos(int pos ) 
    {
      
        int iCnt = 0 ;
        dnode temp = null ;
        int  iCounter = 0 ;

       iCounter = count() ;

       if (pos < 1 || pos > iCounter )
       {
         return ;
       }
       

       if (pos == 1 )
       {
         DeleteFirst();
       }
       else if (pos > iCounter)
       {
         DeleteLast() ;
       }
       else 
       {
           temp = first ;

           for (iCnt = 1 ; iCnt < pos - 1 ; iCnt++ )
           {
             temp = temp.next ;
           }

           temp.next = temp.next.next ;
           temp.next.prev = temp ;
       }
       iCount-- ;

    }

    void Display () 
    {
        dnode temp = null ;
        temp = first ;

        do
        {
        System.out.print("|"+temp.data+"|"+"->") ;
        temp = temp.next ;
        }while (temp != first );
        System.out.print("\n");

    }

    int count () 
    {
        return iCount ; 
    } 

}

//////////////////////////////////////////////doubly circular end ///////////////////////////////////////////////////////////////

public class linkedlistlibrary
{
    SinglyLL slobj ;
    SinglyCLL scobj ;

    DoublyLLL dlobj ;
    DoublyCLL clobj ;
    
}
