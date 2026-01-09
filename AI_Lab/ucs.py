import heapq

def uniform_cost_search(graph, start, goal):
    priority_queue = [(0, start, [start])]
    visited = set()

    while priority_queue:
        cost, current_node, path = heapq.heappop(priority_queue)

        if current_node in visited:
            continue
            
        visited.add(current_node)

        if current_node == goal:
            return cost, path
        
        for neighbor, weight in graph.get(current_node, []):
            if neighbor not in visited:
                heapq.heappush(priority_queue, (cost + weight, neighbor, path + [neighbor]))

    return float('inf'), []  

# Example usage
if __name__ == "__main__":
    graph = {
        'A': [('B', 1), ('C', 4)],
        'B': [('C', 2), ('D', 5)],
        'C': [('D', 1)],
        'D': []
    }
    start_node = 'A'
    goal_node = 'D'

    cost, path = uniform_cost_search(graph, start_node, goal_node)
    print(f"Cost: {cost}, Path: {path}")