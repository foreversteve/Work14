#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <string.h>
/*
	strsep - <string.h>
	strsep( source, delimiters)
		-- Locates the first occurrence of any of the specified delimiters in a string and replaces it with NULL
		-- Treats delimiters as distinct characters.
		-- Modifies the source to point to the location one byte after the first delimiter
		-- Returns a pointer to the original beginning
*/

char **strsep(char **source, char *delimiter){
	char *temp = *source;
	int c = 0;
	while (temp[c]){
		// printf("%c\n",temp[c]);
		if (temp[c] == *delimiter){
			temp[c] = 0;
			*source = temp+c+1;

			return &temp;
		}
		c+=1;
	}

	return &temp;
}

char **parse_args(char *line){
	char **temp = &line;
	char **ans = calloc(5,sizeof(char*));
	for (int i = 0; i < 5; i++){
		if (! *temp){
			return ans;
		}
		ans[i] = *strsep(temp," ");
	}
	return ans;
}

int main(){
	char line[100] = "woah-this-is-cool";
	char *s1 = line;
	char *s2 = *strsep( &s1, "-" );
	printf("[%s]\n", s1);
	printf("[%s]\n", s2);

	strcpy(line,"ls -a -l");
	// printf("%s\n",line);
	char ** args = parse_args(line);
	execvp(args[0], args);
	free(*args);
	return 0;
}


