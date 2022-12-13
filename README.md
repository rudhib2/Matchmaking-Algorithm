# CS225_Matchmaking

[Please click here to access our final project slides presentation](https://docs.google.com/presentation/d/1MET3rRTx6dNrxgwLzAL4kdkJG7kqdjsAbK_bp_XW2_M/edit?usp=sharing)

                                                                        **LOCATION **
**SRC Folder Files :**

      **csv.h + csv.cpp** -   csv.cpp contains functions to the take the data from the file and format it into 3 vectors - preference vector, attribute vector, and id vector. It also contains functions that calculate the preference and attribute scores which are used later on by the BFS and other algorithms. csv.h is the header file for csv.cpp. 
      
      **Graph.h + Graph.cpp** - Graph.cpp contains graph function such as adding an edge to a graph. It also contains the functions which perform the graph traversal - BFS, and the shortest path algorithm - Djikstra's and helper functions for these operations. Graph.h is the header file for Graph.cpp. 
      
      **BFS.h + BFS.h** -  BFS.cpp is the file used to create the adjacency matrix and call the respective functions to find the shortest path and do the traversal on the graph. BFS.h is the header file for BFS.cpp. 
      
      **Kosaraju.h + Kosaraju.cpp** - Kosaraju.cpp contains the Kosaraju's algorithm which is implemented by performing a DFS on an adjacency list and reverse adjacency list that's created by traversing through the dataset and also contains helper functions requred to perform the algorithm. Kosaraju.h is a header file to Kosaraju.cpp.
      
**Test Folder Files : **
 contains multiple files used to run and test all aspects of the project : 
- Data parsing and cleaning
- Kosaraju's Algorithm 
- BFS Algorithm 
- Dijkstra's Algorithm 
 
 
                                                                         **RUNNING**
 - to be able to run the tests, follow the steps : 
            - download the folder CS225_Matchmaking
            - then make a build directory using the command 'mkdir build'
            - move insdie the build directory using the command 'cd build'
            - run the command 'cmake' followed by 'make test'
            - now run './test/ to test all parts of the code 



