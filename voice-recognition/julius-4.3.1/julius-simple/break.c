/* header files */
#include <stdio.h>
#include <stdlib.h>
/* main */
int main(void) {
	FILE *fp;
	char filename[] = "sample.txt";
	int count;
 	/* ファイルオープン */
	if ((fp = fopen(filename, "w")) == NULL) {
		fprintf(stderr, "ファイルのオープンに失敗しました．\n");
		return EXIT_FAILURE;
	}
	/* 書き込み */
	count = fprintf(fp, "Satisfaction!\n");
	if ( count < 0 ) {
		fprintf(stderr, "ファイルの書込みに失敗しました.\n");
		fclose(fp);
		return EXIT_FAILURE;
	}
	fprintf(stdout, "%sへ%d文字出力しました．\n", filename, count);
	/* ファイルクローズ */
	fclose(fp);
	return EXIT_SUCCESS;
}
