/*
* ���� : ����ȭ
* ���� :
	ECMAScript ���

	#include <regex>
	
	regex r("__rule__");
	[abcde]		: abcde �� �ϳ�
	[abcde]+	: 1�� �̻��� abcde => a, aa, ab, abc, abcd, abcde
	[abcde]*	: 0�� �̻��� abcde =>  , a, aa, abc, abcd, abcdeeee
	()			: capture					=> ([0-1])([a-zA-Z])(B*)  ()�������� ��Ī.
											-------------------------
														0�� ĸó [0]
											-----------
											1�� ĸó [1]
													-------------
													2�� ĸó [2]
																--------
																3�� ĸó [3]
	[a-zA-Z]	: ���ĺ� �빮�� �ҹ���

	[:alpha:]	: ���ĺ� �빮�� �ҹ���
	\d			: ���� 0-9
	\w			: ���ĺ�, ����
	\s			: �����̽� ��

	Obj
		regex __	: 
		smatch __	: ĸó ��Ƴ��� ����

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