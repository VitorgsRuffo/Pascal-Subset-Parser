#include <stdio.h>
#include <stdlib.h>
#include "./lex.h"

int token;
int parsingLine = 1;
int thereIsError = 0;

void printSyntaxError(){
    thereIsError = 1; //syntax error occured... 
    printf("ERRO DE SINTAXE. Linha: %d -> \"%s\"", parsingLine, getYYtext());
}

int getNextToken() {
    token=yylex();
    if(token < 0) return 0;
    if(token == NEW_LINE){
        parsingLine++;
        //printf("\n\nLine %d\n\n", parsingLine);
        return getNextToken();
    } 
    return 1;
}

void eat(int t) {
    //printf("Eating... expected: %d, got: %d\n\n", t, token);
    if(thereIsError) return;
    if (token==t){
        if(!getNextToken())
            thereIsError = 1; //lexical error occured... 
    }else{ 
        printSyntaxError();
    }
}


void VarL();
void Variavel();
void OpExpComma();
void FatorPrime();
void Fator();
void TermoOps();
void TermoL();
void Termo();
void SignOr();
void ExpsL();
void Sign();
void Exps();
void ExpPrime();
void Exp();
void Opr();
void Opelse();
void ExpcommaPrime();
void Expcomma();
void OpParenExp();
void ComandoPrime();
void Comando();
void PfLPrime();
void Opvar();
void PfL();
void Pf();
void TipoLPrime();
void TipoL();
void Tipo();
void ComandoSemiPrime();
void ComandoSemi();
void SemiBSemi();
void Func();
void Proc();
void BlocoCodl();
void IdcommaPrime();
void Idcomma();
void BlocoVlPrime();
void BlocoVl();
void Bloco();


void Cons(){
    //printf("Cons()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NUMBER:
        case MINUS:
        case PLUS: Sign(); eat(NUMBER); break;
        default: 
            printSyntaxError(); 
    }
}

void VarL(){
    //printf("VarL()\n\n");
    if(thereIsError) return;
    switch(token) {
        case L_SQUARE_BRACKET: eat(L_SQUARE_BRACKET); Expcomma(); eat(R_SQUARE_BRACKET); VarL(); break;
        case R_SQUARE_BRACKET:
        case R_PAREN:
        case ASSIGN:
        case THEN:
        case DO:
        case END:
        case COLON:
        case TIMES:
        case DIV:
        case AND:
        case OR:
        case MINUS:
        case PLUS:
        case EQUAL:
        case NOT_EQUAL:
        case LESS_THAN:
        case LESS_EQUAL:
        case GREATER_EQUAL:
        case GREATER_THAN:
        case SEMICOLON: break;
        default: 
            printSyntaxError(); 
    }
}

void Variavel(){
    //printf("Variavel()\n\n");
    if(thereIsError) return;
    switch(token) {
        case IDENTIFIER: eat(IDENTIFIER); VarL(); break;
        default: 
            printSyntaxError(); 
    }
}

void OpExpComma(){
    //printf("OpExpComma()\n\n");
    if(thereIsError) return;
    switch(token) {
        case R_PAREN: break;
        case PLUS:
        case MINUS:
        case NUMBER:
        case NOT:
        case L_PAREN:
        case IDENTIFIER: Expcomma(); break;
        default: 
            printSyntaxError(); 
    }
}

void FatorPrime(){
    //printf("FatorPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case L_PAREN: eat(L_PAREN); OpExpComma(); eat(R_PAREN); break;
        case R_PAREN:
        case THEN:
        case DO:
        case TIMES:
        case DIV:
        case AND:
        case OR:
        case MINUS:
        case PLUS:
        case EQUAL:
        case NOT_EQUAL:
        case LESS_THAN:
        case LESS_EQUAL:
        case GREATER_EQUAL:
        case GREATER_THAN:
        case L_SQUARE_BRACKET:
        case R_SQUARE_BRACKET:
        case COMMA:
        case END:
        case SEMICOLON: VarL(); break;
        default: 
            printSyntaxError(); 
    }
}

void Fator(){
    //printf("Fator()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NOT: eat(NOT); Fator(); break;
        case NUMBER: eat(NUMBER); break;
        case L_PAREN: eat(L_PAREN); Exp(); eat(R_PAREN); break;
        case IDENTIFIER: eat(IDENTIFIER); FatorPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void TermoOps(){
    //printf("TermoOps()\n\n");
    if(thereIsError) return;
    switch(token) {
        case TIMES: eat(TIMES); break;
        case DIV: eat(DIV); break;
        case AND: eat(AND); break;
        default: 
            printSyntaxError(); 
    }
}

void TermoL(){
    //printf("TermoL()\n\n");
    if(thereIsError) return;
    switch(token) {
        case TIMES:
        case DIV:
        case AND: TermoOps(); Fator(); TermoL(); break;
        case OR:
        case MINUS:
        case PLUS:
        case EQUAL:
        case NOT_EQUAL:
        case LESS_THAN:
        case LESS_EQUAL:
        case GREATER_EQUAL:
        case GREATER_THAN:
        case DO:
        case THEN:
        case R_PAREN:
        case R_SQUARE_BRACKET:
        case COMMA:
        case END:
        case SEMICOLON: break;
        default: 
            printSyntaxError(); 
    }
}

void Termo(){
    //printf("Termo()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NUMBER:
        case NOT:
        case L_PAREN:
        case IDENTIFIER: Fator(); TermoL(); break;
        default: 
            printSyntaxError(); 
    }
}


void SignOr(){
    //printf("SignOr()\n\n");
    if(thereIsError) return;
    switch(token) {
        case OR: eat(OR); break;
        case MINUS: eat(MINUS); break;
        case PLUS: eat(PLUS); break; 
        default: 
            printSyntaxError(); 
    }
}

void ExpsL(){
    //printf("ExpsL()\n\n");
    if(thereIsError) return;
    switch(token) {
        case OR:
        case MINUS:
        case PLUS: SignOr(); Termo(); ExpsL(); break;
        case THEN:
        case DO:
        case EQUAL:
        case NOT_EQUAL:
        case LESS_THAN:
        case LESS_EQUAL:
        case GREATER_EQUAL:
        case GREATER_THAN:
        case R_PAREN:
        case R_SQUARE_BRACKET:
        case END:
        case COMMA:
        case SEMICOLON: break;
        default: 
            printSyntaxError(); 
    }
}

void Sign(){
    //printf("Sign()\n\n");
    if(thereIsError) return;
    switch(token) {
        case MINUS: eat(MINUS); break;
        case PLUS: eat(PLUS); break;
        case NUMBER:
        case NOT:
        case L_PAREN:
        case IDENTIFIER: break;
        default: 
            printSyntaxError(); 
    }
}

void Exps(){
    //printf("Exps()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NUMBER:
        case NOT:
        case MINUS:
        case PLUS:
        case L_PAREN:
        case IDENTIFIER: Sign(); Termo(); ExpsL(); break;
        default: 
            printSyntaxError(); 
    }
}

void ExpPrime(){
    //printf("ExpPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case THEN:
        case DO:
        case R_PAREN:
        case R_SQUARE_BRACKET:
        case COMMA:
        case END:
        case SEMICOLON:  break;
        case EQUAL: Opr(); Exps(); ExpPrime(); break;
        case NOT_EQUAL: Opr(); Exps(); ExpPrime(); break;
        case LESS_THAN: Opr(); Exps(); ExpPrime(); break;
        case LESS_EQUAL: Opr(); Exps(); ExpPrime(); break;
        case GREATER_EQUAL: Opr(); Exps(); ExpPrime(); break;
        case GREATER_THAN: Opr(); Exps(); ExpPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Exp(){
    //printf("Exp()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NOT:   
        case NUMBER:
        case MINUS:
        case PLUS:
        case L_PAREN:
        case IDENTIFIER: Exps(); ExpPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Opr(){
    //printf("Opr()\n\n");
    if(thereIsError) return;
    switch(token) {
        case EQUAL: eat(EQUAL); break;
        case NOT_EQUAL: eat(NOT_EQUAL); break;
        case LESS_THAN: eat(LESS_THAN); break;
        case LESS_EQUAL: eat(LESS_EQUAL); break;
        case GREATER_EQUAL: eat(GREATER_EQUAL); break;
        case GREATER_THAN: eat(GREATER_THAN); break;
        default: 
            printSyntaxError(); 
    }
}

void Opelse(){
    //printf("Opelse()\n\n");
    if(thereIsError) return;
    switch(token) {
        case END:
        case SEMICOLON:  break;
        case ELSE: eat(ELSE); eat(BEG); ComandoSemi(); eat(END); break;
        default: 
            printSyntaxError(); 
    }
}

void ExpcommaPrime(){
    //printf("ExpcommaPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case R_PAREN:
        case R_SQUARE_BRACKET: break;
        case COMMA: eat(COMMA); Exp(); ExpcommaPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Expcomma(){
    //printf("Expcomma()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NOT:
        case NUMBER:
        case MINUS:
        case PLUS:
        case L_PAREN:
        case IDENTIFIER: Exp(); ExpcommaPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void OpParenExp(){
    //printf("OpParenExp()\n\n");
    if(thereIsError) return;
    switch(token) {
        case L_PAREN: eat(L_PAREN); Expcomma(); eat(R_PAREN); break;
        case END:
        case SEMICOLON: break;
        default: 
            printSyntaxError(); 
    }
}

void ComandoPrime(){
    //printf("ComandoPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case ASSIGN:
        case L_SQUARE_BRACKET: VarL(); eat(ASSIGN); Exp(); break; 
        case L_PAREN:
        case END:
        case SEMICOLON: OpParenExp(); break;
        default: 
            printSyntaxError(); 
    }
}

void Comando(){
    //printf("Comando()\n\n");
    if(thereIsError) return;
    switch(token) {
        case END:   
        case SEMICOLON: break;
        case WHILE: eat(WHILE); Exp(); eat(DO); Comando(); break;
        case IF: eat(IF); Exp(); eat(THEN); eat(BEG); ComandoSemi(); eat(END); Opelse(); break;
        case BEG: eat(BEG); ComandoSemi(); eat(END); break;
        case IDENTIFIER: eat(IDENTIFIER); ComandoPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void PfLPrime(){
    //printf("PfLPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case R_PAREN: break;
        case SEMICOLON: eat(SEMICOLON); Opvar(); Idcomma(); eat(COLON); eat(IDENTIFIER); PfLPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Opvar(){
    //printf("Opvar()\n\n");
    if(thereIsError) return;
    switch(token) {
        case VAR: eat(VAR);
        case IDENTIFIER: break;
        default: 
            printSyntaxError(); 
    }
}


void PfL(){
    //printf("PfL()\n\n");
    if(thereIsError) return;
    switch(token) {
        case VAR: 
        case IDENTIFIER: Opvar(); Idcomma(); eat(COLON); eat(IDENTIFIER); PfLPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Pf(){
    //printf("Pf()\n\n");
    if(thereIsError) return;
    switch(token) {
        case COLON:
        case SEMICOLON: break;
        case L_PAREN: eat(L_PAREN); PfL(); eat(R_PAREN); break;
        default: 
            printSyntaxError(); 
    }
}

void TipoLPrime(){
    //printf("TipoLPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case R_SQUARE_BRACKET: break;
        case COMMA: eat(COMMA); Cons(); eat(DOT_DOT); Cons(); TipoLPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void TipoL(){
    //printf("TipoL()\n\n");
    if(thereIsError) return;
    switch(token) {
        case NUMBER:
        case MINUS:
        case PLUS: Cons(); eat(DOT_DOT); Cons(); TipoLPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Tipo(){
    //printf("Tipo()\n\n");
    if(thereIsError) return;
    switch(token) {
        case ARRAY: eat(ARRAY); eat(L_SQUARE_BRACKET); TipoL(); eat(R_SQUARE_BRACKET); eat(OF); Tipo(); break;
        case IDENTIFIER: eat(IDENTIFIER); break;
        default: 
            printSyntaxError(); 
    }
}

void ComandoSemiPrime(){
    //printf("ComandoSemiPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case END: break;
        case SEMICOLON: eat(SEMICOLON); Comando(); ComandoSemiPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void ComandoSemi(){
    //printf("ComandoSemi()\n\n");
    if(thereIsError) return;
    switch(token) {
        case WHILE:
        case IF:
        case END:
        case BEG:
        case SEMICOLON:
        case IDENTIFIER: Comando(); ComandoSemiPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void SemiBSemi(){
    //printf("SemiBSemi()\n\n");
    if(thereIsError) return;
    switch(token) {
        case SEMICOLON: eat(SEMICOLON); Bloco(); eat(SEMICOLON); break;
        default: 
            printSyntaxError(); 
    }
}

void Func(){
    //printf("Func()\n\n");
    if(thereIsError) return;
    switch(token) {
        case FUNCTION: eat(FUNCTION); eat(IDENTIFIER); Pf(); eat(COLON); eat(IDENTIFIER); break;
        default: 
            printSyntaxError(); 
    }
}

void Proc(){
    //printf("Proc()\n\n");
    if(thereIsError) return;
    switch(token) {
        case PROCEDURE: eat(PROCEDURE); eat(IDENTIFIER); Pf(); break;
        default: 
            printSyntaxError(); 
    }
}

void BlocoCodl(){
    //printf("BlocoCodl()\n\n");
    if(thereIsError) return;
    switch(token) {
        case PROCEDURE: Proc(); SemiBSemi(); BlocoCodl(); break;
        case FUNCTION: Func(); SemiBSemi(); BlocoCodl(); break;
        case BEG: break; 
        default: 
            printSyntaxError(); 
    }
}

void IdcommaPrime(){
    //printf("IdcommaPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case COMMA: eat(COMMA); eat(IDENTIFIER); IdcommaPrime(); break;
        case COLON: break; 
        default: 
            printSyntaxError(); 
    }
}

void Idcomma(){
    //printf("Idcomma()\n\n");
    if(thereIsError) return;
    switch(token) {
        case IDENTIFIER: eat(IDENTIFIER); IdcommaPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void BlocoVlPrime(){
    //printf("BlocoVlPrime()\n\n");
    if(thereIsError) return;
    switch(token) {
        case FUNCTION:
        case PROCEDURE:
        case BEG: break;
        case IDENTIFIER: Idcomma(); eat(COLON); Tipo(); eat(SEMICOLON); BlocoVlPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void BlocoVl(){
    //printf("BlocoVl()\n\n");
    if(thereIsError) return;
    switch(token) {
        case FUNCTION:
        case PROCEDURE:
        case BEG: break;
        case VAR: eat(VAR); Idcomma(); eat(COLON); Tipo(); eat(SEMICOLON); BlocoVlPrime(); break;
        default: 
            printSyntaxError(); 
    }
}

void Bloco(){
    //printf("Bloco()\n\n");
    if(thereIsError) return;
    switch(token) {
        case FUNCTION:
        case PROCEDURE:
        case VAR:
        case BEG: BlocoVl(); BlocoCodl(); eat(BEG); ComandoSemi(); eat(END); break;
        default: 
            printSyntaxError(); 
    }
}

void S(){
    //printf("S()\n\n");
    switch(token) {
        case PROGRAM: eat(PROGRAM); eat(IDENTIFIER); eat(SEMICOLON); Bloco(); eat(DOT); break;
        default: 
            printSyntaxError(); 
    }
}

void parse(){
    int result = getNextToken();
    if(!result) return; //lexical error occured...
    S();
    if(!thereIsError)
        printf("PROGRAMA CORRETO.");
}