%{
	#include<stdio.h>
	
	int remainder;
	int n;
	int result = 0;
int flag = 1;
int val;
	
%}

%%
[0-9]+ {
	val = atoi(yytext);
	n = val;
	while (n != 0) {

        remainder = n % 10;
        
       result += remainder * remainder * remainder;
        
       n /= 10;
	 }
if (result == val)
        printf("%d is an Armstrong number.", val);
    else
        printf("%d is not an Armstrong number.", val);
    }


[\n] return 1;
%%

int main()
{
	yylex();
	if(flag == 1)
	 printf("pal");
	
}
int yywrap()
{
	return 1;
}
