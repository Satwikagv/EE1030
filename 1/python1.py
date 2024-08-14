import numpy as np

# Define the matrix A and the vector b
A = np.array([[41, 62],
              [-30, 21]])

b = np.array([125, 80])

# Solve the equation Ax = b
x = np.linalg.solve(A, b)

# Print the solution vector x
print("The solution vector x is:", x)

