#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ilosc_zmian=0;
	int ilosc_zmian_dla_obiegu = 0;
	int Tab_[5];
	printf("Wygenerowany ciag:\n");
	for (int i = 0; i < (sizeof(Tab_) / 4); i++)
	{
		Tab_[i] = rand() % 50;
		printf("%d, ", Tab_[i]);
	}
	printf("\n###################################################################################################");
	//printf("#####################################################################################################\n");
	for (int i = 0; i <= ((sizeof(Tab_) / 4)-1) ; i++)
	{
		for (int k = 0; k <= (((sizeof(Tab_) / 4) - 1)-i); k++)
		{
			if (Tab_[k - 1] > Tab_[k])
			{
				int zmiana = Tab_[k - 1];
				Tab_[k - 1] = Tab_[k];
				Tab_[k] = zmiana;
				ilosc_zmian++;
				ilosc_zmian_dla_obiegu++;
			}
			

		}
		printf("\n Aktualny ciag dla obiegu nr %d :\n",i+1);
		for (int i = 0; i < (sizeof(Tab_) / 4); i++)
		{
			printf("%d, ", Tab_[i]);
		}
		printf("\n Ilosc zmian  %d",ilosc_zmian_dla_obiegu);
		if (ilosc_zmian_dla_obiegu == 0)
		{
			break;
		}
		else
		{
			ilosc_zmian_dla_obiegu = 0;
		}
		printf("\n###################################################################################################");
		//printf("#####################################################################################################\n");
	}
	printf("\n###################################################################################################");
	//printf("#####################################################################################################\n"); 
	printf("\nPosortowany ciag:\n");
	for (int i = 0; i < (sizeof(Tab_) / 4); i++)
	{
		printf("%d, ", Tab_[i]);
	}
	printf("\n Ilosc zmian: %d\n", ilosc_zmian);
	system("PAUSE");
	return 0;
}
