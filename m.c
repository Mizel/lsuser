#include <pwd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <grp.h>
#include <limits.h>
#include <shadow.h>
#include <crypt.h>
#include <string.h>
#include <sys/types.h>
#include <shadow.h>
#include "color.h"
#include <stdbool.h>
void printUserInfo(struct passwd * pwd){
	if(pwd == NULL){
		if(errno == 0){
	printf("Not found ");
		}else{
	printf("erron : ");
	}
	}

	printf("%s\t\e[1;32m\%s\t\e[4;2;39m%i\e[m\n",pwd->pw_name,pwd->pw_passwd,pwd->pw_uid);

}
int main(int argc,char **argv){

	errno = 0;
	char *user,*currntuser;
	struct passwd * pwd;
	struct uid_t * uid;
	struct group * gup;
	bool x = true;

	currntuser = getenv("USER");

	printf("User\t%sPasswd%s\tId\n",GRN,F);
	if(argc == 1 ){
	user = getenv("USER");
	pwd = getpwnam(user);
	printUserInfo(pwd);
	}

	for(int i = 1 ; i < argc ; i++){
		
		
	 if ((strcmp(argv[i],currntuser) == 0)  && x){
			x = false;
			pwd = getpwnam(argv[i]);
			printUserInfo(pwd);
		} else { 
			pwd = getpwnam(argv[i]);
			printUserInfo(pwd);
		}
		
	}


}

