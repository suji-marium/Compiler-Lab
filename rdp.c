#include <stdio.h>

int E();
int EP();
int T();
int TP();
int F();

char input[10];
int i;

int main()
{
    printf("Enter the string to be checked: ");
    scanf("%s",input);
    if(E())
    {
        if(input[i+1]=='\0')
            printf("String accepted");
        else 
            printf("String not accepted");
    }
    else
        printf("String not accepted");
}

int E()
{
    if(T())
    {
        if (EP())
            return 1;

        else 
            return 0;
    }
}

int EP()
{
    if(input[i]=='+')
    {
        i++;
        if(T())
        {
            if(EP())
                return 1;
            else 
                return 0;
        }
        else 
            return 0;
    }
    else
        return 1;
}

int T()
{
    if(F())
    {
        if (TP())
            return 1;

        else 
            return 0;
    }
}

int TP()
{
    if(input[i]=='*')
    {
        i++;
        if(F())
        {
            if(TP())
                return 1;
            else 
                return 0;
        }
        else 
            return 0;
    }
    else
        return 1;
}

int F()
{
    if(input[i]=='(')
    {
        i++;
        if(E())
        {
            if(input[i]==')')
            {
                i++;
                return 1;
            }
            else 
                return 0;
        }
        else 
            return 0;
    }

    else if(input[i]=='a')
    {
        i++;
        return 1;
    }
    else 
        return 0;
}