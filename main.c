#include<stdio.h>
#include<string.h>
#include<direct.h>
char vorodi[100];
FILE* demo,*demo1;
const int  MAX_ARG_PARAM_SIZE=20;
const char* ROOT_DIRECTORY ="D:\\root";
const char* ACCEPT_COMMANDS[]={"insertstr","cat"};
char cwdbuff[1000];

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
                if(address[addcounter] == '/' || address[addcounter] == '\n'){
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
        //fclose(demo);
        name[strlen(name)-1] = '\0';
      demo = fopen(name,"r+");
      char ch;
      char ch_before;
      int totalpos = 1;
      int rowen = 1;
      int powen = 0;
      int flagmatn = 0;
      demo1 = fopen("temp.txt","w");
      while(1){
            ch_before = ch;
            if(flagmatn == 1){
                for(int i = 0;i < matnlen;i++){
                    if(matn[i] == 92 && matn[i+1] == 10){
                        fprintf(demo1,"\\n");
                        i++;
                    }
                    else{
                        fprintf(demo1,"%c",matn[i]);
                    }
                }
                flagmatn = 0;
            }
            if(flagmatn == 0){
           fscanf(demo,"%c",&ch);
           if(ch == EOF){
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
           else{
            powen++;
            fprintf(demo1,"%c",ch);
           }
           if(powen == pos && rowen == line){
            flagmatn = 1;
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
        //fclose(demo);
        name[strlen(name)-1] = '\0';
      demo = fopen(name,"r+");
      char ch;
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
                fscanf(demo,"%c",&ch);
                if(ch == EOF){
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
           else{
            powen++;
            fprintf(demo1,"%c",ch);
           }
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
            }
            else if(flag == 'f'){
                if(ch == EOF){
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
           else{
            powen++;
           }
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
            }
      }
      fseek(demo,0,SEEK_SET);
      ch = NULL;
      ch_before = NULL;
      long long int jaigahenc = 1;
      while(1){
        ch = ch_before;
        jaigahenc = ftell(demo);
             fscanf(demo,"%c",&ch);
                if(ch == EOF){
            break;
           }
           if(ch == 10){
                if(ch_before != 92){
                    rowen++;
                    powen = 0;
                    printf("\n");
                }
           else{
            powen++;
            printf("\\n");
           }
           }
           else{
            powen++;
            fprintf(demo1,"%c",ch);
           }
           if(jaigahenc == jaigah){
            fseek(demo,sized,SEEK_CUR);
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
                if(address[addcounter] == '/' || address[addcounter] == '\n'){
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
        char ch;
        char ch_before;
        while(1){
            ch_before = ch;
            fscanf(demo,"%c",&ch);
        if(ch == EOF){
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
           else{
            fprintf(demo1,"%c",ch);
           }
        }
    }
}
}
int main(){
chdir("C:\\Users\\ASUS\\Documents\\cblock\\tamroin7\\vim");
char* add = "/root/skd/ali.txt\n";
int pos = 0;
int row = 1;
char* matn = "test";
insert(add,row,pos,matn);

        return 0;
}


