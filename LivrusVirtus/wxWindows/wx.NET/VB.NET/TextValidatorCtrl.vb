Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class TextValidatorCtrl
		Inherits wx.TextCtrl
	
		public shared FILTER_NONE as integer = 0
		public shared FILTER_ALPHA as integer = 1
		public shared FILTER_NUMERIC as integer = 2
    private nLocalFiltro as integer

    Public Sub New(ByVal parent as Window, ByVal id as integer, _
      ByVal valor as string, ByVal pos as System.Drawing.Point, _
      ByVal size as System.Drawing.Size, ByVal estilo as long, _
      ByVal nfiltro as integer)
      MyBase.New(parent, id, valor, pos, size, estilo, nothing, "")

      nLocalFiltro = nfiltro
			EVT_CHAR( new EventListener(AddressOf OnChar ) )
    End Sub

		public sub OnChar(ByVal sender As Object, ByVal e As wx.Event)
      dim ke as wx.KeyEvent
      dim nChave as integer

      ke = CType(e, wx.KeyEvent)
      nChave = ke.KeyCode
    
      if (nLocalFiltro <> FILTER_NONE) then 
        if (nChave < wx.KeyCode.WXK_SPACE) or _
          (nChave = wx.KeyCode.WXK_DELETE) or (nChave > 255) then
          e.Skip()
        else if (nLocalFiltro = FILTER_ALPHA) then 
          if (nChave >= 65 and nChave <= 90) or (nChave >= 97 and nChave <= 122)  then
            e.Skip()
          end if
        else if (nLocalFiltro = FILTER_NUMERIC) then
          if (nChave >= 48 and nChave <= 57) then
            e.Skip()
          end if
        else
          e.Skip()
        end if
      else
        e.Skip()
      end if
		End Sub

	End Class

End Namespace
