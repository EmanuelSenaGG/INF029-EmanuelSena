#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct DQ
{
    int Dia; 
    int Mes;
    int Ano;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;


int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numero, int numerobusca);
DataQuebrada quebraData(char data[]);


void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();


void testQ1(){
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/1/15");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"1/9/2016");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"//2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1//20");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/R/2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/12/19");
    printf("%d\n",q1(str) == 1); 

}

void testQ2(){
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 2);

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 3);

    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 4
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"05/07/2018");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 29);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 5
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/07/2017");
    strcpy(datafinal,"25/08/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 30);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 6
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/06/2017");
    strcpy(datafinal,"26/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 0);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 8
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"27/02/2016");
    strcpy(datafinal,"03/03/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 4);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 9
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"27/02/2015");
    strcpy(datafinal,"03/03/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 5);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 10
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"28/01/2016");
    strcpy(datafinal,"29/02/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

}


void testQ3(){
    char str[250];
    strcpy(str,"Renato Lima Novais");
    printf("%d\n",q3(str, 'a', 0) == 3);
    printf("%d\n",q3(str, 'b', 0) == 0);
    printf("%d\n",q3(str, 'l', 1) == 0);
    printf("%d\n",q3(str, 'l', 0) == 1);
    printf("%d\n",q3(str, 'L', 0) == 1);

    strcpy(str,"Letícia, signifiCa fEliCIdADE");
    printf("%d\n",q3(str, 'c', 0) == 3);
    printf("%d\n",q3(str, 'C', 0) == 3);
    printf("%d\n",q3(str, 'c', 1) == 1);
    printf("%d\n",q3(str, 'C', 1) == 2);
    printf("%d\n",q3(str, 'R', 0) == 0);
    printf("%d\n",q3(str, 'e', 0) == 3);
    printf("%d\n",q3(str, 'E', 1) == 2);
    printf("%d\n",q3(str, 'S', 1) == 0);

    
}


void testQ4(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==37);


    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Ola, o mundo e muito grande. Tem muitas pessoas, e muitos problemas");
    strcpy(strBusca,"mui");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 3);
    printf("%d\n",posicoes[0]==16);
    printf("%d\n",posicoes[1]==18);
    printf("%d\n",posicoes[2]==34);
    printf("%d\n",posicoes[3]==36);
    printf("%d\n",posicoes[4]==52);
    printf("%d\n",posicoes[5]==54);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Programar é legal?");
    strcpy(strBusca,"sim");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 0);

    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"maraaaavilha, meu prograaaama funcionou");
    strcpy(strBusca,"aa");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 4);
    printf("%d\n",posicoes[0]==4);
    printf("%d\n",posicoes[1]==5);
    printf("%d\n",posicoes[2]==6);
    printf("%d\n",posicoes[3]==7);
    printf("%d\n",posicoes[4]==24);
    printf("%d\n",posicoes[5]==25);
    printf("%d\n",posicoes[6]==26);
    printf("%d\n",posicoes[7]==27);

}

void testQ5(){
    printf("%d\n",q5(345) == 543);
    printf("%d\n",q5(78) == 87);
    printf("%d\n",q5(3) == 3);
    printf("%d\n",q5(5430) == 345);
    printf("%d\n",q5(1000) == 1);
    printf("%d\n",q5(0) == 0);
    printf("%d\n",q5(707) == 707);
    printf("%d\n",q5(80) == 8);
    printf("%d\n",q5(8) == 8);
    printf("%d\n",q5(1234) == 4321);
}

void testQ6(){
    printf("%d\n",q6(34567368, 3) == 2);
    printf("%d\n",q6(34567368, 4576) == 0);
    printf("%d\n",q6(3539343, 3) == 4);
    printf("%d\n",q6(3539343, 39) == 1);
    printf("%d\n",q6(5444, 44) == 1);
    printf("%d\n",q6(54444, 44) == 2);
    printf("%d\n",q6(1234562354, 23) == 2);
    printf("%d\n",q6(1234, 13) == 0);
    printf("%d\n",q6(544444, 4) == 5);
    printf("%d\n",q6(1234562354, 32) == 0);

}


//FUNÇÕES AUXILIARES
int isBissexto(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

DiasMesesAnos CalcularDiferencaDatas(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2, DiasMesesAnos Resultado) {
    
   
    int DiasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica se o ano bissexto afeta os cálculos
    if (isBissexto(ano2)) {
        DiasNoMes[2] = 29;
    }

    int DiferencaAnos = ano2 - ano1;
    int DiferencaMeses = mes2 - mes1;
    int DiferencaDias = dia2 - dia1;

    // Ajusta os valores negativos, se necessário
    if (DiferencaDias < 0) {
        DiferencaMeses--;
        DiferencaDias += DiasNoMes[mes1];
    }

    if (DiferencaMeses < 0) {
        DiferencaAnos--;
        DiferencaMeses += 12;
    }
    
    if (ano1 > ano2 || (ano1 == ano2 && mes1 > mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 > dia2)) {
      Resultado.retorno = 4;
    } else{
        Resultado.retorno = 1;
    }
Resultado.qtdAnos = DiferencaAnos;
Resultado.qtdDias = DiferencaDias;
Resultado.qtdMeses = DiferencaMeses;

return Resultado;
    
}
DataQuebrada quebraData(char data[]){
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	
    if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	} else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.Dia = atoi(sDia);
  dq.Mes = atoi(sMes);
  dq.Ano = atoi(sAno); 
  dq.valido = 1;
    
  return dq;
}


//questões


int q1(char data[]){
    
DataQuebrada DadosData = quebraData(data);  
if (DadosData.valido == 0){
	return 0;
} else if(DadosData.Dia > 31 || DadosData.Dia < 1){
	return 0;
} else if (DadosData.Mes > 12 || DadosData.Mes < 1){
	return 0;
} else if (DadosData.Ano % 2 != 0 && DadosData.Mes == 2 && DadosData.Dia == 29 ){
	return 0;
} else {
	return 1;
}
}
//Q2 COMPLETA
DiasMesesAnos q2(char datainicial[], char datafinal[]){
    DiasMesesAnos Resultado;
    int isValida = q1(datainicial);
    int isValidaFinal = q1(datafinal);
switch(isValida){
    case 0:
    Resultado.retorno = 2;
    Resultado.qtdAnos = 0;
    Resultado.qtdDias = 0;
    Resultado.qtdMeses = 0;
    break;

    case 1:
    
    if(isValidaFinal == 0){
    Resultado.retorno = 3;
    Resultado.qtdAnos = 0;
    Resultado.qtdDias = 0;
    Resultado.qtdMeses = 0;

    } else{
        DataQuebrada Data1 = quebraData(datainicial);
        DataQuebrada Data2 = quebraData(datafinal);
        Resultado = CalcularDiferencaDatas(Data1.Dia, Data1.Mes, Data1.Ano, Data2.Dia, Data2.Mes, Data2.Ano, Resultado);



    }
    
    break;
}
return Resultado;
}



int q3(char *texto, char c, int isCaseSensitive){

     int qtd = 0;

    // Percorre a string caractere por caractere
    for (int i = 0; texto[i] != '\0'; i++) {
        // Verifica se a pesquisa é case-sensitive ou não
        if (isCaseSensitive) {
            if (texto[i] == c) {
                qtd++;
            }
        } else {
            // Converte tanto o caractere no texto quanto o caractere de pesquisa para minúsculas
            char textChar = tolower(texto[i]);
            char searchChar = tolower(c);

            if (textChar == searchChar) {
                qtd++;
            }
        }
    }
    
    return qtd;
}




int q4(char *texto, char *strBusca, int posicoes[]){

    int ocorrencias = 0;
    int lenTexto = strlen(texto);
    int lenBusca = strlen(strBusca);
    
    for (int i = 0; i <= lenTexto - lenBusca; i++) {
        int j;
        for (j = 0; j < lenBusca; j++) {
            if (texto[i + j] != strBusca[j]) {
                break;
            }
        }
        if (j == lenBusca) {
           
            posicoes[ocorrencias * 2] = i + 1;                    // Início da ocorrência
            posicoes[ocorrencias * 2 + 1] = i + lenBusca; // Fim da ocorrência
            ocorrencias++;
            i += lenBusca - 1; // Pula a ocorrência para evitar sobreposição
        }
    }
    
    return ocorrencias;
}

     

int q5(int num){
    int inverso = 0;
    while (num != 0) {
        inverso = inverso * 10 + num % 10;
        num = num / 10;
    }
    return inverso;
}


 int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    long long div, i, subdivisao, casabusca, num;
    casabusca = 10;
    while(numerobusca/casabusca!=0){
      casabusca*=10;
    }
    div = 10;
    while(numerobase/div!=0){
      div*=10;
    }
    subdivisao = div/casabusca;
    for(i = div; subdivisao>0; i/=10){
      num = (numerobase%i)/subdivisao;
      if(num==numerobusca){
        qtdOcorrencias++;
        i = i/casabusca*10;
        subdivisao = subdivisao/casabusca*10;
      }
      subdivisao/=10;
    }
     return qtdOcorrencias;
}
    

   


int main()
{
    
    
    printf("Q1----------------------------------\n");
    testQ1();
    printf("Q2----------------------------------\n"); 
    testQ2();
    printf("Q3----------------------------------\n");
    testQ3();
    printf("Q4----------------------------------\n");
    testQ4();
    printf("Q5----------------------------------\n");
    testQ5();
    printf("Q6----------------------------------\n");
    testQ6();

return 0;
}
