import matplotlib.pyplot as plt
import math

# Function to calculate the distance between two points
def distance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

# Given points A, B, and C
A = (-6, 0)
B = (3, -8)
C = (-4, 6)

# Calculate the distances AC and BC
AC = distance(A[0], A[1], C[0], C[1])
BC = distance(B[0], B[1], C[0], C[1])

# Calculate the ratio AC:BC
ratio = AC / BC

print(f"Length of AC: {AC:.2f}")
print(f"Length of BC: {BC:.2f}")
print(f"The ratio of AC to BC is approximately {ratio:.2f}:1")

# Plotting the points and the line segments
plt.figure(figsize=(6, 6))

# Plotting the points A, B, and C
plt.plot(A[0], A[1], 'ro')  # Point A
plt.text(A[0], A[1], '  A(-6,0)', fontsize=12, verticalalignment='bottom')
plt.plot(B[0], B[1], 'bo')  # Point B
plt.text(B[0], B[1], '  B(3,-8)', fontsize=12, verticalalignment='top')
plt.plot(C[0], C[1], 'go')  # Point C
plt.text(C[0], C[1], '  C(-4,6)', fontsize=12, verticalalignment='bottom')

# Plotting the line segments AC and BC
plt.plot([A[0], C[0]], [A[1], C[1]], 'r--', label='AC')
plt.plot([B[0], C[0]], [B[1], C[1]], 'b--', label='BC')

# Setting the limits and grid
plt.xlim(-10, 5)
plt.ylim(-10, 10)
plt.grid(True)

# Adding title and labels
plt.title(f"Line Segments AC and BC with Ratio {ratio:.2f}:1")
plt.xlabel("x-axis")
plt.ylabel("y-axis")

# Show the plot
plt.legend()
plt.savefig("q2.py.png")

