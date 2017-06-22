/*
 * Exercicio Aeroporto
 * autor: Cesar Vergara
 * data inicial: 25-05-2017 data de entrega: 21-06-2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define INTERVAL_TIME 5
#define COMB 5
#define GASTO 3

int idpr = 0;
int idav = 0;
int idat = 0;
int idde = 1;
int id_at = 0;

typedef struct Aviao Aviao;

typedef struct Fila Fila;

typedef struct Registro Registro;

struct Aviao {

  int id_aviao;
  int id_ater;
  int id_deco;
  int permanecer;
  int tempo;

};

struct Fila {

  Aviao *aviao1;
  Aviao *aviao2;
  Aviao *aviao3;
  int avioes;

};

struct Registro {

  int aterrisagens;
  int decolagens;
  int avioes;
  int avioes_decolaram;
  int avioes_aterrisaram;
  int tempo_decolagens;
  int tempo_aterrisagens;
  int avioes_sem_combustivel;

};

void Aterrisagens(Fila *ater1, Fila *ater2, Registro *reg){

  Aviao *aviao;
  int avioes_aterrissando = rand() % 4;
  int success = 0;
  printf(GRN "\n[ATERRISAGENS #%d]\n" RESET, ++id_at);
  printf("Iniciando aterrissagens...\n..\n.\n");

  if (avioes_aterrissando == 0) {
    printf(YEL "Nenhum aviao se aproximou da pista de aterrisagens.\n" RESET);
  }

  for (size_t i = 0; i < avioes_aterrissando; i++) {
    //criacao do aviao
    aviao = malloc(sizeof(Aviao));
    //printf("AVIAO CRIADO %p\n", aviao);
    if (aviao == NULL ) return;
    aviao->id_aviao = idav;
    idav++;
    aviao->permanecer = 1 + rand() % 21;

    if (ater1->avioes < 3 || ater2->avioes < 3) {
      aviao->tempo = 0;
      //procurar lugar para o aviao
      if (ater1->aviao1 == 0) {
        aviao->id_ater = idat;
        idat++;
        ater1->aviao1 = aviao;
        reg->aterrisagens++;
        reg->avioes++;
        success++;
        //printf("Aviao %d pousou na pista ater1\n", aviao->id_aviao);
        ater1->avioes++;
      } else if (ater2->aviao1 == 0) {
        aviao->id_ater = idat;
        idat++;
        ater2->aviao1 = aviao;
        reg->aterrisagens++;
        reg->avioes++;
        success++;
        //printf("Aviao %d pousou na pista ater2\n", aviao->id_aviao);
        ater2->avioes++;
      } else if (ater1->aviao2 == 0) {
        aviao->id_ater = idat;
        idat++;
        ater1->aviao2 = aviao;
        reg->aterrisagens++;
        reg->avioes++;
        success++;
        //printf("Aviao %d pousou na pista ater1\n", aviao->id_aviao);
        ater1->avioes++;
      } else if (ater2->aviao2 == 0) {
        aviao->id_ater = idat;
        idat++;
        ater2->aviao2 = aviao;
        reg->aterrisagens++;
        reg->avioes++;
        success++;
        //printf("Aviao %d pousou na pista ater2\n", aviao->id_aviao);
        ater2->avioes++;
      } else if (ater1->aviao3 == 0) {
        aviao->id_ater = idat;
        idat++;
        ater1->aviao3 = aviao;
        reg->aterrisagens++;
        reg->avioes++;
        success++;
        //printf("Aviao %d pousou na pista ater1\n", aviao->id_aviao);
        ater1->avioes++;
      } else if (ater2->aviao3 == 0) {
        aviao->id_ater = idat;
        idat++;
        ater2->aviao3 = aviao;
        reg->aterrisagens++;
        reg->avioes++;
        success++;
        //printf("Aviao %d pousou na pista ater2\n", aviao->id_aviao);
        ater2->avioes++;
      }
    } else {
      //printf("nao ha vagas nas pistas de aterrisagem | aviao foi mandado para outro aeroporto.\n");
    }

  }

  if (success > 0) {
    printf(YEL "                  _       __         \n");
    printf("                 //       /|         \n");
    printf("         _______//_______/ |         \n");
    printf("        /__________________|     %d avioes se aproximam da pista de aterrissagem\n", success);
    printf("                \\                   \n");
    printf("                 \\                  \n" RESET);
  }

}

void Decolagens(Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  Aviao *aviao;
  int avioes_decolando = rand() % 4;
  printf(BLU "\n[DECOLAGENS]\n" RESET);
  printf("Iniciando decolagens...\n..\n.\n");

  for (size_t i = 0; i < avioes_decolando; i++) {
    aviao = malloc(sizeof(Aviao));
    if (aviao == NULL ) return;
    aviao->id_aviao = idav;
    idav++;
    aviao->permanecer = rand() % 11;

    if (dec1->avioes < 2 || dec2->avioes < 2 || dec3->avioes < 2) {
      aviao->tempo = 0;
      //procurar lugar para o aviao
      if (dec1->aviao1 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec1->aviao1 = aviao;
        reg->decolagens++;
        reg->avioes++;
        printf("Aviao %d se aproxima da pista de decolagem#1\n", aviao->id_aviao);
        dec1->avioes++;
      } else if (dec2->aviao1 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec2->aviao1 = aviao;
        reg->decolagens++;
        reg->avioes++;
        printf("Aviao %d se aproxima da pista de decolagem#2\n", aviao->id_aviao);
        dec2->avioes++;
      } else if (dec3->aviao1 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec3->aviao1 = aviao;
        reg->decolagens++;
        reg->avioes++;
        printf("Aviao %d se aproxima da pista de decolagem#3\n", aviao->id_aviao);
        dec3->avioes++;
      } else if (dec1->aviao2 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec1->aviao2 = aviao;
        reg->decolagens++;
        reg->avioes++;
        printf("Aviao %d se aproxima da pista de decolagem#1\n", aviao->id_aviao);
        dec1->avioes++;
      } else if (dec2->aviao2 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec2->aviao2 = aviao;
        reg->decolagens++;
        reg->avioes++;
        printf("Aviao %d se aproxima da pista de decolagem#2\n", aviao->id_aviao);
        dec2->avioes++;
      } else if (dec3->aviao2 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec3->aviao2 = aviao;
        reg->decolagens++;
        reg->avioes++;
        printf("Aviao %d se aproxima da pista de decolagem#3\n", aviao->id_aviao);
        dec3->avioes++;
      }
    }

  }

  printf(GRN "                  _       __         \n");
  printf("                 //       /|         \n");
  printf("         _______//_______/ |         \n");
  printf("        /__________________|     %d avioes decolando\n", avioes_decolando);
  printf("                \\                   \n");
  printf("                 \\                  \n" RESET);

}

void decolar(Aviao *aux, Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  Aviao *aviao;
  aviao = aux;
  aviao->permanecer = rand() % 11;

  printf(GRN "\n[DECOLAGENS #%d]\n" RESET, idde);
  printf("Iniciando decolagens...\n..\n.\n");

    if (dec1->avioes < 2 || dec2->avioes < 2 || dec3->avioes < 2) {
      aviao->tempo = 0;
      //procurar lugar para o aviao
      if (dec1->aviao1 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec1->aviao1 = aviao;
        reg->decolagens++;
        //reg->avioes++;
        printf("Aviao %d sai da pista de aterrisagem e se aproxima da pista de decolagem#1\n", aviao->id_aviao);
        dec1->avioes++;
      } else if (dec2->aviao1 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec2->aviao1 = aviao;
        reg->decolagens++;
        //reg->avioes++;
        printf("Aviao %d sai da pista de aterrisagem e se aproxima da pista de decolagem#2\n", aviao->id_aviao);
        dec2->avioes++;
      } else if (dec3->aviao1 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec3->aviao1 = aviao;
        reg->decolagens++;
        //reg->avioes++;
        printf("Aviao %d sai da pista de aterrisagem e se aproxima da pista de decolagem#3\n", aviao->id_aviao);
        dec3->avioes++;
      } else if (dec1->aviao2 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec1->aviao2 = aviao;
        reg->decolagens++;
        //reg->avioes++;
        printf("Aviao %d sai da pista de aterrisagem e se aproxima da pista de decolagem#1\n", aviao->id_aviao);
        dec1->avioes++;
      } else if (dec2->aviao2 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec2->aviao2 = aviao;
        reg->decolagens++;
        //reg->avioes++;
        printf("Aviao %d sai da pista de aterrisagem e se aproxima da pista de decolagem#2\n", aviao->id_aviao);
        dec2->avioes++;
      } else if (dec3->aviao2 == 0) {
        aviao->id_deco = idde;
        idde++;
        dec3->aviao2 = aviao;
        reg->decolagens++;
        //reg->avioes++;
        printf("Aviao %d sai da pista de aterrisagem e se aproxima da pista de decolagem#3\n", aviao->id_aviao);
        dec3->avioes++;
      }
    }

  /*printf(GRN "                  _       __         \n");
  printf("                 //       /|         \n");
  printf("         _______//_______/ |         \n");
  printf("        /__________________|     %d avioes decolando\n", avioes_decolando);
  printf("                \\                   \n");
  printf("                 \\                  \n" RESET);*/


}

void decolarFinal(Aviao *aux, Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){


  printf(RED "                  _       __         \n");
  printf("                 //       /|         \n");
  printf("         _______//_______/ |         \n");
  printf("        /__________________|     O aviao %d decolou.\n", aux->id_aviao);
  printf("                \\                   \n");
  printf("                 \\                  \n\n" RESET);

  free(aux);

}

void Combustivel(Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  Aviao *aux;

  if (ater1->aviao1 != 0) {
    aux = ater1->aviao1;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer < 5) {
      //printf("O aviao %d tem pouco combustivel, partir para decolagem.\n", aux->id_aviao);
      reg->tempo_aterrisagens += aux->tempo;
      reg->avioes_aterrisaram++;
      decolar(aux, ater1, ater2, dec1, dec2, dec3, reg);
      ater1->aviao1 = 0;
      ater1->avioes--;
    }

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }
  }

  if (ater1->aviao2 != 0) {
    aux = ater1->aviao2;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer < 5) {
      //printf("O aviao %d tem pouco combustivel, partir para decolagem.\n", aux->id_aviao);
      reg->tempo_aterrisagens += aux->tempo;
      reg->avioes_aterrisaram++;
      decolar(aux, ater1, ater2, dec1, dec2, dec3, reg);
      ater1->aviao2 = 0;
      (ater1->avioes) -= 1;
    }

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }
  }

  if (ater1->aviao3 != 0) {
    aux = ater1->aviao3;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer < 5) {
      //printf("O aviao %d tem pouco combustivel, partir para decolagem.\n", aux->id_aviao);
      reg->tempo_aterrisagens += aux->tempo;
      reg->avioes_aterrisaram++;
      decolar(aux, ater1, ater2, dec1, dec2, dec3, reg);
      ater1->aviao3 = 0;
      (ater1->avioes) -= 1;
    }

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }
  }

  if (ater2->aviao1 != 0) {
    aux = ater2->aviao1;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer < 5) {
      //printf("O aviao %d tem pouco combustivel, partir para decolagem.\n", aux->id_aviao);
      reg->tempo_aterrisagens += aux->tempo;
      reg->avioes_aterrisaram++;
      decolar(aux, ater1, ater2, dec1, dec2, dec3, reg);
      ater2->aviao1 = 0;
      (ater2->avioes) -= 1;
    }

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }
  }

  if (ater2->aviao2 != 0) {
    aux = ater2->aviao2;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer < 5) {
      //printf("O aviao %d tem pouco combustivel, partir para decolagem.\n", aux->id_aviao);
      reg->tempo_aterrisagens += aux->tempo;
      reg->avioes_aterrisaram++;
      decolar(aux, ater1, ater2, dec1, dec2, dec3, reg);
      ater2->aviao2 = 0;
      (ater2->avioes) -= 1;
    }

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }
  }

  if (ater2->aviao3 != 0) {
    aux = ater2->aviao3;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer < 5) {
      //printf("O aviao %d tem pouco combustivel, partir para decolagem.\n", aux->id_aviao);
      reg->tempo_aterrisagens += aux->tempo;
      reg->avioes_aterrisaram++;
      decolar(aux, ater1, ater2, dec1, dec2, dec3, reg);
      ater2->aviao3 = 0;
      (ater2->avioes) -= 1;
    }

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }
  }

  if (dec1->aviao1 != 0) {
    aux = dec1->aviao1;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }

    if (aux->permanecer < 5) {
      //printf("O aviao %d vai decolar.\n", aux->id_aviao);
      reg->tempo_decolagens += aux->tempo;
      reg->avioes_decolaram++;
      decolarFinal(aux, ater1, ater2, dec1, dec2, dec3, reg);
      dec1->aviao1 = 0;
      dec1->avioes--;
    }

  }

  if (dec1->aviao2 != 0) {
    aux = dec1->aviao2;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }

    if (aux->permanecer < 5) {
      //printf("O aviao %d vai decolar.\n", aux->id_aviao);
      reg->tempo_decolagens += aux->tempo;
      reg->avioes_decolaram++;
      decolarFinal(aux, ater1, ater2, dec1, dec2, dec3, reg);
      dec1->aviao2 = 0;
      dec1->avioes--;
    }

  }

  if (dec2->aviao1 != 0) {
    aux = dec2->aviao1;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }

    if (aux->permanecer < 5) {
      //printf("O aviao %d vai decolar.\n", aux->id_aviao);
      reg->tempo_decolagens += aux->tempo;
      reg->avioes_decolaram++;
      decolarFinal(aux, ater1, ater2, dec1, dec2, dec3, reg);
      dec2->aviao1 = 0;
      dec2->avioes--;
    }

  }

  if (dec2->aviao2 != 0) {
    aux = dec2->aviao2;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }

    if (aux->permanecer < 5) {
      //printf("O aviao %d vai decolar.\n", aux->id_aviao);
      reg->tempo_decolagens += aux->tempo;
      reg->avioes_decolaram++;
      decolarFinal(aux, ater1, ater2, dec1, dec2, dec3, reg);
      dec2->aviao2 = 0;
      dec2->avioes--;
    }

  }

  if (dec3->aviao1 != 0) {
    aux = dec3->aviao1;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }

    if (aux->permanecer < 5) {
      //printf("O aviao %d vai decolar.\n", aux->id_aviao);
      reg->tempo_decolagens += aux->tempo;
      reg->avioes_decolaram++;
      decolarFinal(aux, ater1, ater2, dec1, dec2, dec3, reg);
      dec3->aviao1 = 0;
      dec3->avioes--;
    }

  }

  if (dec3->aviao2 != 0) {
    aux = dec3->aviao2;
    aux->permanecer = (aux->permanecer) - GASTO;
    aux->tempo += INTERVAL_TIME;
    //printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);

    if (aux->permanecer == 0) {
      reg->avioes_sem_combustivel++;
    }

    if (aux->permanecer < 5) {
      //printf("O aviao %d vai decolar.\n", aux->id_aviao);
      reg->tempo_decolagens += aux->tempo;
      reg->avioes_decolaram++;
      decolarFinal(aux, ater1, ater2, dec1, dec2, dec3, reg);
      dec3->aviao2 = 0;
      dec3->avioes--;
    }

  }

/*
  if (ater3->aviao1 != 0) {
    aux = ater3->aviao1;
    aux->permanecer = (aux->permanecer) - GASTO;
    printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);
  }

  if (ater3->aviao2 != 0) {
    aux = ater3->aviao2;
    aux->permanecer = (aux->permanecer) - GASTO;
    printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);
  }

  if (ater3->aviao3 != 0) {
    aux = ater3->aviao3;
    aux->permanecer = (aux->permanecer) - GASTO;
    printf("O aviao %d esta com %d de combustivel\n", aux->id_aviao, aux->permanecer);
  }*/
}

void imprimirRelatorio(Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  /*printf("\n--Imprimindo Relatorio--\n");
  printf("Numero total de avioes: %d\n", reg->avioes);
  printf("Numero de decolagens: %d | aterrisagens: %d\n", reg->decolagens, reg->aterrisagens);
  printf("Tempo medio de decolagens: %ds | aterrisagens: %ds\n", (reg->tempo_decolagens)/(reg->avioes_decolaram), (reg->tempo_aterrisagens)/(reg->avioes_aterrisaram));
  printf("Numero de avioes que ficaram sem combustivel: %d\n", reg->avioes_sem_combustivel);
  printf("--Fim do relatorio--\n");*/

  FILE *fp = fopen("relatorio.txt", "w");

  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char s[64];
  strftime(s, sizeof(s), "%c", tm);

  fprintf(fp, "\n--[RELATORIO AEROPORTO]--\n");
  fprintf(fp, "(%s)\n", s);
  fflush(fp);
  fprintf(fp, "Numero total de avioes: %d\n", reg->avioes);
  fprintf(fp, "Numero de decolagens: %d\taterrisagens: %d\n", reg->decolagens, reg->aterrisagens);
  if (reg->avioes_decolaram > 0 && reg->avioes_aterrisaram > 0) {
      fprintf(fp, "Tempo medio de decolagens: %dseg\taterrisagens: %dseg\n", (reg->tempo_decolagens)/(reg->avioes_decolaram), (reg->tempo_aterrisagens)/(reg->avioes_aterrisaram));
  }
  fprintf(fp, "Numero de avioes que ficaram sem combustivel: %d\n", reg->avioes_sem_combustivel);
  fprintf(fp, "\nPista at1: %d avioes; Pista at2: %d avioes\n", ater1->avioes, ater2->avioes);
  fprintf(fp, "Pista dec1: %d avioes; Pista dec2: %d avioes; Pista dec3: %d avioes\n", dec1->avioes, dec2->avioes, dec3->avioes);

  fclose(fp);

}


void imprimirPistas(Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  printf("|ater1|\t\t\t\t|ater2|\t\t\t\t|dec1|\t\t\t\t|dec2|\t\t\t\t|dec3|\n");
  printf("%p\t\t\t\t%p\t\t\t\t%p\t\t\t\t%p\t\t\t\t%p\n", (ater1->aviao1), (ater2->aviao1), (dec1->aviao1), (dec2->aviao1), (dec3->aviao1));
  printf("%p\t\t\t\t%p\t\t\t\t%p\t\t\t\t%p\t\t\t\t%p\n", (ater1->aviao2), (ater2->aviao2), (dec1->aviao2), (dec2->aviao2), (dec3->aviao2));
  printf("%p\t\t\t\t%p\n", (ater1->aviao3), (ater2->aviao3));

}

void funcionarAeroporto(Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  //int work = 0;

  /*do {
    Aterrisagens(ater1, ater2);
    //Decolagens(dec1, dec2, dec3);
    printf(MAG "\nATERRISAGENS E DECOLAGENS ENCERRADAS POR AGORA...\n----------------------------------\n" RESET);
    printf("1 - para aero funcionar\n2 - para aero parar: ");
    scanf("%d", &work);
    setbuf(stdin, NULL);
  } while(work < 2);*/

  int i = 1;

    while ( i > 0 ) {
      Aterrisagens(ater1, ater2, reg);
      Combustivel(ater1, ater2, dec1 ,dec2, dec3, reg);
      //Decolagens(dec1, dec2, dec3, reg);
      printf(MAG "\nATERRISAGENS E DECOLAGENS ENCERRADAS POR AGORA...\n----------------------------------\n" RESET);
      //printf("intervalo de %d segundos\n", INTERVAL_TIME);
      //if ( i % 2 == 0) {
        imprimirRelatorio(ater1, ater2, dec1 ,dec2, dec3, reg);
      //}

      /*if (i > 2) {
          imprimirPistas(ater1, ater2, dec1 ,dec2 ,dec3, reg);
      }*/

      sleep(INTERVAL_TIME);
      i++;
    }

}

void encerrarAeroporto(Fila *ater1, Fila *ater2, Fila *dec1, Fila *dec2, Fila *dec3, Registro *reg){

  free(ater1);
  free(ater2);
  free(dec1);
  free(dec2);
  free(dec3);
  free(reg);

}

int main(int argc, char const *argv[]) {

  Registro *reg;
  Fila *ater1, *ater2, *dec1, *dec2, *dec3;

  reg = malloc(sizeof(Registro));
  if (reg == NULL) return 0;
  reg->aterrisagens = 0;
  reg->decolagens = 0;
  reg->avioes = 0;
  reg->avioes_aterrisaram = 0;
  reg->avioes_decolaram = 0;
  reg->tempo_decolagens = 0;
  reg->tempo_aterrisagens = 0;
  reg->avioes_sem_combustivel = 0;

  ater1 = malloc(sizeof(Fila));
  if (ater1 == NULL ) return 0;
  ater1->avioes = 0;
  ater1->aviao1 = 0;
  ater1->aviao2 = 0;
  ater1->aviao3 = 0;

  ater2 = malloc(sizeof(Fila));
  if (ater2 == NULL ) return 0;
  ater2->avioes = 0;
  ater2->aviao1 = 0;
  ater2->aviao2 = 0;
  ater2->aviao3 = 0;

  dec1 = malloc(sizeof(Fila));
  if (dec1 == NULL ) return 0;
  dec1->avioes = 0;
  dec1->aviao1 = 0;
  dec1->aviao2 = 0;
  dec1->aviao3 = 0;

  dec2 = malloc(sizeof(Fila));
  if (dec2 == NULL ) return 0;
  dec2->avioes = 0;
  dec2->aviao1 = 0;
  dec2->aviao2 = 0;
  dec2->aviao3 = 0;

  dec3 = malloc(sizeof(Fila));
  if (dec3 == NULL ) return 0;
  dec3->avioes = 0;
  dec3->aviao1 = 0;
  dec3->aviao2 = 0;
  dec3->aviao3 = 0;

  printf(RED "Algoritmo de Aeroporto sendo iniciado...\n..\n.\n\n" RESET);

  funcionarAeroporto(ater1, ater2, dec1, dec2, dec3, reg);
  encerrarAeroporto(ater1, ater2, dec1, dec2, dec3, reg);

  return 1;
}
