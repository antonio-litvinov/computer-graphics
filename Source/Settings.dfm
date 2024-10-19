object frmSet: TfrmSet
  Left = 618
  Top = 114
  BorderStyle = bsToolWindow
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 410
  ClientWidth = 231
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000010000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    00000000000000000000000000000000000000022AAAAAA22000000000000000
    000002AAAAAAAAAAAA200000000000000002AAAA22200222AAAA200000000000
    002AAA200000000002AAA2000000000002AA2000000000000002AA2000000000
    2AA200000000000000002AA200000002AA20000000000000000002AA2000000A
    A2000000000000000220002AA000002AA0002AA2000000000AA2000AA20000AA
    200002AA200000002AAA2002AA0002AA0000022A20000000AA2A2000AA2002A2
    0000002AA2000000AA2000002A200AA200000022A220000AA20000002AA00AA2
    00000002AA20000AA20000002AA00AA0000000002AA200AA200000000AA00AA0
    000000002AA200AA200000000AA00AA20000000002AA22A2000000002AA00AA2
    0000000002AAAAA2000000002AA002A200000000002AAAA0000000002A2002AA
    00000000002AAA2000000000AA2000AA20000000000AAA0000000002AA00002A
    A0000000000AA2000000000AA200000AA2000000002AA0000000002AA0000002
    AA2000002AAA2000000002AA200000002AA200002AAA000000002AA200000000
    02AA2000222200000002AA2000000000002AAA200000000002AAA20000000000
    0002AAAA20000222AAAA200000000000000002AAAAAAAAAAAA20000000000000
    000000022AAAAAA2200000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000}
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 8
    Width = 217
    Height = 369
    ActivePage = General
    TabIndex = 0
    TabOrder = 1
    object General: TTabSheet
      Caption = #1054#1073#1097#1080#1077
      object bvlCamera: TBevel
        Left = 128
        Top = 16
        Width = 73
        Height = 9
        Shape = bsTopLine
      end
      object lblCameraPos: TLabel
        Left = 8
        Top = 8
        Width = 118
        Height = 13
        Caption = #1055#1086#1083#1086#1078#1077#1085#1080#1077' '#1082#1072#1084#1077#1088#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblCameraRotateX: TLabel
        Left = 104
        Top = 64
        Width = 10
        Height = 13
        Caption = 'X:'
      end
      object bvlLight: TBevel
        Left = 80
        Top = 104
        Width = 121
        Height = 9
        Shape = bsTopLine
      end
      object lblLight: TLabel
        Left = 8
        Top = 96
        Width = 69
        Height = 13
        Caption = #1054#1089#1074#1077#1097#1077#1085#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object lblLightPosX: TLabel
        Left = 40
        Top = 200
        Width = 10
        Height = 13
        Caption = 'X:'
      end
      object lblLightPosY: TLabel
        Left = 96
        Top = 200
        Width = 10
        Height = 13
        Caption = 'Y:'
      end
      object lblLightPosZ: TLabel
        Left = 152
        Top = 200
        Width = 10
        Height = 13
        Caption = 'Z:'
      end
      object lblKa: TLabel
        Left = 59
        Top = 272
        Width = 47
        Height = 13
        Alignment = taRightJustify
        Caption = #1060#1086#1085#1086#1074#1072#1103
      end
      object lblKd: TLabel
        Left = 46
        Top = 296
        Width = 60
        Height = 13
        Alignment = taRightJustify
        Caption = #1044#1080#1092#1092#1091#1079#1085#1072#1103
      end
      object lblCameraRotate: TLabel
        Left = 24
        Top = 32
        Width = 137
        Height = 13
        Caption = #1055#1086#1074#1086#1088#1086#1090' '#1086#1090#1085#1086#1089#1080#1090#1077#1083#1100#1085#1086' '#1086#1089#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblCameraRotateZ: TLabel
        Left = 48
        Top = 64
        Width = 10
        Height = 13
        Caption = 'Z:'
      end
      object lblLightPos: TLabel
        Left = 24
        Top = 176
        Width = 146
        Height = 13
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1080#1089#1090#1086#1095#1085#1080#1082#1072' '#1089#1074#1077#1090#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblLightKoef: TLabel
        Left = 24
        Top = 248
        Width = 109
        Height = 13
        Caption = #1057#1086#1089#1090#1072#1074#1083#1103#1102#1097#1080#1077' '#1094#1074#1077#1090#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblKs: TLabel
        Left = 57
        Top = 320
        Width = 49
        Height = 13
        Alignment = taRightJustify
        Caption = #1041#1083#1080#1082#1086#1074#1072#1103
      end
      object lblLightColor: TLabel
        Left = 40
        Top = 224
        Width = 28
        Height = 13
        Caption = #1062#1074#1077#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblLightPoint: TLabel
        Left = 24
        Top = 120
        Width = 80
        Height = 13
        Caption = #1048#1089#1090#1086#1095#1085#1080#1082' '#1089#1074#1077#1090#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object edtAlpha: TEdit
        Left = 64
        Top = 60
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 0
        OnKeyDown = edtAlphaKeyDown
        OnKeyPress = edtAlphaKeyPress
      end
      object edtBeta: TEdit
        Left = 120
        Top = 60
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 1
      end
      object edtKs: TEdit
        Left = 112
        Top = 316
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 10
      end
      object edtLightY: TEdit
        Left = 112
        Top = 196
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 6
      end
      object edtLightZ: TEdit
        Left = 168
        Top = 196
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 7
      end
      object edtLightX: TEdit
        Left = 56
        Top = 196
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 5
      end
      object edtKa: TEdit
        Left = 112
        Top = 268
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 8
      end
      object edtKd: TEdit
        Left = 112
        Top = 292
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 9
      end
      object LightColor: TPanel
        Left = 72
        Top = 228
        Width = 129
        Height = 9
        BevelInner = bvSpace
        BevelOuter = bvLowered
        Color = clWhite
        TabOrder = 11
        OnClick = LightColorClick
      end
      object btnLightAdd: TButton
        Left = 112
        Top = 144
        Width = 41
        Height = 17
        Caption = '+'
        TabOrder = 3
        OnClick = btnLightAddClick
      end
      object LightList: TComboBox
        Left = 40
        Top = 144
        Width = 65
        Height = 21
        BevelInner = bvNone
        BevelKind = bkFlat
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 2
        OnChange = LightListChange
      end
      object btnDelete: TButton
        Left = 160
        Top = 144
        Width = 41
        Height = 17
        Caption = '-'
        TabOrder = 4
        OnClick = btnDeleteClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1055#1088#1077#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103
      ImageIndex = 1
      object lblMove: TLabel
        Left = 8
        Top = 8
        Width = 73
        Height = 13
        Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblScale: TLabel
        Left = 8
        Top = 56
        Width = 94
        Height = 13
        Caption = #1052#1072#1089#1096#1090#1072#1073#1080#1088#1086#1074#1072#1085#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblRotate: TLabel
        Left = 8
        Top = 104
        Width = 43
        Height = 13
        Caption = #1055#1086#1074#1086#1088#1086#1090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblScaleZ: TLabel
        Left = 128
        Top = 80
        Width = 10
        Height = 13
        Caption = 'Z:'
      end
      object lblScaleY: TLabel
        Left = 72
        Top = 80
        Width = 10
        Height = 13
        Caption = 'Y:'
      end
      object lblScaleX: TLabel
        Left = 16
        Top = 80
        Width = 10
        Height = 13
        Caption = 'X:'
      end
      object lblRotateZ: TLabel
        Left = 128
        Top = 128
        Width = 10
        Height = 13
        Caption = 'Z:'
      end
      object lblRotateY: TLabel
        Left = 72
        Top = 128
        Width = 10
        Height = 13
        Caption = 'Y:'
      end
      object lblRotateX: TLabel
        Left = 16
        Top = 128
        Width = 10
        Height = 13
        Caption = 'X:'
      end
      object lblMoveZ: TLabel
        Left = 128
        Top = 32
        Width = 10
        Height = 13
        Caption = 'Z:'
      end
      object lblMoveY: TLabel
        Left = 72
        Top = 32
        Width = 10
        Height = 13
        Caption = 'Y:'
      end
      object lblMoveX: TLabel
        Left = 16
        Top = 32
        Width = 10
        Height = 13
        Caption = 'X:'
      end
      object edtScaleZ: TEdit
        Left = 144
        Top = 76
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 5
        OnKeyDown = edtAlphaKeyDown
      end
      object edtScaleY: TEdit
        Left = 88
        Top = 76
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 4
        OnKeyDown = edtAlphaKeyDown
      end
      object edtScaleX: TEdit
        Left = 32
        Top = 76
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 3
        OnKeyDown = edtAlphaKeyDown
      end
      object edtRotateZ: TEdit
        Left = 144
        Top = 124
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 8
        OnKeyDown = edtAlphaKeyDown
      end
      object edtRotateY: TEdit
        Left = 88
        Top = 124
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 7
        OnKeyDown = edtAlphaKeyDown
      end
      object edtRotateX: TEdit
        Left = 32
        Top = 124
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 6
        OnKeyDown = edtAlphaKeyDown
      end
      object edtMoveZ: TEdit
        Left = 144
        Top = 28
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 2
        OnKeyDown = edtAlphaKeyDown
      end
      object edtMoveY: TEdit
        Left = 88
        Top = 28
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 1
        OnKeyDown = edtAlphaKeyDown
      end
      object edtMoveX: TEdit
        Left = 32
        Top = 28
        Width = 33
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 0
        OnKeyDown = edtAlphaKeyDown
      end
    end
    object TabSheet1: TTabSheet
      Caption = #1057#1094#1077#1085#1072
      ImageIndex = 2
      object lblArrow: TLabel
        Left = 32
        Top = 176
        Width = 103
        Height = 13
        Caption = #1054#1073#1098#1077#1082#1090' '#1082#1072#1082' '#1089#1090#1088#1077#1083#1082#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object btnFileOpen: TSpeedButton
        Left = 184
        Top = 42
        Width = 21
        Height = 21
        Flat = True
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
          0000008080000080800000808000008080000080800000808000008080000080
          80000080800000000000FF00FF00FF00FF00FF00FF00FF00FF000000000000FF
          FF00000000000080800000808000008080000080800000808000008080000080
          8000008080000080800000000000FF00FF00FF00FF00FF00FF0000000000FFFF
          FF0000FFFF000000000000808000008080000080800000808000008080000080
          800000808000008080000080800000000000FF00FF00FF00FF000000000000FF
          FF00FFFFFF0000FFFF0000000000008080000080800000808000008080000080
          80000080800000808000008080000080800000000000FF00FF0000000000FFFF
          FF0000FFFF00FFFFFF0000FFFF00000000000000000000000000000000000000
          00000000000000000000000000000000000000000000000000000000000000FF
          FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
          FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFF
          FF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
          FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000FF
          FF00FFFFFF0000FFFF0000000000000000000000000000000000000000000000
          000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
          00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00000000000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FF00
          FF00FF00FF00FF00FF0000000000FF00FF0000000000FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
          00000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        OnClick = btnFileOpenClick
      end
      object lblFileName: TLabel
        Left = 24
        Top = 24
        Width = 57
        Height = 13
        Caption = #1048#1084#1103' '#1092#1072#1081#1083#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsUnderline]
        ParentFont = False
      end
      object lblModelColor: TLabel
        Left = 32
        Top = 152
        Width = 28
        Height = 13
        Caption = #1062#1074#1077#1090':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblModel: TLabel
        Left = 32
        Top = 128
        Width = 42
        Height = 13
        Caption = #1052#1086#1076#1077#1083#1100':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblScene: TLabel
        Left = 8
        Top = 96
        Width = 37
        Height = 13
        Caption = #1057#1094#1077#1085#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Bevel1: TBevel
        Left = 48
        Top = 104
        Width = 153
        Height = 9
        Shape = bsTopLine
      end
      object lblGeneral: TLabel
        Left = 8
        Top = 8
        Width = 41
        Height = 13
        Caption = #1054#1073#1097#1080#1077
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Bevel2: TBevel
        Left = 56
        Top = 16
        Width = 145
        Height = 9
        Shape = bsTopLine
      end
      object lblBackground: TLabel
        Left = 8
        Top = 272
        Width = 64
        Height = 13
        Caption = #1062#1074#1077#1090' '#1092#1086#1085#1072
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Bevel3: TBevel
        Left = 80
        Top = 280
        Width = 121
        Height = 9
        Shape = bsTopLine
      end
      object lblHour: TLabel
        Left = 112
        Top = 202
        Width = 23
        Height = 13
        Caption = '('#1085#1077#1090')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblMin: TLabel
        Left = 136
        Top = 226
        Width = 23
        Height = 13
        Caption = '('#1085#1077#1090')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblSec: TLabel
        Left = 160
        Top = 250
        Width = 23
        Height = 13
        Caption = '('#1085#1077#1090')'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clGray
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object ClockCheck: TCheckBox
        Left = 40
        Top = 64
        Width = 145
        Height = 17
        Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1082#1072#1082' '#1095#1072#1089#1099
        TabOrder = 1
        OnClick = ClockCheckClick
      end
      object ModelColor: TPanel
        Left = 80
        Top = 156
        Width = 81
        Height = 9
        BevelInner = bvSpace
        BevelOuter = bvLowered
        Color = clWhite
        TabOrder = 6
        OnClick = ModelColorClick
      end
      object ModelList: TComboBox
        Left = 80
        Top = 120
        Width = 81
        Height = 21
        BevelInner = bvNone
        BevelKind = bkFlat
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 2
        OnChange = ModelListChange
      end
      object btnSetHour: TButton
        Left = 48
        Top = 200
        Width = 57
        Height = 17
        Caption = #1063#1072#1089#1086#1074#1072#1103
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        OnClick = btnSetHourClick
      end
      object btnSetMin: TButton
        Left = 64
        Top = 224
        Width = 65
        Height = 17
        Caption = #1052#1080#1085#1091#1090#1085#1072#1103
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnClick = btnSetMinClick
      end
      object btnSetSec: TButton
        Left = 88
        Top = 248
        Width = 65
        Height = 17
        Caption = #1057#1077#1082#1091#1085#1076#1085#1072#1103
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        OnClick = btnSetSecClick
      end
      object StartColor: TPanel
        Left = 24
        Top = 292
        Width = 33
        Height = 17
        BevelInner = bvSpace
        BevelOuter = bvLowered
        Color = clWhite
        TabOrder = 7
        OnClick = StartColorClick
      end
      object FinalColor: TPanel
        Left = 64
        Top = 292
        Width = 33
        Height = 17
        BevelInner = bvSpace
        BevelOuter = bvLowered
        Color = clWhite
        TabOrder = 8
        OnClick = FinalColorClick
      end
      object edtFileName: TEdit
        Left = 40
        Top = 44
        Width = 137
        Height = 17
        BevelInner = bvNone
        BevelKind = bkFlat
        BorderStyle = bsNone
        TabOrder = 0
      end
    end
  end
  object btnApply: TButton
    Left = 8
    Top = 388
    Width = 75
    Height = 17
    Caption = #1055#1088#1080#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = btnApplyClick
  end
  object btnSave: TButton
    Left = 104
    Top = 388
    Width = 121
    Height = 17
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1088#1090#1080#1085#1082#1091
    TabOrder = 2
    OnClick = btnSaveClick
  end
  object ColorDialog: TColorDialog
    Ctl3D = True
    Left = 184
    Top = 312
  end
  object OpenDialog: TOpenDialog
    Filter = #1060#1072#1081#1083' '#1089#1094#1077#1085#1099' (*.ase)|*.ase'
    Title = #1054#1090#1082#1088#1099#1090#1100' '#1089#1094#1077#1085#1091
    Left = 184
    Top = 344
  end
  object SaveDialog: TSaveDialog
    DefaultExt = '*.bmp'
    Filter = #1058#1086#1095#1077#1095#1085#1099#1077' '#1088#1080#1089#1091#1085#1082#1080' (*.bmp)|*.bmp'
    FilterIndex = -1
    Left = 184
    Top = 280
  end
end
