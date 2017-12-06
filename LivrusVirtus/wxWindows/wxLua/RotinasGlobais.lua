local Rotinas_sUsuarioLogin = ""
local Rotinas_sUsuarioSenha = ""
local Rotinas_sBarraLogin = ""
local Rotinas_sCodigoSelecionado = ""
local Rotinas_sPreco = ""
local Rotinas_sQtdEstoque = ""
local Rotinas_gConexao = 0
sepDTHR = "#" --SOMENTE ACCESS 
--sepDTHR = "'" --OUTROS BANCOS 

function Rotinas_modulo11(svalor, ndig)
 ncont=1
 slocal='' 
 sres=''
 while (ncont <= 11) do
   slocal=svalor.sub(ncont,ncont) .. slocal
   ncont=ncont+1
 end
 nsoma=0
 if ndig==1 then
   ncont=3
 else
   ncont=2
 end
 npos=2
 while (ncont <= 11) do
   sres = slocal.sub(ncont,ncont)
   nvalor = tonumber(sres)
   nsoma=nsoma + (nvalor * npos)
   ncont=ncont+1
   npos=npos+1
 end
 nsoma=(11 - math.mod(nsoma, 11))

 if nsoma > 9 then
   return 0
 else
   return nsoma
 end
end

function Rotinas_validaCPF(cpf)
  if string.len(cpf)==14 then
    scpf=cpf.sub(1,3)..cpf.sub(5,7)..cpf.sub(9,11)..cpf.sub(13,14)
    sres=cpf.sub(13,13)
    nvalor1 = tonumber(sres)
    sres=cpf.sub(14,14)
    nvalor2 = tonumber(sres)
    if (Rotinas_modulo11(scpf,1)==nvalor1) and 
       (Rotinas_modulo11(scpf,2)==nvalor2) then
      return true
    else
      return false
    end
  else
    return false
  end
end

function Rotinas_validaISBN(isbn)
  if string.len(isbn)==13 then
    sdigito = isbn.sub(string.len(isbn), string.len(isbn))
    sisbn=''
    for ncont = 1, string.len(isbn)-1 do
      if isbn.sub(ncont,ncont)~='-' then
        sisbn=sisbn..isbn.sub(ncont,ncont)
      end 
    end
    if sdigito == 'X' then
      nsoma = 10
    else
      nvalor = tonumber(sdigito)
      nsoma = nvalor
    end
    for ncont = 1, 9 do
      snum=sisbn.sub(ncont, ncont)
      nvalor = tonumber(snum)
      nsoma=nsoma + (nvalor * (11 - ncont))
    end
    if math.mod(nsoma, 11) == 0 then
      return true
    else
      return false
    end
  else
    return false
  end
end

function Rotinas_validaDataHora(sDataHora, bSoData)
local sdia, smes, sano, shora, smin, sseg
local ndia, nmes, nano, nhora, nmin, nseg
bvalida=false
bdatavalida=false
bhoravalida=false
nudiames=0
if bSoData==true then ntam=10
else ntam=19 end

if string.len(sDataHora)==ntam then
  sdia=sDataHora.sub(1,2)
  ndia=tonumber(sdia)
  smes=sDataHora.sub(4,5)
  nmes=tonumber(smes)
  sano=sDataHora.sub(7,10)
  nano=tonumber(sano)

  if (nano >= 1) and (nano <= 9999) then
    if (nmes >= 1) and (nmes <= 31) then 
        if nmes==1 or nmes==3 or nmes==5 or nmes==7 or 
           nmes==8 or nmes==10 or nmes==12 then 
           nudiames=31
        elseif nmes==2 then
             -- ano bissexto 
             if math.mod(nano, 4)==0 then nudiames=29
             else nudiames=28 end
        elseif nmes==4 or nmes==6 or nmes==9 or nmes==11 then 
          nudiames=30
        end
        if (ndia >=1) and (ndia <=nudiames) then
           bdatavalida = true
        end 
    end
  end

  if bSoData==true then 
     if bdatavalida==true then 
       bvalida=true
     else 
       bvalida=false 
     end
  else 
    if bdatavalida==true then
        shora=sDataHora.sub(12,13)
        nhora = tonumber(shora)
        smin=sDataHora.sub(15,16)
        nmin=tonumber(smin)
        sseg=sDataHora.sub(18,19)
        nseg=tonumber(sseg)

        if (nhora >= 0) and (nhora <= 23) then
          if (nmin >= 0) and (nmin <= 59) then
            if (nseg >= 0) and (nseg <= 59) then
               bhoravalida=true
            end
          end
        end
    
        if bhoravalida==true then bvalida=true
        else bvalida=false end
    else
      bvalida=false 
    end
  end
else
  bvalida=false 
end
return bvalida
end

function Rotinas_retDataHoraStr(bData, bHora)
sDataHora = ""

if bData and bHora then
  sDataHora = os.date('%d/%m/%Y %H:%M:%S')
elseif bData then
  sDataHora = os.date('%d/%m/%Y')
elseif bHora then
  sDataHora = os.date('%H:%M:%S')
end
return sDataHora
end

function Rotinas_ValidaCampo(sCampo, sMensagemErro)
  if sCampo == "" then
    wx.wxMessageBox(sMensagemErro, "Erro", wx.wxOK + wx.wxICON_ERROR )
    return true
  end
  return false
end

function Rotinas_AdicionaColunasGrid(grid, nPosIni, nQtdCols, 
  nLargura, sRotulos)
  local nPos, nCont
  
  if nPosIni > 0 then
    grid:AppendCols(nQtdCols)
  end
  nCont = 0
  for nPos = nPosIni, (nPosIni+nQtdCols-1) do
    grid:SetColSize(nPos, nLargura[nCont])
    grid:SetColLabelValue(nPos, sRotulos[nCont])
    nCont = nCont + 1
  end
end
