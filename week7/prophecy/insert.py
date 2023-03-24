import csv
from cs50 import SQL


db = SQL("sqlite:///roster.db")


students = db.execute('SELECT DISTINCT house FROM students;')

print(students)
