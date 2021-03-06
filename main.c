#include "user.h"
#include "menu.h"

int main(int argc, char* argv[]) {
  LOGIN* userlist[100]; // 사용자목록 포인터 배열 (최대 100)

  int is_login=0; // 로그인 여부 (0 NO, 1 Yes)
 
 int menu_id;
  if (argc != 2) {
    printf("Usage : manager <datafile>\n");
    return 0;
  }
 
  int count = load_file(userlist, argv[1]);
//만약 파일을 새로 생성안하거나 잘못된 커맨드를 입력하면 종료. 
 if(count<0){
	printf("Exit the program\n");
	return 0;
}

  while(1){
    menu_id = ask_menu(is_login); // 현재 로그인 되었는지의 여부를 파라미터로 알려야 한다.
    if(menu_id==1) {
	if(join(userlist, count)>0) count++;
	}
    else if (menu_id==2) is_login = login(userlist, count);
    else if (menu_id==3) logout(&is_login);
    else if (menu_id==4) list(userlist, count);
    else if (menu_id==0) {
	break;
	}
    else{
	printf("No such command!!\n");
    }
  }
  save_file(userlist, count, argv[1]);
  return 0;
}
