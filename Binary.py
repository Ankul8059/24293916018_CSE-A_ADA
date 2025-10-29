import pandas as pd
import matplotlib.pyplot as plt

# Data extracted from the user's C program output
data = {
    'Number of Elements': [5000, 15000, 25000, 50000, 100000, 200000 ],
    'Time Taken (seconds)': [0.004549, 0.005324, 0.005505, 0.006044, 0.006367, 0.006753]
}

# Create a DataFrame from the data
df = pd.DataFrame(data)

# Create the plot
plt.plot(df['Number of Elements'], df['Time Taken (seconds)'], marker='o', linestyle='-')
plt.title('Binary Search Time vs. Number of Elements')
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.tight_layout()

# Save the plot to a file
plt.savefig('binary_search_time.png')

# This line displays the plot in a new window.
plt.show()