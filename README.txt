CSCE 629 : Course Project -- README.TXT

The following lists all the files created for this course project to find a maximum bandwidth path in 
random generated graphs with 5000 vertices.

COMPILATION:
=================

COMMAND:                  		 	DESCRIPTION:

g++ -o noheapdij nonheap_dijkstra.cpp		the command to generate the executable file for non-heap Dijkstra

g++ -o heapdij nheap_dijkstra.cpp		the command to generate the executable file for heap Dijkstra

g++ -o kruskal kruskal.cpp			the command to generate the executable file for kruskal

FILE:

noheapdij					the executable file for non-heap Dijkstra

heapdij						the executable file for heap Dijkstra

kruskal						the executable file for kruskal

MAIN PROGRAM FILES:
===================

FILE:                  	 DESCRIPTION:

linkgraph.hpp          	 Singly Linked list data structure to generate a random graph
    				 The header file declares and describes class functions of singly linked list

linkgraph1.cpp         	 Singly Linked list data structure to generate a random sparse graph:
				 Average vertex degree = 8, i.e. E = 4N

linkgraph2.cpp         	 Singly Linked list data structure to generate a random sparse graph:
				 every vertex is adjacent to approximate 20% of other vertices

linked_list.hpp			 Doubly Linked list data structure to store graph's data
				 The header file declares and describes class functions of doubly linked list

heap.hpp			 Utilizes a max-heap to store the graph's edges for max extraction
				 The header file declares and describes class functions of max-heap class

nonheap_dijkstra.cpp		 Implementation of Dijkstra's Algorithm to solve max-bandwidth path without using 				 heap structure to store fringes

heap_dijkstra.cpp		 Implementation of Dijkstra's Algorithm to solve max-bandwidth path with the use 				 of heap structure to store fringes

kruskal.cpp			 Implementation of Kruskal's Maximum Spanning Tree algorithm for max-bandwidth 				 path. Utilizes a max-heap to sort the original graph's edges for max extraction 				 and uses Depth First Search to find the source to target path in the Maximum 				 Spanning Tree.

			 

FILES:
==========

FILE: 				 DESCRIPTION:

“result_with_path” directory	 Contains all result files to Table.1 and Table.2 in the report document.

graph.txt			 A sample graph file to represent the random generated graph (last line = 0 0 0 				 easier to read)

HoLee_finalproject_CSCE629.pdf The final report file which discusses all further implementation details.


Since other generated input graph files for discussion are very large, therefore only the result files are presented :

1Me_vdif.txt			 The result files of fixing total edge number = 1 million and test all three 				 approach with total vertex number = 2000, 4000, 6000, 8000, and 10,000. Which 				 create Table.4 in the report.

compare.txt			 The result files of fixing total vertex number = 5000 and test all three approach 				 with total edge number from 0.5million to 5 million with 0.5million as on step. 				 Which create Table.3 in the report.

vertices_dif.txt		 The result file to create Table.5 in the report.