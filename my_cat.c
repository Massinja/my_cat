#include <errno.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv) 
{
    FILE *fp;
    int i = 1;

    while(i<argc)
    {
           
        fp = fopen(argv[i], "r");
        
        if( fp == NULL)
        {
            fprintf(stderr, "fopen: Could not open '%s': %s", argv[i], strerror(errno));
            fputs("\nCross fingers and continue\n", stderr);
            break;
        }

        char c;

        while((c = fgetc(fp)) != EOF)
        {
            printf("%c", c);
        }

        fclose(fp);
        

        i++;
        if(i>argc)
        {
            printf("\n");
        }

    }

    if(i==1)
    {
        fprintf(stderr, "no arguments found, enter file names!\n");
    }
 
    return 0;
} 
