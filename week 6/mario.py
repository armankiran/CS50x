# TODO# TODO

def main():
    # Check input

    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                break
        # reject input
        except ValueError:
            print("Try again.")

    print_blocks(n)

# Print blocks


def print_blocks(n):
    i = 1
    j = n - 1
    while i < n + 1:
        print(" " * j, end="")
        print("#" * i, end="")
        print()
        i += 1
        j -= 1


main()
