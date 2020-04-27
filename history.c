#include "history.h"
#include<string.h> 
#include<stdio.h> 
#include<stdlib.h> 
#define MAXHISTORY 10 //Smash will save the history of the last 10 commands

struct Cmd 
	{
		int exitStatus;
		int label;
		char cmd[];
	};


struct Cmd *array[MAXHISTORY];
int init_label=0;

void add_history(char* cmd,int exitStatus)
	{
		if(init_label > 9){
			free(array[0]);
			array[0]=array[1];
			array[1]=array[2];
			array[2]=array[3];
			array[3]=array[4];
			array[4]=array[5];
			array[5]=array[6];
			array[6]=array[7];
			array[7]=array[8];
			array[8]=array[9];
			array[9]=malloc(sizeof(struct Cmd) + sizeof(char) * strlen(cmd));
			strcpy(array[9]->cmd,cmd);
			array[9] -> exitStatus = exitStatus;
			array[9] ->label = init_label;
			init_label++;
			

		}
		else
		{
			array[init_label]=malloc(sizeof(struct Cmd) + sizeof(char) * strlen(cmd));
			strcpy(array[init_label]->cmd,cmd);
			array[init_label] -> exitStatus = exitStatus;
			array[init_label] -> label = init_label;
			init_label++;



		}
		




		
	}
	

void init_history(void){


}
void print_history(int firstSequenceNumber) {
	if (init_label < 10){

			for(int i=0; i< init_label; i++)
					{
					

						printf("[%d] %s\n",array[i]->exitStatus,array[i]->cmd);	
				
					}
			}
	else
	{
		for(int i=0; i< MAXHISTORY; i++)
		{
		

			printf("[%d] %s\n",array[i]->exitStatus,array[i]->cmd);	
			
		}

	}
		
			
}


void clear_history(void) {
	init_label=0;
	for(int i=0; i<MAXHISTORY;i++)
		{
			free(array[i]);
		}

}


