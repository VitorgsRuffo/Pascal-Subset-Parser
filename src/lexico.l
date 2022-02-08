%option noyywrap

%{

typedef enum tokenType{
    eof,
    NEW_LINE,
    PROGRAM,
    VAR,
    PROCEDURE,
    FUNCTION,
    BEG,
    END,
    ARRAY,
    OF,
    IF,
    THEN,
    ELSE,
    WHILE,
    DO,
    OR,
    DIV,
    AND,
    NOT,
    SEMICOLON,
    DOT,
    COLON,
    COMMA,
    L_SQUARE_BRACKET,
    R_SQUARE_BRACKET,
    DOT_DOT,
    L_PAREN,
    R_PAREN,
    ASSIGN,
    EQUAL,
    NOT_EQUAL,
    LESS_THAN,
    LESS_EQUAL,
    GREATER_EQUAL,
    GREATER_THAN,
    PLUS,
    MINUS,
    TIMES,
    IDENTIFIER, 
    NUMBER
}tokenType; 

int line = 1;
int column = 1;
#define YY_USER_ACTION column += yyleng;
void printError(int line, int column, char* character);

%}

%x CURLY_B_COMMENT
%x PAREN_COMMENT


%%

(?i:program)            {return PROGRAM;}
(?i:var)                {return VAR;}
(?i:procedure)          {return PROCEDURE;}
(?i:function)           {return FUNCTION;}
(?i:begin)              {return BEG;}
(?i:end)                {return END;}
(?i:array)              {return ARRAY;}
(?i:of)                 {return OF;}
(?i:if)                 {return IF;}
(?i:then)               {return THEN;}
(?i:else)               {return ELSE;}
(?i:while)              {return WHILE;}
(?i:do)                 {return DO;}
(?i:or)                 {return OR;}
(?i:div)                {return DIV;}
(?i:and)                {return AND;}
(?i:not)                {return NOT;}

[;]                     {return SEMICOLON;}
[\.]                    {return DOT;}
[:]                     {return COLON;}
[,]                     {return COMMA;}
[[]                     {return L_SQUARE_BRACKET;}
[]]                     {return R_SQUARE_BRACKET;}
".."                    {return DOT_DOT;}
[(]                     {return L_PAREN;}
[)]                     {return R_PAREN;}
":="                    {return ASSIGN;}
[=]                     {return EQUAL;}
"<>"                    {return NOT_EQUAL;}
[<]                     {return LESS_THAN;}
"<="                    {return LESS_EQUAL;}
">="                    {return GREATER_EQUAL;}
[>]                     {return GREATER_THAN;}
[+]                     {return PLUS;}
[-]                     {return MINUS;}
[*]                     {return TIMES;}

[a-zA-Z_][a-zA-Z0-9_]*  {return IDENTIFIER;}
[0-9]+                  {return NUMBER;}


[{]            		     {BEGIN(CURLY_B_COMMENT);}
<CURLY_B_COMMENT>[^}\n]+ {}
<CURLY_B_COMMENT>\n   	 {line++; column = 1;}
<CURLY_B_COMMENT>[}] 	 {BEGIN(INITIAL);}

"(*"            		{BEGIN(PAREN_COMMENT);}
<PAREN_COMMENT>[^*\n]+  {}
<PAREN_COMMENT>\*[^)]   {}
<PAREN_COMMENT>\n   	{line++; column = 1;}
<PAREN_COMMENT>"*)" 	{BEGIN(INITIAL);}

[ ]+                    {}
[\n]                    {line++; column = 1; return NEW_LINE;}

.					    {printError(line, column-1, yytext); return -1;}

%%

void printError(int line, int column, char* character){
    printf("ERRO LEXICO. Linha: %d Coluna: %d -> %s", line, column, character);
}

char* getYYtext(){
    return yytext;
}