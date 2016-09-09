#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StringSearch.h"
/**********************************************
 Main program accept txt file and a string to 
 be searched and call the BinarySearch function
***********************************************/

int main(int argc, char *argv[])
{
    int check_end;
    if(argc < 3|| argc >3)
    {
        printf(" Please enter valid number of argument\n");
    }
    check_end = BinarySearch(argv[1], argv[2]);
    
return(0);
}