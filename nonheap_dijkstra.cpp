/* The implementation of Dijsktra Algorithm without using heap structure for fringes */
#include <stdio.h>
#include <stdlib.h>
#include "link_list.hpp"

#ifndef
#define TOTAL_VERTICES 5000
#endif
list * edge_list[TOTAL_VERTICES];

/* Vertex struct for the graph */
struct vertex{
    int v_num;
    int label;
    int color; // color : 1 = white / 2 = grey / 3 = black
};

int main(argc, argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    test_heap = new heap();
    
    if(!fp)
    {
        if(argv[2]) printf("Error 01 : file: %s not found\n",argv[2]);
        printf("Error 02 : file open failed.\n");
        printf("file: %s not found\n",argv[1]);
        printf("proper usage: ./program_name input_filename\nPlease try again...\n\n");
        exit(0);
    }
    else
    {
        int flag = 0;
        while(flag ==0)
        {
            int v1, v2, w, edge;
            fscanf(fp,"%d %d %d", &v1, &v2, &w);
            if ((v1== 0)&&(v2==0)&&(w==0))
            {
                flag = 1;
                break;
            }
            else
            {
                edge_list[i] = new list();
                edge_list[i]->newvertex(i+1);
                edge_list[i]->newvertex(i-1);
                random = rand()%9999 +1;
                fprintf(fp, "%d %d %d\n", i, i+1, random);
                edge_count++;
                /* Make the edge name XX_YY, XX is the small vertex number while YY is larger */
                if(v1<v2) edge = v1*100 + v2;
                else edge = v2*100 + v1;
                
            }
            
        }
    }
}