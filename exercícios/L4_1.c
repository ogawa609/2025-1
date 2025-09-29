#include <stdio.h>
#define TRUE 1
#define FALSE 0


typedef struct produtos{
    int codigo;
    float preco;
    int quant;
}tproduto;

tproduto LeProduto();
int EhProduto1MaiorQ2(tproduto p1, tproduto p2);
int EhProduto1MenorQ2(tproduto p1, tproduto p2);
int TemProdutoEmEstoque(tproduto p);
void ImprimeProduto(tproduto p);


    tproduto LeProduto(){

        tproduto p1;

        scanf("%d;%f;%d",&p1.codigo,&p1.preco,&p1.quant);

        return p1;
        
    }

//////////////////////////////////////////////////////////////////////////
int TemProdutoEmEstoque(tproduto p){
    if(p.quant==0){
        return FALSE;
    }

    return TRUE;
}
//////////////////////////////////////////////////////////////////////////////

void ImprimeProduto(tproduto p){

    printf("COD %d, PRE %.2f, QTD %d\n",p.codigo,p.preco,p.quant);
}

///////////////////////////////////////////////////////////////////////////////////

int EhProduto1MaiorQ2(tproduto p1, tproduto p2){

    if(p1.preco>p2.preco){
        return 1;
    }
    return 2;

}

/////////////////////////////////////////////////////////////////////////////////////

int EhProduto1MenorQ2(tproduto p1, tproduto p2){

    if(p1.preco<p2.preco){

        return 1;
    }

    return 2;
}

int main (){

    int prod;
    tproduto p1;
    tproduto maior;
    tproduto menor;
    int umavez=1;
    

    //informa a quant de produtos;

    scanf("%d",&prod);

    //laço para ir comparando os produtos;

    for(int i=0; i<prod; i++){

       p1 = LeProduto();

        if(!TemProdutoEmEstoque(p1)){

            printf("FALTA:");
            ImprimeProduto(p1);
        }

        if(umavez){

            maior=p1;
            menor=p1;
            umavez=0;
        }
        

        if(EhProduto1MaiorQ2(p1,maior)==1){

            maior=p1;

        }

        

        if(EhProduto1MenorQ2(p1,menor)==1){

            menor=p1;
        }

        
        
    
        
}

printf("MAIOR:");
ImprimeProduto(maior);
printf("MENOR:");
ImprimeProduto(menor);

return 0;

}