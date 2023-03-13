from sys import argv, exit
from pyfiglet import Figlet, FontNotFound

args = ["-f", "--font"]


def TextToRender(font="slant" ):
    try:
        f = Figlet(font=font)
    except FontNotFound:
        exit(1)
    text = input("Text to render: ")
    print(f.renderText(text))


def main():
    argv_len = len(argv)

    if argv_len > 3 or argv_len == 2:
        exit(1)
    elif argv_len > 1 and argv[1] in args:
        TextToRender(font=argv[2])
    elif argv_len == 1:
        TextToRender()
    else:
        exit(1)

main()