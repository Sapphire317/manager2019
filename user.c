#include "user.h"

int load_file(LOGIN* list[], char* filename){
  int count=0;
  FILE *datafile = fopen(filename, "r");
  //Check if file is exist
  if(datafile==NULL){
	int cmd;
		printf("%s file not exist!", filename);
		printf(" make anyway? (Yes 1, No 2) >> ");
		scanf("%d", &cmd);
	
	//if yes, new file will be created
	if(cmd==1){
  		datafile = fopen(filename, "w+");
		
	}else 
		return -1;
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
  if(count>0){
  printf("> Welcome!! %d records read!\n",count);
  }else{

  printf("> Welcome!!\n");
}
  fclose(datafile);
  return count;
}

int join(LOGIN* list[], int count){
  char id[20], pass[20];
//  printf("count: %d\n", count);
  while(1){
    printf("Enter new user id : ");
    scanf("%s", id);
    int dup=0;
    for(int i=0;i<count;i++){
      if(strcmp(id, list[i]->id)==0) {
        dup=1; break;
      }
    }
    if(dup==1){
      printf("Already exist!!\n");
	return -1;
    }
    else{
      printf("Enter password : ");
      scanf("%s", pass);
      list[count] = (LOGIN*)malloc(sizeof(LOGIN));
      strcpy(list[count]->id, id);
      strcpy(list[count++]->password, pass);
#ifdef DEBUG_MODE
	printf("DEBUG >>\n id : %s \n password: %s \n count: %d", list[count-1]->id, list[count-1]->password, count);
#endif
      printf("New user added!\n");
      break;
    }
}
return 1;
}
int login(LOGIN* list[], int count){
  char id[20], pass[20];
  printf("Enter user id : ");
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
    printf("No such user!!\n");
    return 0;
  }
  else{
    printf("Enter password : ");
    scanf("%s", pass);
    if(strcmp(list[found]->password, pass)==0){
      printf("Welcome %s!!\n", id);
      return 1;
    }
    else{
      printf("Password incorrect!\n");
      return 0;
    }
  }
}

void list(LOGIN* list[], int count){
 
printf("User list (id/password)\n");

for(int i=0; i<count; i++){
	printf("[%d] %s / %s\n", i+1, list[i]->id, list[i]->password);
}
}
void logout(int* is_login){
  *is_login = 0;
  printf("Bye!\n");
}

void save_file(LOGIN* list[], int count, char* filename){
  FILE *datafile = fopen(filename, "w");
  for(int i=0; i<count; i++){
    fprintf(datafile, "%s %s\n", list[i]->id, list[i]->password);
  }
  printf("%d records saved to %s!\n", count, filename);
  fclose(datafile);
}
