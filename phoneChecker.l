%{
	#include<stdio.h>
	int val;
	int i;
%}

%%
[1-9]{1}[0-9]{9} {val = 1;}
.* {val = 0;}
%%

int main()
{
	yylex();
	if(val == 1)
	printf("VALID");
	else
	printf("NOT VALID");
}

int yywrap()
{
	
	return 1;
}
