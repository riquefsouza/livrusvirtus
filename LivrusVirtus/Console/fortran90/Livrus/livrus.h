C     ------------------------------------------------------------------
C     Livrus.h
C     ------------------------------------------------------------------
C     Bloco de dados
C     --------------
      common /registros/
     &  tAssunto_codigo, tAssunto_assunto,
     &  tAutor_codigo, tAutor_autor,
     &  tEditora_codigo, tEditora_editora,
     &  tIdioma_codigo, tIdioma_idioma,
     &  tUsuario_login, tUsuario_senha,
     &  tPais_codigo, tPais_pais,
     &  tProfissao_codigo, tProfissao_profissao,
     &  tLivro_isbn, tLivro_titulo, tLivro_edicao, tLivro_anopubli,
     &  tLivro_codeditora, tLivro_volume, tLivro_codidioma,
     &  tLivro_npaginas, tLivro_preco, tLivro_qtdestoque,
     &  tLivroAss_isbn, tLivroAss_codassunto,
     &  tLivroAut_isbn, tLivroAut_codautor,
     &  tCliente_cpf, tCliente_nome, tCliente_email,tCliente_identidade, 
     &  tCliente_sexo, tCliente_telefone, tCliente_dtnascimento, 
     &  tCliente_codendereco, tCliente_codpais, tCliente_codprofissao,
     &  tEndereco_codigo, tEndereco_logradouro, tEndereco_bairro,
     &  tEndereco_cep, tEndereco_cidade, tEndereco_estado,
     &  tVenda_dthrvenda, tVenda_cpf, tVenda_isbn, tVenda_precovenda

C     structure /regAssunto/
        character*10 tAssunto_codigo
        character*30 tAssunto_assunto
C     end structure
C      record /regAssunto/ tAssunto
C     structure /regAutor/
        character*10 tAutor_codigo
        character*30 tAutor_autor
C     end structure
C      record /regAutor/ tAutor
C     structure /regEditora/
        character*10 tEditora_codigo
        character*50 tEditora_editora
C     end structure
C      record /regEditora/ tEditora
C     structure /regIdioma/
        character*10 tIdioma_codigo
        character*20 tIdioma_idioma
C     end structure
C      record /regIdioma/ tIdioma
C     structure /regUsuario/
        character*10 tUsuario_login
        character*10 tUsuario_senha
C     end structure
C      record /regEditora/ tEditora
C     structure /regPais/
        character*3 tPais_codigo
        character*50 tPais_pais
C     end structure
C      record /regPais/ tPais
C     structure /regProfissao/
        character*10 tProfissao_codigo
        character*50 tProfissao_profissao
C     end structure
C      record /regProfissao/ tProfissao
C     structure /regLivro/
        character*10 tLivro_isbn
        character*50 tLivro_titulo
        character*10 tLivro_edicao
        character*10 tLivro_anopubli
        character*10 tLivro_codeditora 
        character*10 tLivro_volume
        character*10 tLivro_codidioma
        character*10 tLivro_npaginas 
        character*10 tLivro_preco
        character*10 tLivro_qtdestoque
C     end structure
C      record /regLivro/ tLivro
C     structure /regLivroAss/
        character*13 tLivroAss_isbn
        character*10 tLivroAss_codassunto
C     end structure
C      record /regLivroAss/ tLivroAss
C     structure /regLivroAut/
        character*13 tLivroAut_isbn
        character*10 tLivroAut_codautor
C     end structure
C      record /regLivroAut/ tLivroAut
C     structure /regCliente/
        character*14 tCliente_cpf
        character*30 tCliente_nome
        character*30 tCliente_email
        character*10 tCliente_identidade
        character*1  tCliente_sexo
        character*17 tCliente_telefone
        character*10 tCliente_dtnascimento
        character*10 tCliente_codendereco
        character*3  tCliente_codpais
        character*10 tCliente_codprofissao
C     end structure
C      record /regCliente/ tCliente
C     structure /regEndereco/
        character*10 tEndereco_codigo
        character*40 tEndereco_logradouro
        character*15 tEndereco_bairro
        character*8  tEndereco_cep
        character*30 tEndereco_cidade
        character*20 tEndereco_estado
C     end structure
C      record /regEndereco/ tEndereco
C     structure /regVenda/
C       data/hora da venda dd/mm/yyyy hh:mm:ss 
        character*19 tVenda_dthrvenda  
        character*14 tVenda_cpf
        character*13 tVenda_isbn
        character*10 tVenda_precovenda
C     end structure
C      record /regVenda/ tVenda

C     ----------
C     constantes
C     ----------
      common /ctTipo/
     &  opTexto, opNumero, opData, opDataHora, opSenha

      integer opTexto, opNumero, opData, opDataHora, opSenha

      common /ctArqs/
     &  opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
     &  opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
     &  opUsuario, opVenda

      integer opAssunto, opAutor, opEditora, opEndereco, opIdioma, 
     *opPais, opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
     *opUsuario, opVenda

      common /ctAcao/
     &  opNovo, opAlterar, opPesquisar, opSalvarInclusao,
     &  opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos

      integer opNovo, opAlterar, opPesquisar, opSalvarInclusao,
     *opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos

      common /constantes/
     &  TAM_CRLF, QTD_MAX_LINHA, MSG_ERRO, MSG_OPCAO, MSG_PRESS, 
     &  MSG_REGINC, MSG_REGNINC, MSG_REGALT, MSG_REGNALT, MSG_REGEXC, 
     &  MSG_REGNEXC, MSG_REGEXST, MSG_NUMINV, MSG_DATAINV, MSG_DTHRINV, 
     &  MSG_ISBNINV, MSG_CPFINV, MSG_SENCONFERE, MSG_SENCONFIRM, 
     &  MSG_LOGINENCON, MSG_SEMESTOQUE, MSG_ARQERRO, CRLF

      character*2 CRLF
      integer TAM_CRLF, QTD_MAX_LINHA
      character*36 MSG_ERRO
      character*20 MSG_OPCAO      
      character*30 MSG_PRESS
      character*36 MSG_ARQERRO

      character*18 MSG_REGINC
      character*22 MSG_REGNINC
      character*18 MSG_REGALT
      character*22 MSG_REGNALT 
      character*18 MSG_REGEXC
      character*22 MSG_REGNEXC
      character*19 MSG_REGEXST

      character*34 MSG_NUMINV
      character*44 MSG_DATAINV
      character*58 MSG_DTHRINV 
      character*14 MSG_ISBNINV 
      character*13 MSG_CPFINV 
      character*36 MSG_SENCONFERE 
      character*46 MSG_SENCONFIRM 
      character*21 MSG_LOGINENCON 
      character*28 MSG_SEMESTOQUE 

      common /arquivos/
     &  ARQ_ASSUNTO, ARQ_AUTOR, ARQ_EDITORA, ARQ_IDIOMA, 
     &  ARQ_USUARIO, ARQ_PAIS, ARQ_PROFISSAO, ARQ_LIVRO, ARQ_LIVASS, 
     &  ARQ_LIVAUT, ARQ_CLIENTE, ARQ_ENDERECO, ARQ_VENDA

      character*255 ARQ_ASSUNTO, ARQ_AUTOR, ARQ_EDITORA, ARQ_IDIOMA, 
     *ARQ_USUARIO, ARQ_PAIS, ARQ_PROFISSAO, ARQ_LIVRO, ARQ_LIVASS, 
     *ARQ_LIVAUT, ARQ_CLIENTE, ARQ_ENDERECO, ARQ_VENDA

      common /tamanhos/
     &  TAM_ASSUNTO, TAM_AUTOR, TAM_EDITORA, TAM_IDIOMA, 
     &  TAM_USUARIO, TAM_PAIS, TAM_PROFISSAO, TAM_LIVRO, TAM_LIVASS, 
     &  TAM_LIVAUT, TAM_CLIENTE, TAM_ENDERECO, TAM_VENDA

      integer TAM_ASSUNTO, TAM_AUTOR, TAM_EDITORA, TAM_IDIOMA, 
     *TAM_USUARIO, TAM_PAIS, TAM_PROFISSAO, TAM_LIVRO, TAM_LIVASS, 
     *TAM_LIVAUT, TAM_CLIENTE, TAM_ENDERECO, TAM_VENDA  

      common /tiposarqs/
     &  tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, 
     &  tfPais, tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente,
     &  tfUsuario, tfVenda

      integer tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, 
     *tfPais, tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente,
     *tfUsuario, tfVenda

C     -----------------
C     variaveis globais
C     -----------------
      common /varglobais/ g_nPosChave, g_nTamChave, g_nPreco, 
     & g_SalvarInclusao

      integer g_nPosChave, g_nTamChave
      logical g_SalvarInclusao
      real g_nPreco
C     ------------------------------------------------------------------
