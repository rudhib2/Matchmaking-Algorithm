We are planning on building a matchmaking project which acheives 2 things : 
- finding compatabile matches for people
- find the compatabilty ratio between two specific people 

## Leading Question 
From the dataset, we aim to obtains features that would test the compatability between two people: such as age, gender, height, nationonality etc
The problem we are trying to solve is see whether two people are compatabile with one another

We are hoping to have a graph which would contain the profile of multiple different people, and we will use a traversal technique to find whether a person is compatabile with someone else, and by what ratio

## Dataset Acquisition

## Data Format

The dataset that we are using, in its raw self, contains the survey results of about 8500 respondents on their dating preferences. It contains each respondent’s data such as their age, race, hometown, career etc. It also contains a score on their preferences on features they are looking for in a partner like attractiveness, fun, ambitious, etc. 
We got this dataset from https://perso.telecom-paristech.fr/eagan/class/igr204/datasets. It is in a csv (comma separated values) format. It contains the data of 8379 people and their preferences on 195 parameters. We feel like managing a dataset, a size this big could cause problems later as we could run in timeout errors, we plan on using a subset of 2500 people and 14 parameters.

## Data Correction
We plan to go through the input file, and we will make sure that the data entered is useful and that there are no missing enteries to ensure data is complete and accurate
Any data that is not complete or not accurate, will not be included since we are planning to shorten the raw dataset making it clear and concise. 

## Data Storage
We plan to use multi-dimensional vectors to store our data. As of now, we do not need to use preprocessed tables etc


## Algorithm
* We plan on using Dijkstra’s algorithm for the first use case — looking at one person and comparing them to all others on the dataset to assess compatibility and produce a list of matches with compatibility scores
* We plan on using a BFS algorithm for the second use case — for someone to know compatibility score given a person in the dataset. The BFS will first identify the person in the dataset and provide the total path value between the two people

## Expected Outputs
* In the first case (list of matches) — returns a list of the serial number of the person and the compatibility ratio. The list will include top 10 matches and be ranked by highest to lowest compatibility score. The value for the compatibility store will be stored and printed as an unsigned int and will be converted to a percentage before being displayed.
* In the second case — returns the shortest path / path value between the two individuals given as input. This path value represents the compatibility score between the two people. This value will be stored and printed as an unsigned int and will be converted to a percentage before being displayed.

## Function Efficiency
* In the first case (list of matches) — the worst case time complexity for the implementation of the Dijkstra’s algorithm is O(V^2)
    * V represents the vertex  — in this case we would do V number of calculations and each operation takes O(V) times, therefore leaving us with the complexity of O(V^2)
* In the second case — the worst case BFS scenario, we would need to consider all paths to all possible nodes (people in the dataset). Therefore the time complexity would be O(|E| + |V|) where |V| and |E| is the cardinality of set of vertices and edges respectively.

## Timeline

Week 1: finishing data acquisition and processing and defining header file
Week 2 & 3: working on graph algorithms and traversals
Week 4: debugging and testing
