import sys
import math
import PyQt5.QtWidgets as qw
#from PyQt5.QtWidgets import QApplication

class Sudoku(qw.QWidget):

    # N x N soduku
    N = 9 

    def __init__(self):
        super().__init__();
        #the title of window
        self.title = 'SUDOKU'

        #number of row 
        self.rows = self.N

        #number of column
        self.columns = self.N

        #nunmber of row in sub_grid
        self.subgrid_r = int(math.sqrt(self.N))

        #number of column in sub_grid
        self.subgrid_c = int(math.sqrt(self.N))

        #Math representation of grid which will be a NxN matrix after initilization
        self.board = []

        #board hold a combox button for each element in N x N matrix
        self.GUI_board = []

        #read the init. matrix of sudoku game
        self.initial_configuration()

        #create the GUI for the board game
        self.initUI()

    def initUI(self):
        layout = qw.QGridLayout()

        # create a NxN matrix each element in the matrix will be a QComboBox
        for i in range(self.rows):
            gui_row = []
            for j in range(self.columns):
                combo = self.getComboBox(self.board[i][j])
                gui_row.append(combo)
            self.GUI_board.append(gui_row)

        # A nest grid layout
        for r in range(self.rows//self.subgrid_r):
            for c in range(self.columns//self.subgrid_c):
                #return a qwidget with grid layout
                subgrid = self.getSubGrid(r, c)
                #add qwidget to current grid layout
                layout.addWidget(subgrid, r, c)


        self.setGeometry(100, 100, 500, 500)
        self.setLayout(layout)
        
        self.show()

    def initial_configuration(self):
        #type the file you need to read
        filename = input('filename: ')
        
        #read the content in the file(in this case should be a matrix)
        with open(filename) as f:
            lines = f.readlines()
        
        #parse the line by line
        for line in lines:
            row = list(map(int, line.strip('\t\n ').split(' ')))
            self.board.append(row)

    #subgrid is a Qwidget which has the grid layout, each cell in the grid is a combo box
    def getSubGrid(self, r, c):
        widget = qw.QWidget()
        subgrid = qw.QGridLayout()
        for i in range(self.subgrid_r):
            for j in range(self.subgrid_c):
                subgrid.addWidget(self.GUI_board[r*self.subgrid_r + i][c*self.subgrid_c + j], i, j)
        widget.setLayout(subgrid)
        return widget


    # initial a combo box and return it
    def getComboBox(self, index):
        combo = qw.QComboBox()
        combo.addItem(' ')
        for l in range(1, self.N+1):  # Sets the possible values for the QComboBox
            combo.addItem(str(l))
        combo.setCurrentIndex(index)
        combo.activated.connect(self.modificationEvent)
        
        return combo

    def modificationEvent(self):
        for i in range(self.N):
            for j in range(self.N):
                temp_val=self.GUI_board[i][j].currentText()
                if temp_val==' ':
                    temp_val=0
                if self.board[i][j]!=int(temp_val):
                    mod_row=i
                    mod_col=j
                    mod_val=int(temp_val);
        if(self.validate(self.board,mod_row,mod_col,mod_val)):
            self.board[mod_row][mod_col]=self.GUI_board[i][j].currentText()


    def validate(self,board,i_row,i_col,i_val):
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


if __name__ == '__main__':
    app = qw.QApplication(sys.argv)
    sudoku = Sudoku()
    sys.exit(app.exec_())



