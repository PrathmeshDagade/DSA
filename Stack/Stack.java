class node<T>
{
    public T data ; 
    public node<T> next ;
} 

class Stackx<T>
{
    private node<T> first ;
    private int iCount ;

    public Stackx ()
    {
        this.first = null ;
        this.iCount = 0 ; 
    } 

    public void push(T no)      // insertfirst 
    {
        node<T> newn = null ;

        newn = new node<T>() ;

        newn.data = no ;
        newn.next = null ;

        newn.next = first ;
        first = newn ;

        iCount++ ;

    }

    public T pop ()       // deleteFirst
    {
        node<T> temp = first ;

        if (first == null )
        {
            System.out.println("unable to pop the stack is empty\n") ;
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
            System.out.println("|"+temp.data+"|") ;
            temp = temp.next ;
        }
    }
}

public class Stack
{
    public static void main (String A [] )
    {
    
        Stackx<T> sobj =  new Stackx() ;

    }
    
}

