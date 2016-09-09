
#ifndef StringSearch_h
#define StringSearch_h
/***************************************************
 BinarySearch function below search the given string 
 in the provided text file, otherwise it returns 
 the position where the string should be inserted.
 **************************************************/
int BinarySearch(char *filename, char *str)
{
    FILE *infile;
    int first = 0,middle,last =0;
    char temp[512], str1[512];
    int line, position,compare;
    strcpy(str1,str);                               /* strcpy is used to convert the char* str to char []*/
    
    if(!(infile = fopen(filename, "r")))            /*if ststemnt checks if the file can be opened without error*/
    {
        printf(" Error in file opening\n");
        exit(1);
    }

    while ((line = fgetc(infile)) != EOF) {         /* while loop check the last offset in the text file*/
        if (line == '\n')
            ++last;
    }
    
   while(first <= last)                            /* While loop iterates last offset get smaller then first*/
   {
      position = -1;
      fseek(infile, 0, SEEK_SET);                  /* fseek function points to the starting of text file*/
      middle = (first + last)/2;
      while(position < middle)                     /* While loop iterate in the file to find the middle oofset*/
      {
           fscanf(infile,"%s",temp);
           position++;
      }
      compare = strncasecmp(temp,str1, strlen(str1)); /* Check if the given string is same as middle element*/
      if(compare == 0)
      {
          printf(" Key %s occured at %d \n", str1,middle);
          return(0);
      }
      else if(compare >0)
      {
          last = middle -1;
      }
      else
      {
          first = middle +1;
      }
   }
    compare = strncasecmp(temp,str1,strlen(str1));  /* This would find where the new string should be inserted*/
    if(compare>0)
    {
        printf(" Match does not found and key should be inserted at position %d \n", middle);
    }
    else
    {
        printf(" Match does not found and key should be inserted at position %d \n", middle+1);
    }
    
    return(0);                                     /* End of the function*/
}
#endif
