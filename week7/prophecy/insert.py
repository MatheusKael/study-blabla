import csv

with open('./students.csv') as file:
    students_dict = csv.DictReader(file)
    for row in students_dict:
            print(row)