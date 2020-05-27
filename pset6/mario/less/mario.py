from cs50 import get_int


def pattern(n):

    k = 2*n - 2

    for i in range(0, n):
        for j in range(0, k):
            print(end=" ")
        k = k - 2
        for j in range(0, i+1):
            print("# ", end="")
        print("\r")


while True:
    n = get_int("Enter the height of the tower : ")
    if n > 0 and n < 9:
        break

pattern(n)