import heapq

def manhattan_distance(node, goal):
    """
    Calculate the Manhattan distance between two points.
    :param node: Tuple (x, y) representing the current node.
    :param goal: Tuple (x, y) representing the goal node.
    :return: Manhattan distance between the two points.
    """
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])

def greedy_best_first_search(graph, start, goal, heuristic_func):
    visited = set()
    priority_queue = [(heuristic_func(start, goal), start)]  # Priority queue stores (heuristic_value, node)
    parent = {start: None}  # To reconstruct the path

    while priority_queue:
        _, current = heapq.heappop(priority_queue)

        if current == goal:
            # Reconstruct the path from start to goal
            path = []
            while current is not None:
                path.append(current)
                current = parent[current]
            return path[::-1]

        if current not in visited:
            visited.add(current)
            for neighbor, weight in graph[current]:
                if neighbor not in visited:
                    heapq.heappush(priority_queue, (heuristic_func(neighbor, goal), neighbor))
                    parent[neighbor] = current

    return None  # Goal not reachable

# Example usage
if __name__ == "__main__":
    # Weighted graph represented as adjacency list (grid-based example)
    graph = {
        (0, 0): [((0, 1), 1), ((1, 0), 1)],
        (0, 1): [((0, 0), 1), ((1, 1), 1)],
        (1, 0): [((0, 0), 1), ((1, 1), 1)],
        (1, 1): [((0, 1), 1), ((1, 0), 1), ((2, 2), 2)],
        (2, 2): [((1, 1), 2)]
    }

    start_node = (0, 0)
    goal_node = (2, 2)

    result = greedy_best_first_search(graph, start_node, goal_node, manhattan_distance)
    if result:
        print(f"Path to goal: {result}")
    else:
        print("Goal not reachable")