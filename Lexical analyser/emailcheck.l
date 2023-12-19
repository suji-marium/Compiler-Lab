%{
	int flag=0;
%}

%%
[a-z.0-9]+@[a-z]+".com"|".in" {flag=1;}
%%

int main(int argc, char **argv)
{
	FILE *f1;
	f1=fopen("input.txt","r");

	if(!f1)
	{
		printf("Could not open the file");
		return 0;
	}

	yyin=f1;
	yylex();

	if(flag==1)
		printf("Valid Email");
	else 
		printf("Invalid Email");

}

int yywrap()
{
	return 1;
}
