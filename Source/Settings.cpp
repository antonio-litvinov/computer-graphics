#include "Header.h"

#include "Main.h"
#include "Settings.h"

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"

TfrmSet *frmSet;

extern TScene Scene;
extern TColor Start, Final;

//---------------------------------------------------------------------------
__fastcall TfrmSet::TfrmSet(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmSet::FormCreate(TObject *Sender)
{
   // Камера
   edtAlpha->Text = FloatToStr(Scene.Camera.Alpha);
   edtBeta->Text = FloatToStr(Scene.Camera.Beta);

   // Освещешие
   LightList->Items->Clear();
   for (unsigned Index = 0; Index < Scene.Light.size(); Index++)
      LightList->Items->Add(IntToStr(Index));

   LightList->ItemIndex = 0;

   edtLightX->Text = FloatToStr(Scene.Light[LightList->ItemIndex].Point.X);
   edtLightY->Text = FloatToStr(Scene.Light[LightList->ItemIndex].Point.Y);
   edtLightZ->Text = FloatToStr(Scene.Light[LightList->ItemIndex].Point.Z);

   LightColor->Color = Scene.Light[LightList->ItemIndex].Color;

   // Коэффициенты
   edtKa->Text = FloatToStr(Scene.Ka);
   edtKd->Text = FloatToStr(Scene.Kd);
   edtKs->Text = FloatToStr(Scene.Ks);


   // Преобразования
   edtMoveX->Text = FloatToStr(Scene.Move.X);
   edtMoveY->Text = FloatToStr(Scene.Move.Y);
   edtMoveZ->Text = FloatToStr(Scene.Move.Z);

   edtScaleX->Text = FloatToStr(Scene.Scale.X);
   edtScaleY->Text = FloatToStr(Scene.Scale.Y);
   edtScaleZ->Text = FloatToStr(Scene.Scale.Z);

   edtRotateX->Text = FloatToStr(Scene.Rotate.X);
   edtRotateY->Text = FloatToStr(Scene.Rotate.Y);
   edtRotateZ->Text = FloatToStr(Scene.Rotate.Z);

   edtFileName->Text = Scene.FileName;

   // Часы
   if (Scene.Clock)
      ClockCheck->Checked = True;
   else
      ClockCheck->Checked = False;

   // Модели
   ModelList->Items->Clear();
   for (unsigned Index = 0; Index < Scene.Models.size(); Index++)
      ModelList->Items->Add(IntToStr(Index));

   ModelList->ItemIndex = 0;
   ModelListChange(this);

   // Освещение
   LightList->Items->Clear();
   for (unsigned Index = 0; Index < Scene.Light.size(); Index++)
      LightList->Items->Add(IntToStr(Index));

   LightList->ItemIndex = 0;
   LightListChange(this);

   // Цвета
   StartColor->Color = Start;
   FinalColor->Color = Final;

   // Стрелки
   if (Scene.Hour == -1)
      lblHour->Caption = "(нет)";
   else
      lblHour->Caption = "(" + IntToStr(Scene.Hour) + ")";

   if (Scene.Hour == -1)
      lblMin->Caption = "(нет)";
   else
      lblMin->Caption = "(" + IntToStr(Scene.Min) + ")";

   if (Scene.Hour == -1)
      lblSec->Caption = "(нет)";
   else
      lblSec->Caption = "(" + IntToStr(Scene.Sec) + ")";
}
//---------------------------------------------------------------------------

void __fastcall TfrmSet::btnApplyClick(TObject *Sender)
{
   // Общие
   Scene.Camera.Alpha = StrToFloat(edtAlpha->Text);
   Scene.Camera.Beta  = StrToFloat(edtBeta->Text);

   Scene.Light[LightList->ItemIndex].Point.X = StrToFloat(edtLightX->Text);
   Scene.Light[LightList->ItemIndex].Point.Y = StrToFloat(edtLightY->Text);
   Scene.Light[LightList->ItemIndex].Point.Z = StrToFloat(edtLightZ->Text);

   Scene.Ka = StrToFloat(edtKa->Text);
   Scene.Kd = StrToFloat(edtKd->Text);
   Scene.Ks = StrToFloat(edtKs->Text);

   // Преобразования
   Scene.Move.X = StrToFloat(edtMoveX->Text);
   Scene.Move.Y = StrToFloat(edtMoveY->Text);
   Scene.Move.Z = StrToFloat(edtMoveZ->Text);

   Scene.Scale.X = StrToFloat(edtScaleX->Text);
   Scene.Scale.Y = StrToFloat(edtScaleY->Text);
   Scene.Scale.Z = StrToFloat(edtScaleZ->Text);

   Scene.Rotate.X = StrToFloat(edtRotateX->Text);
   Scene.Rotate.Y = StrToFloat(edtRotateY->Text);
   Scene.Rotate.Z = StrToFloat(edtRotateZ->Text);

   DrawScene(Scene);

}
//---------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
/*                            Изменение цвета                                 */

void __fastcall TfrmSet::LightColorClick(TObject *Sender)
{
   if (ColorDialog->Execute())
      {
         LightColor->Color = ColorDialog->Color;
         Scene.Light[LightList->ItemIndex].Color = ColorDialog->Color;
         DrawScene(Scene);
      }
}
//---------------------------------------------------------------------------

void __fastcall TfrmSet::ModelColorClick(TObject *Sender)
{
   if (ColorDialog->Execute())
      {
         ModelColor->Color = ColorDialog->Color;
         Scene.Models[ModelList->ItemIndex].Color = ColorDialog->Color;
         DrawScene(Scene);
      }
}
//---------------------------------------------------------------------------

void __fastcall TfrmSet::StartColorClick(TObject *Sender)
{
   if (ColorDialog->Execute())
      {
         StartColor->Color = ColorDialog->Color;
         Start = ColorDialog->Color;
         DrawSphere(Start, Final);
         DrawScene(Scene);
      }
}
//---------------------------------------------------------------------------

void __fastcall TfrmSet::FinalColorClick(TObject *Sender)
{
   if (ColorDialog->Execute())
      {
         FinalColor->Color = ColorDialog->Color;
         Final = ColorDialog->Color;
         DrawSphere(Start, Final);
         DrawScene(Scene);
      }
}
//---------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
/*                          Изменение списков                                 */

void __fastcall TfrmSet::LightListChange(TObject *Sender)
{
   edtLightX->Text = FloatToStr(Scene.Light[LightList->ItemIndex].Point.X);
   edtLightY->Text = FloatToStr(Scene.Light[LightList->ItemIndex].Point.Y);
   edtLightZ->Text = FloatToStr(Scene.Light[LightList->ItemIndex].Point.Z);

   LightColor->Color = Scene.Light[LightList->ItemIndex].Color;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSet::ModelListChange(TObject *Sender)
{
   ModelColor->Color = Scene.Models[ModelList->ItemIndex].Color;
}
//---------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
/*                                Кнопки                                      */

// Добавить источник света
void __fastcall TfrmSet::btnLightAddClick(TObject *Sender)
{
   TLight Light;

   Light.Point.X = StrToFloat(edtLightX->Text);
   Light.Point.Y = StrToFloat(edtLightY->Text);
   Light.Point.Z = StrToFloat(edtLightZ->Text);

   Light.Color = LightColor->Color;

   Scene.Light.push_back(Light);

   LightList->Items->Clear();
   for (unsigned Index = 0; Index < Scene.Light.size(); Index++)
      LightList->Items->Add(IntToStr(Index));

   LightList->ItemIndex = LightList->Items->Count - 1;
   LightListChange(this);

   DrawScene(Scene);
}
//---------------------------------------------------------------------------

// Удалить источник света
void __fastcall TfrmSet::btnDeleteClick(TObject *Sender)
{
   if (Scene.Light.size() > 1)
      {
         Scene.Light.erase(&Scene.Light[LightList->ItemIndex]);

         LightList->Items->Clear();
         for (unsigned Index = 0; Index < Scene.Light.size(); Index++)
            LightList->Items->Add(IntToStr(Index));

         LightList->ItemIndex = LightList->Items->Count - 1;
         LightListChange(this);

         DrawScene(Scene);
      }
}
//---------------------------------------------------------------------------

// Открыть файл
void __fastcall TfrmSet::btnFileOpenClick(TObject *Sender)
{
   if (OpenDialog->Execute())
      {
         edtFileName->Text = OpenDialog->FileName;
         Scene.FileName = OpenDialog->FileName.c_str();

         MainForm->Hide();
         frmSet->Hide();

         InitScene(Scene);
         DrawSphere(Start, Final);
         DrawScene(Scene);

         FormCreate(this);

         MainForm->Show();
         frmSet->Show();
      }
}
//---------------------------------------------------------------------------

// Установить часовую стрелку
void __fastcall TfrmSet::btnSetHourClick(TObject *Sender)
{
   Scene.Hour = ModelList->ItemIndex;
   lblHour->Caption = "(" + IntToStr(Scene.Hour) + ")";
}
//---------------------------------------------------------------------------

// Установить минутную стрелку
void __fastcall TfrmSet::btnSetMinClick(TObject *Sender)
{
   Scene.Min = ModelList->ItemIndex;
   lblMin->Caption = "(" + IntToStr(Scene.Min) + ")";
}
//---------------------------------------------------------------------------

// Установить секундную стрелку
void __fastcall TfrmSet::btnSetSecClick(TObject *Sender)
{
   Scene.Sec = ModelList->ItemIndex;
   lblSec->Caption = "(" + IntToStr(Scene.Sec) + ")";
}
//---------------------------------------------------------------------------

// Часы или нет
void __fastcall TfrmSet::ClockCheckClick(TObject *Sender)
{
   if (ClockCheck->Checked) Scene.Clock = True;
   else                     Scene.Clock = False;
}
//---------------------------------------------------------------------------

// Нажатие на Enter
void __fastcall TfrmSet::edtAlphaKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == VK_RETURN) btnApply->Click();
}
//---------------------------------------------------------------------------

// Проверка ввода
void __fastcall TfrmSet::edtAlphaKeyPress(TObject *Sender, char &Key)
{
  //if ( (Key < '0' || Key > '9') && Key != '-' && Key != 8 && Key != 13 ) Key = 0;
  if (((Key < '0') || (Key > '9')) && (Key != '-') && (Key != 8) && (Key != 13))
     Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TfrmSet::btnSaveClick(TObject *Sender)
{
  if (SaveDialog->Execute())
     {
        MainForm->Image->Picture->SaveToFile(SaveDialog->FileName);
     }
}
//---------------------------------------------------------------------------

