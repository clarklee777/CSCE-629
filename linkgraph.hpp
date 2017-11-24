/* Header file to declare functions for random generate graph1 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
    void newvertex(int vertex_num)
    {
        vertices *temp = new vertices;
        temp->next = NULL;
        temp->v_num = vertex_num;
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
    /* A flag to indicate whether the edge exists or not, no repeated edges between vertices allowed */
    bool find_edge(int vertex_num)
    {
        vertices *temp = new vertices;
        temp = head;
        while(temp->next!=NULL)
        {
            if(temp->v_num==vertex_num) return true;
            else temp = temp->next;
        }
        return false;
    }
    /* Function to display the linked list content */
    void display()
    {
        vertices *temp=new vertices;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t", temp->v_num);
            temp=temp->next;
        }
        printf("\n");
    }
    
};