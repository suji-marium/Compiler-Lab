%{
	int vow;
	int cons;
%}

%%
[aeiouAEIOU] {vow++; }
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ] {cons++; }
%%

int main(int argc, char **argv)
{
	FILE *file;
	file=fopen("input.txt","r");

	if(!file)
	{
		printf("Could not open the file");
		return 0;
	}

	yyin=file;
	yylex();
	
	printf("\nNo of vowels=%d and no of consonants=%d",vow,cons);
}

int yywrap()
{
	return 1;
}
