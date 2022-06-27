/*
* 제목 : 정규화
* 설명 :
	ECMAScript 기반

	#include <regex>
	
	regex r("__rule__");
	[abcde]		: abcde 중 하나
	[abcde]+	: 1개 이상의 abcde => a, aa, ab, abc, abcd, abcde
	[abcde]*	: 0개 이상의 abcde =>  , a, aa, abc, abcd, abcdeeee
	()			: capture					=> ([0-1])([a-zA-Z])(B*)  ()기준으로 매칭.
											-------------------------
														0번 캡처 [0]
											-----------
											1번 캡처 [1]
													-------------
													2번 캡처 [2]
																--------
																3번 캡처 [3]
	[a-zA-Z]	: 알파벳 대문자 소문자

	[:alpha:]	: 알파벳 대문자 소문자
	\d			: 숫자 0-9
	\w			: 알파벳, 숫자
	\s			: 스페이스 바

	Obj
		regex __	: 
		smatch __	: 캡처 담아내는 변수

		regex_iterator (begin(), end(), regex)
		sregex_iterator (begin(), end(), regex)

		regex_token_iterator (begin(), end(), regex, -1|0)
		sregex_token_iterator (begin(), end(), regex, -1|0)
	Function
		regex_match()	: total match
		regex_search()	: part match
*/

#include <regex>

void test()
{
	regex r("\\s+");
}