#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void calculate(int&, int&, double& ,double&, double, double&, double&, char[], double[]);
double operation(int&, int&, double&, double, char[], double[]);
double derivative(int, int, double, double, double&, char[], double[]);
double parentheses(int, int, double, char[],  double[]);
double parentheses_deriv(int&, int&, double, char[],  double[]);
void standard_procedure(int&, int&, double& v1, double& v2, double, double&, double&, char[], double[]);


int main(void)
{

//Declaration of variables
//Declaração das variáveis
	
	char a, *expres = NULL, m[1], *p0 = NULL, *p1 = NULL;
	int i = 0, j = 1, k0, k1 = 0, count0 = 1, count1 = 1, *n0 = NULL, kp, kn, stop = 0, language;
	double v1, v2, x, dv1, dv2, y, dy, mult10, *n1 = NULL;


//Choosing the language of the program
//Escolhendo a língua do programa

	printf("\n\n\n	Please, Choose your language.\n\n	Por favor, escolha qual a sua lingua.\n\n\n\n	(1) English/Ingles\n\n	(2) Portuguese/Portugues\n\n");
	do
	{
		printf("\n\n\n	Language/Lingua: ");
		scanf("%d", &language);
		fflush(stdin);
		if (language != 1 && language != 2)
			printf("\n\n	Invalid choice!\n\n	Escolha invalida!");
	} while (language != 1 && language != 2);


//Determining the expression that represents the function. The expression will be recorded in the variable "expres"
//Determinando a expressão que representa a função. A expressão ficará gravada na variável "expres"
		
	system("cls");
	expres = (char *) malloc(10 * sizeof(char) + 1);
	
	
  	switch (language)
	{
		case 1:
			printf("\n\n\n	Enter an expression for f(x):\n");
		break;
		case 2:
			printf("\n\n\n	Digite uma expressao para f(x):\n");
		break;
	}
	
	printf("\n	y = ");
	
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
The character "." does not increment the value of "count1",
because all digits that form a decimal number will later be converted into a single number.
In this situation, the value assumed by "n0" will be -88888, in order to enable its later identification.
On the other hand, in cases where the user types an expression in which the "*" character is suppressed,
it will increment the value of "count1". This is because even though this character is not explicit in the "p0" vector,
it will necessarily appear in the "p1" vector.
*/

/*
Os caracteres da string "expres" passarão a compor três outros vetores ("m", "n0" e "p").
O vetor "m" é responsável por capturar os caracteres de "expres" diretamente na forma de char.
O vetor "n0" irá armazenar a conversão do caractere de "m" em um integer. 
Se "m" não for um numeral, mas um outro caractere qualquer, será atribuído a "n0" o valor -99999. 
O vetor "p" será responsável por separar os caracteres correspondentes a numeral dos demais.
Se "p" for um numeral, ele será identificado com a letra "z". Caso contrário, será identificado com o próprio numeral.
A variável "count0" conta quantos números termos na expressão, desconsiderando a quantidade de algarismos de cada número.
A variável "count1" conta o total de números (independentemente da quantidade de algarismos) e de caracteres não numéricos.
O caractere "." não incrementa o valor de "count1",
pois todos os dígitos que formam um número decimal serão posteriormente convertidos em um único número.
Nessa situação, o valor assumido por "n0" será -88888, de modo a possibilitar a sua posterior identificação.
Por outro lado, nos casos em que o usuário digitar uma expressão em que o caractere "*" é suprimido,
ele irá incrementar o valor de "count1". Isso porque, mesmo que esse caractere não esteja explícito no vetor "p0",
ele irá necessariamente aparecer no vetor "p1".
*/	
	
	n0 = (int *) malloc((strlen(expres)+1) * sizeof(int));
	p0 = (char *) malloc((strlen(expres)+1) * sizeof(char));
	
	
	for (k0 = 0; k0 < strlen(expres); k0++)
	{
		if (expres[k0] == '0' || expres[k0] == '1' || expres[k0] == '2' || expres[k0] == '3' || expres[k0] == '4' || expres[k0] == '5'
		                                           || expres[k0] == '6' || expres[k0] == '7' || expres[k0] == '8' || expres[k0] == '9') 
		{
			
        	m[0] = expres[k0];
        	n0[k0] = atoi(m);
        	p0[k0] = 'z';
        	 
			
			if (k0+1 < strlen(expres))
			{
				
				if (expres[k0+1] == 'x' || expres[k0+1] == '(')
				{
					count1++;
				}
			}
        } else
		{
        	if (expres[k0] == '.')
			{
        		n0[k0] = -88888;
				p0[k0] = 'z';
			} else
			{
        		n0[k0] = -99999;
        		p0[k0] = expres[k0];
        		count1++;

        		if (k0+1 < strlen(expres))
				{
					if (p0[k0] == 'x' || p0[k0] == ')')
					{			
						if (expres[k0+1] == '(')
						{
							count1++;
						}
						
					}
        			if (expres[k0+1] == '0' || expres[k0+1] == '1' || expres[k0+1] == '2' || expres[k0+1] == '3' || expres[k0+1] == '4' || expres[k0+1] == '5'
		                                           || expres[k0+1] == '6' || expres[k0+1] == '7' || expres[k0+1] == '8' || expres[k0+1] == '9') 
					{
        				count0++;
        				count1++;
					}
				}
		
			}
	
        }
    }
	n0[strlen(expres)] = -99999;
	p0[strlen(expres)] = '\0';
	

/*
In this part, the values of the vector "n1" is stored, based only on the values of the "n0" vector that represent numerals.
Each value set to "n1" represents not just a single digit, but the fully number entered in the expression by the user.
For example, in the expression "23*x+5", the vector "n1" should store the values 23 and 5, in that order.
The values of "n1" also include the decimal numbers. Therefore, for the expression "2.5x + 3", we have for "n1" the values 2.5 and 3.
*/

/*
Nessa parte, são armazenados os valores do vetor "n1", tomando como base apenas os valores do vetor "n0" que representam numerais.  
Cada valor armanezado em "n1" representa não mais um simples algarismo, mas sim o número por completo informado na expressão pelo usuário.
Por exemplo, na expressão "23*x+5", o vetor "n1" deverá armazenar os valores 23 e 5, nessa ordem.
Os valores de "n1" incluem também os números decimais. Logo, para a expresão  "2.5x+3", teremos para "n1" os valores 2.5 e 3.  
*/

    if (count0 > 0)
  		n1 = (double *) malloc(count0 * sizeof(double));
  	else
  	{
  		n1 = (double *) malloc(1 * sizeof(double));
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
					if (n0[k0] != -88888)
					{
						n1[k1] = n1[k1]*10 + n0[k0];
						k0++;
					} else 
					{
						k0++;
						mult10 = 10;
						while (n0[k0] != -99999)
						{
							n1[k1] = n1[k1] + (double)n0[k0] / mult10;
							mult10 = 10*mult10;
							k0++;
						}
					}
						
				}
				k1++;
			}	
		}	
	}


/*
From the "p0" vector, the values of "p1" were stored,
but without the unnecessary repetition of the character "z", which occurred in "p0" in cases of numbers with more than one digit.
In cases where the character "*" is suppressed in "p0", the vector "p1" explicitly includes it.
For example, if we have the expression "zx(x-z)(z/x)+z(x^z)" stored in "p0", we will have the expression "z*x*(x-z)*(z/x)+z*(x^z)" stored in "p1".
*/

/*
A partir do vetor "p0", foi feito o armazenamento dos valores de "p1",
mas sem a repetição desnecessáriado do caractere "z", que ocorria em "p0" nos casos de números com mais de um algarismo.
Nos casos em que o caractere "*" se encontra suprimido em "p0", o vetor "p1" passa a incluí-lo de forma explícita.	
Por exemplo, se em "p0" temos armazenada a expressão "zx(x-z)(z/x)+z(x^z)", em p1 teremos a expressão "z*x*(x-z)*(z/x)+z*(x^z)".
*/	


  	p1 = (char *) malloc(count1+1 * sizeof(int));
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
				if (k0 < strlen(expres))
				{
					if (p0[k0] == 'x' || p0[k0] == '(')
					{
						k1++;
						p1[k1] = '*';
					}
				}
			} else if (p0[k0-1] == 'x' || p0[k0-1] == ')')				
			{
				if (p0[k0] == '(')
				{
					k1++;
					p1[k1] = '*';
				}
				
			}			
			k1++;
		}
	} while (k0 < strlen(expres));
	p1[count1] = '\0';



/*
From here begins the implementation part of Newton's method, itself.
The following new variables are introduced: "kp", "kn", "v1", "v2", "dv1", "dv2" and "stop".
"kp" and "kn" have a function similar to the variable "k0". They function as indices of the vectors "p" and "n", respectively.
The variables "v1" and "v2" represent provisional values of parts of the function. They are used to calculate the value of y.
The variables "dv1" and "dv2", in turn, represent temporary derivatives of parts of the function. They serve to calculate the value of the derivative of y for the given x.
The "stop" variable represents how many repetitions were made in the approximation procedure from x to the root of the function.
A limit of 50 replicates was placed. If this limit is reached, we inform the user that the program could not find a root for the function.
*/

/*
A partir daqui começa a parte de implementação do método de Newton, propriamente dito.
São introduzidas as seguintes novas variáveis: "kp", "kn", "v1", "v2", "dv1", "dv2" e "stop".
"kp" e "kn" possuem uma função semelhante à variável "k0". Funcionam como índices dos vetores "p" e "n", respectivamente.
As variáveis "v1" e "v2" representam valores provisórios de partes da função. Elas são utilizadas para se calcular o valor de y.
As variáveis "dv1" e "dv2", por sua vez, representam derivadas provisórias de partes da função. Servem para calcular o valor da derivada de y para o x dado.
A variável "stop" representa quantas repetições foram feitas no procedimento de aproximação de x até a raiz da função.
Foi colocado um limite de 50 repetições. Caso esse limite seja atingido, informamos ao usuário que o programa não conseguiu achar uma raiz para a função.
*/


	switch (language)
	{
		case 1:
			printf("\n\n	Enter the value of x in which you want to derive the function: ");
		break;
		case 2:
			printf("\n\n	Digite o valor de x no qual deseja derivar a funcao: ");
		break;
	}
	
	
  	printf("x = ");
  	scanf("%f", &x);
  
  	 
  	do{
    	kp = 0;
    	kn = 0;
    	v1 = 0;
    	v2 = 0;
    	dv1 = 0;
    	dv2 = 0;
     
    	while (kp < count1){
        	calculate(kp, kn, v1, v2, x, dv1, dv2, p1, n1);
        	kp++;
     	}
	 	y = v1;
     	dy = dv1;
     	x -= y/dy;
     	if (stop == 50)
        	break;
     	stop++;
  	} while (y > 0.000001 || y < -0.000001);
  	if (stop == 50)
  	{
  		switch (language)
		{
			case 1:
				printf("\n\n	The root was not found!\n");
			break;
			case 2:
				printf("\n\n	A raiz nao foi encontrada!\n");
			break;
		}
  	} else
  	{
  		switch (language)
		{
			case 1:
				printf("\n\n	The root of the function is: 5.5f\n", x);
			break;
			case 2:
				printf("\n\n	A raiz da funcao eh: %.5f\n", x);
			break;
		}
    }
  	switch (language)
	{
		case 1:
			printf("\n\n	PROGRAM COMPLETED!\n\n\n");
		break;
		case 2:
			printf("\n\n	PROGRAMA FINALIZADO!\n\n\n");
		break;
	}
  	system("pause");
	return 0;
}


void calculate(int& kp, int& kn, double& v1, double& v2, double x, double& dv1, double& dv2, char *p1, double *n1){

/*
In the "calculate" function, the characters of the vector "p1" are checked and, according to the case,
the appropriate operations are performed for the calculation of "v1" at the given point x, as well as for the calculation of the derivative "dv1" at this same point.
The values of "v1" and "dv1", as they are being calculated, are approaching, respectively, the values of y and dy to be found.
*/

/*
Na função "calculate" é feita a verificação dos caracteres do vetor "p1" e, de acordo com o caso, 
são feitas as operações adequadas para o cálculo de "v1" no ponto x dado, bem como para o cálculo da derivada "dv1" neste mesmo ponto.
Os valores de "v1" e "dv1", a medida que vão sendo calculos, vão se aproximando, respectivamente, dos valores de y e dy a serem encontrados.
*/


	
	switch(p1[kp]){
	  
		case 'z':	
        	v1 = n1[kn];
        	kn++;
        	if (p1[kp + 1] == 'x' || p1[kp + 1] == '('){
           		v1 = v1*operation(kp, kn, v2, x, p1, n1);
                dv1 = v1*derivative(kp, kn, v2, x, dv2, p1, n1);
     		}
      	break;	
	
		case '+':
			v2 = operation(kp, kn, v2, x, p1, n1);
     		dv2 = derivative(kp, kn, v2, x, dv2, p1, n1);
     		v1 = v1 + v2;
     		dv1 = dv1 + dv2;
    	break;

    	case '-':
			v2 = operation(kp, kn, v2, x, p1, n1);
     		dv2 = derivative(kp, kn, v2, x, dv2, p1, n1);
     		v1 = v1 - v2;
     		dv1 = dv1 - dv2;
    	break;
      
    	case '*':
			v2 = operation(kp, kn, v2, x, p1, n1);
     		dv2 = derivative(kp, kn, v2, x, dv2, p1, n1);
     		v1 = v1 * v2;
        	dv1 = dv1*v2 + v1*dv2;
    	break;
      
    	case '/':
			v2 = operation(kp, kn, v2, x, p1, n1);
     		dv2 = derivative(kp, kn, v2, x, dv2, p1, n1);
     		v1 = v1 / v2;
     		dv1 = (dv1*v2-v1*dv2)/pow(v2, 2);
    	break;

    	case '^':
			v2 = operation(kp, kn, v2, x, p1, n1);
     		dv2 = derivative(kp, kn, v2, x, dv2, p1, n1);
     		v1 = pow(v1, v2);
     		dv1 = pow(v1, v2)*((v2*dv1/v1) + dv2*(log(M_E)/log(v1)));
    	break;

    	case 'x':
    		v1 = x;
    		dv1 = 1;
    	break;
    	
    	case '(':
    		v1 = parentheses(kp, kn, x, p1, n1);
    		dv1 = parentheses_deriv(kp, kn, x, p1, n1);
    	break;  
	}
	
}

//The functions below are also required to calculate "v1" and "dv1".

//As funções abaixo também são necessárias ao cálculo de "v1" e "dv1".


double operation(int& kp, int& kn, double& v2, double x, char*p1,  double *n1){
    	
		double LOCv1 = 0;
		double LOCdv1 = 0;
    	double LOCdv2 = 0;
		
		standard_procedure(kp, kn, LOCv1, v2, x, LOCdv1, LOCdv2, p1, n1);
    	return v2;
}

double derivative(int kp, int kn, double v2, double x, double& dv2, char *p1,  double *n1){
    	
		double LOCv1 = 0;
		double LOCdv1 = 0;
    	
		standard_procedure(kp, kn, LOCv1, v2, x, LOCdv1, dv2, p1, n1);
    	return dv2;
}

double parentheses(int kp, int kn, double x, char*p1,  double *n1){
    	
		double LOCv1 = 0;
		double LOCv2 = 0;
		double LOCdv1 = 0;
    	double LOCdv2 = 0;
    	kp++;
        while (p1[kp] != ')')
		{
            calculate(kp, kn, LOCv1, LOCv2, x, LOCdv1, LOCdv2, p1, n1);
            kp++;
        }
        return LOCv1;
}


double parentheses_deriv(int& kp, int& kn, double x, char*p1,  double *n1){
    	
		double LOCv1 = 0;
		double LOCv2 = 0;
		double LOCdv1 = 0;
    	double LOCdv2 = 0;
    	kp++;
        while (p1[kp] != ')')
		{
            calculate(kp, kn, LOCv1, LOCv2, x, LOCdv1, LOCdv2, p1, n1);
            kp++;
        }
        return LOCdv1;
}

void standard_procedure(int& kp, int& kn, double& v1, double& v2, double x, double& dv1, double& dv2, char *p1,  double *n1){
    	
		int situation;
    	
     	switch(p1[kp + 1]){
     		case 'z':
          		if (p1[kp] == '+' || p1[kp] == '-')
             		situation = 1;
             	if (p1[kp] == '*' || p1[kp] == '/')
                	situation = 2;
          		if (p1[kp] == '^')
             		situation = 3;
     		break;     
     	}

	
}
