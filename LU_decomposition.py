"""
Marta Dzięgielewska
LU decomposition
28.01.2020
"""

def lu(mat, n):
    lower = [[0 for x in range(n)]
             for y in range(n)]
    upper = [[0 for x in range(n)]
             for y in range(n)]

    for i in range(n):
        # upper
        for k in range(i, n):
            # sum of L(i, j) i U(j, k)
            sum = 0
            for j in range(i):
                sum += (lower[i][j] * upper[j][k])

            upper[i][k] = mat[i][k] - sum

        # lower
        for k in range(i, n):
            if i == k:
                lower[i][i] = 1  # diagonal 1
            else:
                # sum of L(k, j) * U(j, i)
                sum = 0
                for j in range(i):
                    sum += (lower[k][j] * upper[j][i])

                lower[k][i] = int((mat[k][i] - sum) /
                                  upper[i][i])

    print("Lower\t\t\tUpper")

    for i in range(n):

        # lower
        for j in range(n):
            print(lower[i][j], end="\t")
        print("", end="\t")

        # upper
        for j in range(n):
            print(upper[i][j], end="\t")
        print("")


mat = [[1, 4, -3],
       [-2, 8, 5],
       [3, 4, 7]]

lu(mat, 3)