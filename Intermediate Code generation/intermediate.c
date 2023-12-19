#include <stdio.h>
#include <string.h>
char op[10],arg1[10],arg2[10],res[10];

int main()
{
    FILE *f1,*f2;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");

    while(!feof(f1))
    {
        fscanf(f1,"%s%s%s%s",op,arg1,arg2,res);

        if(strcmp(op,"+")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nADD R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }

        if(strcmp(op,"-")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nSUB R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }

        if(strcmp(op,"*")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nMUL R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }

        if(strcmp(op,"/")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nDIV R0,%s",arg2);
            fprintf(f2,"\nMOV %s,R0",res);
        }

        if(strcmp(op,"=")==0)
        {
            fprintf(f2,"\nMOV R0,%s",arg1);
            fprintf(f2,"\nMOV %s,R0",res);
        }
    }
}