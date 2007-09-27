/**
 * @file token_enum.h
 * List of the different tokens used in the program.
 *
 * @author  Ben Gardner
 * @license GPL v2+
 *
 * $Id$
 */
#ifndef TOKEN_ENUM_H_INCLUDED
#define TOKEN_ENUM_H_INCLUDED

/**
 * This is an enum of all the different chunks/tokens/elements that the
 * program can work with.  The parser and scanner assigns one of these to
 * each chunk/token.
 *
 * The script 'make_token_names.sh' creates token_names.h, so be sure to run
 * that after adding or removing an entry.
 */
typedef enum
{
   CT_NONE,
   CT_SOF,           /* Start of the file */
   CT_EOF,
   CT_UNKNOWN,


   CT_WHITESPACE,    /* whitespace without any newlines */
   CT_SPACE,         /* a fixed number of spaces to support weird spacing rules */
   CT_NEWLINE,       /* CRA, one or more newlines */
   CT_NL_CONT,       /* CRA, backslash-newline */
   CT_COMMENT_CPP,   /* C++ comment (always followed by CT_NEWLINE) */
   CT_COMMENT,       /* C-comment, single line */
   CT_COMMENT_MULTI, /* Multi-lined comment */
   CT_COMMENT_EMBED, /* comment parent_type: non-newline before and after */
   CT_COMMENT_START, /* comment parent_type: newline before */
   CT_COMMENT_END,   /* comment parent_type: newline after */
   CT_COMMENT_WHOLE, /* comment parent_type: newline before and after */

   CT_WORD,          /* variable, type, function name, etc */
   CT_NUMBER,
   CT_NUMBER_FP,
   CT_STRING,        /* quoted string "hi" or 'a' or <in> for include */
   CT_STRING_MULTI,  /* quoted string with embedded newline */
   CT_IF,            /* built-in keywords */
   CT_ELSE,
   CT_ELSEIF,
   CT_FOR,
   CT_WHILE,
   CT_WHILE_OF_DO,
   CT_SWITCH,
   CT_CASE,
   CT_DO,
   CT_VOLATILE,
   CT_TYPEDEF,
   CT_STRUCT,
   CT_ENUM,
   CT_SIZEOF,
   CT_RETURN,
   CT_BREAK,
   CT_UNION,
   CT_GOTO,
   CT_CONTINUE,
   CT_CAST,                /* cast(exp) -- as used in D */
   CT_TYPE_CAST,           /* static_cast<type>(exp) */
   CT_TYPENAME,            /* typename type */
   CT_TEMPLATE,            /* template<...> */

   CT_ASSIGN,              /* =, +=, /=, etc */
   CT_SASSIGN,             /* 'and_eq' */
   CT_COMPARE,             /* ==, !=, <=, >= */
   CT_SCOMPARE,            /* compare op that is a string 'is', 'neq' */
   CT_BOOL,                /* || or && */
   CT_SBOOL,               /* or, and */
   CT_ARITH,               /* +, -, /, <<, etc */
   CT_SARITH,              /* 'not', 'xor' */
   CT_DEREF,               /* * dereference */
   CT_INCDEC_BEFORE,       /* ++a or --a */
   CT_INCDEC_AFTER,        /* a++ or a-- */
   CT_MEMBER,              /* . or -> */
   CT_DC_MEMBER,           /* :: */
   CT_C99_MEMBER,          /* . in structure stuff */
   CT_INV,                 /* ~ */
   CT_DESTRUCTOR,          /* ~ */
   CT_NOT,                 /* ! */
   CT_D_TEMPLATE,          /* ! as in Foo!(A) */
   CT_ADDR,                /* & */
   CT_NEG,                 /* - as in -1 */
   CT_POS,                 /* + as in +1 */
   CT_STAR,                /* * : raw char to be changed */
   CT_PLUS,                /* + : raw char to be changed */
   CT_MINUS,               /* - : raw char to be changed */
   CT_AMP,                 /* & : raw char to be changed */
   CT_BYREF,               /* & in function def/proto params */

   CT_POUND,               /* # */
   CT_PREPROC,             /* # at the start of a line */
   CT_PREPROC_INDENT,      /* # at the start of a line that gets indented: #region */
   CT_PREPROC_BODY,        /* body of every preproc EXCEPT #define */
   CT_PP,                  /* ## */
   CT_ELLIPSIS,            /* ... */
   CT_RANGE,               /* .. */

   CT_SEMICOLON,
   CT_VSEMICOLON,          /* virtual semicolon for PAWN */
   CT_COLON,
   CT_CASE_COLON,
   CT_CLASS_COLON,         /* colon after a class def or constructor */
   CT_D_ARRAY_COLON,       /* D named array initializer colon */
   CT_Q_COLON,
   CT_QUESTION,
   CT_COMMA,

   CT_ASM,
   CT_ATTRIBUTE,
   CT_CATCH,
   CT_CLASS,
   CT_DELETE,
   CT_EXPORT,
   CT_FRIEND,
   CT_MUTABLE,
   CT_NAMESPACE,
   CT_NEW,              /* may turn into CT_PBRACED if followed by a '(' */
   CT_OPERATOR,
   CT_PRIVATE,
   CT_PRIVATE_COLON,
   CT_THROW,
   CT_TRY,
   CT_USING,
   CT_SUPER,
   CT_DELEGATE,
   CT_BODY,
   CT_DEBUG,
   CT_INVARIANT,
   CT_UNITTEST,
   CT_UNSAFE,
   CT_FINALLY,
   CT_IMPORT,
   CT_SCOPE,
   CT_LAZY,
   CT_D_MACRO,

   /* note for paren/brace/square pairs: close MUST be open + 1 */
   CT_PAREN_OPEN,
   CT_PAREN_CLOSE,

   CT_ANGLE_OPEN,       /* template<T*> */
   CT_ANGLE_CLOSE,

   CT_SPAREN_OPEN,      /* 'special' paren after if/for/switch/while */
   CT_SPAREN_CLOSE,

   CT_FPAREN_OPEN,      /* 'function' paren after fcn/macro fcn */
   CT_FPAREN_CLOSE,

   CT_BRACE_OPEN,
   CT_BRACE_CLOSE,

   CT_VBRACE_OPEN,
   CT_VBRACE_CLOSE,

   CT_SQUARE_OPEN,
   CT_SQUARE_CLOSE,

   CT_TSQUARE,          /* special case of [] */

   CT_MACRO_OPEN,       /* stuff specified via custom-pair */
   CT_MACRO_CLOSE,
   CT_MACRO_ELSE,

   /* agregate types */
   CT_LABEL,            /* a non-case label */
   CT_LABEL_COLON,      /* the colon for a label */
   CT_FUNCTION,         /* function - unspecified, call mark_function() */
   CT_FUNC_CALL,        /* function call */
   CT_FUNC_DEF,         /* function definition/implementation */
   CT_FUNC_PROTO,       /* function prototype */
   CT_FUNC_CLASS,       /* ctor or dtor for a class */
   CT_FUNC_CTOR_VAR,    /* variable or class initialization */
   CT_MACRO_FUNC,       /* function-like macro */
   CT_MACRO,            /* a macro def */
   CT_QUALIFIER,        /* static, const, etc */
   CT_ALIGN,            /* paren'd qualifier: align(4) struct a { } */
   CT_TYPE,
   CT_PTR_TYPE,         /* a '*' as part of a type */

   CT_BIT_COLON,        /* a ':' in a variable declaration */

   CT_OC_END,           /* ObjC: @end */
   CT_OC_IMPL,          /* ObjC: @implementation */
   CT_OC_INTF,          /* ObjC: @interface */
   CT_OC_CLASS,         /* ObjC: the name after @interface or @implementation */

   /* start PP types */
   CT_PP_DEFINE,        /* #define */
   CT_PP_DEFINED,       /* #if defined */
   CT_PP_INCLUDE,       /* #include */
   CT_PP_IF,            /* #if, #ifdef, or #ifndef */
   CT_PP_ELSE,          /* #else or #elif */
   CT_PP_ENDIF,         /* #endif */
   CT_PP_ASSERT,
   CT_PP_EMIT,
   CT_PP_ENDINPUT,
   CT_PP_ERROR,
   CT_PP_FILE,
   CT_PP_LINE,
   CT_PP_SECTION,
   CT_PP_UNDEF,

   CT_PP_BODYCHUNK,     /* everything after this gets put in CT_PREPROC_BODY */

   CT_PP_PRAGMA,        /* pragma's should not be altered */
   CT_PP_REGION,        /* C# #region */
   CT_PP_ENDREGION,     /* C# #endregion */
   CT_PP_REGION_INDENT, /* Dummy token for indenting a C# #region */
   CT_PP_OTHER,         /* #line, #error, #pragma, etc */
   /* end PP types */

   /* PAWN stuff */
   CT_CHAR,
   CT_DEFINED,
   CT_FORWARD,
   CT_NATIVE,
   CT_STATE,
   CT_STOCK,
   CT_TAGOF,
   CT_DOT,
   CT_TAG,
   CT_TAG_COLON,

   /* C-sharp crap */
   CT_LOCK,             /* lock/unlock */
   CT_AS,
   CT_IN,               /* "foreach (T c in x)" or "foo(in char c)" or "in { ..." */
   CT_BRACED,           /* simple braced items: try {} */
   CT_VERSION,          /* turns into CT_IF if not followed by '=' */
   CT_THIS,             /* may turn into CT_PBRACED if followed by a '(' */
   CT_BASE,             /* C# thingy */
   CT_DEFAULT,          /* may be changed into CT_CASE */
   CT_GETSET,           /* must be followed by CT_BRACE_OPEN or reverts to CT_WORD */
   CT_CONCAT,           /* The '~' between strings */

   /* Embedded SQL - always terminated with a semicolon */
   CT_SQL_EXEC,         /* the 'EXEC' in 'EXEC SQL ...' */
   CT_SQL_BEGIN,        /* the 'EXEC' in 'EXEC SQL BEGIN ...' */
   CT_SQL_END,          /* the 'EXEC' in 'EXEC SQL END ...' */
   CT_SQL_WORD,         /* CT_WORDs in the 'EXEC SQL' statement */
} c_token_t;

#endif   /* TOKEN_ENUM_H_INCLUDED */
