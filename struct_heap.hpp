// Create by : Ho Lee
// Date      : 2017/11/25

/* The header file for declaration of max-heap class */
// Heap functions are :
// heap(), max_weight(), max_vertex, delete_max(), Insert(vertex, weight)
// Delete(vertex), heapify(vertex_bug), heap_size(), change_size(heap_size)
#include <stdlib.h>
#include <stdio.h>

#define TOTAL_VERTICES 10000000

struct EDGE{
    int v1, v2;
    int weight;
};

class heap{
    
private:
    //int H[TOTAL_VERTICES]; //heap array
    //int D[TOTAL_VERTICES]; //data array
    EDGE heap_array[TOTAL_VERTICES];
    int h_size;            // Returns number of elements in the heap
    /*void change_size(int _size)  // Change the private variable : size of the heap structure
    {
        h_size = _size;
    }*/
    
public:
    /* Class initializer */
    heap()
    {
        int i = 0;
        while (i!=TOTAL_VERTICES)
        {
            heap_array[i].v1 = 0;
            heap_array[i].v2 = 0;
            heap_array[i].weight = 0;
            i++;
        }
        h_size = 0;
    }
    
    /* Find the maximum item in the max-heap
    int max_weight()
    {
        int w_max = D[1];
        return w_max;
    }*/
    
    /* Returns the node of maximum value from a max heap
    int max_vertex()
    {
        int vertex_num = H[1];
        delete_max();
        return vertex_num;
    }
    */
    /* Return the max element and delete it from the heap */
    EDGE extract_max()
    {
        EDGE max_vertex = heap_array[1];
        //max_vertex = heap_array[1];
        delete_max();
        return max_vertex;
    }
    /* Remove the root node of a max heap */
    void delete_max()
    {
        //int size = h_size;
        //H[1] = H[size];
        //D[1] = D[size];
        
        heap_array[1] = heap_array[h_size];
        
        //size = size - 1;
        //change_size(size);
        h_size--;
        heapify(1);
    }
    
    /* Add a new node to the max-heap */
    void Insert(struct EDGE edge/*int _vertice, int _weight*/)
    {
        //int size = h_size;
        //size = size + 1;
        
        h_size++;
        
        //H[size] = _vertice;
        //D[size] = _weight;
        
        heap_array[h_size] = edge;
        
        //change_size(size);
        
        heapify(h_size);
    }
    
    /* Delete a node from the max-heap
    void Delete(int _vertice)
    {
        int size = h_size;
        int index = 0;
        
        for (int i = 1; i<= TOTAL_VERTICES; i++)
        {
            if (H[i]==_vertice)
            {
                index = i;
                break;
            }
        }
        
        H[index] = H[size];
        D[index] = D[size];
        
        size = size - 1;
        change_size(size);
        
        heapify(1);
        
    }
    */
    /* Rearrange the heap for violation of the heap roperty */
    void heapify(int bug)
    {
        /* Bug is the vertex's index in the heap structure, not the vertex number */
        /* When the bug is larger than its parent node : push up swap */
        if((bug>1)&&(heap_array[bug].weight>heap_array[bug/2].weight))
        {
            int temp = bug;
            
            /* Keeping swapping while the bug is still larger than its parent node */
            while ((temp>1)&&(heap_array[temp].weight>heap_array[temp/2].weight))
            {
                //int h_temp = H[temp];
                //int d_temp = D[temp];
                EDGE temp = 
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
    
    /* Return the current heap size */
    int heap_size()
    {
        return h_size;
    }

};