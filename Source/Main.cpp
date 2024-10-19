#include "Header.h"

#include "Main.h"
#include "Settings.h"

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

TScene Scene;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  DoubleBuffered = True;

  Scene.FileName = "Часы.ase";

  if (FileExists(Scene.FileName)) InitScene(Scene);
  else
     {
        ShowMessage("Нет файла");
        exit(0);
     }

  InitScreen(MainForm->Image->Canvas, Image->Width, Image->Height);

  DrawScene(Scene);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  switch (Key)
  {
    case VK_LEFT:
       if (Shift.Contains(ssShift)) Scene.Move.X -= 5;
       else                         Scene.Rotate.Z += 5;
    break;

    case VK_RIGHT:
       if (Shift.Contains(ssShift)) Scene.Move.X += 5;
       else                         Scene.Rotate.Z -= 5;
    break;

    case VK_DOWN:
       if (Shift.Contains(ssShift)) Scene.Move.Y -= 5;
       else                         Scene.Rotate.X += 5;
    break;

    case VK_UP:
       if (Shift.Contains(ssShift)) Scene.Move.Y += 5;
       else                         Scene.Rotate.X -= 5;
    break;

    case VK_PRIOR: // PG Up
       if (Shift.Contains(ssShift)) Scene.Move.Z -= 5;
       else                         Scene.Rotate.Y += 5;
    break;

    case VK_NEXT: // PG Down
       if (Shift.Contains(ssShift)) Scene.Move.Z += 5;
       else                         Scene.Rotate.Y -= 5;
    break;

    case VK_ADD: // +
       Scene.Scale.X += 0.1;
       Scene.Scale.Y += 0.1;
       Scene.Scale.Z += 0.1;
    break;

    case VK_SUBTRACT: // -
       Scene.Scale.X -= 0.1;
       Scene.Scale.Y -= 0.1;
       Scene.Scale.Z -= 0.1;
    break;

    // Вызов меню настроек при нажатии Enter
    case VK_RETURN: frmSet->Left = Left + Width + 5; frmSet->Top = Top; frmSet->Show(); break;
  }

  // Отрисовка сцены
  DrawScene(Scene);

  // Преобразования
  frmSet->edtMoveX->Text = FloatToStr(Scene.Move.X);
  frmSet->edtMoveY->Text = FloatToStr(Scene.Move.Y);
  frmSet->edtMoveZ->Text = FloatToStr(Scene.Move.Z);

  frmSet->edtScaleX->Text = FloatToStr(Scene.Scale.X);
  frmSet->edtScaleY->Text = FloatToStr(Scene.Scale.Y);
  frmSet->edtScaleZ->Text = FloatToStr(Scene.Scale.Z);

  frmSet->edtRotateX->Text = FloatToStr(Scene.Rotate.X);
  frmSet->edtRotateY->Text = FloatToStr(Scene.Rotate.Y);
  frmSet->edtRotateZ->Text = FloatToStr(Scene.Rotate.Z);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TimerTimer(TObject *Sender)
{
   if (Scene.Clock) DrawScene(Scene);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ImageMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
  extern XC,YC;

  if (Shift.Contains(ssShift))
  {
    Scene.Light[frmSet->LightList->ItemIndex].Point.X = X - XC;
    Scene.Light[frmSet->LightList->ItemIndex].Point.Y = YC - Y;

    frmSet->edtLightX->Text = FloatToStr(Scene.Light[frmSet->LightList->ItemIndex].Point.X);
    frmSet->edtLightY->Text = FloatToStr(Scene.Light[frmSet->LightList->ItemIndex].Point.Y);
    frmSet->edtLightZ->Text = FloatToStr(Scene.Light[frmSet->LightList->ItemIndex].Point.Z);
  }
}
//---------------------------------------------------------------------------

