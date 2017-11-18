#===== Heap =====
heap.o: heap.cpp heap.hpp
	g++ -c -o heap.cpp heap.hpp

#===== Main =====
h_dijkstra.o: h_dijkstra.cpp h_dijkstra.hpp heap.cpp heap.hpp
	g++ -c -o h_dijkstra.o h_dijkstra.cpp

h_dijkstra: heap.o h_dijkstra.o
	ld -o h_dijkstra heap.o h_dijsktra.o
