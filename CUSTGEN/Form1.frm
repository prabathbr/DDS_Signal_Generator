VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   8940
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   12900
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   443.535
   ScaleMode       =   0  'User
   ScaleWidth      =   325.758
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Clear"
      Height          =   495
      Left            =   10680
      TabIndex        =   5
      Top             =   1800
      Width           =   1575
   End
   Begin VB.TextBox Text3 
      Height          =   855
      Left            =   480
      TabIndex        =   4
      Top             =   6600
      Width           =   10215
   End
   Begin VB.TextBox Text2 
      Height          =   855
      Left            =   480
      MultiLine       =   -1  'True
      ScrollBars      =   2  'Vertical
      TabIndex        =   3
      Top             =   5640
      Width           =   10335
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Do"
      Height          =   495
      Left            =   10680
      TabIndex        =   2
      Top             =   1200
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Left            =   10680
      TabIndex        =   1
      Top             =   480
      Width           =   1575
   End
   Begin VB.PictureBox Picture1 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      ForeColor       =   &H80000008&
      Height          =   5160
      Left            =   480
      ScaleHeight     =   255
      ScaleMode       =   0  'User
      ScaleWidth      =   257.103
      TabIndex        =   0
      Top             =   360
      Width           =   10138
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'Variables used for the drawing tool.
Dim Drawing As Boolean
Dim FHLastX As Long
Dim FHLastY As Long
Dim x1 As Integer
Dim y1 As Integer
Dim got As Boolean
Dim buf As Integer






Private Sub Command1_Click()
For x1 = 0 To 63
got = False
For y1 = 0 To 255
If (Picture1.Point(x1 * 4, y1) = 0) And (got = False) Then
If Text2.Text = "" Then
Text2.Text = Val(255 - y1)
Text3.Text = Chr$(Val(255 - y1))
Else
Text2.Text = Text2.Text & " " & Val(255 - y1)
Text3.Text = Text3.Text & Chr$(Val(255 - y1))
End If
buf = (255 - y1)
got = True
End If
Next y1
If (got = False) Then
If Text2.Text = "" Then
Text2.Text = "" & Val(buf)
Text3.Text = Chr$(Val(buf))
Else
Text2.Text = Text2.Text & " " & Val(buf)
Text3.Text = Text3.Text & Chr$(Val(buf))
End If
End If
Next x1

End Sub

Private Sub Command2_Click()
Text2.Text = ""
Text3.Text = ""
Picture1.Picture = Nothing
End Sub

Private Sub Picture1_MouseDown(Button As Integer, _
 Shift As Integer, x As Single, Y As Single)
    Drawing = True
    'Specify that we are drawing now.
    
    
    'Start where the mouse cursor is.
    FHLastX = x
    FHLastY = Y

End Sub

Private Sub Picture1_MouseMove(Button As Integer, _
 Shift As Integer, x As Single, Y As Single)
    
    'This is the technique we are using to
    'draw freehand decently. Instead of drawing each point,
    'we join the points up with lines. This is required as the
    'MouseMove event will not fire on every pixel.
    If Drawing = True Then
    Picture1.Line (FHLastX, FHLastY)-(x, Y)
    End If
    FHLastX = x
    FHLastY = Y
Text1.Text = Val(x) & " " & Val(Y)


End Sub

Private Sub Picture1_MouseUp(Button As Integer, _
 Shift As Integer, x As Single, Y As Single)
    
    'Stop drawing.
    Drawing = False

End Sub


