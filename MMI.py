import matplotlib.pyplot as plt

# Matrix sizes and their measured times (from your screenshot)
sizes = [4, 8, 12, 20, 40, 100]
times = [0.000000, 0.000002, 0.000004, 0.000018, 0.000329, 0.001804]

# Plot
plt.figure(figsize=(8,6))
plt.plot(sizes, times, marker='o', linestyle='-', linewidth=2)

# Labels and title
plt.xlabel("Matrix Size (n x n)", fontsize=12)
plt.ylabel("Execution Time (seconds)", fontsize=12)
plt.title("Matrix Multiplication Execution Time vs Matrix Size", fontsize=14)
plt.grid(True)

# Show plot
plt.show()
