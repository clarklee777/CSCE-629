/* The header file for declaration of max-heap class */
#include <stdlib.h>
#include <stdio.h>

#define TOTAL_VERTICES 100

/*struct edge{
    int u, v;
    int weight;

};*/

class heap{
    
private:
    int H[TOTAL_VERTICES]; //heap array
    int D[TOTAL_VERTICES]; //data array
    int h_size;            // Returns number of elements in the heap
    void change_size(int _size); // Change the private variable : size of the heap structure
    
public:
    /* Initialize the heap structure */
    heap();
    
    /* Find the maximum item in the max-heap */
    int max_weight();
    
    /* Returns the node of maximum value from a max heap */
    int max_vertex();
    
    /* Remove the root node of a max heap */
    void delete_max();
    
    /* Add a new node to the max-heap */
    void Insert(int _vertice, int _weight);
    
    /* Delete a node from the max-heap */
    void Delete(int _vertice);
    
    /* Rearrange the heap for violation of the heap roperty */
    void heapify(int bug);
    
    /* Return the current heap size */
    int heap_size();
    
};