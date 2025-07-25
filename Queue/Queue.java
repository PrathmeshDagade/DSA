class node<T>
{
    public T data ; 
    public node<T> next ;
} 

class Queuex <T>
{
    private node<T> first ;
    private int iCount ;

    public Queuex ()
    {
        this.first = null ;
        this.iCount = 0 ; 
    } 

    public void enqueue(T no)      // insertlast
    {
        node<T> temp = null ;
        node<T> newn = null ;

        newn = new node<>() ;

        newn.data = no ;
        newn.next = null ;

       
        if (this.first == null )
        {
            first = newn ;
        }
        else 
        {
            temp = this.first ;

            while (temp.next != null)
            {
                temp = temp.next ;
            }
            temp.next = newn ;
    
        }

        iCount++ ;

    }

    public T dequeue ()       // deleteFirst
    {
        node<T> temp = first ;

        if (first == null )
        {
            System.out.println("unable to dequeue the queue is empty\n") ;
            return null ;
        }
        else 
        {
            first = first.next ;
            iCount-- ;
            return temp.data ;

        }

    }
         
    public int Count ()
    {
        return iCount ;
    }

    public void Display ()
    {
        node<T> temp = null ;
        temp =this.first ;

        while (temp != null )
        {
            System.out.print("|"+temp.data+"|"+'-') ;
            temp = temp.next ;
        }
        System.out.println() ;
    }

}

public class Queue
{
    public static void main (String A [] )
    {
        int iRet = 0 ;
        Queuex <Integer> sobj =  new Queuex <>() ;

      
    }
    
}

