import matplotlib.pyplot as plt

def read_points_from_file(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            # Assuming the format in the file is something like "A(x, y)"
            parts = line.strip().split('(')
            if len(parts) == 2:
                coords = parts[1].strip(')').split(',')
                x = float(coords[0].strip())
                y = float(coords[1].strip())
                points.append((x, y))
    return points

# Read points from the file
points = read_points_from_file('points.txt')

# Separate the points into X and Y coordinates
x_coords, y_coords = zip(*points)

# Close the parallelogram by adding the first point to the end
x_coords = list(x_coords) + [x_coords[0]]
y_coords = list(y_coords) + [y_coords[0]]

# Plot the parallelogram
plt.plot(x_coords, y_coords, 'b-o', label='Parallelogram')
labels = ['A', 'B', 'C', 'D']
for i, label in enumerate(labels):
    plt.text(x_coords[i], y_coords[i], f' {label}({x_coords[i]},{y_coords[i]})', fontsize=12, ha='right')
# Add labels and title
plt.xlabel('X axis')
plt.ylabel('Y axis')
plt.legend()

# Display the plot
plt.grid(True)
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.savefig("parallelogram_plot.png")
plt.show()


