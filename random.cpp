/* Uses Random Generatator to construct graphs */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int random;
    FILE *fp;
    fp = fopen("graph1.txt", "w");
    srand(time(NULL));
    for (int i = 0; i<10 ; i++)
    {
        random = rand()%10 +1;
        fprintf(fp, "the %d random number = %d\n", i, random);
    }
    return 0;
}