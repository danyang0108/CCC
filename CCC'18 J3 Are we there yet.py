#question link: https://dmoj.ca/problem/ccc18j3

dis=list(map(int,input().split()))
list1=dis.copy()
count=0
for i in range(5):
  list1.insert(i,0)
  if count==0:
    for i in range(1,5):
      list1[i]=list1[i]+list1[i-1]
    print (list1[0],list1[1],list1[2],list1[3],list1[4])
    list1=dis.copy()
  elif count==1:
    list1[3]=list1[2]+list1[3]
    list1[4]=list1[3]+list1[4]
    print (list1[0],list1[1],list1[2],list1[3],list1[4])
    list1=dis.copy()
  elif count==2:
    list1[0]=list1[1]+list1[0]
    list1[4]=list1[4]+list1[3]
    print (list1[0],list1[1],list1[2],list1[3],list1[4])
    list1=dis.copy()
  elif count==3:
    list1[0]=list1[0]+list1[1]+list1[2]
    list1[1]=list1[1]+list1[2]
    print (list1[0],list1[1],list1[2],list1[3],list1[4])
    list1=dis.copy()
  elif count==4:
    list1[2]=list1[3]+list1[2]
    list1[1]=list1[1]+list1[2]
    list1[0]=list1[0]+list1[1]
    print (list1[0],list1[1],list1[2],list1[3],list1[4])
  count+=1
