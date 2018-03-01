#include <cstdio>
//#include <cstring>

struct man{
    char ID;
    int row,col,face,alive; //face = 1 代表脸为初始向，即下、右、右下
    float neili,wuyi,energy;
}mans[1000];

int num;

int fighted[12][12];
int table[12][12][3];
int tmp[26] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,1,1,1,1,1};

void initial_fighted(){
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 12; j++)
            fighted[i][j] = 0;
}

void inititial_table(){
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 12; j++)
            for(int k = 0; k < 3; k++)
                table[i][j][k] = 0;
}


int strength(int index){
    char c = mans[index].ID;
    float neili = mans[index].neili;
    float wuyi = mans[index].wuyi;
    float energy = mans[index].energy;
    float tmp = (energy+10.0)/100.0;
    if(c == 'S') return (int)( (0.5*neili + 0.5 * wuyi) * tmp );
    else if(c == 'W') return (int)( (0.8*neili + 0.2 * wuyi) * tmp );
    else return (int)( (0.2*neili + 0.8*wuyi) * tmp );
}

int find_man_index(int table_i,int table_j,int table_k){
    for(int i = 0; i < num; i++){
        if(table_k == tmp[mans[i].ID - 'A'] ){
            if(mans[i].row == table_i && mans[i].col == table_j) return i;
        }
    }
}

void a_man_one_step(int i){
    if(mans[i].alive == 0) return;

    if( mans[i].face == 1 && mans[i].ID == 'S'){
        if(mans[i].row < 11) mans[i].row ++;
        else mans[i].face = 0,mans[i].row--;
    }
    else if( mans[i].face == 0 && mans[i].ID == 'S'){
        if(mans[i].row > 0) mans[i].row--;
        else mans[i].face = 1,mans[i].row++;
    }

    else if( mans[i].face == 1 && mans[i].ID == 'W'){
        if(mans[i].col < 11) mans[i].col ++;
        else mans[i].face = 0,mans[i].col--;
    }
    else if( mans[i].face == 0 && mans[i].ID == 'W'){
        if(mans[i].col > 0) mans[i].col--;
        else mans[i].face = 1,mans[i].col++;
    }
    else if( (mans[i].row==0&&mans[i].col==11) || (mans[i].row==11&&mans[i].col==0) ) return;
    else if( mans[i].face == 1){
        if(mans[i].row < 11 && mans[i].col < 11) mans[i].row++,mans[i].col++;
        else mans[i].face = 0,mans[i].row--,mans[i].col--;
    }
    else if( mans[i].face == 0){
        if( mans[i].row > 0 &&  mans[i].col > 0) mans[i].row--,mans[i].col--;
        else mans[i].face = 1,mans[i].row++,mans[i].col++;
    }
}

void one_step(){
    int tmprow,tmpcol;
    for(int i = 0; i < num; i++){
        if(mans[i].alive == 0) continue;
        tmprow = mans[i].row;
        tmpcol = mans[i].col;
        a_man_one_step(i);
        table[tmprow][tmpcol][tmp[mans[i].ID-'A']]--;
        table[mans[i].row][mans[i].col][tmp[mans[i].ID-'A']]++;
    }
}

void two_men_fight(int man1, int man2){
    float energy1 = mans[man1].energy - strength(man2);
    float energy2 = mans[man2].energy - strength(man1);
    if(energy1 <= 0.0){
        mans[man1].alive = 0;
        table[mans[man1].row][mans[man1].col][tmp[mans[man1].ID-'A']]--;
    }
    else mans[man1].energy = energy1;
    if(energy2 <= 0.0){
        mans[man2].alive = 0;
        table[mans[man2].row][mans[man2].col][tmp[mans[man2].ID-'A']]--;
    }
    else mans[man2].energy = energy2;

}

void fight(){
    int tmp_i,tmp_j,tmp_ID;
    for(int i = 0; i < num; i++){
        tmp_i = mans[i].row,tmp_j = mans[i].col,tmp_ID = tmp[mans[i].ID - 'A'];
        if(fighted[tmp_i][tmp_j] == 1) continue;
        if(mans[i].alive && table[tmp_i][tmp_j][tmp_ID] == 1){
            if(table[tmp_i][tmp_j][(tmp_ID+1)%3] == 1 && table[tmp_i][tmp_j][(tmp_ID+2)%3] == 0){
                //printf("tmp_i = %d tmp_j = %d\n",tmp_i,tmp_j);
                int duishou = find_man_index(tmp_i,tmp_j,(tmp_ID+1)%3);
                two_men_fight(i,duishou);
                fighted[tmp_i][tmp_j] = 1;
            }
            else if(table[tmp_i][tmp_j][(tmp_ID+1)%3] == 0 && table[tmp_i][tmp_j][(tmp_ID+2)%3] == 1){
                //printf("tmp_i = %d tmp_j = %d\n",tmp_i,tmp_j);
                int duishou = find_man_index(tmp_i,tmp_j,(tmp_ID+2)%3);
                two_men_fight(i,duishou);
                fighted[tmp_i][tmp_j] = 1;
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    int t,N;
    scanf("%d",&t);
    while(t--){
        num = 0;
        inititial_table();
        scanf("%d",&N);
        while(1){
            getchar();
            scanf("%c",&mans[num].ID);
            if(mans[num].ID == '0') break;
            scanf("%d %d %f %f %f",&mans[num].row,&mans[num].col,&mans[num].neili,&mans[num].wuyi,&mans[num].energy);
            mans[num].row--,mans[num].col--;
            table[mans[num].row][mans[num].col][tmp[mans[num].ID-'A']]++;
            mans[num].face = 1;
            mans[num].alive = 1;
            num++;
        }

        initial_fighted(); //初始战斗
        fight();
        while(1){
            one_step();
            N--;
            if(N == 0) break;
            initial_fighted();
            fight();
        }

        int s_num = 0,w_num = 0,e_num = 0;
        float s_energy = 0.0,w_energy = 0.0,e_energy = 0.0;
        for(int i = 0; i < num; i++){
            if(mans[i].alive == 0) continue;
            //printf("%c %d %d %f\n",mans[i].ID,mans[i].row+1,mans[i].col+1,mans[i].energy);

            if(mans[i].ID == 'S'){
                s_num++;
                s_energy += mans[i].energy;
            }
            else if(mans[i].ID == 'W'){
                w_num++;
                w_energy += mans[i].energy;
            }
            else{
                e_num++;
                e_energy += mans[i].energy;
            }
        }
        printf("%d %.0f\n%d %.0f\n%d %.0f\n",s_num,s_energy,w_num,w_energy,e_num,e_energy);
        printf("***\n");
    }
    return 0;
}

