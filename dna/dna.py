import csv
from sys import argv
import re

def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    with open(argv[2], "r") as dna:
        dna = dna.read()

    list_dna = []
    database = open(argv[1], "r")
    reader = csv.reader(database, delimiter=',')
    header = next(reader)
    for i in range(1, len(header)):
        list_dna.append(header[i])
    database.close()

    dict_dna = find_dna(dna, list_dna)

    result_of_matching = find_match(dict_dna)
    return result_of_matching


def find_dna(dna, list_dna):
    dict_dna = {}
    for dna_str in list_dna:
        start = 0
        end = 0
        start_end = ()
        list_start_end = list()
        i = 0
        j = 0
        while i < len(dna):
            if dna_str_search(dna, i, dna_str):
                start = i
                end = i + len(dna_str) - 1
                list_start_end.append((start, end))
                i += len(dna_str)
            else:
                i += 1
        result = count_repeats(list_start_end)
        dict_dna[dna_str] = result
    return dict_dna


def dna_str_search(dna, i, dna_str):
    for j in range(len(dna_str)):
        if i + j >= len(dna):
            return False
        if dna[i + j] != dna_str[j]:
            return False
    return True


def count_repeats(list_start_end):
    max_repeats = 0

    current_repeats = 0
    prev_end = -2
    for start, end in list_start_end:
        if start - prev_end == 1:
            current_repeats += 1
        else:
            current_repeats = 1
        if max_repeats < current_repeats:
            max_repeats = current_repeats
        prev_end = end
    return max_repeats


def find_match(matches):
    with open(argv[1], "r") as database:
        reader = csv.DictReader(database)
        for person in reader:
            if len(person) < 1:
                return
            if person_match(person, matches):
                return person["name"]
        return "No match"


def person_match(person,matches):
    for dna_str in matches:
        if matches[dna_str] != int(person[dna_str]):
            return False
    return True


print(main())