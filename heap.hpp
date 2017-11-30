/*
    Utilizes a max-heap to store the graph's edges for max extraction
    The header file declares and describes class functions of max-heap class
 
    File:   heap.hpp
    Author: Ho Lee
    Date  : 2017/11
*/

// Heap functions are :
// heap(), max_weight(), max_vertex, delete_max(), Insert(vertex, weight)
// Delete(vertex), heapify(vertex_bug), heap_size(), change_size(heap_size)
#include <stdlib.h>
#include <stdio.h>
#ifndef TOTAL_SIZE
#define TOTAL_SIZE 3000000
#endif
struct EDGE{
    int edge_num;
    int edge_weight;
};

class heap{
    
private:
    int H[TOTAL_SIZE]; //heap array
    int D[TOTAL_SIZE]; //data array
    int h_size;        // Returns number of elements in the heap
    
public:
    /* Class initializer */
    heap()
    {
        int i = 0;
        while (i!=TOTAL_SIZE)
        {
            H[i] = 0;
            D[i] = 0;
            i++;
        }
        h_size = 0;
    }
    /* Extract max values and delete it all at once */
    EDGE extract_max()
    {
        EDGE temp;
        temp.edge_weight = D[1];
        temp.edge_num = H[1];
        delete_max();
        return temp;
    }
    
    /* Find the maximum item in the max-heap */
    int max_weight()
    {
        int w_max = D[1];
        return w_max;
    }
    
    /* Returns the node of maximum value from a max heap */
    int max_vertex()
    {
        int vertex_num = H[1];
        delete_max();
        return vertex_num;
    }
    
    /* Remove the root node of a max heap */
    void delete_max()
    {
        int size = h_size;
        H[1] = H[h_size];
        D[1] = D[h_size];
        
        h_size--;
        heapify(1);
    }
    
    /* Add a new node to the max-heap */
    void Insert(int _vertice, int _weight)
    {
        h_size++;
        
        H[h_size] = _vertice;
        D[h_size] = _weight;
        
        heapify(h_size);
    }
    
    /* Delete a node from the max-heap */
    void Delete(int _vertice)
    {
        int index = 0;
        
        for (int i = 1; i<= TOTAL_SIZE; i++)
        {
            if (H[i]==_vertice)
            {
                index = i;
                break;
            }
        }
        
        H[index] = H[h_size];
        D[index] = D[h_size];
        
        h_size--;
        
        heapify(1);
    }
    
    /* Rearrange the heap for violation of the heap roperty */
    void heapify(int bug)
    {
        /* Bug is the vertex's index in the heap structure, not the vertex number */
        /* When the bug is larger than its parent node : push up swap */
        if((bug>1)&&(D[bug]>D[bug/2]))
        {
            int temp = bug;
            
            /* Keeping swapping while the bug is still larger than its parent node */
            while ((temp>1)&&(D[temp]>D[temp/2]))
            {
                int h_temp = H[temp];
                int d_temp = D[temp];
                
                H[temp] = H[temp/2];
                D[temp] = D[temp/2];
                
                H[temp/2] = h_temp;
                D[temp/2] = d_temp;
                
                temp = temp/2;
            }
        }
        
        /* When the bug's child is larger than the bug : push down swap */
        else if ((bug<=(h_size/2))&&((D[bug]<D[bug*2])||(D[bug]<D[bug*2 + 1])))
        {
            int temp = bug;
            
            /* Keeping swapping while the bug's child is still larger than itself */
            while ((temp<=(h_size/2))&&((D[temp]<D[temp*2])||(D[temp]<D[temp*2 + 1])))
            {
                int child_for_swap = temp*2;
                int max_value = D[temp*2];
                
                if(max_value<D[temp*2 + 1])
                {
                    max_value = D[temp*2 + 1];
                    child_for_swap = temp*2 + 1;
                }
                
                int h_temp = H[temp];
                int d_temp = D[temp];
                
                H[temp] = H[child_for_swap];
                D[temp] = D[child_for_swap];
                
                H[child_for_swap] = h_temp;
                D[child_for_swap] = d_temp;
                
                temp = child_for_swap;
            }
        }
    }
    
    /* Update a given element's data in the heap structure */
    void update(int node, int data)
    {
        int j;
        //printf("Heap current size = %d, node to find = %d weight = %d\n", h_size, node, data);
        bool found = 0;
        for(int i=1; i<=h_size; i++)
        {
            if(H[i] == node)
            {
                D[i] = data;
                found = 1;
                heapify(i);
                break;
            }
        }
        if(!found)
        {
            printf("Element (%d, %d) not found\n", node, data);
            for(int j=0; j<h_size; j++)
            {
                printf("H[%d] = %d\n", j, H[j]);
            }
            display_heap();
            exit(0);
        }
    }
    
    /* Printout the heap datas */
    void display_heap()
    {
        int i;
        while(h_size!=0)
        {
            EDGE temp = heap::extract_max();
            i++;
            //int vertex, weight;
            //int v1, v2;
            
            //weight = temp.edge_weight;
            //vertex = temp.edge_num;
            
            //v1 = vertex/10000;
            //v2 = vertex%10000;
            printf("%d %d (%d)\n", i, temp.edge_num, temp.edge_weight);
            //heap::Insert(temp.edge_num, temp.edge_weight);
            //printf("edge = %d <-> %d, weight = %d\n", v1, v2, weight);
        }
    }
    /* Return the current heap size */
    int heap_size()
    {
        return h_size;
    }

};