from sys import argv, exit
from pyfiglet import Figlet

args = ["-f", "--font"]

argv_len = len(argv)

if argv_len > 3 or argv_len == 2:
    exit(1)
elif argv_len > 1 and argv[1] in args:

    f = Figlet(font=argv[2])

    text= input("Text to render: ")
    print(f.renderText(text))
elif argv_len == 1:

    f = Figlet(font="slant")

    text= input("Text to render: ")
    print(f.renderText(text))
else:
    exit(1)