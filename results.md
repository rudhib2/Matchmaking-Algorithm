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
    - The values of these nodes is an integer which represents what we call the "holistic score". This score is a part of each person's identity.
        - A person's holistic score is the sum of al their attribute (given by the ints in the corresponding coluns of the dataset) multiplied by 10
        - This only includes the columns corresponding to attractiveness, sincerity, funniness, intelligence, & ambition. These are all represented by an int between 0 and 10 which corresponds to a rating. 
        - There will be a 1d vector with each person's holistic score in addition to the other two vectors (preferences and attributes)
        - preferenes are the weight in the graph.
        - BFS is performed on the graph and the absolute values of scores are compared. If someone's score is greater than the preferred score, they pass
        - We perform BFS for all grapohs where only one node changes, ie, the person whose compatibility we are checking with all other people. The node of this person is what comes from the preferences vector. All other notes come from the attributes vector.
    - **TALK ABOUT IMPLEMENTATION IN GREATER DETAIL**
    - **TESTING ~ EXPLAIN TEST CASES BRIEFLY & OUTCOMES**
    - **IF UNSUCCESSFUL ~ EXPLAIN INTENTIONS & REFLECTION**
2. Djikstra's algorithm was used to find shortest paths between nodes in order to find who an individual is most compatable with. BFS tells weather people are compatible or not, but the degree of compatability is computed using this algorithm
    - There is a graph per person but now we'll make the graphs weighted using attributes
    - Using the algorithm, we'll find the shortest path between people and return in order from shortest to longest path the path that is shortest
    - The path that is shortest will reach the most compatible person and the longest will reach the least compatable among the people that are compatable.
    - **TALK ABOUT IMPLEMENTATION IN GREATER DETAIL**
    - **TESTING ~ EXPLAIN TEST CASES BRIEFLY & OUTCOMES**
    - **IF UNSUCCESSFUL ~ EXPLAIN INTENTIONS & REFLECTION**
3. Kosaraju’s algorithm **NEEDS TO BE MODIFIED AS PER RECENT CHANGES AFTER CALL W SAVYA** was used to place everyone in a category of desirability (based on an individual attributes, which category) ~ lower desirability, average desirability, high desirability [we can rename these], as well as a category of standards (based on an individual’s preferences) ~ lower standards, average standards, high standards.
    - Implementation for attributes / desirability category ~
        - For each person in the dataset, there is one big graph represented as an adjacency matrix with x and y axis being the id vector (all people in the dataset’s ids)
        - Compare every person’s attribute score – use pre-written function to calculate
        - If root person’s score is greater, set the value to 1 (this person is more desirable than the person we just visited)
        - Perform kosaraju’s algorithm 
            - Dfs
            - Make an empty stack and push
            - Bool visited – vector of visited components
            - Need to transpose graph for second dfs
            - First config for dfs 1, second for dfs 2
        - We have a count variable which we increment when ever we have 1 / visited
        - Basically we want to know how many people in the set are you “more desirable” than
        - We will then push this count back into a different vector such that the index of this vector corresponds to the indexes of the ids vector (in fact this could be a 2d vector id,score or maybe even a map ~ data structure will be discussed later)
        - Then we sort by ascending order – the first 181 people are low category, the next 182 people are average category, the last 181 people are high category
    - Implementation for preferences / standards category ~
        - It is the same as described above, but instead of attribute ranks, we'll use preference ranks
    - **TALK ABOUT IMPLEMENTATION IN GREATER DETAIL**
    - **TESTING ~ EXPLAIN TEST CASES BRIEFLY & OUTCOMES**
    - **IF UNSUCCESSFUL ~ EXPLAIN INTENTIONS & REFLECTION**

By implementing these algorithms, we learned that the initial scope of the project could be broadened. We realized half way through that our initial two goals could be accomplished with just BFS and Djikstras, so we ideated and came up with new functionalities for the project using Kosaraju's algorithm. Reflecting on what didn't work **NEED TO FINISH WRITING BASED ON HOW TESTING GOES ~ IF SOMETHING DOESN'T FULLY FUNCTION PROPERLY, EXPLAIN HERE**