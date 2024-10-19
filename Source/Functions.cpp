/*----------------------------------------------------------------------------*/
/*                        Вспомогательные функции                             */

#include "Header.h"

// Вычисление цвета пиксела
void FindColor(TScene &Scene)
{
   TModel Model;

   int p = 100;

   double CosA, CosB;
   double tmp, tmp2;

   T3DPoint Light, Reflected;
   T3DPoint Camera, CameraPos;

   CameraPos.X = cos(Scene.Camera.Beta) * cos(Scene.Camera.Alpha);
   CameraPos.Y = cos(Scene.Camera.Beta) * sin(Scene.Camera.Alpha);
   CameraPos.Z = sin(Scene.Camera.Beta);

   int R,G,B;

   for (unsigned Index = 0; Index < Scene.Models.size(); Index++)
      {
         Model = Scene.Models[Index];
         for (int I = 0; I < Model.NumVertex; I++)
            {
               R = GetRValue(Model.Color) * Scene.Ka;
               G = GetGValue(Model.Color) * Scene.Ka;
               B = GetBValue(Model.Color) * Scene.Ka;

               for (unsigned J = 0; J < Scene.Light.size(); J++)
                  {
                     Light = Vector(Model.Vertices[I].Point, Scene.Light[J].Point);

                     CosA = ScalarProduct(Model.Vertices[I].Normal, Light);

                     Reflected.X = 2 * Model.Vertices[I].Normal.X * CosA - Light.X;
                     Reflected.Y = 2 * Model.Vertices[I].Normal.Y * CosA - Light.Y;
                     Reflected.Z = 2 * Model.Vertices[I].Normal.Z * CosA - Light.Z;

                     Camera = Vector(Model.Vertices[I].Point, CameraPos);
                     CosB = ScalarProduct(Camera,Reflected);

                     if (CosA > 0)
                        {
                           tmp = Scene.Kd * CosA;
                           tmp2 = Scene.Ks * pow(CosB,p);
                           R += GetRValue(Scene.Light[J].Color) * tmp +
                           GetRValue(Scene.Light[0].Color) * tmp2;

                           G += GetGValue(Scene.Light[J].Color) * tmp +
                           GetGValue(Scene.Light[0].Color) * tmp2;

                           B += GetBValue(Scene.Light[J].Color) * tmp +
                           GetBValue(Scene.Light[0].Color) * tmp2;
                        }

                     if (R > 255) R = 255;
                     if (G > 255) G = 255;
                     if (B > 255) B = 255;
                  }

               Model.Vertices[I].Color = (TColor)RGB(R, G, B);
            }
         Scene.Models[Index] = Model;
      }
}

// Сортировка точек
void Sort(vector<TVertex> &Triangle)
{
   TVertex Temp;

   for (int I = 0; I < 3; I++)
     for (int J = 0; J < 3; J++)
        {
            if (Triangle[I].Point.Y < Triangle[J].Point.Y)
                {
                   Temp = Triangle[I];
                   Triangle[I] = Triangle[J];
                   Triangle[J] = Temp;
                }
        }
}

// Знаковая функция
int Sign(float X)
{
   if (X < 0) return -1;
   if (X > 0) return 1;
   return 0;
}

// Алгоритм Брезенхема
void Bresenham(vector<vector<int> > &Intersect, int StartX, int StartY, int FinalX, int FinalY, int Status, int ExitY)
{
   int e;
   int Change;
   int Temp;
   int DX,DY;
   int X,Y;
   int Sx,Sy;
   int I;

   int Index = 0;

   X = StartX; Y = StartY;

   DX = FinalX - StartX; DY = FinalY - StartY;

   Sx = Sign(DX); Sy = Sign(DY);

   DX = abs(DX); DY = abs(DY);

   if (DX > DY) Change = 0;
   else
      {
         Change = 1;
         Temp = DX;
         DX = DY;
         DY = Temp;
      }

   e = 2 * DY - DX;

   for (I = 1; I <= DX; I++)
      {
         Intersect[Index][Status] = X;

         if (e >= 0)
            {
               if (Change == 0)
                  {
                     Y += Sy;
                     Index++;
                  }
               else
                  X += Sx;

               e -= 2 * DX;
            }

         if (Change == 0)
            X += Sx;
         else
            {
               Y += Sy;
               Index++;
            }

         e += 2 * DY;

         if (Y == ExitY)
            {
               Intersect[Index][Status] = X;
               return;
            }
      }
   Intersect[Index][Status] = X;
}

// Поворот стрелок
void SetTime(TScene &Scene)
{
   unsigned short Hour, Min, Sec, MSec;
   TDateTime Time = Now();
   Time.DecodeTime(&Hour, &Min, &Sec, &MSec);

   double HourAngle = Hour * 30 + (double)Min / 60 * 30;
   double MinAngle = Min * 6;
   double SecAngle = Sec * 6;

   Rotate(Scene.Models[Scene.Hour],0,0,-HourAngle);
   Rotate(Scene.Models[Scene.Min], 0,0,-MinAngle);
   Rotate(Scene.Models[Scene.Sec],0,0,-SecAngle);
}
