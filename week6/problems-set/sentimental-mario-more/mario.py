def bricks(size):
    for i in range(size + 1):
        for j in range(size - i):
            print(" ", end="")
        print("#" * i, end=" ")
        print("#" * i)


def main():
    size = 0
    while size <= 0:
        size = int(input("Height: "))

    bricks(size)


main()
