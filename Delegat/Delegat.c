#include <stdio.h>
#include <malloc.h>
#include "Header.h"

int intfuc;

typedef int (*f)(int, int);
typedef f* delegate;

delegate initgelegat()
{
	delegate g = calloc(1, sizeof(f));
	return g;
}

void addFunc(delegate g, f func)
{
	g[intfuc] = func;
	intfuc++;
	g = realloc(g, (intfuc + 1) * sizeof(func));
}

void removeFunc(delegate g, f func)
{
	for (size_t i = 0; i < intfuc; i++)
	{
		if (g[i]== func)
		{
			g[i] = NULL;
				break;
		}
	}
}

void removePovtor(delegate g)
{
	int k = 0, p = 0, l = 0;
	do
	{ 
		int s = 0, r = 0, y = 0;
		for (size_t i = 0; i < intfuc; i++)
		{

			if (g[i])
			{
				if (g[i] == Summ)
				{
					s++;
					if (s > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							g[j] = g[j + 1];
						}
					}
				}
				else if (g[i] == Razn)
				{
					r++;
					if (r > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							g[j] = g[j + 1];
						}
					}
				}
				else if (g[i] == Ymn)
				{
					y++;
					if (y > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							g[j] = g[j + 1];
						}
					}
				}
				g = realloc(g, (intfuc + 1) * sizeof(f));

			}

		}
		k = s;
		p = r;
		l = y;
	} while ((k > 1) || (p > 1) || (l > 1));

}

void Show(delegate g, int a, int b)
{
	for (size_t i = 0; i < intfuc; i++)
	{
		if (g[i])
		{
			printf("%d ", g[i](a, b));
		}
	}
	printf("\n");
}

int main()
{
	delegate g = initgelegat();
	addFunc(g, Summ);
	addFunc(g, Razn);
	addFunc(g, Ymn);
	addFunc(g, Ymn);
	addFunc(g, Razn);
	addFunc(g, Summ);
	addFunc(g, Summ);
	addFunc(g, Razn);
	addFunc(g, Ymn);
	addFunc(g, Ymn);
	addFunc(g, Razn);
	addFunc(g, Summ);


	Show(g, 8, 2);
	removeFunc(g, Summ);
	Show(g, 8, 2);
	removePovtor(g);
	Show(g, 8, 2);

	return 0;
}
