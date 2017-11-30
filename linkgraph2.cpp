/*
    Singly Linked list data structure to generate a random graph
    Graph2 : each vertex is adjacent to 20% of other vertices (Degree = 500)
 
    File:   linkgraph2.cpp
    Author: Ho Lee
    Date  : 2017/11
*/
#include "linkgraph.hpp"

#define TOTAL_VERTICES 5000
list * linked_list[TOTAL_VERTICES];

int main()
{
    int random;
    int i, j, k, l;
    int edge_count=0;
    //struct vertices *vertex;
    
    //vertex = (struct vertices *)malloc(sizeof(struct vertices)*TOTAL_VERTICES);
    
    FILE *fp;
    fp = fopen("graph2.txt", "w");
    srand(time(NULL));              //start the random seed
    
    /* Initialize the linked list array and the whole graph connected first */
    for (i=0; i<TOTAL_VERTICES; i++)
    {
        if(i==0)
        {
            linked_list[i] = new list();
            linked_list[i]->newvertex(i+1);
            random = rand()%9999 +1;
            fprintf(fp, "%d %d %d\n", i, i+1, random);
            edge_count++;
        }
        else if(i<(TOTAL_VERTICES-1))
        {
            linked_list[i] = new list();
            linked_list[i]->newvertex(i+1);
            linked_list[i]->newvertex(i-1);
            random = rand()%9999 +1;
            fprintf(fp, "%d %d %d\n", i, i+1, random);
            edge_count++;
        }
        else
        {
            linked_list[i] = new list();
            linked_list[i]->newvertex(i-1);
            //random = rand()%9999 +1;
            //fprintf(fp, "%d %d %d\n", i, i+1, random);
            //edge_count++;
        }
    }
    printf("Connected edges uses %d.\n", edge_count);
    for(j=0; j<TOTAL_VERTICES; j++)
    {
        for(k=0; k<TOTAL_VERTICES; k++)
        {
            random = rand()%9999 +1;
            if(random<1055)
            {
                if((linked_list[j]->find_edge(k)==0)/*&&(linked_list[k]->find_edge(j)==0)*/&&(j!=k))
                {
                    linked_list[j]->newvertex(k);
                    linked_list[k]->newvertex(j);
                    random = rand()%9999 +1;
                    fprintf(fp, "%d %d %d\n", j, k, random);
                    edge_count++;
                }
            }
        }
    }
    
    /*for further file reading convenience */
    int zero = 0;
    fprintf(fp, "%d %d %d\n", zero, zero, zero);
    
    /* Print out edges (linked list) */
    /*
    for(l=0; l<TOTAL_VERTICES; l++)
    {
        printf("The %dth linked list :\n", l);
        linked_list[l]->display();
    }
    */
    printf("Total %d edges.\n", edge_count);
    //free(vertex);
    fclose(fp);
    return 0;
}