import matplotlib.pyplot as plt

# Data from your C code output for Bubble Sort
elements = [10, 50, 100, 500, 1000, 3000, 6000, 8000]
time_taken = [0.000000, 0.000007, 0.000031, 0.000204, 0.000715, 0.005646, 0.022156, 0.039043]

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(elements, time_taken, marker='o', linestyle='-', color='b')

# Add labels and title
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time (t) in seconds')
plt.title('Time Complexity of Bubble Sort')
plt.grid(True)
plt.show()
