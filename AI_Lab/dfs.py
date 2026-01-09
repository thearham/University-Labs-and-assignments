from collections import defaultdict

def dfs(graph, start, end, visited=None, path=None, total_weight=0):
    if visited is None:
        visited = set()
    if path is None:
        path = []

    visited.add(start)
    path.append(start)

    if start == end:
        print(f"Path found: {path} with total weight: {total_weight}")
        return True

    for neighbor, weight in graph[start]:
        if neighbor not in visited:
            if dfs(graph, neighbor, end, visited, path, total_weight + weight):
                return True

    path.pop()
    visited.remove(start)
    return False

# Example usage
if __name__ == "__main__":
    graph = defaultdict(list)
    graph['A'].append(('B', 1))
    graph['A'].append(('C', 4))
    graph['B'].append(('D', 2))
    graph['C'].append(('D', 3))
    graph['D'].append(('E', 5))

    start_node = 'A'
    end_node = 'E'
    if not dfs(graph, start_node, end_node):
        print("No path found.")