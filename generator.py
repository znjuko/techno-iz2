import sys
from random import randrange

filename = sys.argv[1]
number_count = 1000

f = open(filename, "w+")

for i in range(number_count):
    f.write(str(randrange(200))+"\n")

f.close()














