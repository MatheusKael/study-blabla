from sys import argv, exit
from pyfiglet import Figlet

args = ["-f", "--font"]


def TextToRender(font="slant" ):
    f = Figlet(font=font)

    text = input("Text to render: ")
    print(f.renderText(text))


def main():
    argv_len = len(argv)

    if argv_len > 3 or argv_len == 2:
        exit(1)
    elif argv_len > 1 and argv[1] in args:
        try:
            TextToRender(font=argv[2])
        except(FontNotFound):
            print("font was not found")
    elif argv_len == 1:
        try:
            TextToRender()
        except(FontNotFound):
            print("font was not found")
    else:
            exit(1)

main()