
ponctuations = ['.', '!', '?']


def main():
    s = input("Text: ")

    words = s.split(" ")

    count_letters = 0
    sentences = 0
    n_words = len(words)

    for i in range(len(s)):
        if s[i].isalpha():
            count_letters += 1
        if s[i] in ponctuations:
            sentences += 1

    L = count_letters / n_words * 100

    S = sentences / n_words * 100

    coleman = (0.0588 * L - 0.296 * S - 15.8)

    if coleman < 1:
        print("Before grade 1")
    elif coleman > 16:
        print("Grade 16+")
    else:
        print("Grade ", coleman.__round__())


main()
