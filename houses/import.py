from cs50 import SQL
import csv
from sys import argv




def main():
    if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        return

    db = SQL("sqlite:///students.db")

    with open(argv[1], "r") as characters:
        reader = csv.reader(characters)
        header = next(reader)
        for person in reader:
            person_name = person[0].split(" ")
            if len(person_name) == 3:
                db.execute(f"INSERT INTO students (first, middle, last, house, birth) VALUES ('{person_name[0]}', '{person_name[1]}', '{person_name[2]}', '{person[1]}', '{person[2]}')")
            else:
                db.execute(f"INSERT INTO students (first, middle, last, house, birth) VALUES ('{person_name[0]}', NULL, '{person_name[1]}', '{person[1]}', '{person[2]}')")


main()