#ifndef _lucene_analysis_snowball_analyser_
#define _lucene_analysis_snowball_analyser_

#include "CLucene/analysis/AnalysisHeader.h"

CL_NS_DEF2(analysis,snowball)

/** Filters {@link StandardTokenizer} with {@link StandardFilter}, {@link
 * LowerCaseFilter}, {@link StopFilter} and {@link SnowballFilter}.
 *
 * Available stemmers are listed in {@link net.sf.snowball.ext}.  The name of a
 * stemmer is the part of the class name before "Stemmer", e.g., the stemmer in
 * {@link EnglishStemmer} is named "English".
 */
class SnowballAnalyzer: public Analyzer {
  const TCHAR* language;
  CLTCSetList* stopSet;

public:
  /** Builds the named analyzer with no stop words. */
  SnowballAnalyzer(const TCHAR* language=_T("english"));

  /** Builds the named analyzer with the given stop words.
  */
  SnowballAnalyzer(const TCHAR* language, const TCHAR** stopWords);

  ~SnowballAnalyzer();

  /** Constructs a {@link StandardTokenizer} filtered by a {@link
      StandardFilter}, a {@link LowerCaseFilter} and a {@link StopFilter}. */
  TokenStream* tokenStream(const TCHAR* fieldName, CL_NS(util)::Reader* reader);
};

CL_NS_END2
#endif
