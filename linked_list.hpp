/*
    Doubly Linked list data structure to store graph's data
    The header file declares and describes class functions of doubly linked list
 
    File:   linked_list.hpp
    Author: Ho Lee
    Date  : 2017/11
*/

#include <stdlib.h>
#include <stdio.h>

struct vertices{
    vertices *next; //pointed to the next vertex in the linked list
    vertices *prev; //pointed to the previous vertex in the linked list
    int v_num;      //the vertex number
    int weight;     //the vertex's weight
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
        vertices *temp = head;
        while(temp!=NULL)
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
        vertices *temp= head;
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
        vertices *temp=head;
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
        vertices *temp = head;
        while(temp!=NULL)
        {
            if(temp->v_num==vertex_num) break;
            else temp = temp->next;
        }
        
        if(temp == head)
        {
            head = temp->next;
            temp->next->prev = NULL;
        }
        else if(temp == tail)
        {
            tail = temp->prev;
            temp->prev->next = NULL;
        }
        else //if(temp->next!=NULL && temp->prev!=NULL)
        {
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
        }
        //if(temp!=tail && temp->prev!=NULL) temp->prev->next = temp->next;
        //temp = NULL;
        //delete temp;
    }
    
    /* Update an element's data in the linked list by given information */
    void update(int vertex_num, int weight)
    {
        bool found = 0;
        vertices *temp = head;
        while(temp!=NULL)
        {
            if(temp->v_num==vertex_num)
            {
                temp->weight = weight;
                found = 1;
                break;
            }
            else temp = temp->next;
        }
        if (!found)
        {
            printf("Fringe not found.\n");
            exit(0);
        }
    }
    /* Return private linked list value "head" */
    vertices * list_head()
    {
        if (head==NULL) return NULL;
        else return head;
    }
    
    /* Return private linked list value "tail" */
    vertices * list_tail()
    {
        if (tail==NULL) return NULL;
        else return tail;
    }
};