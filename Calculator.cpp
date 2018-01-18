#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

//Declaration of variables
//Declara��o das vari�veis
	
	char a, *expres = NULL, m[1], *p0 = NULL, *p1 = NULL;
	int i = 0, j = 1, k0, k1 = 0, count0 = 0, count1 = 0, *n0 = NULL, *n1 = NULL;

//Determining the expression that represents the function. The expression will be recorded in the variable "expres"
//Determinando a express�o que representa a fun��o. A express�o ficar� gravada na vari�vel "expres"
	
	expres = (char *) malloc(10 * sizeof(char) + 1);
	
	printf("Digite uma expressao para f(x):\n");
	printf("y = ");
	
	while ((a = getchar()) != '\n' && a != EOF && a != '\0')
	{
		if (j == 10)
		{
			expres = (char *) realloc(expres, strlen(expres) + 10 * sizeof(char) + 1);
			j = 1;
		}
		*(expres + i * sizeof(char)) = a;
		i++;
		j++;
	}
	
	*(expres + i * sizeof(char)) = '\0';
	
		
/*
The characters of the string "expres" will compose three other vectors ("m", "n0" and "p").
The vector "m" is responsible for capturing the characters of "expres" directly in the form of char.
The "n0" vector will store the conversion of the "m" character into an integer.
If "m" is not a numeral, but any other character, it will be assigned to "n0" the value -99999.
The vector "p" will be responsible for separating the characters corresponding to a numeral of the others.
If "p" is a numeral, it will be identified by the letter "z". Otherwise, it will be identified by the numeral itself.
The variable "count0" counts how many number terms in the expression, disregarding the number of digits in each number.
The variable "count1" counts the total numbers (regardless of the number of digits) and non-numeric characters.
*/

/*
Os caracteres da string "expres" passar�o a compor tr�s outros vetores ("m", "n0" e "p").
O vetor "m" � respons�vel por capturar os caracteres de "expres" diretamente na forma de char.
O vetor "n0" ir� armazenar a convers�o do caractere de "m" em um integer. 
Se "m" n�o for um numeral, mas um outro caractere qualquer, ser� atribu�do a "n0" o valor -99999. 
O vetor "p" ser� respons�vel por separar os caracteres correspondentes a numeral dos demais.
Se "p" for um numeral, ele ser� identificado com a letra "z". Caso contr�rio, ser� identificado com o pr�prio numeral.
A vari�vel "count0" conta quantos n�meros termos na express�o, desconsiderando a quantidade de algarismos de cada n�mero.
A vari�vel "count1" conta o total de n�meros (independentemente da quantidade de algarismos) e de caracteres n�o num�ricos.
*/	
	
	n0 = (int *) malloc(strlen(expres)+1 * sizeof(int));
	p0 = (char *) malloc(strlen(expres)+1 * sizeof(int));
	
	
	for (k0 = 0; k0 < strlen(expres); k0++)
	{
		if (expres[k0] == '0' || expres[k0] == '1' || expres[k0] == '2' || expres[k0] == '3' || expres[k0] == '4' || expres[k0] == '5'
		                                           || expres[k0] == '6' || expres[k0] == '7' || expres[k0] == '8' || expres[k0] == '9') 
		{
			
        	m[0] = expres[k0];
        	n0[k0] = atoi(m);
        	p0[k0] = 'z';
        	
        	if (k0 == 0)
        	{
        		count0++;
        		count1++;
        	}
        	else
        	{
        		if (n0[k0-1] == -99999)
        		{
        			count0++;
        			count1++;
        		}
			}
        		
        	
        } else {
        	n0[k0] = -99999;
        	p0[k0] = expres[k0];
        	count1++;
         	
        }
    }
	n0[strlen(expres)] = -99999;
	p0[strlen(expres)] = '\0';

/*
In this part, the values of the vector "n1" were stored, based only on the values of the "n0" vector that represent numerals.
Each value set to "n1" represents not just a single digit, but the fully number entered in the expression by the user.
For example, in the expression "23*x+5", the vector "n1" should store the values 23 and 5, in that order.
*/

/*
Nessa parte, foram armazenados os valores do vetor "n1", tomando como base apenas os valores do vetor "n0" que representam numerais.  
Cada valor armanezado em n1 representa n�o mais um simples algarismo, mas sim o n�mero por completo informado na express�o pelo usu�rio.
Por exemplo, na express�o "23*x+5", o vetor n1 dever� armazenar os valores 23 e 5, nessa ordem.
*/

    if (count0 > 0)
  		n1 = (int *) malloc(count0 * sizeof(int));
  	else
  	{
  		n1 = (int *) malloc(1 * sizeof(int));
		n1[0] = -99999;	
	}
	
	
	for (k0 = 0; k0 < strlen(expres); k0++)
  	{
  		if (n0[k0] != -99999)
		{
			n1[k1] = n0[k0];
			k0++;				
			if (k0 < strlen(expres))
			{
				while (n0[k0] != -99999)
				{
					n1[k1] = n1[k1]*10 + n0[k0];
					k0++;
				}
				k1++;
			}	
		}	
	}


/*
From the "p0" vector, the values of "p1" were stored,
but without the unnecessary repetition of the character "z", which occurred in "p0" in cases of numbers with more than one figure.
*/

/*
A partir do vetor "p0", foi feito o armazenamento dos valores de "p1",
mas sem a repeti��o desnecess�riado do caractere "z", que ocorria em "p0" nos casos de n�meros com mais de um algarismo.	
*/	


  	p1 = (char *) malloc(count1 * sizeof(int));
	k0 = 0;
	k1 = 0;
	  
	do
  	{
		p1[k1] = p0[k0];
		k0++;
		if (k0 < strlen(expres))
		{
			if (p1[k1] == 'z')
			{				
				while (p0[k0] == 'z')
				{
					k0++;
				}
			}
			k1++;
		}
	} while (k0 < strlen(expres));


}
