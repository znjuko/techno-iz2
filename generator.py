import sys
from random import randrange

filename = sys.argv[1]
number_count = 4000000

f = open(filename, "w+")

for i in range(number_count):
    f.write(str(randrange(3000))+"\n")

f.close()














