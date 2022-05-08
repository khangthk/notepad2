#include "EditLexer.h"
#include "EditStyleX.h"

static KEYWORDLIST Keywords_ABAQUS = {{
//++Autogenerated -- start of section automatically generated
"assembly end instance part step "

, // 1 command
NULL

, // 2 slash command
NULL

, // 3 star command
"assembly end instance part step "

, // 4 argument
NULL

, // 5 function
NULL

, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
//--Autogenerated -- end of section automatically generated
}};

static EDITSTYLE Styles_ABAQUS[] = {
	EDITSTYLE_DEFAULT,
	{ SCE_APDL_WORD, NP2StyleX_Keyword, L"bold; fore:#FF8000" },
	{ MULTI_STYLE(SCE_APDL_COMMAND, SCE_APDL_SLASHCOMMAND, SCE_APDL_STARCOMMAND, 0), NP2StyleX_Command, L"fore:#0080C0" },
	{ SCE_APDL_FUNCTION, NP2StyleX_Function, L"fore:#A46000" },
	{ SCE_APDL_ARGUMENT, NP2StyleX_Parameter, L"fore:#A46000" },
	{ SCE_APDL_COMMENT, NP2StyleX_Comment, L"fore:#608060" },
	{ SCE_APDL_STRING, NP2StyleX_String, L"fore:#008000" },
	{ SCE_APDL_NUMBER, NP2StyleX_Number, L"fore:#FF0000" },
	{ SCE_APDL_OPERATOR, NP2StyleX_Operator, L"fore:#B000B0" },
};

EDITLEXER lexABAQUS = {
	SCLEX_APDL, NP2LEX_ABAQUS,
//Settings++Autogenerated -- start of section automatically generated
	{
		LexerAttr_NoBlockComment,
		TAB_WIDTH_4, INDENT_WIDTH_4,
		(1 << 0) | (1 << 1), // level1, level2
		0,
		'\\', 0, 0,
		0,
		0, 0,
		SCE_APDL_OPERATOR, 0
		, KeywordAttr32(0, KeywordAttr_PreSorted) // code folding
		| KeywordAttr32(3, KeywordAttr_PreSorted) // star command
	},
//Settings--Autogenerated -- end of section automatically generated
	EDITLEXER_HOLE(L"ABAQUS", Styles_ABAQUS),
	L"inp",
	&Keywords_ABAQUS,
	Styles_ABAQUS
};
