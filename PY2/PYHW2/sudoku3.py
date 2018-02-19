def validate(board,i_row,i_col,i_val):
    if(i_val is not 0): 
        for j in range(len(board)):
            if(board[i_row][j]==i_val):
                print('Number ',i_val,' twice in row')
                return False;
        for j in range(len(board)):
            if(board[j][i_col]==i_val):
                print('Number ',i_val,' twice in column')
                return False;
        sub_row=i_row-i_row%3
        sub_col=i_col-i_col%3
        p=sub_row
        q=sub_col
        for p in range(3):
            for q in range(3):
                if board[p][q]==i_val:
                    print('Number ',i_val,' twice in subgrid')
                    return False
    return True

           
lines = []
board = []
#type the file you need to read
filename = input('filename: ')
        
#read the content in the file(in this case should be a matrix)
with open(filename) as f:
    lines = f.readlines()
#parse the line by line
for line in lines:
    row = list(map(int, line.strip('\t\n ').split(' ')))
    board.append(row)

i_row=int(input("Enter row: "))
i_col =int(input("Enter column: "))
i_val=int(input("Enter number: "))

if(validate(board,i_row,i_col,i_val)):
    board[i_row][i_col]=i_val
for i in board:
    print(*i)


