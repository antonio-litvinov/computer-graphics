/*----------------------------------------------------------------------------*/
/*                              Преобразования                                */

#include "Header.h"

// Проекция
void Projection(TScene &Scene)
{
   TVector xyz,XYZ;

   InitTransform(Scene.Camera.Alpha,Scene.Camera.Beta);

   for (unsigned Index = 0; Index < Scene.Models.size(); Index++)
      {
         for (int I = 0; I < Scene.Models[Index].NumVertex; I++)
            {
               xyz = PutPoint(Scene.Models[Index].Vertices[I].Point);
               XYZ = Multiply(xyz);
               Scene.Models[Index].Vertices[I].Point = GetPoint(XYZ, True);
            }
      }
}

// Перемещение
void Move(TModel &Model, double DX, double DY, double DZ)
{
   TVector xyz,XYZ;

   InitMove(DX, DY, DZ);

   for (int I = 0; I < Model.NumVertex; I++)
      {
         xyz = PutPoint(Model.Vertices[I].Point);
         XYZ = Multiply(xyz);
         Model.Vertices[I].Point = GetPoint(XYZ);
      }
}

// Масштабирование
void Scale(TModel &Model, double KX, double KY, double KZ)
{
   TVector xyz,XYZ;

   InitScale(KX, KY, KZ);

   for (int I = 0; I < Model.NumVertex; I++)
      {
         xyz = PutPoint(Model.Vertices[I].Point);
         XYZ = Multiply(xyz);
         Model.Vertices[I].Point = GetPoint(XYZ);
      }
}

// Поворот
void Rotate(TModel &Model, double X, double Y, double Z)
{
   TVector xyz,XYZ;

   for (int I = 0; I < Model.NumVertex; I++)
      {
         // Точки
         xyz = PutPoint(Model.Vertices[I].Point);

         InitRotate(X, 'X');
         XYZ = Multiply(xyz);
         xyz = XYZ;

         InitRotate(Y, 'Y');
         XYZ = Multiply(xyz);
         xyz = XYZ;

         InitRotate(Z, 'Z');
         XYZ = Multiply(xyz);

         Model.Vertices[I].Point = GetPoint(XYZ);

         // Нормали
         xyz = PutPoint(Model.Vertices[I].Normal);

         InitRotate(X, 'X');
         XYZ = Multiply(xyz);
         xyz = XYZ;

         InitRotate(Y, 'Y');
         XYZ = Multiply(xyz);
         xyz = XYZ;

         InitRotate(Z, 'Z');
         XYZ = Multiply(xyz);

         Model.Vertices[I].Normal = GetPoint(XYZ);
      }
}
