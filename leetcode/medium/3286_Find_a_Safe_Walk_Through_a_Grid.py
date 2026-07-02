class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        INT_MAX = 3000
        rows = len(grid)
        cols = len(grid[0])
        dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        distances = [[INT_MAX for _ in range(cols)] for _ in range(rows)]
        start_r, start_c = 0,0
        priority_queue = [(grid[start_r][start_c], start_r, start_c)]
        while priority_queue:
            current_dist, r, c = heapq.heappop(priority_queue)
            if current_dist > distances[r][c]:
                continue
            for dr, dc in dirs:
                next_r, next_c = r + dr, c + dc
                if 0 <= next_r < rows and 0 <= next_c < cols:
                    new_dist = current_dist + grid[next_r][next_c]
                    
                    if new_dist < distances[next_r][next_c]:
                        distances[next_r][next_c] = new_dist
                        heapq.heappush(priority_queue, (new_dist, next_r, next_c))
        health_cost = distances[rows-1][cols-1]
        if health - health_cost >= 1:
            return True
        return False