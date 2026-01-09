from collections import deque

def bfs(graph,start, goal):
    visited = set()
    queue = deque([(start,0)])
    parent = {start:None}

    while queue:
        node, cumulative_weight = queue.popleft()

        if node == goal:

            path = []
            while node is not None:
                path.append(node)
                node = parent[node]
            return path[::-1], cumulative_weight
        
        if node not in visited:
            visited.add(node)
            for neighbour, weight in graph[node]:
                if neighbour not in visited:
                    queue.append((neighbour, cumulative_weight + weight))
                    parent[neighbour] = node

    return None
