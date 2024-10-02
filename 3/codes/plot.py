import numpy as np
import matplotlib.pyplot as plt

# Function to extract points from the file
def read_points_from_file(filename):
    points = []
    with open(filename, 'r') as file:
        for line in file:
            # Split line by parentheses and commas
            line = line.strip()
            point = line[line.find('(')+1 : line.find(')')].split(',')
            points.append((float(point[0]), float(point[1])))
    return points

# Function to plot a circle given the center and radius
def plot_circle(ax, center, radius, color, label):
    circle = plt.Circle(center, radius, color=color, fill=False, label=label)
    ax.add_artist(circle)

# Function to label a point with its coordinates
def label_point(ax, point, label):
    ax.annotate(f'{label} {point}', (point[0], point[1]), textcoords="offset points", xytext=(10,-10), ha='center')

# Reading points from 'circle.txt'
points = read_points_from_file('circle.txt')
c1 = points[0]  # First center point
c2 = points[1]  # Second center point
p = points[2]   # Point on the circle

# Given radius
radius = 3

# Create the plot
fig, ax = plt.subplots()

# Plot the circles
plot_circle(ax, c1, radius, 'blue', 'Circle 1')
plot_circle(ax, c2, radius, 'green', 'Circle 2')

# Plot the points c1, c2, and p
ax.plot(c1[0], c1[1], 'bo', label='Center 1')
ax.plot(c2[0], c2[1], 'go', label='Center 2')
ax.plot(p[0], p[1], 'ro', label='Point P')

# Label the points with their coordinates
label_point(ax, c1, 'c1')
label_point(ax, c2, 'c2')
label_point(ax, p, 'P')

# Set plot limits to ensure the full circles are shown
# Find the min and max coordinates to include the entire circle
all_x = [c1[0] - radius, c1[0] + radius, c2[0] - radius, c2[0] + radius]
all_y = [c1[1] - radius, c1[1] + radius, c2[1] - radius, c2[1] + radius]

# Set limits with some padding
ax.set_xlim(min(all_x) - 1, max(all_x) + 1)
ax.set_ylim(min(all_y) - 1, max(all_y) + 1)

# Set equal scaling and labels
ax.set_aspect('equal', 'box')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.legend()


# Show the plot
plt.grid(True)
plt.savefig("circle_plot.png");
plt.show()

