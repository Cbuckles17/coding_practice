#include <stdio.h> 
#include <stdlib.h> 
#include "lib/grid_node.h"

int robotgrid(int **grid, int row, int col, Grid_Node **path)
{
	if(row == 0 && col == 0)
	{
		//printf("Reached the end at: (%d,%d)\n", row, col);
		pushNewHead(path, row, col);
		return 0;
	}
	else if(row < 0 || col < 0 || grid[row][col] == 1)
	{
		//printf("Went Out of Bonds or a No Zone: (%d,%d)\n", row, col);
		return 1;
	}

	int up = robotgrid(grid, row - 1, col, path);
	if(up == 0)
	{
		//printf("Adding to Path: (%d,%d)\n", row, col);
		pushNewHead(path, row, col);
		return 0;
	}

	int left = robotgrid(grid, row, col - 1, path);
	if(left == 0)
	{
		//printf("Adding to Path: (%d,%d)\n", row, col);
		pushNewHead(path, row, col);
		return 0;
	}

	//if you get here it means neither returned 0
	//so set the value to 1 so we can't go here again
	printf("Marking (%d,%d) as a No Zone\n", row, col);
	grid[row][col] = 1;
	return 1;
}

void robotgrid_helper(int **grid, int row, int col)
{
	Grid_Node *path = NULL;

	//return;

	if(robotgrid(grid, row, col, &path) == 0)
	{
		printf("Path found: ");
		printList(path);
	}
	else
	{
		printf("There was no path found for this grid\n");
	}
}

//--------------------------------//
//------------MAIN----------------//
//--------------------------------//

//run with:
//gcc -o build/robot_grid robot_grid.c lib/grid_node.c
//./build/robot_grid

int main()
{	
	int i = 0;

	int row1 = 1;
	int col1 = 1;
	int **grid1 = (int **)calloc(row1, sizeof(int *));
	for (i = 0; i < row1; i++)
	{
		grid1[i] = (int *)calloc(col1, sizeof(int));
	}
	grid1[0][0] = 0;

	/*
	[
		[0]
	]
	*/

	robotgrid_helper(grid1, row1 - 1, col1 - 1);
	printf("--------\n");

	int row2 = 1;
	int col2 = 2;
	int **grid2 = (int **)calloc(row2, sizeof(int *));
	for (i = 0; i < row2; i++)
	{
		grid2[i] = (int *)calloc(col2, sizeof(int));
	}
	grid2[0][0] = 0;
	grid2[0][1] = 0;

	/*
	[
		[0, 0]
	]
	*/

	robotgrid_helper(grid2, row2 - 1, col2 - 1);
	printf("--------\n");

	// int grid3[2][1] = 
	// {
	// 	{0}, 
	// 	{0}
	// };

	int row3 = 2;
	int col3 = 1;
	int **grid3 = (int **)calloc(row3, sizeof(int *));
	for (i = 0; i < row3; i++)
	{
		grid3[i] = (int *)calloc(col3, sizeof(int));
	}
	grid3[0][0] = 0;
	grid3[1][0] = 0;

	/*
	[
		[0, 0]
	]
	*/

	robotgrid_helper(grid3, row3 - 1, col3 - 1);
	printf("--------\n");

	int row4 = 2;
	int col4 = 2;
	int **grid4 = (int **)calloc(row4, sizeof(int *));
	for (i = 0; i < row4; i++)
	{
		grid4[i] = (int *)calloc(col4, sizeof(int));
	}
	grid4[0][0] = 0;
	grid4[0][1] = 1;
	grid4[1][0] = 0;
	grid4[1][1] = 0;

	/*
	[
		[0, 1],
		[0, 0]
	]
	*/

	robotgrid_helper(grid4, row4 - 1, col4 - 1);
	printf("--------\n");

	int row5 = 2;
	int col5 = 2;
	int **grid5 = (int **)calloc(row5, sizeof(int *));
	for (i = 0; i < row5; i++)
	{
		grid5[i] = (int *)calloc(col5, sizeof(int));
	}
	grid5[0][0] = 0;
	grid5[0][1] = 1;
	grid5[1][0] = 1;
	grid5[1][1] = 0;

	/*
	[
		[0, 1],
		[1, 0]
	]
	*/

	robotgrid_helper(grid5, row5 - 1, col5 - 1);
	printf("--------\n");

	int row6 = 5;
	int col6 = 5;
	int **grid6 = (int **)calloc(row6, sizeof(int *));
	for (i = 0; i < row6; i++)
	{
		grid6[i] = (int *)calloc(col6, sizeof(int));
	}
	grid6[0][0] = 0;
	grid6[0][1] = 1;
	grid6[0][2] = 0;
	grid6[0][3] = 0;
	grid6[0][4] = 0;

	grid6[1][0] = 0;
	grid6[1][1] = 0;
	grid6[1][2] = 1;
	grid6[1][3] = 0;
	grid6[1][4] = 0;

	grid6[2][0] = 1;
	grid6[2][1] = 0;
	grid6[2][2] = 0;
	grid6[2][3] = 1;
	grid6[2][4] = 0;

	grid6[3][0] = 0;
	grid6[3][1] = 1;
	grid6[3][2] = 0;
	grid6[3][3] = 0;
	grid6[3][4] = 1;

	grid6[4][0] = 0;
	grid6[4][1] = 0;
	grid6[4][2] = 1;
	grid6[4][3] = 0;
	grid6[4][4] = 0;

	/*
	[
		[0, 1, 0, 0, 0],
		[0, 0, 1, 0, 0],
		[1, 0, 0, 1, 0],
		[0, 1, 0, 0, 1],
		[0, 0, 1, 0, 0],
	]
	*/

	robotgrid_helper(grid6, row6 - 1, col6 - 1);
	printf("--------\n");

	int row7 = 5;
	int col7 = 5;
	int **grid7 = (int **)calloc(row7, sizeof(int *));
	for (i = 0; i < row7; i++)
	{
		grid7[i] = (int *)calloc(col7, sizeof(int));
	}
	grid7[0][0] = 0;
	grid7[0][1] = 1;
	grid7[0][2] = 0;
	grid7[0][3] = 0;
	grid7[0][4] = 0;

	grid7[1][0] = 0;
	grid7[1][1] = 0;
	grid7[1][2] = 1;
	grid7[1][3] = 1;
	grid7[1][4] = 0;

	grid7[2][0] = 1;
	grid7[2][1] = 0;
	grid7[2][2] = 1;
	grid7[2][3] = 1;
	grid7[2][4] = 1;

	grid7[3][0] = 0;
	grid7[3][1] = 0;
	grid7[3][2] = 1;
	grid7[3][3] = 0;
	grid7[3][4] = 0;

	grid7[4][0] = 0;
	grid7[4][1] = 0;
	grid7[4][2] = 0;
	grid7[4][3] = 0;
	grid7[4][4] = 0;

	/*
	[
		[0, 1, 0, 0, 0],
		[0, 0, 1, 1, 0],
		[1, 0, 1, 1, 1],
		[0, 0, 1, 0, 0],
		[0, 0, 0, 0, 0],
	]
	*/

	robotgrid_helper(grid7, row7 - 1, col7 - 1);
	printf("--------\n");

	int row8 = 5;
	int col8 = 5;
	int **grid8 = (int **)calloc(row8, sizeof(int *));
	for (i = 0; i < row8; i++)
	{
		grid8[i] = (int *)calloc(col8, sizeof(int));
	}
	grid8[0][0] = 0;
	grid8[0][1] = 0;
	grid8[0][2] = 0;
	grid8[0][3] = 0;
	grid8[0][4] = 0;

	grid8[1][0] = 0;
	grid8[1][1] = 0;
	grid8[1][2] = 0;
	grid8[1][3] = 0;
	grid8[1][4] = 0;

	grid8[2][0] = 0;
	grid8[2][1] = 0;
	grid8[2][2] = 0;
	grid8[2][3] = 0;
	grid8[2][4] = 0;

	grid8[3][0] = 0;
	grid8[3][1] = 0;
	grid8[3][2] = 0;
	grid8[3][3] = 0;
	grid8[3][4] = 0;

	grid8[4][0] = 0;
	grid8[4][1] = 0;
	grid8[4][2] = 0;
	grid8[4][3] = 0;
	grid8[4][4] = 0;

	/*
	[
		[0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0],
		[0, 0, 0, 0, 0],
	]
	*/

	robotgrid_helper(grid8, row8 - 1, col8 - 1);
	printf("--------\n");

	return 0;
}