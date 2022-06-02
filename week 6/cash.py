# TODO
from cs50 import get_float


def main():
    coins = 0
    cents = get_input()
    # Count coins
    while cents > 0:
        while cents >= 25:
            coins += 1
            cents -= 25
        while cents >= 10:
            coins += 1
            cents -= 10
        while cents >= 5:
            coins += 1
            cents -= 5
        while cents >= 1:
            cents -= 1
            coins += 1
    print(coins)


def get_input():
    # Get input and check input
    while True:
        try:
            money = get_float("Change owed: ")
            if money > 0:
                break
        except:
            pass
    # return cents
    return round(int(money * 100))


main()
