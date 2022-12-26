with open("input.txt") as file:
    rows = file.read().split("\n")

cols = ['' for n in range(len(rows))]
for i in range(len(rows)):
    for j in range(len(rows)):
        cols[i] = cols[i] + rows[j][i]

highest_scenic_score = 0
temp = ""

for y in range(1, len(rows) - 1):
    for x in range(1, len(rows[0]) - 1):
        tree = int(rows[y][x])
        l_visible = 0
        r_visible = 0
        t_visible = 0
        b_visible = 0

        for n in range(x - 1, -1, -1):
            l_visible += 1
            if tree - int(rows[y][n]) <= 0:
                break

        for n in range(x + 1, len(rows[0])):
            r_visible += 1
            if tree - int(rows[y][n]) <= 0:
                break

        for n in range(y - 1, -1, -1):
            t_visible += 1
            if tree - int(cols[x][n]) <= 0:
                break

        for n in range(y + 1, len(rows)):
            b_visible += 1
            if tree - int(cols[x][n]) <= 0:
                break

        scenic_score = l_visible * r_visible * t_visible * b_visible

        if scenic_score > highest_scenic_score:
            highest_scenic_score = scenic_score

print(highest_scenic_score)
