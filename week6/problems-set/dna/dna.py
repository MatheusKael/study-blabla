import csv
import sys


def main():


    if len(sys.argv) > 3 or len(sys.argv) < 3:
        print("Usage: python dna.py ./[csv_file] ./[txt_file]")
        sys.exit(1)

    database_file = sys.argv[1]
    sequence_file = sys.argv[2]

    database = {}

    with open(database_file) as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            database[row['name']] = row
            database[row['name']].pop('name')


    with open(sequence_file) as csv_file:
        reader = csv.reader(csv_file)
        for row in reader:
            sequence = row[0]

    name = list(database.keys())[0]
    genes = database[name].keys()

    profile = {}

    for gene in genes:
        longest = longest_match(sequence, gene)
        if profile.get(gene) is None:
            profile[gene] = str(longest)
        elif profile.get(gene) < int(longest):
            profile[gene] = str(longest)

    if profile in database.values():
        for name in database:
            if profile == database[name]:
                print(name)
    else:
        print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
