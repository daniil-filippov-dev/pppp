#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int inputMatrixParamSize(int matrixNumber, string textParam)
{
	/*Ввод размеров матрицы пользователем*/
	int paramMatrix;
	do
	{
		cout << "Введите размер " << textParam << " " << matrixNumber << " матрицы\n";
		cin >> paramMatrix;
	} while (paramMatrix <= 0);
	return paramMatrix;
}
int** initialMatrix(int columnMatrix, int rowMatrix)
{
	/*Инициализация массива*/
	int** M = new int* [columnMatrix];
	for (int i = 0; i < columnMatrix; i++)
		M[i] = new int[rowMatrix];
	return M;
}
int choiceFillingMethod()
{
	/*Выбор способа заполнения матриц*/
	int fillingMethod;
	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> fillingMethod;
	} while (fillingMethod < 1 || fillingMethod > 2);
	return fillingMethod;
}
void printMatrix(int columnMatrix, int rowMatrix, int** M)
{
	/*Вывод матрицы в консоль*/
	for (int i = 0; i < columnMatrix; i++)
	{
		for (int j = 0; j < rowMatrix; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}
int** fillingMatrix(int fillingMethod, int columnMatrix, int rowMatrix, int** M, int matrixNumber)
{
	/*Заполнение матриц по выборанному способу*/
	switch (fillingMethod)
	{
	case 1:
		for (int i = 0; i < columnMatrix; i++)
			for (int j = 0; j < rowMatrix; j++)
				cin >> M[i][j];
		cout << "\nМатрица " << matrixNumber << "\n\n";
		printMatrix(columnMatrix, rowMatrix, M);
		break;
	case 2:
		for (int i = 0; i < columnMatrix; i++)
			for (int j = 0; j < rowMatrix; j++)
				M[i][j] = rand() % 10;
		cout << "\nМатрица " << matrixNumber << "\n\n";
		printMatrix(columnMatrix, rowMatrix, M);
		break;
	}
	return  M;
}
int** zeroMatrix( int sizeReduceMatrix, int** M )
{
	/*Заполнение квадратной матрицы нулями*/
	for (int i = 0; i < sizeReduceMatrix; i++)
	{
		M[i] = new int[sizeReduceMatrix];
		for (int j = 0; j < sizeReduceMatrix; j++)
			M[i][j] = 0;
	}
	return  M;
}
int** copyMatrix(int columnMatrix, int rowMatrix, int** MResult, int** MCopy)
{
	/*Копирование ячеек матрицы */
	for (int i = 0; i < columnMatrix; i++)
	{
		for (int j = 0; j < rowMatrix; j++)
			MResult[i][j] = MCopy[i][j];
	}
	return MResult;
}

void main()
{
	srand(time(NULL));
	int columnMatrix1, rowMatrix1, columnMatrix2, rowMatrix2, fillingMethod, sizeReduceMatrix = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	columnMatrix1 = inputMatrixParamSize(1, "столбца");
	rowMatrix1 = inputMatrixParamSize(1, "строки");
	columnMatrix2 = inputMatrixParamSize(2, "столбца");
	rowMatrix2 = inputMatrixParamSize(2, "строки");
	int** M1 = initialMatrix(columnMatrix1, rowMatrix1);
	int** M2 = initialMatrix(columnMatrix2, rowMatrix2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	fillingMethod = choiceFillingMethod();
	M1 = fillingMatrix( fillingMethod, columnMatrix1, rowMatrix1, M1, 1);
	M2 = fillingMatrix(fillingMethod, columnMatrix2, rowMatrix2, M2, 2);

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (sizeReduceMatrix < columnMatrix1 || sizeReduceMatrix < columnMatrix2 || sizeReduceMatrix < rowMatrix1 || sizeReduceMatrix < rowMatrix2)
		sizeReduceMatrix *= 2;

	int** M3 = initialMatrix(sizeReduceMatrix, sizeReduceMatrix);
	M3 = zeroMatrix(sizeReduceMatrix, M3);
	int** M4 = initialMatrix(sizeReduceMatrix, sizeReduceMatrix);
	M4 = zeroMatrix(sizeReduceMatrix, M4);
	copyMatrix(columnMatrix1, rowMatrix1, M3, M1);
	copyMatrix(columnMatrix2, rowMatrix2, M4, M2);
	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	printMatrix(sizeReduceMatrix, sizeReduceMatrix, M3);
	cout << "\nМатрица 2\n\n";
	printMatrix(sizeReduceMatrix, sizeReduceMatrix, M4);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int sizeReduceMatrix2 = sizeReduceMatrix / 2;

	int** mat1 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	copyMatrix(sizeReduceMatrix2, sizeReduceMatrix2, mat1, M3);
	int** mat2 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
			mat2[i][j] = M3[i][j + sizeReduceMatrix2];
	}
	int** mat3 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
			mat3[i][j] = M3[i + sizeReduceMatrix2][j];
	}
	int** mat4 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
			mat4[i][j] = M3[i + sizeReduceMatrix2][j + sizeReduceMatrix2];
	}
	int** mat5 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	copyMatrix(sizeReduceMatrix2, sizeReduceMatrix2, mat5, M4);
	int** mat6 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
			mat6[i][j] = M4[i][j + sizeReduceMatrix2];
	}
	int** mat7 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
			mat7[i][j] = M4[i + sizeReduceMatrix2][j];
	}
	int** mat8 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
			mat8[i][j] = M4[i + sizeReduceMatrix2][j + sizeReduceMatrix2];
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** p1 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** p2 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** p3 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** p4 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** p5 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** p6 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** p7 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
		{
			p1[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);
			}

			p2[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];
			}

			p3[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);
			}

			p4[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);
			}

			p5[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];
			}

			p6[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);
			}

			p7[i][j] = 0;
			for (int z = 0; z < sizeReduceMatrix2; z++)
			{
				p7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat9 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** mat10 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** mat11 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);
	int** mat12 = initialMatrix(sizeReduceMatrix2, sizeReduceMatrix2);

	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
		{
			mat9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
			mat10[i][j] = p3[i][j] + p5[i][j];
			mat11[i][j] = p2[i][j] + p4[i][j];
			mat12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = initialMatrix(sizeReduceMatrix, sizeReduceMatrix);

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		for (int j = 0; j < sizeReduceMatrix2; j++)
		{
			M5[i][j] = mat9[i][j];
			M5[i][j + sizeReduceMatrix2] = mat10[i][j];
			M5[i + sizeReduceMatrix2][j] = mat11[i][j];
			M5[i + sizeReduceMatrix2][j + sizeReduceMatrix2] = mat12[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	for (int i = 0; i < sizeReduceMatrix; i++)
	{
		x = 0;
		for (int j = 0; j < sizeReduceMatrix; j++)
		{
			if (M5[i][j] != 0)
			{
				x++;
				f = 100;
			}
		}
		if (x == 0 && i < f)
		{
			f = i;
		}
	}
	for (int i = 0; i < sizeReduceMatrix; i++)
	{
		x = 0;
		for (int j = 0; j < sizeReduceMatrix; j++)
		{
			if (M5[j][i] != 0)
			{
				x++;
				s = 100;
			}
		}
		if (x == 0 && i < s)
		{
			s = i;
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	printMatrix(f, s, M5);
	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < columnMatrix1; i++)
		delete[] M1[i];
	for (int i = 0; i < columnMatrix2; i++)
		delete[] M2[i];
	for (int i = 0; i < sizeReduceMatrix; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}
	for (int i = 0; i < sizeReduceMatrix2; i++)
	{
		delete[] mat1[i];
		delete[] mat2[i];
		delete[] mat3[i];
		delete[] mat4[i];
		delete[] mat5[i];
		delete[] mat6[i];
		delete[] mat7[i];
		delete[] mat8[i];
		delete[] mat9[i];
		delete[] mat10[i];
		delete[] mat11[i];
		delete[] mat12[i];
		delete[] p1[i];
		delete[] p2[i];
		delete[] p3[i];
		delete[] p4[i];
		delete[] p5[i];
		delete[] p6[i];
		delete[] p7[i];
	}
	delete[] M1, M2, M3, M4, M5;
	delete[] mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10, mat11, mat12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}