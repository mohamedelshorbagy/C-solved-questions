#include <iostream>
#include <cmath>
#include <bitset>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
using namespace std;


char * my_strtok(char * str, char *comp)
{
	static int pos;
	static char * s;	
	int i = 0, start = pos;

	if(str!=NULL)
		s = str;


	int j = 0;
	while(s[pos] != '\0')
	{
		j = 0;	
		while(comp[j] != '\0')
		{		
			if(s[pos] == comp[j])
			{
				s[pos] = '\0';
				pos = pos+1;				
				if(s[start] != '\0') {
					return (&s[start]);
                }
				else
				{
					
					start = pos;
					pos--;
					break;
				}
			}
			j++;
		}
		pos++;		
	}
    /* This Part is Activated when the string at the end ( '\0' ) */
	s[pos] = '\0';
	if(s[start] == '\0') {
		return NULL;
    }
	else {
		return &s[start];
    }
}


int main() {



 /* For Explination */
 static int x; // X is Initialized with ( Zero )


char s[] = "Implementation of Strtok Function,The Second Delim.;The Third Delim";
char delim[] = ",;"; // Delims ==> [  (,) , (;) ]

char * p = my_strtok(s , delim);



while(p != NULL) {
    cout << p << endl;
    p = my_strtok(NULL, delim);
}









    return 0;
}