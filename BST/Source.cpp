#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdint.h>

struct BST
{
	uint8_t date;
	struct BST *sL;
	struct BST *sP;
};

void add_node(struct BST **Ne, uint8_t De)
{
	if (*Ne == NULL) 
	{
		*Ne = (struct BST *)malloc(sizeof(struct BST));
		(*Ne)->date = De;
		(*Ne)->sL = (*Ne)->sP = NULL;
		return;
	}
	if ((*Ne)->date >= De)
		add_node(&(*Ne)->sL, De);
	if ((*Ne)->date < De)
		add_node(&(*Ne)->sP, De);

	return;

}
void wypisz(struct BST *N)
{
	if (N)
	{
		wypisz(N->sL);
		printf("%d, ", N->date);
		wypisz(N->sP);
	}
}

int main()
{
	uint8_t Vectors[6] = { 2,5,1,5,34,19 };
	struct BST *root = NULL;
	int i=0,j=0;
	printf("Przed sortowaniem:\n\n");
	do
	{
		printf("%d, ", Vectors[i]);
		i++;
	} while (i<sizeof(Vectors));


	do
	{
		add_node(&root, Vectors[j]);
		j++;
	} while (j<sizeof(Vectors));
	

	printf("\n\nPo sortowaniu:\n\n");

	wypisz(root);
	_getch();
	return 0;
}
