import matplotlib.pyplot as plt

# Data from your C code output for Selection Sort
elements = [10, 50, 100, 500, 1000, 3000, 6000, 8000]
time_taken = [0.000000, 0.000000, 0.000000, 0.001000, 0.001000, 0.009000, 0.042000, 0.067000]

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(elements, time_taken, marker='o', linestyle='-', color='g')

# Add labels and title
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time (t) in seconds')
plt.title('Time Complexity of Selection Sort')
plt.grid(True)
plt.show()
