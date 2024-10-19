/*----------------------------------------------------------------------------*/
/*                      Модуль для работы с матрицами                         */

#include "Header.h"

// Матрица преобразований
double Transform[4][4];

// Умножение вектора на матрицу
TVector Multiply(TVector Vector)
{
   TVector Result;
   double Sum;

   for (int I = 0; I < 4; I++)
      {
         Sum = 0;
         for (int J = 0; J < 4; J++)
            Sum += Vector[J] * Transform[I][J];
         Result.push_back(Sum);
      }
   return Result;
}

// Заполнение матрицы нулями
void Clear()
{
   for (int I = 0; I < 4; I++)
      for (int J = 0; J < 4; J++)
         Transform[I][J] = 0;
}

// Заполнение матрицы перемещения
void InitMove(double dx, double dy, double dz)
{
   Clear();
   Transform[0][0] = 1;
   Transform[1][1] = 1;
   Transform[2][2] = 1;
   Transform[3][3] = 1;
   Transform[0][3] = dx;
   Transform[1][3] = dy;
   Transform[2][3] = dz;
}

// Заполнение матрицы масштабирования
void InitScale(double kx, double ky, double kz)
{
   Clear();
   Transform[0][0] = kx;
   Transform[1][1] = ky;
   Transform[2][2] = kz;
   Transform[3][3] = 1;
}

// Заполнение матрицы поворота
void InitRotate(double Angle, char Axis)
{
   Clear();
   Angle = DegToRad(Angle);

   switch (Axis)
      {
         case 'X': // Поворот вокруг оси X
            Transform[0][0] = 1;
            Transform[1][1] = cos(Angle);
            Transform[1][2] = -sin(Angle);
            Transform[2][1] = sin(Angle);
            Transform[2][2] = cos(Angle);
            Transform[3][3] = 1;
         break;

         case 'Y': // Поворот вокруг оси Y
            Transform[0][0] = cos(Angle);
            Transform[0][2] = -sin(Angle);
            Transform[1][1] = 1;
            Transform[2][0] = sin(Angle);
            Transform[2][2] = cos(Angle);
            Transform[3][3] = 1;
         break;

         case 'Z': // Поворот вокруг оси Z
            Transform[0][0] = cos(Angle);
            Transform[0][1] = -sin(Angle);
            Transform[1][0] = sin(Angle);
            Transform[1][1] = cos(Angle);
            Transform[2][2] = 1;
            Transform[3][3] = 1;
         break;
      }
}

// Заполнение матрицы преобразования координат
void InitTransform(double Alpha, double Beta)
{
   Clear();

   Alpha = DegToRad(Alpha);
   Beta = DegToRad(Beta);

   Transform[0][0] = cos(Alpha);
   Transform[0][1] = -sin(Alpha);
   Transform[1][0] = sin(Alpha) * cos(Beta);
   Transform[1][1] = cos(Alpha) * cos(Beta);
   Transform[1][2] = -sin(Beta);
   Transform[2][0] = sin(Alpha) * sin(Beta);
   Transform[2][1] = cos(Alpha) * sin(Beta);
   Transform[2][2] = cos(Beta);
   Transform[3][3] = 1;
}

// Извлечение координат из матрицы
T3DPoint GetPoint(TVector Vector, bool Integer)
{
   T3DPoint Result;

   if (Integer)
      {
         Result.X = (int)Vector[0];
         Result.Y = (int)Vector[1];
         Result.Z = (int)Vector[2];
      }
   else
      {
         Result.X = Vector[0];
         Result.Y = Vector[1];
         Result.Z = Vector[2];
      }

   return Result;
}

// Помещение координат в матрицу
TVector PutPoint(T3DPoint Point)
{
   TVector Result;

   Result.push_back(Point.X);
   Result.push_back(Point.Y);
   Result.push_back(Point.Z);
   Result.push_back(1);

   return Result;
}
