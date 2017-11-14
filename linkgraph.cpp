/* Using linked list for random generating graphs */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "linkgraph.hpp"

#define TOTAL_VERTICES 100


int main()
{
    int random;
    int i, j, k, l;
    struct vertices *vertex[TOTAL_VERTICES];
    
    FILE *fp;
    fp = fopen("graph1.txt", "w");
    srand(time(NULL));              //start the random seed
    
    for (i=0; i<TOTAL_VERTICES; i++)
    {
        vertex[i]->v_num = i;
        vertex[i].next = NULL;
        vertex[i].prev = NULL;
    }
    
}