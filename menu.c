#include "menu.h"
#include <string.h>

int ask_menu(int is_login){
// 파라미터 : 로그인여부 (0 No, 1Yes)
// 리턴값 : 선택한 메뉴번호
// 메뉴번호 : 1. Sign up 2. Log in 3. Log out 0. Exit
  char menu[10];
  if(is_login==0)
    printf("[login, join, exit] > ");
  else
    printf("[logout, list, exit] # ");
  scanf("%s", menu);

  if(strcmp(menu, "join")==0)
	return 1;
  else if(strcmp(menu, "login")==0)
	return 2;
  else if(strcmp(menu, "logout")==0)
	return 3;
  else if(strcmp(menu, "list")==0)
	return 4;
  else if(strcmp(menu, "exit")==0)
	return 0;
  else return -1;

}
