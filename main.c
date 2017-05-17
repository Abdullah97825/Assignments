#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 144

//=======================================================================================//
//=======================================================================================//
//structure declerations

struct data *Healthcare_Table;
struct data {
	char firstname[MAX];
	char lastname[MAX];
	char gender;
	char date[MAX];
	int waist;
	int hip;
};

//=======================================================================================//
//=======================================================================================//
//function prototypes 

int Load_Healthcare_Table(char string[], struct data *Healthcare_Table);
void Resize_Array(int);


//=======================================================================================//
//=======================================================================================//


int main() {

    int size;
	
	size = Load_Healthcare_Table("test.txt", Healthcare_Table);
	printf("\nthe file has %d characters\n", size);
	    
    return 0;
} 

//=======================================================================================//
//=======================================================================================//


int Load_Healthcare_Table(char filename[], struct data *Healthcare_Table)
{	

	int count = 0, rows = 0, c, i = 0, eq;
	char str[MAX];
	char* str2[MAX];
	char* test[1];
	test[0] = "Lastname";
	FILE *source;
	source = fopen(filename, "r");
	
	if(source == NULL)
	{
		printf("Error: Couldn't open file \n");
		exit(1);
	}
	
	while((c = getc(source)) != '\n')
	{	
		str[i] = ("%c", c);
		i++;
	}
	str[i + 1] = '\0';
	i = 0;
	
	
	//tokenizing a line from the file
	char *token = strtok(str, " ");
	while(token != NULL) 
	{	
		
		str2[i] = token;
    	printf("token is %s\n", token);
    	token = strtok(NULL, " ");
    	i++;
	}
	str2[i +1] = '\0';


	//comparing 2 strings
	eq = strcmp(str2[1], test[0]);
	if(eq == 0)
		printf("similar\n");
	else
		printf("gg life \n");

	
	
	/*while ((c = getc(source)) != EOF)
	{	
		putchar(c);
		if(!isspace(c))
			count++;
		if(c == '\n')
			rows++;
	}*/
	

	
	printf("\nthe file has %d characters and %d rows\n", count, rows);
    Healthcare_Table = malloc(rows * sizeof(int));
	
	fclose(source);
	
	return count;
	
}

//=======================================================================================//
//=======================================================================================//



/*-------------------------- Trash ------------------*/


   /* while (fgets(line, line_size, source) != NULL)  {
        printf(line);
    }
    printf("\n");
    printf("Hello, World!\n");*/

/*	for( ; ; )
	{
		c = fgetc(source);
		printf("c is %c\n", c);
		if(c == EOF || c == '\n')
			break;
		if(!isspace(c))
			count++;
	}*/

/*-------------------------- Trash ------------------*/









