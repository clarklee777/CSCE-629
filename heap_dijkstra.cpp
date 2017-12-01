/*
    Dijkstra's Algorithm using heap structure to store fringe queue to solve max-bandwidth path
    The implementation of Dijsktra Algorithm without using heap structure for fringes
 
    File:   heap_dijkstra.cpp
    Author: Ho Lee
    Date  : 2017/11
 */
//---------------------------------------------------
//            **** INCLUDES ****
//---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "linked_list.hpp"

//----------------------------------------------------
//--------------**** DEFINES ****---------------------
//----------------------------------------------------

#define TOTAL_VERTICES 5000
#define INFINTE 10000
#define TOTAL_SIZE 5000
#include "heap.hpp"

//-----------------------------------------------------
//----------**** DATA STRUCTURES ****------------------
//-----------------------------------------------------

list * edge_list[TOTAL_VERTICES+1]; // Whole graph's edges are stored here index by each vertex number
heap * fringe = new heap();         // The heap to store fringes for faster extract max

int status[TOTAL_VERTICES]; // status : 1 = unseen / 2 = fringe / 3 = in-tree
int labels[TOTAL_VERTICES]; // each verteices's label of current max_bandwidth from source to the vertex
int parent[TOTAL_VERTICES]; // array to keep track of the parent-child relations along the path

//-----------------------------------------------------
//---------------**** FUNCTIONS ****-------------------
//-----------------------------------------------------
/* Function to print all linked list represent each node's adjacency nodes */
void print_linked_list(int _edge_count)
{
    for(int l=0; l<TOTAL_VERTICES; l++)
    {
        if (edge_list[l]!=NULL)
        {
            printf("The %dth linked list :\n", l);
            edge_list[l]->display();
        }
    }
    printf("Total %d edges.\n", _edge_count);
}

/* Initialize the critical contents needed */
void initialize_graph(int _source)
{
    /* Initialize the graph vertices : label = infinite, status = 1 (unseen) */
    for(int i=0; i<TOTAL_VERTICES; i++)
    {
        status[i] = 1;
        labels[i] = 0;
        parent[i] = 9999;
    }
    /* Initialize the source vertex : label = 0, status = 3 (in-tree) */
    labels[_source] = 0;
    status[_source] = 3;
    
    /* Create a fringe list by first examine source node's neighbor nodes */
    vertices *temp;
    temp = edge_list[_source]->list_head();
    while(temp!=NULL)
    {
        int currentv= temp->v_num;
        status[currentv] = 2;
        labels[currentv] = temp->weight;
        parent[currentv] = _source;
        
        fringe->Insert(currentv,temp->weight);
        temp = temp->next;
    }
}

/* The Dijkstra's Algorithm main frame, uses max-heap to store fringes for faster extract max */
void find_path(int _source, int _target)
{
    int source = _source;
    int target = _target;
    vertices *temp;
    
    /* Find until target node is in-tree */
    while(status[target]!=3)
    {
        /* Pick the fringe with largest label and mark it in-tree, then update its neighbor's status */
        int u;
        EDGE max_fringe = fringe->extract_max();
        u = max_fringe.edge_num;
        status[u] = 3;
        temp = edge_list[u]->list_head();
        while(temp!=NULL)
        {
            int cur_v = temp->v_num;
            int min_bw_label;
            
            /* for each edge [u,w]  Min{bandwidth_label[u], edge_weight[u,w]} */
            /* The smaller value between current nodes's label or this edge's weight */
            if(labels[u] < temp->weight) min_bw_label = labels[u];
            else min_bw_label = temp->weight;
            
            /* If the neighbor is unseen, update to fringe and its label */
            if(status[cur_v] == 1)
            {
                /* Update to fringe, and add to fringe list */
                status[cur_v] = 2;
                fringe->Insert(cur_v, min_bw_label);
                
                labels[cur_v] = min_bw_label;
                
                /* Update the parent array */
                parent[cur_v] = u;
            }
            
            /* If the neighbor is a fringe, update to its label only */
            else if((status[cur_v] == 2)&&(labels[cur_v]< min_bw_label))
            {
                //printf("Update orirgnal (node,label) = (%d, %d)\n", cur_v, labels[cur_v]);
                fringe->update(cur_v,min_bw_label);
                labels[cur_v] = min_bw_label;
                /* Update the parent array */
                parent[cur_v] = u;
            }
            temp = temp->next;
        }
    }
}
/* Print out the found max-bandwidth path */
void printf_path(int _source, int _target)
{
    int temp = _target;
    list * print = new list();
    printf("Max Bandwidth Path = \n");
    while(temp!=_source)
    {
        temp = parent[temp];
        print->newvertex(temp,1);
    }
    int i = 1;
    vertices *max_path = print->list_tail();
    while(max_path!=NULL)
    {
        if(i%10!=0) printf("%d \t", max_path->v_num);
        else printf("%d \n", max_path->v_num);
        max_path = max_path->prev;
        i++;
    }
    printf("%d\n", _target);
}
//-----------------------------------------------------
//---------------**** MAIN FCT ****--------------------
//-----------------------------------------------------
int main(int argc, char *argv[])
{
    clock_t begin = clock();
    int edge_count = 0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    /* File reading part */
    if(!fp)
    {
        if(argv[2]) printf("Error 01 : file: %s not found\n",argv[2]);
        printf("Error 02 : file open failed.\n");
        printf("file: %s not found\n",argv[1]);
        printf("proper usage: ./program_name input_filename\nPlease try again...\n\n");
        exit(0);
    }
    else
    {
        printf("Finding graph file: %s \n",argv[1]);
        int flag = 0;
        while(flag == 0)
        {
            int v1, v2, w, edge;
            fscanf(fp,"%d %d %d", &v1, &v2, &w);
            if ((v1== 0)&&(v2==0)&&(w==0))
            {
                flag = 1;
                break;
            }
            else
            {
                if(edge_list[v1] == NULL) edge_list[v1] = new list();
                if(edge_list[v2] == NULL) edge_list[v2] = new list();
                edge_list[v1]->newvertex(v2,w);
                edge_list[v2]->newvertex(v1,w);
                edge_count++;
            }
        }
    }
    //print_linked_list(edge_count);
    
    /* Initialize the graph */

    int source = 2518;
    int target = 4705;
    
    initialize_graph(source);
    
    find_path(source,target);
    
    printf("Graph's Total Edge = %d\n", edge_count);
    printf("The source = %d, target = %d\n", source, target);
    printf_path(source,target);
    printf("The maximal bandwidth path's bandwidth = %d\n", labels[target]);
    fclose(fp);
    clock_t end = clock();
    double computing_time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Computing time = %f second\n\n", computing_time);
    return 0;
}
