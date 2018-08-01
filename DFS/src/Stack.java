/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ahmed
 */
import java.io.*;

class Stack {

   int stk[]  = new int[10];
   int top ;
 Stack () 
 { 
top = -1;
    }

 void push(int item) 
 { 
 
     if (top == 9) 
System.out.println("Stack overflow");
  else  stk[++top]=item ;

   }/*end push*/ 

boolean isempty() 
 { 
 if (top < 0) 
   return true;
      else 
 return false; 
}/*end isempty*/ 

int pop() 
        { 
if (isempty())       
       { 
 System.out.println("Stack underflow");
            return 0;
        
        } 
    else 
return (stk[top--]); 
}/*end pop*/ 

 
void stacktop() 
 { 
 if (isempty()) 
        System.out.println("Stack underflow ");
           else 
System.out.println ("Stack top is"+(stk[top])); 
}/*end stacktop*/ 

 void display() 
        { 
System.out.println("Stack-->");
for (int i = 0; i <= top; i++) 
System.out.println(stk[i]);
    }/*end display*/ 
} 

