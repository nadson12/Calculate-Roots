#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;


void calculate(int&, int&, double& ,double&, double, char[], double[], int);
double operation(int&, int&, double&, double&, double, char[], double[], int);


int main(void)
{

//Declaration of variables
//Declaração das variáveis
	
	char a, m[1], *p1 = NULL;
	int i = 0, j = 1, k0, k1 = 0, count0 = 1, count1 = 1, kp, kn, stop = 0, language;
	double v1, v2, x, dv1, dv2, y, dy, mult10, *n1 = NULL;
	string expres;


//Choosing the language of the program
//Escolhendo a língua do programa

	printf("\n\n\n	Please, Choose your language.\n\n	Por favor, escolha qual a sua lingua.\n\n\n\n	(1) English/Ingles\n\n	(2) Portuguese/Portugues\n\n");
	do
	{
		cout << "\n\n\n	Language/Lingua: ";
		cin >> language;
		if (language != 1 && language != 2)
			cout << "\n\n	Invalid choice!\n\n	Escolha invalida!";
	} while (language != 1 && language != 2);


//Determining the expression that represents the function. The expression will be recorded in the variable "expres"
//Determinando a expressão que representa a função. A expressão ficará gravada na variável "expres"
		
	system("cls");
		
  	switch (language)
	{
		case 1:
			cout << "\n\n\n	Enter an expression for f(x):\n";
		break;
		case 2:
			cout << "\n\n\n	Digite uma expressao para f(x):\n";
		break;
	}
	
	cout <<"\n	y = ";
	cin >> expres;

	
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
	
	int n0[expres.size()];
	char p0[expres.size()];
	
	
	for (k0 = 0; k0 < expres.size(); k0++)
	{
		if (expres[k0] == '0' || expres[k0] == '1' || expres[k0] == '2' || expres[k0] == '3' || expres[k0] == '4' || expres[k0] == '5'
		                                           || expres[k0] == '6' || expres[k0] == '7' || expres[k0] == '8' || expres[k0] == '9') 
		{
			
        	m[0] = expres[k0];
        	n0[k0] = atoi(m);
        	p0[k0] = 'z';
        	 
			
			if (k0+1 < expres.size())
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
        		if (k0 > 0)
        			count1++;

        		if (k0+1 < expres.size())
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
	n0[expres.size()] = -99999;
	p0[expres.size()] = '\0';
	

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
	
	
	for (k0 = 0; k0 < expres.size(); k0++)
  	{
  		if (n0[k0] != -99999)
		{
			n1[k1] = n0[k0];
			k0++;				
			if (k0 < expres.size())
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
		if (k0 < expres.size())
		{
			if (p1[k1] == 'z')
			{				
				while (p0[k0] == 'z')
				{
					k0++;
				}
				if (k0 < expres.size())
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
	} while (k0 < expres.size());
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

	cout << "\n\n\n	x[n] = x[n - 1] - y/y'\n\n";
	switch (language)
	{
		case 1:
			cout << "\n\n	Enter the value of x[0] in which you want to derive the function.\n\n ";
		break;
		case 2:
			cout << "\n\n	Digite o valor de x[0] no qual deseja derivar a funcao.\n\n";
		break;
	}
	
	
  	cout << "	x[0] = ";
	cin >> x;
  	 
  	do{
    	kp = 0;
    	kn = 0;
    	v1 = 0;
    	v2 = 0;
    	dv1 = 0;
    	dv2 = 0;
     
    	while (kp < count1){
        	calculate(kp, kn, v1, dv1, x, p1, n1, language);
     	}
	 	y = v1;
     	dy = dv1;
     	stop++;
     	if (dy == 0)
     	{
     		switch (language)
				{
					case 1:
						cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
						system("pause");
						exit(0);	
						break;
					case 2:
						cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa será encerrado imediatamente!\n\n\n";
						system("pause");
						exit(0);
						break;
				}	
		}
     	cout << "\n	x[" << stop << "] = " ;
     	x -= y/dy;
     	printf("%f\n", x);
     	if (stop == 50)
        	break;
     	
  	} while (y > 0.000000000000000000000000001 || y < -0.000000000000000000000000001);
  	if (stop == 50)
  	{
  		switch (language)
		{
			case 1:
				cout << "\n\n\n	The root was not found!\n";
			break;
			case 2:
				cout << "\n\n\n	A raiz nao foi encontrada!\n";
			break;
		}
  	} else
  	{
  		switch (language)
		{
			case 1:
				printf("\n\n\n	The root of the function is x = %.5f", x);
			break;
			case 2:
				printf("\n\n\n	A raiz da funcao eh x = %.5f", x);
			break;
		}
    }
  	switch (language)
	{
		case 1:
			cout << "\n\n\n	PROGRAM COMPLETED!\n\n\n";
		break;
		case 2:
			cout << "\n\n\n	PROGRAMA FINALIZADO!\n\n\n";
		break;
	}
  	system("pause");
	return 0;
}


void calculate(int& kp, int& kn, double& v1, double& dv1, double x, char *p1, double *n1, int language){

/*
In the "calculate" function, the characters of the vector "p1" are checked and, according to the case,
the appropriate operations are performed for the calculation of "v1" at the given point x, as well as for the calculation of the derivative "dv1" at this same point.
The values of "v1" and "dv1", as they are being calculated, are approaching, respectively, the values of y and dy to be found.
A "calculete" function performs as operations, respecting a priority order in the calculation.
Empowerment has high priority. Then comes a multiplication and a division, with a high priority.
And, finally, addition and subtraction are performed, which have low priority.
*/

/*
Na função "calculate" é feita a verificação dos caracteres do vetor "p1" e, de acordo com o caso, 
são feitas as operações adequadas para o cálculo de "v1" no ponto x dado, bem como para o cálculo da derivada "dv1" neste mesmo ponto.
Os valores de "v1" e "dv1", a medida que vão sendo calculos, vão se aproximando, respectivamente, dos valores de y e dy a serem encontrados.
A função "calculete" realiza as operações necessárias, respeitando a ordem de prioridade no cálculo.
A potenciação tem alta prioridade. Depois vem a multiplicação e a divisão, com prioridade méida. 
E, por fim, realiza-se a adição e a subtração, que têm prioridade baixa.
*/


	double v2 = 0;
	double dv2 = 0;
	double v3 = 0;
	double dv3 = 0;
	
	switch(p1[kp]){
	  
		case 'z':
			dv1 = 0;
        	v1 = n1[kn];		
			kp++;
			kn++;
	      	break;	
	
		case '+':
			kp++;			
			operation(kp, kn, v2, dv2, x, p1, n1, language);
			dv3 = dv2;
			v3 = v2;
    		while (p1[kp] == '*' || p1[kp] == '/' || p1[kp] == '^')
    		{
    			if (p1[kp] == '*')
    			{
  					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					dv3 = dv3*v2 + v3*dv2;
					v3 = v3 * v2;
    	    	} else if (p1[kp] == '/')
    	    	{
					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					if (v2 == 0)
					{
						switch (language)
						{
							case 1:
								cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
								system("pause");
								exit(0);	
								break;
							case 2:
								cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
								system("pause");
								exit(0);
								break;
						}
					}
     				dv3 = (dv3*v2-v3*dv2)/pow(v2, 2);
					v3 = v3 / v2;   		
				} else
				{	
					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
	     			if (v1 > 0)
					 	dv1 = pow(v1, v2)*((v2/v1)*dv1 + dv2*(log(v1)));
					else if (v1 < 0)
						dv1 = pow(v1, v2)*((v2/v1)*dv1 + dv2*(log(-v1)));
					else
					{
					  	switch (language)
						{
							case 1:
								cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
								system("pause");
								exit(0);	
								break;
							case 2:
								cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
								system("pause");
								exit(0);
								break;
						}
					}
					v3 = pow(v3, v2);
				}

			}
			dv1 = dv1 + dv3;
			v1 = v1 + v3;
    		break;

    	case '-':
			kp++;
			operation(kp, kn, v2, dv2, x, p1, n1, language);
			dv3 = dv2;
			v3 = v2;
    		while (p1[kp] == '*' || p1[kp] == '/' || p1[kp] == '^')
    		{
    			if (p1[kp] == '*')
    			{
  					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					dv3 = dv3*v2 + v3*dv2;
					v3 = v3 * v2;
    	    	} else if (p1[kp] == '/')
    	    	{
					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					if (v2 == 0)
					{
						switch (language)
						{
							case 1:
								cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
								system("pause");
								exit(0);	
								break;
							case 2:
								cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
								system("pause");
								exit(0);
								break;
						}
					}
     				dv3 = (dv3*v2-v3*dv2)/pow(v2, 2);
					v3 = v3 / v2;   		
				} else
				{	
					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
	     			if (v1 > 0)
					 	dv1 = pow(v1, v2)*((v2/v1)*dv1 + dv2*(log(v1)));
					else if (v1 < 0)
						dv1 = pow(v1, v2)*((v2/v1)*dv1 + dv2*(log(-v1)));
					else
					{
					  	switch (language)
						{
							case 1:
								cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
								system("pause");
								exit(0);	
								break;
							case 2:
								cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
								system("pause");
								exit(0);
								break;
						}
					}
					v3 = pow(v3, v2);
				}

			}
    		dv1 = dv1 - dv3;
			v1 = v1 - v3;
			break;
			      
    	case '*':
    		while (p1[kp] == '*' || p1[kp] == '/')
    		{
    			if (p1[kp] == '*')
    			{
  					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					dv1 = dv1*v2 + v1*dv2;
					v1 = v1 * v2;
    	    	} else if (p1[kp] == '/')
    	    	{
					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					if (v2 == 0)
					{
						switch (language)
						{
							case 1:
								cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
								system("pause");
								exit(0);	
								break;
							case 2:
								cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
								system("pause");
								exit(0);
								break;
						}
					}     				
					dv1 = (dv1*v2-v1*dv2)/pow(v2, 2);
					v1 = v1 / v2;   		
				}
			} 
    		break;
      
    	case '/':
    		while (p1[kp] == '*' || p1[kp] == '/')
    		{
    			if (p1[kp] == '*')
    			{
  					kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
     				dv1 = dv1*v2 + v1*dv2;
					v1 = v1 * v2;
    	    	} else if (p1[kp] == '/')
    	    	{
    	    		kp++;
					operation(kp, kn, v2, dv2, x, p1, n1, language);
					if (v2 == 0)
					{
						switch (language)
						{
							case 1:
								cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
								system("pause");
								exit(0);	
								break;
							case 2:
								cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
								system("pause");
								exit(0);
								break;
						}
					}     				
					dv1 = ((dv1*v2)-(v1*dv2))/pow(v2, 2);
					v1 = v1 / v2;  		
				}
        	} 
    		break;
    	case '^':
    		kp++;
			operation(kp, kn, v2, dv2, x, p1, n1, language);
     		if (v1 > 0)
			 	dv1 = pow(v1, v2)*((v2/v1)*dv1 + dv2*(log(v1)));
			else if (v1 < 0)
				dv1 = pow(v1, v2)*((v2/v1)*dv1 + dv2*(log(-v1)));
			else
			{
			  	switch (language)
				{
					case 1:
						cout << "\n\n\n	Unexpected error: Unable to divide by 0. \n\n	The program will be terminated immediately!\n\n\n";
						system("pause");
						exit(0);	
						break;
					case 2:
						cout << "\n\n\n	Erro inesperado: Imposivel dividir por 0.\n\n	O programa sera encerrado imediatamente!\n\n\n";
						system("pause");
						exit(0);
						break;
				}
			}
			v1 = pow(v1, v2);
			break;

    	case 'x':
			dv1 = 1;
			v1 = x;		
			kp++;
    		break;
    	
    	case 'e':
    		dv1 = 0;
    		v1 = M_E;
 			kp++;
    		break;   		
    	
    	case '(':
    		kp += 1;
    		while (p1[kp] != ')'){
      	  		calculate(kp, kn, v1, dv1, x, p1, n1, language);
     		}
			kp++;
			break;  
	}
}

//The "operation" function assists the "calculate" function, ensuring that the exponentiation is always performed before the other operations.

//A função "operation" auxilia a função "calculate", garantindo que a operação de potenciação seja sempre efetuada antes das outras operações.


double operation(int& kp, int& kn, double& v1, double& dv1, double x, char*p1,  double *n1, int language){
			do
			{
				calculate (kp, kn, v1, dv1, x, p1, n1, language);
			} while (p1[kp] == '^');
}

