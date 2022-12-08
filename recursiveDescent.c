#include<stdio.h>
#include<string.h>
int E();
int EP();
int TP();
int T();
int F();

char input[100];
int i,l;
void main()
{
printf("\nRecursive descent parsing for the following grammar\n");
printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
printf("\nEnter the string to be checked:");
fgets(input,sizeof(input),stdin);
if(E())
{
	if(input[i+1]=='\0')
	printf("\nString is accepted");
	else{
	printf("\nString is not accepted");
	}
}
else{
	printf("\nString not accepted");
}
}
int E()
{
	if(T())
	{
		if(EP())
		return(1);
		else
		return(0);
	}
	else
	return(0);
}
int EP()
{
	if(input[i]=='+')
	{
		i++;
		if(T())
		{
			if(EP())
			return(1);
			else
			return(0);
		}
		else
		return(0);
	}
	else
	return(1);
}
int T()
{
	if(F())
	{
		if(TP())
		return(1);
		else
		return(0);
	}
	else
	return(0);
}
int TP()
{
	if(input[i]=='*')
	{
		i++;
		if(F())
		{
			if(TP())
			return(1);
			else
			return(0);
		}
		else
		return(0);
	}
	else
	return(1);
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
				return(1);
			}
		else{
			return(0);
			}
		}
	
	}
	else if(input[i]>='a'&&input[i]<='z'||input[i]>='A'&&input[i]<='Z')
	{
		i++;
		return(1);
	}
	else
		return(0);
}

/*
Recursive descent parsing for the following grammar

E->TE'
E'->+TE'/@
T->FT'
T'->*FT'/@
F->(E)/ID

Enter the string to be checked:(a+b)*c
String is accepted
	
*/
