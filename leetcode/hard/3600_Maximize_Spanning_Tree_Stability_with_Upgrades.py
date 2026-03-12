class Solution:
    class DSU:
        def __init__(self, n):
            # Every node is its own parent initially
            self.parent = list(range(n))
            # Keep track of the number of connected components
            self.components = n 

        def find(self, i):
            # Find the root of the component, with path compression
            if self.parent[i] == i:
                return i
            self.parent[i] = self.find(self.parent[i])
            return self.parent[i]

        def union(self, i, j):
            # Connect two nodes. Returns True if successfully connected, 
            # False if they were already connected (a cycle!)
            root_i = self.find(i)
            root_j = self.find(j)
            if root_i != root_j:
                self.parent[root_i] = root_j
                self.components -= 1
                return True
            return False

    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        dsu = self.DSU(n)
        edges.sort(key=lambda edge: (edge[3],edge[2]),reverse=1)
        stack = []
        normalEdgeSize = 0
        print(edges)
        for edge in edges:
            u = edge[0]
            v = edge[1]
            s = edge[2]
            if edge[3] == 1:
                if dsu.find(u) == dsu.find(v):
                    return -1
                dsu.union(u, v)
                stack.append(s)
            else:
                if dsu.find(u) != dsu.find(v):
                    dsu.union(u, v)
                    stack.append(s)
                    normalEdgeSize += 1
        if dsu.components > 1:
            return -1
        smallest_required = float('inf')
        smallest_optional = float('inf')
        
        if len(stack) != normalEdgeSize:
            smallest_required = stack[len(stack) - normalEdgeSize - 1]

        if normalEdgeSize > 0:
            if k < normalEdgeSize:
                smallest_unboosted = stack[-k - 1]
                smallest_boosted = stack[-1] * 2
                smallest_optional = min(smallest_unboosted, smallest_boosted)
            else:
                smallest_optional = stack[-1] * 2
        return min(smallest_required, smallest_optional)