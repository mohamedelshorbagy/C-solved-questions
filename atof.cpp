#include <iostream>
#include <cmath>
#include "stdio.h"
#include <cmath>
#include <stdlib.h>
using namespace std;

bool isDigit(char x) {
    
    return (x >= '0' && x <= '9'); // 48 , 57
}

double my_atof(char * c) {
    
    int sign = 1;
    double result = 0;
    double floatPointResult = 0;
    int floatIncrement = 0;
    
    for(int i = 0; c[i] != '\0' ; i++) {
        
        
        if(c[i] == '-') {
            sign = -1;
        }
        if(c[i] == '.') {
            for(int j = i + 1;c[j] != '\0' ; j++) {
                if(isDigit(c[j])) {
                    floatPointResult = (floatPointResult * 10) + (c[j] - '0');
                    floatIncrement++;
                }
            }
            
            result = result + ((pow(10,-floatIncrement) * floatPointResult));
            break;
        }
        if(isDigit(c[i])) {
            
            result = (result * 10) + (c[i] - '0');
            
        }
        
    }
    
    
    return result * sign;
}


int main()
{
    
    cout << my_atof("1.255") << endl;
    cout << my_atof("1.255") + 2 << endl;
    cout << my_atof("1.255") + 0.478 << endl;

    cout << my_atof("12.27") << endl;
    cout << my_atof("12.27") + 2.5 << endl;
    cout << my_atof("12.27") + 0.2 << endl;

    cout << my_atof("5060") << endl;
    cout << my_atof("50aaaa60") << endl;
    cout << my_atof("1.a2aaa2aa5a") << endl;
    


    return 0;
}



