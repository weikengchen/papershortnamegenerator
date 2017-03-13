#include <stdio.h>
#include <ctype.h>
#include <string.h>

int generate(char *word, char *str){
	int lword = strlen(word);
	int lstr = strlen(str);	

	int pword = 0;
	int pstr = 0;

	while(pword < lword && pstr < lstr){
		if(word[pword] == str[pstr]){
			str[pstr] = toupper(str[pstr]);
			pword++;
			pstr++;
		}else{
			str[pstr] = tolower(str[pstr]);
			pstr++;
		}

		if(pword == lword){
			return 1;
		}
	}
}

int match(char* word, char *str){
	int lword = strlen(word);
	int lstr = strlen(str);	

	int pword = 0;
	int pstr = 0;

	while(pword < lword && pstr < lstr){
		if(word[pword] == str[pstr]){
			pword++;
			pstr++;
		}else{
			pstr++;
		}

		if(pword == lword){
			return 1;
		}
	}
	return 0;
}

int main(){
	char str[1000];
	char strtmp[1000];
	printf("Please enter your title\n");
	scanf("%[^\r\n]*", str);

	char word[1000];
	FILE *fp = fopen("/usr/share/dict/american-english", "r");
	while(fscanf(fp, "%s", word) == 1){
		/* optional: require the matching of first letter of the string */
		if(word[0] != str[0]){
			continue;
		}
		/**/

		if(match(word, str) == 1){
			printf("%s\n", word);
			strcpy(strtmp, str);
			generate(word, strtmp);
			printf("\t%s\n", strtmp);
		}
	}
	return 0;
}
