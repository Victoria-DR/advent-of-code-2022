with open("input.txt") as file:
    data = file.read().split("\n")

cycle = 1
x = 1

for i in range(len(data)):
    if (cycle % 40 == 0) and (40 in [x, x + 1, x + 2]):
        print("#", end="")
    elif (cycle % 40 != 0) and ((cycle % 40) in [x, x + 1, x + 2]):
        print("#", end="")
    else:
        print(".", end="")

    if cycle % 40 == 0:
        print()

    if data[i][:4] == "addx":
        cycle += 1
        if (cycle % 40 == 0) and (40 in [x, x + 1, x + 2]):
            print("#", end="")
        elif (cycle % 40 != 0) and ((cycle % 40) in [x, x + 1, x + 2]):
            print("#", end="")
        else:
            print(".", end="")
        x += int(data[i][5:])
    
        if cycle % 40 == 0:
            print()

    cycle += 1
