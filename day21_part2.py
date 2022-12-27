with open("input.txt") as file:
    data = file.read().split("\n")

monkeys = {}
for x in data:
    if x[6].isdigit():
        monkeys[x[:4]] = int(x[6:])
    else:
        monkeys[x[:4]] = x[6:]

def find_humn(monkey):
    if monkey == "humn":
        return True
    elif isinstance(monkeys[monkey], int):
        return False
    else:
        return find_humn(monkeys[monkey][:4]) or find_humn(monkeys[monkey][7:])

print(find_humn(monkeys["root"][:4]))
print(find_humn(monkeys["root"][7:]))

# humn is within fzvp

def find_num(monkey):
    if isinstance(monkeys[monkey], int):
        return monkeys[monkey]
    else:
        return eval("find_num(monkeys[monkey][:4])" + monkeys[monkey][5] + "find_num(monkeys[monkey][7:])")

print(find_num(monkeys["root"][7:]))

# fzvp must equal 88521161883075

def find_equation(monkey):
    if monkey == "humn":
        return "x"
    elif isinstance(monkeys[monkey], int):
        return str(monkeys[monkey])
    else:
        return "(" + find_equation(monkeys[monkey][:4]) + monkeys[monkey][5] + find_equation(monkeys[monkey][7:]) + ")"

print(find_equation(monkeys["root"][:4]))

# manual simplification:
# 9*(((193764052094285-(((226)+(2*((((((881)+((((216)+((2*(((((516)+((((2*((((((((285)+(((190)+((2*((122)+(((((9*((((917)+(7*((((114)+((317)+(2*(((((6)*(((((((((10*((((765)+((18)*(((x-(334))/3)+(574))))/3)-(899)))+(589))*2)-472)/3)-(733))+(820))/3)+(77)))-(476))/4)+(396)))))/5)-(297))))/7)-(583)))-(726))*2)+(320))/2)))-(115)))/3))/2)-(910))*4)+(754))/2)-(5*((69)+(5*(8))))))+(580))*2)-(729)))+(25))/3)+(549)))-(273)))+685)/2))/3)-(972))*4)-(598))))/2))/(9))+(937))

# set simplified expression equal to 88521161883075 and solve for x

print("Answer: 3699945358564")
