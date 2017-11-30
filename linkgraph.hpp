/*
    Singly Linked list data structure to generate a random graph
    The header file declares and describes class functions of singly linked list
 
    File:   linked_list.hpp
    Author: Ho Lee
    Date  : 2017/11
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct vertices{
    vertices *next; //pointed to the next vertex in the linked list
    int v_num;      //the vertex number
    int weight;     //the vertex's weight
};

class list{
private:
    vertices *head, *tail;  //pointers pointed to the list's head and tail node
    
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