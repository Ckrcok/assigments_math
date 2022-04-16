#include "Mat3.h"

/* Matrix Constructor
	Set matrix entries to the identity matrix */
Mat3::Mat3()
{
	SetIdentity();
}

/* SetIdentity Member Function
	Set matrix entries to the identity matrix */
void Mat3::SetIdentity()
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = m[i] + 1;
	}

}

/* RotateZ Member Function
	Set matrix entries to the rotation matrix */
void Mat3::RotateZ(float angle)
{
	for (int i = 0; i < 9; i++) {
		if (i == 0 ) {
			m[i] = cos(angle);
		}
		else if (i == 1) {
			m[i] = -1 * sin(angle);
		}else if (i == 3) {
			m[i] = sin(angle);
		}else if (i == 4) {
			m[i] = cos(angle);
		}
	}
}

/* Scale Member Function
	Set matrix entries to the scale matrix */
void Mat3::Scale(float x, float y, float z)
{
	for (int i = 0; i < 9; i++) {
		if (i == 0) {
			m[i] = x ;
		}
		else if (i == 4) {
			m[i] = y;
		}
		else if (i == 8) {
			m[i] = z;
		}else
		{
			m[i] = 0;
		}
	}
}

/* Transpose Member Function
	Set matrix entries to the transpose matrix */
void Mat3::Transpose()
{
	float m_1 = m[1];
	float m_3 = m[3];
	for (int i = 0; i < 9; i++) {
		if (i == 1) {
			m[i] = m_3;
		}
		else if(i == 3) {
			m[i] = m_1;
		}
	}
}

/* Multiplication Member Function
	Calculate the multiplication of two matrices and return the result */
Mat3 Mat3::operator*(Mat3 otherMat) 
{
	Mat3 result;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			result.m[i * 3 + j] = (m[0 * 3 + j] * otherMat.m[i * 3 + 0]) + (m[1 * 3 + j] * otherMat.m[i * 3 + 1]) + (m[2 * 3 + j] * otherMat.m[i * 3 + 2]);
		}
	}
	return result;
}

/* Matrix and Vector Multiplication Member Function
	Calculate the multiplication of a matrix and vector, and return the result */
Vec3 Mat3::operator*(Vec3 vector)
{
	Vec3 results;
	 results.x = vector.x * m[0] + vector.y * m[4] + vector.z * m[8] + 1.0f * m[12];
	 results.y = vector.x * m[1] + vector.y * m[5] + vector.z * m[9] + 1.0f * m[13];
	 results.z = vector.x * m[2] + vector.y * m[6] + vector.z * m[10] + 1.0f * m[14];
	
	return results;

}

/* Determinant Member Function
	Calculate the determinant of a matrix */
float Mat3::Det()
{	/*Determinant - lesson 8 slide 9*/
	float Det_;
	Det_ = m[0] * (m[4] * m[8] - m[5] * m[7]) - m[1] * (m[3] * m[8] - m[5] * m[6]) + m[2] * (m[3] * m[7] - m[4] * m[6]);
	return Det_;
}

/* Inverse Member Function
	Calculate the inverse matrix */
void Mat3::Inverse()
{
	
	 int a = m[0];
	 int b = m[1];
	 int c = m[2];
	 int d = m[3];
	 int e = m[4];
	 int f = m[5];
	 int g = m[6];
	 int h = m[7];
	 int i = m[8];

	//Inverse Matrix - lesson 8 slide 17
	 m[0] = ((e * i) - (f * h));
	 m[1] = ((c * h) - (b * i));
	 m[2] = ((b * f) - (c * e));
	 m[3] = ((f * g) - (d * i));
	 m[4] = ((a * i) - (c * g));
	 m[5] = ((c * d) - (a * f));
	 m[6] = ((d * h) - (e * g));
	 m[7] = ((b * g) - (a * h));
	 m[8] = ((a * e) - (b * d));
	 
}


