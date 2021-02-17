#question link: https://dmoj.ca/problem/ecoo18r1p2

ids=[]
ans=[]
ans2=[]
for z in range(10):
    n=int(input())
    for i in range(n):
        list1=list(map(int,input().split()))
        ids.append(list1[0])
        list1.remove(list1[0])
        list1.remove(list1[0])
        list1.sort()
        ans.append(list1[0])
        list1.clear()
    small=min(ans)
    for i in range(len(ans)):
        if (ans[i]==small):
            ans2.append(ids[i])
    ans2.sort()
    print (small,end=" {")
    for i in range(len(ans2)-1):
        print (ans2[i],end=",")
    print (ans2[-1],end="}\n")
    ans2.clear()
    ans.clear()
    ids.clear()