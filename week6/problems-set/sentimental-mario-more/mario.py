def bricks(size):
    for i in range(size):
        for j in range(size - i):
            print(" ", end="")
        print("#" * i, end=" ")
        print("#" * i)


def main():
    size = -1
    while size <= 0:
        size = int(input())

    bricks(size)


main()
