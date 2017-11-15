/* Uses Random Generatator to construct graphs */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TOTAL_VERTICES 100

struct vertices{
    bool edges[TOTAL_VERTICES];
    int v_num;
};

int main()
{
    int random;
    int i, j, k, l;
    struct vertices vertex[TOTAL_VERTICES];
    //bool edge_list[TOTAL_VERTICES][TOTAL_VERTICES];
    FILE *fp;
    fp = fopen("graph1.txt", "w");
    srand(time(NULL));              //start the random seed
    /*for (int i = 0; i<10 ; i++)
    {
        random = rand()%10 +1;
        fprintf(fp, "the %d random number = %d\n", i, random);
    }*/
    
    /* To ensure the sparse graph is connected and initialize the edge list */
    
    for (i=0; i<TOTAL_VERTICES; i++)
    {
        for(l=0; l<TOTAL_VERTICES; l++)
        {
            if (l == (i+1))
            {
                fprintf(fp, "%d %d\n", i, l);
                //printf("%u %u\n", i, l);
                //edge_list[i][i+1] = 1;
                vertex[i].edges[l] = 1;
                vertex[l].edges[i] = 1;
            }
            else vertex[i].edges[l] = 0;
        }
    }
    
    /* Assign edges, no repeat edge between vertices */
    for (j=0; j<TOTAL_VERTICES; j++)
    {
        for (k=0; k<TOTAL_VERTICES; k++)
        {
            if((j!=k)&&(vertex[j].edges[k] == 0) && (vertex[k].edges[j]==0))
            {
                random = rand()%100 +1;
                if(random<4)
                {
                    fprintf(fp, "%d %d\n", j, k);
                    //printf("%u %u\n", j, k);
                    vertex[j].edges[k] = 1;
                    vertex[k].edges[j] = 1;
                }
            }
        }
    }
    fclose(fp);
    return 0;
}