#include<stdlib.h>
#include <stdio.h>
//int k = 0;
int Podzial(int Tab[], int Start, int End)
{
 
    /*int _index = Start ;
    int wartosc = Tab[Start];
    int piv = Start+1;*/
   
    int pivot, i, j, t;
    pivot = Tab[Start];
    i = Start; j = End + 1;
 
    while (1)
    {
        do ++i; while (Tab[i] <= pivot && i <= End);
        do --j; while (Tab[j] > pivot);
        if (i >= j) break;
        t = Tab[i]; Tab[i] = Tab[j]; Tab[j] = t;
    }
    t = Tab[Start]; Tab[Start] = Tab[j]; Tab[j] = t;
    return j;
    /*for (int i = Start; i < (End-1); i++)
    {
       
        if (Tab[i] < wartosc )
        {
           
            piv++;
           
        }
 
    }
 
        int zmina3 = Tab[End];
        Tab[End] = Tab[piv];
        Tab[piv] = zmina3;
 
    k++;
    for (int i = 0; i < 10; i++)
        printf("%d, ", Tab[i]);
    printf("\n index :%d \n Pozycja: %d \n k: %d \n End: %d \n\n", _index, piv, k, End);*/
   
}
 
void quick_sort(int Tab[], int Start, int End)
{
    if (Start < End)
    {
        int Pivot_point = Podzial(Tab, Start, End);
        quick_sort(Tab, Start, Pivot_point - 1);
        quick_sort(Tab, Pivot_point + 1, End);
    }
}
 
 
int main()
{
    int tab_war[20] ;
    for (int i = 0; i < sizeof(tab_war) / 4; i++)
        tab_war[i] = rand() % (sizeof(tab_war) / 4);
 
    printf("\t\t\tPrzed sortowaniem:\n\n");
    for (int i = 0; i < sizeof(tab_war)/4; i++)
        printf("%d, ", tab_war[i]);
 
    quick_sort(tab_war, 0, (sizeof(tab_war) / 4)-1);
    printf("\n\n#####################################################################################\n\n\t\t\tPo sortowaniu:\n\n");
    for (int i = 0; i < sizeof(tab_war) / 4; i++)
        printf("%d, ", tab_war[i]);
    printf("\n");
    system("PAUSE");
 
}
