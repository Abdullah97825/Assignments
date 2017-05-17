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


//=======================================================================================//
//=======================================================================================//
//function prototypes 

//data get_row(FILE *);
int Load_Healthcare_Table(FILE *, data *Healthcare_Table);
int Rows_Num(FILE *);
void Display_Healthcare_Table(data *Healthcare_Table, int);
int Search(data *Healthcare_Table, int, char [], char []);


//=======================================================================================//
//=======================================================================================//


int main() {

    int size;
	FILE *source, *temp;
	data *Healthcare_Table;
	
	source = fopen("healthcare.txt", "r");
	
	size = Load_Healthcare_Table(source, Healthcare_Table);
	printf("\nthe file has %d rows\n", size);
	printf("first element in the array is %s\n", Healthcare_Table[0].firstname);	
	
	free(Healthcare_Table);
	   
    return 0;
} 

//=======================================================================================//
//=======================================================================================//


int Load_Healthcare_Table(FILE *source, data *Healthcare_Table)
{	

	int count = 0, rows = 0, c, i = 0, j, columns = 5, similarity;
	char first[MAX], last[MAX];
	
	if(source == NULL)
	{
		printf("Error: Couldn't open file \n");
		exit(1);
	}
	
	printf("Healthcare records file has been successfully loaded!\n");
	
	while ((c = getc(source)) != EOF)
	{	
		if(!isspace(c))
			count++;
		if(c == '\n')
			rows++;
	}
	
	Healthcare_Table = (data*) malloc(sizeof(data)* rows);

	fseek(source, 0, SEEK_SET);
	
	//skipping first row
	char buffer[MAX];
	fgets(buffer, MAX, source);
	
	
	for(i = 0; i < rows; i++)
	{
		fscanf(source, "%s %s %c %s %d %d", &Healthcare_Table[i].firstname, &Healthcare_Table[i].lastname, &Healthcare_Table[i].gender, &Healthcare_Table[i].date, &Healthcare_Table[i].waist, &Healthcare_Table[i].hip);
	//	Healthcare_Table[i] = get_row(source);
	}

	Display_Healthcare_Table(Healthcare_Table, rows);
	printf("Enter the name and surname for WHR calculation (Exit - X): ");
	scanf("%s %s", &first, &last);
	if((first == "X")|| (first == "x"))
	{
		printf("Bye!!");
		exit(1);
	}
	
	similarity = Search(Healthcare_Table, rows, first, last);

	
	
	fclose(source); 	
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

void Display_Healthcare_Table(data *Healthcare_Table, int rows){
	
	int i;
	printf("Following records have been loaded:\n");
	printf("\n");
	printf("Firstname\t Lastname\t gender\t Date\t Waist<cm>\t hip<cm>\n");
	for(i = 0; i < rows; i++)
	{
		printf("%10s %10s %15c %10s %10d %10d\n", Healthcare_Table[i].firstname, Healthcare_Table[i].lastname, Healthcare_Table[i].gender, Healthcare_Table[i].date, Healthcare_Table[i].waist, Healthcare_Table[i].hip);
	}

	
}

//=======================================================================================//
//=======================================================================================//

int Search (data *Healthcare_Table, int size, char name[MAX], char last[MAX])
{
	int i = 0, first, lastname, similarity;
	
	for (i = 0; i < size; i++)
	{
		first = (strcmp(Healthcare_Table[i].firstname,name));
		lastname = (strcmp(Healthcare_Table[i].lastname,last));
		if(first == 0 || lastname == 0)
		{
			return 1;
		}
	}
	return -1;
}


/*data get_row(FILE *source){
	data line;
	char buffer[MAX];
	
	//skipping first row
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









