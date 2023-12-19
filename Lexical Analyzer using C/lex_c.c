#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int lno=1,tno=0;
    char keywd[50][50]={"printf","scanf","int","main","return","if","else"};
    char str[10],ch;
    FILE *f1,*f2;
    f1=fopen("filein.txt","r");
    f2=fopen("fileout.txt","w");

    while((ch=fgetc(f1))!=EOF)
    {
        if(ch=='/')
        {
            ch=fgetc(f1);
            if(ch=='/')
            {
                while((ch=fgetc(f1))!='\n')
                    if(ch==EOF)
                        break;
                lno++;
            }

            else if(ch=='*')
            {
                while((ch=fgetc(f1))!='*')
                    if(ch==EOF)
                        break;
                ch=fgetc(f1);
                if(ch=='/')
                    continue;
            }
        }

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=')
        {
            fprintf(f2,"\n%d\t\t%d\t\tOperator\t\t%c",lno,tno,ch);
            tno++;
        }

        else if(ch=='{' || ch=='}' || ch=='<' || ch=='>' || ch=='[' || ch==']' || ch=='(' || ch==')' ||ch==';' || ch==':')
        {
            fprintf(f2,"\n%d\t\t%d\t\tSpecial Symbol\t\t%c",lno,tno,ch);
            tno++;
        }

        else if(isdigit(ch))
        {
            fprintf(f2,"\n%d\t\t%d\t\tDigit\t\t%c",lno,tno,ch);
            tno++;
        }

        else if(isalpha(ch))
        {
            int i=0;
            str[i++]=ch;

            ch=fgetc(f1);
            while(isalnum(ch) && ch!=' ')
            {
                str[i++]=ch;
                ch=fgetc(f1);
            }

            str[i]='\0';
            int flag=0;

            for(int j=0;j<50;j++)
            {
                if(strcmp(str,keywd[j])==0)
                {
                    flag=1;
                    break;
                }
            }

            if(flag==1)
            {
                fprintf(f2,"\n%d\t\t%d\t\tKeyword\t\t%s",lno,tno,str);
                tno++;
            }
            else
            {
                fprintf(f2,"\n%d\t\t%d\t\tIdentifier\t\t%s",lno,tno,str);
                tno++;
            }

            if(ch=='{' || ch=='}' || ch=='<' || ch=='>' || ch=='[' || ch==']' || ch=='(' || ch==')' ||ch==';' || ch==':')
            {
                fprintf(f2,"\n%d\t\t%d\t\tSpecial Symbol\t\t%c",lno,tno,ch);
                tno++;
            }
        }

        else if(ch=='\n')
            lno++;
    }

}
