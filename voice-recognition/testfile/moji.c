#include <stdio.h>
#include <string.h>
int main(void){
	char s1[] = "abc";
	char s2[] = "abc";
	char s3[] = "ABC";
	int ret;
	printf( "%s と %s の比較\n", s1, s2 );
	ret = strcmp( s1, s2 );
	if( ret == 0 ){
		printf( "文字列が一致しました\n" );
	}
	else{
		printf( "文字列が異なります\n" );
	}
	printf( "%s と %s の比較\n", s1, s3 );
	ret = strcmp( s1, s3 );
	if( ret == 0 ){
		printf( "文字列が一致しました\n" );
	}
	else{
		printf( "文字列が異なります\n" );
	}
	return 0;
}
