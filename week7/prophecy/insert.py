import csv
from cs50 import SQL


db = SQL("sqlite:///roster.db")

with open("./schema.sql", 'r') as schema:
    schemas = 

students = db.execute('SELECT DISTINCT house FROM students;')

print(students)
