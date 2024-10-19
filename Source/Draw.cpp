/*----------------------------------------------------------------------------*/
/*                          Функции рисования                                 */

#include "Header.h"

int XC,YC;

TCanvas * Canvas;
TPicture * Picture;

TColor Start, Final;

vector <vector <int> > Buffer;

// Прорисовка сферы
void DrawSphere(TColor Start, TColor Final)
{
   TColor Color;
   double R2, r2, K;
   int X, Y;

   Picture->Bitmap->Width = Buffer.size();
   Picture->Bitmap->Height = Buffer[0].size();

   Picture->Bitmap->Canvas->Brush->Color = Start;
   Picture->Bitmap->Canvas->FillRect(Picture->Bitmap->Canvas->ClipRect);

   int R = Picture->Bitmap->Width * 0.6;

   R2 = R * R;

   for(X = 0; X <= R; X++)
      for(Y = 0; Y <= X; Y++)
         {
            r2 = X * X + Y * Y;

            if( r2 > R2 ) break;

            K = 1 - r2 / R2;

            int R = (int)(K * GetRValue(Final) + (1 - K) * GetRValue(Start));
            int G = (int)(K * GetGValue(Final) + (1 - K) * GetGValue(Start));
            int B = (int)(K * GetBValue(Final) + (1 - K) * GetBValue(Start));

            Color = (TColor)RGB(R, G, B);

            Picture->Bitmap->Canvas->Pixels[XC + X][YC + Y] = Color;
            Picture->Bitmap->Canvas->Pixels[XC + X][YC - Y] = Color;
            Picture->Bitmap->Canvas->Pixels[XC - X][YC + Y] = Color;
            Picture->Bitmap->Canvas->Pixels[XC - X][YC - Y] = Color;

            Picture->Bitmap->Canvas->Pixels[XC + Y][YC + X] = Color;
            Picture->Bitmap->Canvas->Pixels[XC + Y][YC - X] = Color;
            Picture->Bitmap->Canvas->Pixels[XC - Y][YC + X] = Color;
            Picture->Bitmap->Canvas->Pixels[XC - Y][YC - X] = Color;
         }
}

// Инициализация экрана
void InitScreen(TCanvas * Source, int Width, int Height)
{
   XC = Width / 2;
   YC = Height / 2;

   Buffer.resize(Width);
   for (int I = 0; I < Width; I++) Buffer[I].resize(Height);

   Canvas = Source;

   Picture = new TPicture;
   DrawSphere(Start, Final);
}

// Инициализация Z-буфера
void InitBuffer()
{
   for (unsigned I = 0; I < Buffer.size(); I++)
      for (unsigned J = 0; J < Buffer[I].size(); J++)
         Buffer[I][J] = -1000;
}

// Прорисовка треугольника
void DrawTriangle(TVertex A, TVertex B, TVertex C, vector<vector<int> > Intersect, bool Bottom)
{
   int StartR, StartG, StartB;

   double StartZ;

   int FinalR, FinalG, FinalB;

   double FinalZ;

   int ResultR, ResultG, ResultB;

   double ResultZ;

   int Y = A.Point.Y;

   double K1, K2;

   double tmp, tmp2;

   if (A.Point.X == B.Point.X) K1 = 90;
   else
      K1 = RadToDeg(atan( (B.Point.Y - A.Point.Y) / (B.Point.X - A.Point.X) ));

   if (A.Point.X == C.Point.X) K2 = 90;
   else
      K2 = RadToDeg(atan( (C.Point.Y - A.Point.Y) / (C.Point.X - A.Point.X) ));

   for (unsigned I = 0; I < Intersect.size(); I++)
      {
         if (fabs(K1) <= 45)
            {
               tmp = Intersect[I][0] - A.Point.X;
               tmp2 = B.Point.X - A.Point.X;
               StartR = GetRValue(A.Color) + tmp * (GetRValue(B.Color) - GetRValue(A.Color)) / tmp2;
               StartG = GetGValue(A.Color) + tmp * (GetGValue(B.Color) - GetGValue(A.Color)) / tmp2;
               StartB = GetBValue(A.Color) + tmp * (GetBValue(B.Color) - GetBValue(A.Color)) / tmp2;

               StartZ = A.Point.Z + tmp * (B.Point.Z - A.Point.Z) / tmp2;
            }
         else
            {
               tmp = Y - A.Point.Y;
               tmp2 = B.Point.Y - A.Point.Y;
               StartR = GetRValue(A.Color) + tmp * (GetRValue(B.Color) - GetRValue(A.Color)) / tmp2;
               StartG = GetGValue(A.Color) + tmp * (GetGValue(B.Color) - GetGValue(A.Color)) / tmp2;
               StartB = GetBValue(A.Color) + tmp * (GetBValue(B.Color) - GetBValue(A.Color)) / tmp2;

               StartZ = A.Point.Z + tmp * (B.Point.Z - A.Point.Z) / tmp2;
            }

         if (fabs(K2) <= 45)
            {
               tmp = Intersect[I][1] - A.Point.X;
               tmp2 = C.Point.X - A.Point.X;
               FinalR = GetRValue(A.Color) + tmp * (GetRValue(C.Color) - GetRValue(A.Color)) / tmp2;
               FinalG = GetGValue(A.Color) + tmp * (GetGValue(C.Color) - GetGValue(A.Color)) / tmp2;
               FinalB = GetBValue(A.Color) + tmp * (GetBValue(C.Color) - GetBValue(A.Color)) / tmp2;

               FinalZ = A.Point.Z + tmp * (C.Point.Z - A.Point.Z) / tmp2;
            }
         else
            {
               tmp = Y - A.Point.Y;
               tmp2 = C.Point.Y - A.Point.Y;
               FinalR = GetRValue(A.Color) + tmp * (GetRValue(C.Color) - GetRValue(A.Color)) / tmp2;
               FinalG = GetGValue(A.Color) + tmp * (GetGValue(C.Color) - GetGValue(A.Color)) / tmp2;
               FinalB = GetBValue(A.Color) + tmp * (GetBValue(C.Color) - GetBValue(A.Color)) / tmp2;

               FinalZ = A.Point.Z + tmp * (C.Point.Z - A.Point.Z) / tmp2;
            }

         for (int X = Intersect[I][0]; X <= Intersect[I][1]; X++)
            {
               ResultR = StartR;
               ResultG = StartG;
               ResultB = StartB;

               ResultZ = StartZ;

               if (Intersect[I][0] != Intersect[I][1])
                  {
                      tmp = X - Intersect[I][0];
                      tmp2 = Intersect[I][1] - Intersect[I][0];
                      ResultR = StartR + tmp * (FinalR - StartR) / tmp2;
                      ResultG = StartG + tmp * (FinalG - StartG) / tmp2;
                      ResultB = StartB + tmp * (FinalB - StartB) / tmp2;

                      ResultZ = StartZ + tmp * (FinalZ - StartZ) / tmp2;
                  }

               if (((unsigned)(XC + X) < Buffer.size())  &&
                   ((unsigned)(YC - Y) < Buffer[0].size()) &&
                   ((XC + X) > 0) && ((YC - Y) > 0))
                  if ((ResultZ >= Buffer[XC + X][YC - Y]) && (ResultZ >= -1000))
                     {
                        Canvas->Pixels[XC + X][YC - Y] = (TColor)RGB(ResultR,ResultG,ResultB);
                        Buffer[XC + X][YC - Y] = ResultZ;
                     }
            }

         if (Bottom) Y--;
         else        Y++;
      }
}

// Растеризация треугольника
void Rasterize(TVertex A, TVertex B, TVertex C)
{
   int dY;
   vector <vector <int> > Intersect;

   vector <TVertex> Temp;

   Temp.push_back(A);
   Temp.push_back(B);
   Temp.push_back(C);

   Sort(Temp);

   A = Temp[0];
   B = Temp[1];
   C = Temp[2];

   double K,X;

   if (A.Point.Y == C.Point.Y) X = A.Point.X;
   else
      {
         K = (A.Point.X - C.Point.X) / (A.Point.Y - C.Point.Y);
         X = C.Point.X + K * (B.Point.Y - C.Point.Y);
      }

   dY = B.Point.Y - A.Point.Y + 1;

   Intersect.resize(dY);
   for (int i = 0; i < dY; i++) Intersect[i].resize(2);

   if (X > B.Point.X)
      {
         if (dY == 1)
            {
               Intersect[0][0] = B.Point.X;
               Intersect[0][1] = A.Point.X;
            }
         else
            {
               Bresenham(Intersect, A.Point.X, A.Point.Y, B.Point.X, B.Point.Y, 0, B.Point.Y);
               Bresenham(Intersect, A.Point.X, A.Point.Y, C.Point.X, C.Point.Y, 1, B.Point.Y);
            }
         DrawTriangle(A, B, C, Intersect, False);
      }
   else
      {
        if (dY == 1)
           {
              Intersect[0][0] = A.Point.X;
              Intersect[0][1] = B.Point.X;
           }
        else
           {
              Bresenham(Intersect, A.Point.X, A.Point.Y, C.Point.X, C.Point.Y, 0, B.Point.Y);
              Bresenham(Intersect, A.Point.X, A.Point.Y, B.Point.X, B.Point.Y, 1, B.Point.Y);
           }
        DrawTriangle(A, C, B, Intersect, False);
      }

   dY = C.Point.Y - B.Point.Y + 1;

   Intersect.resize(dY);
   for (int i = 0; i < dY; i++) Intersect[i].resize(2);

   if (X > B.Point.X)
      {
         if (dY == 1)
            {
               Intersect[0][0] = B.Point.X;
               Intersect[0][1] = C.Point.X;
            }
         else
            {
               Bresenham(Intersect, C.Point.X, C.Point.Y, B.Point.X, B.Point.Y, 0, B.Point.Y);
               Bresenham(Intersect, C.Point.X, C.Point.Y, A.Point.X, A.Point.Y, 1, B.Point.Y);
            }
         DrawTriangle(C, B, A, Intersect, True);
      }
   else
      {
         if (dY == 1)
            {
               Intersect[0][0] = C.Point.X;
               Intersect[0][1] = B.Point.X;
            }
         else
            {
               Bresenham(Intersect, C.Point.X, C.Point.Y, A.Point.X, A.Point.Y, 0, B.Point.Y);
               Bresenham(Intersect, C.Point.X, C.Point.Y, B.Point.X, B.Point.Y, 1, B.Point.Y);
            }
         DrawTriangle(C, A, B, Intersect, True);
      }
}

// Прорисовка модели
void DrawModel(TModel Model)
{
   TVertex A,B,C;

   for (int I = 0; I < Model.NumFaces; I++)
      {
         A = Model.Vertices[Model.Faces[I].A];
         B = Model.Vertices[Model.Faces[I].B];
         C = Model.Vertices[Model.Faces[I].C];
         Rasterize(A, B, C);
      }
}

// Прорисовка сцены
void DrawScene(TScene Scene)
{
  if ((Scene.Clock) && (Scene.Models.size() >= 3)
  && (Scene.Hour != -1) && (Scene.Min != -1) && (Scene.Sec != -1))
     SetTime(Scene);

  for (unsigned Index = 0; Index < Scene.Models.size(); Index++)
     {
        Move(Scene.Models[Index], Scene.Move.X, Scene.Move.Y, Scene.Move.Z);
        Scale(Scene.Models[Index], Scene.Scale.X, Scene.Scale.Y, Scene.Scale.Z);
        Rotate(Scene.Models[Index], Scene.Rotate.X, Scene.Rotate.Y, Scene.Rotate.Z);
     }

  Canvas->Draw(0,0,Picture->Graphic);

  InitBuffer();
  FindColor(Scene);
  Projection(Scene);

  for (unsigned Index = 0; Index < Scene.Models.size(); Index++)
     DrawModel(Scene.Models[Index]);
}
