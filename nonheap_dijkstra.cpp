/* The implementation of Dijsktra Algorithm without using heap structure for fringes */
//---------------------------------------------------
//            **** INCLUDES ****
//---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.hpp"
//----------------------------------------------------
//            **** DEFINES ****
//----------------------------------------------------

#ifndef TOTAL_VERTICES
#define TOTAL_VERTICES 5000
#endif
#define INFINTE 99999999

//-----------------------------------------------------
//          **** DATA STRUCTURES ****
//-----------------------------------------------------

list * edge_list[TOTAL_VERTICES];

/* Vertex struct for the graph */
struct vertex{
    int vnum;
    int label;
    int color; // color : 1 = white / 2 = grey / 3 = black
};

vertex V[TOTAL_VERTICES];

//-----------------------------------------------------
//-----------------------------------------------------

void print_linked_list(int _edge_count)
{
    for(int l=0; l<TOTAL_VERTICES; l++)
    {
        printf("The %dth linked list :\n", l);
        edge_list[l]->display();
    }
    printf("Total %d edges.\n", _edge_count);
}

void initialize_graph()
{
    /* Initialize the graph vertices : label = infinite, color = 1 (white) */
    for(int i=1; i<=TOTAL_VERTICES; i++)
    {
        V[i].vnum = i;
        V[i].label = INFINTE;
        V[i].color = 1;
    }
    
}
int main(int argc, char *argv[])
{
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
    print_linked_list(edge_count);
    
    
    fclose(fp);
    return 0;
}