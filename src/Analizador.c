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
FILE *in, *outLex, *outC3E;

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
		c = -1;
	}
	// LE PROXIMO CARACTER DO ARQUIVO
	fscanf(in, "%c", &c);
}

void getToken() {
	int estado=0,
		fim=0,
		posl=0,
		tipo_numero=0;

	// GRAVA DADOS LEXICOS NO ARQUIVO
	if(tk) fprintf(outLex, "%25s %15s %7d %8d\n", lista[tk],lex,lin,col-posl);

	while (!fim) {
		//printf("char= %c col= %d tk= %d\n",c,col,tk);
		//printf("lexico %s\n",lex);

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
						proxC();estado=2;col++;break;}
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
					printf("Erro lexico: encontrou o caracter %c na posicao %d",c,col);
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
}// funcao

//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> FIM LEXICO <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define MAX_COD 1000

int G(char Com_c[], char lbreak[]);
int E();
int DecGeral(char[]);
int DecGeral2();
int Dec1();
int Dec2();
int Declarator();
int CallFuncParam();
int CallFuncParam2();
int While(char Com_c[], char lbreak[]);
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
int Rel(char Rel_c[], char Rel_true[], char Rel_false[]);
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
int E14(char[], char[]);
int Return();
void geralabel(char label[]);
void geratemp(char temp[]);

int Com_Composto(char Comp_c[]);
int Com(char Com_c[], char lbreak[]);

void F_Printf_Erro(int x){
	erro = true;
	char string[30];

	switch(x){
		case TKId: 				strcpy(string,"identificador"); break;
		case TKInt: 			strcpy(string,"identificador de tipo"); break;
		case TKIf: 				strcpy(string,"anteriormente um if"); break;
		case TKVirgula:			strcpy(string,"uma virgula"); break;
		case TKDoisPontos:		strcpy(string,"dois pontos"); break;
		case TKAbreParenteses: 	strcpy(string,"abrir parenteses"); break;
		case TKFechaParenteses:	strcpy(string,"fechar parenteses"); break;
		case TKAtrib:			strcpy(string,"uma atribuicao"); break;
		case TKPontoEVirgula:	strcpy(string,"um ponto e virgula"); break;
		case TKAbreChaves:		strcpy(string,"abrir chaves"); break;
		case TKFechaChaves:		strcpy(string,"fechar chaves"); break;
		case TKCase:			strcpy(string,"um \"case\""); break;
		case TKInteiro:			strcpy(string,"um numero"); break;
		case TKFlutuante:		strcpy(string,"um numero"); break;
		case TKExpressao:		strcpy(string,"uma expressao"); break;
		case PARAMETRO:			strcpy(string,"um parametro"); break;

		default: x=0;
	}

	if(x) printf("Erro: esperava %s, linha %d coluna %d\n", string, lin, col-posl);
	else printf("Erro: nao identificado linha %d coluna %d\n", lin, col-posl);
}

void geralabel(char label[]){
	static int numlabel = 0;
	sprintf(label, "LB%03d", numlabel++);
}

void geratemp(char temp[]){
	static int numtemp = 0;
	sprintf(temp, "T%03d", numtemp++);
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
	else{return 1;}
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
	else{return 1;}
}

/*
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
*/

//DecGeral -> Tipo id DecGeral2
int DecGeral(char DecGeral2_C[MAX_COD]){
	if(Tipo()){
		if(tk == TKId){// id
			getToken();
			if (DecGeral2(DecGeral2_C)){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKId);return 0;}
	}
	else{return 0;}
}

//DecGeral2 -> ( Parametro ) BlocoComando | Dec1
int DecGeral2(char DecGeral2_C[MAX_COD]){
	if(tk == TKAbreParenteses){// (
		getToken();
		if (Parametro()){
			if(tk == TKFechaParenteses){// )
				getToken();
				if (BlocoComando(DecGeral2_C, "")){
					return 1;
				}
				else{return 0;}
			}
			else{F_Printf_Erro(TKFechaParenteses);return 0;}
		}
		else{return 0;}
	}
	else if (Dec1(DecGeral2_C)){
		return 1;
	}
	else{return 0;}
}

//Dec1 -> = E Dec2 | Dec2
int Dec1(char Dec1_C[MAX_COD]){
	if(tk == TKAtrib){// =
		getToken();
		if (E(Dec1_C)){
			if (Dec2(Dec1_C)){
				return 1;
			}
			else{return 0;}
		}
		else{return 0;}
	}
	else if (Dec2(Dec1_C)){
		return 1;
	}
	else{return 0;}
}

//Dec2 -> ; | , Declarator Dec2
int Dec2(char Dec2_C[MAX_COD]){
	if(tk == TKPontoEVirgula){// ;
		getToken();
		return 1;
	}
	else if(tk == TKVirgula){// ,
		getToken();
		if (Declarator(Dec2_C)){
			if (Dec2(Dec2_C)){
				return 1;
			}
			else{return 0;}
		}
		else{return 0;}
	}
	else{F_Printf_Erro(TKPontoEVirgula);return 0;}
}

//Declarator -> id = E | id
int Declarator(char Declarator_C[MAX_COD]){
	if(tk == TKId){// id
		getToken();
		if(tk == TKAtrib){// =
			getToken();
			if (E(Declarator_C)){
				return 1;
			}
			else{F_Printf_Erro(TKExpressao);return 0;}
		}
		else{return 1;}
	}
	else{return 0;}
}

/*
//CallFuncParam -> E CallFuncParam2 | ?
int CallFuncParam(){
	if(E()){
		if (CallFuncParam2()){
			return 1;
		}
		else{return 0;}
	}
	else{return 1;}
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
	else{return 1;}
}
*/

//While -> while ( E ) BlocoComando
int While(char while_c[], char lbreak[]){
	char Rel_c[MAX_COD],Rel_p[MAX_COD],Com_c[MAX_COD];
    char labelwhile[10],labeltrue[10],labelfim[10];

	if(tk == TKWhile){
		geralabel(labelwhile);
		geralabel(labeltrue);
		geralabel(labelfim);
		getToken();
		if (tk == TKAbreParenteses){
			getToken();
			if (Rel(Rel_c,labeltrue,labelfim)){
				if (tk == TKFechaParenteses){
					getToken();
					if(Com(Com_c, "")){
						sprintf(while_c,"%s:%s%s:\n%s\tgoto %s\n%s:\n",
                                		labelwhile,Rel_c,labeltrue,Com_c,labelwhile,labelfim);
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

/*
//DoWhile -> do BlocoComando while ( E ) ;
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
*/

//For -> for ( EV ; EV ; EV ) BlocoComando
int For(char for_c[], char lbreak[]){
	char Rel1_c[MAX_COD],Rel1_p[MAX_COD],Rel2_c[MAX_COD],Rel2_p[MAX_COD],Rel3_c[MAX_COD],Rel3_p[MAX_COD],Com_c[MAX_COD];
    char labelini[10],labeltrue[10],labelfim[10];

	if(tk == TKFor){// for
		geralabel(labelini);
		geralabel(labeltrue);
		geralabel(labelfim);

		getToken();
		if(tk == TKAbreParenteses){// (
			getToken();
			if (Rel(Rel1_c, "", "")){
				if(tk == TKPontoEVirgula){// ;
					getToken();
					if (Rel(Rel2_c, labeltrue, labelfim)){
						if(tk == TKPontoEVirgula){// ;
							getToken();
							if (Rel(Rel3_c, "", "")){
								if(tk == TKFechaParenteses){// )
									getToken();
									if (Com(Com_c, labelfim)){
										//gera codigo for
										sprintf(for_c,"%s%s:\n%s%s:\n%s%s\tgoto %s\n%s\n",
														Rel1_c,labelini,Rel2_c,labeltrue,Com_c,Rel3_c,labelini,labelfim);
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

/*
//EV -> E | ?
int EV(){
	if (E()){
		return 1;
	}
	else{return 1;}
}
*/

/*
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
	else{return 1;}
}
*/

//BlocoCases -> case CharConst : G BlocoCases | default : G | ?
int BlocoCases(char Cases_c[], char lbreak[]){
	if(tk == TKCase){// case
		getToken();
		if (CharConst()){
			if(tk == TKDoisPontos){// :
				getToken();
				if (G(Cases_c, "")){
					if (BlocoCases(Cases_c, "")){
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
			if (Cases_c, ""){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKDoisPontos);return 0;}
	}
	else{return 1;}
}

/*
//Case1 -> If | For | Switch | DoWhile | While | E | ?
int Case1(char Case_c[], char lbreak[]){
	if (If()){
		return 1;
	}
	else if (For()){
		return 1;
	}
	else if (SwitchCase()){
		return 1;
	}
	//else if (DoWhile()){
	//	return 1;
	//}
	else if (While(Case_c, lbreak)){
		return 1;
	}
	else if (E(Case_c)){
		if(tk==TKPontoEVirgula){
			getToken();
			return 1;
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else{return 1;}
}
*/

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

/*
//If -> if ( E ) BlocoComando Else
int If(){
	if(tk == TKIf){// if
		getToken();
		if(tk == TKAbreParenteses){// (
			getToken();
			if(E()){
				if(tk == TKFechaParenteses){// )
					getToken();
					if(BlocoComando()){
						if(Else()){
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
*/

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> INICIO EXPRESSOES <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int Rel(char Rel_c[MAX_COD], char Rel_true[MAX_COD], char Rel_false[MAX_COD]){
    char E1_c[MAX_COD],E2_c[MAX_COD],R_sc[MAX_COD],E1_p[MAX_COD],E2_p[MAX_COD],R_sp[MAX_COD];

	//todo mudar para E1
    if (E11(E1_p, E1_c)){
        char op[10];
        if (tk==TKMaior) strcpy(op,">");
        else if (tk==TKMenor) strcpy(op,"<");
        else if (tk==TKIgual) strcpy(op,"=");
        else if (tk==TKDiferente) strcpy(op,"<>");
        else if (tk==TKMaiorIgual) strcpy(op,">=");
        else if (tk==TKMenorIgual) strcpy(op,"<=");

        //if (tk==TKMaior||tk==TKMenor||tk==TKIgual||tk==TKDiferente||tk==TKMaiorIgual||tk==TKMenorIgual){
		switch (tk){
			case TKMaior:
			case TKMenor:
			case TKIgual:
			case TKDiferente:
			case TKMaiorIgual:
			case TKMenorIgual:
		
				getToken();
				//todo mudar para E1
				if (E11(E2_p,E2_c)){
					sprintf(Rel_c,"%s%s\tif %s %s %s goto %s\n\tgoto %s\n",
						E1_c,E2_c,E1_p,op,E2_p,Rel_true,Rel_false);
					return 1;
				}
				return 0;
			break;
        default:
            strcpy(Rel_c, E1_c);
            return 1;
			break;
        }
    }
    return 0;
}

//E -> E1
int E(char Com_c[MAX_COD]){
	char E_c[MAX_COD],E_p[MAX_COD];

	//todo: chamar E1
	if(E1(E_p, E_c)){
		sprintf(Com_c, "%s%s", Com_c,E_c);
		return 1;
	}
	else{return 0;}
}

//E1 -> E2 = E1 | E2 += E1 | E2 -= E1 | E2 *= E1 | E2 /= E1 | E2 %= E1 | E2
int E1(char E1_p[MAX_COD],char E1_c[MAX_COD]){
	char A1_p[MAX_COD],A1_c[MAX_COD];

	//todo mudar para E2
	if(E11(E1_p, E1_c)){
		if(tk == TKAtrib){// =
			getToken();
			if(E1(A1_p, A1_c)){
				sprintf(E1_c,"%s\t%s=%s\n",A1_c,E1_p,A1_p);
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKMaisIgual){// +=
			getToken();
			if(E1(A1_p, A1_c)){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKMenosIgual){// -=
			getToken();
			if(E1(A1_p, A1_c)){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKProdIgual){// *=
			getToken();
			if(E1(A1_p, A1_c)){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKDivisaoIgual){// /=
			getToken();
			if(E1(A1_p, A1_c)){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else if(tk == TKRestoIgual){// %=
			getToken();
			if(E1(A1_p, A1_c)){
				return 1;
			}else{F_Printf_Erro(TKExpressao);return 0;}
		}else{return 1;}
	}
	else{return 0;}
}

/*
//E2 -> E3 ? E1 : E1 | E3
int E2(){
	if(E3()){
		if(tk == TKInterogacao){// ?
			getToken();
			if(E1()){
				if(tk == TKDoisPontos){// :
					getToken();
					if(E1()){
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
	else if(E3()){
		return 1;
	}
	else{return 0;}
}

//E3 -> E4 E4Linha
int E3(){
	if(E4()){
		if(E3Linha()){
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
		if(E4()){
			if(E3Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{return 1;}
}

//E4 -> E5 {Bh=num} E4Linha
int E4(){
	if(E5()){
		// acao semantica
		if(E4Linha()){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
	//return 1;
}

//E4Linha -> && E5 {Nh1=Bh&&num} E4Linha | ? {Bs=Bh}
int E4Linha(){
	if(tk == TKAnd){// &&
		getToken();
		if(E5()){
			//acao semantica
			if(E4Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{
		//acao semantica
		return 1;
	}
}

//E5 -> E6 E5Linha
int E5(){
	if(E6()){
		if(E5Linha()){
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
		if(E6()){
			if(E5Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{return 1;}
}

//E6 -> E7 E6Linha
int E6(){
	if(E7()){
		if(E6Linha()){
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
		if(E7()){
			if(E6Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{return 1;}
}

//E7 -> E8 E7Linha
int E7(){
	if(E8()){
		if(E7Linha()){
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
		if(E8()){
			if(E7Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{return 1;}
}

//E8 -> E9 E8Linha
int E8(){
	if(E9()){
		if(E8Linha()){
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
		if(E9()){
			if(E8Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDiferente){// !=
		getToken();
		if(E9()){
			if(E8Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{return 1;}
}

//E9 -> E10 E9Linha
int E9(char E9_p[MAX_COD],char E9_c[MAX_COD]){

	char E1_c[MAX_COD],E2_c[MAX_COD],R_sc[MAX_COD],E1_p[MAX_COD],E2_p[MAX_COD],R_sp[MAX_COD];

	if(E10(E9_p, E9_c)){
		if(E9Linha(E9_p, E9_c)){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E9Linha -> < E10 E9Linha | <= E10 E9Linha | >= E10 E9Linha | > E10 E9Linha | ?
int E9Linha(char Rel_p[MAX_COD],char Rel_c[MAX_COD]){
	if(tk == TKMenor){// <
		getToken();
		if(E10()){
			if(E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMenorIgual){// <=
		getToken();
		if(E10()){
			if(E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMaiorIgual){// >=
		getToken();
		if(E10()){
			if(E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMaior){// >
		getToken();
		if(E10()){
			if(E9Linha()){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else{return 1;}
}
*/

//E10 -> E11 E10Linha
int E10(char E10_p[MAX_COD], char E10_c[MAX_COD]){
	if(E11(E10_p, E10_c)){
		if(E10Linha(E10_p, E10_c)){
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E10Linha -> << E11 E10Linha | >> E11 E10Linha | ?
int E10Linha(char E10L_p[MAX_COD], char E10L_c[MAX_COD]){
	if(tk == TKDeslocamentoEsquerda){// <<
		getToken();
		if(E11(E10L_p, E10L_c)){
			if(E10Linha(E10L_p, E10L_c)){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDeslocamentoDireita){// >>
		getToken();
		if(E11(E10L_p, E10L_c)){
			if(E10Linha(E10L_p, E10L_c)){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else {return 1;}
}

//E11 -> E12 E11Linha
int E11(char E11_p[MAX_COD], char E11_c[MAX_COD]){

	char E12_p[MAX_COD],E12_c[MAX_COD],E11L_hp[MAX_COD],E11L_sp[MAX_COD],E11L_hc[MAX_COD],E11L_sc[MAX_COD];
	if(E12(E12_p, E12_c)){
		strcpy(E11L_hc,E12_c);
        strcpy(E11L_hp,E12_p);
		if(E11Linha(E11L_hp, E11L_sp, E11L_hc, E11L_sc)){
			strcpy(E11_c,E11L_sc);
            strcpy(E11_p,E11L_sp);
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E11Linha -> + E12 E11Linha | - E12 E11Linha | ?
int E11Linha(char E11L_hp[MAX_COD], char E11L_sp[MAX_COD], char E11L_hc[MAX_COD], char E11L_sc[MAX_COD]){

	char E12_c[MAX_COD], E11L1_hc[10000], E11L1_sc[MAX_COD], E12_p[MAX_COD], E11L1_hp[MAX_COD], E11L1_sp[MAX_COD];
	if(tk == TKSoma){// +
		getToken();
		if(E12(E12_p, E12_c)){

			geratemp(E11L1_hp);
            sprintf(E11L1_hc,"%s%s\t%s=%s+%s\n", E11L_hc, E12_c, E11L1_hp, E11L_hp, E12_p);

			if(E11Linha(E11L1_hp, E11L1_sp, E11L1_hc, E11L1_sc)){
				strcpy(E11L_sp, E11L1_sp);
                strcpy(E11L_sc, E11L1_sc);
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKMenos){// -
		getToken();
		if(E12(E12_p, E12_c)){
			geratemp(E11L1_hp);
            sprintf(E11L1_hc,"%s%s\t%s=%s-%s\n", E11L_hc, E12_c, E11L1_hp, E11L_hp, E12_p);
			if(E11Linha(E11L1_hp, E11L1_sp, E11L1_hc, E11L1_sc)){
				strcpy(E11L_sp, E11L1_sp);
                strcpy(E11L_sc, E11L1_sc);
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	strcpy(E11L_sp,E11L_hp);
    strcpy(E11L_sc,E11L_hc);
	return 1;
}

//E12 -> E13 E12Linha
int E12(char E12_p[MAX_COD], char E12_c[MAX_COD]){

	char E13_c[MAX_COD],E13_p[MAX_COD],E12L_hp[MAX_COD],E12L_sp[MAX_COD],E12L_hc[MAX_COD],E12L_sc[MAX_COD];

	if(E13(E13_p, E13_c)){
		strcpy(E12L_hc,E13_c);
        strcpy(E12L_hp,E13_p);

		if(E12Linha(E12L_hp, E12L_sp, E12L_hc, E12L_sc)){
			strcpy(E12_c,E12L_sc);
            strcpy(E12_p,E12L_sp);
			return 1;
		}
		else{return 0;}
	}
	else{return 0;}
}

//E12Linha -> * E13 E12Linha | / E13 E12Linha | % E13 E12Linha | ?
int E12Linha(char E12L_hp[MAX_COD], char E12L_sp[MAX_COD], char E12L_hc[MAX_COD],char E12L_sc[MAX_COD]){
	char E13_p[MAX_COD], E13_c[MAX_COD],E12L1_hc[10000],E12L1_sc[MAX_COD],E12L1_hp[MAX_COD],E12L1_sp[MAX_COD];

	if(tk == TKProd){// *
		getToken();
		if(E13(E13_p, E13_c)){
			
			geratemp(E12L1_hp);
            sprintf(E12L1_hc,"%s%s\t%s=%s*%s\n",E12L_hc,E13_c,E12L1_hp,E12L_hp,E13_p);

			if(E12Linha(E12L1_hp, E12L1_sp, E12L1_hc, E12L1_sc)){
				strcpy(E12L_sp,E12L1_sp);
                strcpy(E12L_sc,E12L1_sc);
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDivisao){// /
		getToken();
		if(E13(E13_p, E13_c)){
			
			geratemp(E12L1_hp);
            sprintf(E12L1_hc,"%s%s\t%s=%s/%s\n",E12L_hc,E13_c,E12L1_hp,E12L_hp,E13_p);

			if(E12Linha(E12L1_hp, E12L1_sp, E12L1_hc, E12L1_sc)){
				strcpy(E12L_sp,E12L1_sp);
                strcpy(E12L_sc,E12L1_sc);
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKResto){// %
		getToken();
		if(E13(E13_p, E13_c)){
			
			geratemp(E12L1_hp);
            sprintf(E12L1_hc,"%s%s\t%s=%s%%%s\n",E12L_hc,E13_c,E12L1_hp,E12L_hp,E13_p);

			if(E12Linha(E12L1_hp, E12L1_sp, E12L1_hc, E12L1_sc)){
				strcpy(E12L_sp,E12L1_sp);
                strcpy(E12L_sc,E12L1_sc);
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	
	strcpy(E12L_sp,E12L_hp);
    strcpy(E12L_sc,E12L_hc);
	return 1;
}

//E13 -> ++ E13 | -- E13 | ! E13 | E14
int E13(char E13_p[MAX_COD], char E13_c[MAX_COD]){
	if(tk == TKDuploMais){// ++
		getToken();
		if(E13(E13_p, E13_c)){
			return 1;
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKDuploMenos){// --
		getToken();
		if(E13(E13_p, E13_c)){
			return 1;
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk == TKNegacao){// !
		getToken();
		if(E13(E13_p, E13_c)){
			return 1;
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(E14(E13_p, E13_c)){
		return 1;
	}
	else{return 0;}
}

//E14 -> id | id ++ | id -- | id ( CallFuncParam ) | inteiro | flutuante | ( E )
int E14(char E14_p[MAX_COD], char E14_c[MAX_COD]){
	if(tk == TKId){// id
		//strcpy(E14_c, "");
        strcpy(E14_p, lex);
		sprintf(E14_c,"\t%s\n", E14_p);
		getToken();
		if(tk == TKDuploMais){// ++
			getToken();
			return 1;
		}else if(tk == TKDuploMenos){// --
			getToken();
			return 1;
		}else if(tk == TKAbreParenteses){// (
			getToken();
			/*
			if(CallFuncParam()){
				if(tk == TKFechaParenteses){// )
					getToken();
					return 1;
				}
				else{F_Printf_Erro(TKFechaParenteses);return 0;}
			}
			else{return 0;}*/
		}else{
			return 1;
		}
	}
	else if(tk == TKInteiro){// INTEIRO
		geratemp(E14_p);
        sprintf(E14_c,"\t%s = %s\n",E14_p,lex);

		getToken();
		return 1;
	}
	else if(tk == TKFlutuante){// FLUTUANTE
		geratemp(E14_p);
        sprintf(E14_c,"\t%s = %s\n",E14_p,lex);

		getToken();
		return 1;
	}
	else if(tk == TKAbreParenteses){// (
		char E14_c[MAX_COD],E14_p[MAX_COD];
		getToken();
		//todo: mudar pro E1
		if (E11(E14_p, E14_c)){
			if(tk == TKFechaParenteses){// )
				getToken();
				strcpy(E14_c,E14_c);
                strcpy(E14_p,E14_p);
				return 1;
			}
			else{F_Printf_Erro(TKFechaParenteses);return 0;}
		}
		else{F_Printf_Erro(TKExpressao);return 0;}
	}
	else if(tk==-1){return 0;}
	else{return 0;}
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! >>>>> FIM EXPRESSOES <<<<< !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//BlocoComando -> { G } | While | DoWhile | DecGeral | If | For | SwitchCase | break | E | ?
int BlocoComando(char Com_C[], char lbreak[]){
	if(tk == TKAbreChaves){// {
		getToken();
		if(G(Com_C, lbreak)){
			if(tk == TKFechaChaves){// }
				getToken();
				return 1;
			}
			else{F_Printf_Erro(TKFechaChaves);return 0;}
		}
		else{return 0;}
	}
	else if(While(Com_C, lbreak)){
		return 1;
	}
	//else if(DoWhile()){
	//	return 1;
	//}
	else if(DecGeral(Com_C)){
		return 1;
	}
	// else if(If()){
	// 	return 1;
	// }
	// else if(For()){
	// 	return 1;
	// //}
	// else if(SwitchCase()){
	// 	return 1;
	// }
	else if(tk==TKBreak) {
		getToken();
		if(tk==TKPontoEVirgula){
			getToken();
			if(G(Com_C, "")){
				return 1;
			}
			else{return 0;}
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else if(E(Com_C)){
		if(tk==TKPontoEVirgula) {
			getToken();
			return 1;
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else{return 1;}
}

//G -> DecGeral G | While G | DoWhile G | For G | If G | SwitchCase G | break | E G | ?
int G(char G_c[], char lbreak[]){
	if(DecGeral(G_c)){
		if(G(G_c, "")){
			return 1;
		}
		else{return 0;}
	}
	else if(While(G_c, lbreak)){
		if(G(G_c, "")){
			return 1;
		}
		else{return 0;}
	}
	//else if(DoWhile()){
	//	if(G(G_c, "")){
	//		return 1;
	//	}
	//	else{return 0;}
	//}
	// else if(For()){
	// 	if(G(G_c, "")){
	// 		return 1;
	// 	}
	// 	else{return 0;}
	// }
	// else if(If()){
	// 	if(G(G_c, "")){
	// 		return 1;
	// 	}
	// 	else{return 0;}
	// }
	// else if(SwitchCase()){
	// 	if(G(G_c, "")){
	// 		return 1;
	// 	}
	// 	else{return 0;}
	// }
	else if(tk==TKBreak) {
		getToken();
		if(tk==TKPontoEVirgula){
			getToken();
			if(G(G_c, "")){
				return 1;
			}
			else{return 0;}
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	// else if(Return()){
	// 	if(G(G_c, "")){
	// 		return 1;
	// 	}
	// 	else{return 0;}
	// }
	else if(E(G_c)){
		if(tk==TKPontoEVirgula) {
			getToken();
			if(G(G_c, "")){
				return 1;
			}
			else{return 0;}
		}else{F_Printf_Erro(TKPontoEVirgula);return 0;}
	}
	else{return 1;}
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! NOVO COMANDO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

int Com_Composto(char Comp_c[]){
    char Com_C[MAX_COD];

	if(tk==TKAbreChaves){
		getToken();
		strcpy(Comp_c,"");
		while (tk!=TKFechaChaves){
			if(!Com(Com_C, "")) return 0;
			strcat(Comp_c,Com_C);
		}
		getToken();
		return 1;
	}
	else{return 0;}
}

int Com(char Com_c[], char lbreak[]) {
    /*if (If(Com_c, lbreak)){
		if(Com(Com_c, "")){
			return 1;
		}
		else{return 0;}
	}
	else*/ 
	if(DecGeral(Com_c)){
		if(G(Com_c, "")){
			return 1;
		}
		else{return 0;}
	}
	else if(While(Com_c, lbreak)){
		if(Com(Com_c, "")){
			return 1;
		}
		else{return 0;}
	}
	else if(For(Com_c, lbreak)){
		if(Com(Com_c, "")){
			return 1;
		}
		else{return 0;}
	}
	//todo mudar para E1
	else if(E(Com_c)){
		if(tk==TKPontoEVirgula){
			getToken();
			if(Com(Com_c, "")){
				return 1;
			}
			else{return 0;}
		}
		else{F_Printf_Erro(TKPontoEVirgula);}
	}
	else if(Com_Composto(Com_c)){
		if(Com(Com_c, "")){
			return 1;
		}
		else{return 0;}
	}
    /*
    else if(token==TK_Break){
        if(lbreak[0]=='\0'){printf("Break fora de iteração"); return 0;}
        sprintf("%s", lbreak); //todo ver como fazer
    }
    else if (tk==TK_id) return Com_Exp(Com_c);
    
    else if (tk==TK_pv){
        token=le_token(); // comando vazio
        strcpy(Com_c,"");
        return 1;
    }
	*/
    else return 1;
}

int main(int argc, char *argv[]){
	char Com_C[MAX_COD];

	//IMPORTACAO ARQUIVO FONTE
	if((in = fopen("entrada.cpp", "r")) == NULL){
		printf("Arquivo nao pode ser aberto!\n");
		//exit(1);
	}

	// EXPORTACAO DOS DADOS LEXICOS
	if((outLex = fopen("Saida.lex", "w")) == NULL) {
		printf("Arquivo nao pode ser criado\n");
		exit(1);
	}
	//cria cabecalho do arquivo de saida
	fprintf(outLex, "		   Token	   Lexema   Linha   Coluna\n");

	// EXPORTACAO DO CODIGO C3E
	if ((outC3E = fopen("saida.kvmp", "wt"))==NULL){
        printf("Erro na abertura do arquivo de saida");
        exit(0);
    }

	//INICIA ANALISE DO ARQUIVO
	proxC();
	getToken();
	
	if(Com(Com_C, "")){
		fprintf(outC3E, "%s", Com_C);
		printf("%s", Com_C);
	}else{
		printf("Erro no comando!!!\n");
	}

	if(erro) printf("Erro no reconhecimento\n");
	else 	 printf("Reconheceu OK!\n");
	

	fclose(in);
	fclose(outLex);
	fclose(outC3E);
}
