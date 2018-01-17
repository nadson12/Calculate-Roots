#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

//Declaration of variables
//Declaração das variáveis
	
	char a, *expres = NULL, m[1], *p = NULL;
	int i = 0, j = 1, k0, *n = NULL;

//Determining the expression that represents the function. The expression will be recorded in the variable "expres"
//Determinando a expressão que representa a função. A expressão ficará gravada na variável "expres"
	
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
The characters of the string "expres" will compose three other vectors ("m", "n" and "p").
The vector "m" is responsible for capturing the characters of "expres" directly in the form of char.
The "n" vector will store the conversion of the "m" character into an integer.
If "m" is not a numeral, but any other character, it will be assigned to "n" the value -99999.
The vector "p" will be responsible for separating the characters corresponding to a numeral of the others.
If "p" is a numeral, it will be identified by the letter "z". Otherwise, it will be identified by the numeral itself.
*/

/*
Os caracteres da string "expres" passarão a compor três outros vetores ("m", "n" e "p").
O vetor "m" é responsável por capturar os caracteres de "expres" diretamente na forma de char.
O vetor "n" irá armazenar a conversão do caractere de "m" em um integer. 
Se "m" não for um numeral, mas um outro caractere qualquer, será atribuído a "n" o valor -99999. 
O vetor "p" será responsável por separar os caracteres correspondentes a numeral dos demais.
Se "p" for um numeral, ele será identificado com a letra "z". Caso contrário, será identificado com o próprio numeral.
*/	
	
	n = (int *) malloc(strlen(expres) * sizeof(int));
	p = (char *) malloc(strlen(expres) * sizeof(int));
	
	
	for (k0 = 0; k0 < strlen(expres); k0++)
	{
		if (expres[k0] == '0' || expres[k0] == '1' || expres[k0] == '2' || expres[k0] == '3' || expres[k0] == '4' || expres[k0] == '5'
		                                           || expres[k0] == '6' || expres[k0] == '7' || expres[k0] == '8' || expres[k0] == '9') 
		{
			
        	m[0] = expres[k0];
        	n[k0] = atoi(m);
        	p[k0] = 'z';
        	
        } else {
        	n[k0] = -99999;
        	p[k0] = expres[k0];
         	
        }
    }
	
	free(expres);
	free(n);
	free(p);
	
	expres = NULL;
	n = NULL;
	p = NULL;
}
