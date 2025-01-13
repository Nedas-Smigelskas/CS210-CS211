#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
double traitorsim(int n)
{
    int traitorvictories = 0;
    int simulations = 1000000;
    for (int i = 0; i < simulations; i++)
    {
        int traitors = n;
        int participants = 22 - n;
        int totalremain = participants + traitors;
        while (totalremain > 2)
        {
            if (participants > 0)
            {
                participants--;
                totalremain--;
            }
            if (traitors > 0)
            {
                int kill = rand() % totalremain;
                if (kill < traitors)
                {
                    traitors--;
                }
                else
                {
                    participants--;
                }
                totalremain--;
            }
        }
        if (participants < 2)
        {
            traitorvictories++;
        }
        /*printf("Remaning : %d\n", totalremain);
        printf("Traitor victories : %d\n", traitorvictories);
        printf("Traitors : %d\n", traitors);
        printf("Survivors : %d\n-------\n", participants);*/
    }
    return ((double)traitorvictories / (double)simulations) * 100.0;
}

int main()
{
    srand(time(NULL));
    int evil;
    printf("How many traitors? : ");
    scanf("%d", &evil);
    printf("%.2f", traitorsim(evil));
    return 0;
}