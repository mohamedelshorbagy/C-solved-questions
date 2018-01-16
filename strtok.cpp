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
		cout << "Pos At the Beginning : " << pos << endl;
		cout << "Start At the Beginning : " << start << endl;

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
				cout << "Pos Before If : " << pos << endl;
				cout << "Start Before If : " << start << endl;
				if(s[start] != '\0') {
					cout << "Pos Inside If : " << pos << endl;
					cout << "Start Inside If : " << start << endl;
					return (&s[start]);
                }
				else
				{
					
					start = pos;
					cout << "Pos Inside Else : " << pos << endl;
					cout << "Start Inside Else : " << start << endl;
					pos--;
					break;
				}
			}
			j++;
		}
		pos++;		
	}
    /* This Part is Activated when the string at the end ( '\0' ) */
	cout << "Pos After While : " << pos << endl;
	cout << "Start After While : " << start << endl;
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


char s[] = "Implementation of Strtok Function()The Second Delim.;The Third Delim-This is the Fourth Sentence";
char delim[] = ",;"; // Delims ==> [ (' ')  , (,) , (;) ]

char * p = my_strtok(s , delim);



while(p != NULL) {
    cout << p << endl;
	cout << "###############################" << endl;
    p = my_strtok(NULL, "-");
}









    return 0;
}