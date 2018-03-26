/*======================================================*/
/*====================== Heap Sort =====================*/
/*================== Bartek Zoltowski ==================*/
/*======================== 2017 ========================*/
/*======================================================*/
#include <stdio.h>
#include <conio.h>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
int Vectors[5];
uint8_t s_Vec = sizeof(Vectors) / 4;



void heap(int i)
{
	int MaxIndex=i;
	int left = (2 * i) + 1, right = left + 1;
	if ((left < s_Vec) && Vectors[left]>Vectors[MaxIndex])
		MaxIndex = left;
	
	if ((right < s_Vec) && Vectors[right]>Vectors[MaxIndex])
		MaxIndex = right;
	//printf("\n============================================\ni=%d, Largest=%d, r = %d, L= %d\n\n", i, Largest,right,left);
	//for (int i = 0; i < s_Vec; i++)
	//	printf("%d, ", Vectors[i]);
	if (MaxIndex != i )
	{
		int zmiana = Vectors[MaxIndex];
		Vectors[MaxIndex] = Vectors[i];
		Vectors[i] = zmiana;
		heap(MaxIndex);
	}
	/*printf("\n||||||||||||||||||||||||||||||||||||||||||||||\ni=%d, Largest=%d, r = %d, L= %d\n\n", i, Largest, right, left);
	for (int i = 0; i < s_Vec; i++)
		printf("%d, ", Vectors[i]);
	printf("\n============================================\n");*/
}

void SPK()
{	
	for (int i = (s_Vec / 2)-1; i >=0; i--)
		heap(i);


	//printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");

	for (int i = s_Vec-1; i>0; i--)
	{
		int zmiana = Vectors[i];
		Vectors[i] = Vectors[0];
		Vectors[0] = zmiana;
		s_Vec--;
		heap(0);
	}


}


int main()
{

	printf("Przed Sortowaniem:\n");
	for (int i = 0; i < sizeof(Vectors) / 4; i++)
	{
		Vectors[i] = rand() % 256;
		printf("%d, ", Vectors[i]);
	}

	SPK();


	printf("\n\nPo Sortowaniu:\n");
	for (int i = 0; i < sizeof(Vectors) / 4; i++)
		printf("%d, ", Vectors[i]);


	_getch();
	return 0;
}
