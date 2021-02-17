#question link: https://dmoj.ca/problem/ccc18j2

n=int(input())
str1=input()
str1=list(str1)
str2=input()
str2=list(str2)
count=0
for i in range(n):
  if str1[i] == "C" and str2[i] == "C":
    count+=1
print (count)
