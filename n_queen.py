import time

def is_safe(board, row, col, n):
    # Check this column on the upper side
    for i in range(row):
        if board[i][col] == 'Q':
            return False

    # Check upper left diagonal
    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j -= 1

    # Check upper right diagonal
    i, j = row, col
    while i >= 0 and j < n:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j += 1

    return True

def solve_n_queens_util(board, row, n, solutions):
    if row == n:
        # Store a copy of the solution
        solutions.append([''.join(r) for r in board])
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 'Q'
            solve_n_queens_util(board, row + 1, n, solutions)
            board[row][col] = '.'  # backtrack

def solve_n_queens(n):
    board = [['.' for _ in range(n)] for _ in range(n)]
    solutions = []
    solve_n_queens_util(board, 0, n, solutions)
    return solutions

def print_solutions(solutions):
    for idx, solution in enumerate(solutions, 1):
        print(f"\nSolution {idx}:")
        for row in solution:
            print(' '.join(row))

def main():
    n = int(input("Enter the value of N for N-Queens problem: "))
    start_time = time.time()
    solutions = solve_n_queens(n)
    end_time = time.time()

    print_solutions(solutions)
    print(f"\nTotal number of solutions: {len(solutions)}")
    print(f"Total execution time: {end_time - start_time:.4f} seconds")

if __name__ == "__main__":

    main()