#include<stdio.h>
#include<string.h>
#include<direct.h>
char vorodi[100];
FILE* demo;
void create(){
        int a;
        char flag;
        char input;
        int lim;
    char name[100];
    memset(name,'\0',sizeof(name));
    scanf("%c",&flag);
    if(flag == '"'){
            scanf("%c",&input);
           while(1){
                int i = 0;
                input = '0';
            while(1){
                scanf("%c",&input);
            name[i] = input;
            i++;
            if(input == '\n' || input == '/' || input == '"'){
                break;
            }
            }
            lim = i;
                char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if (chdir(name) != 0){
                mkdir(name);
              }
              chdir(name);
         for(int j = 0;j < i;i++){
            name[j] = '\0';
        }

        }
        name[lim] = '\0';
                 if(fopen(name,"r")!= NULL){
        printf("The file already exists.\n");
        return;
    }
    else{
            fclose(demo);
       demo = fopen(name,"w");
        fclose(demo);
        return;
    }
    }
    else if(flag == '/'){
        while(1){
                int i = 0;
                input = '0';
            while(1){
                scanf("%c",&input);
            name[i] = input;
            i++;
            if(input == '\n' || input == '/'){
                break;
            }
            }
            lim = i;
                char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p != NULL){
                    break;
                }
              if (chdir(name) != 0){
                mkdir(name);
              }
              chdir(name);
        for(int j = 0;j < i;i++){
            name[j] = '\0';
        }
        }
            printf("%s",name);
         if(fopen(name,"r") != NULL){
        printf("The file already exists.\n");
        return;
    }
    else{
        fclose(demo);
      demo = fopen(name,"w");
        fclose(demo);
        return;
    }
    }

}
int main(){
    mkdir("root");
    chdir("root");
    create();
}
