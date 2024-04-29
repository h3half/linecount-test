import time

def countLines1():
    inputFile = open("source.txt", "r")
    lines = inputFile.readlines()
    count = len(lines)
    inputFile.close()


def countLines2():
    lines = sum(1 for _ in open("source.txt", "r"))

begin = time.time()

for _ in range(100_000):
    countLines1()

end = time.time()
print(f"{end - begin:0.6f}")
