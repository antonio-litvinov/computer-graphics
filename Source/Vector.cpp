/*----------------------------------------------------------------------------*/
/*                      Модуль для работы с векторами                         */

#include "Header.h"

// Модуль вектора
double Length(T3DPoint Vector)
{
   return sqrt(Vector.X * Vector.X + Vector.Y * Vector.Y + Vector.Z * Vector.Z);
}

// Получает радиус-вектор
T3DPoint Vector(T3DPoint Start, T3DPoint Final)
{
   T3DPoint Result;

   Result.X = Final.X - Start.X;
   Result.Y = Final.Y - Start.Y;
   Result.Z = Final.Z - Start.Z;

   double L = Length(Result);

   Result.X /= L;
   Result.Y /= L;
   Result.Z /= L;

   return Result;
}

// Скалярное произведение
double ScalarProduct(T3DPoint A, T3DPoint B)
{
   return A.X * B.X + A.Y * B.Y + A.Z * B.Z;
}
