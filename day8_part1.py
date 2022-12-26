with open("input.txt") as file:
    rows = file.read().split("\n")

cols = ['' for n in range(len(rows))]
for i in range(len(rows)):
    for j in range(len(rows)):
        cols[i] = cols[i] + rows[j][i]

count = (len(rows) * 2) + ((len(cols) - 2) * 2)

for y in range(1, len(rows) - 1):
    for x in range(1, len(rows[0]) - 1):
        tree = int(rows[y][x])
        l_visible = True
        r_visible = True
        t_visible = True
        b_visible = True

        for n in range(tree, 10):
            if rows[y].find(str(n), 0, x) != -1:
                l_visible = False
                break
        for n in range(tree, 10):
            if rows[y].find(str(n), x + 1) != -1:
                r_visible = False
                break
        for n in range(tree, 10):
            if cols[x].find(str(n), 0, y) != -1:
                t_visible = False
                break
        for n in range(tree, 10):
            if cols[x].find(str(n), y + 1) != -1:
                b_visible = False
                break

        if l_visible or r_visible or t_visible or b_visible:
            count += 1

print(count)
