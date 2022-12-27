def snafu_to_decimal(n):
    result = 0
    multiplier = 1
    for i in range(len(n) - 1, -1, -1):
        snafu_digit = n[i]
        if snafu_digit == "=":
            snafu_digit = -2
        elif snafu_digit == "-":
            snafu_digit = -1
        else:
            snafu_digit = int(snafu_digit)
        
        result += snafu_digit * multiplier
        multiplier *= 5
    return result

def decimal_to_snafu(n):
    result = ""
    carry = 0
    while n > 0:
        digit = n % 5 + carry
        if digit == 3:
            result = "=" + result
        elif digit == 4:
            result = "-" + result
        elif digit == 5:
            result = "0" + result
        else:
            result = str(digit) + result
        
        if digit > 2:
            carry = 1
        else:
            carry = 0

        n //= 5
    return result


with open("input.txt") as file:
    data = file.read().split("\n")

total = 0
for snafu in data:
    total += snafu_to_decimal(snafu)
print(decimal_to_snafu(total))
