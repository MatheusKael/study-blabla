def main():
    n = input("Number: ")
    try:
        int(n)
    except ValueError:
        print("Not valid!")
    valid = valid_card(n)

    if valid == True:

        card_type(n, len(n))
        return

    print("INVALID")


def card_type(number, n_digits):
    if number[:1] == '4' and (n_digits == 16 or n_digits == 13):
        print("VISA")
    elif int(number[:2]) > 50 and int(number[:2]) <= 55 and n_digits == 16:
        print("MASTERCARD")
    elif int(number[:2]) == 34 or int(number[:2]) == 37 and n_digits == 15:
        print("AMEX")

    print("INVALID")

def valid_card(number ):

    digits = [int(digit) for digit in str(number)]

    for i in range(len(digits) - 2, -1, -2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] -= 9

    sum_of_digits = sum(digits)

    return sum_of_digits % 2 == 0


main()
