#include <stdio.h>
#include <stdlib.h>
#include "heap.hpp"
// Heap functions are :
// heap(), max_weight(), max_vertex, delete_max(), Insert(vertex, weight)
// Delete(vertex), heapify(vertex_bug), heap_size(), change_size(heap_size)
int main(int argc, char * argv[])
{
    heap * test_heap;
    FILE *fp;
    fp = fopen("argv[1]", "r");
    
    test_heap = new heap();
    
    if(!fp)
    {
        if(argv[2]) printf("Error 01 : file: %s not found\n",argv[2]);
        printf("Error 02 : file open failed.\n");
        printf("proper usage: ./program_name input_filename\nPlease try again...\n\n");
        exit(0);
    }
    else
    {
        int flag = 0;
        while(flag !=0)
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
                if(v1<v2) edge = v1*10 + v2;
                else edge = v2*10 + v1;
                test_heap->Insert(edge, w);
            }
            
        }
     }
    //int i = 1;
    while(test_heap->heap_size()!=0)
    {
        int vertex, weight;
        
        weight = test_heap->max_weight();
        vertex = test_heap->max_vertex();
        //if (i==1)
        //{
            printf("edge = %d, weight = %d\n", vertex, weight);
            //i = i+1;
        //}
    }
    
    fclose(fp);
    return 0;
}
