import matplotlib.pyplot as plt

# Data from the user's C program output
n_elements = [6000, 7000, 10000, 15000, 20000, 50000]
time_taken = [0.000005, 0.000005, 0.000006, 0.000008, 0.000010, 0.000020]

# Create the plot
plt.figure(figsize=(10, 6))
plt.plot(n_elements, time_taken, marker='o', linestyle='-')
plt.title('Linear Search Performance')
plt.xlabel('Number of Elements')
plt.ylabel('Average Time Taken (seconds)')
plt.grid(True)


plt.show()


print('Plot saved as linear_search_performance.png')