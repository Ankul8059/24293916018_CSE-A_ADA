import matplotlib.pyplot as plt

# Matrix sizes (example data)
sizes = [4, 8, 64, 254, 512]

# Corresponding times (in seconds)
times = [0.0, 0.00004, 0.00584, 0.05205, 2.22994]

plt.figure(figsize=(10, 6))
plt.plot(sizes, times, marker='o', linestyle='-', color='green')

plt.title("Recursive Matrix Multiplication Time vs Matrix Size")
plt.xlabel("Matrix Size (n x n)")
plt.ylabel("Average Time (seconds)")
plt.grid(True, ls="--", lw=0.5)

# Optional: annotate each point
for x, y in zip(sizes, times):
    plt.text(x, y, f"{y:.5f}", fontsize=9, ha='right', va='bottom')

plt.show()
