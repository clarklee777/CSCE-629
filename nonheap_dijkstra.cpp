/* The implementation of Dijsktra Algorithm without using heap structure for fringes */
#include <stdio.h>
#include <stdlib.h>
#include "linkgraph.hpp"

int main(argc, argv[])
{
    list *edges;
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
                
                /* Make the edge name XX_YY, XX is the small vertex number while YY is larger */
                if(v1<v2) edge = v1*100 + v2;
                else edge = v2*100 + v1;
                test_heap->Insert(edge, w);
                
            }
            
        }
    }
}