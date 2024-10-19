#ifndef HeaderH
#define HeaderH
#endif

// ����������

#include <graphics.hpp>
#include <math.hpp>
#include <math.h>
#include <fstream>
#include <vector>
#include <Forms.hpp>
#include <vcl.h>


#pragma resource "Splash.res"

using namespace std;

/*----------------------------------------------------------------------------*/
/*                           ���������� ��������                              */

// ��� �������
typedef vector<double> TVector;

// ��������� �����
typedef struct
{
   double X;
   double Y;
   double Z;
}  T3DPoint;

// ��������� �������
typedef struct
{
   T3DPoint Point;
   T3DPoint Normal;
   TColor Color;
}  TVertex;

// ��������� �����
typedef struct
{
   int A;
   int B;
   int C;
}  TFace;

// ������
typedef struct
{
   double Alpha;
   double Beta;
}  TCamera;

// �������� �����
typedef struct
{
   T3DPoint Point;
   TColor Color;

}  TLight;

// ������
typedef struct
{
   vector<TVertex> Vertices;
   vector<TFace> Faces;

   int NumVertex;
   int NumFaces;

   TColor Color;

}  TModel;

// �����
typedef struct
{
   char * FileName;

   vector <TModel> Models;
   vector <TLight> Light;

   TCamera  Camera;

   T3DPoint Move;
   T3DPoint Scale;
   T3DPoint Rotate;

   double Ka;
   double Kd;
   double Ks;

   int Hour;
   int Min;
   int Sec;

   bool Clock;

}  TScene;

/*----------------------------------------------------------------------------*/
/*                     �������� � ������������� �����                         */

// ������������� �����
void InitScene(TScene &Scene);

/*----------------------------------------------------------------------------*/
/*                      ������ ��� ������ � ���������                         */

// �������� ������-������
T3DPoint Vector(T3DPoint Start, T3DPoint Final);

// ��������� ������������
double ScalarProduct(T3DPoint A, T3DPoint B);

/*----------------------------------------------------------------------------*/
/*                      ������ ��� ������ � ���������                         */

// ��������� ������� �� �������
TVector Multiply(TVector Vector);

// ���������� ������� �����������
void InitMove(double dx, double dy, double dz);

// ���������� ������� ���������������
void InitScale(double kx, double ky, double kz);

// ���������� ������� ��������
void InitRotate(double Angle, char Axis);

// ���������� ������� �������������� ���������
void InitTransform(double Alpha, double Beta);

// ���������� ��������� �� �������
T3DPoint GetPoint(TVector Vector, bool Integer = False);

// ��������� ��������� � �������
TVector PutPoint(T3DPoint Point);

/*----------------------------------------------------------------------------*/
/*                              ��������������                                */

// ��������
void Projection(TScene &Scene);

// �����������
void Move(TModel &Model, double dx, double dy, double dz);

// ���������������
void Scale(TModel &Model, double kx, double ky, double kz);

// �������
void Rotate(TModel &Model, double X, double Y, double Z);

/*----------------------------------------------------------------------------*/
/*                          ������� ���������                                 */

// ������������� ������
void InitScreen(TCanvas * Source, int Width, int Height);

// ���������� �����
void DrawScene(TScene Scene);

// ���������� ����������
void DrawSphere(TColor Start, TColor Final);

/*----------------------------------------------------------------------------*/
/*                        ��������������� �������                             */

// ���������� ����� �������
void FindColor(TScene &Scene);

// ���������� �����
void Sort(vector<TVertex> &Triangle);

// �������� ����������
void Bresenham(vector<vector<int> > &Intersect, int StartX, int StartY, int FinalX, int FinalY, int Status, int ExitY);

// ������� �������
void SetTime(TScene &Scene);
