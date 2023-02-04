#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<direct.h>
#include <unistd.h>
#include <errno.h>

char vorodi[100];
FILE* demo,*demo1,*demo2;
const int  MAX_ARG_PARAM_SIZE=20;
const char* ROOT_DIRECTORY ="D:\\root";
const char* ACCEPT_COMMANDS[]={"insertstr","cat"};
char cwdbuff[1000];
int terminate = 0;
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
             name[strlen(name)-1] = '\0';
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
              if ((chdir(name)) != 0){
                mkdir(name);
              }
              chdir(name);
        for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
        }

         if(fopen(name,"r") != NULL){
        printf("The file already exists.\n");
        return;
    }
    else{
        //fclose(demo);
        name[strlen(name)-1] = '\0';
      demo = fopen(name,"w");
        fclose(demo);
        return;
    }
    }

}
void insert(char* address,int line,int pos,char* matn){
int address_len = strlen(address);
int matnlen = strlen(matn);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || address[addcounter] == '\n' || addcounter > address_len){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;

        }
         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) != 0){
                printf("Path is invalid.\n");
                return;
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }


    }

         if(fopen(name,"r") == NULL){
        printf("The file doesn't exist.\n");
        return;
    }
    else{
        fclose(demo);
        name[strlen(name)] = '\0';
      demo = fopen(name,"r");
      fseek(demo,0,SEEK_SET);
      char ch = '~';
      char ch_before;
      int totalpos = 1;
      int rowen = 1;
      int powen = 0;
      int flagmatn = 2;
      demo1 = fopen("temp.txt","w");
      while(1){
            ch_before = ch;

            if(powen == pos && rowen == line){
             for(int i = 0;i < matnlen;i++){
                    if(matn[i] == 92 && matn[i+1] == 10){
                        fprintf(demo1,"\\n");
                        i++;
                    }
                     if(matn[i] == 92 && matn[i+1] == 92){
                        fprintf(demo1,"\\");
                        i++;
                    }
                    else{
                        fprintf(demo1,"%c",matn[i]);
                    }
             }
           }
             flagmatn = fscanf(demo,"%c",&ch);
           if(ch == EOF || flagmatn == 0 || ch == '~'){

            break;
           }
          else if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;
                    fprintf(demo1,"\n");
                }
           else{
            powen++;
            fprintf(demo1,"\\n");
           }
           }
           else if(ch == 92){
            powen++;
           }
           else{
            powen++;
            fprintf(demo1,"%c",ch);
           }
      }
        fclose(demo1);
        fclose(demo);
       /* char uname[strlen(name+1)];
        for(int i = 0;i < strlen(name);i++){
            uname[i] = '\0';
        }
        for(int i = 0;i < strlen(name);i++){
            uname[i] = name[i];
        }
        uname[strlen(name)-3] = 'u';
        rename(name,uname);*/
        int test = remove(name);
         rename("temp.txt",name);
        return;
    }


}
}
void removing(char* address,int line,int pos,int sized,char flag){
int strlength = strlen(address);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || addcounter >= strlength){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;
            name[i] = '\0';

        }
         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) != 0){
            printf("Path is invalid.\n");
                return;
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
    }

         if(fopen(name,"r") == NULL){

        printf("The file doesn't exist.\n");
        return;
    }
    else{
        fclose(demo);
        name[strlen(name)] = '\0';
      demo = fopen(name,"r");
      char ch = '~';
      int test;
      char ch_before;
      long long int jaigah;
      fseek(demo,0,SEEK_END);
      long long int payan = ftell(demo);
      fseek(demo,0,SEEK_SET);
      int rowen = 1;
      int powen = 0;
      demo1 = fopen("temp.txt","w");
      while(1){
            ch_before = ch;
            if(flag == 'b'){
                    if(powen == pos && rowen == line){
            jaigah = ftell(demo);
            jaigah = jaigah - sized;
            if(jaigah < 0){
                printf("not enough characters\n");
                fclose(demo);
                fclose(demo1);
                return;
            }
            break;
           }
               test = fscanf(demo,"%c",&ch);
                if(ch == EOF || test < 1){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;

                }
           else{
            powen++;
           }
           }
           else if(ch == 92){

           }
           else{
            powen++;
           }
            }
            else if(flag == 'f'){
                    if(powen == pos && rowen == line){
            jaigah = ftell(demo);
            jaigah = jaigah + sized;
            if(jaigah > payan){
                printf("not enough characters\n");
                fclose(demo);
                fclose(demo1);
                return;
            }
            jaigah = jaigah - sized;
            break;
           }
           test = fscanf(demo,"%c",&ch);
                if(ch == EOF || test < 1){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;

                }
           else{
            powen++;
           }
           }
           else if(ch == 92){

           }
           else{
            powen++;
           }

            }
      }
      fseek(demo,0,SEEK_SET);
      ch = NULL;
      ch_before;
      long long int jaigahenc = 1;
      while(1){
        ch = ch_before;
        jaigahenc = ftell(demo);
         if(jaigahenc == jaigah){
            fseek(demo,sized,SEEK_CUR);
           }
            test = fscanf(demo,"%c",&ch);
                if(ch == EOF || test < 1){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;
                    fprintf(demo1,"\n");
                }
           else{
            powen++;
            fprintf(demo1,"\\n");
           }
           }
           else if(ch == 92){

           }
           else{
            powen++;
            fprintf(demo1,"%c",ch);
           }
        }

      }
        fclose(demo1);
        fclose(demo);
        remove(name);
        rename("temp.txt",name);
        printf("ok");
        return;
    }

}
void cat(char* address){
int address_len = strlen(address);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || address[addcounter] == '\n' || address_len < addcounter){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;
                name[i] = '\0';
        }

         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) != 0){
                printf("Path is invalid.\n");
                return;
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
    }

         if(fopen(name,"r") == NULL){
        printf("The file doesn't exist.\n");
        return;
    }
    else{
        demo = fopen(name,"r");
        char ch = '~';
        char ch_before;
        int test;
        while(1){
            ch_before = ch;
           test = fscanf(demo,"%c",&ch);
        if(ch == EOF || ch == '~' || test < 1){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    printf("\n");
                }
           else{
            printf("\\n");
           }
           }
           else if(ch == 92){

           }
           else{
            printf("%c",ch);
           }
        }
    }
}
}
void copying(char* address,int pos,int line,int sized,char flag){
    demo1 = fopen("copy.txt","w");
int strlength = strlen(address);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || addcounter >= strlength){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;
            name[i] = '\0';

        }
         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) != 0){
                printf("Path is invalid.\n");
                return;
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
    }

         if(fopen(name,"r") == NULL){
        printf("The file doesn't exist.\n");
        return;
         }
    else{
      demo = fopen(name,"r");
       char ch;
      char ch_before;
      long long int jaigah;
      fseek(demo,0,SEEK_END);
      long long int payan = ftell(demo);
      fseek(demo,0,SEEK_SET);
      int rowen = 1;
      int powen = 0;
      int test;
      while(1){
            ch_before = ch;
            if(flag == 'b'){
                    if(powen == pos && rowen == line){
            jaigah = ftell(demo);
            jaigah = jaigah - sized;
            if(jaigah < 0){
                printf("not enough characters\n");
                fclose(demo);
                fclose(demo1);
                return;
            }
            break;
           }
               test = fscanf(demo,"%c",&ch);
                if(ch == EOF || test < 1){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;

                }
           else{
            powen++;
           }
           }
           else if(ch == 92){

           }
           else{
            powen++;
           }
            }
            else if(flag == 'f'){
                    if(powen == pos && rowen == line){
            jaigah = ftell(demo);
            jaigah = jaigah + sized;
            if(jaigah > payan){
                printf("not enough characters\n");
                fclose(demo);
                fclose(demo1);
                return;
            }
            jaigah = jaigah - sized;
            break;
           }
                    test = fscanf(demo,"%c",&ch);
                if(ch == EOF || test < 1){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;

                }
           else{
            powen++;
           }
           }
           else if(ch == 92){

           }
           else{
            powen++;
           }
            }
      }
      fseek(demo,jaigah,SEEK_SET);
        ch_before = NULL;
        ch = NULL;
        for(int i = 0;i < sized;i++){
                ch_before = ch;
            fscanf(demo,"%c",&ch);
            if(ch == 10 && ch_before != 92){
                fprintf(demo1,"\n");
            }
            else if(ch == 10 && ch_before == 92){
                fprintf(demo1,"\\n");
            }
            else if(ch == 92 && ch_before == 92){
                fprintf(demo1,"\\");
            }
            else if(ch == 92){

            }
            else{
                fprintf(demo1,"%c",ch);
            }
        }
        fclose(demo);
        fclose(demo1);
        return;
      }
}
}
void cut(char* address,int line,int pos,int sized,char flag){
copying(address,line,pos,sized,flag);
chdir("D:\\root");
removing(address,line,pos,sized,flag);
return;
}
void pasteing(char* address,int line,int pos){
if(fopen("copy.txt","r") == NULL){
    printf("clipboard is empty\n");
    return;
}
else{
        fopen("copy.txt","r");
    int strlength = strlen(address);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || addcounter >= strlength){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;
            name[i] = '\0';

        }
         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) != 0){

                printf("Path is invalid.\n");
                return;
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
    }

         if(fopen(name,"r") == NULL){

        printf("The file doesn't exist.\n");
        return;
    }
    else{
    demo = fopen(name,"r");
    demo2 = fopen("temp.txt","w");
    char ch;
    int flag = 0;
    char ch_before;
    int powen = 0;
    int rowen = 1;
    int test;
     while(1){
            ch_before = ch;
            if(flag == 0){
                test = fscanf(demo,"%c",&ch);
            }
            if(flag == 1){
                test = fscanf(demo1,"%c",&ch);
            }
                if((ch == EOF || test < 1)  && flag == 0){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;
                    fprintf(demo2,"\n");

                }
           else{
            powen++;
            fprintf(demo2,"\\n");
           }
           }
           else if(ch == 92){
            if(ch_before == 92){
                fprintf(demo2,"\\");
            }
           }
           else{
            powen++;
            fprintf(demo2,"%c",ch);
           }
           if(powen == pos && rowen == line){
                flag = 1;
            }
            if((ch == EOF || test < 1) && flag == 1){
                flag = 0;
                powen++;
            }
}
fclose(demo);
fclose(demo1);
fclose(demo2);
remove(name);
rename("temp.txt",name);
return;
    }
    }
}
}
finding(char* str,char* address,char flag){
int strlength = strlen(address);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || addcounter == strlength){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;

        }
         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) == 0){
              mkdir(name);
                /*printf("Path is invalid.\n");
                return;*/
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
    }

         if(fopen(name,"r") == NULL){
                fopen(name,"w");
        /*printf("The file doesn't exist.\n");
        return;*/
    }
    else{
    demo = fopen(name,"r");
    if(flag == 'n'){

    }
    }

}}
void autoing(char* address){
int address_len = strlen(address);
int addcounter = 0;
char name[50];
char buff[1000];
if(address[0] == '/'){
    while(1){
        int i = 0;
        addcounter++;
        while(1){
                if(address[addcounter] == '/' || address[addcounter] == '\n' || address_len < addcounter){
                        i++;
                    break;
                }
            name[i] = address[addcounter];
            i++;
            addcounter++;
                name[i] = '\0';
        }

         char s2[] = ".txt";
                char* p = strstr(name,s2);
                if(p){
                    break;
                }
              if(chdir(name) != 0){
                printf("Path is invalid.\n");
                return;
              }
              chdir(name);
         for(int j = 0;j < i;j++){
            name[j] = '\0';
        }
    }

         if(fopen(name,"r") == NULL){
        printf("The file doesn't exist.\n");
        return;
    }
    else{
        demo = fopen(name,"r");
        demo1 = fopen("auto.txt","w");
        char ch;
        char ch_before;
        char ch_bbf;
        int test;
        while(1){
                ch_bbf = ch_before;
                ch_before = ch;
            test = fscanf(demo,"%c",&ch);
            if(test < 1){
                break;
            }
            if(ch == '{'){
                if(ch_before != ' '){
                    fprintf(demo1," {");
                }
                else{
                    fprintf(demo1,"{");
                }

                    fprintf(demo1,"\n\t");

            }
            else if(ch == '}'){
                if(ch_before != ' '){
                    fprintf(demo1,"/n}/n");
                }
                else{
                    fprintf(demo1,"/n}/n");
                }
            }
            else if(ch == 10){
                if(ch_before == 92){
                    fprintf(demo1,"\\n");
                }
                else{
                    fprintf(demo1,"\n");
                }
            }
            else if(ch == 92){
                if(ch_before == 92){
                    fprintf(demo1,"\\");
                }
            }
            else{
                fprintf(demo1,"%c",ch);
            }
        }
    }
    fclose(demo);
    fclose(demo1);
    remove(name);
    rename("auto.txt",name);
    return;
}
}
void reader(char* dastoor){
    char tag[100];
    char vorodi[10000];
    char address[1000];
    char str[1000];
    char pos[1000];
    char sized[1000];
char fake = getchar();
if(!strcmp(dastoor,"create")){
    scanf("%s",tag);
    if(!strcmp(tag,"-file")){
            getchar();
        create();
    }
    else{
        gets(vorodi);
        printf("did you mean -file?\n");
        return;
    }
}
if(!strcmp(dastoor,"insert")){
    int posi = 0;
    int line = 0;
    int jaigah;
    gets(vorodi);
    int counter = 0;
    char* bakhsh = strtok(vorodi,"-");
    int t = strlen(bakhsh);
    if(bakhsh[5] == '"'){
        strncpy(address,bakhsh+6,t-8);
    }
    else{
    strncpy(address,bakhsh+5,t-6);
    }
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(str,bakhsh+4,t-5);
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(pos,bakhsh+4,t-4);
    for(int i = 0;i < strlen(pos);i++){
        if(pos[i] == ':'){
         jaigah = i;
         break;
        }
    }
    for(int i = jaigah+1;i < t-4;i++){
        posi = posi*10;
        posi += pos[i]-'0';
    }
    for(int i = 0;i < jaigah;i++){
        line *= 10;
        line += pos[i] - '0';
    }
   insert(address,line,posi,str);
}
if(!strcmp(dastoor,"remove")){
    int posi = 0;
    int line = 0;
    int jaigah;
    gets(vorodi);
    int counter = 0;
    char* bakhsh = strtok(vorodi,"-");
    int t = strlen(bakhsh);
    if(bakhsh[5] == '"'){
        strncpy(address,bakhsh+6,t-8);
        printf("%s",address);
    }
    else{
    strncpy(address,bakhsh+5,t-6);
    }
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(pos,bakhsh+4,t-4);
    for(int i = 0;i < strlen(pos);i++){
        if(pos[i] == ':'){
         jaigah = i;
         break;
        }
    }
    for(int i = jaigah+1;i < t-5;i++){
        posi = posi*10;
        posi += pos[i]-'0';
    }
    for(int i = 0;i < jaigah;i++){
        line *= 10;
        line += pos[i] - '0';
    }
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(sized,bakhsh+5,t-5);
    int ss = atoi(sized);
    bakhsh = strtok(NULL,"-");
    char flagi = bakhsh[0];
    removing(address,line,posi,ss,flagi);

}
if(!strcmp(dastoor,"cat")){
    scanf("%s",tag);
    if(strcmp("-file",tag)){
        printf("did you mean tag?\n");
        return;
    }
    getchar();
    gets(vorodi);
    if(vorodi[0] == '"'){
        strncpy(address,vorodi+1,strlen(vorodi)-2);
        cat(address);
        return;
    }
    else{
            cat(vorodi);
    return;
    }
}
if(!strcmp(dastoor,"copy")){
    gets(vorodi);
    int posi = 0;
    int line = 0;
    int jaigah;
    gets(vorodi);
    int counter = 0;
    char* bakhsh = strtok(vorodi,"-");
    int t = strlen(bakhsh);
    if(bakhsh[5] == '"'){
        strncpy(address,bakhsh+6,t-8);
        printf("%s",address);
    }
    else{
    strncpy(address,bakhsh+5,t-6);
    }
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(pos,bakhsh+4,t-4);
    for(int i = 0;i < strlen(pos);i++){
        if(pos[i] == ':'){
         jaigah = i;
         break;
        }
    }
    for(int i = jaigah+1;i < t-4;i++){
        posi = posi*10;
        posi += pos[i]-'0';
    }
    for(int i = 0;i < jaigah;i++){
        line *= 10;
        line += pos[i] - '0';
    }
    bakhsh = strtok(NULL,"-");
     t = strlen(bakhsh);
    strncpy(sized,bakhsh+5,t-5);
    int ss = atoi(sized);
    bakhsh = strtok(NULL,"-");
    char flagi = bakhsh[0];
    copying(address,posi,line,ss,flagi);
}
if(!strcmp(dastoor,"cut")){
    gets(vorodi);
    int posi = 0;
    int line = 0;
    int jaigah;
    gets(vorodi);
    int counter = 0;
    char* bakhsh = strtok(vorodi,"-");
    int t = strlen(bakhsh);
    if(bakhsh[5] == '"'){
        strncpy(address,bakhsh+6,t-8);
        printf("%s",address);
    }
    else{
    strncpy(address,bakhsh+5,t-6);
    }
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(pos,bakhsh+4,t-4);
    for(int i = 0;i < strlen(pos);i++){
        if(pos[i] == ':'){
         jaigah = i;
         break;
        }
    }
    for(int i = jaigah+1;i < t-4;i++){
        posi = posi*10;
        posi += pos[i]-'0';
    }
    for(int i = 0;i < jaigah;i++){
        line *= 10;
        line += pos[i] - '0';
    }
    bakhsh = strtok(NULL,"-");
     t = strlen(bakhsh);
    strncpy(sized,bakhsh+5,t-5);
    int ss = atoi(sized);
    bakhsh = strtok(NULL,"-");
    char flagi = bakhsh[0];
    cut(address,posi,line,ss,flagi);
}
if(!strcmp(dastoor,"paste")){
     int posi = 0;
    int line = 0;
    int jaigah;
    gets(vorodi);
    int counter = 0;
    char* bakhsh = strtok(vorodi,"-");
    int t = strlen(bakhsh);
   if(bakhsh[5] == '"'){
        strncpy(address,bakhsh+6,t-8);
        printf("%s",address);
    }
    else{
    strncpy(address,bakhsh+5,t-6);
    }
    bakhsh = strtok(NULL,"-");
    t = strlen(bakhsh);
    strncpy(pos,bakhsh+4,t-4);
    for(int i = 0;i < strlen(pos);i++){
        if(pos[i] == ':'){
         jaigah = i;
         break;
        }
    }
    for(int i = jaigah+1;i < t-5;i++){
        posi = posi*10;
        posi += pos[i]-'0';
    }
    for(int i = 0;i < jaigah;i++){
        line *= 10;
        line += pos[i] - '0';
    }
    pasteing(address,line,posi);
}
if(!strcmp(dastoor,"auto")){
    scanf("%s",tag);
    if(strcmp("-file",tag)){
        printf("did you mean tag?\n");
        return;
    }
    getchar();
    gets(vorodi);
    if(vorodi[0] == '"'){
        strncpy(address,vorodi+1,strlen(vorodi)-2);
        autoing(address);
        return;
    }
    else{
            autoing(vorodi);
    return;
    }
}
if(!strcmp(dastoor,"end")){
    terminate = 1;
    return;
}
else{
    printf("invalid command\n");
    return;
}
}
int main(){
    chdir("D:\\root");
while(1){
    scanf("%s",vorodi);
    reader(vorodi);
    chdir("D:\\root");
    if(terminate == 1){
        printf("program closed");
        break;
    }
}
        return 0;
}


