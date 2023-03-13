from sys import argv, exit
from pyfiglet import Figlet

f = Figlet(font='slant')

if (len(argv) > 2):
    exit(1)

print(f.renderText('text to render'))

