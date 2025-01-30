#include <stdio.h>
#include <string.h>

int ascii[]={48,49,50,51,52,53,54,55,56,57};
int sum = 0;

char left(char* ch);
char right(char* ch);
void process(char* ch);

int main(void){
    FILE *file = fopen("document.txt","r");
    char line[500];

    while (fgets(line, sizeof(line), file) != NULL){
        process(&line[0]);
    }
    
    printf("Sum = %d",sum);
    fclose(file);     
}

char left(char* ch){
    for (int i = 0; i < strlen(ch); i++){
        for (int j = 0; j < 10; j++){
            if (ch[i] == ascii[j]){
                return ch[i];
            }
        }
    }
}

char right(char* ch){
    for (int i = strlen(ch)-1; i >= 0; i--){
        for (int j = 0; j < 10; j++){
            if (ch[i] == ascii[j]){
                return ch[i];
            }
        }
    }
}

void process(char* ch){
    char txt[2];
    sprintf(txt,"%c%c",left(&ch[0]),right(&ch[0]));
    sum += (txt[0]-48)*10 + (txt[1]-48);
}