#include<iostream>


using namespace std;
int map[10][10] = {{1,1,1,1,1,1,1,1,1,1},
				   {1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,1,1,1,0,0,0,1},
				   {1,0,0,1,1,1,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1},
				   {1,0,0,0,0,0,0,0,0,1},
				   {1,1,1,1,1,1,1,1,1,1} };

int mapValue[10][20] ;
#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

const int DIRECTIONS[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };


int main()
{

	int start[3] = { 1,8,0 };
	int currentPoint[3];
	std::copy(std::begin(start), std::end(start), std::begin(currentPoint));
	int pathNumber = 1;
	map[currentPoint[0]][currentPoint[1]] = pathNumber;
	bool criticalPoint = true;
	
	while (criticalPoint)
	{
		bool Flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (map[currentPoint[0] + DIRECTIONS[i][0]][currentPoint[1] + DIRECTIONS[i][1]] == 0) // obstical north
			{
				if (!Flag)
				{
					pathNumber += 1;
					map[currentPoint[0] + DIRECTIONS[i][0]][currentPoint[1] + DIRECTIONS[i][1]] = pathNumber;
					currentPoint[0] += DIRECTIONS[i][0];
					currentPoint[1] += DIRECTIONS[i][1];
					Flag = true;
					criticalPoint = true;
				}
			}
			if (!Flag)
			{
				criticalPoint = false;
				//for (int y = 0; y < 10; y++)
				//{
				//	for (int x = 0; x < 10; x++)
				//	{
				//		if (map[y][x] == 0)
				//		{
				//			currentPoint[1] = x;
				//			currentPoint[0] = y;
				//			criticalPoint = true;
				//		}
				//	}
				//}
			}
		}
		//if (map[currentPoint[0] + 1][currentPoint[1]] == 0) // obstical north
		//{
		//	pathNumber += 1;
		//	map[currentPoint[0]+1][currentPoint[1]] = pathNumber;
		//	currentPoint[0] += 1;
		//}
		//else if (map[currentPoint[0] - 1][currentPoint[1]] == 0) // west
		//{
		//	pathNumber += 1;
		//	map[currentPoint[0] - 1][currentPoint[1]] = pathNumber;
		//	currentPoint[0] -= 1;
		//}
		//else if (map[currentPoint[0]][currentPoint[1] + 1] == 0) // south
		//{
		//	pathNumber += 1;
		//	map[currentPoint[0]][currentPoint[1] + 1] = pathNumber;
		//	currentPoint[1] += 1;
		//}
		//else if (map[currentPoint[0]][currentPoint[1] - 1] == 0) // east
		//{
		//	pathNumber += 1;
		//	map[currentPoint[0]][currentPoint[1] - 1] = pathNumber;
		//	currentPoint[1] -= 1;
		//}
		//else {
		//	criticalPoint = false;
		//}
		

		//for (int y = 0; y < 10; y++)
		//{
		//	for (int x = 0; x < 10; x++)
		//	{
		//		std::cout << map[y][x] << "\t";
		//	}
		//	std::cout << std::endl;
		//}
		//std::cout << std::endl;
	}

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			std::cout << map[y][x] << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}