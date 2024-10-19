//---------------------------------------------------------------------------

#ifndef SettingsH
#define SettingsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmSet : public TForm
{
__published:	// IDE-managed Components
  TPageControl *PageControl1;
  TTabSheet *General;
  TTabSheet *TabSheet2;
  TBevel *bvlCamera;
  TLabel *lblCameraPos;
  TLabel *lblCameraRotateX;
  TBevel *bvlLight;
  TLabel *lblLight;
  TLabel *lblLightPosX;
  TLabel *lblLightPosY;
  TLabel *lblLightPosZ;
  TLabel *lblKa;
  TLabel *lblKd;
  TLabel *lblCameraRotate;
  TLabel *lblCameraRotateZ;
  TLabel *lblLightPos;
  TLabel *lblLightKoef;
  TEdit *edtAlpha;
  TEdit *edtBeta;
  TEdit *edtKs;
  TEdit *edtLightY;
  TEdit *edtLightZ;
  TEdit *edtLightX;
  TEdit *edtKa;
  TColorDialog *ColorDialog;
  TLabel *lblKs;
  TEdit *edtKd;
  TPanel *LightColor;
  TLabel *lblLightColor;
  TLabel *lblMove;
  TLabel *lblScale;
  TLabel *lblRotate;
  TEdit *edtScaleZ;
  TLabel *lblScaleZ;
  TEdit *edtScaleY;
  TLabel *lblScaleY;
  TEdit *edtScaleX;
  TLabel *lblScaleX;
  TEdit *edtRotateZ;
  TLabel *lblRotateZ;
  TEdit *edtRotateY;
  TLabel *lblRotateY;
  TEdit *edtRotateX;
  TLabel *lblRotateX;
  TEdit *edtMoveZ;
  TLabel *lblMoveZ;
  TEdit *edtMoveY;
  TLabel *lblMoveY;
  TEdit *edtMoveX;
  TLabel *lblMoveX;
  TTabSheet *TabSheet1;
  TCheckBox *ClockCheck;
  TLabel *lblArrow;
  TPanel *ModelColor;
  TComboBox *ModelList;
  TButton *btnApply;
  TButton *btnSetHour;
  TButton *btnSetMin;
  TButton *btnSetSec;
  TPanel *StartColor;
  TPanel *FinalColor;
  TButton *btnLightAdd;
  TComboBox *LightList;
  TButton *btnDelete;
  TLabel *lblLightPoint;
  TEdit *edtFileName;
  TSpeedButton *btnFileOpen;
  TLabel *lblFileName;
  TOpenDialog *OpenDialog;
  TLabel *lblModelColor;
  TLabel *lblModel;
  TLabel *lblScene;
  TBevel *Bevel1;
  TLabel *lblGeneral;
  TBevel *Bevel2;
  TLabel *lblBackground;
  TBevel *Bevel3;
  TLabel *lblHour;
  TLabel *lblMin;
  TLabel *lblSec;
  TButton *btnSave;
  TSaveDialog *SaveDialog;
  void __fastcall btnApplyClick(TObject *Sender);
  void __fastcall edtAlphaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall LightColorClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall ClockCheckClick(TObject *Sender);
  void __fastcall ModelListChange(TObject *Sender);
  void __fastcall btnSetHourClick(TObject *Sender);
  void __fastcall btnSetMinClick(TObject *Sender);
  void __fastcall btnSetSecClick(TObject *Sender);
  void __fastcall StartColorClick(TObject *Sender);
  void __fastcall FinalColorClick(TObject *Sender);
  void __fastcall ModelColorClick(TObject *Sender);
  void __fastcall btnLightAddClick(TObject *Sender);
  void __fastcall LightListChange(TObject *Sender);
  void __fastcall btnFileOpenClick(TObject *Sender);
  void __fastcall btnDeleteClick(TObject *Sender);
  void __fastcall edtAlphaKeyPress(TObject *Sender, char &Key);
  void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TfrmSet(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSet *frmSet;
//---------------------------------------------------------------------------
#endif
