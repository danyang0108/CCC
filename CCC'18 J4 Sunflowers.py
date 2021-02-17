#question link: https://dmoj.ca/problem/ccc18s2

n=int(input())
grid=[]
for i in range(n):
  grid.append(list(map(int,input().split())))
edge=[grid[0][0],grid[0][n-1],grid[n-1][0],grid[n-1][n-1]]
if max(edge)==edge[0]: #rotate 180
  rotated = list(zip(*grid[::-1]))
  rotated = list(zip(*rotated[::-1]))
  for i in range(n):
    print(' '.join(list(map(str,rotated[i]))))
elif max(edge)==edge[1]:  #rotate 90
  rotated = list(zip(*grid[::-1]))
  for i in range(n):
    print(' '.join(list(map(str,rotated[i]))))
elif max(edge)==edge[2]: #rotate 270
  rotated = list(zip(*grid[::-1]))
  rotated = list(zip(*rotated[::-1]))
  rotated = list(zip(*rotated[::-1]))
  for i in range(n):
    print(' '.join(list(map(str,rotated[i]))))
else:
  for i in range(n):
    print(' '.join(list(map(str,grid[i]))))
