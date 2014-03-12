// Generated by Flexc++ V2.00.00 on Wed, 12 Mar 2014 18:25:30 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"


// $insert classHead
class Scanner: public ScannerBase
{
    public:
		enum Tokens__
		{
		    L_P = 257,
		    R_P,
		    L_B,
		    Q_M,
		    NS_T,
		    EQ,
		    MINUS,
		    SLASH,
		    STAR,
		    PLUS,
		    GT,
		    LT,
		    GOE,
		    LOE,
		    UNSC,
		    DOT,
		    LETTER,
		    DIGIT,
		    NUMBER,
		    DEFINE,
		    DOMAIN,
		    REQUIREMENTS,
		    STRIPS,
		    TYPING,
		    NEGATIVE_PRECONDITIONS,
		    DISJUNCTIVE_PRECONDITIONS,
		    EQUALITY,
		    EXISTENTIAL_PRECONDITIONS,
		    UNIVERSAL_PRECONDITIONS,
		    QUANTIFIED_PRECONDITIONS,
		    CONDITIONAL_EFFECTS,
		    FLUENTS,
		    NUMERIC_FLUENTS,
		    ADL,
		    DURACTIVE_ACTIONS,
		    DURATION_INEQUALITIES,
		    CONTINUOUS_EFFECTS,
		    DERIVED_PREDICATES,
		    TIMED_INITIAL_LITERALS,
		    PREFERENCES,
		    CONSTRAINTS,
		    ACTION_COSTS,
		    TEMPORALLY_EXTENDED,
		    TYPES,
		    CONSTANTS,
		    PREDICATES,
		    FUNCTIONS,
		    NUM,
		    OBJECT,
		    EITHER,
		    ACTION,
		    PARAMETERS,
		    PRECONDITION,
		    EFFECT,
		    AND,
		    FORALL,
		    PREFERENCE,
		    OR,
		    NOT,
		    IMPLY,
		    EXISTS,
		    WHEN,
		    ASSIGN,
		    UNDEFINED,
		    SCALE_UP,
		    SCALE_DOWN,
		    INCREASE,
		    DECREASE,
		    DURATIVE_ACTION,
		    DURATION,
		    CONDITION,
		    AT,
		    OVER,
		    START,
		    END,
		    ALL,
		    Q_M_DURATION,
		    DERIVED,
		    PROBLEM,
		    DD_DOMAIN,
		    OBJECTS,
		    INIT,
		    GOAL,
		    ALWAYS,
		    SOMETIME,
		    WITHIN,
		    AT_MOST_ONCE,
		    SOMETIME_AFTER,
		    SOMETIME_BEFORE,
		    ALWAYS_WITHIN,
		    HOLD_DURING,
		    HOLD_AFTER,
		    METRIC,
		    MINIMIZE,
		    MAXIMIZE,
		    TOTAL_TIME,
		    IS_VIOLATED,
		    LENGTH,
		    SERIAL,
		    PARALLEL,
		    TIMEPOINTS,
		    TIMEALIASES,
		    TIMECONSTRAINTS,
		    NAME,
		};
        explicit Scanner(std::istream &in = std::cin,
                                std::ostream &out = std::cout);

        Scanner(std::string const &infile, std::string const &outfile);
        
        // $insert lexFunctionDecl
        int lex();

    private:
        int lex__();
        int executeAction__(size_t ruleNr);

        void print();
        void preCode();     // re-implement this function for code that must 
                            // be exec'ed before the patternmatching starts

        void postCode(PostEnum__ type);    
                            // re-implement this function for code that must 
                            // be exec'ed after the rules's actions.
};

// $insert scannerConstructors
inline Scanner::Scanner(std::istream &in, std::ostream &out)
:
    ScannerBase(in, out)
{}

inline Scanner::Scanner(std::string const &infile, std::string const &outfile)
:
    ScannerBase(infile, outfile)
{}

// $insert inlineLexFunction
inline int Scanner::lex()
{
    return lex__();
}

inline void Scanner::preCode() 
{
    // optionally replace by your own code
}

inline void Scanner::postCode(PostEnum__ type) 
{
    // optionally replace by your own code
}

inline void Scanner::print() 
{
    print__();
}


#endif // Scanner_H_INCLUDED_

