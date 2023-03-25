#include <iostream>

/*

	ITEAHometask4.

	Image number 19.
	* - * - * - * > *
	|
	* - * - * - * - *
					|
	* - * - * - * - *
	|
	* - * - * - * - *
					|
	* - * - * - * - *

	Implement the program which allows to work with a two-dimensional array,
	receiving the dimension from the console, and filling with elements
	occurs according to the algorithm.

*/

int** AllocateMemoryForMatrix(int countOfRows, int countOfColumns);
int** FreeToMemory(int** matrix, int countOfRow);

void ShowMatrix(int** matrix, int rows, int columns);
void InitializeMatrix(int** matrix, int rows, int columns);

int main()
{
	int countOfRows{}, countOfColumns{};

	int** matrix{ 0 };

	std::cout << "Input count of rows for matrix: ";
	std::cin >> countOfRows;

	std::cout << "Input count of columns for matrix: ";
	std::cin >> countOfColumns;

	matrix = AllocateMemoryForMatrix(countOfRows, countOfColumns);

	InitializeMatrix(matrix, countOfRows, countOfColumns);
	ShowMatrix(matrix, countOfRows, countOfColumns);

	FreeToMemory(matrix, countOfRows);

	return 0;
}

void InitializeMatrix(int** matrix, int countOfRows, int countOfColumns)
{
	int k{ 1 };

	for (int indexRow{ countOfRows - 1 }; indexRow >= 0; indexRow--)
	{
		if (indexRow % 2 == 0)
		{
			for (int indexColumn{ 0 }; indexColumn < countOfColumns; indexColumn++)
			{
				matrix[indexRow][indexColumn] = k;
				k++;
			}
		}
		else
		{
			for (int indexColumn{ countOfColumns - 1 }; indexColumn >= 0; indexColumn--)
			{
				matrix[indexRow][indexColumn] = k;
				k++;
			}
		}
	}

	std::cout << std::endl;
}

void ShowMatrix(int** matrix, int countOfRows, int countOfColumns)
{
	for (int indexRow{ 0 }; indexRow < countOfRows; indexRow++)
	{
		for (int indexColumn{ 0 }; indexColumn < countOfColumns; indexColumn++)
		{
			std::cout << matrix[indexRow][indexColumn] << "\t";
		}

		std::cout << std::endl << std::endl;
	}
}

int** AllocateMemoryForMatrix(int countOfRows, int countOfColumns)
{
	int** matrix = new int* [countOfRows] {};

	for (int index{ 0 }; index < countOfRows; index++)
		matrix[index] = new int[countOfColumns] {};

	return matrix;
}

int** FreeToMemory(int** matrix, int countOfRow)
{
	for (int index{ 0 }; index < countOfRow; index++)
		delete[] matrix[index];

	delete[] matrix;
	matrix = 0;

	return matrix;
}
