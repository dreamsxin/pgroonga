#pragma once

#include <postgres.h>
#include <fmgr.h>

/* Default values */
#ifndef PGRN_DEFAULT_TOKENIZER
#  define PGRN_DEFAULT_TOKENIZER "TokenBigram"
#endif
#ifndef PGRN_DEFAULT_NORMALIZER
#  define PGRN_DEFAULT_NORMALIZER "NormalizerAuto"
#endif

/* Groonga strategy types */
#define PGrnLessStrategyNumber			1	/* operator < */
#define PGrnLessEqualStrategyNumber		2	/* operator <= */
#define PGrnEqualStrategyNumber			3	/* operator = */
#define PGrnGreaterEqualStrategyNumber	4	/* operator >= */
#define PGrnGreaterStrategyNumber		5	/* operator > */
#define PGrnLikeStrategyNumber			6	/* operator ~~ (LIKE) */
#define PGrnILikeStrategyNumber			7	/* operator ~~* (ILIKE) */
#define PGrnMatchStrategyNumber			8	/* operator %% (@ in Groonga) */
#define PGrnQueryStrategyNumber			9	/* operator @@ (Groonga query) */
#define PGrnRegexpStrategyNumber		10	/* operator @~ (@~ in Groonga)  */
#define PGrnJSONContainStrategyNumber	11	/* operator @> */

#define PGrnMatchStrategyV2Number		12	/* operator &@	(@ in Groonga) */
#define PGrnQueryStrategyV2Number		13	/* operator &?  (query in Groonga) */
#define PGrnSimilarStrategyV2Number		14	/* operator &~? (similar search) */
#define PGrnScriptStrategyV2Number		15	/* operator &`  (script in Groonga) */
#define PGrnPrefixStrategyV2Number		16	/* operator &^  (prefix search) */
#define PGrnPrefixRKStrategyV2Number	17	/* operator &^~ (prefix RK search) */
#define PGrnMatchInStrategyV2Number		18	/* operator &@> (@ in Groonga) */
#define PGrnQueryInStrategyV2Number		19	/* operator &?> (query in Groonga) */
#define PGrnPrefixInStrategyV2Number	20	/* operator &^>  (prefix search) */
#define PGrnPrefixRKInStrategyV2Number	21	/* operator &^~> (prefix RK search) */
#define PGrnRegexpStrategyV2Number		22	/* operator &~ (@~ in Groonga) */
#define PGrnContainStrategyV2Number		23	/* operator &> (@ for vector in Groonga) */

#define PGRN_N_STRATEGIES PGrnContainStrategyV2Number

/* file and table names */
#define PGrnLogPathDefault				"pgroonga.log"
#define PGrnQueryLogPathDefault			"none"
#define PGrnDatabaseBasename			"pgrn"
#define PGrnSourcesTableNamePrefix		"Sources"
#define PGrnSourcesTableNamePrefixLength	(sizeof(PGrnSourcesTableNamePrefix) - 1)
#define PGrnSourcesTableNameFormat		PGrnSourcesTableNamePrefix "%u"
#define PGrnSourcesCtidColumnName		"ctid"
#define PGrnSourcesCtidColumnNameLength	(sizeof(PGrnSourcesCtidColumnName) - 1)
#define PGrnJSONPathsTableNamePrefix	"JSONPaths"
#define PGrnJSONPathsTableNameFormat	PGrnJSONPathsTableNamePrefix "%u_%u"
#define PGrnJSONValuesTableNamePrefix	"JSONValues"
#define PGrnJSONValuesTableNameFormat	PGrnJSONValuesTableNamePrefix "%u_%u"
#define PGrnJSONTypesTableNamePrefix	"JSONTypes"
#define PGrnJSONTypesTableNameFormat	PGrnJSONTypesTableNamePrefix "%u_%u"
#define PGrnJSONValueLexiconNameFormat	"JSONValueLexicon%s%u_%u"
#define PGrnLexiconNameFormat			"Lexicon%u_%u"
#define PGrnIndexColumnName				"index"

extern bool PGrnGroongaInitialized;
