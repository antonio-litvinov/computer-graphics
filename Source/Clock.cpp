//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USEFORM("Settings.cpp", frmSet);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
     {
        Application->Initialize();
        Application->CreateForm(__classid(TMainForm), &MainForm);
        Application->CreateForm(__classid(TfrmSet), &frmSet);
        Application->Run();
     }
  catch (...)
     {
        try
           {
              throw Exception("");
           }
        catch (Exception &exception)
           {
              Application->ShowException(&exception);
           }
     }
  return 0;
}
//---------------------------------------------------------------------------

