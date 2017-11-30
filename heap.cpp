/*
    Utilizes a max-heap to store the graph's edges
    This file is for verification of the heap class functionalities
 
    File:   heap.hpp
    Author: Ho Lee
    Date  : 2017/11
*/
#include "heap.hpp"
// Heap functions are :
// heap(), max_weight(), max_vertex, delete_max(), Insert(vertex, weight)
// Delete(vertex), heapify(vertex_bug), heap_size(), change_size(heap_size)
int main(int argc, char *argv[])
{
    heap * test_heap;
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
                if(v1<v2) edge = v1*10000 + v2;
                else edge = v2*10000 + v1;
                test_heap->Insert(edge, w);
                
            }
            
        }
     }
    test_heap->display_heap();
    /*
    while(test_heap->heap_size()!=0)
    {
        EDGE temp = test_heap->extract_max();
        int vertex, weight;
        int v1, v2;
        
        weight = temp.edge_weight;
        vertex = temp.edge_num;
        
        v1 = vertex/10000;
        v2 = vertex%10000;
        printf("edge = %d <-> %d, weight = %d\n", v1, v2, weight);

    }*/
    
    fclose(fp);
    return 0;
}
