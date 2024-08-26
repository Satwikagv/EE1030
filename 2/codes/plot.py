import matplotlib.pyplot as plt

# Define the points of the parallelogram
points = [(6, 1), (8, 2), (9, 4), (7, 3)]

# Separate the points into X and Y coordinates
x_coords, y_coords = zip(*points)

# Close the parallelogram by adding the first point to the end
x_coords = list(x_coords) + [x_coords[0]]
y_coords = list(y_coords) + [y_coords[0]]

# Plot the parallelogram
plt.plot(x_coords, y_coords, 'b-o', label='Parallelogram')
plt.fill(x_coords, y_coords, 'lightblue', alpha=0.5)

# Add labels and title
plt.xlabel('X axis')
plt.ylabel('Y axis')
plt.title('Parallelogram Plot')
plt.legend()

# Display the plot
plt.grid(True)
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.savefig("plot.py.png")
plt.show()


