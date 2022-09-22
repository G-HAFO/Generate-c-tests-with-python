





# Using readlines()
file1 = open('file.tt', 'r')
lines_with_n = file1.readlines()

lines = []

for line in lines_with_n:
    lines.append(int(line.replace("\n", "")))


def find_inc(depths):
    sum_inc = 0
    for num, aa in enumerate(depths):

        if not num < len(depths) - 1:
            break
        cur = depths[num]
        next = depths[num + 1]
        if cur < next:
            sum_inc += 1

    return sum_inc

result = find_inc(lines)

print("result: ", result)

