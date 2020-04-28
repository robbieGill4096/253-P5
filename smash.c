#include<stdio.h>
#include<string.h>
#include <errno.h>
#include <unistd.h>
#include<stdlib.h>
#include "smash.h"
//#include "smash.c"
#define MAXLINE 4096
void init_history(void); //builds data structures for recording cmd history
void add_history(char *cmd, int exitStatus); //Adds an entry to the history
void clear_history(void); //Frees all malloc'd memory in the history
void print_history(int firstSequenceNumber); //Prints the history to stdout
void executeCommand(char *str);

//char bfr[MAXLINE];

int main()
{  
char bfr[MAXLINE];//

fputs("$",stderr);
	init_history();
	while (fgets(bfr, MAXLINE,stdin) != NULL) 
	{

		
		if (strlen(bfr) == MAXLINE-1)//checks for overflow from user input.
		{ 
			exit(127);
		}
		else
		{
		
			bfr[strlen(bfr)-1] = '\0'; //replace newline with null
			//executeCommand(bfr);
			
			executeInternalCommand(bfr);
			
			fputs("$",stderr);

		}
	}
		return 0;
}


