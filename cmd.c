//Command line interpreter program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Breaks up input line
void breakUp(char *, char *, char *, char *, int *);

int main()
{
    char line[80], comm[10], p1[10], p2[10];
    int len, n;

	do
	{	
    		printf("Please enter a command: ");

        	/* read in a line */
    		fgets(line, 80, stdin);

        	/* get rid of trailing newline character */
    		len = strlen(line) - 1;
    		if (line[len] == '\n')
        	line[len] = '\0';

		//Changes characters in line to lowercase
		for (int i=0; line[i]; i++)
			line[i] = tolower(line[i]);

        	/* Break up the line */
    		breakUp(line, comm, p1, p2, &n);

    		printf ("%d things on this line\n", n);
   	 	printf ("command: %s\n", comm);
    		printf ("parameter 1: %s\n", p1);
    		printf ("parameter 2: %s\n", p2);
		line[0] = '\0';
		memset(line,0,strlen(line));
	}while(1);

    return 0;
}

/*
   This function takes a line and breaks it into words.
   The orginal line is in the char array str, the first word
   will go into the char array c, the second into p1, and the
   the third into p2.  If there are no words, the corresponding
   char arrays are empty.  At the end, n contains the number of
   words read.
*/
void breakUp(char *str, char *c, char *p1, char *p2, int *n)
{
    c[0] = p1[0] = p2[0] = '\0';

    /* YOU CANNOT USE THE FOLLOWING!  IT IS A BUILT-IN FUNCTION! */
    //*n = sscanf(str,"%s %s %s %*s", c, p1, p2);
	*n = 0;	

	int len_str = strlen(str);
	for( int i = 0; i < len_str; i++)
	{
		if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		{
			while( str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			{
				if ( *n == 0 )
				{
					int len2 = strlen(c);
					c[len2] = str[i];
					c[len2+1] = '\0';
					len2 += 1;
				}
				if ( *n == 1 )
				{
					int len3 = strlen(p1);
					p1[len3] = str[i];
					p1[len3+1] = '\0';
				}
				if ( *n == 2 )
				{
					int len4 = strlen(p2);
					p2[len4] = str[i];
					p2[len4+1] = '\0';
				}
			i += 1;
			}
		*n += 1;
		}
	}
	str[0] = '\0';
}
