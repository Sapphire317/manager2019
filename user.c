#include "user.h"

int load_file(LOGIN* list[], char* filename){
  int count=0;
  FILE *datafile = fopen(filename, "r");
  //Check if file is exist
  if(datafile==NULL){
	char cmd;
		printf("There is no such file!\n");
		printf("Do you want to make new file? (y/n)\n");
		scanf("%c", &cmd);
	
	//if yes, new file will be created
	if(cmd =='Y' || cmd=='y'){
  		datafile = fopen(filename, "w+");
	}else if(cmd =='N' || cmd == 'n'){
		return -1;
	}else{
		printf("Wrong command!\n");
		return -1;
	}
	}
 char buff[100];

#ifdef DEBUG_MODE
	printf("DEBUG >>File opened!\n");
#endif
 while(fgets(buff, 100, datafile)!=NULL){
//	printf("buff: %s\n", buff);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
	int len = strlen(buff);
	for(int i=0; i<len; i++){
		if(buff[i]=='\n')buff[i]=0;
	}
	char *ptr;
	ptr=strtok(buff," ");
	strcpy(list[count]->id, ptr);

	ptr = strtok(NULL, " ");
	strcpy(list[count]->password, ptr);	
    count++;
  }
  printf("%d records read!\n",count);
  fclose(datafile);
  return count;
}

int join(LOGIN* list[], int count){
printf("*=========JOIN=========*\n");
  char id[20], pass[20];
//  printf("count: %d\n", count);
  while(1){
    printf("Enter new user id > ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Error : Already exist!!\n");
	return -1;
    }
    else{
      printf("Enter password > ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id);
      strcpy(list[count++]->password, pass);
#ifdef DEBUG_MODE
	printf("DEBUG >>\n id : %s \n password: %s \n count: %d", list[count-1]->id, list[count-1]->password, count);
#endif
      printf("Message : New user added!\n");
      break;
    }
}
return 1;
}
int login(LOGIN* list[], int count){
printf("*=========LOGIN=========*\n");
  char id[20], pass[20];
  printf("Enter user id > ");
  scanf("%s", id);
  int dup=0, found;
  for(int i=0;i<count;i++){
    if(strcmp(id, list[i]->id)==0) {
      dup=1;
      found = i;
      break;
    }
  }
  if(dup!=1){
    printf("Error : No such user!!\n");
    return 0;
  }
  else{
    printf("Enter password > ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Error : Password incorrect!!\n");
      return 0;
    }
  }
}

void list(LOGIN* list[], int count){

printf("*=========LIST=========*\n");

for(int i=0; i<count; i++){
	printf("# : %d\n", i);
	printf("id : %s\n", list[i]->id);
	printf("Password : %s\n", list[i]->password);
}
}
void logout(int* is_login){
  *is_login = 0;
  printf("Message : Logout!!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("Message : %s Saved!\n", filename);
  fclose(datafile);
}
