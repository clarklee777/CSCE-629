/*
    Kruskal's Maximal Spanning Tree algorithm for max-bandwifth path.
    Utilizes a max-heap to sort the original graph's edges for max extraction
 
    File:   kruskal.cpp
    Author: Ho Lee
    Date  : 2017/11
*/
//---------------------------------------------------
//            **** INCLUDES ****
//---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.hpp"
#include "heap.hpp"

/* Heap functions are :                             */
/* heap(), extract_max(), update(), Insert(v, w)    */
/* Delete(vertex), heapify(vertex_bug), heap_size() */

//----------------------------------------------------
//--------------**** DEFINES ****---------------------
//----------------------------------------------------

#define TOTAL_VERTICES 5000
#define INFINTE 10000

//-----------------------------------------------------
//----------**** DATA STRUCTURES ****------------------
//-----------------------------------------------------

list * edge_list[TOTAL_VERTICES+1]; // Whole graph's edges are stored here index by each vertex number
heap * sort_edge = new heap();      // The sorted edge in increasing fasion for Kruskal's MxST

int parent[TOTAL_VERTICES]; // array to track whether new adding edges makes a cycle in MxST
int rank[TOTAL_VERTICES];   // array to keep track of the cycle deciding trees' depths
int path[TOTAL_VERTICES];   // array for print out the final max-bandwidth path
int status[TOTAL_VERTICES]; // status for DFS : 0 = unvisited(white), 1 = visisted(grey),
                            //                  2 = finish visiting all childrens (black)
int edge_count = 0;         // total edge counts in MxST, should be exact 4999
int max_bandwidth = 10000;  // Final max-bandwidth path's bandwidth comparator for finding path

int source = 2518;
int target = 4705;
bool path_found = 0;
//-----------------------------------------------------
//---------------**** FUNCTIONS ****-------------------
//-----------------------------------------------------
/* Find the root of the given edge's two vertices, tree is for finding cycle not MxST */
int find_root(int vertex)
{
    int v = vertex;
    edge_list[TOTAL_VERTICES] = new list(); //uses the unused linked list, since vertex from 0 to 4999
    while (parent[v]!=(-1))
    {
        edge_list[TOTAL_VERTICES]->newvertex(v,1);
        v = parent[v];
    }
    
    /* For path compression, once transverse through a node, its parent */
    /* will point directly to the root node to speed up future find.    */
    vertices *temp = edge_list[TOTAL_VERTICES]->list_head();
    while (temp!=NULL)
    {
        parent[temp->v_num] = v;
        temp = temp->next;
    }
    delete edge_list[TOTAL_VERTICES];
    
    return v;
}
/* When new edge won't make a cycle, mark its two vertices in same tree */
/* tree is for finding cycle not MxST                                   */
void merge_root(int _r1, int _r2)
{
    int r1 = _r1;
    int r2 = _r2;
    
    if(rank[r1]<rank[r2]) parent[r1] = r2;
    else if(rank[r1]>rank[r2]) parent[r2] = r1;
    else //rank[r1]==rank[r2]
    {
        parent[r1] = r2;
        rank[r2]++;
    }
}

/* Detect whether the given edge's two vertices would make a cycle in MxST */
bool cycle_detect(int _v1, int _v2)
{
    int v1 = _v1;
    int v2 = _v2;
    int r1 = find_root(v1);
    int r2 = find_root(v2);
    
    /* the edge's two vertices have same root vertex : this make a cycle */
    if(r1==r2) return true;
    
    /* Doesn't make a cycle, then merge this two vertices as same root now */
    else
    {
        merge_root(r1,r2);
        return false;
    }
}
/* Create the Maximal Spanning Tree by using Kruskals' algorithm */
void create_maxspan_tree()
{
    /* MakeSet() : Initialize the information arrays for deciding cycle existance */
    for(int i=0; i<TOTAL_VERTICES; i++)
    {
        parent[i] = (-1);
        rank[i] = 0;
        path[i] = 5001;
        status[i] = 0;
    }
    /* Scan through all edges to decide whether to add the the MxST */
    while(sort_edge->heap_size()!=0)
    {
        int v1, v2, w;
        EDGE new_edge = sort_edge->extract_max();
        w = new_edge.edge_weight;
        v1 = new_edge.edge_num/10000;
        v2 = new_edge.edge_num%10000;
        
        /* If the edge won't make a cycle, add it to the current MxST */
        if(!cycle_detect(v1,v2))
        {
            if(edge_list[v1] == NULL) edge_list[v1] = new list();
            if(edge_list[v2] == NULL) edge_list[v2] = new list();
            edge_list[v1]->newvertex(v2,w);
            edge_list[v2]->newvertex(v1,w);
            edge_count++;
            /* Since it's a tree, there should only be : # of edges = total # of vertices -1 */
            /* No need to extract all edges (20k~2.5M) in the heap, only TOTAL_VERTICES (5k) */
            if(edge_count==TOTAL_VERTICES-1) break;
        }
    }
}
/* Depth First Search subroutine */
void depth_first_search(int v, int parent)
{
    status[v] = 1; // color = grey (visited)
    path[v] = parent;
    vertices *temp = edge_list[v]->list_head();
    if(status[target] == 1)
    {
        path_found = 1;
        return;
    }
    while(temp!=NULL)
    {
        /* if the node's color is white (unvisited), then DFS it */
        if(status[temp->v_num]==0) depth_first_search(temp->v_num, v);
        temp = temp->next;
    }
    status[v] = 2; // color = black (done visit all its child nodes)
    //edge_list[v] = NULL;
    //edge_list[parent]->Delete(v);
}

/* Find the path between source and target in the MxST by using Depth First Search */
void find_path()
{
    vertices *temp = edge_list[source]->list_head();
    while(temp!=NULL)
    {
        if(status[temp->v_num]==0) depth_first_search(temp->v_num, source);
        if(path_found) break;
        temp = temp->next;
    }
}
/* Print out the found max-bandwidth path */
void print_path()
{
    //printf("Printing path...\n");
    bool arrive_source = 0;
    int v = target;
    list * maxpath = new list();
    while (!arrive_source)
    {
        int w = edge_list[v]->find_edge(path[v]);
        if(w < max_bandwidth) max_bandwidth = w;
        maxpath->newvertex(path[v],1);
        v = path[v];
        if(v == source) arrive_source = 1;
    }
    vertices *temp = maxpath->list_tail();
    printf("Max bandwidth path = \n");
    int i = 1;
    while(temp!=NULL)
    {
        //printf("Record finish, printing out...\n");
        if(i%10!=0) printf("%d \t", temp->v_num);
        else printf("%d \n", temp->v_num);
        temp = temp->prev;
        i++;
    }
    printf("%d\n", target);
}

//-----------------------------------------------------
//---------------**** MAIN FCT ****--------------------
//-----------------------------------------------------
int main(int argc, char *argv[])
{
    clock_t begin = clock();
    int graph_edge_count = 0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    /* Graph file reading */
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
        while(flag ==0)
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
                /* Make the edge name XX_YY, XX is the small vertex number while YY is larger */
                if(v1<v2) edge = v1*10000 + v2;
                else edge = v2*10000 + v1;
                sort_edge->Insert(edge, w);
                graph_edge_count++;
            }
        }
    }
    //printf("Ready to create MxST\n");
    create_maxspan_tree();
    find_path();
    
    
    printf("Graph's Total Edge = %d\n", graph_edge_count);
    printf("Kruskal's MxST Total Edge = %d\n", edge_count);
    printf("The source = %d, target = %d\n", source, target);
    print_path();
    printf("The maximal bandwidth path's bandwidth = %d\n", max_bandwidth);
    fclose(fp);
    clock_t end = clock();
    double computing_time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Computing time = %f second\n\n", computing_time);
    return 0;
}