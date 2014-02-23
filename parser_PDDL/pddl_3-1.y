/* Mini Calculator */
/* pddl_3-1.y */

%{
#include "heading.h"
int yyerror(char *s);
int yylex(void);
%}

%union{
  int		int_val;
  string*	op_val;
}

%start	input 

%token	<int_val>	INTEGER_LITERAL
%type	<int_val>	exp
%left	PLUS
%left	MULT

%token L_P
%token R_P
%token Q_M
%token EQ
%token N_L
%token TAB
%token MINUS
%token SLASH
%token STAR
%token PLUS
%token GT
%token LT
%token GOE
%token LOE
%token UNSC
%token DOT
%token LETTER
%token DIGIT
%token DEFINE
%token DOMAIN
%token REQUIREMENTS
%token TYPES
%token CONSTANTS
%token PREDICATES
%token FUNCTIONS
%token NUMBER
%token CONSTRAINTS
%token OBJECT
%token EITHER
%token ACTION
%token PARAMETERS
%token PRECONDITION
%token EFFECT
%token AND
%token FORALL
%token PREFERENCE
%token OR
%token NOT
%token IMPLY
%token EXISTS
%token WHEN
%token ASSIGN
%token UNDEFINED
%token SCALE_UP
%token SCALE_DOWN
%token INCREASE
%token DECREASE
%token DURATIVE_ACTION
%token DURATION
%token CONDITION
%token AT
%token OVER
%token START
%token END
%token ALL
%token Q_M_DURATION
%token DERIVED
%token PROBLEM
%token DD_DOMAIN
%token OBJECTS
%token INIT
%token GOAL
%token END
%token ALWAYS
%token SOMETIME
%token WITHIN
%token AT_MOST_ONCE
%token SOMETIME_AFTER
%token SOMETIME_BEFORE
%token ALWAYS_WITHIN
%token HOLD_DURING
%token HOLD_AFTER
%token METRIC
%token MINIMIZE
%token MAXIMIZE
%token TOTAL_TIME
%token IS_VIOLATED
%token LENGTH
%token SERIAL
%token PARALLEL

%%

/* completer ici */
input:
		/* empty */
		| exp	{ cout << "Result: " << $1 << endl; }
		;

exp:
		INTEGER_LITERAL	{ $$ = $1; }
		| exp PLUS exp	{ $$ = $1 + $3; }
		| exp MULT exp	{ $$ = $1 * $3; }
		;
		
/***************************************************/
/************** Domain Description *****************/
/***************************************************/		

/* <domain> */

domain:
		L_P DEFINE L_P DOMAIN name R_P option_require-def option_types-def option_constants-def option_predicates-def option_functions-def option_constraints list_structure-def R_P
		;
		
option_require-def:
		/* empty */
		| require-def
		;
		
option_types-def:
		/* empty */
		| types-def
		;
		
option_constants-def:
		/* empty */
		| constants-def
		;

option_predicates-def:
		/* empty */
		| predicates-def
		;
		
option_functions-def:
		/* empty */
		| functions-def
		;
		
option_constraints:
		/* empty */
		| contraints
		;
		
list_structure-def:
		/* empty */
		| structure-def list_structure-def
		;

/* <require-def> */

require-def:
		L_P REQUIREMENTS nvList_require-key R_P
		;
		
nvList_require-key:
		require-key list_require-key
		;
		
list_require-key:
		/* empty */
		| require-key list_require_key
		;
		
/* <require-key> */

require-key: /* section 1.3 */
		/* empty */
		;
		
/* <types-def> */
types-def:
		L_P TYPES typed-list L_P x R_P R_P //fn
		;
		
/* <contants-def> */

constantes-def:
		L_P CONSTANTS typed-list L_P name R_P R_P //fn
		;

/* <predicates-def> */

predicates-def:
		L_P PREDICATES nvList_atomic-formula-skeleton R_P
		;

nvList_atomic-formula-skeleton:
		atomic-formula-skeleton list_atomic-formula-skeleton
		;

list_atomic-formula-skeleton:
		/* empty */		
		| atomic-formula-skeleton list_atomic-formula-skeleton
		;
		
/* <atomic formula skeleton> */
		
atomic-formula-skeleton:
		L_P predicate typed-list L_P variable R_P R_P //fn
		;
		
/* <predicate> */

predicate:
		name
		;
		
/* <variable> */

variable:
		Q_M name
		;

/* <atomic function skeleton> */

atomic-function-skeleton:
		L_P function-symbol typed-list L_P variable R_P R_P //fn
		;
		
/* <function-symbol> */

function-symbol:
		name
		;
		
/* <function-def> */

function-def:
		L_P FUNCTIONS function-typed-list L_P atomic-function_skeleton R_P R_P
		;
		
/* <function typed list (x)> */

function-typed-list:
		/* empty */
		| /* x+ */
		| /* x+ */ MINUS type typed-list L_P /* x */ R_P //fn
		;

/* <function type> */

function-type:
		NUMBER
		| type
		;

/* <constraints> */

constraints:
		L_P CONSTRAINTS con-GD R_P
		;
		
/* <structure-def> */

structure-def:
		action-def
		| durative-action-def
		| derived-def
		;
		
/* <ryped list (x)> */

typed-list: //fn
		/* x* */
		| /* x* */ MINUS type typed-list L_P /* x */ R_P
		;
		
/* <primitive-type> */

primitive-type:
		name
		| OBJECT
		;
		
/* <type> */

type:
		primitive-type
		| L_P EITHER nvList_primitive-type R_P
		;
		
nvList_primitive-type:
		primitive-type list_primitive-type
		;
		
list_primitive-type:
		/* empty */
		| primitive-type list_primitive-type
		;
		
/* <emptyOr (x)> */

emptyOr: //fn
		L_P R_P
		| /* x */
		;
		
/* <action-def> */

action-def:
		L_P ACTION action-symbol N_L TAB PARAMETERS L_P typed-list L_P /* variable */ R_P R_P N_L TAB action-def-body R_P //fn
		;
		
/* <action-symbol> */

action-symbol:
		name
		;
		
/* <action-def body> */

action-def-body:
		option_precondition option_effect
		;
		
option_precondition:
		/* empty */
		| PRECONDITION emptyOr //fn
		;

option_effect:
		/* empty */
		| EFFECT emptyOr //fn
		;
		
/* <pre-GD> */

pre-GD:
		pref-GD
		| L_P AND list_pre-GD R_P
		| L_P FORALL L_P typed-list L_P /* variable */ R_P R_P pre-GD R_P //fn
		;
		
list_pre-GD:
		pre-GD list_pre-GD
		;

/* <pref-GD> */
	
pref-GD:
		GD
		| L_P PREFERENCE /* choix */ GD R_P
		;

/* <pref-name> */

pref-name:
		name
		;
		
/* <GD> */

GD:
		atomic forumla L_P term R_P //fn
		| litteral L_P term R_P //fn
		| L_P AND list_GD R_P
		| L_P OR list_GD R_P
		| L_P NOT GD R_P
		| L_P IMPLY GD GD R_P
		| L_P EXISTS L_P typed-list L_P variable R_P R_P GD R_P //fn
		| L_P FORALL L_P typed-list L_P variable R_P R_P GD R_P //fn
		| f-comp
		;
		
list_GD:
		/* empty */
		| GD list_GD
		;

/* <f-comp> */

f-comp:
		L_P binary-comp f-exp f-exp R_P
		;

/* <litteral (t)> */

litteral: //fn
		atomic-formula L_P t R_P //fn
		| L_P NOT atomic-formula L_P t R_P //fn
		;

/* <atomic formula (t)> */

atomic-formula: //fn
		L_P predicate t* R_P //fn
		| L_P EQ t t R_P //fn
		;

/* <term> */

term:
	name
	| variable
	| function-term
	;

/* <function-term> */

function-term:
		L_P function-symbol list_term R_P
		;

list_term:
		/* empty */
		| term list_term
		;

/* <f-exp> */

f-exp:
		number
		| L_P binary-op f-exp f-exp R_P
		| L_P multi-op f-exp nvList_f-exp R_P
		| L_P MINUS f-exp R_P
		| f-head
		;

nvList_f-exp:
		f-exp list_f-exp
		;

list_f-exp:
		/* empty */
		| f-exp list_f-exp
		;

/* <f-head> */

f-head:
		L_P function-symbol list_term R_P
		| funciton-symbol
		;

/* <binary-op> */

binary-op:
		multi-op
		| MINUS
		| SLASH
		;

/* <multi-op> */

multi-op:
		STAR
		| PLUS
		;

/* <binary-comp> */

binary-comp:
		GT
		| LT
		| EQ
		| GOE
		| LOE
		;

/* <name> */

name:
	letter list_any-char
	;

/* <letter> */

letter:
		LETTER
		;

/* <any char> */

any-char:
		letter
		| digit
		| MINUS
		| UNSC
		;

list_any-char:
		/* empty */
		| any-char list_any-char
		;

/* <digit> */

digit:
		DIGIT
		;

/* <decimal> */

decimal:
		DOT nvList_digit
		;

nvList_digit:
		digit list_digit
		;

list_digit:
		/* empty */
		| digit list_digit
		;

/* <effect> */

effect:
		L_P AND list_c-effect R_P
		| c-effect
		;

list_c-effect:
		/* empty */
		| c-effect list_c-effect
		;

/* <c-effect> */

c-effect:
		L_P FORALL L_P typed-list L_P variable R_P R_P effect R_P //fn
		| L_P WHEN GD const-effect R_P
		| p-effect
		;

/* <p-effect> */

p-effect:
		L_P NOT atomic-formula L_P term R_P R_P //fn
		| atomic-formula L_P term R_P //fn
		| L_P assign-op f-head f-exp
		| L_P ASSIGN function-term term R_P
		| L_P ASSIGN function-term UNDEFINED R_P
		;

/* <const-effect> */

const-effect:
		L_P AND list_p-effect R_P
		| p-effect
		;

list_p-effect:
		/* empty */
		| p-effect list_p-effect
		;

/* <assign-op> */

assign-op:
		ASSIGN
		| SCALE_UP
		| SCALE_DOWN
		| INCREASE
		| DECREASE
		;

/* <durative-action-def> */

durative-action-def:
		L_P DURATIVE_ACTION da-symbol N_L TAB PARAMETERS L_P typed-list L_P variable R_P R_P da-def-body R_P //fn
		;

/* <da-symbol> */

da-symbol:
		name
		;

/* <da-def body> */

da-def-body:
		DURATION duration-constraint N_L CONDITION  emptyOr L_P da-GD R_P N_L EFFECT emptyOr L_P da-effect R_P //fn
		;

/* <da-GD> */

da-GD:
		pref-timed-GD
		| L_P AND list_da-GD R_P
		| L_P FORALL L_P typed-list L_P variable R_P R_P da-GD R_P //fn
		;

list_da-GD:
		/* empty */
		| da-GD list_da-GD
		;

/* <oref-timed-GD> */

pref-timed-GD:
		timed-GD
		| L_P PREFERENCE option_pref-name timed-GD R_P
		;

option_pref-name:
		/* empty */
		| pref-name
		;

/* <timed-GD> */

timed-GD:
		L_P AT time-specifier GD R_P
		| L_P OVER interval GD R_P
		;

/* <time-specifier> */

time-specifier:
		START
		| END
		;

/* <interval> */

interval:
		ALL
		;

/* <duration-constraint> */

duration-constraint:
		L_P AND nvList_simple-duration-constraint R_P
		| L_P R_P
		| simple-duration-constraint
		;

nvList_simple-duration-constraint:
		simple-duration-constraint list_simple-duration-constraint
		;

list_simple-duration-constraint:
		/* empty */
		| simple-duration-constraint list_simple-duration-constraint
		;

/* <simple-duration-constraint> */

simple-duration-constraint:
		L_P d-op Q_M_DURATION d-value R_P
		| L_P AT time-specifier simple-duration-constraint R_P
		;

/* <d-op> */

d-op:
		LOE
		| GOE
		| EQ
		;

/* <d-value> */

d-value:
		NUMBER
		| f-exp
		;

/* <da-effect> */

da-effect:
		L_P AND list_da-effect R_P
		| timed-effect
		| L_P FORALL L_P typed-list L_P variable R_P R_P da-effect R_P //fn
		| L_P WHEN da-GD timed-effect R_P
		;

list_da-effect:
		/* empty */
		| da-effect list_da-effect
		;

/* <timed-effect> */

timed-effect:
		L_P AT time-specifier cond-effect R_P
		| L_P AT time-specifier f-assign-da R_P
		| L_P assign-op-t f-head f-exp-t R_P
		;

/* <f-assign-da> */

f-assign-da:
		L_P assign-op f-head f-exp-da R_P
		;

/* <f-exp-da> */

f-exp-da:
		L_P binary-op f-exp-da f-exp-da R_P
		| L_P multi-op f-exp-da nvList_f-exp-da R_P
		| L_P MINUS f-exp-da R_P
		| Q_M_DURATION
		| f-exp
		;

nvList_f-exp-da:
		f-exp-da list_f-exp-da
		;

list_f-exp-da:
		/* empty */
		| f-exp-da list_f-exp-da
		;

/* <assign-op-t> */

assign-op-t:
		INCREASE
		| DECREASE
		;

/* <f-exp-t> */

f-exp-t:
		L_P STAR f-exp //todo R_P
		| L_P STAR //todo f-exp R_P
		| //todo
		;

/* <derived-def> */

derived-def:
		L_P DERIVED atomic-formula-skeleton GD R_P
		;


/***************************************************/
/************** Problem Description ****************/
/***************************************************/

/* <problem> */

problem:
		L_P DEFINE L_P PROBLEM name R_P N_L TAB L_P DD_DOMAIN name R_P N_L TAB option_require-def N_L TAB option_object-declaration N_L TAB init N_L TAB goal N_L TAB option_constraints N_L TAB option_metric-spec N_L TAB option_length-spec R_P
		;

option_object-declaration:
		/* empty */
		| object-declaration
		;

option_metric-spec:
		/* empty */
		| metric-spec
		;

option_length-spec:
		/* empty */
		| length-spec
		;

/* <object declaration> */

object-declaration:
		L_P OBJECTS typed-list L_P name R_P R_P //fn
		;

/* <init> */

init:
		L_P INIT list_init-el R_P
		;

list_init-el:
		/* empty */
		| init-el list_init-el
		;

/* <init-el> */

init-el:
		literal L_P name R_P //fn
		| L_P AT nuber literal L_P name R_P R_P //fn
		| L_P EQ basic-function-term number R_P
		| L_P EQ basic-function-term name R_P
		;

/* <basic-function-term> */

basic-function-term:
		function-symbol
		| L_P function-symbol list_name R_P
		;

list_name:
		/* empty */
		| name list_name
		;

/* <goal> */

goal:
		L_P GOAL pre-GD
		;

/* <contraints> */
/* is contraints different between domain definition and problem definition ? */

/* <pref-con-GD> */

pref-con-GD:
		L_P AND list_pref-con-GD R_P
		| L_P FORALL L_P typed-list L_P variable R_P R_P pref-con-GD R_P
		| L_P PREFERENCE option_pref-name con-GD R_P
		| con-GD
		;

list_pref-con-GD:
		/* empty */
		| pref-con-GD list_pref-con-GD
		;

/* <con-GD> */

con-GD:
		L_P AND list_con-GD R_P
		| L_P FORALL L_P typed-list L_P variable R_P R_P con-GD R_P //fn
		| L_P AT END GD R_P
		| L_P ALWAYS con2-GD R_P
		| L_P SOMETIME con2-GD R_P
		| L_P WITHIN number con2-GD R_P
		| L_P AT_MOST_ONCE con2-GD con2-GD R_P
		| L_P SOMETIME_AFTER con2-GD con2-GD R_P
		| L_P SOMETIME_BEFORE con2-GD con2-GD R_P
		| L_P ALWAYS_WITHIN number con2-GD con2-GD R_P
		| L_P HOLD_DURING number number con2-GD R_P
		| L_P HOLD_AFTER number con2-GD R_P
		;

list_con-GD:
		/* empty */
		| con-GD list_con-GD
		;

/* <con2-GD> */

con2-GD:
		con-GD
		| GD
		;

/* <metric-spec> */

metric-spec:
		L_P METRIC optimization metric-f-exp R_P
		;

/* <optimization> */

optimization:
		MINIMIZE
		| MAXIMIZE
		;

/* <metric-f-exp> */

metric-f-exp:
		L_P binary-op metric-f-exp metric-f-exp R_P
		| L_P multi-op metric-f-exp nvList_metric-f-exp R_P
		| L_P MINUS metric-f-exp R_P
		| number
		| L_P function-symbol list_name R_P
		| function-symbol
		| TOTAL_TIME
		| L_P IS_VIOLATED pref-name R_P
		;

nvList_metric-f-exp:
		metric-f-exp list_metric-f-exp
		;

list_metric-f-exp:
		/* empty */
		| metric-f-exp list_metric-f-exp
		;

/* <length-spec> */

length-spec:
		L_P LENGTH option_serial option_parallel R_P
		;

option_serial:
		/* empty */
		| L_P SERIAL integer R_P
		;

option_parallel:
		/* empty */
		| L_P PARALLEL integer R_P


/***************************************************/
/*********************** End ***********************/
/***************************************************/

%%

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

int yyerror(char *s)
{
  return yyerror(string(s));
}


