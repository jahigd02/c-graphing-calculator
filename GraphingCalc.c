#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ParseFunction();

typedef struct expression{
	
	int cft;
	
}term;

int funcChoice;
char trigChoice[3];
int trigInsideChoice;
int degree;
term pnm[10];
char board [100][100];
int v;

int main()
{
	ClearPolynomial();
	degree = 0;
	v = 0;
	system("COLOR 0B");
	Menu();
}

void Menu()
{
	printf("What type of funcion?\n\n");
	printf("1- Polynomial\n");
	printf("2- Trigonometric\n");
	
	scanf("%d", &funcChoice);
	
	switch (funcChoice)
	{
		case 1:
			ParsePolynomial();
			break;
		case 2:
			ParseTrig();
			break;
	}
}

void ParsePolynomial()
{
	//Retreives the desired degree of the polynomial
	printf("Degree of polynomial?\n");
	scanf("%d", &degree);
	
	//For each member of polynomial:
	int a;
	for (a = 0; a < degree; a++)
	{
		//Make a new term in the polynomial, and scanf() it to initialize its coefficient.
		term newTerm;
		newTerm.cft = 0;
		if (a < degree)
		{
			printf("Coefficient of degree %d term: ", a+1);
			scanf("%d", &newTerm.cft);	
			
		} else //The maximum degree is a static value, so once the for loop reaches user's desired degree, just initialize remaining coefficients to ZERO so they don't effect the function
		{
			newTerm.cft = 0;
		}
		//Asign term at spot [a] of term array pnmp[] to this newTerm
		pnm[a] = newTerm;	
	}
	
	DrawBoard();
	
}

void ParseTrig()
{
	printf("Which trigonometric function? sin, cos, tan, csc, sec, cot\n");
	scanf("%s", &trigChoice);
	
	trigInsideChoice = 1;
	
	DrawBoard();
}

void DrawBoard() //GUI OF GRAPH, AND LOGIC TO DRAW FUNC
{
	
	int x = 0;
	int y = 0;
	//Initializes row
	for(y = 0; y < 100; y++)
	{
		//Initializes column
		for(x = 0; x < 100; x++)
		{
			//Sets every coordinate to the blank tile (ASCII CODE 176-- FADED BOX) (this is for 
			board[y][x] = 176;
			
			//Determines the x/y coordinate based on the halfway point of each dimension (the axes) and subtracts current spot to get SIGNED distance (coordinate)
			int yCoord = (50 - y);
			int xCoord = (50 - x);
			
			//Absolute distances of coordinates from respective axes
			int height = abs(yCoord);
			int length = abs(xCoord);
			
			switch (funcChoice)
			{
				//The actual logic that draws the graph-- if the function of the x Coordinate is equal to the y coordinate, I.E, if the coordinate (x,y) is a solution
				//to the function, color that coordinate in with a tile (ASCII CODE 178).
				case 1:	
					if (Polynomial(-xCoord) == yCoord)
					{
						board[y][x] = 178;

					}
					break;
				case 2:
					if (Trig(-xCoord) == yCoord)
					{
						board[y][x] = 178;
					}
					break;
			}
		
			//Prints axes as - characters, overriding any previous graph
			if (x == 50 || y == 50)
			{
				board[y][x] = '-';
			}
		}
	}
	
	//Prints entire 2D array as actual graph 
	for(y = 0; y < 100; y++)
	{
		for(x = 0; x < 100; x++)
		{
			printf("%c", board[y][x]);
		}
		printf("\n");
	}
	
	switch (funcChoice)
	{
		case 1:
			PrintPolynomial();
			break;
		case 2:
			break;
	}
	//Prints out the constructed function into text

	main();
	
}


int Trig(int v)
{

	if (trigInsideChoice == 1)
	{
		if(strcmp(trigChoice, "sin") == 0)
		{
			int answer = sin(v*314159)*10;
			return answer;
		} else if (strcmp(trigChoice, "cos") == 0)
		{
			int answer = cos(v*314159)*10;
			return answer;
		} else if (strcmp(trigChoice, "tan") == 0)
		{
			int answer = tan(v*314159)*10;
			return answer;
		} else if (strcmp(trigChoice, "csc") == 0)
		{
			int answer = 1/(sin(v*314159)*10);
			return answer;
		} else if (strcmp(trigChoice, "sec") == 0)
		{
			int answer = 1/(cos(v*314159)*10);
			return answer;
		} else if (strcmp(trigChoice, "cot") == 0)
		{
			int answer = 1/(tan(v*314159)*10);
			return answer;
		}
	} else 
	{
		return 0;
	}
}


int Polynomial(int v)
{
	
	//Assign function to be sum of polynomials (1-10 degrees, with unwanted degrees * zero) and their coefficients
	int answer = pnm[0].cft*v + pnm[1].cft*(v*v)/(10*degree) + pnm[2].cft*(v*v*v)/(10*degree) + pnm[3].cft*(v*v*v*v)/(100*degree) + pnm[4].cft*(v*v*v*v*v)/(1000*degree) + pnm[5].cft*(v*v*v*v*v*v)/(10000*degree) + pnm[6].cft*(v*v*v*v*v*v*v)/(100000*degree) + pnm[7].cft*(v*v*v*v*v*v*v*v)/(1000000*degree) + pnm[8].cft*(v*v*v*v*v*v*v*v*v)/(1000000*degree) + pnm[9].cft*(v*v*v*v*v*v*v*v*v*v)/(100000000*degree);
	return answer;
}

void PrintPolynomial()
{
	int a;
	for(a = 0; a < degree; a++)
	{
		if (pnm[a].cft != 0)
		{
				if (a == 0)
				{
					if (pnm[a].cft == 1)
					{
						printf("x^%d +", pnm[a].cft, a+1);
					} else
					{
						printf("%dx^%d +", pnm[a].cft, a+1);
					}
					
				} else if (a > 0 && a < degree-1)
				{
					if (pnm[a].cft == 1)
					{
						printf(" x^%d + ", pnm[a].cft, a+1);
					} else
					{
						printf(" %dx^%d + ", pnm[a].cft, a+1);
					}
					
				} else 
				{
					if (pnm[a].cft == 1)
					{
							printf(" x^%d", pnm[a].cft, a+1);
					} else
					{
						printf(" %dx^%d", pnm[a].cft, a+1);
					}
			}
		}		
	}
	
	printf("\n");
}

void ClearPolynomial()
{
	int a;
	for (a = 0; a < 10; a++)
	{
		pnm[a].cft = 0;
	}
}


