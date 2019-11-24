# gaussian-elimination-with-complete-pivoting
Gaussian elimination algorithm with complete pivoting together with backward substitution to solve Ax=b, where A is an n×n square matrix

- The program accepts 2 command line arguments for filenames. The first argument is the file where you read the A matrix, and the second one is the file where you read the b vector. Each line in a file represents a row. 
- Use dynamically allocated memory to store the matrix and the vector
- Print out an error message and quit if it detects that A is singular
- Use counters to count the total number of multiplication and addition operations
- Print out the number of operations together with the solution x
