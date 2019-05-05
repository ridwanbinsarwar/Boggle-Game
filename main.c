#include <stdio.h>
#include <time.h>
#include <string.h>
#define NUM_WORDS 152
//011171184
int i,j,x,y,z1,z2,x1,y1,valid=1,move=0,p,o,no_double=0;
char ch[1000];

static const char *words[] = {"iil","aas" ,"aegis","aka","ake","akes","ash","ate","ates","ave","avel","aves",
                              "eas","ease","easel","eat","eave","eaves","egis","eisel","eish","elm","elt","eta","etas",
                              "evil","geat","geo","geos","ghi","gie","gies","gis","hie","hies","hilt","hive","hives","ilea",
                              "ish","iso","ivies","kaas","kae","kaes","kas","kat","kea","keas","kelt","kesh","ket","keta",
                              "ketas","kevil","koa","koas","kos","lea","leak","leas","lease","leash","leat","lei","lek","les",
                              "let","lev","leva","lie","lies","live","lives","mease","meat","mel","melt","mes","mesa","mese","mesh","met",
                              "meta","oak","oat","oaves","oes","oka","okas","oke","okes","okta","oaktas","ose","sae","sake","sat","sate","satem",
                              "sav","save","sea","seat","seg","sei","seil","sekt","sel","selva","set","seta","setae","shiel","shiv","shiva","shive",
                              "sigh","soak","soave","soke","tae","tael","taes","tak","taka","take","takes","tao","taos","tas","tash","tav","tavs","tea",
                              "teak","teas","tease","teil","tel","tes","vae","vaes","vas","vase","vat","veil","vet","vie","vies","vile","vlei","vlies"};

char board[5][5] = {' ', '1', '2', '3', '4',
                    '1',  'i', 'i', 'l', 'm',
                    '2',  'h', 'v', 'e', 't',
                    '3',  'g', 's', 'a', 'k',
                    '4',  'i', 'e', 'o', 'a'};
struct word{
    char temp[100];
}; struct word temp_word[100];

int saveWord()
{
    for(i=move; i<=move; i++)
    {
        strcpy(temp_word[i].temp,ch);
    }
}
int check(){
    for(i=0; i<=move; i++)
    {
        if(strcmp(temp_word[i].temp,ch)!=0)
            p=1;
        else
            no_double=1;
    }


}


int convertToSecond(int h, int m, int s){
    return h*3600 + m*60 + s;

}

int PrintBoard()
{
    printf("-1 -1 to Exit the game\n0 0 to submit word\n");

    printf("Playing move: %d:\n",move+1);
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Enter your move: ");
}

int SaveChar()
{
    ch[i]=board[x][y];
    if((x==0 && y==0))
    {
        ch[i]='\0';
        i=0;
    }
    return (ch);

}
int ValidMove_SaveChar(){

    SaveChar();
    if(i!=0 && (x!=0 && y!=0))

    {
        z1=abs(x-x1);
        z2=abs(y-y1);
        if((z1>1 || z1<0)|| (z2>1 || z2<0))
        {
            valid =0;

        }

    }
    return (valid);
}
//011171184

int main() {
    unsigned int count = 0;
    int z,c,k,n,found=0,m,point,scoring_moves=0,t_point=0,qw=1;
    char b_ch[1000];
    time_t t = time(NULL);
    struct tm start_time = *localtime(&t);
    int total_seconds = 0;


    for(i = 0; i < NUM_WORDS; i++){
        printf("%-5s ", words[i]);
    }
    printf("\n\n");

    PrintBoard();

    i=0;

    while(1){

        scanf("%d %d",&x,&y);
        ValidMove_SaveChar();
        puts(ch);

        if(x==-1 && y==-1)
        {
            t = time(NULL);
            struct tm end_time = *localtime(&t);
            total_seconds = (convertToSecond(end_time.tm_hour, end_time.tm_min, end_time.tm_sec) - convertToSecond(start_time.tm_hour, start_time.tm_min, start_time.tm_sec));
            break;
        }
        if ( x==0 && y==0)
        {
            check();
            saveWord();


            if (valid==0)
            {
                printf("You entered:");
                puts(ch);
                printf("invalid chain\n\n");
                qw =0;
            }

            else
            {
                printf("You entered:");
                puts(ch);
                if(no_double==1)
                    printf("Already Entered\n\n");
            }

            int len = strlen(ch);
            if ( len == 3) point =1;
            if (len == 4) point =1;
            if (len == 5) point =2;
            if (len == 6) point =3;
            if (len == 7) point =5;
            if (len >= 8) point =11;

            for(i = 0; i < 152; i++)
            {
                if (strcmp(ch,words[i]) !=0) m =0;

                else found = 1;

            }

            if(found == 0 && qw!=0)
            {
                printf("The word is not in our dictionary\n\n");
            }

            else if( found ==1 && no_double==0 &&valid!=0)
            {
                printf("good job. you scored %d points\n\n",point);
                scoring_moves++;
                t_point=t_point+point;
                if(scoring_moves==1)
                    strcpy(b_ch,ch);
                int ll= strlen(b_ch);
                if(len>ll)
                    strcpy(b_ch,ch);
            }
            move++;
            PrintBoard();

        }

        x1=x;
        y1=y;
        i++;
        if(x==0 && y==0){
            i=0;
            valid =1;
            no_double=0;
            found=0;
            qw=1;}
    }

    printf("The end.\n\n");

    printf("Total time taken: %d seconds.\n", total_seconds);
    printf("total moves: %d\n",move);
    printf("Total non-scoring moves: %d\n",move-scoring_moves);
    printf("Total scoring moves: %d\n",scoring_moves);
    printf("Total points: %d\n",t_point);
    printf("Average time per move: %d seconds/move\n",total_seconds/move);
    printf("Best Word:");
    puts(b_ch);

}
//011171184
