option explicit

dim common Rotinas_sUsuarioLogin = ""
dim common Rotinas_sUsuarioSenha = ""
dim common Rotinas_sBarraLogin = ""
dim common Rotinas_sCodigoSelecionado = ""
dim common Rotinas_sPreco = ""
dim common Rotinas_sQtdEstoque = ""
dim common Rotinas_gConexao = 0
Const sepDTHR = "#" 'SOMENTE ACCESS 
'Const sepDTHR = "'" 'OUTROS BANCOS 

Function Rotinas_modulo11(svalor, ndig)
Dim ncont, nsoma, nstatus
Dim nvalor, npos
Dim sres, slocal

 ncont = 0
 while ncont < 11 
   slocal = Mid$(svalor,ncont+1,1) + slocal
   ncont = ncont+1
 end while
 nsoma = 0
 if ndig=1 then
   ncont = 2
 else
   ncont = 1
 end if
 npos = 2
 while ncont < 11
   sres = Mid$(slocal,ncont+1,1)
   nvalor = Val(sres)
   nsoma = nsoma + (nvalor * npos)
   ncont = ncont+1
   npos = npos+1
 end while
 nsoma = (11 - (nsoma Mod 11))

if nsoma > 9 then
  return 0
else
  return nsoma
end if
End Function

Function Rotinas_ValidaCPF(cpf)
Dim sCPF

If Length(cpf) = 14 Then
  sCPF = Mid$(cpf, 1, 3) & Mid$(cpf, 5, 3) & Mid$(cpf, 9, 3) &
	 Mid$(cpf, 13, 2)
  If ((Rotinas_modulo11(sCPF, 1) = Val(Mid$(cpf, 13, 1))) And 
     (Rotinas_modulo11(sCPF, 2) = Val(Mid$(cpf, 14, 1)))) Then
    return True
  Else
    return False
  End If
Else
  return False
End If
End Function

Function Rotinas_ValidaISBN(isbn)
Dim snum, sdigito, sisbn
Dim nvalor, nsoma
Dim nstatus, ncont

If Length(isbn) = 13 Then
  sdigito = Mid$(isbn,Length(isbn), 1)
  sisbn=""
  for ncont=1 to Length(isbn)
    if Mid$(isbn,ncont,1)<>"-" then
      sisbn=sisbn & Mid$(isbn,ncont,1)
    end if
  next
  if sdigito = "X" then
    nsoma = 10
  else
    nvalor = Val(sdigito)
    nsoma = nvalor
  end if
  for ncont = 1 to 9
    snum = Mid$(sisbn,ncont, 1)
    nvalor = Val(snum)
    nsoma = nsoma + (nvalor * (11 - ncont))
  next
  If (nsoma Mod 11) = 0 Then
    return True
  else
    return False
  end if
Else
  return False
End If
End Function

function Rotinas_validaDataHora(sDataHora, bSoData)
dim bvalida, bdatavalida, bhoravalida
dim sdia, smes, sano, shora, smin, sseg
dim ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam

bvalida = False
bdatavalida = False
bhoravalida = False
nudiames = 0
if bSoData=True then 
  ntam=10
else 
  ntam=19
end if

if Length(sDataHora)=ntam then
  sdia = Mid$(sDataHora,1,2)
  ndia = Val(sdia)
  smes = Mid$(sDataHora,4,2)
  nmes = Val(smes)
  sano = Mid$(sDataHora,7,4)
  nano = Val(sano)
  
  if (nano >= 1) and (nano <= 9999) then
    if (nmes >= 1) and (nmes <= 31) then
      Select Case nmes
        Case 1, 3, 5, 7, 8, 10, 12
          nudiames = 31
        Case 2
          ' ano bissexto 
          if (nano mod 4)=0 then 
            nudiames = 29
          else 
            nudiames = 28
          end if
        Case 4, 6, 9, 11
          nudiames = 30
      End Select
      if (ndia >=1) and (ndia <=nudiames) then
         bdatavalida = True
      end if
    end if
  end if

  if bSoData then
    if bdatavalida then
      bvalida = True
    else
      bvalida = False
    end if
  else 
    if bdatavalida then
      shora = Mid$(sDataHora,12,2)
      nhora = Val(shora)
      smin = Mid$(sDataHora,15,2)
      nmin = Val(smin)
      sseg = Mid$(sDataHora,18,2)
      nseg = Val(sseg)
    
      if (nhora >= 0) and (nhora <= 23) then
        if (nmin >= 0) and (nmin <= 59) then
          if (nseg >= 0) and (nseg <= 59) then
            bhoravalida = True
          end if
        end if
      end if
    
      if bhoravalida then
        bvalida = True
      else
        bvalida = False
      end if
    else
      bvalida = False
    end if
  end if
else
  bvalida = False
end if
return bvalida
end function

function Rotinas_retDataHoraStr(bData, bHora)
dim sDataHora = ""
dim sData = ""
sData = Mid$(Date$,4,2) & "/" & Mid$(Date$,1,2) & "/" & Mid$(Date$,7,4)

If bData and bHora Then
  sDataHora = sData & " " & Time$
ElseIf bData Then
  sDataHora = sData
ElseIf bHora Then
  sDataHora = Time$
End If
return sDataHora
end function

Function Rotinas_ValidaCampo(sCampo, sMensagemErro)
  If sCampo = "" Then
    wxMessageBox(sMensagemErro, "Erro", wxOK + wxICON_ERROR )
    return True
  End If
  return False
End Function

sub Rotinas_AdicionaColunasGrid(lista, nPosIni, nQtdCols,
                                nLargura[], sRotulos[])
  dim nPos, nCont

  nCont = 0
  for nPos = nPosIni to (nPosIni + nQtdCols - 1)
    lista.InsertColumnInfo(nPos, sRotulos[nCont], 0, nLargura[nCont])
    nCont = nCont + 1
  next
end sub
