__s-t connectivity__: (s-t联通问题) 给定两个节点s,t，是否有一条s-t之间的路径？

__s-t shortest path problem__:（s-t最短路径)给定两个节点s-t，他们之间的最短路径是多少？

**BFS algorithm.** （分层）
- L0 = { s }.
- L1 = all neighbors of L0.
- L2 = all nodes that do not belong to L0 or L1, and that have an edge to a node in L1.
- Li+1 = all nodes that do not belong to an earlier layer, and that have an edge to a node in Li.


**定理：** For each i, Li consists of all nodes at distance exactly i from s.  There is a path from s to t iff t appears in some layer.

性质：Let T be a BFS tree of G = (V, E), and let (x, y) be an edge of G. Then the level of x and y differ by at most 1.