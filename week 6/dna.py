import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    sample_file = sys.argv[1]
    with open(sample_file) as data:
        sample_data = csv.DictReader(data)
        sample_list = list(sample_data)

        # Read headers and remove name tag
        STR = sample_data.fieldnames
        STR.remove("name")

    # TODO: Read DNA sequence file into a variable
    sequence_file = sys.argv[2]
    with open(sequence_file) as data:
        sequence_data = data.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Create dictionary for sample to compare
    dna_dict = dict()
    for key in STR:
        dna_dict[key] = None

    # Copy count match values into the sample dict
    for dna in STR:
        dna_dict[dna] = longest_match(sequence_data, dna)

    # TODO: Check database for matching profiles
    # Convert strings to int in sample list
    for i in range(len(sample_list)):
        for k, v in sample_list[i].items():
            try:
                sample_list[i][k] = int(v)
            except:
                pass

    for i in sample_list:
        if dna_dict.items() <= i.items():
            print(i["name"])
            exit()
    print("No match.")

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
