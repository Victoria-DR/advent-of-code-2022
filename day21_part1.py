with open("input.txt") as file:
    data = file.read().split("\n")

monkeys = {}
for x in data:
    if x[6].isdigit():
        monkeys[x[:4]] = int(x[6:])
    else:
        monkeys[x[:4]] = x[6:]

def find_num(monkey):
    if isinstance(monkeys[monkey], int):
        return monkeys[monkey]
    else:
        return eval("find_num(monkeys[monkey][:4])" + monkeys[monkey][5] + "find_num(monkeys[monkey][7:])")

print(find_num("root"))
