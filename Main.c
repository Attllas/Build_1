#include <stdio.h>
#include<stdlib.h>

struct Build {
    int Nivel;
    int Forca;
    int Vitalidade;
    int Constituicao;
    int Inteligencia;
    int Feiticaria;
    int Foco;
    int Agilidade;
    int Sorte;
};

void Imprime_build(struct Build Build, int i);
int Calc_Vida(int Forca, int Vitalidade, int Constituicao);
int Calc_Mana(int Feiticaria, int Foco, int Inteligencia);
int Calc_Dano(int Forca, int Agilidade, int Sorte);
int Calc_Defesa( int Sorte, int Constituicao);
int Calc_DanoMagico(int Inteligencia, int Feiticaria);
int Calc_DefesaMagica(int Inteligencia, int Foco);
float Calc_VelocidadeAtaque(int Agilidade, int Sorte);

int main(){
    int n, i, aux;
    int *vida, *mana, *dano, *defesa, *danomag, *defmag, *critico;
    float *velocidade;
struct Build *User;
printf("Quantas Builds voce vai querer testar?");
scanf("%i", &n);
User = (struct Build *) malloc(n*sizeof(struct Build));
for (i = 0; i < n; i++){
NV: printf("\nQuanto de Nivel o personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Nivel);
aux=User[i].Nivel;
if(aux>=101 || aux<=0){
    puts("Valor invalido, tente novamente.\n");
    goto NV;
}
            FOR: printf("\nQuanto de Forca  personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Forca);
aux=aux-User[i].Forca;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Forca;
    goto FOR;
}
            VIT: printf("Quanto de Vitalidade personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Vitalidade);
aux=aux-User[i].Vitalidade;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Vitalidade;
    goto VIT;
}
            COS: printf("Quanto de Constituicao personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Constituicao);
aux=aux-User[i].Constituicao;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Constituicao;
    goto COS;
}
            INT: printf("Quanto de Inteligencia personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Inteligencia);
aux=aux-User[i].Inteligencia;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Inteligencia;
    goto INT;
}
            FET: printf("Quanto de Feiticaria personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Feiticaria);
aux=aux-User[i].Feiticaria;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Feiticaria;
    goto FET;
}
           FOC: printf("Quanto de Foco personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Foco);
aux=aux-User[i].Foco;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Foco;
    goto FOC;
}
           AGI: printf("Quanto de Agilidade personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Agilidade);
aux=aux-User[i].Agilidade;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
    aux=aux+User[i].Agilidade;
    goto AGI;
}
           SOR: printf("Quanto de Sorte personagem %i tem seu personagen?", i+1);
scanf("%i", &User[i].Sorte);
aux=aux-User[i].Sorte;
if(aux<0){
    puts("Valor invalido, tente novamente.\n");
         aux=aux+User[i].Sorte;
    goto SOR;
}
if(aux>0){
    printf("Voce deixou de destribuir %i pontos", aux);
}}
 vida = (int *)malloc(n * sizeof(int));
 mana = (int *)malloc(n * sizeof(int));
 dano = (int *)malloc(n * sizeof(int));
 defesa = (int *)malloc(n * sizeof(int));
 danomag = (int *)malloc(n * sizeof(int));
 defmag= (int *)malloc(n * sizeof(int));
 velocidade=(float*) malloc (n * sizeof(float));
 critico= (int *)malloc(n * sizeof(int));
for (i = 0; i < n; i++){
vida[i]= Calc_Vida(User[i].Forca, User[i].Vitalidade, User[i].Constituicao);
mana[i]= Calc_Mana(User[i].Feiticaria, User[i].Foco, User[i].Inteligencia);
dano[i]= Calc_Dano(User[i].Forca, User[i].Agilidade, User[i].Sorte);
defesa[i]= Calc_Defesa( User[i].Sorte, User[i].Constituicao);
danomag[i]= Calc_DanoMagico(User[i].Inteligencia, User[i].Feiticaria);
defmag[i]= Calc_DefesaMagica(User[i].Inteligencia,  User[i].Foco);
velocidade[i]= Calc_VelocidadeAtaque(User[i].Agilidade, User[i].Sorte);
critico[i]= User[i].Sorte;
Imprime_build(User[i], i);
printf("\nE os status do seu heroi %i sao:\nVida: %i\nMana:%i\nDano Fisico: %i\nDefesa Fisica: %i\nDano Magico: %i\nDefesa Magica: %i\nVelocidade de Ataque: %f ataques por segundo\nCritico: %i%% de chance", i+1, vida[i], mana[i], dano[i], defesa[i], danomag[i], defmag[i], velocidade[i], critico[i]);
}
free(User);
free(vida);
free(mana);
free(dano);
free(defesa);
free(danomag);
free(defmag);
free(velocidade);
free(critico);
return 0;

}

void Imprime_build(struct Build Build, int i){
printf("\nA Build do heroi %i eh:\nForca: %i\nVitalidade: %i\nConstituicao: %i\nInteligencia: %i\nFeiticaria: %i\nFoco: %i\nAgilidade: %i\nSorte: %i", i+1, Build.Forca, Build.Vitalidade, Build.Constituicao, Build.Inteligencia, Build.Feiticaria, Build.Foco, Build.Agilidade, Build.Sorte );
}

int Calc_Vida(int Forca, int Vitalidade, int Constituicao){
    return Forca*25+Vitalidade*15+Constituicao*5+500;
};

int Calc_Mana(int Feiticaria, int Foco, int Inteligencia){
    return Feiticaria*10+Foco*6+Inteligencia*3+100;
};

int Calc_Dano(int Forca, int Agilidade, int Sorte){
    return Forca*5+Agilidade+Sorte+10;
};

int Calc_Defesa( int Sorte, int Constituicao){
    return Sorte+Constituicao*4;
};

int Calc_DanoMagico(int Inteligencia, int Feiticaria){
    return Inteligencia*4+Feiticaria*2;
};

int Calc_DefesaMagica(int Inteligencia, int Foco){
    return Inteligencia*4+Foco*2;
};

float Calc_VelocidadeAtaque(int Agilidade, int Sorte){
    return  (Agilidade*1.8+Sorte)/60+0.2;
};
