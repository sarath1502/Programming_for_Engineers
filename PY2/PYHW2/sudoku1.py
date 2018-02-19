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

for i in board:
    print(*i)