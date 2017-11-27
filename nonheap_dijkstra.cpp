/* The implementation of Dijsktra Algorithm without using heap structure for fringes */
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

#ifndef TOTAL_VERTICES
#define TOTAL_VERTICES 5000
#endif
#define INFINTE 10000

//using namespace std;
//-----------------------------------------------------
//----------**** DATA STRUCTURES ****------------------
//-----------------------------------------------------

list * edge_list[TOTAL_VERTICES+1];
//list * fringe = new list();
/*struct NODE{
    int node_num;
    int label;
};*/

int fringe[TOTAL_VERTICES];
int status[TOTAL_VERTICES]; // status : 1 = unseen / 2 = fringe / 3 = in-tree
int labels[TOTAL_VERTICES];
int parent[TOTAL_VERTICES];


//-----------------------------------------------------
//---------------**** FUNCTIONS ****-------------------
//-----------------------------------------------------

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

void initialize_graph(int _source)
{
    /* Initialize the graph vertices : label = 0, status = 1 (unseen) */
    for(int i=0; i<TOTAL_VERTICES; i++)
    {
        status[i] = 1;
        labels[i] = 0;
        parent[i] = 9999;
        fringe[i] = 0;
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
        
        fringe[currentv] = temp->weight;
        temp = temp->next;
    }
}
/* Transverse throught the linked list to find the max label fringe, then extract it */
int max_fringe()
{
    int max = 0;
    int max_node = 0;
    
    for (int i=0; i<TOTAL_VERTICES; i++)
    {
        if(fringe[i]!=0)
        {
            if(labels[i] > max)
            {
                max_node = i;
                max = labels[i];
            }
        }
    }
    fringe[max_node] = 0;
    return max_node;
}

void find_path(int _source, int _target)
{
    int source = _source;
    int target = _target;
    vertices *temp;

    /* Find until target node is in-tree */
    while(status[target]!=3)
    {
        /* Pick the fringe with largest label and mark it in-tree, then update it's neighbor */
        int u = max_fringe();
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
                fringe[cur_v] = min_bw_label;

                //if(labels[u] < temp->weight) labels[cur_v] = labels[u];
                //else labels[cur_v] = temp->weight;
                labels[cur_v] = min_bw_label;

                /* Update the parent array */
                parent[cur_v] = u;
            }
            
            /* If the neighbor is a fringe, update its label only */
            else if((status[cur_v] == 2)&&(labels[cur_v]< min_bw_label))
            {
                labels[cur_v] = min_bw_label;
                fringe[cur_v] = min_bw_label;
                /* Update the parent array */
                parent[cur_v] = u;
            }
            temp = temp->next;
        }

    }
}
//-----------------------------------------------------
//---------------**** MAIN FCT ****--------------------
//-----------------------------------------------------
int main(int argc, char *argv[])
{
    clock_t begin = clock();
    srand(time(NULL));
    int edge_count = 0;
    FILE *fp;
    fp = fopen(argv[1], "r");
    
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
                /* Make the edge name XX_YY, XX is the small vertex number while YY is larger */
                //if(v1<v2) edge = v1*100 + v2;
                //else edge = v2*100 + v1;
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
    //int source = rand()%4999;
    //int target = rand()%4999;
    int source = 228;
    int target = 3741;
    
    initialize_graph(source);
    
    //printf("The fringe list :\n");
    //fringe->display_with_weight();
    find_path(source,target);
    
    
    printf("The source = %d, target = %d\n", source, target);
    printf("The maximal bandwidth path's bandwidth = %d\n", labels[target]);
    fclose(fp);
    clock_t end = clock();
    double computing_time = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("Computing time = %f second\n\n", computing_time);
    return 0;
}
