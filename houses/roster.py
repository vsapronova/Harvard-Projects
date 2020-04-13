from cs50 import SQL
import csv
from sys import argv





def main():
    if len(argv) != 2:
        print("Usage: python roster.py house_name")
        return

    db = SQL("sqlite:///students.db")
    persons = db.execute(f"SELECT first, middle, last, birth FROM students WHERE house = '{argv[1]}' ORDER BY last, first ASC")
    for person in persons:
        first = person["first"]
        middle = person["middle"]
        last = person["last"]
        birth = person["birth"]

        person_info = first
        if middle != None:
            person_info += " "+middle
        person_info += " "+last
        person_info += ", born "+str(birth)
        print(person_info)
        # list_values = []
        # for key in person:
        #     value = d[key]
        #     if value == None:
        #         continue
        #     list_values.append(str(value))
        # print(" ".join(list_values))


main()

