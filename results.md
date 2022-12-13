<!-- The output and correctness of each algorithm – You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.

The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team. -->

The inital goal of the project was to build a matchmaking program that could perform 2 tasks: 
- find compatable matches for people in the form of a list, ranking the top ten most compatable ids for a given id from the data set
- find the compatability ratio between two specific people, when given the two ids from the dataset

In addition to these two tasks, the team added a few additional functionalities
- finding the category of "desirability" a person from the dataset falls under, based on their attribute score "ranking". The categories are "high", "average", and "low", each signifying how "desirable" other people would find them. This information is useful to an individual who wants to know how easy it will be for them to find a match.
- finding the category of "standards" a person from the dataset falls under based on their preference score "ranking" The categories are "high", "average", and "low", each signifying how high a person's "standards" are. This information is valuable to an individual who wants to know how easy it will be for them to find a match.

In order to meet these goals, we utilized BFS traversal, Djikstra's algorithm, and Kosaraju's algorithm. 

1. BFS was used to compute the compatability between two people. This was done by comparing an individual's preferences to other individual's attributes.
    - A graph is created for each person in the form of an adjacency matrix. Vertices are all people in the dataset.
    - For every person, we create a new graph, where the root node's (the person whose compatibility we need to check) value comes from our preferences vector and the value of all the other nodes comes from the attributes vector. The reasoning for doing this was simple, we want to keep in mind the preferences of the person for whom we are finding compatible people and compare it to other people's attributes.
    - The values of these nodes is an integer which represents what we call the "holistic score". This score is a part of each person's identity.
        - A person's holistic score is the sum of al their attribute (given by the ints in the corresponding coluns of the dataset) multiplied by 10
        - This only includes the columns corresponding to attractiveness, sincerity, funniness, intelligence, & ambition. These are all represented by an int between 0 and 10 which corresponds to a rating. 
        - There will be a 1d vector with each person's holistic score in addition to the other two vectors (preferences and attributes)
    - We have an additional function called PrelimCheck that the data needs to pass before going performing a BFS on it. 
        - In the PrelimCheck function, we are checking 4 variables: age, gender, relationship type ,and race preference
        - To pass this, the value of all of these 4 variables should be exactly the same for both the people we are comparing because unlike the other variables, the age variable can take any value and gender (takes value 0 or 1), rel_type (takes value 1-6), race (takes value 1-6) also take values that aren't necessarily between 1-10.
        - A big reason for adding the PrelimCheck function was to improve the efficiency of our code. Earlier, with just the threshold, there was a large number of people that were included in the graph and we had to perform a BFS on this huge graph. Furthermore, there would be a new graph for each person (where the root takes value from the prefrences vector i.e the enitire graph changes each time). We would have done this for all 544 people in our dataset. But after adding the PrelimCheck function, we automatically reduce the number of people each person is compatible with.
    - BFS is performed on the graph and the absolute values of scores are compared. If someone's score is within a range of 50 more or less compared to the preferred score, they pass else they fail
    - We perform BFS for all graphs where only one node changes, ie, the person whose compatibility we are checking with all other people. 

TESTS for BFS:
   
   - test 1: compatible pair
   - test 2: not compatible (PrelimCheck fails)
   - test 3: not compatible (PrelimCheck fails - but threshold passes: overall result should still be not compatible)
   - test 4: not compatible (same id is passed for both: expected result should be not compatile as the same person cannot be compatible to themselves)
    
 Testing was successful and the algorithm passes the written test cases! 
    
    
    
2. Djikstra's algorithm was used to find shortest paths between nodes in order to find who an individual is most compatable with. BFS tells weather people are compatible or not, but the degree of compatability is computed using this algorithm
    - There is a graph per person but now we'll make the graphs weighted using one of the attributes
    - Using the algorithm, we'll be able to find the shortest path from the source node to a particular vertex. 
    - The algorithm will return a the list of distances of each vertex from the source node
    - We now can perform a bubble sort and see which distances are the shortest and sort accordinly. 
    - Now we can return the top 3 people (3 people with the shortest distance) as the people the person is likely to be very compatible with. 
    - Additionally, just like we did in BFS, we added checks like the PrelimCheck so we can make our code faster and more efficient. 
    - **TALK ABOUT IMPLEMENTATION IN GREATER DETAIL**
    - **TESTING ~ EXPLAIN TEST CASES BRIEFLY & OUTCOMES**
    - **IF UNSUCCESSFUL ~ EXPLAIN INTENTIONS & REFLECTION**


3. Kosaraju’s algorithm was used to find the number of strongly connected components in our graph (represented by an adjacency matrix that is a 2D vector). We 'found' a strongly connected component by comparing Person A's preference score to every other person's attribute score and seeing if the preference score is greater than the other people's attribute score. For example, if Person A's preference score is greater than Person B's attribute score and vice versa, they become a strongly connected component (or if there is a path between multiple people), and therefore, we know that that pairing is incompatible. This test case is useful in seeing out of a group of people, how many groups of people will be incompatible with each other instead of compatible (which is what we are looking at for the other test cases). The higher the number of strongly connected components, the better because the max number of SCC's we can have is the max number of people. So if we have five people and the numComponents returned by the algorithm is 5, that means every person is a strongly connected to themselves and there are no incompatibiliities with other people. 
    - Implementation for attributes / desirability category ~
        1. There is 
            - Dfs
           
    - **TALK ABOUT IMPLEMENTATION IN GREATER DETAIL**
    - **TESTING ~ EXPLAIN TEST CASES BRIEFLY & OUTCOMES**
    - **IF UNSUCCESSFUL ~ EXPLAIN INTENTIONS & REFLECTION**

By implementing these algorithms, we learned that the initial scope of the project could be broadened. We realized half way through that our initial two goals could be accomplished with just BFS and Djikstras, so we ideated and came up with new functionalities for the project using Kosaraju's algorithm. Reflecting on what didn't work, we ended up not completely passing the Djikstra test case due to an out of bounds error. We believe the source of this came from trying to access a node in the graph that was past the size of the graph itself, and for further iterations we would go back through the addEdge function in Graph.cpp and the populate function in BFS.cpp because that is where out error was originating from based on gdb. 
