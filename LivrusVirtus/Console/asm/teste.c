/*
extrn	_strncpy:near
extrn	_strcpy:near
extrn	_strcat:near
extrn	_strstr:near
extrn	_strcmp:near
extrn	_strlen:near
extrn	_getch:near
extrn	_exit:near


extrn	_atol:near
extrn	_atof:near
extrn	_gcvt:near

extrn	_localtime:near
extrn	_strftime:near

extrn	_fgets:near
extrn	_printf:near

extrn	_fflush:near
extrn	_rewind:near
extrn	_fopen:near
extrn	_fwrite:near
extrn	_fclose:near
extrn	_ftell:near
extrn	_fseek:near
extrn	_fread:near
extrn	_fgetc:near
extrn	_fscanf:near

extrn	_malloc:near
extrn	_time:near
extrn	_free:near
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef char* mstring;


int tamstr(char *str)
{
  int ncont = 0;
  while (str[ncont]!='\0')
    ncont++;
  return ncont;
}

void atribstr(char *str1, char *str2)
{
  int ncont = 0;
  while (str2[ncont]!='\0') {
    str1[ncont]=str2[ncont];
    ncont++;
  }
  str1[ncont]='\0';
}

void atribmaxstr(char *str1, char *str2, int ntam)
{
  atribstr(str1,str2);
  str1[ntam]='\0';
}

char *concatstr(char *str1, char *str2)
{
  int ncont1 = 0;
  int ncont2 = tamstr(str1);

  while (str2[ncont1]!='\0') {
    str1[ncont2]=str2[ncont1];
    ncont1++;
    ncont2++;
  }
  str1[ncont2]='\0';

 return str1;
}

int comparastr(char *str1, char *str2)
{
  if (tamstr(str1)==tamstr(str2)) {
    int ncont = 0;
    while (str2[ncont]!='\0') {
      if (str1[ncont]!=str2[ncont])
        return 1;
      ncont++;
    }
    return 0;
  } else
    return 1;
}


void sair(void)
{
 asm mov cx,0         /* CX = conta na saida */
 asm jcxz p1_fora     /* sem funcoes de saidas ? */
 asm mov si,0FF60h    /* SI = tabela na saida */

p1_loop:
 asm lodsw            /* pega funcao */
 asm call ax          /* chama funcao */
 asm loop p1_loop     /* Loop de volta */

p1_fora:
 asm pop ax ax        /* retira argumento dentro de AX */
 asm mov ah,4Ch       /* termina programa */
 asm int 21h          /* chama interrupcao do DOS */
}

int auxpegatecla(void)
{
 asm push dx
 asm mov ah, 6
 asm mov dl, 255
 asm int 21h
 asm pop dx
 asm jz semchar
 asm xor ah,ah
 asm ret

semchar:
 asm mov ax,-1
 asm ret
}

int pegatecla(void)
{
esperaloop:
 asm call auxpegatecla
 asm cmp ax, -1
 asm je esperaloop
 asm ret
}

int strtoint(char *str)
{
  int acc = 0;
  int ncont = 0;
  char ch;
  int negativo = 1;
  int primpos = 0;
  int ntemp;

  if (str[0] == '-') {
       negativo = -1;
       primpos = 1;
  }
  for (ncont=primpos; ncont < tamstr(str); ncont++) {
       ch = str[ncont];
       if (ch >= '0' && ch <= '9') {
         switch(ch) {
           case '0': ntemp=0; break;
           case '1': ntemp=1; break;
           case '2': ntemp=2; break;
           case '3': ntemp=3; break;
           case '4': ntemp=4; break;
           case '5': ntemp=5; break;
           case '6': ntemp=6; break;
           case '7': ntemp=7; break;
           case '8': ntemp=8; break;
           case '9': ntemp=9; break;
         }
         acc = acc*10 + ntemp;
       } else
         break;
  }
  return acc * negativo;
}

int log10approx(int n)
{
   int nn, count;

   nn = n;
   count = 0;
   while (nn >= 10) {
     count++;
     nn = nn / 10;
   }
   return count;
}

void inttostr(int n, char *s)
{
  int pos = 0;
  int nn, digit, ncont, npos;
  char stemp;

  if (n == 0) {
     s[pos] = '0';
     return;
  }

  if (n < 0) {
     s[pos] = '-';
     pos++;
     nn = -n;
  } else
     nn = n;

  npos=pos;
  pos = log10approx(nn) + pos;

  if ((0+pos-1) > tamstr(s)) {
     for (ncont=0; ncont < tamstr(s); ncont++)
       s[ncont] = '*';
     return;
  }

  while (nn >= 1) {
     digit = nn % 10;
     nn = nn / 10;

     switch(digit) {
       case 0: stemp='0'; break;
       case 1: stemp='1'; break;
       case 2: stemp='2'; break;
       case 3: stemp='3'; break;
       case 4: stemp='4'; break;
       case 5: stemp='5'; break;
       case 6: stemp='6'; break;
       case 7: stemp='7'; break;
       case 8: stemp='8'; break;
       case 9: stemp='9'; break;
     }
     s[pos] = stemp;
     pos--;

     npos++;
  }
  s[npos]='\0';
}

int converte(char ch) {
  int ntemp;
  switch(ch) {
    case '0': ntemp=0; break;
    case '1': ntemp=1; break;
    case '2': ntemp=2; break;
    case '3': ntemp=3; break;
    case '4': ntemp=4; break;
    case '5': ntemp=5; break;
    case '6': ntemp=6; break;
    case '7': ntemp=7; break;
    case '8': ntemp=8; break;
    case '9': ntemp=9; break;
  }
  return ntemp;
}

float strtofloat(char *line)
{
  int i, j, state;
  float value, sign, integral, fractional, factor;
  int exponent, expsign;

  i = 0;
  sign = 1.0;

  if (line[i] == '-') {
       sign = -1.0;
       j = i + 1;
  } else if (line[i] == '+')
       j = i + 1;
  else
       j = i;

  integral = 0.0;
  fractional = 0.0;
  exponent = 0;
  state = 1;     /* se 1, entao nos estamos na frente do ponto decimal,
                    se 2, entao nos estamos atrás do ponto decimal, */
  factor = 0.1;
  expsign = 1;

  for (i=j; i < tamstr(line); i++) {
    if (state == 1) {
      if (line[i] == '.')
        state = 2;
      else
        integral = integral * 10.0 + converte(line[i]);

    } else if (state == 2) {
      if (line[i] == 'e' || line[i] == 'E')
        state = 3;
      else {
        fractional = fractional + converte(line[i]) * factor;
        factor = factor / 10.0;
      }
    } else {   /* state = 3 */
        if (line[i] == '-')
          expsign = -1;
        else if (line[i] == '+')
          expsign = 1;
        else
          exponent = exponent*10 + converte(line[i]);
    }
  }

  value = sign * (integral + fractional);
  if (expsign == -1) {
     for (i=1; i < exponent; i++)
       value = value / 10.0;
  } else {
     for (i=1; i < exponent; i++)
       value = value * 10.0;
  }
  return value;
}

void imprimestr(char *str)
{
 asm PUSHF            /* Save the direction flag */
 asm CLD              /* Set direction for increment (forward) */
 asm MOV SI,str       /* Place address into SI for LODSB */

strloop:
 asm LODSB            /* Get a character into the AL register */
 asm OR AL,AL         /* Have we found the 0 yet? */
 asm JZ fimstr        /* Yes, we are done with the string */
 asm MOV AH,14        /* Ask for write character function */
 asm XOR BH,BH        /* Write to page 0 */
 asm INT 10h          /* Write one character to the screen */
 asm JMP strloop

fimstr:
 asm POPF             /* Restore direction flag */
}

mstring somastr(int num,...)
{
 int ig,j,t;
 char str[510], soma[1020];
 va_list argptr;

 va_start(argptr,num);

 str[0]='\0';
 soma[0]='\0';

 j=0; t=0;
 for(;num;num--){
   atribstr(str, va_arg(argptr,char*));
   for(ig=j; ig < abs(j+tamstr(str)); ig++){
      soma[ig]=str[t];
      t++;
    }
   soma[ig]='\0';
   j=tamstr(soma);
   t=0;
 }
 va_end(argptr);

 return(soma);
}

mstring retDataHora(void)
{
int ndia = 0;
int nmes = 0;
int nano = 0;
int nhora = 0;
int nmin = 0;
int nseg = 0;
char sdia[255], smes[255], sano[255], 
shora[255], smin[255], sseg[255], sret[255];

  asm mov ah,2Ah
  asm int 21h

  asm mov ndia, dl
  asm mov nmes, dh
  asm mov nano, cx

  asm mov ah,2Ch
  asm int 21h

  asm mov nhora, ch
  asm mov nmin, cl
  asm mov nseg, dh

  inttostr(ndia, sdia);
  inttostr(nmes, smes);
  inttostr(nano, sano);

  inttostr(nhora, shora);
  inttostr(nmin, smin);
  inttostr(nseg, sseg);

  atribstr(sret,somastr(11,sdia,"/",smes,"/",sano," ",shora,":",smin,":",sseg));

return sret;
}

/*int main(int argc, char *argv[])*/
int main(void)
{ char *codigo;
 char stecla;

 imprimestr(retDataHora());
 imprimestr("\n");

 sair();
 return 0;
}

