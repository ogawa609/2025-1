#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1 
#define FALSE 0

typedef struct personagens{

    char galinha[2][3];
    char carro[2][3];

}personagem;

typedef struct config_inicial{

    char direcao;
    int velocidade;
    int qtd_carros;
    int posicoes[10];
}pistas;

typedef struct{
    int animacao;
    int colunas;


    int qtd_pistas;
    pistas caract_pista[12];
    int galinhaX;
    int vidas;


}config;

typedef struct{

    int indice_pista;
    int indice_carro;
    int interacao;
}ranking; //armazena infos para o ranking

typedef struct{

     int movimentos;
    int altura_max_galinha;
    int altura_max_morte;
    int altura_minima_morte;
    int direcao_oposta;
} testatistica;


config LeArquivo (char *caminho);
personagem LePersonagem(char*caminho);
void DesenharMapa(config mapa, personagem personagens,int linhas,int colunas, char matriz[linhas][colunas],int linha_galinha);
void RastreiaGalinha (int linhas,int colunas,int heatmap[linhas][colunas],int colG,int linG);
void ZeraMatriz(int linhas,int colunas,int a[linhas][colunas]);
config MoverCarros (config mapa);
int MoverGalinha(config mapa, char comando,int pista_atual);
int ChecarColisao(config mapa,int linhas,int colunas, int heatmapa[linhas][colunas]);
int dist_circular(int a, int b, int m);
void MapadeCalor(int linhas, int colunas, int heatmap_final[linhas][colunas], int colG, int linG);

//FUNÇÕES

void MapadeCalor(int linhas, int colunas, int heatmap_final[linhas][colunas], int colG, int linG) {

    for (int x = 0; x < linhas; x++) {//varrer linhas e colunas do mapa

        for (int y = 0; y < colunas; y++) {

            if ((x == linG || x == linG + 1) && (y == colG || y == colG - 1 || y == colG + 1)) { //se for linha da galinha adiciona 1 as 6 celulas

                if (heatmap_final[x][y] < 99) {

                    heatmap_final[x][y]++;
                }
            }
        }
    }
}




int dist_circular(int a, int b, int m) {
    int d = abs(a - b);
    if (d > m - d) d = m - d;
    return d;
}

int ChecarColisao(config mapa, int linhas, int colunas, int heatmapa[linhas][colunas]) {

    
    for (int i = 0; i < mapa.qtd_pistas; i++) { //Varre pista por pista

        if (mapa.caract_pista[i].direcao == 'D' || mapa.caract_pista[i].direcao == 'E') { //Verifica se é pista valida

            int cima  = 1 + i * 3; //cima do carro
            int baixo = 2 + i * 3; //baixo carro

            for (int j = 0; j < mapa.caract_pista[i].qtd_carros; j++) { //varre os carros de cada pista

                int col = mapa.caract_pista[i].posicoes[j]; //col é a posição do carro

                for (int dx = -1; dx <= 1; dx++) { //percorre esquerda e direita da posicao central
                    int c = col + dx; //c assume posicao esquerda central e direita
                    if (c < 1) c = mapa.colunas; //se ultrapassar limites retorna o limite
                    if (c > mapa.colunas) c = 1;

                    if (heatmapa[cima][c] > 0 || heatmapa[baixo][c] > 0) {
                        return TRUE; //se na posicao do carro for!= de 0 -> sem colisao
                    }
                }
            }
        }
    }
    return FALSE;
}

int MoverGalinha(config mapa, char comando,int pista_atual){

    int movimento = pista_atual; // padrão: ficar parado

    if ((comando == 'w' || comando == 'W') && pista_atual > 1) {

        movimento--;
    } else if ((comando == 's' || comando == 'S') && pista_atual < mapa.qtd_pistas) {
        movimento++;
    }

    else if (comando==' '){
        movimento=pista_atual; //se espaço as config de posição são as mesmas
    }

    return movimento;
}

config MoverCarros(config mapa) {
    config dados = mapa;

    for (int i = 0; i < dados.qtd_pistas; i++) {

        if (dados.caract_pista[i].direcao == 'D') { // Direita
            for (int j = 0; j < dados.caract_pista[i].qtd_carros; j++) {

                // Avança velocidade casas de forma circular
                dados.caract_pista[i].posicoes[j] = ((mapa.caract_pista[i].posicoes[j] - 1 + mapa.caract_pista[i].velocidade) % mapa.colunas) + 1;
            }
        }

        else if (dados.caract_pista[i].direcao == 'E') { // Esquerda

            for (int k = 0; k < dados.caract_pista[i].qtd_carros; k++) {
                // Volta velocidade casas
                dados.caract_pista[i].posicoes[k] = ((mapa.caract_pista[i].posicoes[k] - 1 - mapa.caract_pista[i].velocidade + mapa.colunas) % mapa.colunas) + 1;
            }
        }
    }

    return dados;
}




void ZeraMatriz(int linhas,int colunas,int a[linhas][colunas]){ //reinicia a matriz que rastreia a galinha

    for (int i=0;i<linhas;i++){

         for(int j=0;j<colunas;j++){
                
             a[i][j]=0;
                
         }
    }
}

    
void RastreiaGalinha (int linhas,int colunas,int heatmap[linhas][colunas],int colG,int linG){ //LinG equivale a linha onde esta a cabeça da galinha
                                                                                       
    for(int x=0;x<linhas;x++){

        for(int y=0;y<colunas;y++){

            if((x==linG||x==linG+1)&&(y==colG||y==colG-1||y==colG+1)){

                heatmap[x][y]++; //mapa está contabilizando as bordas
            }

        }
    }
}



void DesenharMapa (config mapa, personagem personagens,int linhas,int colunas, char matriz[linhas][colunas], int linha_galinha){

    // Preenche matriz mapa
     for (int a = 0; a < linhas; a++) {

        for (int b = 0; b < colunas; b++) {

            if (b == 0 || b == colunas - 1){

                 matriz[a][b] = '|'; //preenche bordas colunas
            }

            else if (a == 0 || a == linhas - 1) {

                matriz[a][b] = '-';  //bota bordas horizontais
            }

            else if(a % 3 == 0&&b%3!=0){
                matriz[a][b] = '-'; 
                //bota pistas em linhas divisiveis por 3
            }
            else{
                 matriz[a][b] = ' ';
            }
        }
    }

    // Coloca galinha
    for (int dy = 0; dy < 2; dy++) {

        for (int dx = 0; dx < 3; dx++) {

            int y = linha_galinha + dy;  //soma o x da galinha com a posicao atual da cabeca dela;
            int x = mapa.galinhaX + dx - 1;

            matriz[y][x] = personagens.galinha[dy][dx];
        }
    }

    // Coloca carros
    for (int pista = 0; pista < mapa.qtd_pistas; pista++) {

        if (mapa.caract_pista[pista].direcao == 'D' || mapa.caract_pista[pista].direcao == 'E') {  //verifica se a pista tem carro

            int cima_carro = 1 + pista * 3; 
            int baixo_carro = 2 + pista * 3;

            for (int p = 0; p < mapa.caract_pista[pista].qtd_carros; p++) {

                int col = mapa.caract_pista[pista].posicoes[p];  //varre cada posicao dos carros
                int direita;
                int esquerda;

                esquerda = (col - 2 + mapa.colunas) % mapa.colunas + 1;
                direita  = col % mapa.colunas + 1;

                matriz[cima_carro][esquerda] = personagens.carro[0][0];  //preenche matriz com carro
                matriz[cima_carro][col]     = personagens.carro[0][1];
                matriz[cima_carro][direita] = personagens.carro[0][2];

                matriz[baixo_carro][esquerda] = personagens.carro[1][0];
                matriz[baixo_carro][col]     = personagens.carro[1][1];
                matriz[baixo_carro][direita] = personagens.carro[1][2];
            }
        }
    }
}



personagem LePersonagem(char*caminho){

    FILE *arquivo; //verifica arquivo
    personagem p;
    
    arquivo = fopen(caminho, "r");

    if (!arquivo) {

        printf("Erro ao abrir o arquivo: %s\n", caminho);

        exit(1);
    }

    // Lê a galinha 

    for (int a = 0; a < 2; a++) {

        for (int b = 0; b < 3; b++) {
            
            do {    // Lê cada caractere ignorando \n
                       
                fscanf(arquivo, "%c", &p.galinha[a][b]);

            } while (p.galinha[a][b] == '\n'); //laço se repete até achar um caract que n seja \n
        }
        
        while (fgetc(arquivo) != '\n' && !feof(arquivo));  // Lê a linha incluindo a quebra de linha e descartando
    }

    
    for (int c = 0; c < 2; c++) {    // Lê o carro 

        for (int d = 0; d < 3; d++) { // Lê cada caractere ignorando \n
            
            do {

                fscanf(arquivo, "%c", &p.carro[c][d]);

            } while (p.carro[c][d] == '\n');
        }
        
        while (fgetc(arquivo) != '\n' && !feof(arquivo));  // Lê o restante da linha  e descarta
    }

    fclose(arquivo);
    return p;
}

//------------------ Le Arquivo de Configuração Inicial-------------------------------------------------------------------//
config LeArquivo (char *caminho){

    FILE *arquivo;
    int i=0;
    char c;
    config mapa;
    

    arquivo = fopen(caminho,"r");

    if (!arquivo) {  //verifica os arquivos

    printf("Erro ao abrir o arquivo: %s\n", caminho);
       
    exit(1);

    }

    fscanf(arquivo,"%d", &mapa.animacao);
    fscanf(arquivo, "%d %d", &mapa.colunas, &mapa.qtd_pistas);

    fgetc(arquivo);
    
    for(i=0;i<mapa.qtd_pistas;i++){  

        fscanf(arquivo, "%c", &c); //pega o primeiro caracter de cada linha


        if(c=='G'){ //se o caracter for G é a linha da galinha

            fscanf(arquivo, "%d %d", &mapa.galinhaX, &mapa.vidas);
            fgetc(arquivo);

            mapa.caract_pista[i].direcao = 'G';
         }

         else if(c=='D'||c=='E'){ //se for e ou d é pista de carro

            mapa.caract_pista[i].direcao = c;

            fscanf(arquivo,"%d", &mapa.caract_pista[i].velocidade);
            fscanf(arquivo,"%d",&mapa.caract_pista[i].qtd_carros);

            for(int a=0; a<mapa.caract_pista[i].qtd_carros;a++){

                fscanf(arquivo,"%d",&mapa.caract_pista[i].posicoes[a]);
            }

            fgetc(arquivo);
         }

         else if(c=='\n'){ //se for linha vazia

            mapa.caract_pista[i].direcao = '-';
            mapa.caract_pista[i].qtd_carros = 0;
            mapa.caract_pista[i].velocidade = 0;
            continue;
            
         }

    }

    fclose(arquivo);
    return mapa;

}


//======MAIN=====//

int main (int argc, char *argv[]){

//CHECAR DIRETÓRIO//

    FILE *arquivo1;
    FILE *arquivo2;
    char caminho_arquivo1[1001];
    char caminho_arquivo2[1001];

    if (argc<2){

        printf("ERRO: Informe o diretorio com os arquivos de configuracao.");

        exit(1);
    }

    sprintf(caminho_arquivo1, "%s/config_inicial.txt", argv[1]);
    sprintf(caminho_arquivo2, "%s/personagens.txt", argv[1]);

    arquivo1 = fopen(caminho_arquivo1,"r");
    arquivo2= fopen(caminho_arquivo2,"r");

    if (!arquivo1){

        printf("ERRO: Não foi possivel ler o arquivo %s.\n",caminho_arquivo1);

        exit(1);
    }

    if (!arquivo2){

        printf("ERRO: Não foi possivel ler o arquivo %s.\n",caminho_arquivo2);

        exit(1);
    }

    fclose(arquivo1);
    fclose(arquivo2);

//-----------------------------------------------------------------------------------------------------------------------------------------
   
    personagem personagens;
    config mapa;
    char comando;
    
   mapa = LeArquivo(caminho_arquivo1); //Le arqivo config. inicial
   personagens = LePersonagem(caminho_arquivo2); //le arquivo personagens

   int linhas= (mapa.qtd_pistas*3)+1; //linhas totais com borda e tudo
   int colunas = mapa.colunas+2;  //colunas totais com borda e tudo
   char jogo[linhas][colunas]; //cria matriz do mapa do jogo
   int heatmap[linhas][colunas]; //cria copia do mapa para rastrear a galinha
   int pista_atual_galinha=mapa.qtd_pistas;
   int linha_cabeca_galinha= (pista_atual_galinha*3)-2; //linha onde a cabeça da galinha está contando a partir da borda ->borda = 0; no heat map é a posição linha do corpo
   int pontos=0;
   int interacoes=0;
   int reinicia=(mapa.qtd_pistas*3)-2;
   ranking Rank[mapa.vidas];  //armazena infos para montar ranking
   testatistica est; //armazena dados para estatistica
   int mapacalor[linhas][colunas];
   int colidiu[linhas];

   for(int u=0;u<linhas;u++){//zera o vetor de colisoes

    colidiu[u]=0;
   }

   DesenharMapa(mapa,personagens,linhas,colunas,jogo,linha_cabeca_galinha); //inicializa o mapa

   ZeraMatriz(linhas,colunas,heatmap); //preenche parte util do mapa de 0 no heat map
   ZeraMatriz(linhas,colunas,mapacalor);//preenche parte util do mapa de 0 no heat map
   MapadeCalor(linhas,colunas,mapacalor,mapa.galinhaX,linha_cabeca_galinha);

   RastreiaGalinha(linhas,colunas,heatmap,mapa.galinhaX,linha_cabeca_galinha); //atribui galinha como 1;


    //CRIA ARQUIVO INICIALIZACAO.TXT//

    FILE* inicializacao;
    char caminho_arquivo3 [1001];

    sprintf(caminho_arquivo3, "%s/saida/inicializacao.txt", argv[1]);

    inicializacao= fopen(caminho_arquivo3, "w");

    if (!inicializacao) {

        printf("Erro ao criar arquivo de inicialização\n");

        exit(1);
    }

    for(int u=0;u<linhas; u++){

        for(int v=0; v<colunas; v++){

            fprintf(inicializacao,"%c",jogo[u][v]);
        }

        fprintf(inicializacao,"\n");
    }

   
    

    fprintf(inicializacao,"A posicao central da galinha iniciara em (%d %d).\n", mapa.galinhaX, linha_cabeca_galinha);

    fclose(inicializacao);


// LE ARQUIVO ENTRADAS//

    FILE*entrada;
    char caminho_arquivo4[1001];

    sprintf(caminho_arquivo4,"%s/entrada.txt",argv[1]);

    entrada= fopen(caminho_arquivo4,"r");

    if (!entrada){

        printf("ERRO: Não foi possivel ler o arquivo %s.\n",caminho_arquivo4);

        exit(1);
    }

//CRIA RESUMO//

    FILE*resumo;
    char caminho_resumo[1001];

    sprintf(caminho_resumo,"%s/saida/resumo.txt",argv[1]);

    resumo= fopen(caminho_resumo,"w");

    if (!resumo){

        printf("ERRO: Não foi possivel criar o arquivo %s.\n",caminho_resumo);

        exit(1);
    }

//CRIA RANKING//

    FILE*Ranking;
    char caminho_ranking[1001];

    sprintf(caminho_ranking, "%s/saida/ranking.txt",argv[1]);
    Ranking= fopen(caminho_ranking,"w");

     if (!Ranking){

        printf("ERRO: Não foi possivel criar o arquivo %s.\n",caminho_ranking);

        exit(1);
    }

//CRIA ESTATISTICA

     FILE*Estatistica;
    char caminho_estatistica[1001];

    sprintf(caminho_estatistica, "%s/saida/estatistica.txt",argv[1]);
    Estatistica= fopen(caminho_estatistica,"w");

     if (!Estatistica){

        printf("ERRO: Não foi possivel criar o arquivo %s.\n",caminho_estatistica);

        exit(1);
    }

//CRIA HEATMAP

     FILE*Heat_Map;
    char caminho_heatmap[1001];

    sprintf(caminho_heatmap, "%s/saida/heatmap.txt",argv[1]);
    Heat_Map= fopen(caminho_heatmap,"w");

     if (!Heat_Map){

        printf("ERRO: Não foi possivel criar o arquivo %s.\n",caminho_heatmap);

        exit(1);
    }

//===========================================================================================================================================//

//Leitura dos comandos de entrada até final do arquivo;   
    int ch;
    int perdeu=0;
    int ganhou=0;
    int u;
    int R=0;
    est.altura_max_galinha=0;
    est.altura_max_morte=0;
    est.altura_minima_morte=0;
    est.direcao_oposta=0;
    est.movimentos=0;
    int unico=1;
    


    printf("Pontos: %d | Vidas: %d | Iteracoes: %d\n",pontos,mapa.vidas,interacoes); //imprime o mapa limpo

        for(int L=0;L<linhas;L++){

            for(int C=0;C<colunas;C++){

                printf("%c",jogo[L][C]);
            }

            printf("\n");
        }

    do{

        
         ch= fscanf(entrada,"%c",&comando); //recebe comando e verifica se eh valido

        if(comando!=' '&&comando!='w'&&comando!='s'){//se for \n ignora

            continue;
        }

        if(comando=='w'){

            est.movimentos++;

            if(est.altura_max_galinha<((mapa.qtd_pistas*3)-linha_cabeca_galinha)){

                est.altura_max_galinha=((mapa.qtd_pistas*3)-linha_cabeca_galinha);
            }

        }

        else if(comando=='s'){

            est.direcao_oposta++;//incrementa contadores
            est.movimentos++;
        }

        
          

        mapa = MoverCarros(mapa); //movimenta os carros

        ZeraMatriz(linhas,colunas,heatmap); //zera o mapa de rastreio da galinha para atualizar a posição dela

        interacoes++; //incrementa as interações do jogo
         
        u=MoverGalinha(mapa,comando,pista_atual_galinha);  //move galinha atualizando a pista dela

        pista_atual_galinha=u;

        linha_cabeca_galinha= (pista_atual_galinha*3)-2; //atualiza a linha da matriz onde a galinha esta para ser usada nas funções
         

        DesenharMapa(mapa,personagens,linhas,colunas,jogo,linha_cabeca_galinha); //reescreve a matriz com as atualizações

        RastreiaGalinha(linhas,colunas,heatmap,mapa.galinhaX,linha_cabeca_galinha);  //cria uma nova matriz de rastreamento e sobreposição da posição da galinha
       
         MapadeCalor(linhas,colunas,mapacalor,mapa.galinhaX,linha_cabeca_galinha); //atualiza mapa de calor
        if(ChecarColisao(mapa,linhas,colunas,heatmap)){ //verifica se houve colisão com base na sobreposição do rastreio

           int indice = -1;

        for (int w = 0; w < mapa.caract_pista[pista_atual_galinha-1].qtd_carros; w++) { //Encontra indice do carro que atropelou a galinha

            int pos = mapa.caract_pista[pista_atual_galinha-1].posicoes[w];

            if (dist_circular(pos, mapa.galinhaX, mapa.colunas) <= 2) {

                indice = w + 1;  
                 break;
            }
        }

            Rank[R].indice_carro=indice;//armazena dados no vetor para dps ser ordenado para ranking
            Rank[R].indice_pista=pista_atual_galinha;
            Rank[R].interacao=interacoes;
            R++;

            if(unico){//inicia altura minima de morte na primeira colisao
                est.altura_minima_morte=(mapa.qtd_pistas*3)-linha_cabeca_galinha;
                unico=0;
            }

            if(est.altura_max_morte<((mapa.qtd_pistas*3)-linha_cabeca_galinha)){//atualiza altura maxima de morte

                est.altura_max_morte=(mapa.qtd_pistas*3)-linha_cabeca_galinha;
            }

             if(est.altura_minima_morte>((mapa.qtd_pistas*3)-linha_cabeca_galinha)){//atualiza altura minima de morte

                est.altura_minima_morte=(mapa.qtd_pistas*3)-linha_cabeca_galinha;
            }

            int mark=1;

            mapa.vidas--; //vidas da galinha diminuem para colisão

            colidiu[linha_cabeca_galinha]=1;//marca no vetor as pistas que a galinha morreu
             colidiu[linha_cabeca_galinha+1]=1;
            

            fprintf(resumo,"[%d] Na pista %d o carro %d atropelou a galinha na posicao (%d,%d).\n",interacoes,pista_atual_galinha,indice,mapa.galinhaX,linha_cabeca_galinha); //atualiza arquivo resumo

            if(mapa.vidas==0){ //se as vidas chegarem a zero o jogo acaba

                fprintf(resumo,"[%d] Fim de jogo",interacoes);

                mark=0;
                perdeu=1;
                pontos=0;
                linha_cabeca_galinha=reinicia;
                pista_atual_galinha=mapa.qtd_pistas;
                DesenharMapa(mapa,personagens,linhas,colunas,jogo,linha_cabeca_galinha);//atualiza mapa para galinha voltar posicao inicial
                MapadeCalor(linhas,colunas,mapacalor,mapa.galinhaX,linha_cabeca_galinha); //atualiza mapa de calor
                
            }

            if(mark){ //caso  galinha ainda tenha vidas restantes

                pontos=0;
                linha_cabeca_galinha=reinicia;
                pista_atual_galinha=mapa.qtd_pistas;

                DesenharMapa(mapa,personagens,linhas,colunas,jogo,linha_cabeca_galinha); //atualiza a matriz para a galinha voltar a posição inicial
                MapadeCalor(linhas,colunas,mapacalor,mapa.galinhaX,linha_cabeca_galinha); //atualiza mapa de calor
            }
        }

        else{

            if(pista_atual_galinha==1){ //se a galinha chegar na ultima pista

                pontos++;
                pontos=pontos+10;
                ganhou=1;
            }

            else{
                if(comando=='w'){ //se a galinha avança uma pista

                    pontos++;

                }
            }
        }

        if(est.altura_max_galinha<((mapa.qtd_pistas*3)-linha_cabeca_galinha)){//compara se pista atual é maior que o atual maximo altura galinha

            est.altura_max_galinha=((mapa.qtd_pistas*3)-linha_cabeca_galinha);
        }

       

        printf("Pontos: %d | Vidas: %d | Iteracoes: %d\n",pontos,mapa.vidas,interacoes); //imprime matriz

        for(int L=0;L<linhas;L++){

            for(int C=0;C<colunas;C++){

                printf("%c",jogo[L][C]);
            }

            printf("\n");
        }

        if(perdeu){//caso n tenha vidas

            printf("Voce perdeu todas as vidas! Fim de jogo.\n");
            break;
        }

        if(ganhou){//caso chegue na ultima pista

            printf("Parabens! Voce atravessou todas as pistas e venceu!\n");
            fprintf(resumo,"[%d] Fim de jogo",interacoes);

            break;

        }

        
        
    }while(ch!=EOF);//le ate final do arquivo entrada

//-------------------------------------------------------------------------------
//PREENCHE ARQUIVO RANKING
    ranking temporario;
    for(int n=0;n<R;n++){

        for(int m=n+1;m<R;m++){

            if(Rank[n].indice_pista>Rank[m].indice_pista){//ordena segundo especificações

                temporario=Rank[n];
                Rank[n]=Rank[m];
                Rank[m]=temporario;
            }

            else if(Rank[n].indice_pista==Rank[m].indice_pista){

                if(Rank[n].indice_carro>Rank[m].indice_carro){

                temporario=Rank[n];
                Rank[n]=Rank[m];
                Rank[m]=temporario;
            }

            else if(Rank[n].indice_carro==Rank[m].indice_carro){

                if(Rank[n].interacao<Rank[m].interacao){

                temporario=Rank[n];
                Rank[n]=Rank[m];
                Rank[m]=temporario;
            }
            }

            }
        }
    }

    fprintf(Ranking,"id_pista,id_carro,iteracao\n");

    for(int o=0;o<R;o++){

        fprintf(Ranking,"%d,%d,%d\n",Rank[o].indice_pista,Rank[o].indice_carro,Rank[o].interacao);
    }
//----------------------------------------------------------------------------------------------------------------------------------------
//PREENCHE ARQUIVO ESTATISTICA

    fprintf(Estatistica,"Numero total de movimentos: %d\n",est.movimentos);
    fprintf(Estatistica,"Altura maxima que a galinha chegou: %d\n",est.altura_max_galinha);
    fprintf(Estatistica,"Altura maxima que a galinha foi atropelada: %d\n",est.altura_max_morte);
    fprintf(Estatistica,"Altura minima que a galinha foi atropelada: %d\n",est.altura_minima_morte);
    fprintf(Estatistica,"Numero de movimentos na direcao oposta: %d\n",est.direcao_oposta);

//----------------------------------------------------------------------------------------------------------------------------------------
//PREENCHE ARQUIVO HEAT MAP

for (int i = 1; i < linhas-1; i++) {//percorre linhas validas do heatmap

    if (colidiu[i] == 1) {// se na linha x do colidiu tiver 1, indica acidente, logo linha com *


        for (int j = 1; j < colunas-1; j++) {//percorre colunas

            fprintf(Heat_Map, "  *");

        }
    } else {

        for (int j = 1; j < colunas-1; j++) {

            fprintf(Heat_Map, "%3d", mapacalor[i][j]);//imprime a posica do mapa de calor caso n tiver acidente
        }
    }
    fprintf(Heat_Map, "\n");
}
//-------------------------------------------------------------------------------------------------------------

    fclose(entrada);
    fclose(resumo);
    fclose(Ranking);
    fclose(Estatistica);
    fclose(Heat_Map);
    return 0;

}



