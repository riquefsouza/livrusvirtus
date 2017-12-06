C     ------------------------------------------------------------------
C     Sistema integrante do projeto Livrus Virtus.
C     Todos os direitos reservados para Henrique F. de Souza.
C     Versão programada na linguagem fortran 77.
C     ------------------------------------------------------------------
      program Livrus
      include 'livrus.h'
C     ---------
C     variaveis
C     ---------
      logical bopcao, frmlogin
      character*255 repete, srepete, retDataHora, ftrim
      character opmenu
      character sarg      
      integer modulo11
C     ------------------------------------------------------------------
C     Parte inicial do código
C     ------------------------------------------------------------------
      Call GetArg(0, sarg)
      if (sarg.eq.'-cria') then
         call abrecriaArqs(.false.)
      else
        call frmSplash
        call abrecriaArqs(.true.)
        if (frmLogin() .eqv. .true.) then
          bopcao = .true.
          do while (bopcao)
           call menu(1)
           read(*,'(A1)') opmenu
           if (opmenu.eq.'C' .or. opmenu.eq.'c') then
             call usaMenu(1)
           else if (opmenu.eq.'P' .or. opmenu.eq.'p') then
             call usaMenu(2)
           else if (opmenu.eq.'V' .or. opmenu.eq.'v') then
             call usaMenu(3)
           else if (opmenu.eq.'O' .or. opmenu.eq.'o') then
             call usaMenu(4)
           else
             write(*,*) MSG_ERRO
           end if
          end do
        else
         call fechaArqs
         stop
        end if
      end if

      stop
      end
C     ------------------------------------------------------------------
C     Bloco de dados
C     ------------------------------------------------------------------
      block data
      include 'livrus.h'
C     ctTipo
      data opTexto /1/ 
      data opNumero /2/
      data opData /3/
      data opDataHora /4/
      data opSenha /5/
C     ctArqs
      data opAssunto /1/
      data opAutor /2/
      data opEditora /3/
      data opEndereco /4/
      data opIdioma /5/
      data opPais /6/
      data opProfissao /7/
      data opCliente /8/
      data opLivro /9/
      data opLivroAss /10/
      data opLivroAut /11/
      data opUsuario /12/
      data opVenda /13/
C     ctAcao
      data opNovo /1/
      data opAlterar /2/
      data opPesquisar /3/
      data opSalvarInclusao /4/
      data opSalvarAlteracao /5/
      data opExcluir /6/
      data opConfirmaExclusao /7/
      data opListarTodos /8/

      data TAM_CRLF /2/
      data QTD_MAX_LINHA /18/
      data MSG_ERRO / 'Erro: opcao invalida digite de novo' /
      data MSG_OPCAO / 'Escolha uma opção: ' /
      data MSG_PRESS / 'pressione para continuar...' /
      data MSG_ARQERRO / 'Erro: O arquivo não pode ser aberto.' / 

      data MSG_REGINC / 'registro incluido!' /
      data MSG_REGNINC / 'registro não incluido!' /
      data MSG_REGALT / 'registro alterado!' /
      data MSG_REGNALT / 'registro não alterado!' /
      data MSG_REGEXC / 'registro excluido!' /
      data MSG_REGNEXC / 'registro não excluido!' /
      data MSG_REGEXST / 'registro já existe!' /

      data MSG_NUMINV / 'Número inválido ou menor do que 1!' /
      data MSG_DATAINV / 'Data inválida!, formato correto (dd/mm/yyyy)'/
      data MSG_DTHRINV / 
     *'Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)' /
      data MSG_ISBNINV / 'ISBN inválido!' /
      data MSG_CPFINV / 'CPF inválido!' /
      data MSG_SENCONFERE / 'senha não confere com a senha atual!' /
      data MSG_SENCONFIRM / 
     *'nova senha não confere com a senha confirmada!' /
      data MSG_LOGINENCON / 'login não encontrado!' /
      data MSG_SEMESTOQUE / 'livro não existe no estoque!' /

      data ARQ_ASSUNTO /'assunto.dat'/
      data ARQ_AUTOR /'autor.dat'/
      data ARQ_EDITORA /'editora.dat'/
      data ARQ_IDIOMA /'idioma.dat'/
      data ARQ_USUARIO /'usuario.dat'/
      data ARQ_PAIS /'pais.dat'/
      data ARQ_PROFISSAO /'profissao.dat'/
      data ARQ_LIVRO /'livro.dat'/
      data ARQ_LIVASS /'livroass.dat'/
      data ARQ_LIVAUT /'livroaut.dat'/
      data ARQ_CLIENTE /'cliente.dat'/
      data ARQ_ENDERECO /'endereco.dat'/
      data ARQ_VENDA /'venda.dat'/

      data TAM_ASSUNTO /40/
      data TAM_AUTOR /40/
      data TAM_EDITORA /60/
      data TAM_IDIOMA /30/
      data TAM_USUARIO /20/
      data TAM_PAIS /53/
      data TAM_PROFISSAO /60/
      data TAM_LIVRO /143/
      data TAM_LIVASS /23/
      data TAM_LIVAUT /23/
      data TAM_CLIENTE /135/
      data TAM_ENDERECO /123/
      data TAM_VENDA /56/
	
      data tfAssunto /1/
      data tfAutor /2/
      data tfEditora /3/
      data tfIdioma /4/ 
      data tfEndereco /5/
      data tfPais /6/
      data tfProfissao /7/  
      data tfLivro /8/ 
      data tfLivroAss /9/
      data tfLivroAut /10/
      data tfCliente /11/
      data tfUsuario /12/ 
      data tfVenda /13/

      end

C     ------------------------------------------------------------------
C     Função que retorna o tamanho de uma string.
C     sTexto - indica a string
C     retorna - o tamanho da string
C     ------------------------------------------------------------------
      integer function TamStr(sTexto)
      character*(*) sTexto

      integer ncont

      TamStr = LEN(sTexto)
      do ncont=1,TamStr
        if (sTexto(ncont:ncont).EQ.char(0)) then
          TamStr = ncont-1
          exit
        end if
      end do
      return
      end
C     ------------------------------------------------------------------
C     Função que concatena uma string com a outra.
C     sDestino - indica a string a ser retornada
C     sOrigem  - indica a string a ser somada
C     retorna - a string concatenada
C     ------------------------------------------------------------------
      subroutine SomaStr(sDestino,sOrigem)
      character*(*) sDestino,sOrigem

      integer nDestino,nOrigem,TamStr

      nDestino = TamStr(sDestino)
      nOrigem = TamStr(sOrigem)
      sDestino(nDestino+1:) = sOrigem
      sDestino(nDestino+nOrigem+1:) = char(0)
      return
      end
C     ------------------------------------------------------------------
C     Função que insere uma string num determinado indice.
C     sDestino - indica a string a ser retornada
C     sOrigem  - indica a string a ser inserida
C     nIndice  - indica a posicao na string
C     retorna - a string inserida
C     ------------------------------------------------------------------
      subroutine InsereStr(sDestino,sOrigem,nIndice)
      character*(*) sDestino,sOrigem
      integer nIndice

      integer ntam,TamStr

      ntam = TamStr(sOrigem)
      sDestino(ntam+nIndice:) = sDestino(nIndice:)
      sDestino(nIndice:ntam+nIndice-1) = sOrigem(:ntam)
      return
      end
C     ------------------------------------------------------------------
C     Função que converte de string para inteiro
C     sTexto - indica a string
C     retorna - o inteiro convertido
C     ------------------------------------------------------------------
      integer function StrToInt(sTexto)
      character*(*) sTexto

      integer ncont,TamStr,nnum,vnum

      StrToInt = 0
      nnum = 1
      do ncont=1,TamStr(sTexto)
        vnum = ICHAR(sTexto(ncont:ncont))
        select case (vnum)
          case (45) !ICHAR('-')
            if (ncont.EQ.1) then
              nnum = -1
            else
              return
            endif
          case (48:57)
            StrToInt = StrToInt*10 + (vnum-48)
          case default
            return
        end select
      end do
      StrToInt = StrToInt*nnum
      return
      end
C     ------------------------------------------------------------------
C     Função que converte de inteiro para string
C     nNumero - indica o numero a ser convertido
C     retorna - a string convertida
C     ------------------------------------------------------------------
      character*(*) function IntToStr(nNumero)
      integer nNumero

      integer ncont

      ncont = ABS(nNumero)
      IntToStr = char(0)
      do while (ncont.GE.10)
        call InsereStr(IntToStr,CHAR(MOD(ncont,10)+48),1)
        ncont = ncont / 10
      end do
      call InsereStr(IntToStr,CHAR(MOD(ncont,10)+48),1)
      if (nNumero.LT.0) then
        call InsereStr(IntToStr,'-',1)
      endif
      return
      end
C     ------------------------------------------------------------------
C     Função que retorna um pedaço de uma string.
C     str - indica a string
C     ini - indica a posicao inicial do pedaco
C     tam - indica o tamanho do pedaco
C     retorna - o pedaço da string
C     ------------------------------------------------------------------
      character*(*) function copy(stexto,nini,ntam)
      character*255 stexto
      integer nini, ntam

      ntam = nini+ntam-1
      copy = stexto(nini:ntam)
      return
      end

C     ------------------------------------------------------------------
C     Retira os espaços em branco antes ou depois do texto.
C     sTexto - o texto a ser retirado os espaços em branco
C     retorna - o texto sem os espaços em branco
C     ------------------------------------------------------------------
      character*(*) function ftrim(sTexto)
      character*255 sTexto

      integer ncont, nPosIni, nPosFim
      logical bQuebra
      character*255 sret, copy

      sret = char(0)
      nPosIni=0
      nPosFim=0
      ncont=1
      bQuebra=.false.
      do while (ncont.le.len(sTexto) .and. bQuebra .eqv. .false.)
        if (sTexto(ncont:ncont).ne.' ') then
           nPosIni=ncont
           bQuebra=.true.
        end if
        ncont=ncont+1
      end do
      ncont=len(sTexto)
      bQuebra=.false.
      do while (ncont .ge. 1 .and. bQuebra .eqv. .false.)
        if (sTexto(ncont:ncont).ne.' ') then
           nPosFim=ncont
           bQuebra=.true.
        end if
        ncont=ncont-1
      end do
      sret=sTexto(nPosIni:nPosFim)
      sret(nPosFim+1:nPosFim+1) = char(0)
C      sret=copy(sTexto,nPosIni,(nPosFim-nPosIni)+1)
      ftrim = sret
      return 
      end
C     ------------------------------------------------------------------
C     Repete um texto um número determinado de vezes.
C     sTexto - o texto a ser repetido
C     nQtd - a quantidade de vezes
C     retorna - o texto repetido
C     ------------------------------------------------------------------
      character*(*) function repete(sTexto, nQtd)
      character*(*) sTexto 
      integer nQtd

      integer ncont
      character*255 sret

      sret = char(0)
      do ncont=1,nQtd
        call SomaStr(sret,sTexto)
      end do
      repete = sret 
      return
      end
C     ------------------------------------------------------------------
C     Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
C     sTexto - o texto
C     nTam - tamanho máximo do texto
C     retorna - o texto com espaços em branco a mais
C     ------------------------------------------------------------------
      character*(*) function esp(sTexto, nTam)
      character*(*) sTexto
      character*255 repete
      integer nTam, TamStr

      call SomaStr(sTexto, repete(" ",nTam-TamStr(sTexto)))
      esp = sTexto
      return
      end

C     ------------------------------------------------------------------
C     Faz uma pesquisa relativa de um texto através de um valor chave.
C     sTexto - o texto
C     sChave - a chave a ser pesquisada
C     retorna - se achou ou não a chave dentro do texto
C     ------------------------------------------------------------------
      logical function strRelativa(sTexto, sChave)
      character*255 sTexto, sChave

      integer nCont, nTamChave, nTamTexto
      logical bret
      character*255 sPedaco, copy

      bret=.false.
      nCont=1
      nTamChave=len(sChave)
      nTamTexto=len(sTexto)
      if (nTamChave .le. nTamTexto) then
        do while (nCont .le. (nTamTexto-nTamChave+1))
           sPedaco=copy(sTexto,nCont,nTamChave)
           if (sPedaco.eq.sChave) then
              bret=.true.
           end if
           nCont=nCont+1
        end do
      end if
      strRelativa=bret
      return
      end
C     ------------------------------------------------------------------
C     Calcula o modulo11 de um valor qualquer.
C     svalor - a mstring com o número a ser calculado
C     ndig - dígito do valor a ser calculado
C     retorna - o dígito correto
C     ------------------------------------------------------------------
      integer function modulo11(svalor, ndig)
      character*255 svalor
      integer ndig

      integer ncont, nsoma, nvalor, npos, StrToInt
      character*255 sres, slocal, copy

      ncont=1
      slocal=char(0)
      sres = char(0) 
      npos = 11
      do while (ncont .le. 11)
        sres = copy(svalor,npos,1)
        sres(2:2)=char(0)
        call InsereStr(slocal, sres, ncont)
        ncont=ncont+1 
        npos=npos-1
      end do
      nsoma=0
      if (ndig .eq. 1) then
        ncont=3
      else
        ncont=2
      end if
      npos=2
      do while (ncont .le. 11)
        sres = copy(slocal,ncont,1)
        sres(2:2)=char(0)
        nvalor = StrToInt(sres)
        nsoma=nsoma + (nvalor * npos)
        ncont=ncont+1
        npos=npos+1
      end do
      nsoma=(11 - mod(nsoma,11))
     
      if (nsoma .gt. 9) then
        modulo11=0
      else
        modulo11=nsoma
      end if 
      return 
      end
C     ------------------------------------------------------------------
C     Validação de um número de CPF qualquer.
C     cpf - a mstring com o número do CPF
C     retorna - se é valido ou não
C     ------------------------------------------------------------------
      logical function validaCPF(cpf)
      character*255 cpf 

      character*255 scpf, sres, copy
      integer nvalor1, nvalor2, TamStr, StrToInt, modulo11

      if (TamStr(cpf) .eq. 14) then
        call SomaStr(scpf, copy(cpf,1,3))
        call SomaStr(scpf, copy(cpf,5,3))
        call SomaStr(scpf, copy(cpf,9,3))
        call SomaStr(scpf, copy(cpf,13,2))
        sres=copy(cpf,13,1)
        sres(2:2)=char(0) 
        nvalor1 = StrToInt(sres)
        sres=copy(cpf,14,1)
        sres(2:2)=char(0) 
        nvalor2 = StrToInt(sres)
        if ((modulo11(scpf,1) .eq. nvalor1) 
     *    .and. (modulo11(scpf,2) .eq. nvalor2)) then
          validaCPF=.true.
        else
          validaCPF=.false.
        end if
      else
        validaCPF=.false.
      end if
      return
      end
C     ------------------------------------------------------------------
C     Validação de um número ISBN qualquer.
C     isbn - a mstring com o número do ISBN
C     retorna - se é valido ou não
C     ------------------------------------------------------------------
      logical function validaISBN(isbn)
      character*255 isbn
  
      character*255 snum, sdigito, sisbn, copy
      integer nvalor, nsoma, nstatus, ncont, TamStr, StrToInt
      
      if (TamStr(isbn) .eq. 13) then
        sdigito = copy(isbn, TamStr(isbn), 1)
        sisbn = char(0)
        do ncont=1, TamStr(isbn)-1 
          if (copy(isbn,ncont,1) .ne. "-") then
            call SomaStr(sisbn,copy(isbn,ncont,1)) 
          end if
        end do
        if (sdigito .eq. "X") then
          nsoma = 10
        else
          nvalor = StrToInt(sdigito)
          nsoma = nvalor
        end if
        do ncont=1, 9 
          snum=copy(sisbn, ncont, 1)
          nvalor = StrToInt(snum)
          nsoma=nsoma + (nvalor * (11 - ncont))
        end do
        if (mod(nsoma, 11) .eq. 0) Then
          validaISBN=.true.
        else
          validaISBN=.false.
        end if
      else
        validaISBN=.false.
      end if
      return 
      end
C     ------------------------------------------------------------------
C     Esconde a digitação da senha
C     retorna - a senha digitada
C     ------------------------------------------------------------------
      character*255 function digitaSenha(sRotulo, nTamSenha)
      character*255 sRotulo
      integer nTamSenha

      character*255 sSenha
C      character sLetra
C      integer ncont

      write(*,*) sRotulo
      read(*,*) sSenha
C        ncont = 0
C        sSenha=char(0)
C        sLetra=char(0)
C        do while ((sLetra .ne. char(13)) .and. (ncont .lt. nTamSenha))
C          sLetra=readkey
C          call SomaStr(sSenha, sLetra)
C          ncont=ncont+1
C        end dos
      digitaSenha=sSenha
      return
      end
C     ------------------------------------------------------------------
C     Validação de um número qualquer.
C     sRotulo - o texto antes de se digitar o número
C     sNumero - a mstring com o valor do número
C     retorna - o sNumero
C     ------------------------------------------------------------------
      character*255 function validaNumero(sRotulo, sNumero)
      character*255 sRotulo, sNumero
        
      include 'livrus.h'
      integer nnum
      integer nStatus, StrToInt

      nStatus=-1
      do while (nStatus .ne. 0)
        write(*,*) sRotulo
        read(*,*) sNumero
        nnum = StrToInt(sNumero)
        if ((nnum .lt. 1) .or. (nStatus.ne.0)) then
           write(*,*) MSG_NUMINV
        end if
      end do
      validaNumero=sNumero
      return
      end
C     ------------------------------------------------------------------
C     Validação de uma data ou data/hora qualquer.
C     sRotulo - o texto antes de se digitar a data/hora
C     sDataHora - a mstring com o valor da data/hora
C     bSoData - indica se vai validar somente uma data sem a hora
C     retorna - a sDataHora
C     ------------------------------------------------------------------
      character*255 function validaDataHora(sRotulo, sDataHora, bSoData)
      character*255 sRotulo, sDataHora
      logical bSoData

      include 'livrus.h'
      logical bvalida, bdatavalida, bhoravalida
      character*255 sdia, smes, sano, shora, smin, sseg, copy
      integer ndia, nmes, nano, nhora, nmin, nseg, nudiames
      integer ntam, TamStr, StrToInt

      bvalida=.false.
      bdatavalida=.false.
      bhoravalida=.false.
      nudiames=0
      
      if (bSoData .eqv. .true.) then 
        ntam=10
      else 
        ntam=19
      end if
      do while (bvalida .eqv. .false.)
        write(*,*) sRotulo
        read(*,*) sDataHora
        if (TamStr(sDataHora) .eq. ntam) then
          sdia=copy(sDataHora,1,2)
          ndia = StrToInt(sdia)
          smes=copy(sDataHora,4,2)
          nmes = StrToInt(smes)
          sano=copy(sDataHora,7,4)
          nano = StrToInt(sano)
        
          if ((nano .ge. 1) .and. (nano .le. 9999)) then
            if ((nmes .ge. 1) .and. (nmes .le. 31)) then
                if ((nmes.eq.1) .or. (nmes.eq.3) .or. (nmes.eq.5) .or. 
     *               (nmes.eq.7) .or. (nmes.eq.8) .or. 
     *               (nmes.eq.10) .or. (nmes.eq.12)) then
                   nudiames=31
                else if (nmes.eq.2) then
C                  ano bissexto 
                   if (mod(nano, 4).eq.0) then 
                     nudiames=29
                   else 
                     nudiames=28
                   end if
                else if ((nmes.eq.4) .or. (nmes.eq.6) .or. 
     *           (nmes.eq.9) .or. (nmes.eq.11)) then 
                  nudiames=30
                end if
                if ((ndia .ge. 1) .and. (ndia .le. nudiames)) then
                   bdatavalida=.true.
                end if 
            end if
          end if
        
          if (bSoData .eqv. .true.) then
             if (bdatavalida .eqv. .true.) then 
               bvalida=.true.
             else 
               write(*,*) MSG_DATAINV
             end if       
          else
            if (bdatavalida .eqv. .true.) then
                shora=copy(sDataHora,12,2)
                nhora = StrToInt(shora)
                smin = copy(sDataHora,15,2)
                nmin = StrToInt(smin)
                sseg=copy(sDataHora,18,2)
                nseg = StrToInt(sseg)
        
                if ((nhora .ge. 0) .and. (nhora .le. 23)) then
                  if ((nmin .ge. 0) .and. (nmin .le. 59)) then
                    if ((nseg .ge. 0) .and. (nseg .le. 59)) then
                       bhoravalida=.true.
                    end if
                  end if
                end if
        
                if (bhoravalida .eqv. .true.) then 
                  bvalida=.true.
                else 
                  write(*,*) MSG_DTHRINV
                end if
            else
              write(*,*) MSG_DTHRINV
            end if
          end if
        else
          if (bSoData .eqv. .true.) then 
            write(*,*) MSG_DATAINV
          else 
            write(*,*) MSG_DTHRINV
          end if    
        end if
      end do
      validaDataHora=sDataHora
      return
      end
C     ------------------------------------------------------------------
C     Retorna a Data e a hora do sistema.
C     retorna - a data e a hora
C     ------------------------------------------------------------------
      character*(*) function retDataHora()
      character*255 sano, smes, sdia, shora, smin, sseg, sDataHora
      character*255 IntToStr
      integer tempo(9)

      call GMTime(time(), tempo)
      sseg = IntToStr(tempo(1))
      smin = IntToStr(tempo(2))
      shora = IntToStr(tempo(3))
      sdia = IntToStr(tempo(4))
      smes = IntToStr(tempo(5))
      sano = IntToStr(tempo(6) + 1900)
      if (tempo(4) .lt. 10) then
         call SomaStr(sDataHora,"0")
      end if
      call SomaStr(sDataHora,sdia)
      call SomaStr(sDataHora,"/")
      if (tempo(5) .lt. 10) then
         call SomaStr(sDataHora,"0")
      end if
      call SomaStr(sDataHora,smes)
      call SomaStr(sDataHora,"/")
      call SomaStr(sDataHora,sano)
      call SomaStr(sDataHora," ")
      if (tempo(3) .lt. 10) then
         call SomaStr(sDataHora,"0")
      end if
      call SomaStr(sDataHora,shora)
      call SomaStr(sDataHora,":")
      if (tempo(2) .lt. 10) then
         call SomaStr(sDataHora,"0")
      end if
      call SomaStr(sDataHora,smin)
      call SomaStr(sDataHora,":")
      if (tempo(1) .lt. 10) then
         call SomaStr(sDataHora,"0")
      end if
      call SomaStr(sDataHora,sseg)
      retDataHora = sDataHora
      end

C     ------------------------------------------------------------------
C     Calcula o tamanho do arquivo.
C     sArq - o arquivo
C     retorna - o tamanho do arquivo
C     ------------------------------------------------------------------
      integer function tamArq(sArq)
      integer sArq
      integer fimarq,cont
      cont=1
      do while (fimarq.ne.-1)
        read(sArq,rec=cont,iostat=fimarq) 
        cont=cont+1
      end do
      tamArq = cont
      end

C     ------------------------------------------------------------------
C     Abre ou cria os arquivos do sistema.
C     bAbre - condição para abrir ou criar os arquivos do sistema
C     ------------------------------------------------------------------
      subroutine abrecriaArqs(bAbre)
      logical bAbre
       
      include 'livrus.h'
      logical bexiste

      if (bAbre) then
        inquire(file=ARQ_ASSUNTO,exist=bexiste)
        if (bexiste) then
          open(tfAssunto,file=ARQ_ASSUNTO,status='old',access='direct',
     *         form='formatted',recl=TAM_ASSUNTO)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_ASSUNTO
        end if
        inquire(file=ARQ_AUTOR,exist=bexiste)
        if (bexiste) then
          open(tfAutor,file=ARQ_AUTOR,status='old',access='direct',
     *         form='formatted',recl=TAM_AUTOR)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_AUTOR
        end if
        inquire(file=ARQ_EDITORA,exist=bexiste)
        if (bexiste) then
          open(tfEditora,file=ARQ_EDITORA,status='old',access='direct',
     *         form='formatted',recl=TAM_EDITORA)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_EDITORA
        end if
        inquire(file=ARQ_IDIOMA,exist=bexiste)
        if (bexiste) then
          open(tfIdioma,file=ARQ_IDIOMA,status='old',access='direct',
     *         form='formatted',recl=TAM_IDIOMA)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_IDIOMA
        end if
        inquire(file=ARQ_ENDERECO,exist=bexiste)
        if (bexiste) then
          open(tfEndereco,file=ARQ_ENDERECO,status='old',
     *         access='direct', form='formatted',recl=TAM_ENDERECO)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_ENDERECO
        end if
        inquire(file=ARQ_PAIS,exist=bexiste)
        if (bexiste) then
          open(tfPais,file=ARQ_PAIS,status='old',access='direct',
     *         form='formatted',recl=TAM_PAIS)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_PAIS
        end if
        inquire(file=ARQ_PROFISSAO,exist=bexiste)
        if (bexiste) then
          open(tfProfissao,file=ARQ_PROFISSAO,status='old',
     *         access='direct', form='formatted',recl=TAM_PROFISSAO)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_PROFISSAO
        end if
        inquire(file=ARQ_LIVRO,exist=bexiste)
        if (bexiste) then
          open(tfLivro,file=ARQ_LIVRO,status='old',access='direct',
     *         form='formatted',recl=TAM_LIVRO)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_LIVRO
        end if
        inquire(file=ARQ_LIVASS,exist=bexiste)
        if (bexiste) then
          open(tfLivroAss,file=ARQ_LIVASS,status='old',access='direct',
     *         form='formatted',recl=TAM_LIVASS)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_LIVASS
        end if
        inquire(file=ARQ_LIVAUT,exist=bexiste)
        if (bexiste) then
          open(tfLivroAut,file=ARQ_LIVAUT,status='old',access='direct',
     *         form='formatted',recl=TAM_LIVAUT)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_LIVAUT
        end if
        inquire(file=ARQ_CLIENTE,exist=bexiste)
        if (bexiste) then
          open(tfCliente,file=ARQ_CLIENTE,status='old',access='direct',
     *         form='formatted',recl=TAM_CLIENTE)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_CLIENTE
        end if
        inquire(file=ARQ_USUARIO,exist=bexiste)
        if (bexiste) then
          open(tfUsuario,file=ARQ_USUARIO,status='old',access='direct',
     *         form='formatted',recl=TAM_USUARIO)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_USUARIO
        end if
        inquire(file=ARQ_VENDA,exist=bexiste)
        if (bexiste) then
          open(tfVenda,file=ARQ_VENDA,status='old',access='direct',
     *         form='formatted',recl=TAM_VENDA)
        else
          write(*,"(A37,' --> ',A15)") MSG_ARQERRO, ARQ_VENDA
        end if
      else
        open(tfAssunto,file=ARQ_ASSUNTO,status='new',access='direct',
     *       form='formatted',recl=TAM_ASSUNTO)
        open(tfAutor,file=ARQ_AUTOR,status='new',access='direct',
     *       form='formatted',recl=TAM_AUTOR)
        open(tfEditora,file=ARQ_EDITORA,status='new',access='direct',
     *       form='formatted',recl=TAM_EDITORA)
        open(tfIdioma,file=ARQ_IDIOMA,status='new',access='direct',
     *       form='formatted',recl=TAM_IDIOMA)
        open(tfEndereco,file=ARQ_ENDERECO,status='new',access='direct',
     *       form='formatted',recl=TAM_ENDERECO)
        open(tfPais,file=ARQ_PAIS,status='new',access='direct',
     *       form='formatted',recl=TAM_PAIS)
        open(tfProfissao,file=ARQ_PROFISSAO,status='new',
     *       access='direct', form='formatted',recl=TAM_PROFISSAO)
        open(tfLivro,file=ARQ_LIVRO,status='new',access='direct',
     *       form='formatted',recl=TAM_LIVRO)
        open(tfLivroAss,file=ARQ_LIVASS,status='new',access='direct',
     *       form='formatted',recl=TAM_LIVASS)
        open(tfLivroAut,file=ARQ_LIVAUT,status='new',access='direct',
     *       form='formatted',recl=TAM_LIVAUT)
        open(tfCliente,file=ARQ_CLIENTE,status='new',access='direct',
     *       form='formatted',recl=TAM_CLIENTE)
        open(tfUsuario,file=ARQ_USUARIO,status='new',access='direct',
     *       form='formatted',recl=TAM_USUARIO)
        open(tfVenda,file=ARQ_VENDA,status='new',access='direct',
     *       form='formatted',recl=TAM_VENDA)
      end if
      return 
      end

C     ------------------------------------------------------------------
C     Fecha todos os arquivos abertos.
C     ------------------------------------------------------------------
      subroutine fechaArqs

      include 'livrus.h'

      close(tfAssunto)
      close(tfAutor)
      close(tfEditora)
      close(tfIdioma)
      close(tfEndereco)
      close(tfPais)
      close(tfProfissao)
      close(tfLivro)
      close(tfLivroAss)
      close(tfLivroAut)
      close(tfCliente)
      close(tfUsuario)
      close(tfVenda)
      end
C     ------------------------------------------------------------------
C     Pesquisa um registro através de um valor chave num arquivo.
C     sArq - o arquivo
C     sChave - a chave a ser pesquisada
C     nPosChave - a posicao inicial da chave dentro do registro
C     nTamChave - o tamanho da chave dentro do registro
C     nTamLinha - o tamanho do registro
C     retorna - o registro pesquisado
C     ------------------------------------------------------------------
      character*(*) function pesqArq(sArq, sChave, nPosChave, nTamChave
     *, nTamLinha)
      integer sArq, nPosChave, nTamChave, nTamLinha
      character*255 sChave
     
      character*255 slinha, sres, ftrim, copy
      logical bQuebra
      integer nPosicao, fimarq

      slinha ='\0'
      sres='\0'
      nPosicao = 1
      bQuebra=.false.
C      fseek(sArq, 0)
      do while ((fimarq.ne.-1) .and. (bQuebra .eqv. .false.))
        read(sArq,rec=nPosicao,iostat=fimarq) slinha
C        sres=ftrim(slinha(nPosChave:nPosChave+nTamChave-1))
C        sres=slinha(nPosChave:nPosChave+nTamChave-1)
        sres = ftrim(copy(slinha,nPosChave,nTamChave))
        if (sres.eq.sChave) then
           bQuebra=.true.
        end if 
        nPosicao=nPosicao+1
      end do

      nPosicao=ftell(sArq)-(nTamLinha + TAM_CRLF)
C      if (nPosicao.gt.0) then
C         seek(sArq, nPosicao)
C      else
C         seek(sArq, 0)
C      end if
      if (sRes.ne.sChave) then
         pesqArq='\0'
      else
         pesqArq = copy(slinha,1,nTamLinha)
      end if
      end
C     ------------------------------------------------------------------
C     Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
C     sArq - o arquivo
C     nTamLinha - o tamanho do registro
C     ------------------------------------------------------------------
      subroutine pesqLinhaExcluida(sArq, nTamLinha)
      integer sArq, nTamLinha
      character*255 sExcluido, pesqArq
      
      sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha)
C      if (sExcluido .eq. "") then
C         fseek(sArq, tamArq(sArq))
C      end if
      return
      end
C     ------------------------------------------------------------------
C     Pesquisa o maior código num arquivo.
C     sArq - o arquivo
C     nPosChave - a posicao inicial da chave dentro do registro
C     nTamChave - o tamanho da chave dentro do registro
C     nTamLinha - o tamanho do registro
C     retorna - o maior código
C     ------------------------------------------------------------------
      character*(*) function pesqMaxCod(sArq, nPosChave, 
     * nTamChave, nTamLinha)
      integer sArq, nPosChave, nTamChave, nTamLinha

      character*255 slinha, sres, IntToStr, ftrim, copy
      logical bQuebra
      integer nMaior, nCod, fimarq, nPosicao, StrToInt

      bQuebra=.false.
      nMaior=0
C      fseek(sArq, 0)

      do while ((fimarq.ne.-1) .and. (bQuebra .eqv. .false.))
        read(sArq,rec=nPosicao,iostat=fimarq) slinha
        sres=ftrim(copy(slinha,nPosChave,nTamChave))
        nCod = StrToInt(sres)
        if (nCod .gt. nMaior) then
           nMaior=nCod
        end if
        nPosicao=nPosicao+1
      end do
      call pesqLinhaExcluida(sArq, nTamLinha)
      sres=IntToStr(nMaior+1)
      pesqMaxCod=sres
      return
      end
C     ------------------------------------------------------------------
C     Grava os registros num determinado arquivo.
C     sArq - o arquivo
C     sTexto - o registro a ser gravado
C     sMsgAcerto - a mensagem caso o registro foi gravado
C     sMsgErro - a mensagem caso o registro não foi gravado
C     ------------------------------------------------------------------
      subroutine escreveArq(sArq, sTexto, sMsgAcerto,	sMsgErro)
      integer sArq 
      character*255 sTexto, sMsgAcerto,	sMsgErro

      include 'livrus.h'
      integer nStatus

      call SomaStr(sTexto, CRLF)
      write(sArq,rec=nPosicao,iostat=nStatus) sTexto
      if (nStatus > 0) then 
        write(*,*) sMsgAcerto
      else
        write(*,*) sMsgErro
      end if

      return
      end
C     ------------------------------------------------------------------
C     Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
C     sreg - o tipo de arquivo
C     retorna - o registro montado
C     ------------------------------------------------------------------
      character*(*) function LinhaReg(sreg)
      integer sreg

      include 'livrus.h'
      character*255 slinha, esp

      slinha=char(0)
      if (sreg .eq. opAssunto) then
         slinha=esp(tAssunto_codigo,10)
         call SomaStr(slinha,esp(tAssunto_assunto,30))
      else if (sreg .eq. opAutor) then
         slinha=esp(tAutor_codigo,10)
         call SomaStr(slinha,esp(tAutor_autor,30))
      else if (sreg .eq. opEditora) then
         slinha=esp(tEditora_codigo,10)
         call SomaStr(slinha,esp(tEditora_editora,50))
      else if (sreg .eq. opEndereco) then
         slinha=esp(tEndereco_codigo,10)
         call SomaStr(slinha,esp(tEndereco_logradouro,40))
         call SomaStr(slinha,esp(tEndereco_bairro,15))
         call SomaStr(slinha,esp(tEndereco_cep,8))
         call SomaStr(slinha,esp(tEndereco_cidade,30))
         call SomaStr(slinha,esp(tEndereco_estado,20))
      else if (sreg .eq. opIdioma) then
         slinha=esp(tIdioma_codigo,10)
         call SomaStr(slinha,esp(tIdioma_idioma,20))
      else if (sreg .eq. opPais) then
         slinha=esp(tPais_codigo,3)
         call SomaStr(slinha,esp(tPais_pais,50))
      else if (sreg .eq. opProfissao) then
         slinha=esp(tProfissao_codigo,10)
         call SomaStr(slinha,esp(tProfissao_profissao,50))
      else if (sreg .eq. opUsuario) then
         slinha=esp(tUsuario_login,10)
         call SomaStr(slinha,esp(tUsuario_senha,10))
      else if (sreg .eq. opLivro) then
         slinha=esp(tLivro_isbn,13)
         call SomaStr(slinha,esp(tLivro_titulo,50))
         call SomaStr(slinha,esp(tLivro_edicao,10))
         call SomaStr(slinha,esp(tLivro_anopubli,10))
         call SomaStr(slinha,esp(tLivro_codeditora,10))
         call SomaStr(slinha,esp(tLivro_volume,10))
         call SomaStr(slinha,esp(tLivro_codidioma,10))
         call SomaStr(slinha,esp(tLivro_npaginas,10))
         call SomaStr(slinha,esp(tLivro_preco,10))
         call SomaStr(slinha,esp(tLivro_qtdestoque,10))         
      else if (sreg .eq. opLivroAss) then
         slinha=esp(tLivroAss_isbn,13)
         call SomaStr(slinha,esp(tlivroAss_codassunto,10))
      else if (sreg .eq. opLivroAut) then
         slinha=esp(tLivroAut_isbn,13)
         call SomaStr(slinha,esp(tlivroAut_codautor,10))
      else if (sreg .eq. opCliente) then
         slinha=esp(tCliente_cpf,14)
         call SomaStr(slinha,esp(tCliente_nome,30))
         call SomaStr(slinha,esp(tCliente_email,30))
         call SomaStr(slinha,esp(tCliente_identidade,10))
         call SomaStr(slinha,esp(tCliente_sexo,1))
         call SomaStr(slinha,esp(tCliente_telefone,17))
         call SomaStr(slinha,esp(tCliente_dtnascimento,10))
         call SomaStr(slinha,esp(tCliente_codendereco,10))
         call SomaStr(slinha,esp(tCliente_codpais,3))
         call SomaStr(slinha,esp(tCliente_codprofissao,10))
      else if (sreg .eq. opVenda) then
         slinha=esp(tVenda_dthrvenda,19)
         call SomaStr(slinha,esp(tVenda_cpf,14))
         call SomaStr(slinha,esp(tVenda_isbn,13))         
         call SomaStr(slinha,esp(tVenda_precovenda,10))
      end if
      LinhaReg=slinha
      return
      end
C     ------------------------------------------------------------------
C     Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
C     sreg - o tipo de arquivo
C     retorna - o tamanho do registro
C     ------------------------------------------------------------------
      integer function tamReg(sreg)
      integer sreg

      include 'livrus.h'
      integer nret

      nret=0
      if (sreg .eq. opAssunto) then 
        nret=TAM_ASSUNTO
      else if (sreg .eq. opAutor) then 
        nret=TAM_AUTOR
      else if (sreg .eq. opEditora) then 
        nret=TAM_EDITORA
      else if (sreg .eq. opEndereco) then 
        nret=TAM_ENDERECO
      else if (sreg .eq. opIdioma) then 
        nret=TAM_IDIOMA
      else if (sreg .eq. opPais) then 
        nret=TAM_PAIS
      else if (sreg .eq. opProfissao) then 
        nret=TAM_PROFISSAO
      else if (sreg .eq. opUsuario) then 
        nret=TAM_USUARIO
      else if (sreg .eq. opLivro) then 
        nret=TAM_LIVRO
      else if (sreg .eq. opLivroAss) then 
        nret=TAM_LIVASS
      else if (sreg .eq. opLivroAut) then 
        nret=TAM_LIVAUT
      else if (sreg .eq. opCliente) then  
        nret=TAM_CLIENTE
      else if (sreg .eq. opVenda) then 
        nret=TAM_VENDA
      end if
      tamReg=nret
      return
      end
C     ------------------------------------------------------------------
C     Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
C     sreg - o tipo de arquivo
C     nNum - indica qual rotulo será retornado
C     retorna - o rotulo
C     ------------------------------------------------------------------
      character*(*) function rotulo(sreg, nNum)
      integer sreg, nNum

      include 'livrus.h'
      character*255 sret

      sret=char(0)
      if (sreg .eq. opAssunto) then
         select case (nNum)
           case (0)
               sret='Assunto(s) não encontrado(s)!'
           case (1) 
               sret='Código do assunto: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Assunto: '
               g_nPosChave=11
               g_nTamChave=30
         end select
      else if (sreg .eq. opAutor) then 
         select case (nNum)
           case (0) 
               sret='Autor(es) não encontrado(s)!'
           case (1) 
               sret='Código do autor: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Autor: '
               g_nPosChave=11
               g_nTamChave=30
         end select
      else if (sreg .eq. opEditora) then 
         select case (nNum)
           case (0) 
               sret='Editora(s) não encontrada(s)!'
           case (1) 
               sret='Código da editora: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Editora: '
               g_nPosChave=11
               g_nTamChave=50
         end select
      else if (sreg .eq. opEndereco) then 
         select case (nNum)
           case (0) 
               sret='Endereço(s) não encontrado(s)!'
           case (1) 
               sret='Código do endereço: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Logradouro: '
               g_nPosChave=11
               g_nTamChave=40
           case (3) 
               sret='Bairro: '
               g_nPosChave=51
               g_nTamChave=15
           case (4) 
               sret='CEP: '
               g_nPosChave=66
               g_nTamChave=8
           case (5) 
               sret='Cidade: '
               g_nPosChave=74
               g_nTamChave=30
           case (6) 
               sret='Estado: '
               g_nPosChave=104
               g_nTamChave=20
         end select
      else if (sreg .eq. opIdioma) then 
         select case (nNum)
           case (0) 
               sret='Idioma(s) não encontrado(s)!'
           case (1)
               sret='Código do idioma: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Idioma: '
               g_nPosChave=11
               g_nTamChave=20
         end select
      else if (sreg .eq. opPais) then 
         select case (nNum)
           case (0) 
               sret='País(es) não encontrado(s)!'
           case (1) 
               sret='Código do país: '
               g_nPosChave=1
               g_nTamChave=3
           case (2) 
               sret='País: '
               g_nPosChave=4
               g_nTamChave=50
         end select
      else if (sreg .eq. opProfissao) then 
         select case (nNum)
           case (0) 
               sret='Profissão(es) não encontrada(s)!'
           case (1) 
               sret='Código da profissão: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Profissão: '
               g_nPosChave=11
               g_nTamChave=50
         end select
      else if (sreg .eq. opUsuario) then 
         select case (nNum)
           case (0) 
               sret='login ou senha incorreta, tente de novo!'
           case (1) 
               sret='Login: '
               g_nPosChave=1
               g_nTamChave=10
           case (2) 
               sret='Senha: '
               g_nPosChave=11
               g_nTamChave=10
         end select
      else if (sreg .eq. opLivro) then 
         select case (nNum)
           case (0) 
               sret='Livro(s) não encontrado(s)!'
           case (1) 
               sret='ISBN: '
               g_nPosChave=1
               g_nTamChave=13
           case (2) 
               sret='Título: '
               g_nPosChave=14
               g_nTamChave=50
           case (3) 
               sret='Edição: '
               g_nPosChave=64
               g_nTamChave=10
           case (4) 
               sret='Ano de Publicação: '
               g_nPosChave=74
               g_nTamChave=10
           case (5) 
               sret='Código da editora: '
               g_nPosChave=84
               g_nTamChave=10
           case (6) 
               sret='Volume: '
               g_nPosChave=94
               g_nTamChave=10
           case (7) 
               sret='Código do idioma: '
               g_nPosChave=104
               g_nTamChave=10
           case (8) 
               sret='Número de páginas: '
               g_nPosChave=114
               g_nTamChave=10
           case (9) 
               sret='Preço: '
               g_nPosChave=124
               g_nTamChave=10
           case (10) 
                sret='Qtd. Estoque: '
                g_nPosChave=134
                g_nTamChave=10
         end select
      else if (sreg .eq. opLivroAss) then 
         select case (nNum)
           case (0) 
               sret='Assunto(s) não encontrado(s)!'
           case (1) 
               sret='ISBN: '
               g_nPosChave=1
               g_nTamChave=13
           case (2) 
               sret='Código do assunto: '
               g_nPosChave=14
               g_nTamChave=10
         end select
      else if (sreg .eq. opLivroAut) then 
         select case (nNum)
           case (0) 
               sret='Autor(s) não encontrado(s)!'
           case (1) 
               sret='ISBN: '
               g_nPosChave=1
               g_nTamChave=13
           case (2) 
               sret='Código do autor: '
               g_nPosChave=14
               g_nTamChave=10
         end select
      else if (sreg .eq. opCliente) then 
         select case (nNum)
           case (0) 
               sret='Cliente(s) não encontrado(s)!'
           case (1) 
               sret='CPF: '
               g_nPosChave=1
               g_nTamChave=14
           case (2) 
               sret='Nome: '
               g_nPosChave=15
               g_nTamChave=30
           case (3)
               sret='E-mail: '
               g_nPosChave=45
               g_nTamChave=30
           case (4) 
               sret='Identidade: '
               g_nPosChave=75
               g_nTamChave=10
           case (5) 
               sret='Sexo: '
               g_nPosChave=85
               g_nTamChave=1
           case (6) 
               sret='Telefone: '
               g_nPosChave=86
               g_nTamChave=17
           case (7) 
               sret='Dt. Nascimento: '
               g_nPosChave=103
               g_nTamChave=10
           case (8) 
               sret='Código do endereço: '
               g_nPosChave=113
               g_nTamChave=10
           case (9) 
               sret='Código do país: '
               g_nPosChave=123
               g_nTamChave=3
           case (10)
                sret='Código da Profissão: '
                g_nPosChave=126
                g_nTamChave=10
         end select
      else if (sreg .eq. opVenda) then 
         select case (nNum)
           case (0) 
               sret='Venda(s) não encontrada(s)!'
           case (1) 
               sret='Data/Hora venda: '
               g_nPosChave=1
               g_nTamChave=19
           case (2) 
               sret='CPF: '
               g_nPosChave=20
               g_nTamChave=14
           case (3) 
               sret='ISBN: '
               g_nPosChave=34
               g_nTamChave=13
           case (4) 
               sret='Preço de venda: '
               g_nPosChave=47
               g_nTamChave=10
         end select
      end if      
      rotulo=sret
      return
      end
C     ------------------------------------------------------------------
C     Indica se continua ou não mostrando um número máximo de linhas.
C     nlinha - a linha a ser continuada
C     nQtdLinha - a quantidade de linhas a serem mostradas
C     retorna - se continua ou não
C     ------------------------------------------------------------------
      logical function ContinuaSN(nlinha, nQtdLinha)
      integer nlinha, nQtdLinha

      include 'livrus.h'
      logical bSOp, bret
      character opCSubMenu
      
      bret=.false.
      if (nlinha .gt. 0) then
        if (mod(nlinha, nQtdLinha) .eq. 0) then
           bSOp=.true.
           do while(bSOp .eqv. .true.)
             call menu(13)
             read(*,*) opCSubMenu
             if ((opCSubMenu.eq.'S') .or. (opCSubMenu.eq.'s')) then 
               bSOp=.false.
             else if ((opCSubMenu.eq.'N') .or. (opCSubMenu.eq.'n')) then
               bret=.true.
               bSOp=.false.
             else
               write(*,*) MSG_ERRO
             end if
           end do
        end if
      end if
      
      ContinuaSN=bret
      return
      end
C     ------------------------------------------------------------------
C     Lista vários registros de acordo com a pesquisa feita.
C     sArq - o arquivo
C     sreg - o tipo de arquivo
C     sChave - a chave a ser pesquisada
C     nPosChave - a posicao inicial da chave dentro do registro
C     nTamChave - o tamanho da chave dentro do registro
C     nTamLinha - o tamanho do registro
C     nQtdLinha - a quantidade de linhas a serem mostradas
C     retorna - se encontrou algum registro
C     ------------------------------------------------------------------
      logical function ListarTodos(sArq, sreg, sChave, nPosChave, 
     *  nTamChave, nTamLinha, nQtdLinha, bPesqRelativa)
      integer sArq, sreg, nPosChave, nTamChave, nTamLinha, nQtdLinha
      character*255 sChave
      logical bPesqRelativa

      character*255 slinha, sres, ftrim, copy
      logical bQuebra, bAchou, bRet, ContinuaSN, strRelativa
      integer nCont, fimarq

      bRet=.false.
      bQuebra=.false.
      nCont=0
      call mostrarDados(sreg, '', 2)
C      fseek(sArq, 0)
      do while ((fimarq.ne.-1) .and. (bQuebra .eqv. .false.))
        read(sArq,rec=nPosicao,iostat=fimarq) slinha
      
        if (bPesqRelativa .eqv. .true.) then
          sres=ftrim(copy(slinha,nPosChave,nTamChave))
          if (strRelativa(sres,sChave) .eqv. .true.) then
             bAchou=.true.
             bRet=.true.
          else
             bAchou=.false.
          end if
        else
          bAchou=.true.
          bRet=.true.
        end if
      
        if (bAchou .eqv. .true.) then
          call mostrarDados(sreg, copy(slinha,1,nTamLinha), 3)
          nCont=nCont+1
        end if
      
        bQuebra=ContinuaSN(nCont, nQtdLinha)
      end do
      ListarTodos=bret
      return
      end
C     ------------------------------------------------------------------
C     Lista vários registros entre arquivos de acordo com a pesquisa feita.
C     sArq1 - o arquivo de ligação
C     sreg1 - o tipo de arquivo de ligação
C     nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
C     nTamChave1 - o tamanho da primeira chave no arquivo de ligação
C     nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
C     nTamChave2 - o tamanho da segunda chave do arquivo de ligação
C     sChave - a chave a ser pesquisada no arquivo de ligação
C     sArq2 - o arquivo a ser pesquisado
C     sreg2 - o tipo de arquivo a ser pesquisado
C     nPosChave3 - a posicao inicial da chave do arquivo pesquisado
C     nQtdLinha - a quantidade de linhas a serem mostradas
C     ------------------------------------------------------------------
      subroutine ListarRegLigados(sArq1, sreg1, nPosChave1, nTamChave1, 
     *  nPosChave2, nTamChave2, sChave, sArq2, sreg2, nPosChave3, 
     *  nQtdLinha)
      integer sArq1, sreg1, nPosChave1, nTamChave1, nPosChave2,    
     * nTamChave2, sArq2, sreg2, nPosChave3, nQtdLinha
      character*255 sChave

      character*255 slinha1, sCodigo1, sCodigo2, slinha2, 
     * ftrim, copy, pesqArq, rotulo
      logical bQuebra, bRet, ContinuaSN
      integer nCont, fimarq, nPosicao, tamReg

      bRet=.false.
      nCont=0
      bQuebra=.false.
      call mostrarDados(sreg2, '', 2)
C      fseek(sArq1, 0)
      do while ((fimarq.ne.-1) .and. (bQuebra .eqv. .false.))
        read(sArq1,rec=nPosicao,iostat=fimarq) slinha1

        sCodigo1=ftrim(copy(slinha1,nPosChave1,nTamChave1))
        if (sCodigo1 .eq. sChave) then
          sCodigo2=ftrim(copy(slinha1,nPosChave2,nTamChave2))
          slinha2=pesqArq(sArq2, sCodigo2, nPosChave3, 
     *            nTamChave2, tamReg(sreg2))
          call mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3)
          bRet=.true.
          nCont=nCont+1
        end if
        bQuebra=ContinuaSN(nCont, nQtdLinha)
      end do
      if (bRet .eqv. .false.) then
         write(*,*) rotulo(sreg2,0)
      end if
      return
      end
C     ------------------------------------------------------------------
C     Valida a entrada de registros de acordo com a pesquisa feita.
C     sArq - o arquivo
C     sreg - o tipo de arquivo
C     nTexto - o numero do rótulo da entrada
C     sEntrada - a chave a ser pesquisada e validada
C     nTentativas - o número máximo de tentativas
C     bPesqRelativa - indica se vai realizar uma pesquisa relativa
C     bTipoEntrada - indica o tipo de entrada
C     retorna - o registro pesquisado e validado
C     ------------------------------------------------------------------
      character*(*) function validaEntrada(sArq, sreg, nTexto,
     *  sEntrada, nTentativas, bPesqRelativa, bTipoEntrada)
      integer sArq, sreg, nTexto, nTentativas, bTipoEntrada
      character*255 sEntrada
      logical bPesqRelativa

      include 'livrus.h'
      logical bQuebra, ListarTodos
      character*255 sres, sTexto, sMsgErro, rotulo
      integer ncont, nPosChave, nTamChave, nTamLinha, tamReg
      character*255 validaNumero, validaDataHora, digitaSenha, pesqArq

      nTamLinha=tamReg(sreg)
      sMsgErro=rotulo(sreg,0)
      sTexto=rotulo(sreg,nTexto)
      nPosChave=g_nPosChave
      nTamChave=g_nTamChave
      
      ncont=1
      bQuebra=.false.
      do while ((bQuebra .eqv. .false.) .and. (ncont .le. nTentativas))
        if (bTipoEntrada .eq. opTexto) then
          write(*,*) sTexto
          read(*,*) sEntrada
        else if (bTipoEntrada .eq. opNumero) then
           sEntrada=validaNumero(sTexto,sEntrada)
        else if (bTipoEntrada .eq. opData) then
           sEntrada=validaDataHora(sTexto,sEntrada,.true.)
        else if (bTipoEntrada .eq. opDataHora) then
           sEntrada=validaDataHora(sTexto,sEntrada,.false.)
        else if (bTipoEntrada .eq. opSenha) then
           sEntrada=digitaSenha(sTexto, 10)
        end if
    
        if (bPesqRelativa .eqv. .true.) then
          if (ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, 
     *       nTamLinha, QTD_MAX_LINHA, .true.) .eqv. .true.) then
            sres=' '
          end if
        else
           sres=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)
        end if
        if (sres .eq. '') then
           write(*,*) sMsgErro
        else
           bQuebra=.true.
        end if
        ncont=ncont+1
      end do
      validaEntrada=sres
      return
      end
C     ------------------------------------------------------------------
C     Mostra a tela de splash do sistema.
C     ------------------------------------------------------------------
      subroutine frmSplash
      integer cont

      include 'livrus.h'

      write(*,*) '*-----------------------------------------------------
     *-----------------------*'
      write(*,*) '| LL    II VV   VV RRRRR  UU  UU   SSSS VV   VV II RRR
     *RR  TTTT UU  UU   SSSS |'
      write(*,*) '| LL    II  VV VV  RR   R UU  UU  SS     VV VV  II RR 
     *  R  TT  UU  UU  SS    |'
      write(*,*) '| LL    II   VVV   RRRRR  UU  UU    SS    VVV   II RRR
     *RR   TT  UU  UU    SS  |'
      write(*,*) '| LLLLL II    V    RR   R  UUUU  SSSS      V    II RR 
     *  R  TT   UUUU  SSSS   |'
      write(*,*) '*-----------------------------------------------------
     *-----------------------*'
      do cont=1,17
        write(*,*)
      end do
      write(*,*) MSG_PRESS
      read(*,*) 
      end
C     ------------------------------------------------------------------
C     Mostra a tela de sobre do sistema.
C     ------------------------------------------------------------------
      subroutine frmSobre
      integer cont

      include 'livrus.h'

      write(*,*) '*-----------------------------------------------------
     *-------*'
      write(*,*) '|  LL        II  VV       VV  RRRRRRR   UU    UU   SSS
     *SSSS   |'
      write(*,*) '|  LL        II   VV     VV   RR     R  UU    UU  SS  
     *       |'
      write(*,*) '|  LL        II    VV   VV    RR     R  UU    UU   SSS
     *S      |'
      write(*,*) '|  LL        II     VV VV     RRRRRRR   UU    UU     S
     *SSS    |'
      write(*,*) '|  LLLL      II      VVV      RR RR     UU    UU      
     *  SS   |'
      write(*,*) '|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSS
     *SSSS   |'
      write(*,*) '|                                                      
     *       |'
      write(*,*) '|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSS
     *SSSS   |'
      write(*,*) '|   VV     VV   II  RR     R     TT     UU    UU  SS  
     *       |'
      write(*,*) '|    VV   VV    II  RR     R     TT     UU    UU   SSS
     *S      |'
      write(*,*) '|     VV VV     II  RRRRRRR      TT     UU    UU     S
     *SSS    |'
      write(*,*) '|      VVV      II  RR RR        TT     UU    UU      
     *  SS   |'
      write(*,*) '|       V       II  RR   RR      TT      UUUUUU   SSSS
     *SSSS   |'
      write(*,*) '|                                                     
     *       |'
      write(*,*) '|                                               Versao
     * 1.0.0 |'
      write(*,*) '| Sistema integrante do projeto Livrus Virtus.        
     *       |'
      write(*,*) '| Todos os direitos reservados para Henrique F. de Sou
     *za.    |'
      write(*,*) '| Versao programada na linguagem fortran 77.          
     *       |'
      write(*,*) '*-----------------------------------------------------
     *-------*'
      do cont=1,3
        write(*,*)
      end do
      write(*,*) MSG_PRESS
      read(*,*) 
      end
C     ------------------------------------------------------------------
C     Mostra a tela de login do sistema.
C     retorna - se o login foi validado corretamente
C     ------------------------------------------------------------------
      logical function frmLogin()
      include 'livrus.h'
      logical bret
      character*255 slinha, ftrim, copy, validaEntrada
      
      bret=.false.
      write(*,*) '*-----------------------------------------------------
     *---------*'
      write(*,*) '| Login do sistema
     *         |'
      write(*,*) '*-----------------------------------------------------
     *---------*'
      slinha=validaEntrada(tfUsuario, opUsuario, 1, tUsuario_login, 3,
     *    .false., opTexto)
      if (slinha .ne. '') then
         slinha = validaEntrada(tfUsuario, opUsuario, 2, 
     *       tUsuario_senha, 3, .false., opSenha)
         if (slinha.ne.'') then
           tUsuario_login=ftrim(copy(slinha, 1, 10))
           tUsuario_senha=ftrim(copy(slinha, 11, 10))
           bret=.true.
         end if
      end if
      write(*,*)
	    frmLogin = bret
      return
      end
C     ------------------------------------------------------------------
C     Mostra os menus do sistema.
C     num - o número do menu
C     ------------------------------------------------------------------
      subroutine menu(num)
      integer num

      include 'livrus.h'

      if (num.eq.1) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| (C)adastros        (P)esquisas     (V)endas
     * (O)pções  |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.2) then 
        write(*,*) '*---------------------------------*'
        write(*,*) '| 01. Cadastro de Assuntos        |'
        write(*,*) '| 02. Cadastro de Autores         |'
        write(*,*) '| 03. Cadastro de Editoras        |'
        write(*,*) '| 04. Cadastro de Endereços       |'
        write(*,*) '| 05. Cadastro de Idiomas         |'
        write(*,*) '| 06. Cadastro de Países          |'
        write(*,*) '| 07. Cadastro de Profissões      |'
        write(*,*) '| 08. Cadastro de Clientes        |'
        write(*,*) '| 09. Cadastro de Livros          |'
        write(*,*) '| 10. Voltar ao menu              |'
        write(*,*) '*---------------------------------*'
      else if (num.eq.3) then 
        write(*,*) '*---------------------------------*'
        write(*,*) '| 01. Consulta de Assuntos        |'
        write(*,*) '| 02. Consulta de Autores         |'
        write(*,*) '| 03. Consulta de Editoras        |'
        write(*,*) '| 04. Consulta de Endereços       |'
        write(*,*) '| 05. Consulta de Idiomas         |'
        write(*,*) '| 06. Consulta de Países          |'
        write(*,*) '| 07. Consulta de Profissões      |'
        write(*,*) '| 08. Consulta de Clientes        |'
        write(*,*) '| 09. Consulta de Livros          |'
        write(*,*) '| 10. Voltar ao menu              |'
        write(*,*) '*---------------------------------*'
      else if (num.eq.4) then 
        write(*,*) '*---------------------------------*'
        write(*,*) '| 01. Vender Livros               |'
        write(*,*) '| 02. Vendas Realizadas           |'
        write(*,*) '| 03. Voltar ao menu              |'
        write(*,*) '*---------------------------------*'
      else if (num.eq.5) then 
        write(*,*) '*---------------------------------*'
        write(*,*) '| 01. Alterar senha               |'
        write(*,*) '| 02. Sobre o sistema             |'
        write(*,*) '| 03. Sair do sistema             |'
        write(*,*) '| 04. Voltar ao menu              |'
        write(*,*) '*---------------------------------*'
      else if (num.eq.6) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| (1) Novo  (2) Pesquisar   (3) Voltar ao menu
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.7) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| (1) Salvar inclusão       (2) Voltar ao menu
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.8) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| (1) Alterar       (2) Excluir     (3) Voltar ao me
     *nu         |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.9) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| (1) Salvar alteração      (2) Voltar ao menu
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.10) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| Certeza de excluir? (S/N)
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.11) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| Deseja sair do sistema? (S/N)
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.12) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| (1) Pesquisar  (2) Listar todos   (3) Voltar ao me
     *nu         |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.13) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| Deseja continuar? (S/N)
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      else if (num.eq.14) then 
        write(*,*) '*---------------------------------------------------
     *-----------*'
        write(*,*) '| Salvar inclusão (S/N)
     *           |'
        write(*,*) '*---------------------------------------------------
     *-----------*'
      end if
      write(*,*) MSG_OPCAO
      end
C     ------------------------------------------------------------------
C     Realiza os cadastros de acordo com o tipo de arquivo.
C     sreg - o tipo de arquivo
C     sacao - a ação a ser realizada
C     ------------------------------------------------------------------
      subroutine frmCadastros(sreg, sacao)
      integer sreg, sacao

      include 'livrus.h'
      integer tamReg
      character*255 slinha, pesqMaxCod, validaEntrada, rotulo, 
     * retDataHora, ftrim, copy, pesqArq
      logical validaISBN, validaCPF

      if (sreg .eq. opAssunto) then
         if (sacao .eq. opNovo) then
           tAssunto_codigo=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg))
           call mostrarDados(sreg, '', 1)
           call subMenu(7, sreg)
         else if (sacao .eq. opPesquisar) then
           slinha=validaEntrada(tfAssunto,sreg,1,
     *       tAssunto_codigo,1,.false.,opNumero)
            if (slinha .ne. '') then
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opAutor) then 
         if (sacao .eq. opNovo) then
            tAutor_codigo=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg))
            call mostrarDados(sreg, '', 1)
            call subMenu(7, sreg)
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfAutor, sreg, 1, 
     *        tAutor_codigo,1,.false.,opNumero)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opEditora) then 
         if (sacao .eq. opNovo) then
            tEditora_codigo=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg))
            call mostrarDados(sreg, '', 1)
            call subMenu(7, sreg)
         else if (sacao .eq. opPesquisar) then
           slinha=validaEntrada(tfEditora,sreg,1,
     *       tEditora_codigo,1,.false.,opNumero)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opEndereco) then 
         if (sacao .eq. opNovo) then
            tEndereco_codigo=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg))
            call mostrarDados(sreg, '', 1)
            call subMenu(7, sreg)
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfEndereco,sreg,1,tEndereco_codigo,1,
     *               .false.,opNumero)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opIdioma) then 
         if (sacao .eq. opNovo) then
            tIdioma_codigo=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg))
            call mostrarDados(sreg, '', 1)
            call subMenu(7, sreg)
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfIdioma,sreg,1,
     *       tIdioma_codigo,1,.false.,opNumero)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opPais) then 
         if (sacao .eq. opNovo) then
            write(*,*) rotulo(sreg, 1)
            read(*,*) tPais_codigo
            slinha=pesqArq(tfPais, tPais_codigo, 1, 3, tamReg(sreg))
            if (slinha .eq. '') then 
               call pesqLinhaExcluida(tfPais, tamReg(sreg))
               call mostrarDados(sreg, '', 1)
               call subMenu(7, sreg)
            else 
              write(*,*) MSG_REGEXST
            end if    
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfPais, sreg, 1, 
     *       tPais_codigo, 1, .false., opTexto)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            write(*,*) rotulo(sreg, 1), tPais_codigo
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opProfissao) then 
         if (sacao .eq. opNovo) then
            tProfissao_codigo=pesqMaxCod(tfProfissao, 1, 10, 
     *       tamReg(sreg))
            call mostrarDados(sreg, '', 1)
            call subMenu(7, sreg)
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfProfissao,sreg,1,tProfissao_codigo,1,
     *               .false.,opNumero)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opLivro) then 
         if (sacao .eq. opNovo) then
            write(*,*) rotulo(sreg, 1)
            read(*,*) tLivro_isbn
            if (validaISBN(tLivro_isbn) .eqv. .true.) then 
                slinha=pesqArq(tfLivro, tLivro_isbn, 1, 13,tamReg(sreg))
                if (slinha .eq. '') then 
                   call pesqLinhaExcluida(tfLivro, tamReg(sreg))
                   call mostrarDados(sreg, '', 1)
                   call subMenu(7, sreg)
                   call frmCadLigados(opLivroAss, opNovo, tLivro_isbn)
                   call frmCadLigados(opLivroAut, opNovo, tLivro_isbn)
                else 
                  write(*,*) MSG_REGEXST
                end if    
            else 
              write(*,*) MSG_ISBNINV
            end if
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfLivro, sreg, 1, 
     *        tLivro_isbn, 1,.false.,opTexto)
            if (slinha .ne. '') then 
               call mostrarDados(sreg, '', 2)
               call mostrarDados(sreg, slinha, 3)
               call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            write(*,*) rotulo(sreg, 1), tLivro_isbn
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
            call frmCadLigados(opLivroAss, opExcluir, tLivro_isbn)
            write(*,*) 'Assuntos dos livros excluídos, inclua novos!'
            call frmCadLigados(opLivroAss, opNovo, tLivro_isbn)
            call frmCadLigados(opLivroAut, opExcluir, tLivro_isbn)
            write(*,*) 'Autores dos livros excluídos, inclua novos!'
            call frmCadLigados(opLivroAut, opNovo, tLivro_isbn)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
            write(*,*) 'Assuntos dos livros sendo excluídos!'
            call frmCadLigados(opLivroAss, opExcluir, tLivro_isbn)
            write(*,*) 'Autores dos livros sendo excluídos!'
            call frmCadLigados(opLivroAut, opExcluir, tLivro_isbn)
         end if
      else if (sreg .eq. opCliente) then 
         if (sacao .eq. opNovo) then
            write(*,*) rotulo(sreg, 1)
            read(*,*) tCliente_cpf
            if (validaCPF(tCliente_cpf) .eqv. .true.) then 
                slinha=pesqArq(tfCliente, tCliente_cpf, 1, 14, 
     *           tamReg(sreg))
                if (slinha .eq. '') then 
                   call pesqLinhaExcluida(tfCliente, tamReg(sreg))
                   call mostrarDados(sreg, '', 1)
                   call subMenu(7, sreg)
                else 
                  write(*,*) MSG_REGEXST
                end if
            else 
              write(*,*) MSG_CPFINV
            end if
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfCliente, sreg, 1, 
     *       tCliente_cpf,1,.false.,opTexto)
            if (slinha .ne. '') then 
               call mostrarDados(sreg, '', 2)
               call mostrarDados(sreg, slinha, 3)
               call subMenu(8, sreg)
            end if
         else if (sacao .eq. opAlterar) then
            write(*,*) rotulo(sreg, 1), tCliente_cpf
            call mostrarDados(sreg, '', 1)
            call subMenu(9, sreg)
         else if (sacao .eq. opExcluir) then
            call subMenu(10, sreg)
         end if
      else if (sreg .eq. opVenda) then 
         if (sacao .eq. opNovo) then
            tVenda_dthrvenda=retDataHora()
            write(*,*) rotulo(sreg, 1), tVenda_dthrvenda
            slinha=pesqArq(tfVenda, tVenda_dthrvenda, 1, 19, 
     *       tamReg(sreg))
            if (slinha .eq. '') then 
               slinha=validaEntrada(tfCliente,opCliente,1,tVenda_cpf,3,
     *                  .false.,opTexto)
               if (slinha .ne. '') then 
                  tVenda_cpf=ftrim(copy(slinha,1,14))
                  if (validaCPF(tVenda_cpf) .eqv. .true.) then 
                     write(*,*) ' ',rotulo(opCliente, 2)
                     write(*,*) copy(slinha, g_nPosChave, g_nTamChave)
                     call frmCadLigados(opVenda, opNovo, tVenda_cpf)
                  else 
                    write(*,*) MSG_CPFINV
                  end if
               end if
            else 
              write(*,*) MSG_REGEXST
            end if
         else if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfVenda, sreg, 1, tVenda_dthrvenda,1,
     *               .false.,opDataHora)
            if (slinha .ne. '') then 
              call mostrarDados(sreg, '', 2)
              call mostrarDados(sreg, slinha, 3)
              call subMenu(8, sreg)
            end if
         end if
      end if
      return
      end
C     ------------------------------------------------------------------
C     Realiza as consultas de acordo com o tipo de arquivo.
C     sreg - o tipo de arquivo
C     sacao - a ação a ser realizada
C     ------------------------------------------------------------------
      subroutine frmConsultas(sreg, sacao)
      integer sreg, sacao

      include 'livrus.h' 
      character*255 slinha, validaEntrada, rotulo
      logical ListarTodos
      integer tamReg

      if (sreg .eq. opAssunto) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfAssunto,sreg,2,
     *       tAssunto_assunto,1,.true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfAssunto, sreg, '', 0, 0, tamReg(sreg),
     *         QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opAutor) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfAutor,sreg, 2, 
     *       tAutor_autor, 1, .true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfAutor, sreg, '', 0, 0, tamReg(sreg),
     *         QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opEditora) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfEditora,sreg,2,tEditora_editora,1,
     *       .true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfEditora, sreg, '', 0, 0, tamReg(sreg),
     *         QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opEndereco) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfEndereco,sreg,2,tEndereco_Logradouro,
     *         1, .true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfEndereco, sreg, '', 0, 0, tamReg(sreg),
     *          3, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opIdioma) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfIdioma, sreg, 2, tIdioma_idioma,
     *       1,.true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfIdioma, sreg, '', 0, 0, tamReg(sreg),
     *        QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opPais) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfPais, sreg, 2, tPais_pais, 1, 
     *       .true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfPais, sreg, '', 0, 0, tamReg(sreg),
     *        QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opProfissao) then
         if (sacao .eq. opPesquisar) then
           slinha=validaEntrada(tfProfissao,sreg,2,
     *      tProfissao_profissao,1,.true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfProfissao, sreg, '', 0, 0, tamReg(sreg),
     *        QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opLivro) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfLivro, sreg, 2, 
     *       tLivro_titulo, 1, .true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfLivro, sreg, '', 0, 0, tamReg(sreg),
     *         1, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opCliente) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfCliente, sreg, 2, tCliente_nome,
     *       1,.true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfCliente, sreg, '', 0, 0, tamReg(sreg),
     *         1, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      else if (sreg .eq. opVenda) then
         if (sacao .eq. opPesquisar) then
            slinha=validaEntrada(tfVenda, sreg, 2, tVenda_cpf, 
     *       1, .true.,opTexto)
         else if (sacao .eq. opListarTodos) then
            if (ListarTodos(tfVenda, sreg, '', 0, 0, tamReg(sreg),
     *         QTD_MAX_LINHA, .false.) .eqv. .false.) then
              write(*,*) rotulo(sreg, 0)
            end if
         end if
      end if
      if (slinha .eq. '') then
         write(*,*) ''
      end if
      return
      end
C     ------------------------------------------------------------------
C     Mostra a tela de alteração de senha do sistema e realiza a alteração.
C     ------------------------------------------------------------------
      subroutine frmAlterarSenha()

      include 'livrus.h'
      logical bQuebra
      character*255 sres, sSenhaAtual, sNovaSenha, sConfirmaSenha, 
     * digitaSenha, pesqArq, rotulo
      integer nopcao, tamReg

      write(*,*) rotulo(opUsuario, 1), tUsuario_login
      nopcao=1
      bQuebra=.false.
      do while (bQuebra .eqv. .false.)
        select case (nopcao)
          case (1)
             sSenhaAtual=digitaSenha('Senha Atual: ',10)
             if (sSenhaAtual .ne. tUsuario_senha) then
                write(*,*) MSG_SENCONFERE
                bQuebra=.true.
             else 
                nopcao=2
             end if
          case (2)
             sNovaSenha=digitaSenha('Nova Senha: ',10)
             sConfirmaSenha=digitaSenha('Confirma Senha: ',10)
             if (sNovaSenha .ne. sConfirmaSenha) then
                write(*,*) MSG_SENCONFIRM
                bQuebra=.true.
             else 
                nopcao=3
             end if
         case (3)
             sres=pesqArq(tfUsuario, tUsuario_login, 1, 10, 
     *        tamReg(opUsuario))
             if (sres .eq. '') then
               write(*,*) MSG_LOGINENCON
             else
               tUsuario_senha=sConfirmaSenha
               call subMenu(9,opUsuario)
               bQuebra=.true.
             end if
        end select
      end do
      return
      end
C     ------------------------------------------------------------------
C     Executa uma ação de gravação de acordo com o tipo de arquivo.
C     sreg - o tipo de arquivo
C     sacao - a ação a ser realizada
C     ------------------------------------------------------------------
      subroutine btnAcao(sreg, sacao)
      integer sreg, sacao

      include 'livrus.h'
      integer tamReg
      character*255 LinhaReg, repete

      if (sreg .eq. opAssunto) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, 
     *      MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, 
     *      MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfAssunto, repete('*',tamReg(sreg)), 
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opAutor) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfAutor, repete('*',tamReg(sreg)), 
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opEditora) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfEditora, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opEndereco) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfEndereco, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opIdioma) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfIdioma, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opPais) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfPais, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opProfissao) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfProfissao, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opLivro) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfLivro, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opLivroAss) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfLivroAss, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opLivroAut) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfLivroAut, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opCliente) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfCliente, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opVenda) then
         if (sacao .eq. opSalvarInclusao) then
           call escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, 
     *     MSG_REGNINC)
         else if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, 
     *     MSG_REGNALT)
         else if (sacao .eq. opConfirmaExclusao) then
           call escreveArq(tfVenda, repete('*',tamReg(sreg)),
     *      MSG_REGEXC, MSG_REGNEXC)
         end if 
      else if (sreg .eq. opUsuario) then
         if (sacao .eq. opSalvarAlteracao) then
           call escreveArq(tfUsuario, LinhaReg(sreg), 
     *      MSG_REGALT, MSG_REGNALT)
         end if
      end if
      return  
      end
C     ------------------------------------------------------------------
C     Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
C     nmenu - o número do menu
C     sreg - o tipo de arquivo
C     ------------------------------------------------------------------
      subroutine subMenu(nmenu, sreg)
      integer nmenu, sreg

      include 'livrus.h'
      
      integer opSubMenu
      character opCSubMenu
      logical bSOp

      bSOp=.true.
      select case (nmenu)
        case (6)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(I1)') opSubMenu
            select case (opSubMenu)
              case (1)
                call frmCadastros(sreg, opNovo)
                if (sreg .eq. opAssunto) then
                  write(*,*) 'cadastro novo'
                end if
              case (2)
                call frmCadastros(sreg, opPesquisar)
              case (3)
                bSOp=.false.
              case default 
                write(*,*) MSG_ERRO
            end select 
          end do
        case (7)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(I1)') opSubMenu
            select case (opSubMenu)
              case (1)
                call btnAcao(sreg, opSalvarInclusao)
                bSOp=.false.
              case (2)
                bSOp=.false.
              case default 
                write(*,*) MSG_ERRO
            end select 
          end do
        case (8)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(I1)') opSubMenu
            select case (opSubMenu)
              case (1)
                call frmCadastros(sreg, opAlterar)
                bSOp=.false. 
              case (2) 
                call frmCadastros(sreg, opExcluir)
                bSOp=.false.
              case (3)
                bSOp=.false.
              case default 
                write(*,*) MSG_ERRO
            end select 
          end do
        case (9)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(I1)') opSubMenu
            select case (opSubMenu)
              case (1)
                call btnAcao(sreg, opSalvarAlteracao)
                bSOp=.false.
              case (2)
                bSOp=.false.
              case default 
                write(*,*) MSG_ERRO
            end select 
          end do
        case (10)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(A1)') opCSubMenu
            if (opCSubMenu.eq.'S' .or. opCSubMenu.eq.'s') then
              call btnAcao(sreg, opConfirmaExclusao)
              bSOp=.false.
            else if (opCSubMenu.eq.'N' .or. opCSubMenu.eq.'n') then 
              bSOp=.false.
            else 
              write(*,*) MSG_ERRO
            end if
          end do
        case (12)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(I1)') opSubMenu
            select case (opSubMenu)
              case (1)
                call frmConsultas(sreg, opPesquisar)
              case (2) 
                call frmConsultas(sreg, opListarTodos)
              case (3)
                bSOp=.false.
              case default 
                write(*,*) MSG_ERRO
            end select 
          end do
        case (14)
          do while(bSOp) 
            call menu(nmenu)
            read(*,'(A1)') opCSubMenu
            if (opCSubMenu.eq.'S' .or. opCSubMenu.eq.'s') then
              call btnAcao(sreg, opSalvarInclusao)
              bSOp=.false.
              g_SalvarInclusao = .true.
            else if (opCSubMenu.eq.'N' .or. opCSubMenu.eq.'n') then
              bSOp=.false.
            else
              write(*,*) MSG_ERRO
            end if
          end do
      end select      
      end
C     ------------------------------------------------------------------
C     Seleciona o submenu e/ou a tela certa de acordo com número do menu.
C     nmenu - o número do menu
C     ------------------------------------------------------------------
      subroutine usaMenu(num)
      integer num   

      include 'livrus.h'

      integer opSubMenu
      logical bSOp
      character opSair

      bSOp=.true.
C     ---------
C     Cadastros
C     ---------  
      if (num.eq.1) then  
        do while(bSOp)
          call menu(2)
          read(*,'(I2)') opSubMenu
          select case (opSubMenu)
            case (1) 
              call subMenu(6, opAssunto)
            case (2)
              call subMenu(6, opAutor)
            case (3)
              call subMenu(6, opEditora)
            case (4)
              call subMenu(6, opEndereco)
            case (5)
              call subMenu(6, opIdioma)
            case (6)
              call subMenu(6, opPais)
            case (7)
              call subMenu(6, opProfissao)
            case (8)
              call subMenu(6, opCliente)
            case (9)
              call subMenu(6, opLivro)
            case (10)
              bSOp=.false.
            case default 
              write(*,*) MSG_ERRO
          end select
        end do
C     ---------
C     Pesquisas
C     ---------
      else if (num.eq.2) then  
        do while(bSOp)
          call menu(3)
          read(*,'(I2)') opSubMenu
          select case (opSubMenu)
            case (1) 
              call subMenu(12, opAssunto)
            case (2)
              call subMenu(12, opAutor)
            case (3)
              call subMenu(12, opEditora)
            case (4)
              call subMenu(12, opEndereco)
            case (5)
              call subMenu(12, opIdioma)
            case (6)
              call subMenu(12, opPais)
            case (7)
              call subMenu(12, opProfissao)
            case (8)
              call subMenu(12, opCliente)
            case (9)
              call subMenu(12, opLivro)
            case (10)
              bSOp=.false.
            case default 
              write(*,*) MSG_ERRO
          end select
        end do
C     ------
C     Vendas 
C     ------
      else if (num.eq.3) then 
        do while(bSOp)
          call menu(4)
          read(*,'(I2)') opSubMenu
          select case (opSubMenu)
            case (1) 
              call subMenu(6, opVenda)
            case (2)
              call subMenu(12, opVenda)
            case (3)
              bSOp=.false.
            case default 
              write(*,*) MSG_ERRO
          end select
        end do
C     ------
C     Opcoes
C     ------
      else if (num.eq.4) then
        do while(bSOp)
          call menu(5)
          read(*,'(I2)') opSubMenu
          select case (opSubMenu)
            case (1) 
              call frmAlterarSenha
            case (2)
              call frmSobre
            case (3)
              call menu(11)
              read(*,'(A1)') opSair
              if (opSair.eq.'S' .or. opSair.eq.'s') then 
                call fechaArqs
                stop
              end if
            case (4) 
              bSOp=.false.
            case default 
              write(*,*) MSG_ERRO
          end select
        end do
      end if
      end
C     ------------------------------------------------------------------
C     Mostra as entradas e as saídas do sistema.
C     sreg - o tipo de arquivo
C     slinha - o registro com os dados
C     nOpcao - indica qual opção será mostrada
C     ------------------------------------------------------------------
      subroutine mostrarDados(sreg, slinha, nOpcao)
      integer sreg, nOpcao
      character*255 slinha 

      include 'livrus.h'
      character*255 rotulo, ftrim, copy, validaNumero, validaDataHora

      if (sreg .eq. opAssunto) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 1), tAssunto_codigo
              write(*,*) rotulo(sreg, 2)
              read(*,*) tAssunto_assunto
           case (2)
              write(*,*) 'Código     Assunto'
              write(*,*) '------     -------'
           case (3)
              tAssunto_codigo=copy(slinha, 1, 10)
              tAssunto_assunto=copy(slinha, 11, 30)
              write(*,*) tAssunto_codigo,' ',tAssunto_assunto
         end select
      else if (sreg .eq. opAutor) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 1), tAutor_codigo
              write(*,*) rotulo(sreg, 2)
              read(*,*) tAutor_autor
           case (2)
              write(*,*) 'Código     Autor'
              write(*,*) '------     -----'
           case (3)
              tAutor_codigo=copy(slinha, 1, 10)
              tAutor_autor=copy(slinha, 11, 30)
              write(*,*) tAutor_codigo,' ',tAutor_autor
         end select
      else if (sreg .eq. opEditora) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 1), tEditora_codigo
              write(*,*) rotulo(sreg, 2)
              read(*,*) tEditora_editora
           case (2)
              write(*,*) 'Código     Editora'
              write(*,*) '------     -------'
           case (3)
              tEditora_codigo=copy(slinha, 1, 10)
              tEditora_editora=copy(slinha, 11, 50)
              write(*,*) tEditora_codigo,' ',tEditora_editora
         end select
      else if (sreg .eq. opEndereco) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 1), tEndereco_codigo
              write(*,*) rotulo(sreg, 2)
              read(*,*) tEndereco_Logradouro
              write(*,*) rotulo(sreg, 3)
              read(*,*) tEndereco_bairro
              write(*,*) rotulo(sreg, 4)
              read(*,*) tEndereco_cep
              write(*,*) rotulo(sreg, 5)
              read(*,*) tEndereco_cidade
              write(*,*) rotulo(sreg, 6)
              read(*,*) tEndereco_estado
           case (3)
              tEndereco_codigo=ftrim(copy(slinha, 1, 10))
              tEndereco_logradouro=ftrim(copy(slinha, 11, 40))
              tEndereco_bairro=ftrim(copy(slinha, 51, 15))
              tEndereco_cep=ftrim(copy(slinha, 66, 8))
              tEndereco_cidade=ftrim(copy(slinha, 74, 30))
              tEndereco_estado=ftrim(copy(slinha, 104, 20))
              write(*,*) '--------------------'
              write(*,*) rotulo(sreg, 1), tEndereco_codigo
              write(*,*) rotulo(sreg, 2), tEndereco_Logradouro
              write(*,*) rotulo(sreg, 3), tEndereco_bairro
              write(*,*) rotulo(sreg, 4), tEndereco_cep
              write(*,*) rotulo(sreg, 5), tEndereco_cidade
              write(*,*) rotulo(sreg, 6), tEndereco_estado
         end select
      else if (sreg .eq. opIdioma) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 1), tIdioma_codigo
              write(*,*) rotulo(sreg, 2)
              read(*,*) tIdioma_idioma
           case (2)
              write(*,*) 'Código     Idioma'
              write(*,*) '------     ------'
           case (3)
              tIdioma_codigo=copy(slinha, 1, 10)
              tIdioma_idioma=copy(slinha, 11, 20)
              write(*,*) tIdioma_codigo,' ',tIdioma_idioma
         end select
      else if (sreg .eq. opPais) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 2)
              read(*,*) tPais_pais
           case (2)
              write(*,*) 'Código País'
              write(*,*) '------ ----'
           case (3)
              tPais_codigo=copy(slinha, 1, 3)
              tPais_pais=copy(slinha, 4, 50)
              write(*,*) tPais_codigo,'    ',tPais_pais
         end select
      else if (sreg .eq. opProfissao) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 1), tProfissao_codigo
              write(*,*) rotulo(sreg, 2)
              read(*,*) tProfissao_profissao
           case (2)
              write(*,*) 'Código     Profissão'
              write(*,*) '------     ---------'
           case (3)
              tProfissao_codigo=copy(slinha, 1, 10)
              tProfissao_profissao=copy(slinha, 11, 50)
              write(*,*) tProfissao_codigo,' ',tProfissao_profissao
         end select
      else if (sreg .eq. opLivro) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 2)
              read(*,*) tLivro_titulo
              tLivro_edicao=validaNumero(rotulo(sreg, 3), tLivro_edicao)
              tLivro_anopubli=validaNumero(rotulo(sreg, 4), 
     *         tLivro_anopubli)
              call mostrarSubDados(opLivro, opEditora, .false.)
              tLivro_volume=validaNumero(rotulo(sreg, 6), tLivro_volume)
              call mostrarSubDados(opLivro, opIdioma, .false.)
              tLivro_npaginas=validaNumero(rotulo(sreg, 8), 
     *         tLivro_npaginas)
              tLivro_preco=validaNumero(rotulo(sreg, 9), tLivro_preco)
              tLivro_qtdestoque=validaNumero(rotulo(sreg, 10), 
     *         tLivro_qtdestoque)
           case (3)
              tLivro_isbn=ftrim(copy(slinha, 1, 13))
              tLivro_titulo=ftrim(copy(slinha, 14, 50))
              tLivro_edicao=ftrim(copy(slinha, 64, 10))
              tLivro_anopubli=ftrim(copy(slinha, 74, 10))
              tLivro_codeditora=ftrim(copy(slinha, 84, 10))
              tLivro_volume=ftrim(copy(slinha, 94, 10))
              tLivro_codidioma=ftrim(copy(slinha, 104, 10))
              tLivro_npaginas=ftrim(copy(slinha, 114, 10))
              tLivro_preco=ftrim(copy(slinha, 124, 10))
              tLivro_qtdestoque=ftrim(copy(slinha, 134, 10))
              write(*,*) '--------------------'
              write(*,*) rotulo(sreg, 1), tLivro_isbn
              write(*,*) rotulo(sreg, 2), tLivro_titulo
              write(*,*) rotulo(sreg, 3), tLivro_edicao
              write(*,*) rotulo(sreg, 4), tLivro_anopubli
              write(*,*) rotulo(sreg, 5), tLivro_codeditora
              call mostrarSubDados(opLivro, opEditora, .true.)
              write(*,*) rotulo(sreg, 6), tLivro_volume
              write(*,*) rotulo(sreg, 7), tLivro_codidioma
              call mostrarSubDados(opLivro, opIdioma, .true.)
              write(*,*) rotulo(sreg, 8), tLivro_npaginas
              write(*,*) rotulo(sreg, 9), tLivro_preco
              write(*,*) rotulo(sreg, 10), tLivro_qtdestoque
              call ListarRegLigados(tfLivroAss, opLivroAss, 
     *         1, 13, 14, 10, tLivro_isbn, tfAssunto, opAssunto, 1, 4)
              call ListarRegLigados(tfLivroAut, opLivroAut, 
     *         1, 13, 14, 10, tLivro_isbn, tfAutor, opAutor, 1, 4)
         end select
      else if (sreg .eq. opCliente) then
         select case (nOpcao)
           case (1)
              write(*,*) rotulo(sreg, 2)
              read(*,*) tCliente_nome
              write(*,*) rotulo(sreg, 3)
              read(*,*) tCliente_email
              write(*,*) rotulo(sreg, 4)
              read(*,*) tCliente_identidade
              write(*,*) rotulo(sreg, 5)
              read(*,*) tCliente_sexo
              write(*,*) rotulo(sreg, 6)
              read(*,*) tCliente_telefone
              tCliente_dtnascimento=validaDataHora(rotulo(sreg, 7), 
     *         tCliente_dtnascimento, .true.)
              call mostrarSubDados(opCliente, opEndereco, .false.)
              call mostrarSubDados(opCliente, opPais, .false.)
              call mostrarSubDados(opCliente, opProfissao, .false.)
           case (3)
              tCliente_cpf=ftrim(copy(slinha, 1, 14))
              tCliente_nome=ftrim(copy(slinha, 15, 30))
              tCliente_email=ftrim(copy(slinha, 45, 30))
              tCliente_identidade=ftrim(copy(slinha, 75, 10))
              tCliente_sexo=ftrim(copy(slinha, 85, 1))
              tCliente_telefone=ftrim(copy(slinha, 86, 17))
              tCliente_dtnascimento=ftrim(copy(slinha, 103, 10))
              tCliente_codendereco=ftrim(copy(slinha, 113, 10))
              tCliente_codpais=ftrim(copy(slinha, 123, 3))
              tCliente_codprofissao=ftrim(copy(slinha, 126, 10))
              write(*,*) '--------------------'
              write(*,*) rotulo(sreg, 1), tCliente_cpf
              write(*,*) rotulo(sreg, 2), tCliente_nome
              write(*,*) rotulo(sreg, 3), tCliente_email
              write(*,*) rotulo(sreg, 4), tCliente_identidade
              write(*,*) rotulo(sreg, 5), tCliente_sexo
              write(*,*) rotulo(sreg, 6), tCliente_telefone
              write(*,*) rotulo(sreg, 7), tCliente_dtnascimento
              write(*,*) rotulo(sreg, 8), tCliente_codendereco
              call mostrarSubDados(opCliente, opEndereco, .true.)
              write(*,*) rotulo(sreg, 9), tCliente_codpais
              call mostrarSubDados(opCliente, opPais, .true.)
              write(*,*) rotulo(sreg, 10), tCliente_codprofissao
              call mostrarSubDados(opCliente, opProfissao, .true.)
         end select
      else if (sreg .eq. opVenda) then
         select case (nOpcao)
           case (1) 
              call mostrarSubDados(opVenda,opVenda, .false.)
           case (2)
              write(*,*) 'DataHoraVenda       CPF            ISBN       
     *   PreçoVenda'
              write(*,*) '-------------       ---            ----       
     *   ----------'
           case (3)
              tVenda_dthrvenda=copy(slinha, 1, 19)
              tVenda_cpf=copy(slinha, 20, 14)
              tVenda_isbn=copy(slinha, 34, 13)
              tVenda_precovenda=copy(slinha, 47, 10)
              write(*,*) tVenda_dthrvenda,' ',tVenda_cpf,' ',
     *         tVenda_isbn,' ',tVenda_precovenda
         end select
      end if
      return
      end
C     ------------------------------------------------------------------
C     Mostra as sub informções de entrada e de saída.
C     sreg - o tipo de arquivo
C     ssubreg - o subtipo de arquivo
C     bSoMostrar - se vai só mostrar na saída 
C     ------------------------------------------------------------------
      subroutine mostrarSubDados(sreg, ssubreg, bSoMostrar)
      integer sreg, ssubreg
      logical bSoMostrar

      include 'livrus.h'
      character*255 sRegistro, sPreco, pesqArq, 
     * validaEntrada, ftrim, copy, rotulo
      integer nMaxTentativas, tamReg

      nMaxTentativas=3
      if (sreg .eq. opLivro) then
        if (sreg .eq. opEditora) then
          if (bSoMostrar .eqv. .true.) then
             sRegistro=pesqArq(tfEditora,tLivro_codeditora,1,10,
     *        tamReg(opEditora))
          else
             sRegistro=validaEntrada(tfEditora,ssubreg,1,
     *        tLivro_codeditora,nMaxTentativas,.false.,opNumero)
          end if  
          if (sRegistro .ne. '') then
            tLivro_codeditora=ftrim(copy(sRegistro,1,10))
            write(*,*) ' ',rotulo(opEditora, 2)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
          end if
        else if (ssubreg .eq. opIdioma) then
          if (bSoMostrar .eqv. .true.) then
             sRegistro=pesqArq(tfIdioma, tLivro_codidioma, 1, 10,
     *        tamReg(opIdioma))
          else
             sRegistro=validaEntrada(tfIdioma,ssubreg,1,
     *        tLivro_codidioma,nMaxTentativas,.false.,opNumero)
          end if  
          if (sRegistro .ne. '') then
            tLivro_codidioma=ftrim(copy(sRegistro,1,10))
            write(*,*) ' ',rotulo(opIdioma, 2)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
          end if
        end if
      else if (sreg .eq. opCliente) then
        if (ssubreg .eq. opEndereco) then
          if (bSoMostrar .eqv. .true.) then
             sRegistro=pesqArq(tfEndereco, tCliente_codendereco, 1, 10,
     *                 tamReg(opEndereco))
          else
             sRegistro=validaEntrada(tfEndereco,ssubreg,1,
     *       tCliente_codendereco,nMaxTentativas,.false.,opNumero)
          end if  
          if (sRegistro.ne.'') then
            tCliente_codendereco=ftrim(copy(sRegistro,1,10))
            write(*,*) ' ',rotulo(opEndereco, 2)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
            write(*,*) ' ',rotulo(opEndereco, 3)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
            write(*,*) ' ',rotulo(opEndereco, 4)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
            write(*,*) ' ',rotulo(opEndereco, 5)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
            write(*,*) ' ',rotulo(opEndereco, 6)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
          end if
        else if (ssubreg .eq. opPais) then
          if (bSoMostrar .eqv. .true.) then
             sRegistro=pesqArq(tfPais, tCliente_codpais, 1, 3, 
     *        tamReg(opPais))
          else
             sRegistro=validaEntrada(tfPais,ssubreg,1,tCliente_codpais,
     *                   nMaxTentativas,.false.,opTexto)
          end if
          if (sRegistro.ne.'') then
            tCliente_codpais=ftrim(copy(sRegistro,1,3))
            write(*,*) ' ',rotulo(opPais, 2)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
          end if
        else if (ssubreg .eq. opProfissao) then
          if (bSoMostrar .eqv. .true.) then
             sRegistro=pesqArq(tfProfissao,tCliente_codprofissao,1,10,
     *                  tamReg(opProfissao))
          else
             sRegistro=validaEntrada(tfProfissao,ssubreg,1,
     *       tCliente_codprofissao,nMaxTentativas,.false.,opNumero)
          end if
          if (sRegistro.ne.'') then
            tCliente_codprofissao=ftrim(copy(sRegistro,1,10))
            write(*,*) ' ',rotulo(opProfissao, 2)
            write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
          end if
        end if
      else if (sreg .eq. opVenda) then
        sRegistro=pesqArq(tfLivro, tVenda_isbn, 1, 13,tamReg(opLivro))
        if (sRegistro.ne.'') then
          write(*,*) ' ',rotulo(opLivro, 2)
          write(*,*) copy(sRegistro, g_nPosChave, g_nTamChave)
          write(*,*) ' ',rotulo(opLivro, 9)
          sPreco=copy(sRegistro, g_nPosChave, g_nTamChave)
C          g_nPreco = FloatToStr(sPreco)
          write(*,*) sPreco
        end if
      end if
      return
      end
C     ------------------------------------------------------------------
C     Realiza os cadastros dos arquivos que se ligam a outros arquivos.
C     sreg - o tipo de arquivo
C     sacao - a ação a ser realizada
C     sCodigo - um das chaves do arquivo de ligação
C     ------------------------------------------------------------------
      subroutine frmCadLigados(sreg, sacao, sCodigo)
      integer sreg, sacao 
      character*255 sCodigo

      include 'livrus.h'
      integer nQtd, nCont, nQtdEstoque, tamReg, StrToInt
      real nTotalPreco
      character*255 slinha, sTotalPreco, sPreco, sQtd, rotulo,
     * pesqArq, validaNumero, ftrim, copy, IntToStr, validaEntrada, esp
      logical validaISBN

      if (sacao .eq. opNovo) then
        nCont=1
        if (sreg .eq. opLivroAss) then
          sQtd=validaNumero('Quantos assuntos quer cadastrar?: ', sQtd)
          nQtd=StrToInt(sQtd)
C          seek(tfLivroAss, 0)
          do while (nCont .le. nQtd)
            tLivroAss_isbn=sCodigo
            write(*,*) rotulo(opLivroAss, 2)
            read(*,*) tLivroAss_codassunto
            slinha=pesqArq(tfAssunto, tLivroAss_codassunto,1,10,
     *       tamReg(opAssunto))
            write(*,*) ' ',rotulo(opAssunto, 2)
            write(*,*) copy(slinha, g_nPosChave, g_nTamChave)
            call pesqLinhaExcluida(tfLivroAss, tamReg(sreg))
            call subMenu(14, sreg)
            nCont=nCont+1
          end do
        else if (sreg .eq. opLivroAut) then
          sQtd=validaNumero('Quantos autores quer cadastrar?: ',sQtd)
          nQtd=StrToInt(sQtd)
C          seek(tfLivroAut, 0)
          do while (nCont .le. nQtd)
            tLivroAut_isbn=sCodigo
            write(*,*) rotulo(opLivroAut, 2)
            read(*,*) tLivroAut_codautor
            slinha=pesqArq(tfAutor, tLivroAut_codautor,1,10,
     *       tamReg(opAutor))
            write(*,*) ' ',rotulo(opAutor, 2)
            write(*,*) copy(slinha, g_nPosChave, g_nTamChave)
            call pesqLinhaExcluida(tfLivroAut, tamReg(sreg))
            call subMenu(14, sreg)
            nCont=nCont+1
          end do
        else if (sreg .eq. opVenda) then
          sQtd=validaNumero('Quantos livros quer vender?: ',sQtd)
          nQtd=StrToInt(sQtd)
          nTotalPreco=0
          do while (nCont .le. nQtd)
            slinha=validaEntrada(tfLivro,opLivro,1,tVenda_isbn,3,
     *       .false.,opTexto)
            if (slinha.ne.'') then
              tVenda_isbn=ftrim(copy(slinha,1,13))
              if (validaISBN(tVenda_isbn) .eqv. .true.) then
                call mostrarDados(sreg, '', 1)
                tLivro_qtdestoque=ftrim(copy(slinha,134,10))
                nQtdEstoque=StrToInt(tLivro_qtdestoque)
                if (nQtdEstoque .gt. 0) then
                   nTotalPreco=nTotalPreco + g_nPreco
C                   sPreco = FloatToStr(g_nPreco)
                   tVenda_precovenda=sPreco
                   g_SalvarInclusao=.false.
                   call subMenu(14, sreg)
                   if (g_SalvarInclusao .eqv. .true.) then
                      slinha=pesqArq(tfLivro, tVenda_isbn, 1, 13, 
     *                 tamReg(opLivro))
                      if (slinha .ne. '') then
                         nQtdEstoque=nQtdEstoque-1
                         tLivro_qtdestoque = IntToStr(nQtdEstoque)
                         call SomaStr(slinha, copy(slinha,1,133))
                         call SomaStr(slinha, esp(tLivro_qtdestoque,10))
                         call escreveArq(tfLivro, slinha, '', '')
                      end if
                   end if
                   nCont=nCont+1
                else 
                  write(*,*) MSG_SEMESTOQUE
                end if    
              else 
                write(*,*) MSG_ISBNINV
              end if    
            end if
          end do
C          sTotalPreco = FloatToStr(nTotalPreco)
          write(*,*) 'Total de ',rotulo(sreg,4), sTotalPreco
        end if  
      else if (sacao .eq. opExcluir) then
        if (sreg .eq. opLivroAss) then
          call ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo)
        else if (sreg .eq. opLivroAut) then
          call ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo)
        end if
      end if
      return
      end
C     ------------------------------------------------------------------
C     Realiza a exclusão dos arquivos de ligação.
C     sArq - o arquivo de ligação
C     sreg - o tipo de arquivo de ligação
C     nPosChave - a posicao inicial da chave dentro do registro
C     nTamChave - o tamanho da chave dentro do registro
C     sChave - a chave a ser excluida
C     ------------------------------------------------------------------
      subroutine ExcluirRegLigados(sArq, sreg, nPosChave, 
     * nTamChave, sChave)
      integer sArq, sreg, nPosChave, nTamChave
      character*255 sChave

      include 'livrus.h' 
      character*255 slinha, sCodigo, ftrim, copy
      integer fimarq, nPosicao

C        seek(sArq, 0)
        do while (fimarq.ne.-1)
          read(sArq,rec=nPosicao,iostat=fimarq) slinha
          sCodigo=ftrim(copy(slinha,nPosChave,nTamChave))
          if (sCodigo .eq. sChave) then
             call btnAcao(sreg,opConfirmaExclusao)
          end if  
          nPosicao = nPosicao + 1
        end do
      return
      end      
