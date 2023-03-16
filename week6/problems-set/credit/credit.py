def main():
    n = input("Number: ")
    try:
        int(n)
    except ValueError:
        print("Not valid!")

    valid = valid_card(n)

    if valid == True:
        card_type(n)
        return

    print("INVALID")


def card_type(number):
    if number[:1] == '4':
        print("VISA")
    elif int(number[:2]) > 50 and int(number[:2]) <= 55:
        print("MASTERCARD")
    elif int(number[:2]) == 34 or int(number[:2]) == 37:
        print("AMEX")


def valid_card(number):
    new_digits = ""
    digits_final_sum = 0
    digits_sum = 0

    for i in range(2, len(number), 2):
        new_digits += str(int(number[-i]) * 2)

    for i in range(len(new_digits)):
        digits_sum += int(new_digits[i])

    for i in range(1, len(number), 2):
        digits_final_sum += int(number[-i])

    result = digits_final_sum + digits_sum + int(number[0])

    if str(result)[-1] == "0":

        return True

    return False


main()