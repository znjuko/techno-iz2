import sys
from random import randrange

filename = sys.argv[1]
number_count = 100000

f = open(filename, "w+")

for i in range(number_count):
    f.write(str(randrange(127))+"\n")

f.close()














