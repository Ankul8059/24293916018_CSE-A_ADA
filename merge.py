import matplotlib.pyplot as plt

# Data from the C code output for Merge Sort
elements = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000]
time_taken = [0.000004, 0.000013, 0.000035, 0.000132, 0.000234, 0.000585, 0.000899, 0.000995, 0.001221, 0.001407]

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(elements, time_taken, marker='o', linestyle='-', color='g')

# Add labels and a title to the graph
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time (t) in seconds')
plt.title('Time Complexity of Merge Sort (Average Case)')
plt.grid(True)
plt.show()
