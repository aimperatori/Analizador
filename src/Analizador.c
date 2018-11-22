#define TKId 1 // 1
#define TKVoid 2 // 2
#define TKInt 3 // 3
#define TKFloat 4 // 4
#define TKVirgula 5 // 5
#define TKDoisPontos 6 // 6
#define TKAbreParenteses 7 // 7
#define TKFechaParenteses 8 // 8
#define TKAtrib 9 // 9
#define TKPontoEVirgula 10 // 10
#define TKAbreChaves 11 // 11
#define TKFechaChaves 12 // 12
#define TKSoma 13 // 13
#define TKDuploMais 14 // 14
#define TKProd 15 // 15
#define TKChar 16 // 16
#define TKMenos 17 // 17
#define TKDuploMenos 18 // 18
#define TKMenosIgual 19 // 19
#define TKDivisao 20 // 20
#define TKResto 21 // 21
#define TKMaisIgual 22 // 22
#define TKProdIgual 23 // 23
#define TKDivisaoIgual 24 // 24
#define TKMaior 25 // 25
#define TKMenor 26 // 26
#define TKWhile 27 // 27
#define TKFor 28 // 28
#define TKSwitch 29 // 29
#define TKCase 30 // 30
#define TKBreak 31 // 31
#define TKIf 32 // 32
#define TKReturn 33 // 33
#define TKDo 34 // 34
#define TKDefault 35 // 35
#define TKDouble 36 // 36
#define TKShort 37 // 37
#define TKLong 38 // 38
#define TKInteiro 39 // 39
#define TKMaiorIgual 40 // 40
#define TKMenorIgual 41 // 41
#define TKDiferente 42 // 42
#define TKIgual 43 // 43
#define TKAnd 44 // 44
#define TKOr 44 // 44
#define TKRestoIgual 46 // 46
#define TKInterogacao 47 // 47
#define TKXor 48 // XOR Para Bits
#define TKAndParaBits 49 // And Para Bits
#define TKOrParaBits 50 // Or para Bits
#define TKDeslocamentoEsquerda 51 // <<
#define TKDeslocamentoDireita 52 // >>
#define TKExpressao 53 // Expressao
#define TKNegacao 54 // !
#define TKContinue 55
#define TKElse 55
#define TKAuto 57
#define TKEnum 58
#define TKConst 59
#define TKExtern 60
#define TKGoto 61
#define TKRegister 62
#define TKSigned 63
#define TKSizeof 64
#define TKStatic 65
#define TKTypedef 66
#define TKUnsigned 66
#define TKVolatile 68
#define TKAsm 69
#define PARAMETRO 70
#define TKFlutuante 71

#define false 0
#define true 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int pos = 0;
int lin=1, col=1, posl, erro=false;
int tk, tipo_numero;
char exp1[200],lex[20];
char tk_name[50];
char lista[][30] = {"", "TKId ", "TKVoid ", "TKInt ",
		"TKFloat ", "TKVirgula ", "TKDoisPontos ", "TKAbreParenteses ",
		"TKFechaParenteses ", "TKAtrib ", "TKPontoEVirgula ", "TKAbreChaves ",
		"TKFechaChaves ", "TKSoma ", "TKDuploMais ", "TKProd ", "TKChar ",
		"TKMenos ", "TKDuploMenos ", "TKMenosIgual ", "TKDivisao ", "TKResto ",
		"TKMaisIgual ", "TKProdIgual ", "TKDivisaoIgual ", "TKMaior ",
		"TKMenor ", "TKWhile ", "TKFor ", "TKSwitch ", "TKCase ", "TKBreak ",
		"TKIf ", "TKReturn ", "TKDo ", "TKDefault ", "TKDouble ", "TKShort ",
		"TKLong ", "TKInteiro ", "TKMaiorIgual ", "TKMenorIgual ",
		"TKDiferente ", "TKIgual ", "TKAnd ", "TKOr ", "TKRestoIgual ",
		"TKInterogacao ", "TKXor ", "TKAndParaBits ", "TKOrParaBits ",
		"TKDeslocamentoEsquerda ", "TKDeslocamentoDireita ", "TKExpressao ",
		"TKNegacao ", "TKContinue ", "TKElse ", "TKAuto ", "TKEnum ",
		"TKConst ", "TKExtern ", "TKGoto ", "TKRegister ", "TKSigned ",
		"TKSizeof ", "TKStatic ", "TKTypedef ", "TKUnsigned ", "TKVolatile ",
		"TKAsm ", "PARAMETRO ", "TKFlutuante " };

char c;
FILE *in, *out;

//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> INICIO LEXICO <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

struct pal_res{char palavra[20]; int tk;};
struct pal_res lista_pal[]={
							{"void",TKVoid},
							{"int",TKInt},
							{"char",TKChar},
							{"float",TKFloat},
							{"double",TKDouble},
							{"short",TKShort},
							{"long",TKLong},
							{"break",TKBreak},
							{"case",TKCase},
							{"continue",TKContinue},
							{"default",TKDefault},
							{"do",TKDo},
							{"if",TKIf},
							{"else",TKElse},
							{"for",TKFor},
							{"return",TKReturn},
							{"switch",TKSwitch},
							{"while",TKWhile},
							{"auto", TKAuto},
							{"const", TKConst},
							{"enum", TKEnum},
							{"extern", TKExtern},
							{"goto", TKGoto},
							{"register", TKRegister},
							{"signed", TKSigned},
							{"sizeof", TKSizeof},
							{"static", TKStatic},
							{"typedef", TKTypedef},
							{"unsigned", TKUnsigned},
							{"volatile", TKVolatile},
							{"asm", TKAsm},
							{"fimtabela",TKId}
							};

int palavra_reservada(char lex[]) {
	int postab=0;
	while (strcmp("fimtabela",lista_pal[postab].palavra)!=0){
	   if (strcmp(lex,lista_pal[postab].palavra)==0)
		  return lista_pal[postab].tk;
	   postab++;
	}
	return TKId;
}

void proxC() {
	if (feof(in)) {
		c=-1;
//		printf("Chegou no fim de arquivo!\n");
	}

	// LE PROXIMO CARACTER DO ARQUIVO
	fread(&c, 1, 1, in);
//	printf("Leu caracter %c\n",c);
}

void getToken() {
	int estado=0,
		fim=0,
		posl=0,
		tipo_numero=0;

	// GRAVA DADOS LEXICOS NO ARQUIVO "Saida.lex"
	if(tk) fprintf(out, "%25s %15s %7d %8d\n", lista[tk],lex,lin,col-posl);

	while (!fim) {
//		printf("char= %c col= %d tk= %d\n",c,col,tk);
//		printf("lexico %s\n",lex);

		// VERIFICA SE c ESTA COM TK DE FIM DE ARQUIVO
		if(c==-1) {
			tk=-1;
			return;
		}

		lex[posl++]=c;
		switch(estado){
			case 0: if ((c>='a' && c<='z') || (c>='A' && c<='Z') || c=='_')
					{proxC();col++;estado=1;break;}
					if ((c>='0' && c<='9') || c=='.'){
						estado=2;col++;break;}
					if (c=='='){
						proxC();col++;
						if(c=='='){
							lex[posl++]='=';
							lex[posl]='\0';
							proxC();col++;
							tk=TKIgual;
							return;
						}else{
							lex[posl]='\0';
							tk=TKAtrib;
							return;}
					}
					if (c=='+'){
						proxC();col++;
						if (c=='+'){
							lex[posl++]='+';
							lex[posl]='\0';
							proxC();col++;
							tk=TKDuploMais;return;
						}else if (c=='='){
							lex[posl++]='=';
							lex[posl]='\0';
							proxC();col++;
							tk=TKMaisIgual;return;
						}else{
							lex[posl]='\0';
							tk=TKSoma;return;
						}
					}
					if (c=='-'){
						proxC();col++;
						if (c=='-') {
							lex[posl++]='-';
							lex[posl]='\0';
							proxC();col++;
							tk=TKDuploMenos;return;}
						else if(c=='='){
							lex[posl++]='=';
							lex[posl]='\0';
							proxC();col++;
							tk=TKMenosIgual;return;
						}else{
							lex[posl]='\0';
							tk=TKMenos;return;}
					}
					if (c=='&'){
						proxC();col++;
						if (c=='&'){
							lex[posl++]='&';
							lex[posl]='\0';
							proxC();col++;
							tk=TKAnd;return;}
						else{
							lex[posl]='\0';
							tk=TKAndParaBits;return;}
					}
					if (c=='|'){
						proxC();col++;
						if (c=='|'){
							lex[posl++]='|';
							lex[posl]='\0';
							proxC();col++;
							tk=TKOr;return;}
						else{
							lex[posl]='\0';
							tk=TKOrParaBits;return;}
					}
					if (c=='>'){
						proxC();col++;
						if(c=='=') {lex[posl++]='=';lex[posl]='\0';proxC();col++;tk=TKMaiorIgual;return;
						}else if(c=='>') {lex[posl++]='>';lex[posl]='\0';proxC();col++;tk=TKDeslocamentoDireita;return;}
						else {lex[posl]='\0';tk=TKMaior;return;}
					}
					if (c=='<'){
						proxC();col++;
						if(c=='='){lex[posl++]='=';lex[posl]='\0';proxC();col++;tk=TKMenorIgual;return;
						}else if(c=='<'){lex[posl++]='<';lex[posl]='\0';proxC();col++;tk=TKDeslocamentoEsquerda;return;
						}else{lex[posl]='\0';tk=TKMenor;return;}
					}
					if (c=='!'){
						proxC();col++;
						if(c=='='){lex[posl++]='=';lex[posl]='\0';proxC();col++;tk=TKDiferente;return;}
						else{lex[posl]='\0';tk=TKNegacao;return;}
					}
					if (c=='*'){
						proxC();col++;
						if(c=='='){lex[posl++]='=';lex[posl]='\0';proxC();col++;tk=TKProdIgual;return;
						}else{lex[posl]='\0';tk=TKProd;return;}
					}
					if (c=='/'){
						proxC();col++;
						if(c=='='){lex[posl++]='=';lex[posl]='\0';proxC();col++;tk=TKDivisaoIgual;return;}
						else{lex[posl]='\0';tk=TKDivisao;return;}
					}
					if (c=='%'){
						proxC();col++;
						if(c=='='){lex[posl]='\0';proxC();col++;tk=TKRestoIgual;return;
						}else{lex[posl]='\0';proxC();tk=TKResto;return;}
					}
					if (c=='('){lex[posl]='\0';proxC();col++;tk=TKAbreParenteses;return;}
					if (c==')'){lex[posl]='\0';proxC();col++;tk=TKFechaParenteses;return;}
					if (c=='{'){lex[posl]='\0';proxC();col++;tk=TKAbreChaves;return;}
					if (c=='}'){lex[posl]='\0';proxC();col++;tk=TKFechaChaves;return;}
					if (c==','){lex[posl]='\0';proxC();col++;tk=TKVirgula;return;}
					if (c==';'){lex[posl]='\0';proxC();col++;tk=TKPontoEVirgula;return;}
					if (c==':'){lex[posl]='\0';proxC();col++;tk=TKDoisPontos;return;}
					if (c=='?'){lex[posl]='\0';proxC();col++;tk=TKInterogacao;return;}
					if (c=='^'){lex[posl]='\0';proxC();col++;tk=TKXor;return;}
					if (c==-1) {lex[posl]='\0';proxC();tk=-1;return;}
					if (c==' ' || c=='\t' || c=='\r'){proxC();posl--;col++;break;}
					if (c=='\n') {proxC();col=0;posl--;lin++;break;}
					if (c=='\0') {tk=-1;return;}
					printf("Erro léxico: encontrou o caracter %c na posição %d",c,col);
					break;
			case 1: if ((c>='a' && c<='z') || (c>='A' && c<='Z') || c=='_' || (c>='0' && c<='9')) {proxC();col++;break;}
					lex[--posl]='\0';
					tk=palavra_reservada(lex);
					return;
			case 2: if(c>='0' && c<='9') {
						proxC();col++;break;
					}else if(c=='.') {
						 proxC();col++;
						 tipo_numero=1;
						 break;
					}
					lex[--posl]='\0';
					if(tipo_numero==1) tk=TKFlutuante; else tk=TKInteiro;
					return;
		}// switch
	}// while
}// função

//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> FIM LEXICO <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int G();
int E();
int DecGeral();
int DecGeral2();
int Dec1();
int Dec2();
int Declarator();
int CallFuncParam();
int CallFuncParam2();
int While();
int If();
int Else();
int For();
int EV();
int SwitchCase();
int Cases();
int BlocoCases();
int Case1();
int CharConst();
int Parametro();
int Parametro2();
int Parametro2Linha();
int BlocoComando();
int E();
int E1();
int E2();
int E3();
int E3Linha();
int E4();
int E4Linha();
int E5();
int E5Linha();
int E6();
int E6Linha();
int E7();
int E7Linha();
int E8();
int E8Linha();
int E9();
int E9Linha();
int E10();
int E10Linha();
int E11();
int E11Linha();
int E12();
int E12Linha();
int E13();
int E14();
int Return();

void F_Printf_Erro(int x){
	erro = true;
	char string[15];

	switch(x){
		case TKId: 				strcpy(string,"identificador"); break;
		case TKInt: 			strcpy(string,"identificador de tipo"); break;
		case TKIf: 				strcpy(string,"anteriormente um if"); break;
		case TKVirgula:			strcpy(string,"uma vírgula"); break;
		case TKDoisPontos:		strcpy(string,"dois pontos"); break;
		case TKAbreParenteses: 	strcpy(string,"abrir parenteses"); break;
		case TKFechaParenteses:	strcpy(string,"fechar parenteses"); break;
		case TKAtrib:			strcpy(string,"uma atribuição"); break;
		case TKPontoEVirgula:	strcpy(string,"um ponto e vírgula"); break;
		case TKAbreChaves:		strcpy(string,"abrir chaves"); break;
		case TKFechaChaves:		strcpy(string,"fechar chaves"); break;
		case TKCase:			strcpy(string,"um \"case\""); break;
		case TKInteiro:			strcpy(string,"um numero"); break;
		case TKFlutuante:		strcpy(string,"um numero"); break;
		case TKExpressao:		strcpy(string,"uma expressão"); break;
		case PARAMETRO:			strcpy(string,"um parametro"); break;

		default: x=0;
	}

	if(x) printf("Erro: esperava %s, linha %d coluna %d\n", string, lin, col-posl);
	else printf("Erro: não identificado linha %d coluna %d\n", lin, col-posl);
}

//Tipo -> void | short | int | long | float | double | char
int Tipo(){
	if(tk == TKVoid){// void
		getToken();
		return 1;
	}
	else if(tk == TKShort){// short
		getToken();
		return 1;
	}
	else if(tk == TKInt){// int
		getToken();
		return 1;
	}
	else if(tk == TKLong){// long
		getToken();
		return 1;
	}
	else if(tk == TKFloat){// float
		getToken();
		return 1;
	}
	else if(tk == TKDouble){// double
		getToken();
		return 1;
	}
	else if(tk == TKChar){// char
		getToken();
		return 1;
	}
	else{return 0;}
}

//Parametro -> Parametro2 | ?
int Parametro(){
	if (Parametro2()){
		return 1;
	}
	else {return 1;}
}

//Parametro2 -> Tipo id Parametro2Linha
int Parametro2(){
	if(Tipo()){
		if(tk == TKId){// id
			getToken();
			if (Parametro2Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{return 0;}
	}
	else{return 0;}
}

//Parametro2Linha -> , Parametro2 Parametro2Linha | ?
int Parametro2Linha(){
	if(tk == TKVirgula){// ,
		getToken();
		if (Parametro2()){
			if (Parametro2Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(PARAMETRO);return 0;}
	}
	else {return 1;}
}

//Return -> return EV ;
int Return(){
	if(tk == TKReturn){// return
		getToken();
		if (EV()){
			if(tk == TKPontoEVirgula){// ;
				getToken();
				return 1;
			}
			else{return 0;}
		}
		else{return 0;}
	}
	else{return 0;}
}

//DecGeral -> Tipo id DecGeral2
int DecGeral(){
	if(Tipo()){
		if(tk == TKId){// id
			getToken();
			if (DecGeral2()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKId);return 0;}
	}
	else{return 0;}
}

//DecGeral2 -> ( Parametro ) BlocoComando | Dec1
int DecGeral2(){
	if(tk == TKAbreParenteses){// (
		getToken();
		if (Parametro()){
			if(tk == TKFechaParenteses){// )
				getToken();
				if (BlocoComando()){
					return 1;
				}
				else{return 0;}
			}
			else{F_Printf_Erro(TKFechaParenteses);return 0;}
		}
		else{return 0;}
	}
	else if (Dec1()){
		return 1;
	}
	else{return 0;}
}

//Dec1 -> = E Dec2 | Dec2
int Dec1(){
	if(tk == TKAtrib){// =
		getToken();
		if (E()){
			if (Dec2()){
				return 1;
			}
			else{return 0;}
		}
		else{return 0;}
	}
	else if (Dec2()){
		return 1;
	}
	else{return 0;}
}

//Dec2 -> ; | , Declarator Dec2
int Dec2(){
	if(tk == TKPontoEVirgula){// ;
		getToken();
		return 1;
	}
	else if(tk == TKVirgula){// ,
		getToken();
		if (Declarator()){
			if (Dec2()){
				return 1;
			}
			else{return 0;}
		}
		else{return 0;}
	}
	else{F_Printf_Erro(TKPontoEVirgula);return 0;}
}

//Declarator -> id = E | id
int Declarator(){
	if(tk == TKId){// id
		getToken();
		if(tk == TKAtrib){// =
			getToken();
			if (E()){
				return 1;
			}
			else{F_Printf_Erro(TKExpressao);return 0;}
		}
		else{return 1;}
	}
	else{return 0;}
}

//CallFuncParam -> E CallFuncParam2 | ?
int CallFuncParam(){
	if(E()){
		if (CallFuncParam2()){
			return 1;
		}
		else{return 0;}
	}
	else {return 1;}
}

//CallFuncParam2 -> , E CallFuncParam2 | ?
int CallFuncParam2(){
	if(tk == TKVirgula){// ,
		getToken();
		if(E()){
			if (CallFuncParam2()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(PARAMETRO);return 0;}
	}
	else {return 1;}
}


//While -> while ( E ) { G }
int While(){
	if(tk == TKWhile){
		getToken();
		if (tk == TKAbreParenteses){
			getToken();
			if (E()){
				if (tk == TKFechaParenteses){
					getToken();
					if(BlocoComando()){
						return 1;
					}else{return 0;}
				}
				else{F_Printf_Erro(TKFechaParenteses);return 0;}
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKAbreParenteses);return 0;}
	}
	else{return 0;}
}

//DoWhile -> do { BlocoComando } while ( E ) ;
int DoWhile(){
	if(tk == TKDo){// do
		getToken();
		if(BlocoComando()){
			if(tk == TKWhile){// while
				getToken();
				if(tk == TKAbreParenteses){// (
					getToken();
					if (E()){
						if(tk == TKFechaParenteses){// )
							getToken();
							if(tk == TKPontoEVirgula){// ;
								getToken();
								return 1;
							}
							else{F_Printf_Erro(TKPontoEVirgula);return 0;}
						}
						else{F_Printf_Erro(TKFechaParenteses);return 0;}
					}
					else{return 0;}
				}
				else{F_Printf_Erro(TKAbreParenteses);return 0;}
			}
			else{F_Printf_Erro(TKWhile);return 0;}
		}
		else{return 0;}
	}
	else{return 0;}
}

//For -> for ( EV ; EV ; EV ) BlocoComando
int For(){
	if(tk == TKFor){// for
		getToken();
		if(tk == TKAbreParenteses){// (
			getToken();
			if (EV()){
				if(tk == TKPontoEVirgula){// ;
					getToken();
					if (EV()){
						if(tk == TKPontoEVirgula){// ;
							getToken();
							if (EV()){
								if(tk == TKFechaParenteses){// )
									getToken();
									if (BlocoComando()){
										return 1;
									}
									else{return 0;}
								}
								else{F_Printf_Erro(TKFechaParenteses);return 0;}
							}
							else{return 0;}
						}
						else{F_Printf_Erro(TKPontoEVirgula);return 0;}
					}
					else{return 0;}
				}
				else{F_Printf_Erro(TKPontoEVirgula);return 0;}
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKAbreParenteses);return 0;}
	}
	else{return 0;}
}

//EV -> E | ?
int EV(){
	if (E()){
		return 1;
	}
	else {return 1;}
}

//SwitchCase -> switch ( E ) Cases
int SwitchCase(){
	if(tk == TKSwitch){// switch
		getToken();
		if(tk == TKAbreParenteses){// (
			getToken();
			if (E()){
				if(tk == TKFechaParenteses){// )
					getToken();
					if (Cases()){
						return 1;
					}
					else{return 0;}
				}
				else{F_Printf_Erro(TKFechaParenteses);return 0;}
			}
			else{F_Printf_Erro(0);return 0;}
		}
		else{F_Printf_Erro(TKAbreParenteses);return 0;}
	}
	else{return 0;}
}

//Cases -> case CharConst : Case1 | { BlocoCases } | default : Case1 | ?
int Cases(){
	if(tk == TKCase){// case
		getToken();
		if (CharConst()){
			if(tk == TKDoisPontos){// :
				getToken();
				if (Case1()){
					return 1;
				}
				else{return 0;}
			}
			else{F_Printf_Erro(TKDoisPontos);return 0;}
		}
		else{return 0;}
	}
	else if(tk == TKAbreChaves){// {
		getToken();
		if (BlocoCases()){
			if(tk == TKFechaChaves){// }
				getToken();
				return 1;
			}
			else{F_Printf_Erro(TKFechaChaves);return 0;}
		}
		else{return 0;}
	}
	else if(tk == TKDefault){// default
		getToken();
		if(tk == TKDoisPontos){// :
			getToken();
			if (Case1()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKDoisPontos);return 0;}
	}
	else {return 1;}
}

//BlocoCases -> case CharConst : G BlocoCases | default : G | ?
int BlocoCases(){
	if(tk == TKCase){// case
		getToken();
		if (CharConst()){
			if(tk == TKDoisPontos){// :
				getToken();
				if (G()){
					if (BlocoCases()){
						return 1;
					}
					else{return 0;}
				}
				else{return 0;}
			}
			else{F_Printf_Erro(TKDoisPontos);return 0;}
		}
		else{return 0;}
	}
	else if(tk == TKDefault){// default
		getToken();
		if(tk == TKDoisPontos){// :
			getToken();
			if (G()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKDoisPontos);return 0;}
	}
	else {return 1;}
}

//Case1 -> If | For | Switch | DoWhile | While | E | ?
int Case1(){
	if (If()){
		return 1;
	}
	else if (For()){
		return 1;
	}
	else if (SwitchCase()){
		return 1;
	}
	else if (DoWhile()){
		return 1;
	}
	else if (While()){
		return 1;
	}
	else if (E()){
		if(tk==TKPontoEVirgula){
			getToken();
			return 1;
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else {return 1;}
}

//CharConst -> char | constante
int CharConst(){
	if(tk == TKChar){// char
		getToken();
		return 1;
	}
	else if(tk == TKInteiro){// constante
		getToken();
		return 1;
	}
	else{F_Printf_Erro(0);return 0;}
}

//If -> if ( E ) BlocoComando Else
int If(){
	if(tk == TKIf){// if
		getToken();
		if(tk == TKAbreParenteses){// (
			getToken();
			if (E()){
				if(tk == TKFechaParenteses){// )
					getToken();
					if (BlocoComando()){
						if (Else()){
							return 1;
						}
						else{return 0;}
					}
					else{return 0;}
				}
				else{F_Printf_Erro(TKFechaParenteses);return 0;}
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKAbreParenteses);return 0;}
	}
	else{return 0;}
}

//Else -> else If | else BlocoComando | ?
int Else(){
	if(tk == TKElse){// else
		getToken();
		if (If()){
			return 1;
		}else if (BlocoComando()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> INICIO EXPRESSÕES <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//E -> E1
int E(){
	if (E1()){
		return 1;
	}
	else{return 0;}
}

//E1 -> E2 = E1 | E2 += E1 | E2 -= E1 | E2 *= E1 | E2 /= E1 | E2 %= E1 | E2
int E1(){
	if(E2()){
		if(tk == TKAtrib){// =
			getToken();
			if (E1()){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKMaisIgual){// +=
			getToken();
			if (E1()){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		} else if(tk == TKMenosIgual){// -=
			getToken();
			if (E1()){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		} else if(tk == TKProdIgual){// *=
			getToken();
			if (E1()){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		} else if(tk == TKDivisaoIgual){// /=
			getToken();
			if (E1()){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKRestoIgual){// %=
			getToken();
			if (E1()){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else{return 1;}
	}
	else{return 0;}
}

//E2 -> E3 ? E1 : E1 | E3
int E2(){
	if(E3()){
		if(tk == TKInterogacao){// ?
			getToken();
			if (E1()){
				if(tk == TKDoisPontos){// :
					getToken();
					if (E1()){
						return 1;
					}
					else{F_Printf_Erro(TKExpressao);return 0;}
				}
				else{F_Printf_Erro(TKDoisPontos);return 0;}
			}
			else{F_Printf_Erro(TKExpressao);return 0;}
		}
		else{return 1;}
	}
	else if (E3()){
		return 1;
	}
	else{return 0;}
}

//E3 -> E4 E4Linha
int E3(){
	if(E4()){
		if (E3Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E3Linha -> || E4 E3Linha | ?
int E3Linha(){
	if(tk == TKOr){// ||
		getToken();
		if (E4()){
			if (E3Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E4 -> E5 E4Linha
int E4(){
	if(E5()){
		if (E4Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
	return 1;
}

//E4Linha -> && E5 E4Linha | ?
int E4Linha(){
	if(tk == TKAnd){// &&
		getToken();
		if (E5()){
			if (E4Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
	return 1;
}

//E5 -> E6 E5Linha
int E5(){
	if(E6()){
		if (E5Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E5Linha -> | E6 E5Linha | ?
int E5Linha(){
	if(tk == TKOrParaBits){// |
		getToken();
		if (E6()){
			if (E5Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E6 -> E7 E6Linha
int E6(){
	if(E7()){
		if (E6Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E6Linha -> ^ E7 E6Linha | ?
int E6Linha(){
	if(tk == TKXor){// ^
		getToken();
		if (E7()){
			if (E6Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E7 -> E8 E7Linha
int E7(){
	if(E8()){
		if (E7Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E7Linha -> & E8 E7Linha | ?
int E7Linha(){
	if(tk == TKAndParaBits){// &
		getToken();
		if (E8()){
			if (E7Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E8 -> E9 E8Linha
int E8(){
	if(E9()){
		if (E8Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E8Linha -> == E9 E8Linha | != E9 E8Linha | ?
int E8Linha(){
	if(tk == TKIgual){// ==
		getToken();
		if (E9()){
			if (E8Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDiferente){// !=
		getToken();
		if (E9()){
			if (E8Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E9 -> E10 E9Linha
int E9(){
	if(E10()){
		if (E9Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E9Linha -> < E10 E9Linha | <= E10 E9Linha | >= E10 E9Linha | > E10 E9Linha | ?
int E9Linha(){
	if(tk == TKMenor){// <
		getToken();
		if (E10()){
			if (E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMenorIgual){// <=
		getToken();
		if (E10()){
			if (E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMaiorIgual){// >=
		getToken();
		if (E10()){
			if (E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMaior){// >
		getToken();
		if (E10()){
			if (E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E10 -> E11 E10Linha
int E10(){
	if(E11()){
		if (E10Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E10Linha -> << E11 E10Linha | >> E11 E10Linha | ?
int E10Linha(){
	if(tk == TKDeslocamentoEsquerda){// <<
		getToken();
		if (E11()){
			if (E10Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDeslocamentoDireita){// >>
		getToken();
		if (E11()){
			if (E10Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E11 -> E12 E11Linha
int E11(){
	if(E12()){
		if (E11Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E11Linha -> + E12 E11Linha | - E12 E11Linha | ?
int E11Linha(){
	if(tk == TKSoma){// +
		getToken();
		if (E12()){
			if (E11Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMenos){// -
		getToken();
		if (E12()){
			if (E11Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E12 -> E13 E12Linha
int E12(){
	if(E13()){
		if (E12Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E12Linha -> * E13 E12Linha | / E13 E12Linha | % E13 E12Linha | ?
int E12Linha(){
	if(tk == TKProd){// *
		getToken();
		if (E13()){
			if (E12Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDivisao){// /
		getToken();
		if (E13()){
			if (E12Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKResto){// %
		getToken();
		if (E13()){
			if (E12Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E13 -> ++ E13 | -- E13 | ! E13 | E14
int E13(){
	if(tk == TKDuploMais){// ++
		getToken();
		if (E13()){
			return 1;
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDuploMenos){// --
		getToken();
		if (E13()){
			return 1;
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKNegacao){// !
		getToken();
		if (E13()){
			return 1;
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if (E14()){
		return 1;
	}
	else{return 0;}
}

//E14 -> id | id ++ | id -- | id ( CallFuncParam ) | inteiro | flutuante | ( E )
int E14(){
	if(tk == TKId){// id
		getToken();
		if(tk == TKDuploMais){// ++
			getToken();
			return 1;
		}else if(tk == TKDuploMenos){// --
			getToken();
			return 1;
		}else if(tk == TKAbreParenteses){// (
			getToken();
			if(CallFuncParam()){
				if(tk == TKFechaParenteses){// )
					getToken();
					return 1;
				}
				else{F_Printf_Erro(TKFechaParenteses);return 0;}
			}
			else{return 0;}
		}else{
			return 1;
		}
	}
	else if(tk == TKInteiro){// INTEIRO
		getToken();
		return 1;
	}
	else if(tk == TKFlutuante){// FLUTUANTE
		getToken();
		return 1;
	}
	else if(tk == TKAbreParenteses){// (
		getToken();
		if (E()){
			if(tk == TKFechaParenteses){// )
				getToken();
				return 1;
			}
			else{F_Printf_Erro(TKFechaParenteses);return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk==-1) return 0;
	else{return 0;}
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> FIM EXPRESSÕES <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//BlocoComando -> { G } | While | DoWhile | DecGeral | If | For | SwitchCase | break | E | ?
int BlocoComando(){
	if(tk == TKAbreChaves){// {
		getToken();
		if(G()){
			if(tk == TKFechaChaves){// }
				getToken();
				return 1;
			}
			else{F_Printf_Erro(TKFechaChaves);return 0;}
		}
		else{return 0;}
	}
	else if (While()){
		return 1;
	}
	else if (DoWhile()){
		return 1;
	}
	else if (DecGeral()){
		return 1;
	}
	else if (If()){
		return 1;
	}
	else if (For()){
		return 1;
	}
	else if (SwitchCase()){
		return 1;
	}
	else if(tk==TKBreak) {
		getToken();
		if(tk==TKPontoEVirgula){
			getToken();
			if (G()){
				return 1;
			}
			else{return 0;}
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else if (E()){
		if(tk==TKPontoEVirgula) {
			getToken();
			return 1;
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else{return 1;}
}

//G -> DecGeral G | While G | DoWhile G | For G | If G | SwitchCase G | break | E G | ?
int G(){
	if(DecGeral()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if(While()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if(DoWhile()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if(For()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if(If()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if (SwitchCase()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if(tk==TKBreak) {
		getToken();
		if(tk==TKPontoEVirgula){
			getToken();
			if (G()){
				return 1;
			}
			else{return 0;}
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else if(Return()){
		if (G()){
			return 1;
		}
		else{return 0;}
	}
	else if(E()){
		if(tk==TKPontoEVirgula) {
			getToken();
			if (G()){
				return 1;
			}
			else{return 0;}
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else{
		return 1;
	}
}

int main(int argc, char *argv[]){
	setbuf(stdout, NULL);

	in = fopen("entrada.cpp", "r");
	if(in == NULL){
		printf("\nArquivo nao pode ser aberto");
		exit(1);
	}

	// EXPORTASÃO DOS DADOS LEXICOS
	out = fopen("Saida.lex", "w");
	if(out == NULL) {
		printf("Arquivo não pode ser criado\n");
		exit(1);
	}
	//cria cabeçalho do arquivo de saída
	fprintf(out, "		   Token	   Lexema   Linha   Coluna\n");


	proxC();
	getToken();
	G();
	if (erro==true) printf("Erro no reconhecimento\n");
	else printf("Reconheceu OK!\n");

	system("pause");
}
