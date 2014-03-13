// Generated by Flexc++ V0.98.00 on Thu, 13 Mar 2014 14:40:46 +0100

#ifndef Scanner_H_INCLUDED_
#define Scanner_H_INCLUDED_

// $insert baseclass_h
#include "Scannerbase.h"


// $insert classHead
class Scanner: public ScannerBase
{
    public:
        enum Tokens
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

inline void Scanner::print() 
{
    print__();
}


#endif // Scanner_H_INCLUDED_
