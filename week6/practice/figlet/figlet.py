from sys import argv, exit
from pyfiglet import Figlet

args = ["-f", "--font"]

argv_len = len(argv)

if argv_len > 3:
    exit(1)
elif argv_len > 1 and argv[1] in args:

    print(argv[2])
    f = Figlet(font=argv[2])

    text= input("Text to render: ")
    print(f.renderText(text))
else:

    f = Figlet(font="slant")

    text= input("Text to render: ")
    print(f.renderText(text))
