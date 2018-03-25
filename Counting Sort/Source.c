#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE *Plik1 = fopen("file2.txt", "w");
	FILE *Plik2 = fopen("Losowe_bez_sortowania.txt", "w");
	int Vector1[255];
	int Tab[sizeof(Vector1)/4];
//////////////////////////////////////////////////////////
	for (int z = 0; z < sizeof(Vector1)/4; z++)
		Tab[z] = 0;

	for (int b = 0; b < sizeof(Vector1) / 4; b++)
	{
		Vector1[b] = rand() % (sizeof(Vector1) / 4);
		Tab[Vector1[b]]++;
	}

	for (int j = 0; j < sizeof(Vector1) / 4; j++)
		fprintf(Plik2, "%d, ", Vector1[j]);

	for (int k = 0; k < sizeof(Vector1) / 4; k++)
	{
		if (Tab[k] > 0)
		{
		//	printf("%d, %d \n", k, Tab[k]);
			fprintf(Plik1, "%d	%d\n", k, Tab[k]);
		}
	}

	fclose(Plik1, Plik2);
	getchar();
	return 0;
}