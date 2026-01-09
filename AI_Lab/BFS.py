from collections import deque

def bfs_with_goal(graph, start, goal):
    visited = set()
    queue = deque([(start, 0)])  # Queue stores (node, cumulative_weight)
    parent = {start: None}  # To reconstruct the path

    while queue:
        node, cumulative_weight = queue.popleft()

        if node == goal:
            # Reconstruct the path from start to goal
            path = []
            while node is not None:
                path.append(node)
                node = parent[node]
            return path[::-1], cumulative_weight

        if node not in visited:
            visited.add(node)
            for neighbor, weight in graph[node]:
                if neighbor not in visited:
                    queue.append((neighbor, cumulative_weight + weight))
                    parent[neighbor] = node

    return None  # Goal not reachable

# Example usage
if __name__ == "__main__":
    # Weighted graph represented as adjacency list
    graph = {
        'A': [('B', 1), ('C', 2)],
        'B': [('A', 1), ('D', 4), ('E', 2)],
        'C': [('A', 2), ('F', 3)],
        'D': [('B', 4)],
        'E': [('B', 2), ('F', 1)],
        'F': [('C', 3), ('E', 1)]
    }
    start_node = 'A'
    goal_node = 'F'
    result = bfs_with_goal(graph, start_node, goal_node)
    if result:
        path, total_weight = result
        print(f"Path to goal: {path}, Total weight: {total_weight}")
    else:
        print("Goal not reachable")