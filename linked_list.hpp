/* Linked list data structure header for Dijkstra's max-bandwidth path */
/* Header file to declare functions for random generate graph1 */

#include <stdlib.h>
#include <stdio.h>

struct vertices{
    vertices *next; //pointed to the next vertex in the linked list
    vertices *prev;
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
        temp->prev = NULL;
        temp->v_num = vertex_num;
        temp->weight = _weight;
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            temp->prev = NULL;
            temp->next = NULL;
        }
        else
        {
            temp->next = NULL;
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        temp = NULL;
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
            printf("%d \t", temp->v_num); //print only connected vertex
            //printf("%d (%d)\t", temp->v_num, temp->weight); //also print edge's weight
            temp=temp->next;
        }
        printf("\n");
    }
    
    /* Function to display the linked list content */
    void display_with_weight()
    {
        vertices *temp=new vertices;
        temp=head;
        while(temp!=NULL)
        {
            //printf("%d \t", temp->v_num); //print only connected vertex
            printf("%d(%d)\t", temp->v_num, temp->weight); //also print edge's weight
            temp=temp->next;
        }
        printf("\n");
    }
    
    /* Delete the element by the given vertex number in the linked_list */
    void Delete(int vertex_num)
    {
        if(head==NULL) return;
        vertices *temp = new vertices;
        temp = head;
        while(temp->next!=NULL)
        {
            if(temp->v_num==vertex_num) break;
            else temp = temp->next;
        }
        if(temp == head) head = temp->next;
        if(temp->next!=NULL) temp->next->prev = temp->prev;
        if(temp->prev!=NULL) temp->prev->next = temp->next;
        
        delete temp;
    }
    
    vertices * list_head()
    {
        if (head==NULL) return NULL;
        else return head;
    }
    
    vertices * list_tail()
    {
        if (tail==NULL) return NULL;
        else return tail;
    }
};