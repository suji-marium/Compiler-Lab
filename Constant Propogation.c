#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void input();
void output();
void constant();
void change(int p,char *res);

int n;

struct exp 
{
    char op[10],op1[10],op2[10],res[10];
    int flag;
}arr[10];

int main()
{
    input();
    constant();
    output();
}

void input()
{
    printf("\nEnter the number of expressions: ");
    scanf("%d",&n);
    printf("\nEnter the inputs: \n");

    for(int i=0;i<n;i++)
    {
        scanf("%s",arr[i].op);
        scanf("%s",arr[i].op1);
        scanf("%s",arr[i].op2);
        scanf("%s",arr[i].res);
        arr[i].flag=0;
    }
}

void constant()
{
    int op1,op2,res;
    char res1[10],op;

    for(int i=0;i<n;i++)
    {
        if(isdigit(arr[i].op1[0]) && isdigit(arr[i].op2[0]) || strcmp(arr[i].op,"=")==0)
        {
            op1=atoi(arr[i].op1);
            op2=atoi(arr[i].op2);
            op=arr[i].op[0];

            switch(op)
            {
                case '+':
                    res=op1+op2;
                    break;
                case '-':
                    res=op1-op2;
                    break;
                case '*':
                    res=op1*op2;
                    break;
                case '/':
                    res=op1/op2;
                    break;
                case '=':
                    res=op1;
                    break;
            }
            sprintf(res1,"%d",res);
            arr[i].flag=1;
            change(i,res1);
        }
    }
}


void change(int p,char *res)
{
    for(int i=p+1;i<n;i++)
    {
        if(strcmp(arr[p].res,arr[i].op1)==0)
            strcpy(arr[i].op1,res);
        if(strcmp(arr[p].res,arr[i].op2)==0)
            strcpy(arr[i].op2,res);
        
    }
}

void output()
{
    printf("\nOptimized Code: ");
    for(int i=0;i<n;i++)
    {
        if(!arr[i].flag)
        {
            printf("\n%s %s %s %s",arr[i].op,arr[i].op1,arr[i].op2,arr[i].res);
        }
    }
}
