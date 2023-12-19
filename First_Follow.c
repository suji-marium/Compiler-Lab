#include <stdio.h>
#include <string.h>
#include <ctype.h>
void FIRST(char c);
void FOLLOW(char  c);
void FOLLOW2(char c);
void result(char c);

int nop,m=0;
char prod[10][10],res[10];
char c;
int main()
{
    int ch;
    printf("Enter the number of expressions: ");
    scanf("%d",&nop);
    printf("Enter the productions: \n");
    for (int i=0;i<nop;i++)
    {
        printf("\nEnter production %d: ",i+1);
        scanf("%s",prod[i]);
    }

    do {

        m=0;
        memset(res,'\0',sizeof(res));

        printf("Enter the symbol whose first and follow to be found: ");
        scanf(" %c",&c);

        if(isupper(c))
            FIRST(c);
        else 
        {
            printf("Not possible");
            return 0;
        }

        printf("First(%c)={",c);
        for(int i=0;i<m;i++)
        {
            printf("%c ",res[i]);
        }
        puts("}");

        m=0;
        memset(res,'\0',sizeof(res));
        if(isupper(c))
            FOLLOW(c);
        else 
        {
            printf("Not possible");
            return 0;
        }

        printf("Follow(%c)={",c);
        for(int i=0;i<m;i++)
        {
            printf("%c ",res[i]);
        }
        puts("}");

        printf("\nDo you want to continue: ");
        scanf("%d",&ch);

    }while(ch==1);
}

void FIRST(char c)
{
    if(!(isupper(c)))
        result(c);
    for(int k=0;k<nop;k++)
    {
        if(prod[k][0]==c)
        {
            if(prod[k][2]==c)
                return;
            else if(islower(prod[k][2]))
                result(prod[k][2]);
            else
                FIRST(prod[k][2]);
        }
    }
}

void FOLLOW2(char c)
{
    if(!(isupper(c)))
        result(c);
    for(int k=0;k<nop;k++)
    {
        if(prod[k][0]==c)
        {
            if(prod[k][2]=='#')
                FOLLOW(prod[k][0]);
            else if(prod[k][2]==c)
                return;
            else if(islower(prod[k][2]))
                result(prod[k][2]);
            else
                FIRST(prod[k][2]);
        }
    }
}

void FOLLOW(char c)
{
    if(prod[0][0]==c)
        result('$');
    for(int i=0;i<nop;i++)
    {
        for(int j=2;j<=strlen(prod[i]);j++)
        {
            if(prod[i][j]==c)
            {
                if(prod[i][j+1]!='\0')
                    FOLLOW2(prod[i][j+1]);
                if(prod[i][j+1]=='\0' && prod[i][0]!=c)
                    FOLLOW(prod[i][0]);
            }
        }
    }
}


void result(char c)
{
    for(int i=0;i<m;i++)
        if(res[i]==c)
            return;
    res[m++]=c;
}

