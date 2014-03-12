// Generated by Bisonc++ V4.01.00 on Wed, 12 Mar 2014 23:51:33 +0100

#ifndef ParserBase_h_included
#define ParserBase_h_included

#include <vector>
#include <iostream>


namespace // anonymous
{
    struct PI__;
}



class ParserBase
{
    public:
// $insert tokens

    // Symbolic tokens:
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

// $insert STYPE
typedef int STYPE__;

    private:
        int d_stackIdx__;
        std::vector<size_t>   d_stateStack__;
        std::vector<STYPE__>  d_valueStack__;

    protected:
        enum Return__
        {
            PARSE_ACCEPT__ = 0,   // values used as parse()'s return values
            PARSE_ABORT__  = 1
        };
        enum ErrorRecovery__
        {
            DEFAULT_RECOVERY_MODE__,
            UNEXPECTED_TOKEN__,
        };
        bool        d_debug__;
        size_t      d_nErrors__;
        size_t      d_requiredTokens__;
        size_t      d_acceptedTokens__;
        int         d_token__;
        int         d_nextToken__;
        size_t      d_state__;
        STYPE__    *d_vsp__;
        STYPE__     d_val__;
        STYPE__     d_nextVal__;

        ParserBase();

        void ABORT() const;
        void ACCEPT() const;
        void ERROR() const;
        void clearin();
        bool debug() const;
        void pop__(size_t count = 1);
        void push__(size_t nextState);
        void popToken__();
        void pushToken__(int token);
        void reduce__(PI__ const &productionInfo);
        void errorVerbose__();
        size_t top__() const;

    public:
        void setDebug(bool mode);
}; 

inline bool ParserBase::debug() const
{
    return d_debug__;
}

inline void ParserBase::setDebug(bool mode)
{
    d_debug__ = mode;
}

inline void ParserBase::ABORT() const
{
    throw PARSE_ABORT__;
}

inline void ParserBase::ACCEPT() const
{
    throw PARSE_ACCEPT__;
}

inline void ParserBase::ERROR() const
{
    throw UNEXPECTED_TOKEN__;
}


// As a convenience, when including ParserBase.h its symbols are available as
// symbols in the class Parser, too.
#define Parser ParserBase


#endif


