#question link: https://dmoj.ca/problem/ccc11s3

def crystalSquaresatX(m,x):
    if m >= 1:
        power = 5 ** (m-1)
        location = x // power
        if location == 0 or location == 4:
            return 0
        elif location == 1 or location == 3:
            return 1 * power + crystalSquaresatX(m - 1, x % power)
        elif location == 2:
            return 2 * power + crystalSquaresatX(m - 1, x % power)
        return maxheightatx
    return 0

T = eval(input())
for t in range(0,T):
    line = (input())
    space = line.find(" ")
    m = eval(line[0:space])
    line = line[space+1:]
    space = line.find(" ")
    x = eval(line[0:space])
    y = eval(line[space+1:])
    if y < crystalSquaresatX(m,x):
        print("crystal")
    else:
        print("empty")