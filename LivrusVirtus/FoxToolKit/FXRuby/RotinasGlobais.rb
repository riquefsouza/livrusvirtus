require 'fox'
require 'DBI'
# require 'DBD::ODBC'

require 'resource'
require 'ListaStr'

include Fox
$Rotinas = nil

class RotinasGlobais
  attr :gConexao, true
  attr :sBarraLogin, true
  attr :sUsuarioLogin, true
  attr :sUsuarioSenha, true
  attr :sCodigoSelecionado, true
  attr :sPreco, true
  attr :sQtdEstoque, true
  SepDTHR = "#" #SOMENTE ACCESS
  #SepDTHR = "'" #OUTROS BANCOS

  # Ler uma figura do arquivo
  def lerFigura(form, nomearquivo)
    begin
      nomearquivo = File.join("bmps", nomearquivo)
      figura = nil
      File.open(nomearquivo, "rb") { |f|
        #figura = FXPNGIcon.new(getApp(), f.read)
	      figura = FXBMPIcon.new(form, f.read)
      }
      return figura
    rescue
      raise RuntimeError, "Não posso ler a figura: #{nomearquivo}"
    end
  end

  def ValidaFloat(sNum)
    if sNum != ""
      if sNum.to_f > 0
        return true
      else
        FXMessageBox.error(nil, MBOX_OK, "Erro", Resource::STR_NUMINV)
        return false
      end
    else
     return false
    end
  end 

  def VirgulaParaPonto(sNum, bRevertido)
    if (bRevertido)
      return sNum.sub(/[.]/, ',')
    else
      return sNum.sub(/[,]/, '.')
    end
  end

  def modulo11(svalor, ndig)
    ncont, nsoma, npos, nvalor = 0,0,0,0
    sres, slocal = "", ""
  
    ncont=1
    while ncont <= 11 do
      slocal=svalor.slice(ncont-1,1) + slocal
      ncont=ncont+1
    end
    nsoma=0
    if ndig == 1 then
      ncont=3
    else
      ncont=2
    end
    npos=2
    while ncont <= 11 do
      sres=slocal.slice(ncont-1,1)
      nvalor = sres.to_i
      nsoma=nsoma + (nvalor * npos)
      ncont=ncont+1
      npos=npos+1
    end
    nsoma=(11 - (nsoma % 11))
    
    if nsoma > 9
      return 0
    else
      return nsoma
    end
  end

  def validaCPF(cpf)
    scpf, sres = "", ""
    nvalor1, nvalor2 = 0,0
    
    if cpf.length==14 then
      scpf=cpf.slice(0,3)+cpf.slice(4,3)+cpf.slice(8,3)+cpf.slice(12,2)
      sres=cpf.slice(12,1)
      nvalor1 = sres.to_i
      sres=cpf.slice(13,1)
      nvalor2 = sres.to_i
      if (modulo11(scpf,1)==nvalor1) and (modulo11(scpf,2)==nvalor2)
        return true
      else
        return false
      end
    else
      return false
    end
  end

  def validaISBN(isbn)
    snum, sdigito, sisbn = "", "", ""
    ncont, nsoma, nvalor = 0,0,0
  
    if isbn.length==13 then
      sdigito=isbn.slice(isbn.length-1, 1)
      sisbn = ""
      for ncont in (1..isbn.length-1) do
        if isbn.slice(ncont-1,1)!="-" then
          sisbn=sisbn+isbn.slice(ncont-1,1)
        end
      end
      if sdigito == "X" then
        nsoma = 10
      else
        nvalor = sdigito.to_i
        nsoma = nvalor
      end
      for ncont in (1..9) do
        snum=sisbn.slice(ncont-1, 1)
        nvalor = snum.to_i
        nsoma=nsoma + (nvalor * (11 - ncont))
      end
      if (nsoma % 11) == 0
        return true
      else
        return false
      end
    else
      return false
    end
  end

  def validaDataHora(sDataHora, bSoData)
    sdia, smes, sano, shora, smin, sseg = "","","","","",""
    ndia, nmes, nano, nhora, nmin, nseg, ntam = 0,0,0,0,0,0,0 
    
    bvalida=false
    bdatavalida=false
    bhoravalida=false
    nudiames=0
    
    if bSoData==true then ntam=10
    else ntam=19
    end
    if sDataHora.length==ntam then
      sdia=sDataHora.slice(0,2)
      ndia=sdia.to_i
      smes=sDataHora.slice(3,2)
      nmes=smes.to_i
      sano=sDataHora.slice(6,4)
      nano=sano.to_i
    
      if (nano >= 1) and (nano <= 9999) then
        if (nmes >= 1) and (nmes <= 31) then
            case nmes
              when 1, 3, 5, 7, 8, 10, 12
                nudiames=31
              when 2
                 # ano bissexto
                 if (nano % 4)==0 then 
                   nudiames=29
                 else 
                   nudiames=28
                 end
               when 4, 6, 9, 11
                 nudiames=30
            end
            if (ndia >=1) and (ndia <=nudiames) then
               bdatavalida=true
            end 
        end
      end
    
      if bSoData then
         if bdatavalida then 
           bvalida=true
         else 
           bvalida=false
         end 
      else
        if bdatavalida then
            shora=sDataHora.slice(11,2)
            nhora = shora.to_i
            smin=sDataHora.slice(14,2)
            nmin = smin.to_i
            sseg=sDataHora.slice(17,2)
            nseg = sseg.to_i
    
            if (nhora >= 0) and (nhora <= 23) then
              if (nmin >= 0) and (nmin <= 59) then
                if (nseg >= 0) and (nseg <= 59) then
                   bhoravalida=true
                end
              end
            end
    
            if bhoravalida then 
               bvalida=true
            else 
               bvalida=false
            end
        else
          bvalida=false
        end
      end
    else
      bvalida=false
    end
    return bvalida
  end

  def retDataHoraStr(bData, bHora)
    sDataHora = ''
    sTempo = Time.now 
    if (bData) and (bHora) then
      sDataHora = sTempo.strftime("%d/%m/%Y %H:%M:%S")
    elsif bData then
      sDataHora = sTempo.strftime("%d/%m/%Y")
    elsif bHora then
      sDataHora = sTempo.strftime("%H:%M:%S")
    end
    return sDataHora
  end

  def ConverteDataHoraStr(sDTHR, bDMY_ou_YMD, sFrmtData, sFrmtHora)
    sDataHora = ''
    
    if sFrmtData.length > 0 then
      if bDMY_ou_YMD then
        ndia = sDTHR.slice(0, 2)
        nmes = sDTHR.slice(3, 2)
        nano = sDTHR.slice(6, 4)
      else
        nano = sDTHR.slice(0, 4)
        nmes = sDTHR.slice(5, 2)
        ndia = sDTHR.slice(8, 2)
      end
    end
    if sFrmtHora.length > 0 then
      nhora = sDTHR.slice(11, 2)
      nmin = sDTHR.slice(14, 2)
      nseg = sDTHR.slice(17, 2)
    end
    sTempo = Time.local(nano, nmes, ndia, nhora, nmin, nseg, 0)
    if sFrmtHora.length > 0 then
      sDataHora = sTempo.strftime( sFrmtData + ' ' + sFrmtHora )
    else
      sDataHora = sTempo.strftime( sFrmtData + ' 00:00:00' )
    end
    return sDataHora
  end

  def ConectaBanco(sBancoDeDados, sLogin, sSenha)
    begin
      self.gConexao = DBI.connect( sBancoDeDados, sLogin, sSenha ) 
      return true
    rescue
      FXMessageBox.error(nil, MBOX_OK, "Erro", Resource::STR_NCONBANCO)
      return false
    end
  end
  
  def DisconectaBanco()
    self.gConexao.disconnect()
  end

  def AtualizaDados(hBancoLocal, sSql)
    begin
      sth = hBancoLocal.prepare( sSql )
      sth.execute()
      sth.finish()
      return true
    rescue
      FXMessageBox.error(nil, MBOX_OK, "Erro", Resource::STR_NCEXECSQL)
      return false
    end
  end

  def ConsultaDados(hBancoLocal, sSql)
    sth = hBancoLocal.prepare( sSql )
    rc = sth.execute()
    if rc then
      $ListaMStr.col = sth.fetch
      if $ListaMStr.col then
        $ListaMStr.tam = $ListaMStr.col.length
        sth.finish()
        if $ListaMStr.tam > 0 then
          return true
        else
          return false
        end
      else
        return false
      end
    else
      FXMessageBox.error(nil, MBOX_OK, "Erro", Resource::STR_NCEXECSQL)
      sth.finish()
      return false
    end
  end

  def arrumaColunas(sth)
    lstLinhas = []
    nCol = 0
    nLinha = 0
    while sDBILinha = sth.fetch do
      lstCols = []		
      for nCol in (0..sDBILinha.length-1) do
        if sDBILinha[nCol].class == String then
          lstCols[nCol] = sDBILinha[nCol]
        elsif sDBILinha[nCol].class == Fixnum then
          lstCols[nCol] = sDBILinha[nCol].to_s
        elsif sDBILinha[nCol].class == Float then
          lstCols[nCol] = "%.2f" % sDBILinha[nCol]
        else
          lstCols[nCol] = sDBILinha[nCol].to_time.strftime('%d/%m/%Y %H:%M:%S')
        end
      end
      lstLinhas[nLinha] = lstCols
      nLinha+=1
    end
    return lstLinhas
  end

  def ConsultaDadosLista(hBancoLocal, lstLocal, sSql)
    sth = hBancoLocal.prepare( sSql )
    rc = sth.execute()
    if rc then
      lstLocal.col = arrumaColunas(sth)
      if lstLocal.col then
        lstLocal.tam = lstLocal.col.length     
        if lstLocal.tam > 0 then
          sth.finish()
          return true
        end
      else
        return false
      end
    else
      FXMessageBox.error(nil, MBOX_OK, "Erro", Resource::STR_NCEXECSQL)
      sth.finish()
      return false
    end
  end

  def ValidaCampo(sCampo, sMensagemErro)
    if sCampo.strip == "" then
      FXMessageBox.error(nil, MBOX_OK, "Erro", sMensagemErro)
      return true
    else
      return false
    end
  end

  def ConsultaCampoDesc(lstCampos, sTextoSql, sMensagemErro)
    sret = ""
    if ConsultaDadosLista(self.gConexao, lstCampos, sTextoSql) then
      sret = lstCampos.col[0][1]
    else
      #FXMessageBox.error(nil, MBOX_OK, "Erro", sMensagemErro)
      sret = ""
    end
    return sret
  end

  def AdicionaItemLista(lstLista, slCodLista, sCampoCodigo, sCampoDesc)   
    if sCampoDesc.getText().length > 0    
      sCodigo = sCampoCodigo.getText()
      sDesc = sCampoDesc.getText()
      
      sItems = sCodigo + ' - ' + sDesc
      
      if lstLista.findItem(sItems) == -1
        slCodLista.col.push(sCodigo) 
        lstLista.appendItem(sItems)
      end
      sCampoCodigo.setText("")
      sCampoDesc.setText("")
    end 
  end
  
  def RemoveItemLista(lstLista, slCodLista)
     if lstLista.getNumItems() > 0
       nSelIndice = lstLista.getCurrentItem()
       if lstLista.isItemCurrent(nSelIndice)
         slCodLista.col.delete_at(nSelIndice)
    	   lstLista.removeItem(nSelIndice)
       end
     end
  end
  
  def AdicionaValoresLista(sTextoSql, lstLista, slCodLista)
    lstCampos = LISTAMSTR.new
    nLinha = 0
  
    lstLista.clearItems()
    slCodLista.col = []
    if ConsultaDadosLista(self.gConexao, lstCampos, sTextoSql)
      for nLinha in (0..lstCampos.tam-1) do
        sCodigo = lstCampos.col[nLinha][0]
        sDesc = lstCampos.col[nLinha][1]
  
  	    slCodLista.col.push(lstCampos.col[nLinha][0])
        sItems = sCodigo + ' - ' + sDesc
  	    lstLista.appendItem(sItems)
  	  end
    end
  end
  
  def AdicionaColunasGrid(grid, nPosIni, nQtdCols, nLargura, sRotulos) 
    #if (nPosIni > 1)
    #  grid.insertColumns(nPosIni, nQtdCols)
    #end
    nCont = 0
    for nPos in (nPosIni..(nPosIni+nQtdCols-1)) do
      grid.setColumnWidth(nPos, nLargura[nCont])
      grid.setItemText(0, nPos, sRotulos[nCont])  
      nCont = nCont + 1
    end
  end
  
  def AdicionaLinhasGrid(grid, lstLinhas, nQtdCol)  
    if (grid.getNumRows() > 1)
      grid.removeRows(1, grid.getNumRows()-1)  
    end  
    grid.insertRows(1, lstLinhas.tam())

    for nLinha in (1..grid.getNumRows()-1) do
      grid.setItemText(nLinha, 0, nLinha.to_s)
      grid.getItem(nLinha, 0).setButton(true)
    end
    for nCol in (1..nQtdCol) do
      for nLinha in (1..lstLinhas.tam) do
        sLinha = lstLinhas.col[nLinha-1][nCol-1]
        grid.setItemText(nLinha, nCol, sLinha)
        grid.getItem(nLinha, nCol).justify = FXTableItem::RIGHT
        if (nCol > 1)
          grid.getItem(nLinha, nCol).justify = FXTableItem::LEFT
        end
      end
    end
  end

  def IniciaLayoutGrid(grid, nQtdLinhas, nQtdCols)
    grid.setTableSize(nQtdLinhas, nQtdCols)

    grid.leadingRows = 1
    grid.leadingCols = 1
    #grid.trailingRows = 1
    #grid.trailingCols = 1

    grid.setItemText( 0,  0, "")
    grid.setItemText( 0, nQtdCols-1, "")
    grid.setItemText(nQtdLinhas-1,  0, "")
    grid.setItemText(nQtdLinhas-1, nQtdCols-1, "")
    
    for nCol in (1..nQtdCols-1) do
      grid.setItemText(0, nCol, "")
      grid.getItem(0, nCol).setButton(true)
      grid.getItem(0, nCol).justify = FXTableItem::LEFT
    end
    
    for nLinha in (1..nQtdLinhas-1) do
      grid.setItemText(nLinha, 0, nLinha.to_s)
      grid.getItem(nLinha, 0).setButton(true)
    end
    grid.getItem(0, 0).setButton(true)

    grid.setItemText(0, 1, "Código")
    grid.setColumnWidth(1, 80)
    grid.setItemText(0, 2, "Descrição")
    grid.setColumnWidth(2, 180)
  end

end
