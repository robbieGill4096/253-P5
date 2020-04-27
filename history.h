
#ifdef HISTORY_H_
#define HISTORY_H_
#define MAXHISTORY 10 //Smash will save the history of the last 10 commands
//Define the layout of a single entry in the history array
struct Cmd 
	{
		int exitStatus;
		int label;
		char *cmd;
	};
//struct Cmd *array[MAXHISTORY];
//Define the maximum number of entries in the  history array
//Function prototypes for the command history feature
void init_history(void); //builds data structures for recording cmd history
void add_history(char *cmd, int exitStatus); //Adds an entry to the history
void clear_history(void); //Frees all malloc'd memory in the history
void print_history(int firstSequenceNumber); //Prints the history to stdout
#endif


//--------------**Instructions**--------------------
//implement tyhe history command in, history.c with a capacity of storing exactly 10 commands.
//Consider how history behaves after the user enters more than 10 commands:

//- Smash always retains the history of the last 10 commands. When the user enters the 11th command, //smash discards the entry for the command labeled1, and records the 11 command in the last entry of //the history array. smash prints the history for the most recent 10 commands ; dont change this as //the grader's tests depend upon exactly 10 entries are printed.
