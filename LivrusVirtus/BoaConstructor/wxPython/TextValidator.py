from wxPython.wx import *
import string

class TextValidator(wxPyValidator):
  FILTER_NONE = 0
  FILTER_ALPHA = 1
  FILTER_NUMERIC = 2

  def __init__(self, flag=None, pyVar=None):
    wxPyValidator.__init__(self)
    self.flag = flag
    EVT_CHAR(self, self.OnChar)

  def Clone(self):
    return TextValidator(self.flag)

  def Validate(self, win):
    tc = self.GetWindow()
    val = tc.GetValue()
    if self.flag == self.FILTER_ALPHA:
      for x in val:
        if x not in string.letters:
          return False

    elif self.flag == self.FILTER_NUMERIC:
      for x in val:
        if x not in string.digits:
          return False

    elif self.flag == self.FILTER_NONE:
      return True

    return True

  def OnChar(self, event):
    if self.flag != self.FILTER_NONE:
      key = event.KeyCode()
      if key < WXK_SPACE or key == WXK_DELETE or key > 255:
        event.Skip()
        return
      if self.flag == self.FILTER_ALPHA and chr(key) in string.letters:
        event.Skip()
        return
      if self.flag == self.FILTER_NUMERIC and chr(key) in string.digits:
        event.Skip()
        return
  
      if not wxValidator_IsSilent():
        wxBell()

      return

    else:
      event.Skip()

