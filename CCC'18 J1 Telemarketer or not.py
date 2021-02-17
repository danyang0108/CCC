#question link: https://dmoj.ca/problem/ccc18j1

digit=4
if digit == 4:
    x=int(input())
    if x == 8 or x==9:
        digit=digit-1
    else:
        print ("answer")
if digit == 3:
    y=int(input())
    z=int(input())
    if y==z:
        digit=digit-2
    else:
        print ("answer")
if digit == 1:
    w=int(input())
    if w==8 or w==9:
        print ("ignore")
    else: 
        print ("answer")
