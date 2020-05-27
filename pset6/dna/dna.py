import csv
from sys import argv, exit


def get_maximum(s, sub):
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]

    return max(ans)


def print_match(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("No match found !!!")


if len(argv) != 3:
    print("Arguement Error !!!")
    exit(1)

csv_filename = argv[1]
with open(csv_filename, "r") as file:
    csv_reader = csv.reader(file)
    all_sequences = next(csv_reader)[1:]

    dna_samples = argv[2]
    with open(dna_samples, "r") as str_pattern:
        pattern = str_pattern.read()
        actual = [get_maximum(pattern, seq) for seq in all_sequences]

    print_match(csv_reader, actual)
