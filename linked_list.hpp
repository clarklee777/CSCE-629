/* Linked list data structure header for Dijkstra's max-bandwidth path */
/* Header file to declare functions for random generate graph1 */

#include <stdlib.h>
#include <stdio.h>

struct vertices{
    vertices *next; //pointed to the next vertex in the linked list
    int v_num;      //the vertex number
    int weight;
};

class list{
private:
    vertices *head, *tail;
    
public:
    /* Initialize the list */
    list()
    {
        head = NULL;
        tail = NULL;
    }
    /* With new edges added to the vertex, we store the new adjacent vertex to the linked list */
    void newvertex(int vertex_num, int _weight)
    {
        vertices *temp = new vertices;
        temp->next = NULL;
        temp->v_num = vertex_num;
        temp->weight = _weight;
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    /* A return value to indicate whether the edge exists or not, no repeated edges between vertices allowed */
    /* If return a zero => no edge exist, otherwise => return the edge's weight */
    int find_edge(int vertex_num)
    {
        int edge_weight;
        vertices *temp = new vertices;
        temp = head;
        while(temp->next!=NULL)
        {
            if(temp->v_num==vertex_num)
            {
                edge_weight = temp->weight;
                return edge_weight;
            }
            else temp = temp->next;
        }
        return 0;
    }
    /* Function to display the linked list content */
    void display()
    {
        vertices *temp=new vertices;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d (%d)\t", temp->v_num, temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
    
};