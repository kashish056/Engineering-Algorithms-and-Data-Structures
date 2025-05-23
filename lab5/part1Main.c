#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//the 3 functions from intStack.c
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
	//the 3 variable functions
  int ch;
  int mainPop;

  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;

   //the input if ch == '<'
  else if(ch == '<')
   {
   
   //ch will be inserted an alphabet
   ch = getchar();

   //if statement checks if the "ch" is an alphabet, then push the character
	if(isalpha(ch))
      {
		push(ch); 
      }

  //if statement starts with "/", the character will be popped out of the chain.
   else if(ch == '/') 
     {
     ch = getchar();
     mainPop = pop();						 

 //it will be non-valid, then pop does not equal to the top character
    if(mainPop != ch)
	 {
          
	fprintf(stderr,"Valid\n"); 
	 exit(1); 
	 }
	
  
   else 
	{
	fprintf(stdout,"Valid\n"); 
	exit(0); 
	} 
   }
 }
}
  
	
    if(isEmpty()== 1) 
	{
		fprintf(stderr," Valid \n");
		exit(1);   
	}
    else if (isEmpty() == 0)
	{

      fprintf(stdout,"Non-Valid\n");
 	  exit(0);   
    }   
   exit(0);
  }
