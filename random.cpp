/* Uses Random Generatator to construct graphs */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TOTAL_VERTICES 5000

int main()
{
    int random;
    bool edge_list[TOTAL_VERTICES][TOTAL_VERTICES];
    FILE *fp;
    fp = fopen("graph1.txt", "w");
    srand(time(NULL));              //start the random seed
    /*for (int i = 0; i<10 ; i++)
    {
        random = rand()%10 +1;
        fprintf(fp, "the %d random number = %d\n", i, random);
    }*/
    
    /* To ensure the sparse graph is connected and initialize the edge list */
    
    for (int i=0; i<TOTAL_VERTICES; i++)
    {
        for(int l=0; l<TOTAL_VERTICES; l++)
        {
            if (l == (i+1))
            {
                fprintf(fp, "%d %d\n", i, l);
                printf("%d %d\n", i, l);
                edge_list[i][i+1] = 1;
            }
            else edge_list[i][l]=0;
        }
    }
    
    /* Assign edges, no repeat edge between vertices */
    for (int j=0; j<TOTAL_VERTICES; j++)
    {
        for (int k=0; k<TOTAL_VERTICES; k++)
        {
            if((j!=k)&&(edge_list[j][k]==0))
            {
                random = rand()%100 +1;
                if(random<4)
                {
                    fprintf(fp, "%d %d\n", j, k);
                    printf("%d %d\n", j, k);
                    edge_list[j][k] = 1;
                }
            }
        }
    }
    
    return 0;
}