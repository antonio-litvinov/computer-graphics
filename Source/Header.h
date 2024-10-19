#ifndef HeaderH
#define HeaderH
#endif

// Библиотеки

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
/*                           Объявления структур                              */

// Тип вектора
typedef vector<double> TVector;

// Структура точки
typedef struct
{
   double X;
   double Y;
   double Z;
}  T3DPoint;

// Структура вершины
typedef struct
{
   T3DPoint Point;
   T3DPoint Normal;
   TColor Color;
}  TVertex;

// Структура грани
typedef struct
{
   int A;
   int B;
   int C;
}  TFace;

// Камера
typedef struct
{
   double Alpha;
   double Beta;
}  TCamera;

// Источник света
typedef struct
{
   T3DPoint Point;
   TColor Color;

}  TLight;

// Модель
typedef struct
{
   vector<TVertex> Vertices;
   vector<TFace> Faces;

   int NumVertex;
   int NumFaces;

   TColor Color;

}  TModel;

// Сцена
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
/*                     Загрузка и инициализация сцены                         */

// Инициализация сцены
void InitScene(TScene &Scene);

/*----------------------------------------------------------------------------*/
/*                      Модуль для работы с векторами                         */

// Получает радиус-вектор
T3DPoint Vector(T3DPoint Start, T3DPoint Final);

// Скалярное произведение
double ScalarProduct(T3DPoint A, T3DPoint B);

/*----------------------------------------------------------------------------*/
/*                      Модуль для работы с матрицами                         */

// Умножение вектора на матрицу
TVector Multiply(TVector Vector);

// Заполнение матрицы перемещения
void InitMove(double dx, double dy, double dz);

// Заполнение матрицы масштабирования
void InitScale(double kx, double ky, double kz);

// Заполнение матрицы поворота
void InitRotate(double Angle, char Axis);

// Заполнение матрицы преобразования координат
void InitTransform(double Alpha, double Beta);

// Извлечение координат из матрицы
T3DPoint GetPoint(TVector Vector, bool Integer = False);

// Помещение координат в матрицу
TVector PutPoint(T3DPoint Point);

/*----------------------------------------------------------------------------*/
/*                              Преобразования                                */

// Проекция
void Projection(TScene &Scene);

// Перемещение
void Move(TModel &Model, double dx, double dy, double dz);

// Масштабирование
void Scale(TModel &Model, double kx, double ky, double kz);

// Поворот
void Rotate(TModel &Model, double X, double Y, double Z);

/*----------------------------------------------------------------------------*/
/*                          Функции рисования                                 */

// Инициализация экрана
void InitScreen(TCanvas * Source, int Width, int Height);

// Прорисовка сцены
void DrawScene(TScene Scene);

// Прорисовка окружности
void DrawSphere(TColor Start, TColor Final);

/*----------------------------------------------------------------------------*/
/*                        Вспомогательные функции                             */

// Вычисление цвета пиксела
void FindColor(TScene &Scene);

// Сортировка точек
void Sort(vector<TVertex> &Triangle);

// Алгоритм Брезенхема
void Bresenham(vector<vector<int> > &Intersect, int StartX, int StartY, int FinalX, int FinalY, int Status, int ExitY);

// Поворот стрелок
void SetTime(TScene &Scene);
