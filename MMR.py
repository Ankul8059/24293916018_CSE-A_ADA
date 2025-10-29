import matplotlib.pyplot as plt

# Matrix sizes (n x n)
sizes = [4, 8, 16, 32, 64]

# Corresponding average times in seconds
times = [0.0, 0.000010, 0.000080, 0.000480, 0.003580]

# Create the plot
plt.figure(figsize=(8,5))
plt.plot(sizes, times, marker='o', linestyle='-', color='green', linewidth=2)

# Labels and title
plt.xlabel('Matrix Size (n x n)')
plt.ylabel('Average Time (seconds)')
plt.title('Recursive Matrix Multiplication Time vs Matrix Size')
plt.grid(True)

# Show plot
plt.show()
