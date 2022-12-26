with open("input.txt") as file:
    data = file.read().split("\n")

x = 1
signal_strengths = [0]

for i in range(len(data)):
    signal_strengths.append(x)
    if data[i][:4] == "addx":
        signal_strengths.append(x)
        x += int(data[i][5:])

total = 0
for x in [20, 60, 100, 140, 180, 220]:
    total += x * signal_strengths[x]

print(total)
