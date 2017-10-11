#include <iostream>
#include <stdlib.h>
#define DEFX 50
#define DEFY 50

void DisplayGrid(bool grid[DEFY * DEFX]);
void CopyGrid(bool grid[DEFY * DEFX], bool grid2[DEFY * DEFX]);
void Calculate(bool grid[DEFY * DEFX]);

int main()
{
    bool grid[DEFX * DEFY] = {};

    //Set Cells Here
    grid[DEFX * 6 + 5] = true;
    grid[DEFX * 5 + 6] = true;
    grid[DEFX * 6 + 8] = true;
    grid[DEFX * 6 + 6] = true;

    while(true)
    {
        DisplayGrid(grid);
        Calculate(grid);
        std::cin.get();
        system("clear");
    }

    return 0;
}


void DisplayGrid(bool grid[DEFY * DEFX])
{
    const char* cellImage[2] = { " ", "O" };

    for (int y = 0; y < DEFY; y++)
    {
        for(int x = 0; x < DEFX; x++)
        {
            std::cout << cellImage[grid[DEFX * y + x]];
        }
        std::cout << std::endl;
    }

    return;
}


void CopyGrid(bool grid[DEFY * DEFX], bool grid2[DEFY * DEFX]) //Copies grid2 to grid
{
	for (int y = 0; y < DEFY; y++)
    {
		for (int x = 0; x < DEFX; x++)
        {
			grid[DEFX * y + x] = grid2[DEFX * y + x];
        }
    }

    return;
}


void Calculate(bool grid[DEFY * DEFX])
{
	bool cGrid[DEFY * DEFX] = {};

	CopyGrid(cGrid, grid); //Copies previous grid to the current grid for calculation, we don't want to calculate while updating.

	for (int y = 0; y < DEFY; y++)
	{
		for (int x = 0; x < DEFX; x++)
		{
			int living = 0;

			for (int y0 = -1; y0 < 2; y0++) //Check Neighbors
			{
				for (int x0 = -1; x0 < 2; x0++)
				{
					if (!(y0 == false && x0 == false))
					{   //Fix ordering
						if (cGrid[DEFX * (y + y0) + (x + x0)] == true) living++; //Add to living if there are any neighbors that are alive
					}
				}
			}

			if (living < 2) grid[DEFX * y + x] = false;
			else if (living == 3) grid[DEFX * y + x] = true;
			else if (living > 3) grid[DEFX * y + x] = false;
		}
	}

    return;
}
