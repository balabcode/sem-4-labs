# import random

# def hill_climbing(f, x_range, epsilon=0.01):
#     x = x_range[0]
#     while True:
#         neighbors = generate_neighbors(x, x_range)
#         best_neighbor = max(neighbors, key=lambda x: f(x))
#         if f(best_neighbor) <= f(x) + epsilon:
#             break
#         x = best_neighbor
#     return x

# def generate_neighbors(x, x_range):
#     left_neighbor = max(x - 1, x_range[0])
#     right_neighbor = min(x + 1, x_range[1])
#     return [left_neighbor, right_neighbor] if random.random() < 0.5 else [right_neighbor, left_neighbor]

# def objective(x):
#     return x**2

# x_range = (-10, 10)
# result = hill_climbing(objective, x_range)
# print(f"Maximum value of f(x) within {x_range} is {objective(result)}")


import random

def func(x):
    return x**2

def hill_climbing_maximize(func, x_range=(-10, 10), step_size=0.1, max_iterations=1000):
    current_x = random.uniform(x_range[0], x_range[1])
    current_value = func(current_x)

    for _ in range(max_iterations):
        neighbor_x = current_x + random.uniform(-step_size, step_size)
        neighbor_x = max(min(neighbor_x, x_range[1]), x_range[0])  # Ensure the neighbor is within the range
        neighbor_value = func(neighbor_x)

        if neighbor_value > current_value:
            current_x = neighbor_x
            current_value = neighbor_value

    return current_x, current_value

# Find the maximum value of f(x) = x^2 using Hill Climbing
max_x, max_value = hill_climbing_maximize(func)
print(f"Maximum value of f(x) = x^2 is {max_value:.4f} at x = {max_x:.4f}")
