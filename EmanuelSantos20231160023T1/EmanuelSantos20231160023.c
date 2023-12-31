// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Emanuel Sena Gomes Santos
//  email: senamanu.ms@gmail.com
//  Matrícula: 20231160023
//  Semestre: 2023-2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "EmanuelSantos20231160023.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
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

//QUESTÕES
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
    