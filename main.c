#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 144

//=======================================================================================//
//=======================================================================================//
//structure declerations


typedef struct{
	char firstname[MAX];
	char lastname[MAX];
	char gender;
	char date[MAX];
	int waist;
	int hip;
}data;
data data_var; 
data *Healthcare_Table;

//=======================================================================================//
//=======================================================================================//
//function prototypes 

data get_row(FILE *);
int Load_Healthcare_Table(FILE *, data *Healthcare_Table);
int Rows_Num(FILE *);




//=======================================================================================//
//=======================================================================================//


int main() {

    int size;
	FILE *source, *temp;
	source = fopen("healthcare.txt", "r");
	size = Load_Healthcare_Table(source, Healthcare_Table);
	printf("\nthe file has %d rows\n", size);
	
	free(Healthcare_Table);
	fclose(source);    
    return 0;
} 

//=======================================================================================//
//=======================================================================================//


int Load_Healthcare_Table(FILE *source, data *Healthcare_Table)
{	

	int count = 0, rows = 0, c, i = 0, j, columns = 5, eq;

	
	if(source == NULL)
	{
		printf("Error: Couldn't open file \n");
		exit(1);
	}
	
	while ((c = getc(source)) != EOF)
	{	
		if(!isspace(c))
			count++;
		if(c == '\n')
			rows++;
	}
	
	Healthcare_Table = (data*) malloc(sizeof(data)* rows);
	printf("number of rows equals %d\n", rows);
	fseek(source, 0, SEEK_SET);
	
	for(i = 0; i < rows; i++)
	{
		Healthcare_Table[i] = get_row(source);
	}
	
		
	return rows;
	
}

//=======================================================================================//
//=======================================================================================//

int Rows_Num(FILE *source){
	
	char c;
	int rows = 0;
	
	while((c = fgetc(source)) != EOF){
		
		if(c == '\n')
			rows++;
	}
	
	return rows;
	
}


//=======================================================================================//
//=======================================================================================//

data get_row(FILE *source){
	data line;
	char str[MAX], c, buffer[MAX];
	int i = 0, j = 0, length;
	
	fgets(buffer, MAX, source);
	
	fscanf(source, "%s %s %c %s %d %d", &line.firstname, &line.lastname, &line.gender, &line.date, &line.waist, &line.hip);
	printf("scanned %s %s %c %s %d %d\n", line.firstname, line.lastname, line.gender, line.date, line.waist, line.hip);
	
	printf("all good\n");
	return line;
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
	
	//tokenizing a line from the file
/*	char *token = strtok(str, " ");
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
		printf("gg life \n");*/
		
		
	/*while((c = getc(source)) != '\n')
	{
		str[i] = c;
		i++;	
	}
	str[i] = '\0';
	length = strlen(str);
	for(i = 0; i < length; i++)
	{
		printf("string element is %c\n", str[i]);
	}
	i = 0;
	*/


/*-------------------------- Trash ------------------*/









