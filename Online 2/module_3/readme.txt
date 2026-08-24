Algorithms for single source shortest paths : 
    1. BFS -> Unweighted / same weight 
    2. Dijkstra -> If edges have different costs (like distances or weights) and  they are all positive
    3. Bellman-Ford -> If there are negative edges

*Time Complexity for Dijkstra in worst case scenario is 2*BFS since we have to  visit every node just twice (if we didn't use priority queue then we had to visit many times more). So the time complexity becomes O(V+E) since O(2n)=O(n). But we are using priority_queue instead of queue. 
So the final complexity becomes O((V+E)logV) 

Input :
5 8 0
0 1 10
1 2 1
0 2 7
0 3 4
2 3 1
3 4 5
1 4 3
2 4 5

Output : 
0 -> 0
1 -> 10
2 -> 7
3 -> 4
4 -> 9