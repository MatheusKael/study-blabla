def bricks(size):
    for i in range(1, size + 1):
        for j in range(size - i):
            print(" ", end="")
        print("#" * i, end="  ")
        print("#" * i)


def main():
    size = 0
    while size <= 0 or size >= 9:
        size = int(input("Height: "))

    bricks(size)


main()
