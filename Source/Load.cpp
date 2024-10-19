/*----------------------------------------------------------------------------*/
/*                     Загрузка и инициализация сцены                         */

#include "Header.h"

extern TColor Start, Final;

// Загрузка из файла
void Load(char * FileName, TScene &Scene)
{
   fstream File;
   char String[20];
   TVertex Vertex;
   TFace Face;
   double R,G,B;

   TForm * LoadScreen = new TForm(Application);
   TPicture * Picture = new TPicture;

   Picture->Bitmap->LoadFromResourceName(0,"SPLASH");

   LoadScreen->DoubleBuffered = True;

   LoadScreen->Width = Picture->Width;
   LoadScreen->Height = Picture->Height;

   LoadScreen->BorderStyle = bsNone;
   LoadScreen->Position = poScreenCenter;

   LoadScreen->Show();
   LoadScreen->Release();

   LoadScreen->Canvas->Draw(0,0,Picture->Graphic);

   File.open(FileName ,ios::in);

   Scene.Models.clear();
   Scene.Light.clear();

   while (!File.eof())
      {
         File >> String;

         if (!strcmp(String,"*SCENE_LIGHT_POINT"))
            {
               Scene.Light.resize(Scene.Light.size() + 1);

               File >> Scene.Light.back().Point.X;
               File >> Scene.Light.back().Point.Y;
               File >> Scene.Light.back().Point.Z;
            }

         if (!strcmp(String,"*SCENE_LIGHT_COLOR"))
            {
               File >> R;
               File >> G;
               File >> B;
               Scene.Light.back().Color = (TColor)RGB(R, G, B);
            }

         if (!strcmp(String,"*SCENE_LIGHT_PARAM"))
            {
               File >> Scene.Ka;
               File >> Scene.Kd;
               File >> Scene.Ks;
            }

         if (!strcmp(String,"*SCENE_CAMERA"))
            {
               File >> Scene.Camera.Alpha;
               File >> Scene.Camera.Beta;
            }

         if (!strcmp(String,"*SCENE_START"))
            {
               File >> R;
               File >> G;
               File >> B;
               Start = (TColor)RGB(R, G, B);
            }

         if (!strcmp(String,"*SCENE_FINAL"))
            {
               File >> R;
               File >> G;
               File >> B;
               Final = (TColor)RGB(R, G, B);
            }

         if (!strcmp(String,"*SCENE_CLOCK"))
            {
               Scene.Clock = True;
               File >> Scene.Hour;
               File >> Scene.Min;
               File >> Scene.Sec;
            }

         if (!strcmp(String,"*GEOMOBJECT"))
            Scene.Models.resize(Scene.Models.size() + 1);

         if (!strcmp(String,"*MESH_NUMVERTEX"))
            File >> Scene.Models.back().NumVertex;

         if (!strcmp(String,"*MESH_NUMFACES"))
            File >> Scene.Models.back().NumFaces;

         if (!strcmp(String,"*MESH_VERTEX"))
            {
               File >> String;
               File >> Vertex.Point.X;
               File >> Vertex.Point.Y;
               File >> Vertex.Point.Z;
               Scene.Models.back().Vertices.push_back(Vertex);
            }

         if (!strcmp(String,"*MESH_FACE"))
            {
               File >> String;
               File >> String;
               File >> Face.A;
               File >> String;
               File >> Face.B;
               File >> String;
               File >> Face.C;
               Scene.Models.back().Faces.push_back(Face);
            }

         if (!strcmp(String,"*MESH_VERTEXNORMAL"))
            {
               File >> String;
               File >> Scene.Models.back().Vertices[StrToInt(String)].Normal.X;
               File >> Scene.Models.back().Vertices[StrToInt(String)].Normal.Y;
               File >> Scene.Models.back().Vertices[StrToInt(String)].Normal.Z;
            }

         if (!strcmp(String,"*WIREFRAME_COLOR"))
            {
               File >> R;
               File >> G;
               File >> B;
               Scene.Models.back().Color = (TColor)RGB(R * 255, G * 255, B * 255);
            }

      }
   File.close();

   LoadScreen->Hide();
}

// Инициализация сцены
void InitScene(TScene &Scene)
{
   // Преобразования
   Scene.Move.X = 0; Scene.Move.Y = 0; Scene.Move.Z = 0;

   Scene.Scale.X = 1; Scene.Scale.Y = 1; Scene.Scale.Z = 1;

   Scene.Rotate.X = 0; Scene.Rotate.Y = 0; Scene.Rotate.Z = 0;

  // Параметры камеры
  Scene.Camera.Alpha = 0; Scene.Camera.Beta  = 0;

  // Коэффициенты
  Scene.Ka = 0.5; Scene.Kd = 0.5; Scene.Ks = 0.2;

  // Цвет фона
  Start = clTeal; Final = clBlack;

  // Часы
  Scene.Clock = False;

  Scene.Hour = -1; Scene.Min = -1; Scene.Sec = -1;

  // Загрузка сцены
  Load(Scene.FileName,Scene);

  // Задание источника света
  if (Scene.Light.size() == 0)
     {
        TLight Light;

        Light.Point.X = 0;
        Light.Point.Y = 0;
        Light.Point.Z = 100;

        Light.Color = clWhite;

        Scene.Light.push_back(Light);
     }
}
