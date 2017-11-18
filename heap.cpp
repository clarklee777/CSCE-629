#include "heap.hpp"

heap::heap()
{
    int i;
    while (i!=TOTAL_VERTICES)
    {
        H[i] = 0;
        D[i] = 0;
        i++;
    }
    h_size = 0;
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
    H[1] = H[size];
    D[1] = D[size];
    
    size = size - 1;
    change_size(size);
    
    heapify(1);
}

/* Add a new node to the max-heap */
void Insert(int _vertice, int _weight)
{
    int size = h_size;
    
    size = size + 1;
    
    H[size] = _vertice;
    D[size] = _weight;
    
    change_size(size);
    
    heapify(size);
}

/* Delete a node from the max-heap */
void Delete(int _vertice)
{
    int size = h_size;
    int index;
    
    for (int i = 1; i<= TOTAL_VERTICES; i++)
    {
        if (H[i]==_vertice)
        {
            index = i;
            break;
        }
    }
    
    H[i] = H[size];
    D[i] = D[size];
    
    size = size - 1;
    change_size(size);
    
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
    else if ((bug<=(h_size/2))&&((D[bug]>D[bug*2])||(D[bug]>D[bug*2 + 1])))
    {
        int temp = bug;
        
        /* Keeping swapping while the bug's child is still larger than itself */
        while ((temp<=(h_size/2))&&((D[temp]>D[temp*2])||(D[temp]>D[temp*2 + 1])))
        {
            int child_for_swap = temp*2;
            int min_value = D[temp*2];
            
            if(min_value>D[temp*2 + 1])
            {
                min_value = D[temp*2 + 1];
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

/* Change the private variable : size of the heap structure*/
void change_size(int _size)
{
    h_size = _size;
}

int main()
{
    printf("Not ready for testing yet.\n")
    return 0;
}
