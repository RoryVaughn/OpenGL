#include <iostream>
using namespace std;
int main()
{
	int Vector4[4] = { 5,3,2,1 };
	int mat[16] = { 1,0,0,0,
					 0,1,0,0,
					 0,0,1,0,
				     0,0,0,1};
	int mat3[16];

	mat3[0] = (mat[0]);
	mat3[1] = (mat[1]);
	mat3[2] = (mat[2]);
	mat3[3] = ((mat[0] * Vector4[0]) + (mat[1] * Vector4[1]) + (mat[2] * Vector4[2]) + (mat[3] * Vector4[3]));
	mat3[4] = (mat[4]);
	mat3[5] = (mat[5]);
	mat3[6] = (mat[6]);
	mat3[7] = ((mat[4] * Vector4[0]) + (mat[5] * Vector4[1]) + (mat[6] * Vector4[2]) + (mat[7] * Vector4[3]));
	mat3[8] = (mat[8]);
	mat3[9] = (mat[9]);
	mat3[10] = (mat[10]);
	mat3[11] = ((mat[8] * Vector4[0]) + (mat[9] * Vector4[1]) + (mat[10] * Vector4[2]) + (mat[11] * Vector4[3]));
	mat3[12] = (mat[12]);
	mat3[13] = (mat[13]);
	mat3[14] = (mat[14]);
	mat3[15] = ((mat[12] * Vector4[0]) + (mat[13] * Vector4[1]) + (mat[14] * Vector4[2]) + (mat[15] * Vector4[3]));

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

	system("pause");
	return 0;
}