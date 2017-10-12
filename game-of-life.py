#Input cell pattern, the one below is the R-Pentomino
main_grid = [
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
]


#Display method
def display(grid):
    for y, row_con in enumerate(grid):
        for x, cell in enumerate(row_con): #col is the current coordinate of x and cell is the current item being iterated over
            if cell == 1:
                print "O",
            else:
                print ".",
        print "\n"


#Calculates the states of the cells
def calculate(grid):
    calc_grid = [row[:] for row in grid] #Copies current grid to the grid we will calculate, we don't want to update as it goes.

    for y, row_con in enumerate(calc_grid): #Loop over grid
        for x, cell in enumerate(row_con):
            living = 0

            for y0 in [-1, 0, 1]: #Checks the amount of living neighbors
                for x0 in [-1, 0, 1]:
                    if not y0 == x0 == 0:
                        try:
                            if calc_grid[y + y0][x + x0] == 1:
                                living += 1
                        except IndexError:
                            pass

            #Determines the state of the current cell being iterated over
            if living < 2: grid[y][x] = 0
            elif living == 3: grid[y][x] = 1
            elif living > 3: grid[y][x] = 0

while True:
    display(main_grid) #display
    calculate(main_grid) #calculate
    raw_input()
