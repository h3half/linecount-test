import time

def countLines():
    inputFile = open("source.txt", "r")
    lines = inputFile.readlines()
    count = len(lines)
    inputFile.close()

begin = time.time()

for _ in range(100_000):
    countLines()

end = time.time()

print(f"{end - begin:0.6f}")
