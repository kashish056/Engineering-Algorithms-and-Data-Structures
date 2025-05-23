#include <stdlib.h>
#include <stdio.h>


typedef struct StateMachine 
{
 char stateName;

 int variable;

 int stateNumber;

 struct StateMachine*value0;

 struct StateMachine*value1;
} 


fsm; 


fsm states[8];



  
void initialStates() 
{

 states[0].stateName = 'A';
states[0].stateNumber = 0;
states[0].value0 = states +4;
states[0].value1 = states +5;

states[1].stateName = 'B';
states[1].stateNumber = 1;
states[1].value0 = states +5;
states[1].value1 = states +3;

states[2].stateName = 'C';
states[2].stateNumber = 2;
states[2].value0 = states +6;
states[2].value1 = states +1;

states[3].stateName = 'D';
states[3].stateNumber = 3;
states[3].value0 = states +0;
states[3].value1 = states +6;

states[4].stateName = 'E';
states[4].stateNumber = 4;
states[4].value0 = states +7;
states[4].value1 = states +0;

states[5].stateName = 'F';
states[5].stateNumber = 5;
states[5].value0 = states +3;
states[5].value1 = states +7;

states[6].stateName = 'G';
states[6].stateNumber = 6;
states[6].value0 = states +1;
states[6].value1 = states +4;

states[7].stateName = 'H';
states[7].stateNumber = 7;
states[7].value0 = states +7;
states[7].value1 = states +2;
	 

}


void printCommand()
  {
int i=0;
for(i =0; i <8; i++)
     {
if(states[i].variable!= 1)
     {
     fprintf(stdout, "%c %c %c\n", states[i].stateName, states[i].value0->stateName, states[i].value1->stateName);
     }
     }
  }

int main(int argc, char * argv[])
{

int i=0;

int j=0;

char commands[1]; 

   initialStates();

 fsm currentState = states[3]; 

    
   fprintf(stdout, "Enter a command \n"); 

   
   fprintf(stdout, "The Starting State is: %c \n", currentState.stateName);


while(j != 1)
{
  
for (i=0; i<=8;i++)
   {
	scanf("%c",&commands[i]);
 
if (commands[i] == '\n')
   {
      
     printCommand();
	
     break;
   }
}
    
if(commands[0] == '0')
      {
	    fprintf(stdout, "%c\n",currentState.value0-> stateName);

		currentState = states[currentState.value0-> stateNumber];
	  }
if(commands[0] == '1')
      {
	    fprintf(stdout, "%c\n",currentState.value1-> stateName);

		currentState = states[currentState.value1-> stateNumber];
	  }
if(commands[0] == 'e')
      {
	      j=1;

		 break;
	  }
  }
    
    
if(commands[0] == 'p')
      {
	     printCommand();
	  }

   
      exit(0);	
  }



	   
	  
	

	
   

 
