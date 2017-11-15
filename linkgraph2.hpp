/* Header file to declare functions for random generate graph */

#include <stdlib.h>
#include <stdio.h>
//#include <iostream>
#include <time.h>
//#include <string.h>
//#include <new>
//using namespace std;

struct vertices{
    struct vertices *next;
    //vertices *prev;
    int v_num;
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
    void insert(struct vertices *vertex)
    {
        struct vertices *temp = vertex;
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