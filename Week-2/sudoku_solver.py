from z3 import *
def solve(input1):
  #allocate solver
  s= Solver()
  sudoku=[[0 for j in range(9)] for i in range(9)]
  for i in range (9):
    for j in range (9):
      cval=input1[i][j]
      if cval !=0:
        s.add(sudoku[i][j]==cval)

  for i in range(9):
    #distinct function is specific to the z3 library
    s.add(Distinct(sudoku[i]))
    s.add(Distinct([sudoku[i][j] for j in range(9)]))

  for i in range(3):
    for j in range(3):
      s.add(Distinct([sudoku[row][col] for row in range (i*3, (i+1)*3) for col in range(j*3, (j+1)*3)]))

  for i in range(9):
    for j in range(9):
      if input1[i][j]==0:
        s.add(sudoku[i][j]>=1)
        s.add(sudoku[i][j]<=9)
  r=s.check()
  if r==sat:
    m=s.model()
    sol=[[m.evaluate(sudoku[i][j]).as_long() if input1[i][j]==0 else input[i][j] for j in range(9)] for i in range(9)]
    return sol
  else:
    return -1
data = [[0 for x in range(9)] for y in range(9)]
for i in range(81):
  j=i%9
  k=i//9
  num = int(input("integer: "))
  data[k][j] = num
solution1=solve(data)
if solution1==-1:
  print(-1)
else:
  for row in solution1:
    print(solution1)