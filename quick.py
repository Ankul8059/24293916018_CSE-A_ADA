import matplotlib.pyplot as plt

# Data from your C code output for Quick Sort
elements = [6000, 10000, 15000, 25000, 50000, 100000, 500000, 1000000]
time_taken = [0.000451, 0.000797, 0.001253, 0.002248, 0.004686, 0.009855, 0.058059, 0.165043]

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(elements, time_taken, marker='o', linestyle='-', color='r')

# Add labels and title
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time (t) in seconds')
plt.title('Time Complexity of Quick Sort')
plt.grid(True)
plt.show()
