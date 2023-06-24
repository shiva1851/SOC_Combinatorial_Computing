    Greedy Algo v/s DP for solving problem:
Greedy algorithms often have a greedy choice property, meaning that a locally optimal choice leads to a globally optimal solution.
Greedy algorithms are prone to making shortsighted decisions, leading to suboptimal solutions.

Dynamic programming (DP) is a more systematic approach that breaks down a complex problem into smaller overlapping subproblems.
It solves each subproblem only once, and stores the results for future reference.
Example is solving Fibonacci sequence problem.

Network Flow:
Network flow is a mathematical abstraction used to model the movement of quantities.
It consists of a network of interconnected nodes and edges. 
Network Flow is characterised by 4 parameters: Source(s), Sink(t), flow and capacity.
It is a directed graph and capacity is the max possible flow through an edge.

The Ford-Fulkerson algorithm starts with an initial flow and repeatedly finds an augmenting path from the source to the sink.
It keeps on increasing the flow along that path until no more augmenting paths exist. 
The algorithm terminates when it reaches a maximum flow.

In our problem, we have already modelled that network flow can be used to solve Bipartite Matching Problem.
We have shown that we are required to find the max possible flow of the graph and this can be done using Ford Fulkerson Algorithm.
However, I couldnot figure out the solution :(
