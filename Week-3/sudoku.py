sudoku = [[0 for x in range(9)] for y in range(9)]
for i in range(81):
  j=i%9
  k=i//9
  num = int(input())
  sudoku[k][j] = num
#for a solved sudoku, each line should sum upto the same number, no number in each line should repeat and no number in each 3x3 square should repeat
#first we define a function which tells if a number 'r' is valid at the vacant position (x,y) where x=row no. and y=col no.
#this approach doesnot require z3
def valid(r,x,y):
  global sudoku
#row valid
  for i in range(0,9):
    if sudoku[i][x]==r:
      return False
#column valid
  for j in range(0,9):
    if sudoku[y][j]==r:
      return False
#square valid
  row_quo=x//3
  col_quo=y//3
  row_fir=row_quo*3
  col_fir=col_quo*3
  for i in range(0,3):
    for j in range(0,3):
      if sudoku[j+col_fir][i+row_fir]==r:
        return False
  return True
def solve():
  global sudoku
  for x in range(0,9):
    for y in range(0,9):
      for r in range(1,10):
        if valid(r,x,y):
          sudoku[y][x]=r
          solve()
          sudoku[y][x]=0
      return
  print(sudoku)
  solve()