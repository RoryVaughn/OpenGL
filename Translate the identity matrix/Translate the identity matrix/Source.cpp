#include <iostream>
using namespace std;
int Vector4[4] = { 5,3,2,1 };
int mat[16] = { 1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1 };

int mat3[16];

	bool print()
	{
		cout << mat3[0] << ",";
		cout << mat3[1] << ",";
		cout << mat3[2] << ",";
		cout << mat3[3] << ",";
		cout << endl;
		cout << mat3[4] << ",";
		cout << mat3[5] << ",";
		cout << mat3[6] << ",";
		cout << mat3[7] << ",";
		cout << endl;
		cout << mat3[8] << ",";
		cout << mat3[9] << ",";
		cout << mat3[10] << ",";
		cout << mat3[11] << ",";
		cout << endl;
		cout << mat3[12] << ",";
		cout << mat3[13] << ",";
		cout << mat3[14] << ",";
		cout << mat3[15] << ",";
		cout << endl;
		cout << endl;
		return true;
	}
bool MoveMatrix() //this function moves the position of the object that correlates with this matrix.
	{
		mat3[0] = (mat[0]);
		mat3[1] = (mat[1]);
		mat3[2] = (mat[2]);
		mat3[3] = ((mat[0] * Vector4[0]) + (mat[1] * Vector4[1]) + (mat[2] * Vector4[2]) + (mat[3] * Vector4[3]));//this correlates with the X value of the position of the object.
		mat3[4] = (mat[4]);
		mat3[5] = (mat[5]);
		mat3[6] = (mat[6]);
		mat3[7] = ((mat[4] * Vector4[0]) + (mat[5] * Vector4[1]) + (mat[6] * Vector4[2]) + (mat[7] * Vector4[3]));//this correlates with the y value of the position of the object.
		mat3[8] = (mat[8]);
		mat3[9] = (mat[9]);
		mat3[10] = (mat[10]);
		mat3[11] = ((mat[8] * Vector4[0]) + (mat[9] * Vector4[1]) + (mat[10] * Vector4[2]) + (mat[11] * Vector4[3]));//this correlates with the z value of the position of the object.
		mat3[12] = (mat[12]);
		mat3[13] = (mat[13]);
		mat3[14] = (mat[14]);
		mat3[15] = ((mat[12] * Vector4[0]) + (mat[13] * Vector4[1]) + (mat[14] * Vector4[2]) + (mat[15] * Vector4[3]));//this value matters but doesnt correlate with a specific coordinate plane.
		print();
		return true;
	}


	bool RotateMatrixX() //this function can be used to rotate the two given matrices by a certain axis.
	{
		mat3[0] = mat[0];
		mat3[1] = mat[1];
		mat3[2] = mat[2];
		mat3[3] = mat[3];
		mat3[4] = mat[4];
		mat3[5] = cos(mat[5]);
		mat3[6] = -sin(mat[6]);
		mat3[7] = mat[7];
		mat3[8] = mat[8];
		mat3[9] = cos(mat[9]);
		mat3[10] = -sin(mat[10]);
		mat3[11] = mat[11];
		mat3[12] = mat[12];
		mat3[13] = mat[13];
		mat3[14] = mat[14];
		mat3[15] = mat[15];
		print();
		return true;
	}
	bool RotateMatrixY() //this function can be used to rotate the two given matrices by a certain axis.
	{
		mat3[0] = cos(mat[0]);
		mat3[1] = mat[1];
		mat3[2] = sin(mat[2]);
		mat3[3] = mat[3];
		mat3[4] = mat[4];
		mat3[5] = mat[5];
		mat3[6] = mat[6];
		mat3[7] = mat[7];
		mat3[8] = -sin(mat[8]);
		mat3[9] = mat[9];
		mat3[10] = cos(mat[10]);
		mat3[11] = mat[11];
		mat3[12] = mat[12];
		mat3[13] = mat[13];
		mat3[14] = mat[14];
		mat3[15] = mat[15];
		print();
		return true;
	}
	bool RotateMatrixZ() //this function can be used to rotate the two given matrices by a certain axis.
	{
		mat3[0] = cos(mat[0]);
		mat3[1] = -sin(mat[1]);
		mat3[2] = mat[2];
		mat3[3] = mat[3];
		mat3[4] = sin(mat[4]);
		mat3[5] = cos(mat[5]);
		mat3[6] = mat[6];
		mat3[7] = mat[7];
		mat3[8] = mat[8];
		mat3[9] = mat[9];
		mat3[10] = mat[10];
		mat3[11] = mat[11];
		mat3[12] = mat[12];
		mat3[13] = mat[13];
		mat3[14] = mat[14];
		mat3[15] = mat[15];
		print();
		return true;
	}
	bool ScaleMatrix() //this function can be used to scale a matrix given a scalar value;
	{
		int scalar = 2;
		mat3[0] = mat[0] * scalar;
		mat3[1] = (mat[1]);
		mat3[2] = (mat[2]);
		mat3[3] = (mat[3]);
		mat3[4] = (mat[4]);
		mat3[5] = mat[5] * scalar;
		mat3[6] = (mat[6]);
		mat3[7] = (mat[7]);
		mat3[8] = (mat[8]);
		mat3[9] = (mat[9]);
		mat3[10] = mat[10] * scalar;
		mat3[11] = (mat[11]);
		mat3[12] = (mat[12]);
		mat3[13] = (mat[13]);
		mat3[14] = (mat[14]);
		mat3[15] = mat[15] * scalar;
		print();
		return true;
	}


int main()
{
	MoveMatrix();
	ScaleMatrix();
	RotateMatrixX();
	RotateMatrixY();
	RotateMatrixZ();
	system("pause");	
	return 0;
}