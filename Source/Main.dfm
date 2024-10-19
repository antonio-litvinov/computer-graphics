object MainForm: TMainForm
  Left = 192
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #1050#1091#1088#1089#1086#1074#1072#1103' '#1088#1072#1073#1086#1090#1072' '#1087#1086' '#1084#1072#1096#1080#1085#1085#1086#1081' '#1075#1088#1072#1092#1080#1082#1077
  ClientHeight = 410
  ClientWidth = 418
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 13
  object Image: TImage
    Left = 8
    Top = 8
    Width = 401
    Height = 393
    OnMouseDown = ImageMouseDown
  end
  object Timer: TTimer
    OnTimer = TimerTimer
    Left = 368
    Top = 336
  end
end
