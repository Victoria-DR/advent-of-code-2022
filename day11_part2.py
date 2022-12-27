with open("input.txt") as file:
    data = [x.strip() for x in file.read().split("\n")]

monkeys = {
    0: [
        [85, 77, 77],
        lambda x: x * 7,
        lambda y: y % 19 == 0,
        6,
        7,
        0
    ],
    1: [
        [80, 99],
        lambda x: x * 11,
        lambda y: y % 3 == 0,
        3,
        5,
        0
    ],
    2: [
        [74, 60, 74, 63, 86, 92, 80],
        lambda x: x + 8,
        lambda y: y % 13 == 0,
        0,
        6,
        0
    ],
    3: [
        [71, 58, 93, 65, 80, 68, 54, 71],
        lambda x: x + 7,
        lambda y: y % 7 == 0,
        2,
        4,
        0
    ],
    4: [
        [97, 56, 79, 65, 58],
        lambda x: x + 5,
        lambda y: y % 5 == 0,
        2,
        0,
        0
    ],
    5: [
        [77],
        lambda x: x + 4,
        lambda y: y % 11 == 0,
        4,
        3,
        0
    ],
    6: [
        [99, 90, 84, 50],
        lambda x: x * x,
        lambda y: y % 17 == 0,
        7,
        1,
        0
    ],
    7: [
        [50, 66, 61, 92, 64, 78],
        lambda x: x + 3,
        lambda y: y % 2 == 0,
        5,
        1,
        0
    ]
}

for round in range(10000):
    for monkey, attributes in monkeys.items():
        for item in attributes[0]:
            attributes[5] += 1
            item = attributes[1](item) % 9699690
            if attributes[2](item):
                monkeys[attributes[3]][0].append(item)
            else:
                monkeys[attributes[4]][0].append(item)
        attributes[0] = []

inspections = sorted([monkey[5] for monkey in monkeys.values()], reverse=True)
print(inspections[0] * inspections[1])
